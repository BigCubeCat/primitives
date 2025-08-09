#include "TScene.hpp"

#include <QDebug>

#include "object_factory.hpp"

TScene::TScene() : mObjectFactory(TObjectFactory::instance()) {}

void TScene::draw(QPainter& painter) const {
    mObjectContainer.draw(painter);
    if (mCurrentObject)
        mCurrentObject->draw(painter);
    if (mCurrentEdge) {
        mCurrentEdge->draw(painter);
    }
}

void TScene::setContainer(const TObjectContainter& container) {
    mObjectContainer = container;
}

void TScene::click(const QPoint& point) {
    // TODO: policy pattern
    if (mToolTag == EToolTag::kDelete) {
        auto it = mObjectContainer.nearestPoint(point);
        mObjectContainer.erase(it);
    } else if (mToolTag == EToolTag::kMove) {
        mCurrentObject = nullptr;
        auto it = mObjectContainer.nearestPoint(point);
        if (it != mObjectContainer.end()) {
            mCurrentObject = *it;
            mCurrentPoint = point;
        }
    } else if (mToolTag == EToolTag::kJoin) {
        mCurrentPoint = point;
        auto it = mObjectContainer.nearestPoint(point);
        if (it == mObjectContainer.end()) {
            qDebug() << "object not found: " << point;
            return;
        }
        mCurrentEdge = std::make_shared<TEdge>(*it);
    } else if (mToolTag == EToolTag::kCreate) {
        mCurrentPoint = point;
    }
}

void TScene::move(const QPoint& point) {
    if (mToolTag == EToolTag::kJoin && mCurrentEdge != nullptr) {
        mCurrentEdge->move(point);
    } else if (mToolTag == EToolTag::kCreate) {
        mCurrentObject =
            mObjectFactory.createObject(mCurrentPoint, point, mObjectTag);
    } else if (mToolTag == EToolTag::kMove && mCurrentObject != nullptr) {
        mCurrentObject->move(point - mCurrentPoint);
        mCurrentPoint = point;
    }
}

void TScene::commit(const QPoint& point) {
    if (mToolTag == EToolTag::kCreate) {
        mCurrentObject =
            mObjectFactory.createObject(mCurrentPoint, point, mObjectTag);
        mObjectContainer.insert(mCurrentObject);
        mCurrentObject = nullptr;
    } else if (mToolTag == EToolTag::kJoin && mCurrentEdge != nullptr) {
        auto it = mObjectContainer.nearestPoint(point);
        mCurrentEdge->setEnd(*it);
        mObjectContainer.addEdge(mCurrentEdge);
        mCurrentObject = nullptr;
        mCurrentEdge = nullptr;
    }
}

void TScene::rollback() {
    if (mToolTag == EToolTag::kCreate) {
        mObjectContainer.insert(mCurrentObject);
        mCurrentObject = nullptr;
    }
}

void TScene::setTool(const EToolTag& tag) {
    mToolTag = tag;
}

void TScene::setObject(const EObjectTag& obj) {
    mObjectTag = obj;
}
