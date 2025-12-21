#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

namespace oop {

class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    // vraag 29: const references (1)
    inline void setName(const QString& n) { name = n; }
    inline QString getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    inline void setOpacity(unsigned char o) { opacity = o; }
    inline unsigned char getOpacity() const { return opacity; }

    inline void setLayer(unsigned char l) { layer = l; }
    inline unsigned char getLayer() const { return layer; }

    // vraag 26: friend function + vraag 29: const reference (2)
    friend QString inspectShape(const Shape& s);

protected:
    QString name;
    bool visible = true;

    unsigned char opacity = 255;
    unsigned char layer = 0;
};

} // namespace oop

#endif // SHAPE_H

