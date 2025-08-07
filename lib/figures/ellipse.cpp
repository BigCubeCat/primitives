#include "ellipse.hpp"

namespace {
bool is_point_inside_ellipse(const QPoint& point, const QPoint& center,
                             double a, double b) {
    auto translated = point - center;
    double value = ((translated.x() * translated.x()) / (a * a)) +
                   ((translated.y() * translated.y()) / (b * b));
    return value <= 1.0;
}
};  // namespace

EFigureTag TEllipseShape::type() const {
    return EFigureTag::kEllipse;
}

bool TEllipseShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    if (!box.contains(point)) {
        return false;
    }
    const auto center = box.center();
    return is_point_inside_ellipse(point, center, mFirstRadius, mSecondRadius);
}
