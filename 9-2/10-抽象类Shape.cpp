#include "Shape.h"

namespace {
    const double Pi = 3.14;
}

class Rectangle : public Shape {
private:
    double l, w;
public:
    Rectangle(const double l, const double w) {
        this->l = l;
        this->w = w;
    }

    double GetArea() {
        return l * w;
    }

    double GetPerimeter() {
        return 2 * (l + w);
    }
};

class Circle : public Shape {
private:
    double r;
public:
    Circle(const double r) {
        this->r = r;
    }

    double GetArea() {
        return Pi * r * r;
    }

    double GetPerimeter() {
        return 2 * Pi * r;
    }
};

Shape *Shape::createRectangle(double length, double width) {
    return new Rectangle(length, width);
}

Shape *Shape::createCircle(double radius) {
    return new Circle(radius);
}