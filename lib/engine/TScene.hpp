#ifndef FIGURES_SCENE_HPP
#define FIGURES_SCENE_HPP

#include "object_containter.hpp"
#include "object_factory.hpp"

class TScene {
   public:
    explicit TScene();

    void draw(QPainter& painter) const;

    void setContainer(const TObjectContainter& container);

    /*!
     * @param point Начальная точка
     */
    void click(const QPoint& point);

    void move(const QPoint& point);

    void commit(QPoint& point);

    void rollback();

    void setTool(const EToolTag& tag);

    void setObject(const EObjectTag& obj);

   private:
    TObjectContainter mObjectContainer;
    TObjectFactory& mObjectFactory;
    EToolTag mToolTag = EToolTag::kCreate;
    EObjectTag mObjectTag = EObjectTag::kRectangle;

    std::shared_ptr<AbstractShape> mCurrentObject;
    std::shared_ptr<TEdge> mCurrentEdge;
    QPoint mCurrentPoint;
};

#endif
