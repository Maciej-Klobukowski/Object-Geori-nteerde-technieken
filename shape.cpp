#include "shape.h"

namespace oop {

/*
 * vraag 26 + 27: friend function inside namespace
 */
QString inspectShape(const Shape& s) {
    return QString("Shape[name=%1, visible=%2]")
    .arg(s.name)
        .arg(s.visible ? "true" : "false");
}

QString Shape::describe(bool includeType) const {
    if (!visible) {
        return "Shape is hidden";
    }

    if (includeType) {
        return "Shape name: " + name;
    }
    return name;
}

} // namespace oop
