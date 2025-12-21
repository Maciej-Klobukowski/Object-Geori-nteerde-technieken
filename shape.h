#ifndef SHAPE_H
#define SHAPE_H

#include <QString>



/*
 * vraag 3 useful and correct class
 *
 * CLASS: Shape
 * This is a useful and correct class because it models a real-world concept:
 * a generic shape. It represents an abstract idea and provides behavior to be
 * shared by all specific shape types.
 *
 * Vraag 4 useful and correct abstraction
 *
 * ABSTRACTION:
 * This class hides implementation details. It does NOT specify HOW a shape
 * is drawn—only that every shape must be drawable.
 *
 * Vraag 5 useful and correct encapsulation
 *
 * ENCAPSULATION:
 * The 'name' field is protected, and can only be accessed through getters
 * and setters. This protects internal data from invalid outside modification.
 *
 * vraag 10 useful and correct abstract base class
 *
 * ABSTRACT BASE CLASS:
 * It contains a pure virtual function, so it cannot be instantiated.
 */
class Shape {
public:
    virtual ~Shape() {}



    /*
     * vraag 11 useful and correct virtual function
     *
     * VIRTUAL FUNCTION:
     * draw() is declared as pure virtual, ensuring all subclasses must implement
     * their own drawing behavior.
     *
     * Vraag 7 useful and correct polymorphism
     *
     * POLYMORPHISM:
     * When draw() is called through a Shape pointer, the correct subclass
     * implementation is invoked at runtime.
     */
    virtual QString draw() const = 0;

    // 🔹 default value in function definition (header)
    QString describe(bool includeType = true) const;

    void setName(const QString& n) { name = n; }
    QString getName() const { return name; }

protected:
    QString name; // Only derived classes can access
};


#endif // SHAPE_H
