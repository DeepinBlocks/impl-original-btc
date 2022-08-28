#ifndef BTC_CMAINFRAMEBASE_H
#define BTC_CMAINFRAMEBASE_H

#include "common.h"

#define wxID_MAINFRAME 1000
#define wxID_OPTIONSGENERATEBITCOINS 1001
#define wxID_BUTTONSEND 1002
#define wxID_BUTTONRECEIVE 1003
#define wxID_TEXTCTRLADDRESS 1004
#define wxID_BUTTONCOPY 1005
#define wxID_BUTTONCHANGE 1006
#define wxID_TRANSACTIONFEE 1007
#define wxID_TEXTCTRLPAYTO 1008
#define wxID_BUTTONPASTE 1009
#define wxID_BUTTONADDRESSBOOK 1010
#define wxID_TEXTCTRLAMOUNT 1011
#define wxID_CHOICETRANSFERTYPE 1012
#define wxID_LISTCTRL 1013
#define wxID_BUTTONRENAME 1014
#define wxID_BUTTONNEW 1015
#define wxID_BUTTONEDIT 1016
#define wxID_BUTTONDELETE 1017
#define wxID_DEL0 1018
#define wxID_DEL1 1019
#define wxID_DEL2 1020
#define wxID_DEL3 1021
#define wxID_DEL4 1022
#define wxID_DEL5 1023
#define wxID_DEL6 1024
#define wxID_DEL7 1025
#define wxID_DEL8 1026
#define wxID_DEL9 1027
#define wxID_DEL10 1028
#define wxID_DEL11 1029
#define wxID_DEL12 1030
#define wxID_DEL13 1031
#define wxID_DEL14 1032
#define wxID_DEL15 1033
#define wxID_DEL16 1034
#define wxID_DEL17 1035
#define wxID_DEL18 1036
#define wxID_DEL19 1037
#define wxID_BUTTONPREVIEW 1038
#define wxID_BUTTONSAMPLE 1039
#define wxID_CANCEL2 1040
#define wxID_BUTTONBACK 1041
#define wxID_BUTTONNEXT 1042
#define wxID_SUBMIT 1043
#define wxID_OPENNEWTABLE 1044
#define wxID_DEALHAND 1045
#define wxID_FOLD 1046
#define wxID_CALL 1047
#define wxID_RAISE 1048
#define wxID_LEAVETABLE 1049
#define wxID_DITCHPLAYER 1050
#define wxID_TEXTCTRL 1051


class MainFrameBase: public wxFrame {
protected:
    wxMenuBar* m_menubar;
    wxMenu* m_menuFile;
    wxMenu* m_menuHelp;
    wxToolBar* m_toolBar;
    wxStatusBar* m_statusBar;

    wxStaticText* m_staticText32;
    wxTextCtrl* m_textCtrlAddress;
    wxButton* m_buttonCopy;
    wxButton* m_button91;

    wxPanel* m_panel14;
    wxStaticText* m_staticText41;
    wxStaticText* m_staticTextBalance;

    wxChoice* m_choiceFilter;
    wxNotebook* m_notebook;
    wxPanel* m_panel7;
    wxPanel* m_panel9;
    wxPanel* m_panel8;
    wxPanel* m_panel10;
    wxPanel* m_panel11;

    // Virtual event handlers, overide them in your derived class
    virtual void OnClose(wxCloseEvent& event){ event.Skip(); }
    virtual void OnIdle(wxIdleEvent& event){ event.Skip(); }
    virtual void OnMouseEvents(wxMouseEvent& event){ event.Skip(); }
    virtual void OnPaint(wxPaintEvent& event){ event.Skip(); }
    virtual void OnMenuFileExit(wxCommandEvent& event){ event.Skip(); }
    virtual void OnMenuOptionsGenerate(wxCommandEvent& event){ event.Skip(); }
    virtual void OnMenuOptionsOptions(wxCommandEvent& event){ event.Skip(); }
    virtual void OnMenuHelpAbout(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonSend(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonAddressBook(wxCommandEvent& event){ event.Skip(); }
    virtual void OnKeyDown(wxKeyEvent& event){ event.Skip(); }
    virtual void OnMouseEventsAddress(wxMouseEvent& event){ event.Skip(); }
    virtual void OnSetFocusAddress(wxFocusEvent& event){ event.Skip(); }
    virtual void OnButtonCopy(wxCommandEvent& event){ event.Skip(); }
    virtual void OnButtonChange(wxCommandEvent& event){ event.Skip(); }
    virtual void OnListColBeginDrag(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemActivatedAllTransactions(wxListEvent& event){ event.Skip(); }
    virtual void OnPaintListCtrl(wxPaintEvent& event){ event.Skip(); }
    virtual void OnListItemActivatedOrdersSent(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemActivatedProductsSent(wxListEvent& event){ event.Skip(); }
    virtual void OnListItemActivatedOrdersReceived(wxListEvent& event){ event.Skip(); }


public:
    wxMenu* m_menuOptions;
    wxListCtrl* m_listCtrl;
    wxListCtrl* m_listCtrlEscrows;
    wxListCtrl* m_listCtrlOrdersSent;
    wxListCtrl* m_listCtrlProductsSent;
    wxListCtrl* m_listCtrlOrdersReceived;
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_MAINFRAME, const wxString& title = wxT("Bitcoin"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(705, 484), long style = wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER | wxTAB_TRAVERSAL);
    ~MainFrameBase();
};


#endif //BTC_CMAINFRAMEBASE_H
