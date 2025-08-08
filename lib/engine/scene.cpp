#include "scene.hpp"

void TScene::insert(const ShapePtr& shape) {
    mShapesList.insert(shape);
}

void TScene::erase(ShapeSet::iterator it) {
    mShapesList.erase(it);
}

ShapeSet::iterator TScene::nearestPoint(const QPoint& point) const {
    ShapePtr cursor = std::make_shared<TRectangleShape>(point, point);
    auto it = mShapesList.lower_bound(cursor);
    while (it != mShapesList.end()) {
        if (it->get()->contains(point)) {
            break;
        }
    }
    return it;
}

void TScene::draw(QPainter& painter) {
    for (auto it = mShapesList.begin(); it != mShapesList.end(); ++it) {
        it->get()->draw(painter);
    }
}
