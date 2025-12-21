#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QStringBuilder>
#include <utility>

namespace oop { // vraag 27: self-made namespace

// vraag 10: abstract base class
class Shape {
public:
    virtual ~Shape() {} // vraag 15: destructor

    // vraag 18: dynamic polymorphism
    virtual QString draw() const = 0;

    // vraag 20: useful member function
    // vraag 21: default value in function definition
    QString describe(bool includeType = true) const;

    // vraag 23: getters/setters
    // vraag 24: inline functions
    // vraag 29: const reference parameter
    inline void setName(const QString& n) { name = n; }

    // vraag 30: const reference return
    inline const QString& getName() const { return name; }

    // vraag 34: modern call-by-reference
    inline void setName(QString&& n) { name = std::move(n); }

    // vraag 31: useful bools
    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    inline void setSelected(bool v) { selected = v; }
    inline bool isSelected() const { return selected; }

    inline void setLocked(bool v) { locked = v; }
    inline bool isLocked() const { return locked; }

    inline void setDirty(bool v) { dirty = v; }
    inline bool isDirty() const { return dirty; }

    // vraag 28: memory efficient types
    inline void setOpacity(unsigned char o) { opacity = o; }
    inline unsigned char getOpacity() const { return opacity; }

    inline void setLayer(unsigned char l) { layer = l; }
    inline unsigned char getLayer() const { return layer; }

    // vraag 26: friend function
    friend QString inspectShape(const Shape& s);

protected:
    QString name;

    bool visible = true;     // vraag 31
    bool selected = false;   // vraag 31
    bool locked = false;     // vraag 31
    bool dirty = false;      // vraag 31

    unsigned char opacity = 255; // vraag 28
    unsigned char layer = 0;     // vraag 28
};

} // namespace oop

#endif
