#ifndef BITCOIN_YOURADDRESSDIALOGBASE_H
#define BITCOIN_YOURADDRESSDIALOGBASE_H

#include "common.h"

class YourAddressDialogBase : public wxDialog {
public:
    YourAddressDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Your Bitcoin Address"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(610, 390), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    ~YourAddressDialogBase();

protected:
    wxStaticText* m_staticText45;
    wxListCtrl* m_listCtrl;
    wxButton* m_buttonRename;
    wxButton* m_buttonNew;
    wxButton* m_buttonCopy;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnListEndLabelEdit(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemActivated(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemSelected(wxListEvent& event){ event.Skip(); }
    virtual void OnButtonRename(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonNew(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCopy(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_YOURADDRESSDIALOGBASE_H
