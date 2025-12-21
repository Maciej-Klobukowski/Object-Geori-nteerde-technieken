#include "shape.h"

namespace oop {

// vraag 26: friend function
QString inspectShape(const Shape& s) {
    return "Shape[" % s.name % "]";
}

// vraag 35: useful string class usage (QStringBuilder)
QString Shape::describe(bool includeType) const {
    if (!visible) return "Hidden";

    QString out = includeType ? ("Shape: " % name) : name;

    if (selected) out = out % " [selected]";
    if (locked)   out = out % " [locked]";
    if (dirty)    out = out % " [dirty]";

    return out;
}

}
