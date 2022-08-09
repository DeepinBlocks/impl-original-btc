#ifndef BITCOIN_COPTIONSDIALOGBASE_H
#define BITCOIN_COPTIONSDIALOGBASE_H

#include "common.h"

class COptionsDialogBase : wxDialog {
public:
    COptionsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,261), long style = wxDEFAULT_DIALOG_STYLE);
    ~COptionsDialogBase();
protected:
    wxStaticText* m_staticText32;
    wxStaticText* m_staticText31;
    wxTextCtrl* m_textCtrlTransactionFee;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

    virtual void OnKillFocusTransactionFee(wxFocusEvent& event){ event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_COPTIONSDIALOGBASE_H
