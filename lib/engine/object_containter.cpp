#include "object_containter.hpp"

#include <QDebug>

void TObjectContainter::draw(QPainter& painter) const {
    for (const auto& object : mShapesList) {
        object->draw(painter);
    }
    for (const auto& edge : mEdges) {
        edge->draw(painter);
    }
}

void TObjectContainter::insert(const ShapePtr& shape) {
    mShapesList.push_back(shape);
}

void TObjectContainter::erase(ObjectContainer::iterator it) {
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

ObjectContainer::iterator TObjectContainter::nearestPoint(const QPoint& point) {
    for (auto rit = mShapesList.rbegin(); rit != mShapesList.rend(); ++rit) {
        if ((*rit)->contains(point)) {
            auto it = rit.base();
            --it;
            return it;
        }
    }
    return mShapesList.end();
}
