#include <iostream>
#include <string>

namespace {
    const float Pi = 3.14;
}

class Table {
protected:
    float high;
public:
    Table(const float high) {
        this->high = high;
    }

    float GetHigh() {
        return high;
    }
};

class Circle {
protected:
    float radius;
public:
    Circle(const float radius) {
        this->radius = radius;
    }

    float GetArea() {
        return Pi * radius * radius;
    }
};

class RoundTable : public Table, public Circle {
private:
    std::string color;
public:
    RoundTable(const float radius, const float high, const std::string &color) : Table(high), Circle(radius) {
        this->color = color;
    }

    std::string GetColor() {
        return color;
    }
};

using namespace std;

int main() {
    float radius, high;
    string color;
    cin >> radius >> high >> color;
    RoundTable RT(radius, high, color);
    cout << "Area:" << RT.GetArea() << endl;
    cout << "High:" << RT.GetHigh() << endl;
    cout << "Color:" << RT.GetColor() << endl;
    return 0;
}