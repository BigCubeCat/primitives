#ifndef TRIANGLE_SHAPE_HPP
#define TRIANGLE_SHAPE_HPP

#include <qpainter.h>
#include "abstract_shape.hpp"

class TTriangleShape final : public AbstractShape {
   public:
    explicit TTriangleShape(const QPoint& topLeft, const QPoint& bottomRight);

    ~TTriangleShape() override = default;

    EObjectTag type() const override;

    bool contains(const QPoint& point) const override;

    void draw(QPainter& painter) const override;
};

#endif
