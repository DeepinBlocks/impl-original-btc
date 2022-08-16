#ifndef BITCOIN_POKERLOBBYDIALOGBASE_H
#define BITCOIN_POKERLOBBYDIALOGBASE_H

#include "common.h"

class PokerLobbyDialogBase : public wxFrame {
public:
    PokerLobbyDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Poker Lobby"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(586, 457), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
    ~PokerLobbyDialogBase();

protected:
    wxTreeCtrl* m_treeCtrl;
    wxListCtrl* m_listCtrl;
    wxButton* m_buttonNewTable;

    // Virtual event handlers, overide them in your derived class
    virtual void OnTreeSelChanged(wxTreeEvent& event){ event.Skip(); }
    virtual void OnListItemActivated(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemSelected(wxListEvent& event){ event.Skip(); }
    virtual void OnButtonNewTable(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_POKERLOBBYDIALOGBASE_H
