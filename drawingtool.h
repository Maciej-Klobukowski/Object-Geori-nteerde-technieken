#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "shape.h"


//Vraag 8 useful and correct object composition

/*
 * OBJECT COMPOSITION:
 * DrawingTool HAS A Shape pointer.
 * This shows useful and correct composition, because DrawingTool depends on a
 * Shape to perform its work, rather than extending Shape.
 *
 * Composition is used instead of inheritance because a DrawingTool is NOT a Shape,
 * but it USES Shape objects. This is the correct design choice.
 */
class DrawingTool {
public:
    // Inject a shape instance (composition)
    DrawingTool(Shape* s) : shape(s) {}

    /*
     * Delegates the draw task to the composed Shape object.
     * This also triggers polymorphism.
     */
    QString performDraw() const {
        return shape->draw();
    }

private:
    Shape* shape; // Composition: part-of relationship
};

#endif // DRAWINGTOOL_H
