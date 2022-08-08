#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// 应用程序
class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

enum {
    ID_Hello = 1
};

// 主窗口
class MyFrame : public wxFrame {
public:
    MyFrame();
private:
    // 事件处理函数
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxMenu* m_menuFile;
    wxMenu* m_menuHelp;
    wxMenuBar* m_menuBar;
};


bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show();
    return true;
}

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "tutorial") {
    // File菜单
    m_menuFile = new wxMenu();
    m_menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    // 菜单项之间的分隔符
    m_menuFile->AppendSeparator();
    m_menuFile->Append(wxID_EXIT);
    // Help菜单
    m_menuHelp = new wxMenu();
    m_menuHelp->Append(wxID_ABOUT);

    // 菜单栏
    m_menuBar = new wxMenuBar();
    // 将菜单加入菜单栏
    m_menuBar->Append(m_menuFile, "&File");
    m_menuBar->Append(m_menuHelp,"&Help");
    // 菜单栏加到窗口上
    this->SetMenuBar(m_menuBar);
    // 创建状态栏
    this->CreateStatusBar();
    // 状态栏显示的内容
    this->SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example","About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

wxIMPLEMENT_APP(MyApp);