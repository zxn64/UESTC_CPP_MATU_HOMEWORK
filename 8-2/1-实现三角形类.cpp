#include <iostream>
#include <cmath>

using namespace std;

class Ctriangle {
    double a_, b_, c_;
public:
    Ctriangle(double a, double b, double c) {
        a_ = a;
        b_ = b;
        c_ = c;
    }

    void display() {
        cout << "Ctriangle:";
        cout << "a=" << a_ << ',';
        cout << "b=" << b_ << ',';
        cout << "c=" << c_ << endl;
    }

    double GetPerimeter() const {
        return a_ + b_ + c_;
    }

    double GetArea() {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
};

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    Ctriangle T(a, b, c);
    T.display();
    cout << "Perimeter:" << T.GetPerimeter() << endl;
    cout << "Area:" << T.GetArea() << endl;
    return 0;
}