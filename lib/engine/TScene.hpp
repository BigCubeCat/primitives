#ifndef FIGURES_SCENE_HPP
#define FIGURES_SCENE_HPP

#include "object_containter.hpp"

class TScene {
   public:
    explicit TScene() = default;

    void draw(QPainter& painter) const;

    void setContainer(const TObjectContainter& container);

    void click(const QPoint& point);

    void setTool(const EToolTag& tag);

    void setObject(const EObjectTag& obj);

   private:
    TObjectContainter mObjectContainer;
    EToolTag mToolTag = EToolTag::kCreate;
    EObjectTag mObjectTag = EObjectTag::kRectangle;
};

#endif
