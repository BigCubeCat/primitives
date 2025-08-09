#ifndef DRAWABLE_OBJECT_HPP
#define DRAWABLE_OBJECT_HPP

#include <QPainter>

class IObject {
   public:
    virtual ~IObject() = default;

    virtual void draw(QPainter& painter) const = 0;
    virtual void move(const QPoint& delta) = 0;
};

#endif
