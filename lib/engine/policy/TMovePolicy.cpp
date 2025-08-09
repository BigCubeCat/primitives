#include "TMovePolicy.hpp"

void TMovePolicy::click(const QPoint& point) {
    mTotalMove = QPoint(0, 0);
    mCurrentObject = nullptr;
    auto sceneObjectContainer = container();
    auto it = sceneObjectContainer->nearestPoint(point);
    if (it != sceneObjectContainer->end()) {
        mCurrentObject = *it;
        mCurrentPoint = point;
        mHasStarted = true;
    }
}

void TMovePolicy::move(const QPoint& point) {
    mCurrentObject->move(point - mCurrentPoint);
    mCurrentPoint = point;
    mTotalMove += point;
}

void TMovePolicy::rollback() {
    if (mCurrentObject) {
        mCurrentObject->move(-mTotalMove);
        mTotalMove = QPoint(0, 0);
        mCurrentPoint = QPoint(0, 0);
    }
    mCurrentObject = nullptr;
}