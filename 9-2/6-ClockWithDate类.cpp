#include "ClockAndDate.h"

class ClockWithDate : public Clock, public Date {
public:
    ClockWithDate(int h, int m, int s, int year, int month, int day) :
            Clock(h, m, s), Date(year, month, day) {}

    void showTime() {
        cout << "Now:" << hour << ":" << minute << ":" << second << endl;
        cout << year << "-" << month << "-" << day << endl;
    }

    void run() {
        second = second + 1;
        if (second > 59) {
            second = 0;
            minute += 1;
        }
        if (minute > 59) {
            minute = 0;
            hour += 1;
        }
        if (hour > 23) {
            hour = 0;
            NewDay();
        }
    }
};

Clock *Clock::createClockWithDate(int h, int m, int s, int year, int month, int day) {
    return new ClockWithDate(h, m, s, year, month, day);
}

namespace {
    const int Days[12] =
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

int Date::days(int year, int month) {
    bool leap;
    if (year % 4) {
        leap = false;
    } else {
        if (year % 100) {
            leap = true;
        } else {
            if (year % 400) {
                leap = false;
            } else {
                leap = true;
            }
        }
    }
    if (leap && month == 2) {
        return Days[1] + 1;
    } else {
        return Days[month - 1];
    }
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