#include "OutPoint.h"
#include "util.h"

OutPoint::OutPoint() {
    setNull();
}

OutPoint::OutPoint(uint256 hashIn, unsigned int in) {
    hash = hashIn;
    n = in;
}

void OutPoint::setNull() {
    hash = 0;
    n = -1;
}

bool OutPoint::isNull() {
    return hash == 0 && n == -1;
}

string OutPoint::toString() const {
    return strprintf("COutPoint(%s, %d)", hash.ToString().substr(0,6).c_str(), n);
}

void OutPoint::print() const {
    cout << toString() << endl;
}

bool operator<(const OutPoint &a, const OutPoint &b) {
    return a.hash < b.hash || (a.hash == b.hash && a.n < b.n);
}

bool operator==(const OutPoint &a, const OutPoint &b) {
    return a.hash == b.hash && a.n == b.n;
}

bool operator!=(const OutPoint &a, const OutPoint &b) {
    return !(a == b);
}
