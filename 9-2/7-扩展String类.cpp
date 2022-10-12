#include "CString.h"

int EditString::IsSubString(int start, const char *str) {
    char *idx = strstr(mystr + start, str);
    if (idx) {
        return idx - mystr;
    } else {
        return -1;
    }
}

void EditString::EditChar(char s, char d) {
    for (int i = 0; i < len; ++i) {
        if (mystr[i] == s) mystr[i] = d;
    }
    len = strlen(mystr);
}

void EditString::EditSub(char *subs, char *subd) {
    int idx, last = 0;
    char *str = new char[100000];
    memset(str, 0, strlen(str));
    while (true) {
        idx = IsSubString(last, subs);
        if (idx == -1) {
            strcat(str, mystr + last);
            break;
        }
        strncat(str, mystr + last, idx - last);
        strcat(str, subd);
        last = idx + strlen(subs);
    }
    delete[]mystr;
    mystr = new char[strlen(str) + 1];
    strcpy(mystr, str);
    delete[]str;
    len = strlen(mystr);
}

void EditString::DeleteChar(char ch) {
    char *str = new char[100000];
    int idx = 0;
    for (int i = 0; i < len; ++i) {
        if (mystr[i] == ch) continue;
        else {
            str[idx++] = mystr[i];
        }
    }
    str[idx] = '\0';
    delete[]mystr;
    mystr = new char[idx + 1];
    strcpy(mystr, str);
    delete[]str;
    len = strlen(mystr);
}

void EditString::DeleteSub(char *sub) {
    char str[] = "";
    EditSub(sub, str);
    len = strlen(mystr);
}