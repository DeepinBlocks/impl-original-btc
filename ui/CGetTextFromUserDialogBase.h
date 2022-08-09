#ifndef BITCOIN_CGETTEXTFROMUSERDIALOGBASE_H
#define BITCOIN_CGETTEXTFROMUSERDIALOGBASE_H

#include "common.h"

class CGetTextFromUserDialogBase : public wxDialog {
public:
    CGetTextFromUserDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(403,138), long style = wxDEFAULT_DIALOG_STYLE);
    ~CGetTextFromUserDialogBase();

protected:
    wxStaticText* m_staticTextMessage1;
    wxTextCtrl* m_textCtrl1;
    wxStaticText* m_staticTextMessage2;
    wxTextCtrl* m_textCtrl2;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }

};


#endif //BITCOIN_CGETTEXTFROMUSERDIALOGBASE_H
