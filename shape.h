#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

/*
 * CLASS: Shape
 * This is a useful and correct class because it models a real-world concept:
 * a generic shape. It represents an abstract idea and provides behavior to be
 * shared by all specific shape types.
 *
 * ABSTRACTION:
 * This class hides implementation details. It does NOT specify HOW a shape
 * is drawn—only that every shape must be drawable.
 *
 * ENCAPSULATION:
 * The 'name' field is protected, and can only be accessed through getters
 * and setters. This protects internal data from invalid outside modification.
 *
 * ABSTRACT BASE CLASS:
 * It contains a pure virtual function, so it cannot be instantiated.
 */
class Shape {
public:
    virtual ~Shape() {}

    /*
     * VIRTUAL FUNCTION:
     * draw() is declared as pure virtual, ensuring all subclasses must implement
     * their own drawing behavior.
     *
     * POLYMORPHISM:
     * When draw() is called through a Shape pointer, the correct subclass
     * implementation is invoked at runtime.
     */
    virtual QString draw() const = 0;

    // Useful and correct encapsulation: controlled access to 'name'
    void setName(const QString& n) { name = n; }
    QString getName() const { return name; }

protected:
    QString name; // Only derived classes can access
};

#endif // SHAPE_H
