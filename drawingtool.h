#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "shape.h"

namespace oop {

class DrawingTool {
public:
    DrawingTool(Shape* s) : shape(s) {}

    QString performDraw() const {
        return shape->draw();
    }

    // vraag 30: const reference for function (return const reference)
    inline const Shape& getShape() const { return *shape; }

private:
    Shape* shape;
};

// vraag 25: template function
template <typename T>
QString drawTemplate(const T& shape) {
    return shape.draw();
}

} // namespace oop

#endif // DRAWINGTOOL_H
