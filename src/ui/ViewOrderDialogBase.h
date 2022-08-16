#ifndef BITCOIN_VIEWORDERDIALOGBASE_H
#define BITCOIN_VIEWORDERDIALOGBASE_H

#include "common.h"

class ViewOrderDialogBase : public wxFrame {
public:
    ViewOrderDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("View Order"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(630, 520), long style = wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER | wxTAB_TRAVERSAL);
    ~ViewOrderDialogBase();

protected:
    wxHtmlWindow* m_htmlWin;
    wxButton* m_buttonOK;

    // Virtual event handlers, overide them in your derived class
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_VIEWORDERDIALOGBASE_H
