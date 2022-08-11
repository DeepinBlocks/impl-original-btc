#ifndef BITCOIN_CEDITREVIEWDIALOGBASE_H
#define BITCOIN_CEDITREVIEWDIALOGBASE_H

#include "common.h"

class CEditReviewDialogBase : public wxFrame {
public:
    CEditReviewDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Enter Review"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(630,440), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL);
    ~CEditReviewDialogBase();

protected:
    wxStaticText* m_staticTextSeller;
    wxStaticText* m_staticText110;
    wxChoice* m_choiceStars;
    wxStaticText* m_staticText43;
    wxTextCtrl* m_textCtrlReview;
    wxButton* m_buttonSubmit;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnButtonSubmit(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CEDITREVIEWDIALOGBASE_H
