#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "ui/CMainFrameBase.h"

class CMyApp : public wxApp {
public:
    virtual bool OnInit();
};

bool CMyApp::OnInit() {
    CMainFrameBase* frame = new CMainFrameBase(nullptr);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(CMyApp);
