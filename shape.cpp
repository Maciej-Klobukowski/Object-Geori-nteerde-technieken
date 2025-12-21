#include "shape.h"

QString Shape::describe(bool includeType) const {
    if (includeType) {
        return "Shape name: " + name;
    }
    return name;
}
