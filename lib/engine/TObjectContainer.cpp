#include "TObjectContainer.hpp"

void TObjectContainer::draw(QPainter& painter) const {
    for (const auto& object : mShapesList) {
        object->draw(painter);
    }
    for (const auto& edge : mEdges) {
        edge->draw(painter);
    }
}

void TObjectContainer::insert(const ObjectPtr& shape) {
    mShapesList.push_back(shape);
}

void TObjectContainer::erase(ObjectContainer::iterator it) {
    if (it == mShapesList.end()) {
        return;
    }
    mShapesList.erase(it);
    for (auto edge = mEdges.begin(); edge != mEdges.end();) {
        if (!(*edge)->isAlive()) {
            edge = mEdges.erase(edge);
        } else {
            ++edge;
        }
    }
}

void TObjectContainer::addEdge(const std::shared_ptr<TEdge>& edge) {
    if (edge->isAlive()) {
        const auto newFrom = edge->from().lock();
        const auto newTo = edge->to().lock();
        for (auto edge_it = mEdges.begin(); edge_it != mEdges.end();
             ++edge_it) {
            const auto currFrom = (*edge_it)->from().lock();
            const auto currTo = (*edge_it)->to().lock();
            if (((newFrom == currFrom) && (newTo == currTo)) ||
                ((newFrom == currTo) && (newTo == currFrom))) {
                return;
            }
        }
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
