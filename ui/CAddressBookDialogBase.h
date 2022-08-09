#ifndef BITCOIN_CADDRESSBOOKDIALOGBASE_H
#define BITCOIN_CADDRESSBOOKDIALOGBASE_H

#include "common.h"

class CAddressBookDialogBase : public wxDialog {
public:
    wxButton* m_buttonCancel;
    CAddressBookDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Address Book"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(610,390), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    ~CAddressBookDialogBase();

protected:
    wxStaticText* m_staticText55;
    wxListCtrl* m_listCtrl;
    wxButton* m_buttonEdit;
    wxButton* m_buttonNew;
    wxButton* m_buttonDelete;
    wxButton* m_buttonOK;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnListEndLabelEdit(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemActivated(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemSelected(wxListEvent& event){ event.Skip(); }
    virtual void OnButtonEdit(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonNew(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDelete(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CADDRESSBOOKDIALOGBASE_H
