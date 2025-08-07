#include "edge.hpp"

void TEdge::draw(QPainter& painter) const {
    const auto firstPtr = mBegin.lock();
    const auto beginPoint = firstPtr->center();

    const auto secondPtr = mEnd.lock();
    const auto endPoint = secondPtr->center();

    painter.drawLine(beginPoint, endPoint);
}
