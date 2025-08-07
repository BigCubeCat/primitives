#include "rectangle.hpp"

EFigureTag TRectangleShape::type() const {
    return EFigureTag::kRectangle;
}

bool TRectangleShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    return box.contains(point);
}
