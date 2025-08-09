#include "TDeletePolicy.hpp"


void TDeletePolicy::click(const QPoint& point) {
    auto objectContainer = container();
    auto it = objectContainer->nearestPoint(point);
    objectContainer->erase(it);
}
