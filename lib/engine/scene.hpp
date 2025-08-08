#ifndef FIGURE_STORAGE_HPP
#define FIGURE_STORAGE_HPP

#include <memory>
#include <set>

#include "figures/shapes.hpp"

using ShapePtr = std::shared_ptr<AbstractShape>;

struct ShapeComparator {
    bool operator()(const ShapePtr& a, const ShapePtr& b) const {
        return a->corner() < b->corner();
    }
};

using ShapeSet = std::set<ShapePtr, ShapeComparator>;

class TScene {
   public:
    /*!
     * Добавление фигуры в множество
     */
    void insert(const ShapePtr& shape);

    /*!
     * Обработка клика пользователя.
     * Вернет итератор на ближайший объект
    */
    ShapeSet::iterator nearestPoint(const QPoint& point) const;

    void erase(ShapeSet::iterator it);

    void draw(QPainter& painter);

   private:
    ShapeSet mShapesList;
};

#endif
