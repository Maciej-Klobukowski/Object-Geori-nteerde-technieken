#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace oop {

/*
 * vraag 27: class inside self-made namespace
 */
class Rectangle : public Shape {
public:
    Rectangle() : Rectangle(20, 10, "Rectangle") {}
    Rectangle(int w, int h) : Rectangle(w, h, "Rectangle") {}

    Rectangle(int w, int h, const QString& customName)
        : Shape(), width(w), height(h)
    {
        setName(customName);
    }

    Rectangle(const Rectangle& other)
        : Rectangle(other.width, other.height, other.getName())
    {}

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

    inline int getWidth() const { return width; }
    inline int getHeight() const { return height; }
    inline void setWidth(int w) { width = w; }
    inline void setHeight(int h) { height = h; }

private:
    int width;
    int height;
};

} // namespace oop

#endif // RECTANGLE_H
