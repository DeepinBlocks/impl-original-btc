#include "TxDetailDialogBase.h"


CTxDetailsDialogBase::CTxDetailsDialogBase(wxWindow* parent,
                                         wxWindowID id,
                                         const wxString& title,
                                         const wxPoint& pos,
                                         const wxSize& size,
                                         long style) : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer64;
    bSizer64 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer66;
    bSizer66 = new wxBoxSizer(wxVERTICAL);

    m_htmlWin = new wxHtmlWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO);
    bSizer66->Add(m_htmlWin, 1, wxALL, 5);

    bSizer64->Add(bSizer66, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer65;
    bSizer65 = new wxBoxSizer(wxVERTICAL);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(85,25), 0);
    bSizer65->Add(m_buttonOK, 0, wxALL, 5);

    bSizer64->Add(bSizer65, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer64);
    this->Layout();

    // Connect Events
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CTxDetailsDialogBase::OnButtonOK), nullptr, this);
}

CTxDetailsDialogBase::~CTxDetailsDialogBase() {
    // Disconnect Events
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CTxDetailsDialogBase::OnButtonOK), NULL, this);
}