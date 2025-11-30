#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

/*
 * INHERITANCE:
 * Rectangle inherits correctly from Shape, modeling a proper IS-A relationship.
 */
class Rectangle : public Shape {
public:

    /*
     * DEFAULT CONSTRUCTOR #2
     * Useful and correct—ensures the class can be instantiated with no arguments.
     */


    Rectangle() : width(20), height(10) {
        setName("Rectangle");
    }

    // Parameterized constructor #1
    Rectangle(int w, int h) : width(w), height(h) {
        setName("Rectangle");
    }

    // Parameterized constructor #2
    Rectangle(int w, int h, const QString& customName)
        : width(w), height(h)
    {
        setName(customName);
    }

    // Polymorphic override of abstract virtual method
    QString draw() const override {
        return "Drawing a Rectangle";
    }

    // Encapsulation
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setSize(int w, int h) { width = w; height = h; }

    private:
        int width;
        int height;
    };



#endif // RECTANGLE_H
