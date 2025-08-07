#include "edge.hpp"
#include <utility>

void TEdge::draw(QPainter& painter) const {
    const auto firstPtr = mBegin.lock();
    const auto beginPoint = firstPtr->center();

    const auto secondPtr = mEnd.lock();
    const auto endPoint = secondPtr->center();

    painter.drawLine(beginPoint, endPoint);
}

void TEdge::move(const QPoint& delta) {
    if (mNotTemporary) {
        // Нет смысла изменять переменную, если есть конечный узел
        return;
    }
    mCurrentEnd += delta;
}

void TEdge::setEnd(std::weak_ptr<AbstractShape> endShape) {
    mEnd = std::move(endShape);
    mNotTemporary = true;
}
