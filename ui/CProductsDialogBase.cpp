#include "CProductsDialogBase.h"


CProductsDialogBase::CProductsDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer22;
    bSizer22 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer23;
    bSizer23 = new wxBoxSizer(wxHORIZONTAL);

    m_comboBoxCategory = new wxComboBox(this, wxID_ANY, wxT("(Any Category)"), wxDefaultPosition, wxSize(150,-1), 0, nullptr, 0);
    m_comboBoxCategory->Append(wxT("(Any Category)"));
    bSizer23->Add(m_comboBoxCategory, 0, wxALL, 5);

    m_textCtrlSearch = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer23->Add(m_textCtrlSearch, 1, wxALL, 5);

    m_buttonSearch = new wxButton(this, wxID_ANY, wxT("&Search"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer23->Add(m_buttonSearch, 0, wxALL, 5);

    bSizer22->Add(bSizer23, 0, wxEXPAND, 5);

    m_listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer22->Add(m_listCtrl, 1, wxALL, 5);

    this->SetSizer(bSizer22);
    this->Layout();

    // Connect Events
    m_comboBoxCategory->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(CProductsDialogBase::OnCombobox), nullptr, this);
    m_textCtrlSearch->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(CProductsDialogBase::OnKeyDown), nullptr, this);
    m_buttonSearch->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CProductsDialogBase::OnButtonSearch), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CProductsDialogBase::OnListItemActivated), nullptr, this);
}

CProductsDialogBase::~CProductsDialogBase()
{
    // Disconnect Events
    m_comboBoxCategory->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(CProductsDialogBase::OnCombobox), nullptr, this);
    m_textCtrlSearch->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(CProductsDialogBase::OnKeyDown), nullptr, this);
    m_buttonSearch->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CProductsDialogBase::OnButtonSearch), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(CProductsDialogBase::OnListItemActivated), nullptr, this);
}