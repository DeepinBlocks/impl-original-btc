#ifndef BITCOIN_BIGNUM_H
#define BITCOIN_BIGNUM_H
#include <stdexcept>
#include <vector>
#include<openssl/bn.h>
#include <tiff.h>

using namespace std;

class BigNumError: public runtime_error {
public:
    explicit BigNumError(const string& str) : runtime_error(str) {}
};

class AutoBN_CTX {
public:
    AutoBN_CTX();
    ~AutoBN_CTX();

    operator BN_CTX*();
    BN_CTX& operator*();
    BN_CTX** operator&();
    bool operator!();

protected:
    BN_CTX* pctx;
    BN_CTX* operator=(BN_CTX* pnew);
};

class BigNum : public BIGNUM {
public:
    BigNum();

    BigNum(const BigNum& b);
    explicit BigNum(const string& str);
    BigNum& operator=(const BigNum& b);
    ~BigNum();

    BigNum(char n)             { BN_init(this); if (n >= 0) setulong(n); else setint64(n); }
    BigNum(short n)            { BN_init(this); if (n >= 0) setulong(n); else setint64(n); }
    BigNum(int n)              { BN_init(this); if (n >= 0) setulong(n); else setint64(n); }
    BigNum(long n)             { BN_init(this); if (n >= 0) setulong(n); else setint64(n); }
    BigNum(int64 n)            { BN_init(this); setint64(n); }
    BigNum(unsigned char n)    { BN_init(this); setulong(n); }
    BigNum(unsigned short n)   { BN_init(this); setulong(n); }
    BigNum(unsigned int n)     { BN_init(this); setulong(n); }
    BigNum(unsigned long n)    { BN_init(this); setulong(n); }
    BigNum(uint64 n)           { BN_init(this); setuint64(n); }
    explicit BigNum(uint256 n) { BN_init(this); setuint256(n); }
    explicit BigNum(const vector<unsigned char>& vch);


    void setulong(unsigned long n);
    unsigned long getulong() const;

    void setuint64(uint64 n);
    unsigned int getuint() const;

    void setint64(int64 n);
    int getint() const;

    void setuint256(uint256 n);
    uint256 getuint256() const;

    void setvch(const vector<unsigned char>& vch);
    vector<unsigned char> getvch() const;

    BigNum& SetCompact(unsigned int compact);
    unsigned int GetCompact() const;

    void SetHex(const string& str);


private:

};


#endif //BITCOIN_BIGNUM_H
