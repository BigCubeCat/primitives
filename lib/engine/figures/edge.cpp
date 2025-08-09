#include "edge.hpp"
#include <utility>

void TEdge::draw(QPainter& painter) const {
    const auto firstPtr = mBegin.lock();
    const auto beginPoint = firstPtr->center();

    const auto secondPtr = mEnd.lock();
    auto endPoint =
        (mNotTemporary && secondPtr) ? secondPtr->center() : mCurrentEnd;

    painter.drawLine(beginPoint, endPoint);
}

void TEdge::move(const QPoint& newEnd) {
    if (mNotTemporary) {
        // Нет смысла изменять переменную, если есть конечный узел
        return;
    }
    mCurrentEnd = newEnd;
}

void TEdge::setEnd(std::weak_ptr<AbstractShape> endShape) {
    mEnd = std::move(endShape);
    mNotTemporary = true;
}

bool TEdge::operator<(const TEdge& rhs) const {
    return mCurrentEnd.x() < rhs.mCurrentEnd.x();
}

bool TEdge::isAlive() const {
    return !mBegin.expired() && !mEnd.expired();
}

std::weak_ptr<AbstractShape> TEdge::from() const {
    return mBegin;
}

std::weak_ptr<AbstractShape> TEdge::to() const {
    return mEnd;
}
