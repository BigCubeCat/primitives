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

class TObjectContainter {
   public:
    /*!
     * Добавление фигуры в множество
     */
    void insert(const ShapePtr& shape);

    /*!
     * Обработка клика пользователя.
     * Вернет итератор на ближайший объект
    */
    ShapeSet::iterator& nearestPoint(const QPoint& point);

    void erase(ShapeSet::iterator it);

    void addEdge(const std::shared_ptr<TEdge>& edge);

    ShapeSet::iterator begin() { return mShapesList.begin(); }
    ShapeSet::iterator end() { return mShapesList.end(); }

    ShapeSet::const_iterator begin() const { return mShapesList.begin(); }
    ShapeSet::const_iterator end() const { return mShapesList.end(); }

   private:
    ShapeSet mShapesList;
    std::set<std::shared_ptr<TEdge>> mEdges;
};

#endif
