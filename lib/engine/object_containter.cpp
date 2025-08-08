#include "object_containter.hpp"

void TObjectContainter::insert(const ShapePtr& shape) {
    mShapesList.insert(shape);
}

void TObjectContainter::erase(ShapeSet::iterator it) {
    mShapesList.erase(it);
}

ShapeSet::const_iterator TObjectContainter::nearestPoint(const QPoint& point) const {
    const ShapePtr cursor = std::make_shared<TRectangleShape>(point, point);
    const auto it = mShapesList.lower_bound(cursor);
    while (it != mShapesList.end()) {
        if (it->get()->contains(point)) {
            break;
        }
    }
    return it;
}
