#include "Clock.h"

Clock::Clock(int h, int m, int s) {
    if (h < 0 || h >= 24)h = 0;
    if (m < 0 || m >= 60)m = 0;
    if (s < 0 || s >= 60)
        s = 0;
    hour = h;
    minute = m;
    second = s;
}

void Clock::SetAlarm(int h, int m, int s) {
    if (h >= 24 || m >= 60 || s >= 60) {
        Ahour = Aminute = Asecond = -1;
    } else {
        Ahour = h;
        Aminute = m;
        Asecond = s;
    }
}

void Clock::run() {
    ++second;
    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    if (hour == Ahour && minute == Aminute && second == Asecond) {
        cout << "Plink!plink!plink!..." << endl;
    }
}