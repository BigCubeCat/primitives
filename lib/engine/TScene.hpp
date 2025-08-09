#ifndef FIGURES_SCENE_HPP
#define FIGURES_SCENE_HPP

#include "TObjectContainer.hpp"
#include "TObjectFactory.hpp"
#include "policy/AbstractPolicy.hpp"

class TScene {
   public:
    explicit TScene();

    explicit TScene(std::shared_ptr<TObjectContainer> container);

    void draw(QPainter& painter) const;

    /*!
     * @param point Начальная точка
     */
    void click(const QPoint& point);

    void move(const QPoint& point);

    void commit(const QPoint& point);

    void rollback();

    void setTool(const EToolTag& tag);

    void setObject(const EObjectTag& obj);

    std::shared_ptr<TObjectContainer> objects() const;

    EToolTag tool() const;

    EObjectTag objectTag() const;

    void addObject(const std::shared_ptr<AbstractObject>& obj);

    void addEdge(const std::shared_ptr<TEdge>& edge);

   private:
    std::shared_ptr<TObjectContainer> mObjectContainer;
    TObjectFactory& mObjectFactory;
    EToolTag mToolTag = EToolTag::kCreate;
    EObjectTag mObjectTag = EObjectTag::kRectangle;

    std::unordered_map<EToolTag, size_t> mPolicyMap;
    std::vector<std::shared_ptr<AbstractPolicy>> mPolicy;

    void preparePolicy();
};

#endif
