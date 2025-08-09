#include "rectangle.hpp"
#include "AbstractObject.hpp"

TRectangleShape::TRectangleShape(const QPoint& topLeft,
                                 const QPoint& bottomRight)
    : AbstractObject(topLeft, bottomRight) {}

EObjectTag TRectangleShape::type() const {
    return EObjectTag::kRectangle;
}

bool TRectangleShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    return box.contains(point);
}

void TRectangleShape::draw(QPainter& painter) const {
    painter.drawRect(boundingBox());
}
