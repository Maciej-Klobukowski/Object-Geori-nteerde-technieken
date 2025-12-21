#include "shape.h"

/*
 * vraag 26: useful friend function (implementation)
 * Kan direct aan protected members zonder extra getters.
 * Nuttig voor debugging/logging.
 */
QString inspectShape(const Shape& s) {
    return QString("Shape[name=%1, visible=%2]")
    .arg(s.name)
        .arg(s.visible ? "true" : "false");
}
