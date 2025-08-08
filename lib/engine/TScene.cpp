#include "TScene.hpp"

#include "object_factory.hpp"

void TScene::draw(QPainter& painter) const {
    for (const auto& value : mObjectContainer) {
        value->draw(painter);
    }
}

void TScene::setContainer(const TObjectContainter& container) {
    mObjectContainer = container;
}

void TScene::click(const QPoint& point) {
    if (mToolTag == EToolTag::kCreate) {
        TObjectFactory& factory = TObjectFactory::instance();
    }
}

void TScene::setTool(const EToolTag& tag) {
    mToolTag = tag;
}

void TScene::setObject(const EObjectTag& obj) {
    mObjectTag = obj;
}
