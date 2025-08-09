#include "object_container.hpp"

#include <QDebug>

void TObjectContainer::draw(QPainter& painter) const {
    for (const auto& object : mShapesList) {
        object->draw(painter);
    }
    for (const auto& edge : mEdges) {
        edge->draw(painter);
    }
}

void TObjectContainer::insert(const ShapePtr& shape) {
    mShapesList.push_back(shape);
}

void TObjectContainer::erase(ObjectContainer::iterator it) {
    if (it == mShapesList.end()) {
        return;
    }
    mShapesList.erase(it);
    for (auto edge = mEdges.begin(); edge != mEdges.end(); ) {
        if (!(*edge)->isAlive()) {
            edge = mEdges.erase(edge);
        } else {
            ++edge;
        }
    }

}

void TObjectContainer::addEdge(const std::shared_ptr<TEdge>& edge) {
    if (edge->isAlive()) {
        mEdges.insert(edge);
    }
}

ObjectContainer::iterator TObjectContainer::nearestPoint(const QPoint& point) {
    for (auto rit = mShapesList.rbegin(); rit != mShapesList.rend(); ++rit) {
        if ((*rit)->contains(point)) {
            auto it = rit.base();
            --it;
            return it;
        }
    }
    return mShapesList.end();
}
