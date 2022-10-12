#include <iostream>

using namespace std;

namespace {
    const int days_per_months[12] =
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

class Date {
public:
    Date(int y = 1996, int m = 1, int d = 1) {
        day = d;
        month = m;
        year = y;
        if (m > 12 || m < 1) {
            month = 1;
        }
        if (d > days(y, m)) {
            cout << "Invalid day!" << endl;
            day = 1;
        }
    };

    int days(int y, int m) {
        if (m < 1 || m > 12) return 0;
        bool leap;
        if (y % 4) {
            leap = false;
        } else {
            if (y % 100) {
                leap = true;
            } else {
                if (y % 400) leap = false;
                else leap = true;
            }
        }
        if (leap && m == 2) {
            return 29;
        } else {
            return days_per_months[m - 1];
        }
    }

    void display() const {
        cout << year << "-" << month << "-" << day << endl;
    }

private:
    int year;
    int month;
    int day;
};

ostream &operator<<(ostream &os, const Date &dt) {
    dt.display();
    return os;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    Date dt(y, m, d);
    cout << dt;
    return 0;
}