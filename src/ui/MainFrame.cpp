#include "MainFrame.h"


MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent)
{
    Connect(wxEVT_CROSSTHREADCALL, wxCommandEventHandler(MainFrame::OnCrossThreadCall), NULL, this);

    // Init
    fRefreshListCtrl = false;
    fRefreshListCtrlRunning = false;
    fOnSetFocusAddress = false;
    pindexBestLast = NULL;
    m_choiceFilter->SetSelection(0);
    m_staticTextBalance->SetLabel(FormatMoney(GetBalance()) + "  ");
    m_listCtrl->SetFocus();
    SetIcon(wxICON(bitcoin));
    m_menuOptions->Check(wxID_OPTIONSGENERATEBITCOINS, fGenerateBitcoins);

    // Init toolbar with transparency masked bitmaps
    m_toolBar->ClearTools();

    //// shouldn't have to do mask separately anymore, bitmap alpha support added in wx 2.8.9,
    wxBitmap bmpSend(wxT("send20"), wxBITMAP_TYPE_RESOURCE);
    bmpSend.SetMask(new wxMask(wxBitmap(wxT("send20mask"), wxBITMAP_TYPE_RESOURCE)));
    m_toolBar->AddTool(wxID_BUTTONSEND, wxT("&Send Coins"), bmpSend, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);

    wxBitmap bmpAddressBook(wxT("addressbook20"), wxBITMAP_TYPE_RESOURCE);
    bmpAddressBook.SetMask(new wxMask(wxBitmap(wxT("addressbook20mask"), wxBITMAP_TYPE_RESOURCE)));
    m_toolBar->AddTool(wxID_BUTTONRECEIVE, wxT("&Address Book"), bmpAddressBook, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);

    m_toolBar->Realize();

    // Init column headers
    int nDateWidth = DateTimeStr(1229413914).size() * 6 + 8;
    m_listCtrl->InsertColumn(0, "",             wxLIST_FORMAT_LEFT,     0);
    m_listCtrl->InsertColumn(1, "",             wxLIST_FORMAT_LEFT,     0);
    m_listCtrl->InsertColumn(2, "Status",       wxLIST_FORMAT_LEFT,    90);
    m_listCtrl->InsertColumn(3, "Date",         wxLIST_FORMAT_LEFT,   nDateWidth);
    m_listCtrl->InsertColumn(4, "Description",  wxLIST_FORMAT_LEFT,   409 - nDateWidth);
    m_listCtrl->InsertColumn(5, "Debit",        wxLIST_FORMAT_RIGHT,   79);
    m_listCtrl->InsertColumn(6, "Credit",       wxLIST_FORMAT_RIGHT,   79);

    // Init status bar
    int pnWidths[3] = { -100, 81, 286 };
    m_statusBar->SetFieldsCount(3, pnWidths);

    // Fill your address text box
    vector<unsigned char> vchPubKey;
    if (CWalletDB("r").ReadDefaultKey(vchPubKey))
        m_textCtrlAddress->SetValue(PubKeyToAddress(vchPubKey));

    // Fill listctrl with wallet transactions
    RefreshListCtrl();
}

MainFrame::~MainFrame()
{
    pframeMain = NULL;
}
void MainFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
    _beginthread(Shutdown, 0, NULL);
}

void MainFrame::OnMouseEvents(wxMouseEvent& event)
{
    RandAddSeed();
    RAND_add(&event.m_x, sizeof(event.m_x), 0.25);
    RAND_add(&event.m_y, sizeof(event.m_y), 0.25);
}

void MainFrame::OnListColBeginDrag(wxListEvent& event)
{
    // Hidden columns not resizeable
    if (event.GetColumn() <= 1 && !fDebug)
        event.Veto();
}

void MainFrame::InsertLine(bool fNew, int nIndex, uint256 hashKey, string strSort, const wxString& str2, const wxString& str3, const wxString& str4, const wxString& str5, const wxString& str6)
{
    string str0 = strSort;
    long nData = *(long*)&hashKey;

    if (fNew)
    {
        nIndex = m_listCtrl->InsertItem(0, str0);
    }
    else
    {
        if (nIndex == -1)
        {
            // Find item
            while ((nIndex = m_listCtrl->FindItem(nIndex, nData)) != -1)
                if (GetItemText(m_listCtrl, nIndex, 1) == hashKey.ToString())
                    break;
            if (nIndex == -1)
            {
                printf("CMainFrame::InsertLine : Couldn't find item to be updated\n");
                return;
            }
        }

        // If sort key changed, must delete and reinsert to make it relocate
        if (GetItemText(m_listCtrl, nIndex, 0) != str0)
        {
            m_listCtrl->DeleteItem(nIndex);
            nIndex = m_listCtrl->InsertItem(0, str0);
        }
    }

    m_listCtrl->SetItem(nIndex, 1, hashKey.ToString());
    m_listCtrl->SetItem(nIndex, 2, str2);
    m_listCtrl->SetItem(nIndex, 3, str3);
    m_listCtrl->SetItem(nIndex, 4, str4);
    m_listCtrl->SetItem(nIndex, 5, str5);
    m_listCtrl->SetItem(nIndex, 6, str6);
    m_listCtrl->SetItemData(nIndex, nData);
}

void MainFrame::InsertTransaction(const CWalletTx& wtx, bool fNew, int nIndex)
{
    int64 nTime = wtx.nTimeDisplayed = wtx.GetTxTime();
    int64 nCredit = wtx.GetCredit();
    int64 nDebit = wtx.GetDebit();
    int64 nNet = nCredit - nDebit;
    uint256 hash = wtx.GetHash();
    string strStatus = FormatTxStatus(wtx);
    map<string, string> mapValue = wtx.mapValue;

    // Find the block the tx is in
    CBlockIndex* pindex = NULL;
    map<uint256, CBlockIndex*>::iterator mi = mapBlockIndex.find(wtx.hashBlock);
    if (mi != mapBlockIndex.end())
        pindex = (*mi).second;

    // Sort order, unrecorded transactions sort to the top
    string strSort = strprintf("%010d-%01d-%010u",
                               (pindex ? pindex->nHeight : INT_MAX),
                               (wtx.IsCoinBase() ? 1 : 0),
                               wtx.nTimeReceived);

    // Insert line
    if (nNet > 0 || wtx.IsCoinBase())
    {
        //
        // Credit
        //
        string strDescription;

        if (wtx.IsCoinBase())
        {
            // Coinbase
            strDescription = "Generated";
            if (nCredit == 0)
            {
                int64 nUnmatured = 0;
                foreach(const CTxOut& txout, wtx.vout)
                nUnmatured += txout.GetCredit();
                if (wtx.IsInMainChain())
                    strDescription += strprintf(" (%s matures in %d blocks)", FormatMoney(nUnmatured).c_str(), wtx.GetBlocksToMaturity());
                else
                    strDescription += " (not accepted)";
            }
        }
        else if (!mapValue["from"].empty() || !mapValue["message"].empty())
        {
            // Online transaction
            if (!mapValue["from"].empty())
                strDescription += "From: " + mapValue["from"];
            if (!mapValue["message"].empty())
            {
                if (!strDescription.empty())
                    strDescription += " - ";
                strDescription += mapValue["message"];
            }
        }
        else
        {
            // Offline transaction
            foreach(const CTxOut& txout, wtx.vout)
            {
                if (txout.IsMine())
                {
                    vector<unsigned char> vchPubKey;
                    if (ExtractPubKey(txout.scriptPubKey, true, vchPubKey))
                    {
                        string strAddress = PubKeyToAddress(vchPubKey);
                        if (mapAddressBook.count(strAddress))
                        {
                            strDescription += "Received with: ";
                            if (!mapAddressBook[strAddress].empty())
                                strDescription += mapAddressBook[strAddress] + " ";
                            strDescription += strAddress;
                        }
                    }
                    break;
                }
            }
        }

        string strDescription2;
        foreach(int c, strDescription)
        if (c >= ' ')
            strDescription2 += c;

        InsertLine(fNew, nIndex, hash, strSort,
                   strStatus,
                   nTime ? DateTimeStr(nTime) : "",
                   strDescription2,
                   "",
                   FormatMoney(nNet, true));
    }
    else
    {
        bool fAllFromMe = true;
        foreach(const CTxIn& txin, wtx.vin)
        fAllFromMe = fAllFromMe && txin.IsMine();

        bool fAllToMe = true;
        foreach(const CTxOut& txout, wtx.vout)
        fAllToMe = fAllToMe && txout.IsMine();

        if (fAllFromMe && fAllToMe)
        {
            // Payment to self
            int64 nValue = wtx.vout[0].nValue;
            InsertLine(fNew, nIndex, hash, strSort,
                       strStatus,
                       nTime ? DateTimeStr(nTime) : "",
                       "Payment to yourself",
                       FormatMoney(nNet - nValue, true),
                       FormatMoney(nValue, true));
        }
        else if (fAllFromMe)
        {
            //
            // Debit
            //
            int64 nTxFee = nDebit - wtx.GetValueOut();
            for (int nOut = 0; nOut < wtx.vout.size(); nOut++)
            {
                const CTxOut& txout = wtx.vout[nOut];
                if (txout.IsMine())
                    continue;

                string strAddress;
                if (!mapValue["to"].empty())
                {
                    // Online transaction
                    strAddress = mapValue["to"];
                }
                else
                {
                    // Offline transaction
                    uint160 hash160;
                    if (ExtractHash160(txout.scriptPubKey, hash160))
                        strAddress = Hash160ToAddress(hash160);
                }

                string strDescription = "To: ";
                if (mapAddressBook.count(strAddress) && !mapAddressBook[strAddress].empty())
                    strDescription += mapAddressBook[strAddress] + " ";
                strDescription += strAddress;
                if (!mapValue["message"].empty())
                {
                    if (!strDescription.empty())
                        strDescription += " - ";
                    strDescription += mapValue["message"];
                }

                string strDescription2;
                foreach(int c, strDescription)
                if (c >= ' ')
                    strDescription2 += c;

                int64 nValue = txout.nValue;
                if (nOut == 0 && nTxFee > 0)
                    nValue += nTxFee;

                InsertLine(fNew, nIndex, hash, strprintf("%s-%d", strSort.c_str(), nOut),
                           strStatus,
                           nTime ? DateTimeStr(nTime) : "",
                           strDescription2,
                           FormatMoney(-nValue, true),
                           "");
            }
        }
        else
        {
            //
            // Mixed debit transaction, can't break down payees
            //
            bool fAllMine = true;
            foreach(const CTxOut& txout, wtx.vout)
            fAllMine = fAllMine && txout.IsMine();
            foreach(const CTxIn& txin, wtx.vin)
            fAllMine = fAllMine && txin.IsMine();

            InsertLine(fNew, nIndex, hash, strSort,
                       strStatus,
                       nTime ? DateTimeStr(nTime) : "",
                       "",
                       FormatMoney(nNet, true),
                       "");
        }
    }
}

void MainFrame::RefreshStatus()
{
    static int nLastTop;
    int nTop = m_listCtrl->GetTopItem();
    if (nTop == nLastTop && pindexBestLast == pindexBest)
        return;

    TRY_CRITICAL_BLOCK(cs_mapWallet)
    {
        int nStart = nTop;
        int nEnd = min(nStart + 100, m_listCtrl->GetItemCount());
        if (pindexBestLast == pindexBest)
        {
            if (nStart >= nLastTop && nStart < nLastTop + 100)
                nStart = nLastTop + 100;
            if (nEnd >= nLastTop && nEnd < nLastTop + 100)
                nEnd = nLastTop;
        }
        nLastTop = nTop;
        pindexBestLast = pindexBest;

        for (int nIndex = nStart; nIndex < nEnd; nIndex++)
        {
            uint256 hash((string)GetItemText(m_listCtrl, nIndex, 1));
            map<uint256, CWalletTx>::iterator mi = mapWallet.find(hash);
            if (mi == mapWallet.end())
            {
                printf("CMainFrame::RefreshStatus() : tx not found in mapWallet\n");
                continue;
            }
            const CWalletTx& wtx = (*mi).second;
            if (wtx.IsCoinBase() || wtx.GetTxTime() != wtx.nTimeDisplayed)
                InsertTransaction(wtx, false, nIndex);
            else
                m_listCtrl->SetItem(nIndex, 2, FormatTxStatus(wtx));
        }
    }
}

void MainFrame::RefreshListCtrl()
{
    fRefreshListCtrl = true;
    ::wxWakeUpIdle();
}

void MainFrame::OnIdle(wxIdleEvent& event)
{
    if (fRefreshListCtrl)
    {
        // Collect list of wallet transactions and sort newest first
        bool fEntered = false;
        vector<pair<unsigned int, uint256> > vSorted;
        TRY_CRITICAL_BLOCK(cs_mapWallet)
        {
            printf("RefreshListCtrl starting\n");
            fEntered = true;
            fRefreshListCtrl = false;
            vWalletUpdated.clear();

            // Do the newest transactions first
            vSorted.reserve(mapWallet.size());
            for (map<uint256, CWalletTx>::iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
            {
                const CWalletTx& wtx = (*it).second;
                unsigned int nTime = UINT_MAX - wtx.GetTxTime();
                vSorted.push_back(make_pair(nTime, (*it).first));
            }
            m_listCtrl->DeleteAllItems();
        }
        if (!fEntered)
            return;

        sort(vSorted.begin(), vSorted.end());

        // Fill list control
        for (int i = 0; i < vSorted.size();)
        {
            if (fShutdown)
                return;
            bool fEntered = false;
            TRY_CRITICAL_BLOCK(cs_mapWallet)
            {
                fEntered = true;
                uint256& hash = vSorted[i++].second;
                map<uint256, CWalletTx>::iterator mi = mapWallet.find(hash);
                if (mi != mapWallet.end())
                    InsertTransaction((*mi).second, true);
            }
            if (!fEntered || i == 100 || i % 500 == 0)
                wxYield();
        }

        printf("RefreshListCtrl done\n");
    }
    else
    {
        // Check for time updates
        static int64 nLastTime;
        if (GetTime() > nLastTime + 30)
        {
            TRY_CRITICAL_BLOCK(cs_mapWallet)
            {
                nLastTime = GetTime();
                for (map<uint256, CWalletTx>::iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
                {
                    CWalletTx& wtx = (*it).second;
                    if (wtx.nTimeDisplayed && wtx.nTimeDisplayed != wtx.GetTxTime())
                        InsertTransaction(wtx, false);
                }
            }
        }
    }
}

void MainFrame::OnPaint(wxPaintEvent& event)
{
    event.Skip();
}

void MainFrame::OnPaintListCtrl(wxPaintEvent& event)
{
    // Update listctrl contents
    if (!vWalletUpdated.empty())
    {
        TRY_CRITICAL_BLOCK(cs_mapWallet)
        {
            pair<uint256, bool> item;
            foreach(item, vWalletUpdated)
            {
                bool fNew = item.second;
                map<uint256, CWalletTx>::iterator mi = mapWallet.find(item.first);
                if (mi != mapWallet.end())
                {
                    printf("vWalletUpdated: %s %s\n", (*mi).second.GetHash().ToString().substr(0,6).c_str(), fNew ? "new" : "");
                    InsertTransaction((*mi).second, fNew);
                }
            }
            m_listCtrl->ScrollList(0, INT_MAX);
            vWalletUpdated.clear();
        }
    }

    // Update status column of visible items only
    RefreshStatus();

    // Update status bar
    string strGen = "";
    if (fGenerateBitcoins)
        strGen = "    Generating";
    if (fGenerateBitcoins && vNodes.empty())
        strGen = "(not connected)";
    m_statusBar->SetStatusText(strGen, 1);

    string strStatus = strprintf("     %d connections     %d blocks     %d transactions", vNodes.size(), nBestHeight + 1, m_listCtrl->GetItemCount());
    m_statusBar->SetStatusText(strStatus, 2);

    // Balance total
    TRY_CRITICAL_BLOCK(cs_mapWallet)
    m_staticTextBalance->SetLabel(FormatMoney(GetBalance()) + "  ");

    m_listCtrl->OnPaint(event);
}

void MainFrame::OnCrossThreadCall(wxCommandEvent& event)
{
    void* pdata = event.GetClientData();
    switch (event.GetInt())
    {
        case UICALL_ADDORDER:
        {
            break;
        }

        case UICALL_UPDATEORDER:
        {
            break;
        }
    }
}

void MainFrame::OnMenuFileExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnMenuOptionsGenerate(wxCommandEvent& event)
{
    fGenerateBitcoins = event.IsChecked();
    nTransactionsUpdated++;
    CWalletDB().WriteSetting("fGenerateBitcoins", fGenerateBitcoins);

    if (fGenerateBitcoins)
        if (_beginthread(ThreadBitcoinMiner, 0, NULL) == -1)
            printf("Error: _beginthread(ThreadBitcoinMiner) failed\n");

    Refresh();
    wxPaintEvent eventPaint;
    AddPendingEvent(eventPaint);
}

void MainFrame::OnMenuOptionsOptions(wxCommandEvent& event)
{
    COptionsDialog dialog(this);
    dialog.ShowModal();
}

void MainFrame::OnMenuHelpAbout(wxCommandEvent& event)
{
    CAboutDialog dialog(this);
    dialog.ShowModal();
}

void MainFrame::OnButtonSend(wxCommandEvent& event)
{
    /// debug test
    if (fRandSendTest)
    {
        RandSend();
        return;
    }

    // Toolbar: Send
    CSendDialog dialog(this);
    dialog.ShowModal();
}

void MainFrame::OnButtonAddressBook(wxCommandEvent& event)
{
    // Toolbar: Address Book
    CAddressBookDialog dialogAddr(this, "", false);
    if (dialogAddr.ShowModal() == 2)
    {
        // Send
        CSendDialog dialogSend(this, dialogAddr.GetAddress());
        dialogSend.ShowModal();
    }
}

void MainFrame::OnSetFocusAddress(wxFocusEvent& event)
{
    // Automatically select-all when entering window
    m_textCtrlAddress->SetSelection(-1, -1);
    fOnSetFocusAddress = true;
    event.Skip();
}

void MainFrame::OnMouseEventsAddress(wxMouseEvent& event)
{
    if (fOnSetFocusAddress)
        m_textCtrlAddress->SetSelection(-1, -1);
    fOnSetFocusAddress = false;
    event.Skip();
}

void MainFrame::OnButtonCopy(wxCommandEvent& event)
{
    // Copy address box to clipboard
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(m_textCtrlAddress->GetValue()));
        wxTheClipboard->Close();
    }
}

void MainFrame::OnButtonChange(wxCommandEvent& event)
{
    CYourAddressDialog dialog(this, string(m_textCtrlAddress->GetValue()));
    if (!dialog.ShowModal())
        return;
    string strAddress = (string)dialog.GetAddress();
    if (strAddress != m_textCtrlAddress->GetValue())
    {
        uint160 hash160;
        if (!AddressToHash160(strAddress, hash160))
            return;
        if (!mapPubKeys.count(hash160))
            return;
        CWalletDB().WriteDefaultKey(mapPubKeys[hash160]);
        m_textCtrlAddress->SetValue(strAddress);
    }
}

void MainFrame::OnListItemActivatedAllTransactions(wxListEvent& event)
{
    uint256 hash((string)GetItemText(m_listCtrl, event.GetIndex(), 1));
    CWalletTx wtx;
    CRITICAL_BLOCK(cs_mapWallet)
    {
        map<uint256, CWalletTx>::iterator mi = mapWallet.find(hash);
        if (mi == mapWallet.end())
        {
            printf("CMainFrame::OnListItemActivatedAllTransactions() : tx not found in mapWallet\n");
            return;
        }
        wtx = (*mi).second;
    }
    CTxDetailsDialog dialog(this, wtx);
    dialog.ShowModal();
    //CTxDetailsDialog* pdialog = new CTxDetailsDialog(this, wtx);
    //pdialog->Show();
}

void MainFrame::OnListItemActivatedProductsSent(wxListEvent& event)
{
    CProduct& product = *(CProduct*)event.GetItem().GetData();
    CEditProductDialog* pdialog = new CEditProductDialog(this);
    pdialog->SetProduct(product);
    pdialog->Show();
}

void MainFrame::OnListItemActivatedOrdersSent(wxListEvent& event)
{
    CWalletTx& order = *(CWalletTx*)event.GetItem().GetData();
    CViewOrderDialog* pdialog = new CViewOrderDialog(this, order, false);
    pdialog->Show();
}

void MainFrame::OnListItemActivatedOrdersReceived(wxListEvent& event)
{
    CWalletTx& order = *(CWalletTx*)event.GetItem().GetData();
    CViewOrderDialog* pdialog = new CViewOrderDialog(this, order, true);
    pdialog->Show();
}