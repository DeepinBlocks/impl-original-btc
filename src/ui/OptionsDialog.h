#ifndef BITCOIN_OPTIONSDIALOG_H
#define BITCOIN_OPTIONSDIALOG_H

#include "common.h"
#include "ui.h"
#include "OptionsDialogBase.h"

class OptionsDialog : public OptionsDialogBase{
public:
    void OnKillFocusTransactionFee(wxFocusEvent& event);
    void OnButtonOK(wxCommandEvent& event);
    void OnButtonCancel(wxCommandEvent& event);
protected:
    OptionsDialog(wxWindow* parent);
};


#endif //BITCOIN_OPTIONSDIALOG_H
