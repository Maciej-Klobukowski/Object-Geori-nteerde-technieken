#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

/*
 * INHERITANCE:
 * Rectangle inherits correctly from Shape, modeling a proper IS-A relationship.
 */
class Rectangle : public Shape {
public:
    Rectangle() {
        setName("Rectangle");
    }

    // Polymorphic override of abstract virtual method
    QString draw() const override {
        return "Drawing a Rectangle";
    }
};

#endif // RECTANGLE_H
