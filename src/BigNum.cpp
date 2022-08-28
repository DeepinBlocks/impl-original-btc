#include "BigNum.h"

AutoBN_CTX::AutoBN_CTX() {
    pctx = BN_CTX_new();
    if (pctx == nullptr) {
        throw BigNumError("AutoBN_CTX: BN_CTX_new() returned nullptr");
    }
}

AutoBN_CTX::~AutoBN_CTX() {
    if (pctx != nullptr) {
        BN_CTX_free(pctx);
    }
}

BN_CTX* AutoBN_CTX::operator=(BN_CTX* pnew) {
    return pctx = pnew;
}

AutoBN_CTX::operator BN_CTX*() {
    return pctx;
}

BN_CTX& AutoBN_CTX::operator*() {
    return *pctx;
}

BN_CTX** AutoBN_CTX::operator&() {
    return &pctx;
}

bool AutoBN_CTX::operator!() {
    return pctx == nullptr;
}