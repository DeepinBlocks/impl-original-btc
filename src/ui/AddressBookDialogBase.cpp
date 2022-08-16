#include "AddressBookDialogBase.h"

AddressBookDialogBase::AddressBookDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer68;
    bSizer68 = new wxBoxSizer(wxVERTICAL);


    bSizer68->Add(0, 5, 0, wxEXPAND, 5);

    m_staticText55 = new wxStaticText(this, wxID_ANY, wxT("Bitcoin Address"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText55->Wrap(-1);
    m_staticText55->Hide();

    bSizer68->Add(m_staticText55, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    m_listCtrl = new wxListCtrl(this, wxID_LISTCTRL, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SORT_ASCENDING);
    bSizer68->Add(m_listCtrl, 1, wxALL, 5);

    wxBoxSizer* bSizer69;
    bSizer69 = new wxBoxSizer(wxHORIZONTAL);


    bSizer69->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonEdit = new wxButton(this, wxID_BUTTONEDIT, wxT("&Edit..."), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonEdit->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonEdit, 0, wxALL, 5);

    m_buttonNew = new wxButton(this, wxID_BUTTONNEW, wxT("&New Address..."), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonNew->SetMinSize(wxSize(110,25));

    bSizer69->Add(m_buttonNew, 0, wxALL, 5);

    m_buttonDelete = new wxButton(this, wxID_BUTTONDELETE, wxT("&Delete"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonDelete->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonDelete, 0, wxALL, 5);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer68->Add(bSizer69, 0, wxEXPAND, 5);

    this->SetSizer(bSizer68);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(AddressBookDialogBase::OnClose));
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler(AddressBookDialogBase::OnListEndLabelEdit), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(AddressBookDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(AddressBookDialogBase::OnListItemSelected), nullptr, this);
    m_buttonEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonEdit), nullptr, this);
    m_buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonNew), nullptr, this);
    m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonDelete), nullptr, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonCancel), nullptr, this);
}

AddressBookDialogBase::~AddressBookDialogBase()
{
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(AddressBookDialogBase::OnClose));
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_END_LABEL_EDIT, wxListEventHandler(AddressBookDialogBase::OnListEndLabelEdit), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(AddressBookDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(AddressBookDialogBase::OnListItemSelected), nullptr, this);
    m_buttonEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonEdit), nullptr, this);
    m_buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonNew), nullptr, this);
    m_buttonDelete->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonDelete), nullptr, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddressBookDialogBase::OnButtonCancel), nullptr, this);
}