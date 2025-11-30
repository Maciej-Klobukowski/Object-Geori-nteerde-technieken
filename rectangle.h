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


    Rectangle() {
        setName("Rectangle");
    }

    // Polymorphic override of abstract virtual method
    QString draw() const override {
        return "Drawing a Rectangle";
    }
};

#endif // RECTANGLE_H
