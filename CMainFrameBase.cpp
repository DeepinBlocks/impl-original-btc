#include "CMainFrameBase.h"

CMainFrameBase::CMainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    m_menubar = new wxMenuBar(0);
    m_menubar->SetBackgroundColour(wxColour(240, 240, 240));

    m_menuFile = new wxMenu();
    wxMenuItem* m_menuFileExit;
    m_menuFileExit = new wxMenuItem(m_menuFile, wxID_ANY, wxString(wxT("E&xit")) , wxEmptyString, wxITEM_NORMAL);
    m_menuFile->Append(m_menuFileExit);

    m_menubar->Append(m_menuFile, wxT("&File"));

    m_menuOptions = new wxMenu();
    wxMenuItem* m_menuOptionsGenerateBitcoins;
    m_menuOptionsGenerateBitcoins = new wxMenuItem(m_menuOptions, wxID_OPTIONSGENERATEBITCOINS, wxString(wxT("&Generate Coins")) , wxEmptyString, wxITEM_CHECK);
    m_menuOptions->Append(m_menuOptionsGenerateBitcoins);

    wxMenuItem* m_menuOptionsOptions;
    m_menuOptionsOptions = new wxMenuItem(m_menuOptions, wxID_ANY, wxString(wxT("&Options...")) , wxEmptyString, wxITEM_NORMAL);
    m_menuOptions->Append(m_menuOptionsOptions);

    m_menubar->Append(m_menuOptions, wxT("&Options"));

    m_menuHelp = new wxMenu();
    wxMenuItem* m_menuHelpAbout;
    m_menuHelpAbout = new wxMenuItem(m_menuHelp, wxID_ANY, wxString(wxT("&About...")) , wxEmptyString, wxITEM_NORMAL);
    m_menuHelp->Append(m_menuHelpAbout);

    m_menubar->Append(m_menuHelp, wxT("&Help"));

    this->SetMenuBar(m_menubar);

    m_toolBar = this->CreateToolBar(wxTB_FLAT|wxTB_HORZ_TEXT, wxID_ANY);
    m_toolBar->SetToolBitmapSize(wxSize(20,20));
    m_toolBar->SetToolSeparation(1);
    m_toolBar->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

    m_toolBar->AddTool(wxID_BUTTONSEND, wxT("&Send Coins"), wxBitmap(wxT("../rc/send20.bmp"), wxBITMAP_TYPE_RESOURCE), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_toolBar->AddTool(wxID_BUTTONRECEIVE, wxT("&Address Book"), wxBitmap(wxT("../rc/addressbook20.bmp"), wxBITMAP_TYPE_RESOURCE), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_toolBar->Realize();

    m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);
    m_statusBar->SetBackgroundColour(wxColour(240, 240, 240));

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxVERTICAL);


    bSizer2->Add(0, 2, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer85;
    bSizer85 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText32 = new wxStaticText(this, wxID_ANY, wxT("Your Bitcoin Address:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText32->Wrap(-1);
    bSizer85->Add(m_staticText32, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5);

    m_textCtrlAddress = new wxTextCtrl(this, wxID_TEXTCTRLADDRESS, wxEmptyString, wxDefaultPosition, wxSize(250,-1), wxTE_READONLY);
    m_textCtrlAddress->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

    bSizer85->Add(m_textCtrlAddress, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_buttonCopy = new wxButton(this, wxID_BUTTONCOPY, wxT("&Copy to Clipboard"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    bSizer85->Add(m_buttonCopy, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_button91 = new wxButton(this, wxID_BUTTONCHANGE, wxT("C&hange..."), wxDefaultPosition, wxDefaultSize, 0);
    bSizer85->Add(m_button91, 0, wxRIGHT, 5);


    bSizer85->Add(0, 0, 0, wxEXPAND, 5);

    bSizer2->Add(bSizer85, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_panel14 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer66;
    bSizer66 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText41 = new wxStaticText(m_panel14, wxID_ANY, wxT("Balance:"), wxDefaultPosition, wxSize(-1,15), 0);
    m_staticText41->Wrap(-1);
    bSizer66->Add(m_staticText41, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_TOP|wxBOTTOM|wxLEFT, 5);

    m_staticTextBalance = new wxStaticText(m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120,15), wxALIGN_RIGHT|wxST_NO_AUTORESIZE);
    m_staticTextBalance->Wrap(-1);
    m_staticTextBalance->SetFont(wxFont(8, 70, 90, 90, false, wxEmptyString));
    m_staticTextBalance->SetBackgroundColour(wxColour(240, 240, 240));

    bSizer66->Add(m_staticTextBalance, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_panel14->SetSizer(bSizer66);
    m_panel14->Layout();
    bSizer66->Fit(m_panel14);
    bSizer3->Add(m_panel14, 1, wxEXPAND, 5);


    bSizer3->Add(0, 0, 0, wxEXPAND, 5);

    wxString m_choiceFilterChoices[] = { wxT(" All"), wxT(" Sent"), wxT(" Received"), wxT(" In Progress") };
    int m_choiceFilterNChoices = sizeof(m_choiceFilterChoices) / sizeof(wxString);
    m_choiceFilter = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(110,-1), m_choiceFilterNChoices, m_choiceFilterChoices, 0);
    m_choiceFilter->SetSelection(0);
    m_choiceFilter->Hide();

    bSizer3->Add(m_choiceFilter, 0, wxALIGN_BOTTOM|wxALIGN_TOP|wxRIGHT|wxLEFT, 5);

    bSizer2->Add(bSizer3, 0, wxEXPAND, 5);

    m_notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
    m_panel7 = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer157;
    bSizer157 = new wxBoxSizer(wxVERTICAL);

    m_listCtrl = new wxListCtrl(m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SORT_DESCENDING|wxALWAYS_SHOW_SB);
    bSizer157->Add(m_listCtrl, 1, wxEXPAND, 5);

    m_panel7->SetSizer(bSizer157);
    m_panel7->Layout();
    bSizer157->Fit(m_panel7);
    m_notebook->AddPage(m_panel7, wxT("All Transactions"), false);

    bSizer2->Add(m_notebook, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer_TabsForFutureUse;
    bSizer_TabsForFutureUse = new wxBoxSizer(wxVERTICAL);

    m_panel9 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_panel9->Hide();

    wxBoxSizer* bSizer159;
    bSizer159 = new wxBoxSizer(wxVERTICAL);

    m_listCtrlEscrows = new wxListCtrl(m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer159->Add(m_listCtrlEscrows, 1, wxEXPAND, 5);

    m_panel9->SetSizer(bSizer159);
    m_panel9->Layout();
    bSizer159->Fit(m_panel9);
    bSizer_TabsForFutureUse->Add(m_panel9, 1, wxEXPAND, 5);

    m_panel8 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_panel8->Hide();

    wxBoxSizer* bSizer158;
    bSizer158 = new wxBoxSizer(wxVERTICAL);

    m_listCtrlOrdersSent = new wxListCtrl(m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer158->Add(m_listCtrlOrdersSent, 1, wxEXPAND, 5);

    m_panel8->SetSizer(bSizer158);
    m_panel8->Layout();
    bSizer158->Fit(m_panel8);
    bSizer_TabsForFutureUse->Add(m_panel8, 1, wxEXPAND, 5);

    m_panel10 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_panel10->Hide();

    wxBoxSizer* bSizer160;
    bSizer160 = new wxBoxSizer(wxVERTICAL);

    m_listCtrlProductsSent = new wxListCtrl(m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer160->Add(m_listCtrlProductsSent, 1, wxALL, 5);

    m_panel10->SetSizer(bSizer160);
    m_panel10->Layout();
    bSizer160->Fit(m_panel10);
    bSizer_TabsForFutureUse->Add(m_panel10, 1, wxEXPAND, 5);

    m_panel11 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_panel11->Hide();

    wxBoxSizer* bSizer161;
    bSizer161 = new wxBoxSizer(wxVERTICAL);

    m_listCtrlOrdersReceived = new wxListCtrl(m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer161->Add(m_listCtrlOrdersReceived, 1, wxALL, 5);

    m_panel11->SetSizer(bSizer161);
    m_panel11->Layout();
    bSizer161->Fit(m_panel11);
    bSizer_TabsForFutureUse->Add(m_panel11, 1, wxEXPAND, 5);

    bSizer2->Add(bSizer_TabsForFutureUse, 1, wxEXPAND, 5);

    this->SetSizer(bSizer2);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CMainFrameBase::OnClose));
    this->Connect(wxEVT_IDLE, wxIdleEventHandler(CMainFrameBase::OnIdle));
    this->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_MOTION, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(CMainFrameBase::OnPaint));
    this->Connect(m_menuFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuFileExit));
    this->Connect(m_menuOptionsGenerateBitcoins->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuOptionsGenerate));
    this->Connect(m_menuOptionsOptions->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuOptionsOptions));
    this->Connect(m_menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuHelpAbout));
    this->Connect(wxID_BUTTONSEND, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonSend));
    this->Connect(wxID_BUTTONRECEIVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonAddressBook));
    m_textCtrlAddress->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(CMainFrameBase::OnKeyDown), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_MOTION, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Connect(wxEVT_SET_FOCUS, wxFocusEventHandler(CMainFrameBase::OnSetFocusAddress), NULL, this);
    m_buttonCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonCopy), NULL, this);
    m_button91->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonChange), NULL, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_COL_BEGIN_DRAG, wxListEventHandler(CMainFrameBase::OnListColBeginDrag), NULL, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedAllTransactions), NULL, this);
    m_listCtrl->Connect(wxEVT_PAINT, wxPaintEventHandler(CMainFrameBase::OnPaintListCtrl), NULL, this);
    m_listCtrlOrdersSent->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedOrdersSent), NULL, this);
    m_listCtrlProductsSent->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedProductsSent), NULL, this);
    m_listCtrlOrdersReceived->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedOrdersReceived), NULL, this);
}

CMainFrameBase::~CMainFrameBase(){
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CMainFrameBase::OnClose));
    this->Disconnect(wxEVT_IDLE, wxIdleEventHandler(CMainFrameBase::OnIdle));
    this->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_MOTION, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CMainFrameBase::OnMouseEvents));
    this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(CMainFrameBase::OnPaint));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuFileExit));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuOptionsGenerate));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuOptionsOptions));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CMainFrameBase::OnMenuHelpAbout));
    this->Disconnect(wxID_BUTTONSEND, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonSend));
    this->Disconnect(wxID_BUTTONRECEIVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonAddressBook));
    m_textCtrlAddress->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(CMainFrameBase::OnKeyDown), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_MOTION, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CMainFrameBase::OnMouseEventsAddress), NULL, this);
    m_textCtrlAddress->Disconnect(wxEVT_SET_FOCUS, wxFocusEventHandler(CMainFrameBase::OnSetFocusAddress), NULL, this);
    m_buttonCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonCopy), NULL, this);
    m_button91->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CMainFrameBase::OnButtonChange), NULL, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_COL_BEGIN_DRAG, wxListEventHandler(CMainFrameBase::OnListColBeginDrag), NULL, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedAllTransactions), NULL, this);
    m_listCtrl->Disconnect(wxEVT_PAINT, wxPaintEventHandler(CMainFrameBase::OnPaintListCtrl), NULL, this);
    m_listCtrlOrdersSent->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedOrdersSent), NULL, this);
    m_listCtrlProductsSent->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedProductsSent), NULL, this);
    m_listCtrlOrdersReceived->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CMainFrameBase::OnListItemActivatedOrdersReceived), NULL, this);
}