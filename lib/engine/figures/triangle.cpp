#include "triangle.hpp"

namespace {
/*!
 * Находить коэффиценты y = kx + b
 * \returns k and b
*/
std::pair<double, double> getFunc(const QPoint& first, const QPoint& second) {
    const double k = static_cast<double>(second.y() - first.y()) /
                     static_cast<double>(second.x() - first.x());
    const double b = static_cast<double>(first.y()) - (k * first.x());
    return {k, b};
}
/*!
 * точка пересечения линии и прямой
*/
double intersection(const std::pair<double, double>& func, int m) {
    return (static_cast<double>(m) - func.second) / func.first;
}
};  // namespace

EFigureTag TTriangleShape::type() const {
    return EFigureTag::kTriangle;
}

bool TTriangleShape::contains(const QPoint& point) const {
    const auto box = boundingBox();
    if (!box.contains(point)) {
        return false;
    }
    const QPoint centerPoint(box.center().x(), box.top());
    const auto x1 =
        intersection(getFunc(box.bottomLeft(), centerPoint), point.y());
    const auto x2 =
        intersection(getFunc(centerPoint, box.bottomRight()), point.y());
    // Если точка внутри, то будет ровно одна точка пересечения справа
    return (x1 > point.x()) ^ (x2 > point.x());
}

void TTriangleShape::draw(QPainter& painter) const {
    const auto box = boundingBox();
    const QPoint centerPoint(box.center().x(), box.top());
    painter.drawLine(box.bottomLeft(), box.bottomRight());
    painter.drawLine(box.bottomRight(), centerPoint);
    painter.drawLine(centerPoint, box.bottomLeft());
}
