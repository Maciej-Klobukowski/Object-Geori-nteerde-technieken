#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

namespace oop {

/*
 * vraag 27: everything in a self-made namespace
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

    // vraag 26: friend function
    friend QString inspectShape(const Shape& s);

protected:
    QString name;
    bool visible = true;
};

} // namespace oop

#endif // SHAPE_H
