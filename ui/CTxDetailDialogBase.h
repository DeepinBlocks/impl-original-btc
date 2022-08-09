#ifndef BITCOIN_CTXDETAILDIALOGBASE_H
#define BITCOIN_CTXDETAILDIALOGBASE_H

#include "common.h"

class CTxDetailsDialogBase : public wxDialog {
public:
    CTxDetailsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Transaction Details"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(620,450), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    ~CTxDetailsDialogBase();
protected:
    wxHtmlWindow* m_htmlWin;
    wxButton* m_buttonOK;

    virtual void OnButtonOK(wxCommandEvent& event) { event.Skip(); }
};


#endif //BITCOIN_CTXDETAILDIALOGBASE_H
