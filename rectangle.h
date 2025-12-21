#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace oop {

class Rectangle : public Shape {
public:
    // vraag 12
    Rectangle() : Rectangle(10, 5, "Rectangle") {}

    // vraag 13
    Rectangle(int w, int h) : Rectangle(w, h, "Rectangle") {}

    // vraag 16
    Rectangle(int w, int h, const QString& n)
        : width(w), height(h)
    {
        setName(n);
    }

    // vraag 14
    Rectangle(const Rectangle& r)
        : Rectangle(r.width, r.height, r.getName()) {}

    ~Rectangle() {} // vraag 15

    QString draw() const override {
        return "Drawing Rectangle " %
               QString::number(width) % "x" %
               QString::number(height);
    }

private:
    int width;
    int height;
};

} // namespace oop

#endif
