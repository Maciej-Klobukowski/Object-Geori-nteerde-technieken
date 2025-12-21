#include "shape.h"

namespace oop {

QString inspectShape(const Shape& s) {
    return QString("Shape[name=%1, visible=%2, opacity=%3, layer=%4]")
    .arg(s.name)
        .arg(s.visible ? "true" : "false")
        .arg(s.opacity)
        .arg(s.layer);
}

QString Shape::describe(bool includeType) const {
    if (!visible) {
        return "Shape is hidden";
    }

    QString result;
    if (includeType) {
        result = "Shape name: " + name;
    } else {
        result = name;
    }

    result += QString(" (opacity=%1, layer=%2)")
                  .arg(opacity)
                  .arg(layer);

    return result;
}

} // namespace oop
