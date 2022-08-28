#ifndef BITCOIN_TXDETAILSDIALOGBASE_H
#define BITCOIN_TXDETAILSDIALOGBASE_H

#include "common.h"
#include "ui.h"

class TxDetailsDialogBase : public wxDialog {
public:
    TxDetailsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Transaction Details"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(620,450), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    ~TxDetailsDialogBase();
protected:
    wxHtmlWindow* m_htmlWin;
    wxButton* m_buttonOK;

    virtual void OnButtonOK(wxCommandEvent& event) { event.Skip(); }
};


#endif //BITCOIN_TXDETAILSDIALOGBASE_H
