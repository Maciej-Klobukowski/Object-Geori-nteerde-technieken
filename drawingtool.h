#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "shape.h"

namespace oop {

/*
 * vraag 27: class inside namespace
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
 * vraag 25 + 27: template function inside namespace
 */
template <typename T>
QString drawTemplate(const T& shape) {
    return shape.draw();
}

} // namespace oop

#endif // DRAWINGTOOL_H
