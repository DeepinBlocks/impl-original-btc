
#include "CPokerDialogBase.h"

CPokerDialogBase::CPokerDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer174;
    bSizer174 = new wxBoxSizer(wxVERTICAL);

    m_checkSitOut = new wxCheckBox(this, wxID_ANY, wxT("Deal Me Out"), wxDefaultPosition, wxDefaultSize, 0);

    bSizer174->Add(m_checkSitOut, 0, wxALL, 5);

    m_buttonDealHand = new wxButton(this, wxID_DEALHAND, wxT("&Deal Hand"), wxDefaultPosition, wxSize(150,25), 0);
    bSizer174->Add(m_buttonDealHand, 0, wxALL, 5);

    m_buttonFold = new wxButton(this, wxID_FOLD, wxT("&Fold"), wxDefaultPosition, wxSize(80,25), 0);
    bSizer174->Add(m_buttonFold, 0, wxALL, 5);

    m_buttonCall = new wxButton(this, wxID_CALL, wxT("&Call"), wxDefaultPosition, wxSize(80,25), 0);
    bSizer174->Add(m_buttonCall, 0, wxALL, 5);

    m_buttonRaise = new wxButton(this, wxID_RAISE, wxT("&Raise"), wxDefaultPosition, wxSize(80,25), 0);
    bSizer174->Add(m_buttonRaise, 0, wxALL, 5);

    m_buttonLeaveTable = new wxButton(this, wxID_LEAVETABLE, wxT("&Leave Table"), wxDefaultPosition, wxSize(90,25), 0);
    bSizer174->Add(m_buttonLeaveTable, 0, wxALL, 5);

    m_textDitchPlayer = new wxTextCtrl(this, wxID_DITCHPLAYER, wxEmptyString, wxDefaultPosition, wxSize(45,-1), wxTE_PROCESS_ENTER);
    bSizer174->Add(m_textDitchPlayer, 0, wxALL, 5);

    m_checkPreFold = new wxCheckBox(this, wxID_ANY, wxT("FOLD"), wxDefaultPosition, wxSize(100,-1), 0);

    bSizer174->Add(m_checkPreFold, 0, wxALL, 5);

    m_checkPreCall = new wxCheckBox(this, wxID_ANY, wxT("CALL"), wxDefaultPosition, wxSize(100,-1), 0);

    bSizer174->Add(m_checkPreCall, 0, wxALL, 5);

    m_checkPreCallAny = new wxCheckBox(this, wxID_ANY, wxT("CALL ANY"), wxDefaultPosition, wxSize(100,-1), 0);

    bSizer174->Add(m_checkPreCallAny, 0, wxALL, 5);

    m_checkPreRaise = new wxCheckBox(this, wxID_ANY, wxT("RAISE"), wxDefaultPosition, wxSize(100,-1), 0);

    bSizer174->Add(m_checkPreRaise, 0, wxALL, 5);

    m_checkPreRaiseAny = new wxCheckBox(this, wxID_ANY, wxT("RAISE ANY"), wxDefaultPosition, wxSize(100,-1), 0);

    bSizer174->Add(m_checkPreRaiseAny, 0, wxALL, 5);

    this->SetSizer(bSizer174);
    this->Layout();
    m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

    // Connect Events
    this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CPokerDialogBase::OnClose));
    this->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_MOTION, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(CPokerDialogBase::OnPaint));
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(CPokerDialogBase::OnSize));
    m_checkSitOut->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckSitOut), nullptr, this);
    m_buttonDealHand->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonDealHand), nullptr, this);
    m_buttonFold->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonFold), nullptr, this);
    m_buttonCall->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonCall), nullptr, this);
    m_buttonRaise->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonRaise), nullptr, this);
    m_buttonLeaveTable->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonLeaveTable), nullptr, this);
    m_textDitchPlayer->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(CPokerDialogBase::OnDitchPlayer), nullptr, this);
    m_checkPreFold->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreFold), nullptr, this);
    m_checkPreCall->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreCall), nullptr, this);
    m_checkPreCallAny->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreCallAny), nullptr, this);
    m_checkPreRaise->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreRaise), nullptr, this);
    m_checkPreRaiseAny->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreRaiseAny), nullptr, this);
}

CPokerDialogBase::~CPokerDialogBase()
{
    // Disconnect Events
    this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CPokerDialogBase::OnClose));
    this->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_MOTION, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CPokerDialogBase::OnMouseEvents));
    this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(CPokerDialogBase::OnPaint));
    this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(CPokerDialogBase::OnSize));
    m_checkSitOut->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckSitOut), nullptr, this);
    m_buttonDealHand->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonDealHand), nullptr, this);
    m_buttonFold->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonFold), nullptr, this);
    m_buttonCall->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonCall), nullptr, this);
    m_buttonRaise->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonRaise), nullptr, this);
    m_buttonLeaveTable->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnButtonLeaveTable), nullptr, this);
    m_textDitchPlayer->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(CPokerDialogBase::OnDitchPlayer), nullptr, this);
    m_checkPreFold->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreFold), nullptr, this);
    m_checkPreCall->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreCall), nullptr, this);
    m_checkPreCallAny->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreCallAny), nullptr, this);
    m_checkPreRaise->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreRaise), nullptr, this);
    m_checkPreRaiseAny->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(CPokerDialogBase::OnCheckPreRaiseAny), nullptr, this);
}