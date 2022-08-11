#ifndef BITCOIN_CVIEWORDERDIALOGBASE_H
#define BITCOIN_CVIEWORDERDIALOGBASE_H

#include "common.h"

class CViewOrderDialogBase : public wxFrame {
public:
    CViewOrderDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("View Order"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(630,520), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL);
    ~CViewOrderDialogBase();

protected:
    wxHtmlWindow* m_htmlWin;
    wxButton* m_buttonOK;

    // Virtual event handlers, overide them in your derived class
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CVIEWORDERDIALOGBASE_H
