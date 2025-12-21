#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "shape.h"

namespace oop {

// vraag 8: object composition
class DrawingTool {
public:
    DrawingTool(Shape* s) : shape(s) {}

    // vraag 18: dynamic polymorphism
    QString performDraw() const {
        return shape->draw();
    }

private:
    Shape* shape;
};

// vraag 25: template function
template<typename T>
QString drawTemplate(const T& s) {
    return s.draw();
}

} // namespace oop

#endif
