#ifndef BITCOIN_SENDINGDIALOGBASE_H
#define BITCOIN_SENDINGDIALOGBASE_H

#include "common.h"


class SendingDialogBase : public wxDialog {
public:
    SendingDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sending..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(442, 151), long style = wxDEFAULT_DIALOG_STYLE);
    ~SendingDialogBase();
protected:
    wxStaticText* m_staticTextSending;
    wxTextCtrl* m_textCtrlStatus;

    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnPaint(wxPaintEvent& event){ event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_SENDINGDIALOGBASE_H
