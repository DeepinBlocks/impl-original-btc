#ifndef BITCOIN_OUTPOINT_H
#define BITCOIN_OUTPOINT_H
#include <iostream>
using namespace std;

class OutPoint {
public:
    OutPoint();
    OutPoint(uint256 hashIn, unsigned int in);
    void setNull();
    bool isNull();
    string toString() const;
    void print() const;

    friend bool operator<(const OutPoint& a, const OutPoint& b);
    friend bool operator==(const OutPoint& a, const OutPoint& b);
    friend bool operator!=(const OutPoint& a, const OutPoint& b);

private:
    uint256 hash;
    unsigned int n;
};


#endif //BITCOIN_OUTPOINT_H
