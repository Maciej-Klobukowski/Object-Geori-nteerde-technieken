#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

namespace oop {

class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    inline void setName(const QString& n) { name = n; }
    inline const QString& getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

    inline void setOpacity(unsigned char o) { opacity = o; }
    inline unsigned char getOpacity() const { return opacity; }

    inline void setLayer(unsigned char l) { layer = l; }
    inline unsigned char getLayer() const { return layer; }

    // vraag 31: useful bool getters/setters
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

    // vraag 31: 4 useful bool member variables
    bool visible     = true;   // zichtbaar in UI
    bool selected    = false;  // geselecteerd door gebruiker
    bool locked      = false;  // niet bewerkbaar
    bool highlighted = false;  // visuele highlight
    bool dirty       = false;  // moet opnieuw getekend worden

    unsigned char opacity = 255;
    unsigned char layer = 0;
};

} // namespace oop

#endif // SHAPE_H
