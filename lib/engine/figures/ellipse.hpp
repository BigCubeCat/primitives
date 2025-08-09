#ifndef ELLIPSE_SHAPE_HPP
#define ELLIPSE_SHAPE_HPP

#include "AbstractObject.hpp"

class TEllipseShape final : public AbstractObject {
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
