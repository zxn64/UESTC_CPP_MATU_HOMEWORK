#include "Clock.h"

class NewClock : public Clock {
private:
    int hour, minute, second;
    //bool AM;
public:
    NewClock(int h, int m, int s) : Clock(h, m, s) {
        hour = (h > 23 ? 0 : h);
        minute = (m > 59 ? 0 : m);
        second = (s > 59 ? 0 : m);
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
        }
    }

    void showTime() {
        cout << "Now:" << hour % 12 << ":" << minute << ":" << second << ((hour > 11) ? "PM" : "AM") << endl;
    }
};

Clock *Clock::createNewClock(int h, int m, int s) {
    return new NewClock(h, m, s);
}