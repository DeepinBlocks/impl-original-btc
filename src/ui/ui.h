#ifndef BITCOIN_UI_H
#define BITCOIN_UI_H

#include <iostream>
#include <wx/event.h>
#include <tiff.h>


using namespace std;

DECLARE_EVENT_TYPE(wxEVT_CROSSTHREADCALL, -1)
DECLARE_EVENT_TYPE(wxEVT_REPLY1, -1)
DECLARE_EVENT_TYPE(wxEVT_REPLY2, -1)
DECLARE_EVENT_TYPE(wxEVT_REPLY3, -1)
DECLARE_EVENT_TYPE(wxEVT_TABLEADDED, -1)
DECLARE_EVENT_TYPE(wxEVT_TABLEUPDATED, -1)
DECLARE_EVENT_TYPE(wxEVT_TABLEDELETED, -1)

enum
{
    UICALL_ADDORDER = 1,
    UICALL_UPDATEORDER,
};


void HandleCtrlA(wxKeyEvent& event);
string DateTimeStr(int64 nTime);
string FormatTxStatus(const CWalletTx& wtx);
void CrossThreadCall(int nID, void* pdata);
void MainFrameRepaint();
void Shutdown(void* parg);

#endif //BITCOIN_UI_H
