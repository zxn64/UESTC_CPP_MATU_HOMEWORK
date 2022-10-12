#include "CString.h"

bool String::IsSubstring(const char *str) {
    int l = strlen(str), idx = 0;
    for (int i = 0; i < len; ++i) {
        while (mystr[i + idx] == str[idx]) {
            ++idx;
            if (idx == l - 1) {
                return true;
            }
            if (i + idx == len - 1) {
                return false;
            }
        }
        idx = 0;
    }
    return false;
}

bool String::IsSubstring(const String &str) {
    return IsSubstring(str.mystr);
}

int String::str2num() {
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(mystr[i])) {
            ans *= 10;
            ans += mystr[i] - '0';
        }
    }
    return ans;
}

void String::toUppercase() {
    for (int i = 0; i < len; ++i) {
        if (islower(mystr[i])) {
            mystr[i] = mystr[i] - 'a' + 'A';
        }
    }
}