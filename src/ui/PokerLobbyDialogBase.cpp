#include "PokerLobbyDialogBase.h"


PokerLobbyDialogBase::PokerLobbyDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    wxBoxSizer* bSizer156;
    bSizer156 = new wxBoxSizer(wxHORIZONTAL);

    m_treeCtrl = new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_HIDE_ROOT|wxTR_LINES_AT_ROOT);
    m_treeCtrl->SetMinSize(wxSize(130,-1));

    bSizer156->Add(m_treeCtrl, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer172;
    bSizer172 = new wxBoxSizer(wxVERTICAL);

    m_listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT);
    bSizer172->Add(m_listCtrl, 1, wxEXPAND, 5);

    m_buttonNewTable = new wxButton(this, wxID_OPENNEWTABLE, wxT("&Open New Table"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer172->Add(m_buttonNewTable, 0, wxALL, 5);

    bSizer156->Add(bSizer172, 1, wxEXPAND, 5);

    this->SetSizer(bSizer156);
    this->Layout();

    // Connect Events
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler(PokerLobbyDialogBase::OnTreeSelChanged), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(PokerLobbyDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(PokerLobbyDialogBase::OnListItemSelected), nullptr, this);
    m_buttonNewTable->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PokerLobbyDialogBase::OnButtonNewTable), nullptr, this);
}

PokerLobbyDialogBase::~PokerLobbyDialogBase()
{
    // Disconnect Events
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler(PokerLobbyDialogBase::OnTreeSelChanged), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler(PokerLobbyDialogBase::OnListItemActivated), nullptr, this);
    m_listCtrl->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler(PokerLobbyDialogBase::OnListItemSelected), nullptr, this);
    m_buttonNewTable->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PokerLobbyDialogBase::OnButtonNewTable), nullptr, this);
}