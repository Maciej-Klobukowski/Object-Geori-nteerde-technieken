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


    Rectangle()
        : Shape()
        , width(20)
        , height(10)
    {
        setName("Rectangle");
    }


    // Parameterized constructor #1
    Rectangle(int w, int h)
        : Shape()
        , width(w)
        , height(h)
    {
        setName("Rectangle");
    }
    // Parameterized constructor #2
    Rectangle(int w, int h, const QString& customName)
        : Shape()
        , width(w)
        , height(h)
    {
        setName(customName);
    }

    /*
     * COPY CONSTRUCTOR #1 (standard)
     * Useful & correct because it fully copies internal state while keeping
     * encapsulation intact and properly copying base class data.
     */
    Rectangle(const Rectangle& other)
        : Shape(other)
        , width(other.width)
        , height(other.height)
    {
        setName(other.getName());
    }

    /*
     * COPY CONSTRUCTOR #2 (copy with new name)
     * Demonstrates extended flexibility: copying dimensions but assigning
     * a different human-readable identifier.
     */
    Rectangle(const Rectangle& other, const QString& newName)
        : Shape(other)
        , width(other.width)
        , height(other.height)
    {
        setName(newName);
    }

    /*
     * DESTRUCTOR
     * Dit is destructor #2 van het totale project.
     * Wederom nuttig voor cleanup of logging.
     */
    ~Rectangle() {
        // Bijvoorbeeld logging:
        // qDebug() << "Rectangle destroyed";
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
