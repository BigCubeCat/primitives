#ifndef RECTANGLE_SHAPE_HPP
#define RECTANGLE_SHAPE_HPP

#include "abstract_shape.hpp"

class TRectangleShape : public AbstractShape {
   public:
    explicit TRectangleShape(const QPoint& topLeft, const QPoint& bottomRight);
    ~TRectangleShape() override = default;
    EFigureTag type() const override;
    bool contains(const QPoint& point) const override;
};

#endif  // !RECTANGLE_HPP
