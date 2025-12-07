#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:

    // Default constructor → forwarded naar constructor(#2)
    Circle()
        : Circle(10, "Circle")   // forwarding
    {}

    // Parameterized constructor #1 → forwarded naar constructor(#2)
    Circle(int r)
        : Circle(r, "Circle")    // forwarding
    {}

    // Parameterized constructor #2 (eindpunt)
    Circle(int r, const QString& customName)
        : Shape(), radius(r)
    {
        setName(customName);
    }

    // Copy constructor #1 → forwarded
    Circle(const Circle& other)
        : Circle(other.radius, other.getName())   // forwarding
    {}

    // Copy constructor #2 (copy + rename)
    Circle(const Circle& other, const QString& newName)
        : Shape(other), radius(other.radius)
    {
        setName(newName);
    }

    ~Circle() {}

    QString draw() const override {
        return QString("Drawing a Circle with radius %1").arg(radius);
    }

private:
    int radius;
};

#endif // CIRCLE_H
