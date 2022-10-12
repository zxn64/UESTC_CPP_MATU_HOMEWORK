#include "CDate.h"

Date::Date(int y, int m, int d) {
    year = y;
    if (m < 1 || m > 12) {
        cout << "Invalid month!" << endl;
        m = 1;
    }
    month = m;
    if (days(y, m) < d) {
        cout << "Invalid day!" << endl;
        d = 1;
    }
    day = d;
}

int Date::days(int year, int month) {
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = true;
    if (year % 4) leap = false;
    else {
        if (year % 100) leap = false;
        else {
            if (year % 400) leap = false;
        }
    }
    if (leap) ++day[2];
    return day[month];
}

void Date::NewDay() {
    ++day;
    if (day > days(year, month)) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}