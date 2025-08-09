#include "TJoinPolicy.hpp"

void TJoinPolicy::click(const QPoint& point) {
    mStartPoint = point;
    auto sceneObjects = container();
    auto it = sceneObjects->nearestPoint(point);
    if (it == sceneObjects->end()) {
        return;
    }
    mCurrentObject = *it;
    mCurrentEdge = std::make_shared<TEdge>(mCurrentObject);
    mCurrentEdge->move(point);
}

void TJoinPolicy::move(const QPoint& point) {
    if (!mCurrentEdge) {
        mStartPoint = QPoint();
        return;
    }
    mCurrentEdge->move(point);
}

void TJoinPolicy::commit(const QPoint& point) {
    if (!mCurrentEdge || !mCurrentObject) {
        mStartPoint = QPoint();
        return;
    }
    auto sceneObjects = container();
    auto it = sceneObjects->nearestPoint(point);
    if (it == sceneObjects->end()) {
        rollback();
        return;
    }
    if (*it == mCurrentObject) {
        rollback();
        return;
    }
    mCurrentEdge->setEnd(*it);
    sceneObjects->addEdge(mCurrentEdge);
    mCurrentObject = nullptr;
    mCurrentEdge = nullptr;
}

void TJoinPolicy::draw(QPainter& painter) const {
    if (mCurrentEdge)
        mCurrentEdge->draw(painter);
}

void TJoinPolicy::rollback() {
    mStartPoint = QPoint();
    mCurrentObject = nullptr;
    mCurrentEdge = nullptr;
}
