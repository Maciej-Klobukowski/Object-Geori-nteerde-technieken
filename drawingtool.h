#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "shape.h"

/*
 * vraag 8: useful and correct object composition
 * DrawingTool HAS-A Shape pointer.
 *
 * vraag 18: useful proven (dynamic) polymorphism
 * performDraw() roept virtuele draw() aan via Shape*.
 */
class DrawingTool {
public:
    DrawingTool(Shape* s) : shape(s) {}

    QString performDraw() const {
        return shape->draw();
    }

private:
    Shape* shape;
};

/*
 * vraag 25: useful template function
 *
 * Deze template werkt voor ELKE Shape-subclass (Circle, Rectangle, ...)
 * zonder code duplicatie.
 *
 * De template is nuttig omdat:
 * - hij type-veilig is
 * - hij werkt voor alle Shape types
 * - hij herbruikbaar is
 */
template <typename T>
QString drawTemplate(const T& shape) {
    return shape.draw();
}

#endif // DRAWINGTOOL_H
