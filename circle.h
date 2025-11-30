#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

/*
 * Vraag 6 useful and correct inheritance
 *
 * INHERITANCE:
 * Circle correctly inherits from Shape because a Circle IS-A Shape.
 *
 * This demonstrates useful and correct inheritance:
 * shared behavior is reused, and only unique behavior is added.
 */
class Circle : public Shape {
public:

    /*
     * DEFAULT CONSTRUCTOR #1
     * Useful and correct: allows creating a Circle even when no initial
     * configuration is provided.
    */
    Circle() : radius(10) {
        setName("Circle");
    }

    // Parameterized constructor #1
    Circle(int r) : radius(r) {
        setName("Circle");
    }

    // Parameterized constructor #2
    Circle(int r, const QString& customName) : radius(r) {
        setName(customName);
    }

    /*
     * POLYMORPHISM:
     * This overrides Shape::draw().
     * When referenced through a Shape*, this version will be called for circles.
     */
    QString draw() const override {
        return QString("Drawing a Circle with radius %1").arg(radius);
    }

    // Encapsulation
    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }

    private:
       int radius;

};

#endif // CIRCLE_H

