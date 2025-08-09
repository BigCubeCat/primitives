#include "TScene.hpp"

#include <utility>

#include "object_factory.hpp"
#include "policy/TCreatePolicy.hpp"
#include "policy/TDeletePolicy.hpp"
#include "policy/TJoinPolicy.hpp"
#include "policy/TMovePolicy.hpp"

TScene::TScene()
    : mObjectContainer(std::make_shared<TObjectContainer>()),
      mObjectFactory(TObjectFactory::instance()) {
    preparePolicy();
}

TScene::TScene(std::shared_ptr<TObjectContainer> container)
    : mObjectContainer(std::move(container)),
      mObjectFactory(TObjectFactory::instance()) {
    preparePolicy();
}

std::shared_ptr<TObjectContainer> TScene::objects() const {
    return mObjectContainer;
}

void TScene::draw(QPainter& painter) const {
    mObjectContainer->draw(painter);
    const auto index = mPolicyMap.at(mToolTag);
    mPolicy[index]->draw(painter);
}

void TScene::click(const QPoint& point) {
    const auto index = mPolicyMap.at(mToolTag);
    mPolicy[index]->click(point);
}

void TScene::move(const QPoint& point) {
    const auto index = mPolicyMap.at(mToolTag);
    mPolicy[index]->move(point);
}

void TScene::commit(const QPoint& point) {
    const auto index = mPolicyMap.at(mToolTag);
    mPolicy[index]->commit(point);
}

void TScene::rollback() {
    const auto index = mPolicyMap.at(mToolTag);
    mPolicy[index]->rollback();
}

void TScene::setTool(const EToolTag& tag) {
    mToolTag = tag;
}

void TScene::setObject(const EObjectTag& obj) {
    mObjectTag = obj;
    const auto index = mPolicyMap.at(EToolTag::kCreate);
    auto policy = std::dynamic_pointer_cast<TCreatePolicy>(mPolicy[index]);
    policy->setTag(obj);
}

EToolTag TScene::tool() const {
    return mToolTag;
}

EObjectTag TScene::objectTag() const {
    return mObjectTag;
}

void TScene::addObject(const std::shared_ptr<AbstractShape>& obj) {
    mObjectContainer->insert(obj);
}

void TScene::addEdge(const std::shared_ptr<TEdge>& edge) {
    mObjectContainer->addEdge(edge);
}

void TScene::preparePolicy() {
    mPolicyMap = {
        {EToolTag::kCreate, 0},
        {EToolTag::kJoin, 1},
        {EToolTag::kMove, 2},
        {EToolTag::kDelete, 3},
    };
    mPolicy = {
        std::shared_ptr<AbstractPolicy>(
            std::make_shared<TCreatePolicy>(mObjectContainer)),
        std::shared_ptr<AbstractPolicy>(
            std::make_shared<TJoinPolicy>(mObjectContainer)),
        std::shared_ptr<AbstractPolicy>(
            std::make_shared<TMovePolicy>(mObjectContainer)),
        std::shared_ptr<AbstractPolicy>(
            std::make_shared<TDeletePolicy>(mObjectContainer)),
    };
}
