#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:

    // Default constructor → forwarded
    Rectangle()
        : Rectangle(20, 10, "Rectangle")    // forwarding
    {}

    // Parameterized constructor #1 → forwarded
    Rectangle(int w, int h)
        : Rectangle(w, h, "Rectangle")      // forwarding
    {}

    // Parameterized constructor #2 (eindpunt)
    Rectangle(int w, int h, const QString& customName)
        : Shape(), width(w), height(h)
    {
        setName(customName);
    }

    // Copy constructor #1 → forwarded
    Rectangle(const Rectangle& other)
        : Rectangle(other.width, other.height, other.getName())
    {}

    // Copy constructor #2 (copy + renamed)
    Rectangle(const Rectangle& other, const QString& newName)
        : Shape(other), width(other.width), height(other.height)
    {
        setName(newName);
    }

    ~Rectangle() {}

    QString draw() const override {
        return QString("Drawing a Rectangle %1x%2")
        .arg(width).arg(height);
    }


    // ✅ useful getters & setters
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

private:
    int width;
    int height;
};

#endif // RECTANGLE_H
