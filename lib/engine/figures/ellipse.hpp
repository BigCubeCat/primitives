#ifndef ELLIPSE_SHAPE_HPP
#define ELLIPSE_SHAPE_HPP

#include "abstract_shape.hpp"

class TEllipseShape final : public AbstractShape {
   public:
    explicit TEllipseShape(const QPoint& topLeft, const QPoint& bottomRight);

    ~TEllipseShape() override = default;

    EObjectTag type() const override;

    bool contains(const QPoint& point) const override;

    void draw(QPainter& painter) const override;

   private:
    double mFirstRadius;
    double mSecondRadius;
};

#endif
