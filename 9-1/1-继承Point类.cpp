#include "CPoint.h"

namespace {
    const double pi = 3.14;
}

Rectangle::Rectangle(float xx, float yy, float w, float h) : Point(xx, yy) {
    width = w;
    high = h;
}

Circle::Circle(float xx, float yy, float r) : Point(xx, yy) {
    radius = r;
}

float Rectangle::Area() {
    return width * high;
}

float Circle::Area() {
    return pi * radius * radius;
}
