#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "ui/MainFrameBase.h"

class CMyApp : public wxApp {
public:
    virtual bool OnInit();
};

bool CMyApp::OnInit() {
    auto frame = new MainFrameBase(nullptr);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(CMyApp);
