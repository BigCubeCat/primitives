#ifndef RECTANGLE_SHAPE_HPP
#define RECTANGLE_SHAPE_HPP

#include "abstract_shape.hpp"

class TRectangleShape final : public AbstractShape {
   public:
    explicit TRectangleShape(const QPoint& topLeft, const QPoint& bottomRight);

    ~TRectangleShape() override = default;

    EObjectTag type() const override;

    bool contains(const QPoint& point) const override;

    void draw(QPainter& painter) const override;
};

#endif
