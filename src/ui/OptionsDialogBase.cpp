#include "OptionsDialogBase.h"

OptionsDialogBase::OptionsDialogBase(wxWindow* parent,
                                     wxWindowID id,
                                     const wxString& title,
                                     const wxPoint& pos,
                                     const wxSize& size,
                                     long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer55;
    bSizer55 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer57;
    bSizer57 = new wxBoxSizer(wxVERTICAL);


    bSizer57->Add(0, 20, 0, wxEXPAND, 5);

    m_staticText32 = new wxStaticText(this, wxID_ANY, wxT("Optional transaction fee you give to the nodes that process your transactions."), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText32->Wrap(-1);
    bSizer57->Add(m_staticText32, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* bSizer56;
    bSizer56 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText31 = new wxStaticText(this, wxID_ANY, wxT("Transaction fee:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText31->Wrap(-1);
    bSizer56->Add(m_staticText31, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlTransactionFee = new wxTextCtrl(this, wxID_TRANSACTIONFEE, wxEmptyString, wxDefaultPosition, wxSize(70,-1), 0);
    bSizer56->Add(m_textCtrlTransactionFee, 0, wxALL, 5);

    bSizer57->Add(bSizer56, 0, wxEXPAND, 5);

    bSizer55->Add(bSizer57, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer58;
    bSizer58 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(85,25), 0);
    bSizer58->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer58->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer55->Add(bSizer58, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer55);
    this->Layout();

    // Connect Events
    m_textCtrlTransactionFee->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(OptionsDialogBase::OnKillFocusTransactionFee), nullptr, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OptionsDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OptionsDialogBase::OnButtonCancel), nullptr, this);
}

OptionsDialogBase::~OptionsDialogBase()
{
    // Disconnect Events
    m_textCtrlTransactionFee->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(OptionsDialogBase::OnKillFocusTransactionFee), nullptr, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OptionsDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(OptionsDialogBase::OnButtonCancel), nullptr, this);
}