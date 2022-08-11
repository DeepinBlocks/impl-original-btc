#include "CAboutDialogBase.h"

CAboutDialogBase::CAboutDialogBase(wxWindow* parent,
                                   wxWindowID id,
                                   const wxString& title,
                                   const wxPoint& pos,
                                   const wxSize& size,
                                   long style) : wxDialog(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer60;
    bSizer60 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer62;
    bSizer62 = new wxBoxSizer(wxHORIZONTAL);


    bSizer62->Add(60, 0, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer63;
    bSizer63 = new wxBoxSizer(wxVERTICAL);


    bSizer63->Add(0, 50, 0, wxEXPAND, 5);

    wxBoxSizer* bSizer64;
    bSizer64 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText40 = new wxStaticText(this, wxID_ANY, wxT("Bitcoin "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText40->Wrap(-1);
    m_staticText40->SetFont(wxFont(10, 74, 90, 92, false, wxT("Tahoma")));

    bSizer64->Add(m_staticText40, 0, wxALIGN_BOTTOM, 5);

    m_staticTextVersion = new wxStaticText(this, wxID_ANY, wxT("version"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextVersion->Wrap(-1);
    m_staticTextVersion->SetFont(wxFont(10, 74, 90, 90, false, wxT("Tahoma")));

    bSizer64->Add(m_staticTextVersion, 0, wxALIGN_BOTTOM, 5);

    bSizer63->Add(bSizer64, 0, wxEXPAND, 5);


    bSizer63->Add(0, 4, 0, wxEXPAND, 5);

    m_staticTextMain = new wxStaticText(this, wxID_ANY, wxT("Copyright © 2009 Satoshi Nakamoto.\n\nThis is experimental software.  Do not rely on it for actual financial transactions.\n\nDistributed under the MIT/X11 software license, see the accompanying file license.txt or http://www.opensource.org/licenses/mit-license.php.\n\nThis product includes software developed by the OpenSSL Project for use in the OpenSSL Toolkit (http://www.openssl.org/) and cryptographic software written by Eric Young (eay@cryptsoft.com)."), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextMain->Wrap(400);
    bSizer63->Add(m_staticTextMain, 0, wxALL, 5);


    bSizer63->Add(0, 0, 1, wxEXPAND, 5);

    bSizer62->Add(bSizer63, 1, wxEXPAND, 5);

    bSizer60->Add(bSizer62, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer61;
    bSizer61 = new wxBoxSizer(wxHORIZONTAL);


    bSizer61->Add(0, 0, 1, wxEXPAND, 5);

    m_buttonOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(85,25), 0);
    bSizer61->Add(m_buttonOK, 0, wxALL, 5);

    bSizer60->Add(bSizer61, 0, wxALIGN_RIGHT, 5);

    this->SetSizer(bSizer60);
    this->Layout();

    // Connect Events
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CAboutDialogBase::OnButtonOK), nullptr, this);
}

CAboutDialogBase::~CAboutDialogBase()
{
    // Disconnect Events
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CAboutDialogBase::OnButtonOK), nullptr, this);
}