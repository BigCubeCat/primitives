#include "ellipse.hpp"

namespace {
bool is_point_inside_ellipse(const QPoint& point, const QPoint& center,
                             double a, double b) {
    const auto translated = point - center;
    const double value = ((translated.x() * translated.x()) / (a * a)) +
                         ((translated.y() * translated.y()) / (b * b));
    return value <= 1.0;
}
};  // namespace

TEllipseShape::TEllipseShape(const QPoint& topLeft, const QPoint& bottomRight)
    : AbstractObject(topLeft, bottomRight) {
    const auto box = boundingBox();
    mFirstRadius = static_cast<double>(box.width()) / 2.0;
    mSecondRadius = static_cast<double>(box.height()) / 2.0;
}

EObjectTag TEllipseShape::type() const {
    return EObjectTag::kEllipse;
}

bool TEllipseShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    if (!box.contains(point)) {
        return false;
    }
    const auto center = box.center();
    return is_point_inside_ellipse(point, center, mFirstRadius, mSecondRadius);
}

void TEllipseShape::draw(QPainter& painter) const {
    painter.drawEllipse(boundingBox());
}
