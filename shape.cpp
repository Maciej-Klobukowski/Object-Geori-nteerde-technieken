#include "shape.h"

QString Shape::describe(bool includeType) const {
    if (!visible) {
        return "Shape is hidden";
    }

    if (includeType) {
        return "Shape name: " + name;
    }
    return name;
}
