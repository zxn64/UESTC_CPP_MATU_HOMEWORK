#include "ShapeFactory.h"

namespace {
    const float Pi = 3.14;
}

class Triangle : public ShapeFactory {
private:
    float a_, b_, c_;
public:
    Triangle(const float a, const float b, const float c) {
        a_ = a;
        b_ = b;
        c_ = c;
    }

    float Circumstance() {
        return a_ + b_ + c_;
    }
};

class Quadrangle : public ShapeFactory {
private:
    float a_, b_, c_, d_;
public:
    Quadrangle(const float a, const float b, const float c, const float d) {
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
    }

    float Circumstance() {
        return a_ + b_ + c_ + d_;
    }
};

class Circle : public ShapeFactory {
private:
    float r_;
public:
    Circle(const float r) {
        r_ = r;
    }

    float Circumstance() {
        return Pi * 2 * r_;
    }
};

ShapeFactory *ShapeFactory::Create(float a, float b, float c) {
    return new Triangle(a, b, c);
}

ShapeFactory *ShapeFactory::Create(float a, float b, float c, float d) {
    return new Quadrangle(a, b, c, d);
}

ShapeFactory *ShapeFactory::Create(float r) {
    return new Circle(r);
}