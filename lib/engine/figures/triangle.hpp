#ifndef TRIANGLE_SHAPE_HPP
#define TRIANGLE_SHAPE_HPP

#include <QPainter>
#include "AbstractObject.hpp"

class TTriangleShape final : public AbstractObject {
   public:
    explicit TTriangleShape(const QPoint& topLeft, const QPoint& bottomRight);

    ~TTriangleShape() override = default;

    EObjectTag type() const override;

    bool contains(const QPoint& point) const override;

    void draw(QPainter& painter) const override;
};

#endif
