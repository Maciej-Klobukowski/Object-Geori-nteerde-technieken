#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace oop {

class Circle : public Shape {
public:
    // vraag 12: default constructor
    Circle() : Circle(10, "Circle") {}

    // vraag 13: parameterized constructor
    Circle(int r) : Circle(r, "Circle") {}

    // vraag 16: member initialization list
    Circle(int r, const QString& n) : radius(r) {
        setName(n);
    }

    // vraag 14: copy constructor
    Circle(const Circle& other) : Circle(other.radius, other.getName()) {}

    // vraag 17: constructor forwarding
    Circle(const Circle& other, const QString& newName)
        : radius(other.radius)
    {
        setName(newName);
    }

    ~Circle() {} // vraag 15: destructor

    // vraag 18: polymorphism
    QString draw() const override {
        return "Drawing Circle r=" % QString::number(radius);
    }

private:
    int radius;
};

} // namespace oop

#endif
