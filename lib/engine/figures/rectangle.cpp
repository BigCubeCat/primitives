#include "rectangle.hpp"
#include "abstract_shape.hpp"

TRectangleShape::TRectangleShape(const QPoint& topLeft,
                                 const QPoint& bottomRight)
    : AbstractShape(topLeft, bottomRight) {}

EFigureTag TRectangleShape::type() const {
    return EFigureTag::kRectangle;
}

bool TRectangleShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    return box.contains(point);
}
