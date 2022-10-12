#include <iostream>
#include <cmath>

using namespace std;

class Point {
    double x_, y_;
public:
    Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    double Distance(Point b) {
        return sqrt(pow(x_ - b.x_, 2) + pow(y_ - b.y_, 2));
    }
};

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Point A(a, b), B(c, d);
    cout << A.Distance(B) << endl;
    return 0;
}