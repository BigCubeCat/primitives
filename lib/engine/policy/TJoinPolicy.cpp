#include "TJoinPolicy.hpp"

void TJoinPolicy::click(const QPoint& point) {
    mStartPoint = point;
    auto sceneObjects = container();
    auto it = sceneObjects->nearestPoint(point);
    if (it == sceneObjects->end()) {
        return;
    }
    mCurrentEdge = std::make_shared<TEdge>(*it);
}

void TJoinPolicy::move(const QPoint& point) {
    if (!mCurrentEdge) {
        mStartPoint = QPoint();
        return;
    }
    mCurrentEdge->move(point);
}

void TJoinPolicy::commit(const QPoint& point) {
    if (!mCurrentEdge) {
        mStartPoint = QPoint();
        return;
    }
    auto sceneObjects = container();
    auto it = sceneObjects->nearestPoint(point);
    mCurrentEdge->setEnd(*it);
    sceneObjects->addEdge(mCurrentEdge);
    mCurrentObject = nullptr;
    mCurrentEdge = nullptr;
}

void TJoinPolicy::draw(QPainter& painter) const {
    mCurrentEdge->draw(painter);
}

void TJoinPolicy::rollback() {
    mStartPoint = QPoint();
    mCurrentObject = nullptr;
    mCurrentEdge = nullptr;
}
