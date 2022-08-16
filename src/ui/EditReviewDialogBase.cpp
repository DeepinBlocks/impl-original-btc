#include "EditReviewDialogBase.h"

EditReviewDialogBase::EditReviewDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

    wxBoxSizer* bSizer112;
    bSizer112 = new wxBoxSizer(wxVERTICAL);


    bSizer112->Add(0, 3, 0, 0, 5);

    m_staticTextSeller = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextSeller->Wrap(-1);
    bSizer112->Add(m_staticTextSeller, 0, wxALL, 5);


    bSizer112->Add(0, 3, 0, 0, 5);

    m_staticText110 = new wxStaticText(this, wxID_ANY, wxT("Rating"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText110->Wrap(-1);
    bSizer112->Add(m_staticText110, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    wxString m_choiceStarsChoices[] = { wxT(" 1 star"), wxT(" 2 stars"), wxT(" 3 stars"), wxT(" 4 stars"), wxT(" 5 stars") };
    int m_choiceStarsNChoices = sizeof(m_choiceStarsChoices) / sizeof(wxString);
    m_choiceStars = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceStarsNChoices, m_choiceStarsChoices, 0);
    m_choiceStars->SetSelection(0);
    bSizer112->Add(m_choiceStars, 0, wxALL, 5);

    m_staticText43 = new wxStaticText(this, wxID_ANY, wxT("Review"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText43->Wrap(-1);
    bSizer112->Add(m_staticText43, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    m_textCtrlReview = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    bSizer112->Add(m_textCtrlReview, 1, wxALL, 5);

    wxBoxSizer* bSizer113;
    bSizer113 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonSubmit = new wxButton(this, wxID_SUBMIT, wxT("&Submit"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonSubmit->SetMinSize(wxSize(85,25));

    bSizer113->Add(m_buttonSubmit, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer113->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer112->Add(bSizer113, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer112);
    this->Layout();

    // Connect Events
    m_textCtrlReview->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditReviewDialogBase::OnKeyDown), nullptr, this);
    m_buttonSubmit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditReviewDialogBase::OnButtonSubmit), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditReviewDialogBase::OnButtonCancel), nullptr, this);
}

EditReviewDialogBase::~EditReviewDialogBase()
{
    // Disconnect Events
    m_textCtrlReview->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditReviewDialogBase::OnKeyDown), nullptr, this);
    m_buttonSubmit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditReviewDialogBase::OnButtonSubmit), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditReviewDialogBase::OnButtonCancel), nullptr, this);
}