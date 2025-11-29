#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

/*
 * INHERITANCE:
 * Circle correctly inherits from Shape because a Circle IS-A Shape.
 *
 * This demonstrates useful and correct inheritance:
 * shared behavior is reused, and only unique behavior is added.
 */
class Circle : public Shape {
public:
    Circle() {
        setName("Circle"); // encapsulation through setter
    }

    /*
     * POLYMORPHISM:
     * This overrides Shape::draw().
     * When referenced through a Shape*, this version will be called for circles.
     */
    QString draw() const override {
        return "Drawing a Circle";
    }
};

#endif // CIRCLE_HRCLE_H
