#ifndef BITCOIN_MAINFRAME_H
#define BITCOIN_MAINFRAME_H

#include "common.h"
#include "ui.h"
#include "MainFrameBase.h"

class MainFrame : public MainFrameBase {
public:
    MainFrame(wxWindow* parent);
    ~MainFrame();

    // Custom
    bool fRefreshListCtrl;
    bool fRefreshListCtrlRunning;
    bool fOnSetFocusAddress;
    CBlockIndex* pindexBestLast;
    set<uint256> setUnmaturedDisplayed;

    void OnCrossThreadCall(wxCommandEvent& event);
    void InsertLine(bool fNew, int nIndex, uint256 hashKey, string strSort, const wxString& str1, const wxString& str2, const wxString& str3, const wxString& str4, const wxString& str5);
    void InsertTransaction(const CWalletTx& wtx, bool fNew, int nIndex=-1);
    void RefreshListCtrl();
    void RefreshStatus();
protected:
    void OnClose(wxCloseEvent& event);
    void OnMouseEvents(wxMouseEvent& event);
    void OnKeyDown(wxKeyEvent& event) { HandleCtrlA(event); }
    void OnIdle(wxIdleEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnPaintListCtrl(wxPaintEvent& event);
    void OnMenuFileExit(wxCommandEvent& event);
    void OnMenuOptionsGenerate(wxCommandEvent& event);
    void OnMenuOptionsOptions(wxCommandEvent& event);
    void OnMenuHelpAbout(wxCommandEvent& event);
    void OnButtonSend(wxCommandEvent& event);
    void OnButtonAddressBook(wxCommandEvent& event);
    void OnSetFocusAddress(wxFocusEvent& event);
    void OnMouseEventsAddress(wxMouseEvent& event);
    void OnButtonCopy(wxCommandEvent& event);
    void OnButtonChange(wxCommandEvent& event);
    void OnListColBeginDrag(wxListEvent& event);
    void OnListItemActivatedAllTransactions(wxListEvent& event);
    void OnListItemActivatedProductsSent(wxListEvent& event);
    void OnListItemActivatedOrdersSent(wxListEvent& event);
    void OnListItemActivatedOrdersReceived(wxListEvent& event);
};


#endif //BITCOIN_MAINFRAME_H
