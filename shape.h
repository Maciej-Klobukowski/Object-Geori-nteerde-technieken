#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class Shape {
public:
    virtual ~Shape() {}

    virtual QString draw() const = 0;

    QString describe(bool includeType = true) const;

    // ✅ correct inline usage (small, frequently used, header-defined)
    inline void setName(const QString& n) { name = n; }
    inline QString getName() const { return name; }

    inline void setVisible(bool v) { visible = v; }
    inline bool isVisible() const { return visible; }

protected:
    QString name;
    bool visible = true;
};

#endif // SHAPE_H
