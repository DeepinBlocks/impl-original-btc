#ifndef BITCOIN_PRODUCTSDIALOGBASE_H
#define BITCOIN_PRODUCTSDIALOGBASE_H

#include "common.h"

class ProductsDialogBase : public wxDialog {
public:
    ProductsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Marketplace"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(708, 535), long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    ~ProductsDialogBase();

protected:
    wxComboBox* m_comboBoxCategory;
    wxTextCtrl* m_textCtrlSearch;
    wxButton* m_buttonSearch;
    wxListCtrl* m_listCtrl;

    // Virtual event handlers, overide them in your derived class
    virtual void OnCombobox(wxCommandEvent& event){ event.Skip(); }
    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnButtonSearch(wxCommandEvent& event){ event.Skip(); }
    virtual void OnListItemActivated(wxListEvent& event){ event.Skip(); }
};


#endif //BITCOIN_PRODUCTSDIALOGBASE_H
