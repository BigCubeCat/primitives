#include "object_containter.hpp"

void TObjectContainter::insert(const ShapePtr& shape) {
    mShapesList.insert(shape);
}

void TObjectContainter::erase(ShapeSet::iterator it) {
    mShapesList.erase(it);
    for (const auto& edge : mEdges) {
        if (!edge->isAlive()) {
            mEdges.erase(edge);
            break;
        }
    }
}

void TObjectContainter::addEdge(const std::shared_ptr<TEdge>& edge) {
    if (edge->isAlive()) {
        mEdges.insert(edge);
    }
}

ShapeSet::iterator& TObjectContainter::nearestPoint(const QPoint& point) {
    const ShapePtr cursor = std::make_shared<TRectangleShape>(point, point);
    auto it = mShapesList.lower_bound(cursor);
    while (it != mShapesList.end()) {
        if (it->get()->contains(point)) {
            break;
        }
    }
    return it;
}
