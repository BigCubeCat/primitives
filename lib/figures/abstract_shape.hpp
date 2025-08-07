#ifndef ABSTRACT_SHAPE_HPP
#define ABSTRACT_SHAPE_HPP

#include <qpoint.h>
#include "drawable_iface.hpp"
#include "figure_tag.hpp"

class AbstractShape : public DrawableInterface {
   public:
    /// Тип фигуры
    virtual EFigureTag type() const = 0;

    /// Вернет true, если точка внутри фигуры
    virtual bool contains(const QPoint& point) const = 0;

    [[nodiscard]] QRect boundingBox() const { return mBoundingBox; }

    [[nodiscard]] QPoint center() const { return mBoundingBox.center(); }

   private:
    QRect mBoundingBox;
};

#endif
