#include "ViewOrderDialogBase.h"


ViewOrderDialogBase::ViewOrderDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer116;
    bSizer116 = new wxBoxSizer(wxHORIZONTAL);

    m_htmlWin = new wxHtmlWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO);
    bSizer116->Add(m_htmlWin, 1, wxALL, 5);

    bSizer20->Add(bSizer116, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer26;
    bSizer26 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonOK, 0, wxALL, 5);

    bSizer20->Add(bSizer26, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer20);
    this->Layout();

    // Connect Events
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ViewOrderDialogBase::OnButtonOK), nullptr, this);
}

ViewOrderDialogBase::~ViewOrderDialogBase()
{
    // Disconnect Events
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ViewOrderDialogBase::OnButtonOK), nullptr, this);
}
