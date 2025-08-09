#ifndef FIGURES_SCENE_HPP
#define FIGURES_SCENE_HPP

#include <unordered_set>

#include "object_container.hpp"
#include "object_factory.hpp"
#include "policy/AbstractPolicy.hpp"

class TScene {
   public:
    explicit TScene();

    void draw(QPainter& painter) const;

    void setContainer(const std::shared_ptr<TObjectContainer>& container);

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

    void addObject(const std::shared_ptr<AbstractShape>& obj);

    void addEdge(const std::shared_ptr<TEdge>& edge);

   private:
    std::shared_ptr<TObjectContainer> mObjectContainer;
    TObjectFactory& mObjectFactory;
    EToolTag mToolTag = EToolTag::kCreate;
    EObjectTag mObjectTag = EObjectTag::kRectangle;

    std::unordered_map<EToolTag, size_t> mPolicyMap;
    std::vector<std::shared_ptr<AbstractPolicy>> mPolicy;
};

#endif
