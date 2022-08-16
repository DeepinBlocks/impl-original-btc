#include "GetTextFromUserDialogBase.h"


GetTextFromUserDialogBase::GetTextFromUserDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer79;
    bSizer79 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer81;
    bSizer81 = new wxBoxSizer(wxVERTICAL);


    bSizer81->Add(0, 0, 1, wxEXPAND, 5);

    m_staticTextMessage1 = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextMessage1->Wrap(-1);
    bSizer81->Add(m_staticTextMessage1, 0, wxTOP, 5);

    m_textCtrl1 = new wxTextCtrl(this, wxID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    bSizer81->Add(m_textCtrl1, 0, wxALL, 5);

    m_staticTextMessage2 = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextMessage2->Wrap(-1);
    m_staticTextMessage2->Hide();

    bSizer81->Add(m_staticTextMessage2, 0, wxTOP, 5);

    m_textCtrl2 = new wxTextCtrl(this, wxID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    m_textCtrl2->Hide();

    bSizer81->Add(m_textCtrl2, 0, wxALL, 5);


    bSizer81->Add(0, 0, 1, wxEXPAND, 5);

    bSizer79->Add(bSizer81, 1, wxEXPAND, 10);

    wxBoxSizer* bSizer80;
    bSizer80 = new wxBoxSizer(wxHORIZONTAL);


    bSizer80->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer80->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer80->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer79->Add(bSizer80, 0, wxEXPAND, 5);

    this->SetSizer(bSizer79);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(GetTextFromUserDialogBase::OnClose));
    m_textCtrl1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GetTextFromUserDialogBase::OnKeyDown), nullptr, this);
    m_textCtrl2->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GetTextFromUserDialogBase::OnKeyDown), nullptr, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GetTextFromUserDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GetTextFromUserDialogBase::OnButtonCancel), nullptr, this);
}

GetTextFromUserDialogBase::~GetTextFromUserDialogBase()
{
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(GetTextFromUserDialogBase::OnClose));
    m_textCtrl1->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(GetTextFromUserDialogBase::OnKeyDown), nullptr, this);
    m_textCtrl2->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(GetTextFromUserDialogBase::OnKeyDown), nullptr, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GetTextFromUserDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(GetTextFromUserDialogBase::OnButtonCancel), nullptr, this);
}