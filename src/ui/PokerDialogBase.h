#ifndef BITCOIN_POKERDIALOGBASE_H
#define BITCOIN_POKERDIALOGBASE_H

#include "common.h"

class PokerDialogBase : public wxFrame {
public:
    wxCheckBox* m_checkSitOut;
    wxCheckBox* m_checkPreFold;
    wxCheckBox* m_checkPreCall;
    wxCheckBox* m_checkPreCallAny;
    wxCheckBox* m_checkPreRaise;
    wxCheckBox* m_checkPreRaiseAny;
    wxStatusBar* m_statusBar;
    PokerDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Poker"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(806, 550), long style = wxDEFAULT_FRAME_STYLE | wxFRAME_NO_TASKBAR | wxFULL_REPAINT_ON_RESIZE | wxTAB_TRAVERSAL);
    ~PokerDialogBase();

protected:
    wxButton* m_buttonDealHand;
    wxButton* m_buttonFold;
    wxButton* m_buttonCall;
    wxButton* m_buttonRaise;
    wxButton* m_buttonLeaveTable;
    wxTextCtrl* m_textDitchPlayer;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnMouseEvents(wxMouseEvent& event){ event.Skip(); }
    virtual void OnPaint(wxPaintEvent& event){ event.Skip(); }
    virtual void OnSize(wxSizeEvent& event){ event.Skip(); }
    virtual void OnCheckSitOut(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDealHand(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonFold(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCall(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonRaise(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonLeaveTable(wxCommandEvent& event){ event.Skip(); }
    virtual void OnDitchPlayer(wxCommandEvent& event){ event.Skip(); }
    virtual void OnCheckPreFold(wxCommandEvent& event){ event.Skip(); }
    virtual void OnCheckPreCall(wxCommandEvent& event){ event.Skip(); }
    virtual void OnCheckPreCallAny(wxCommandEvent& event){ event.Skip(); }
    virtual void OnCheckPreRaise(wxCommandEvent& event){ event.Skip(); }
    virtual void OnCheckPreRaiseAny(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_POKERDIALOGBASE_H
