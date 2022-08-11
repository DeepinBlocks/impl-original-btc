#ifndef BITCOIN_CSENDDIALOGBASE_H
#define BITCOIN_CSENDDIALOGBASE_H

#include "common.h"

class CSendDialogBase : public wxDialog {
public:
    CSendDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Send Coins"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(675,338), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    ~CSendDialogBase();
protected:
    wxStaticText* m_staticText14;
    wxStaticBitmap* m_bitmapCheckMark;
    wxStaticText* m_staticText36;
    wxTextCtrl* m_textCtrlAddress;
    wxButton* m_buttonPaste;
    wxButton* m_buttonAddress;
    wxStaticText* m_staticText19;
    wxTextCtrl* m_textCtrlAmount;
    wxStaticText* m_staticText20;
    wxChoice* m_choiceTransferType;
    wxStaticText* m_staticTextFrom;
    wxTextCtrl* m_textCtrlFrom;
    wxStaticText* m_staticTextMessage;
    wxTextCtrl* m_textCtrlMessage;

    wxButton* m_buttonSend;
    wxButton* m_buttonCancel;

    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnTextAddress(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonPaste(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonAddressBook(wxCommandEvent& event){ event.Skip(); }
    virtual void OnKillFocusAmount(wxFocusEvent& event){ event.Skip(); }
    virtual void OnButtonSend(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CSENDDIALOGBASE_H
