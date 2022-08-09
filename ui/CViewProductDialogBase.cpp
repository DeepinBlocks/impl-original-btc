#include "CViewProductDialogBase.h"

CViewProductDialogBase::CViewProductDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer116;
    bSizer116 = new wxBoxSizer(wxHORIZONTAL);

    m_htmlWinReviews = new wxHtmlWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO);
    m_htmlWinReviews->Hide();

    bSizer116->Add(m_htmlWinReviews, 1, wxALL, 5);

    m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTAB_TRAVERSAL|wxVSCROLL);
    m_scrolledWindow->SetScrollRate(5, 5);
    m_scrolledWindow->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer(wxVERTICAL);

    m_richTextHeading = new wxRichTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,50), wxTE_READONLY|wxNO_BORDER);
    bSizer21->Add(m_richTextHeading, 0, wxEXPAND, 5);

    m_staticTextInstructions = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Order Form instructions here\nmultiple lines\n1\n2\n3\n4\n5\n6"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextInstructions->Wrap(-1);
    bSizer21->Add(m_staticTextInstructions, 0, wxALL, 5);

    wxBoxSizer* bSizer25;
    bSizer25 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonSubmitForm = new wxButton(m_scrolledWindow, wxID_BUTTONSAMPLE, wxT("&Submit"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer25->Add(m_buttonSubmitForm, 0, wxALL, 5);

    m_buttonCancelForm = new wxButton(m_scrolledWindow, wxID_CANCEL2, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer25->Add(m_buttonCancelForm, 0, wxALL, 5);

    bSizer21->Add(bSizer25, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    m_scrolledWindow->SetSizer(bSizer21);
    m_scrolledWindow->Layout();
    bSizer21->Fit(m_scrolledWindow);
    bSizer116->Add(m_scrolledWindow, 1, wxEXPAND, 5);

    bSizer20->Add(bSizer116, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer26;
    bSizer26 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonBack = new wxButton(this, wxID_BUTTONBACK, wxT("< &Back  "), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonBack->Enable(false);
    m_buttonBack->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonBack, 0, wxALL, 5);

    m_buttonNext = new wxButton(this, wxID_BUTTONNEXT, wxT("  &Next >"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonNext->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonNext, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer20->Add(bSizer26, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer20);
    this->Layout();

    // Connect Events
    m_buttonSubmitForm->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonSubmitForm), nullptr, this);
    m_buttonCancelForm->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonCancelForm), nullptr, this);
    m_buttonBack->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonBack), nullptr, this);
    m_buttonNext->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonNext), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonCancel), nullptr, this);
}

CViewProductDialogBase::~CViewProductDialogBase()
{
    // Disconnect Events
    m_buttonSubmitForm->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonSubmitForm), nullptr, this);
    m_buttonCancelForm->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonCancelForm), nullptr, this);
    m_buttonBack->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonBack), nullptr, this);
    m_buttonNext->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonNext), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CViewProductDialogBase::OnButtonCancel), nullptr, this);
}