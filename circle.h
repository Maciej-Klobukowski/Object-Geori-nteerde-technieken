#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace oop {

class Circle : public Shape {
public:
    Circle() : Circle(10, "Circle") {}
    Circle(int r) : Circle(r, "Circle") {}

    // vraag 29: const reference (3)
    Circle(int r, const QString& customName)
        : Shape(), radius(r)
    {
        setName(customName);
    }

    Circle(const Circle& other)
        : Circle(other.radius, other.getName())
    {}

    // vraag 29: const reference (4)
    Circle(const Circle& other, const QString& newName)
        : Shape(other), radius(other.radius)
    {
        setName(newName);
    }

    ~Circle() {}

    QString draw() const override {
        return QString("Drawing a Circle with radius %1").arg(radius);
    }

    inline int getRadius() const { return radius; }
    inline void setRadius(int r) { radius = r; }

private:
    int radius;
};

} // namespace oop

#endif // CIRCLE_H
