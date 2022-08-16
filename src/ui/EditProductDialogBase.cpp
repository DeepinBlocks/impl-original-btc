#include "EditProductDialogBase.h"

EditProductDialogBase::EditProductDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer(wxVERTICAL);

    m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTAB_TRAVERSAL|wxVSCROLL);
    m_scrolledWindow->SetScrollRate(5, 5);
    m_scrolledWindow->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer(wxVERTICAL);

    wxFlexGridSizer* fgSizer8;
    fgSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
    fgSizer8->AddGrowableCol(1);
    fgSizer8->SetFlexibleDirection(wxBOTH);
    fgSizer8->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    m_staticText106 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Category"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    m_staticText106->Wrap(-1);
    fgSizer8->Add(m_staticText106, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5);

    m_comboBoxCategory = new wxComboBox(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, nullptr, 0);
    m_comboBoxCategory->SetMinSize(wxSize(180,-1));

    fgSizer8->Add(m_comboBoxCategory, 0, wxALL, 5);

    m_staticText108 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Title"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    m_staticText108->Wrap(-1);
    fgSizer8->Add(m_staticText108, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5);

    m_textCtrlTitle = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    fgSizer8->Add(m_textCtrlTitle, 1, wxALL, 5);

    m_staticText107 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Price"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    m_staticText107->Wrap(-1);
    fgSizer8->Add(m_staticText107, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5);

    m_textCtrlPrice = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlPrice->SetMinSize(wxSize(105,-1));

    fgSizer8->Add(m_textCtrlPrice, 0, wxALL, 5);

    bSizer21->Add(fgSizer8, 0, wxEXPAND, 5);

    m_staticText22 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Page 1: Description"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText22->Wrap(-1);
    bSizer21->Add(m_staticText22, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    m_textCtrlDescription = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    m_textCtrlDescription->SetMinSize(wxSize(-1,170));

    bSizer21->Add(m_textCtrlDescription, 0, wxALL, 5);

    m_staticText23 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Page 2: Order Form"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText23->Wrap(-1);
    bSizer21->Add(m_staticText23, 0, wxTOP|wxRIGHT|wxLEFT, 5);

    m_textCtrlInstructions = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    m_textCtrlInstructions->SetMinSize(wxSize(-1,120));

    bSizer21->Add(m_textCtrlInstructions, 0, wxEXPAND, 5);

    fgSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
    fgSizer5->AddGrowableCol(1);
    fgSizer5->SetFlexibleDirection(wxBOTH);
    fgSizer5->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    m_staticText24 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Label"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText24->Wrap(-1);
    fgSizer5->Add(m_staticText24, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_staticText25 = new wxStaticText(m_scrolledWindow, wxID_ANY, wxT("Comma separated list of choices, or leave blank for text field"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText25->Wrap(-1);
    fgSizer5->Add(m_staticText25, 0, wxALIGN_CENTER_VERTICAL, 5);


    fgSizer5->Add(0, 0, 1, wxEXPAND, 5);

    m_textCtrlLabel0 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel0->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel0, 0, wxALL, 5);

    m_textCtrlField0 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField0, 0, wxALL, 5);

    m_buttonDel0 = new wxButton(m_scrolledWindow, wxID_DEL0, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel0, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel1 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel1->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel1, 0, wxALL, 5);

    m_textCtrlField1 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField1, 0, wxALL, 5);

    m_buttonDel1 = new wxButton(m_scrolledWindow, wxID_DEL1, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel1, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel2 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel2->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel2, 0, wxALL, 5);

    m_textCtrlField2 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField2, 0, wxALL, 5);

    m_buttonDel2 = new wxButton(m_scrolledWindow, wxID_DEL2, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel2, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel3 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel3->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel3, 0, wxALL, 5);

    m_textCtrlField3 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField3, 0, wxALL, 5);

    m_buttonDel3 = new wxButton(m_scrolledWindow, wxID_DEL3, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel3, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel4 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel4->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel4, 0, wxALL, 5);

    m_textCtrlField4 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField4, 0, wxALL, 5);

    m_buttonDel4 = new wxButton(m_scrolledWindow, wxID_DEL4, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel4, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel5 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel5->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel5, 0, wxALL, 5);

    m_textCtrlField5 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField5, 0, wxALL, 5);

    m_buttonDel5 = new wxButton(m_scrolledWindow, wxID_DEL5, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel5, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel6 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel6->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel6, 0, wxALL, 5);

    m_textCtrlField6 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField6, 0, wxALL, 5);

    m_buttonDel6 = new wxButton(m_scrolledWindow, wxID_DEL6, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel6, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel7 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel7->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel7, 0, wxALL, 5);

    m_textCtrlField7 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField7, 0, wxALL, 5);

    m_buttonDel7 = new wxButton(m_scrolledWindow, wxID_DEL7, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel7, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel8 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel8->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel8, 0, wxALL, 5);

    m_textCtrlField8 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField8, 0, wxALL, 5);

    m_buttonDel8 = new wxButton(m_scrolledWindow, wxID_DEL8, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel8, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel9 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel9->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel9, 0, wxALL, 5);

    m_textCtrlField9 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField9, 0, wxALL, 5);

    m_buttonDel9 = new wxButton(m_scrolledWindow, wxID_DEL9, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel9, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel10 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel10->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel10, 0, wxALL, 5);

    m_textCtrlField10 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField10, 0, wxALL, 5);

    m_buttonDel10 = new wxButton(m_scrolledWindow, wxID_DEL10, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel10, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel11 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel11->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel11, 0, wxALL, 5);

    m_textCtrlField11 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField11, 0, wxALL, 5);

    m_buttonDel11 = new wxButton(m_scrolledWindow, wxID_DEL11, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel11, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel12 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel12->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel12, 0, wxALL, 5);

    m_textCtrlField12 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField12, 0, wxALL, 5);

    m_buttonDel12 = new wxButton(m_scrolledWindow, wxID_DEL12, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel12, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel13 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel13->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel13, 0, wxALL, 5);

    m_textCtrlField13 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField13, 0, wxALL, 5);

    m_buttonDel13 = new wxButton(m_scrolledWindow, wxID_DEL13, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel13, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel14 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel14->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel14, 0, wxALL, 5);

    m_textCtrlField14 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField14, 0, wxALL, 5);

    m_buttonDel14 = new wxButton(m_scrolledWindow, wxID_DEL14, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel14, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel15 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel15->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel15, 0, wxALL, 5);

    m_textCtrlField15 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField15, 0, wxALL, 5);

    m_buttonDel15 = new wxButton(m_scrolledWindow, wxID_DEL15, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel15, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel16 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel16->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel16, 0, wxALL, 5);

    m_textCtrlField16 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField16, 0, wxALL, 5);

    m_buttonDel16 = new wxButton(m_scrolledWindow, wxID_DEL16, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel16, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel17 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel17->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel17, 0, wxALL, 5);

    m_textCtrlField17 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField17, 0, wxALL, 5);

    m_buttonDel17 = new wxButton(m_scrolledWindow, wxID_DEL17, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel17, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel18 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel18->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel18, 0, wxALL, 5);

    m_textCtrlField18 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField18, 0, wxALL, 5);

    m_buttonDel18 = new wxButton(m_scrolledWindow, wxID_DEL18, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel18, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_textCtrlLabel19 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_textCtrlLabel19->SetMinSize(wxSize(150,-1));

    fgSizer5->Add(m_textCtrlLabel19, 0, wxALL, 5);

    m_textCtrlField19 = new wxTextCtrl(m_scrolledWindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
    fgSizer5->Add(m_textCtrlField19, 0, wxALL, 5);

    m_buttonDel19 = new wxButton(m_scrolledWindow, wxID_DEL19, wxT("Delete"), wxDefaultPosition, wxSize(60,20), 0);
    fgSizer5->Add(m_buttonDel19, 0, wxALIGN_CENTER_VERTICAL, 5);

    bSizer21->Add(fgSizer5, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer25;
    bSizer25 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonAddField = new wxButton(m_scrolledWindow, wxID_ANY, wxT("&Add Field"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer25->Add(m_buttonAddField, 0, wxALL, 5);

    bSizer21->Add(bSizer25, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    m_scrolledWindow->SetSizer(bSizer21);
    m_scrolledWindow->Layout();
    bSizer21->Fit(m_scrolledWindow);
    bSizer20->Add(m_scrolledWindow, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer26;
    bSizer26 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonOK = new wxButton(this, wxID_BUTTONSEND, wxT("&Send"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonOK->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonOK, 0, wxALL, 5);

    m_buttonPreview = new wxButton(this, wxID_BUTTONPREVIEW, wxT("&Preview"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonPreview->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonPreview, 0, wxALL, 5);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    m_buttonCancel->SetMinSize(wxSize(85,25));

    bSizer26->Add(m_buttonCancel, 0, wxALL, 5);

    bSizer20->Add(bSizer26, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer20);
    this->Layout();

    // Connect Events
    m_textCtrlTitle->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlPrice->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlDescription->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlInstructions->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlLabel0->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField0->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel0->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel0), nullptr, this);
    m_textCtrlLabel1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField1->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel1), nullptr, this);
    m_textCtrlLabel2->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField2->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel2), nullptr, this);
    m_textCtrlLabel3->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField3->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel3), nullptr, this);
    m_textCtrlLabel4->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField4->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel4), nullptr, this);
    m_textCtrlLabel5->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField5->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel5), nullptr, this);
    m_textCtrlLabel6->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField6->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel6), nullptr, this);
    m_textCtrlLabel7->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField7->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel7), nullptr, this);
    m_textCtrlLabel8->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField8->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel8), nullptr, this);
    m_textCtrlLabel9->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField9->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel9->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel9), nullptr, this);
    m_textCtrlLabel10->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField10->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel10->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel10), nullptr, this);
    m_textCtrlLabel11->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField11->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel11->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel11), nullptr, this);
    m_textCtrlLabel12->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField12->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel12->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel12), nullptr, this);
    m_textCtrlLabel13->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField13->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel13->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel13), nullptr, this);
    m_textCtrlLabel14->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField14->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel14->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel14), nullptr, this);
    m_textCtrlLabel15->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField15->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel15->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel15), nullptr, this);
    m_textCtrlLabel16->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField16->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel16->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel16), nullptr, this);
    m_textCtrlLabel17->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField17->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel17->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel17), nullptr, this);
    m_textCtrlLabel18->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField18->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel18->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel18), nullptr, this);
    m_textCtrlLabel19->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField19->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel19->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel19), nullptr, this);
    m_buttonAddField->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonAddField), nullptr, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonSend), nullptr, this);
    m_buttonPreview->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonPreview), nullptr, this);
    m_buttonCancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonCancel), nullptr, this);
}

EditProductDialogBase::~EditProductDialogBase()
{
    // Disconnect Events
    m_textCtrlTitle->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlPrice->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlDescription->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlInstructions->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlLabel0->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField0->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel0->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel0), nullptr, this);
    m_textCtrlLabel1->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField1->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel1), nullptr, this);
    m_textCtrlLabel2->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField2->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel2->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel2), nullptr, this);
    m_textCtrlLabel3->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField3->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel3->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel3), nullptr, this);
    m_textCtrlLabel4->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField4->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel4->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel4), nullptr, this);
    m_textCtrlLabel5->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField5->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel5->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel5), nullptr, this);
    m_textCtrlLabel6->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField6->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel6->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel6), nullptr, this);
    m_textCtrlLabel7->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField7->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel7->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel7), nullptr, this);
    m_textCtrlLabel8->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField8->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel8->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel8), nullptr, this);
    m_textCtrlLabel9->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField9->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel9->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel9), nullptr, this);
    m_textCtrlLabel10->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField10->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel10->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel10), nullptr, this);
    m_textCtrlLabel11->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField11->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel11->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel11), nullptr, this);
    m_textCtrlLabel12->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField12->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel12->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel12), nullptr, this);
    m_textCtrlLabel13->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField13->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel13->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel13), nullptr, this);
    m_textCtrlLabel14->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField14->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel14->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel14), nullptr, this);
    m_textCtrlLabel15->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField15->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel15->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel15), nullptr, this);
    m_textCtrlLabel16->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField16->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel16->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel16), nullptr, this);
    m_textCtrlLabel17->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField17->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel17->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel17), nullptr, this);
    m_textCtrlLabel18->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField18->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel18->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel18), nullptr, this);
    m_textCtrlLabel19->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_textCtrlField19->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(EditProductDialogBase::OnKeyDown), nullptr, this);
    m_buttonDel19->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonDel19), nullptr, this);
    m_buttonAddField->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonAddField), nullptr, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonSend), nullptr, this);
    m_buttonPreview->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonPreview), nullptr, this);
    m_buttonCancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditProductDialogBase::OnButtonCancel), nullptr, this);
}