#include "TCreatePolicy.hpp"

void TCreatePolicy::setTag(const EObjectTag& tag) {
    mTag = tag;
}

void TCreatePolicy::click(const QPoint& point) {
    mStartPoint = point;
    mCurrentObject = mObjectFactory(mStartPoint, point, mTag);
}

void TCreatePolicy::move(const QPoint& point) {
    if (!mCurrentObject) {
        return;
    }
    mCurrentObject = mObjectFactory(mStartPoint, point, mTag);
}

void TCreatePolicy::commit(const QPoint& point) {
    if (!mCurrentObject) {
        return;
    }
    mCurrentObject = mObjectFactory(mStartPoint, point, mTag);
    auto cont = container();
    cont->insert(mCurrentObject);
}

void TCreatePolicy::draw(QPainter& painter) const {
    if (mCurrentObject)
        mCurrentObject->draw(painter);
}

void TCreatePolicy::rollback() {
    mCurrentObject = nullptr;
}