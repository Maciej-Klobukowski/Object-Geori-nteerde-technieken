#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <utility> // std::move

namespace oop {

class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    /*
     * vraag 34: 2 useful (modern) call-by-references
     * Overloads met rvalue reference (QString&&) om temporaries efficiënt over te nemen.
     */
    inline void setName(const QString& n) { name = n; }                // bestaande const&
    inline void setName(QString&& n) { name = std::move(n); }          // #1 modern call-by-reference

    inline const QString& getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    inline void setOpacity(unsigned char o) { opacity = o; }
    inline unsigned char getOpacity() const { return opacity; }

    inline void setLayer(unsigned char l) { layer = l; }
    inline unsigned char getLayer() const { return layer; }

    inline void setSelected(bool v) { selected = v; }
    inline bool isSelected() const { return selected; }

    inline void setLocked(bool v) { locked = v; }
    inline bool isLocked() const { return locked; }

    inline void setHighlighted(bool v) { highlighted = v; }
    inline bool isHighlighted() const { return highlighted; }

    inline void setDirty(bool v) { dirty = v; }
    inline bool isDirty() const { return dirty; }

    friend QString inspectShape(const Shape& s);

protected:
    QString name;

    bool visible     = true;
    bool selected    = false;
    bool locked      = false;
    bool highlighted = false;
    bool dirty       = false;

    unsigned char opacity = 255;
    unsigned char layer = 0;
};

} // namespace oop

#endif // SHAPE_H
