#include "object_containter.hpp"

#include <QDebug>

void TObjectContainter::insert(const ShapePtr& shape) {
    mShapesList.insert(shape);
}

void TObjectContainter::erase(ShapeSet::iterator it) {
    if (it == mShapesList.end()) {
        return;
    }
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

ShapeSet::iterator TObjectContainter::nearestPoint(const QPoint& point) {
    const ShapePtr cursor = std::make_shared<TRectangleShape>(point, point);
    ShapeSet::iterator it = mShapesList.lower_bound(cursor);
    it--;
    qDebug() << "TObjectContainter::nearestPoint start";
    while (it != mShapesList.end()) {
        qDebug() << "TObjectContainter::nearestPoint";
        if (it->get()->contains(point)) {
            return it;
        }
        ++it;
    }
    qDebug() << "TObjectContainter::nearestPoint finish";
    return it;
}
