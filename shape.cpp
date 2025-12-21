#include "shape.h"

namespace oop {

QString inspectShape(const Shape& s) {
    return QString(
               "Shape[name=%1, visible=%2, selected=%3, locked=%4, highlighted=%5, dirty=%6]"
               )
        .arg(s.name)
        .arg(s.visible ? "true" : "false")
        .arg(s.selected ? "true" : "false")
        .arg(s.locked ? "true" : "false")
        .arg(s.highlighted ? "true" : "false")
        .arg(s.dirty ? "true" : "false");
}

QString Shape::describe(bool includeType) const {
    if (!visible) {
        return "Shape is hidden";
    }

    QString result = includeType ? "Shape name: " + name : name;

    if (selected)    result += " [selected]";
    if (locked)      result += " [locked]";
    if (highlighted) result += " [highlighted]";
    if (dirty)       result += " [dirty]";

    return result;
}

} // namespace oop
