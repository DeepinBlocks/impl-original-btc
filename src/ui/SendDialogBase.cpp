#include "SendDialogBase.h"

SendDialogBase::SendDialogBase(wxWindow* parent,
                               wxWindowID id,
                               const wxString& title,
                               const wxPoint& pos,
                               const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer(wxVERTICAL);


    bSizer21->Add(0, 5, 0, wxEXPAND, 5);

    wxFlexGridSizer* fgSizer1;
    fgSizer1 = new wxFlexGridSizer(3, 2, 0, 0);
    fgSizer1->AddGrowableCol(1);
    fgSizer1->SetFlexibleDirection(wxBOTH);
    fgSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);


    fgSizer1->Add(0, 0, 0, wxEXPAND, 5);

    m_staticText14 = new wxStaticText(this, wxID_ANY, wxT("Enter the recipient's IP address (e.g. 123.45.6.7) for online transfer with comments and confirmation, \nor bitcoin address (e.g. 1NS17iag9jJgTHD1VXjvLCEnZuQ3rJED9L) if recipient is not online."), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText14->Wrap(-1);
    fgSizer1->Add(m_staticText14, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    wxBoxSizer* bSizer47;
    bSizer47 = new wxBoxSizer(wxHORIZONTAL);

    bSizer47->SetMinSize(wxSize(70,-1));

    bSizer47->Add(0, 0, 1, wxEXPAND, 5);
    // wxICON
    m_bitmapCheckMark = new wxStaticBitmap(this, wxID_ANY, wxIcon(), wxDefaultPosition, wxSize(16,16), 0);
    bSizer47->Add(m_bitmapCheckMark, 0, wxALL, 5);

    m_staticText36 = new wxStaticText(this, wxID_ANY, wxT("Pay &To:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_staticText36->Wrap(-1);
    bSizer47->Add(m_staticText36, 0, wxALIGN_CENTER_VERTICAL, 5);

    fgSizer1->Add(bSizer47, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer19;
    bSizer19 = new wxBoxSizer(wxHORIZONTAL);

    m_textCtrlAddress = new wxTextCtrl(this, wxID_TEXTCTRLPAYTO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer19->Add(m_textCtrlAddress, 1, wxALIGN_CENTER_VERTICAL, 5);

    m_buttonPaste = new wxButton(this, wxID_BUTTONPASTE, wxT("&Paste"), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    bSizer19->Add(m_buttonPaste, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_buttonAddress = new wxButton(this, wxID_BUTTONADDRESSBOOK, wxT(" Address &Book..."), wxDefaultPosition, wxDefaultSize, 0);
    bSizer19->Add(m_buttonAddress, 0, wxALIGN_CENTER_VERTICAL, 5);

    fgSizer1->Add(bSizer19, 1, wxEXPAND, 5);

    m_staticText19 = new wxStaticText(this, wxID_ANY, wxT("&Amount:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_staticText19->Wrap(-1);
    fgSizer1->Add(m_staticText19, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlAmount = new wxTextCtrl(this, wxID_TEXTCTRLAMOUNT, wxEmptyString, wxDefaultPosition, wxSize(145,-1), 0);
    m_textCtrlAmount->SetMaxLength(20);
    m_textCtrlAmount->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    fgSizer1->Add(m_textCtrlAmount, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_staticText20 = new wxStaticText(this, wxID_ANY, wxT("T&ransfer:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_staticText20->Wrap(-1);
    fgSizer1->Add(m_staticText20, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5);

    wxString m_choiceTransferTypeChoices[] = { wxT(" Standard") };
    int m_choiceTransferTypeNChoices = sizeof(m_choiceTransferTypeChoices) / sizeof(wxString);
    m_choiceTransferType = new wxChoice(this, wxID_CHOICETRANSFERTYPE, wxDefaultPosition, wxDefaultSize, m_choiceTransferTypeNChoices, m_choiceTransferTypeChoices, 0);
    m_choiceTransferType->SetSelection(0);
    fgSizer1->Add(m_choiceTransferType, 0, wxALIGN_CENTER_VERTICAL, 5);

    bSizer21->Add(fgSizer1, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer672;
    bSizer672 = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer* bSizer681;
    bSizer681 = new wxBoxSizer(wxVERTICAL);

    m_staticTextFrom = new wxStaticText(this, wxID_ANY, wxT("&From:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextFrom->Wrap(-1);
    bSizer681->Add(m_staticTextFrom, 0, wxBOTTOM|wxLEFT, 5);

    m_textCtrlFrom = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    bSizer681->Add(m_textCtrlFrom, 0, wxLEFT, 5);

    bSizer672->Add(bSizer681, 1, wxEXPAND, 5);

    bSizer21->Add(bSizer672, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer67;
    bSizer67 = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer* bSizer68;
    bSizer68 = new wxBoxSizer(wxVERTICAL);

    m_staticTextMessage = new wxStaticText(this, wxID_ANY, wxT("&Message:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextMessage->Wrap(-1);
    bSizer68->Add(m_staticTextMessage, 0, wxTOP|wxBOTTOM|wxLEFT, 5);

    m_textCtrlMessage = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    bSizer68->Add(m_textCtrlMessage, 1, wxEXPAND, 5);

    bSizer67->Add(bSizer68, 1, wxEXPAND, 5);

    bSizer21->Add(bSizer67, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer23;
    bSizer23 = new wxBoxSizer(wxHORIZONTAL);


    bSizer23->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonSend = new wxButton(this, wxID_BUTTONSEND, wxT("&Send"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonSend->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));
    m_buttonSend->SetMinSize(wxSize(85,25));

    bSizer23->Add(m_buttonSend, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer23->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer21->Add(bSizer23, 0, wxEXPAND, 5);

    this->SetSizer(bSizer21);
    this->Layout();

    // Connect Events
    m_textCtrlAddress->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlAddress->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(SendDialogBase::OnTextAddress), nullptr, this);
    m_buttonPaste->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonPaste), nullptr, this);
    m_buttonAddress->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonAddressBook), nullptr, this);
    m_textCtrlAmount->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlAmount->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(SendDialogBase::OnKillFocusAmount), nullptr, this);
    m_textCtrlFrom->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlMessage->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_buttonSend->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonSend), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonCancel), nullptr, this);
}

SendDialogBase::~SendDialogBase()
{
    // Disconnect Events
    m_textCtrlAddress->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlAddress->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(SendDialogBase::OnTextAddress), nullptr, this);
    m_buttonPaste->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonPaste), nullptr, this);
    m_buttonAddress->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonAddressBook), nullptr, this);
    m_textCtrlAmount->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlAmount->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(SendDialogBase::OnKillFocusAmount), nullptr, this);
    m_textCtrlFrom->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlMessage->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(SendDialogBase::OnKeyDown), nullptr, this);
    m_buttonSend->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonSend), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SendDialogBase::OnButtonCancel), nullptr, this);
}