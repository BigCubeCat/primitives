#ifndef ABSTRACT_SHAPE_HPP
#define ABSTRACT_SHAPE_HPP

#include <qpoint.h>

#include "drawable_iface.hpp"
#include "tag.hpp"

class AbstractShape : public IObject {
   public:
    explicit AbstractShape(const QPoint& topLeft, const QPoint& bottomRight)
        : mBoundingBox(topLeft, bottomRight) {
        if (topLeft.x() > bottomRight.x() || topLeft.y() > bottomRight.y()) {
            const auto left = std::min(topLeft.x(), bottomRight.x());
            const auto right = std::max(topLeft.x(), bottomRight.x());
            const auto bottom = std::max(topLeft.y(), bottomRight.y());
            const auto top = std::min(topLeft.y(), bottomRight.y());

            mBoundingBox = QRect(QPoint(left, top), QPoint(right, bottom));
        }
    }

    /// Тип фигуры
    virtual EObjectTag type() const = 0;

    /// Вернет true, если точка внутри фигуры
    virtual bool contains(const QPoint& point) const = 0;

    [[nodiscard]] QRect boundingBox() const { return mBoundingBox; }

    [[nodiscard]] QPoint center() const { return mBoundingBox.center(); }

    [[nodiscard]] int corner() const { return mBoundingBox.left(); }

    void move(const QPoint& delta) override {
        mBoundingBox.moveCenter(mBoundingBox.center() + delta);
    }

   private:
    QRect mBoundingBox;
};

#endif
