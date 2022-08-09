#ifndef BITCOIN_CVIEWPRODUCTDIALOGBASE_H
#define BITCOIN_CVIEWPRODUCTDIALOGBASE_H

#include "common.h"

class CViewProductDialogBase : public wxFrame {
public:
    CViewProductDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Order Form"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(630,520), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL);
    ~CViewProductDialogBase();

protected:
    wxHtmlWindow* m_htmlWinReviews;
    wxScrolledWindow* m_scrolledWindow;
    wxRichTextCtrl* m_richTextHeading;
    wxStaticText* m_staticTextInstructions;
    wxButton* m_buttonSubmitForm;
    wxButton* m_buttonCancelForm;
    wxButton* m_buttonBack;
    wxButton* m_buttonNext;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnButtonSubmitForm(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancelForm(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonBack(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonNext(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CVIEWPRODUCTDIALOGBASE_H
