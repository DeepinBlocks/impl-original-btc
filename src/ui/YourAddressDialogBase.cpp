#include "YourAddressDialogBase.h"

YourAddressDialogBase::YourAddressDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer68;
    bSizer68 = new wxBoxSizer(wxVERTICAL);


    bSizer68->Add(0, 5, 0, wxEXPAND, 5);

    m_staticText45 = new wxStaticText(this, wxID_ANY, wxT("These are your Bitcoin addresses for receiving payments.\nYou may want to give a different one to each sender so you can keep track of who is paying you."), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText45->Wrap(600);
    bSizer68->Add(m_staticText45, 0, wxALL, 5);

    m_listCtrl = new wxListCtrl(this, wxID_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SORT_ASCENDING);
    bSizer68->Add(m_listCtrl, 1, wxALL, 5);

    wxBoxSizer* bSizer69;
    bSizer69 = new wxBoxSizer(wxHORIZONTAL);


    bSizer69->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonRename = new wxButton(this, wxID_BUTTONRENAME, wxT("&Rename..."), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonRename->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonRename, 0, wxALL, 5);

    m_buttonNew = new wxButton(this, wxID_BUTTONNEW, wxT("&New Address..."), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonNew->SetMinSize(wxSize(110,25));

    bSizer69->Add(m_buttonNew, 0, wxALL, 5);

    m_buttonCopy = new wxButton(this, wxID_BUTTONCOPY, wxT("&Copy to Clipboard"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCopy->SetMinSize(wxSize(120,25));

    bSizer69->Add(m_buttonCopy, 0, wxALL, 5);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer68->Add(bSizer69, 0, wxEXPAND, 5);

    this->SetSizer(bSizer68);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(YourAddressDialogBase::OnClose));
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler(YourAddressDialogBase::OnListEndLabelEdit), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(YourAddressDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(YourAddressDialogBase::OnListItemSelected), nullptr, this);
    m_buttonRename->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonRename), nullptr, this);
    m_buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonNew), nullptr, this);
    m_buttonCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonCopy), nullptr, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonCancel), nullptr, this);
}

YourAddressDialogBase::~YourAddressDialogBase()
{
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(YourAddressDialogBase::OnClose));
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler(YourAddressDialogBase::OnListEndLabelEdit), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(YourAddressDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(YourAddressDialogBase::OnListItemSelected), nullptr, this);
    m_buttonRename->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonRename), nullptr, this);
    m_buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonNew), nullptr, this);
    m_buttonCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonCopy), nullptr, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(YourAddressDialogBase::OnButtonCancel), nullptr, this);
}