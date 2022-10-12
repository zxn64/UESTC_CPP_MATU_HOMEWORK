#include "CSet.h"

bool Set::operator<=(const Set &s) const {
    for (int i = 1; i <= n; ++i) {
        if (!s.IsElement(pS[i])) {
            return false;
        }
    }
    return true;
}

bool Set::operator==(const Set &s) const {
    if (n != s.n) return false;
    for (int i = 1; i <= n; ++i) {
        if (!s.IsElement(pS[i])) return false;
    }
    return true;
}

Set &Set::operator+=(int e) {
    if (IsElement(e)) return *this;
    int *temp = pS;
    pS = new int[n + 2];
    for (int i = 1; i <= n; ++i) {
        pS[i] = temp[i];
    }
    ++n;
    pS[n] = e;
    delete[] temp;
    return *this;
}

Set &Set::operator-=(int e) {
    if (!IsElement(e)) return *this;
    int *temp = pS;
    pS = new int[n];
    for (int i = 1; i < n; ++i) {
        if (temp[i] == e) {
            swap(temp[i], temp[n]);
        }
        pS[i] = temp[i];
    }
    --n;
    delete[] temp;
    return *this;
}

Set Set::operator|(const Set &s) const {
    int cnt = 0, *temp = new int[n + s.n + 1];
    for (int i = 1; i <= n; ++i) {
        temp[i] = pS[i];
        ++cnt;
    }
    for (int i = 1; i <= s.n; ++i) {
        if (IsElement(s.pS[i])) continue;
        temp[++cnt] = s.pS[i];
    }
    Set ans;
    ans.n = cnt;
    ans.pS = new int[cnt + 1];
    for (int i = 1; i <= ans.n; ++i) {
        ans.pS[i] = temp[i];
    }
    return ans;
}

Set Set::operator&(const Set &s) const {
    int cnt = 0, *temp = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
        if (!s.IsElement(pS[i])) continue;
        temp[++cnt] = pS[i];
    }
    Set ans;
    ans.n = cnt;
    ans.pS = new int[cnt + 1];
    for (int i = 1; i <= ans.n; ++i) {
        ans.pS[i] = temp[i];
    }
    return ans;
}

Set Set::operator-(const Set &s) const {
    int cnt = 0, *temp = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
        if (s.IsElement(pS[i])) continue;
        temp[++cnt] = pS[i];
    }
    Set ans;
    ans.n = cnt;
    ans.pS = new int[cnt + 1];
    for (int i = 1; i <= ans.n; ++i) {
        ans.pS[i] = temp[i];
    }
    return ans;
}