#ifndef BITCOIN_CABOUTDIALOGBASE_H
#define BITCOIN_CABOUTDIALOGBASE_H
#include "common.h"

class CAboutDialogBase : public wxDialog {
public:
    wxStaticText* m_staticTextVersion;
    CAboutDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About Bitcoin"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(507,298), long style = wxDEFAULT_DIALOG_STYLE);
    ~CAboutDialogBase();
protected:
    wxStaticText* m_staticText40;
    wxStaticText* m_staticTextMain;
    wxButton* m_buttonOK;

    virtual void OnButtonOK(wxCommandEvent& event){ event.Skip(); }

};


#endif //BITCOIN_CABOUTDIALOGBASE_H
