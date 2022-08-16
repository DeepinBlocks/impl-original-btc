#include "SendingDialogBase.h"


SendingDialogBase::SendingDialogBase(wxWindow* parent,
                                     wxWindowID id,
                                     const wxString& title,
                                     const wxPoint& pos,
                                     const wxSize& size,
                                     long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer68;
    bSizer68 = new wxBoxSizer(wxVERTICAL);

    m_staticTextSending = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,14), 0);
    m_staticTextSending->Wrap(-1);
    bSizer68->Add(m_staticTextSending, 0, wxALIGN_CENTER_VERTICAL, 8);

    m_textCtrlStatus = new wxTextCtrl(this, wxID_ANY, wxT("\n\nConnecting..."), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER);
    m_textCtrlStatus->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    bSizer68->Add(m_textCtrlStatus, 1, wxEXPAND, 10);

    wxBoxSizer* bSizer69;
    bSizer69 = new wxBoxSizer(wxHORIZONTAL);


    bSizer69->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonOK = new wxButton(this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonOK->Enable(false);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer69->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer68->Add(bSizer69, 0, wxEXPAND, 5);

    this->SetSizer(bSizer68);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SendingDialogBase::OnClose));
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(SendingDialogBase::OnPaint));
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendingDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendingDialogBase::OnButtonCancel), nullptr, this);
}

SendingDialogBase::~SendingDialogBase()
{
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SendingDialogBase::OnClose));
    this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SendingDialogBase::OnPaint));
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendingDialogBase::OnButtonOK), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendingDialogBase::OnButtonCancel), nullptr, this);
}