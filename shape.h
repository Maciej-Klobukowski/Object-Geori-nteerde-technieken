#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

/*
 * vraag 10: abstract base class
 */
class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    inline void setName(const QString& n) { name = n; }
    inline QString getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    /*
     * vraag 26: useful friend function
     * Deze functie krijgt toegang tot protected/private members
     * voor logging/debugging zonder getters te misbruiken.
     */
    friend QString inspectShape(const Shape& s);

protected:
    QString name;
    bool visible = true;
};

#endif // SHAPE_H
