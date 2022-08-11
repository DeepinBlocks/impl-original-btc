#ifndef BITCOIN_CEDITPRODUCTDIALOGBASE_H
#define BITCOIN_CEDITPRODUCTDIALOGBASE_H
#include "common.h"

class CEditProductDialogBase : public wxFrame {
public:
    wxFlexGridSizer* fgSizer5;
    CEditProductDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Edit Product"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(660,640), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL);
    ~CEditProductDialogBase();
protected:
    wxScrolledWindow* m_scrolledWindow;
    wxStaticText* m_staticText106;
    wxComboBox* m_comboBoxCategory;
    wxStaticText* m_staticText108;
    wxTextCtrl* m_textCtrlTitle;
    wxStaticText* m_staticText107;
    wxTextCtrl* m_textCtrlPrice;
    wxStaticText* m_staticText22;
    wxTextCtrl* m_textCtrlDescription;
    wxStaticText* m_staticText23;
    wxTextCtrl* m_textCtrlInstructions;
    wxStaticText* m_staticText24;
    wxStaticText* m_staticText25;

    wxTextCtrl* m_textCtrlLabel0;
    wxTextCtrl* m_textCtrlField0;
    wxButton* m_buttonDel0;
    wxTextCtrl* m_textCtrlLabel1;
    wxTextCtrl* m_textCtrlField1;
    wxButton* m_buttonDel1;
    wxTextCtrl* m_textCtrlLabel2;
    wxTextCtrl* m_textCtrlField2;
    wxButton* m_buttonDel2;
    wxTextCtrl* m_textCtrlLabel3;
    wxTextCtrl* m_textCtrlField3;
    wxButton* m_buttonDel3;
    wxTextCtrl* m_textCtrlLabel4;
    wxTextCtrl* m_textCtrlField4;
    wxButton* m_buttonDel4;
    wxTextCtrl* m_textCtrlLabel5;
    wxTextCtrl* m_textCtrlField5;
    wxButton* m_buttonDel5;
    wxTextCtrl* m_textCtrlLabel6;
    wxTextCtrl* m_textCtrlField6;
    wxButton* m_buttonDel6;
    wxTextCtrl* m_textCtrlLabel7;
    wxTextCtrl* m_textCtrlField7;
    wxButton* m_buttonDel7;
    wxTextCtrl* m_textCtrlLabel8;
    wxTextCtrl* m_textCtrlField8;
    wxButton* m_buttonDel8;
    wxTextCtrl* m_textCtrlLabel9;
    wxTextCtrl* m_textCtrlField9;
    wxButton* m_buttonDel9;
    wxTextCtrl* m_textCtrlLabel10;
    wxTextCtrl* m_textCtrlField10;
    wxButton* m_buttonDel10;
    wxTextCtrl* m_textCtrlLabel11;
    wxTextCtrl* m_textCtrlField11;
    wxButton* m_buttonDel11;
    wxTextCtrl* m_textCtrlLabel12;
    wxTextCtrl* m_textCtrlField12;
    wxButton* m_buttonDel12;
    wxTextCtrl* m_textCtrlLabel13;
    wxTextCtrl* m_textCtrlField13;
    wxButton* m_buttonDel13;
    wxTextCtrl* m_textCtrlLabel14;
    wxTextCtrl* m_textCtrlField14;
    wxButton* m_buttonDel14;
    wxTextCtrl* m_textCtrlLabel15;
    wxTextCtrl* m_textCtrlField15;
    wxButton* m_buttonDel15;
    wxTextCtrl* m_textCtrlLabel16;
    wxTextCtrl* m_textCtrlField16;
    wxButton* m_buttonDel16;
    wxTextCtrl* m_textCtrlLabel17;
    wxTextCtrl* m_textCtrlField17;
    wxButton* m_buttonDel17;
    wxTextCtrl* m_textCtrlLabel18;
    wxTextCtrl* m_textCtrlField18;
    wxButton* m_buttonDel18;
    wxTextCtrl* m_textCtrlLabel19;
    wxTextCtrl* m_textCtrlField19;
    wxButton* m_buttonDel19;
    wxButton* m_buttonAddField;
    wxButton* m_buttonOK;
    wxButton* m_buttonPreview;
    wxButton* m_buttonCancel;

    // Virtual event handlers, overide them in your derived class
    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnButtonDel0(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel1(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel2(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel3(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel4(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel5(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel6(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel7(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel8(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel9(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel10(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel11(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel12(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel13(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel14(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel15(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel16(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel17(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel18(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonDel19(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonAddField(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonSend(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonPreview(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonCancel(wxCommandEvent& event){ event.Skip(); }
};


#endif //BITCOIN_CEDITPRODUCTDIALOGBASE_H
