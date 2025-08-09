#ifndef FIGURE_STORAGE_HPP
#define FIGURE_STORAGE_HPP

#include <memory>
#include <set>

#include "figures/shapes.hpp"

using ShapePtr = std::shared_ptr<AbstractShape>;

using ObjectContainer = std::list<ShapePtr>;

class TObjectContainter {
   public:
    /*!
     * Добавление фигуры в множество
     */
    void insert(const ShapePtr& shape);

    void draw(QPainter& painter) const;

    /*!
     * Обработка клика пользователя.
     * Вернет итератор на ближайший объект
    */
    ObjectContainer::iterator nearestPoint(const QPoint& point);

    void erase(ObjectContainer::iterator it);

    void addEdge(const std::shared_ptr<TEdge>& edge);

    ObjectContainer::iterator begin() { return mShapesList.begin(); }
    ObjectContainer::iterator end() { return mShapesList.end(); }

    ObjectContainer::const_iterator begin() const { return mShapesList.begin(); }
    ObjectContainer::const_iterator end() const { return mShapesList.end(); }

    std::set<std::shared_ptr<TEdge>>& edges() { return mEdges; }

    std::set<std::shared_ptr<TEdge>> edges() const { return mEdges; }

   private:
    ObjectContainer mShapesList;
    std::set<std::shared_ptr<TEdge>> mEdges;
};

#endif
