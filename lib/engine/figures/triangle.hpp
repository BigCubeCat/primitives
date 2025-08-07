#ifndef TRIANGLE_SHAPE_HPP
#define TRIANGLE_SHAPE_HPP

#include <qpainter.h>
#include "abstract_shape.hpp"

class TTriangleShape : public AbstractShape {
   public:
    ~TTriangleShape() override = default;

    EFigureTag type() const override;

    bool contains(const QPoint& point) const override;

    void draw(QPainter& painter) const override;
};

#endif
