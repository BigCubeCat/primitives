#ifndef ELLIPSE_SHAPE_HPP
#define ELLIPSE_SHAPE_HPP

#include "abstract_shape.hpp"

class TEllipseShape : public AbstractShape {
   public:
    ~TEllipseShape() override = default;
    EFigureTag type() const override;
    bool contains(const QPoint& point) const override;

   private:
    double mFirstRadius;
    double mSecondRadius;
};

#endif
