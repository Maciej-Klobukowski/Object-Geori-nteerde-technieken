#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

namespace oop {

class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    // vraag 29: const reference for variable (parameter)
    inline void setName(const QString& n) { name = n; }

    // vraag 30: const reference for function (return const reference)
    inline const QString& getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    inline void setOpacity(unsigned char o) { opacity = o; }
    inline unsigned char getOpacity() const { return opacity; }

    inline void setLayer(unsigned char l) { layer = l; }
    inline unsigned char getLayer() const { return layer; }

    // vraag 26 + vraag 29: friend function uses const reference parameter
    friend QString inspectShape(const Shape& s);

protected:
    QString name;
    bool visible = true;

    unsigned char opacity = 255;
    unsigned char layer = 0;
};

} // namespace oop

#endif // SHAPE_H
