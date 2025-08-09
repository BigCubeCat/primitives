#ifndef FIGURES_IPOLICY_HPP
#define FIGURES_IPOLICY_HPP

#include <QPainter>
#include <QPoint>

#include "../object_container.hpp"

class AbstractPolicy {
   public:
    explicit AbstractPolicy(const std::shared_ptr<TObjectContainer>& cont)
        : mContainer(cont) {}

    virtual ~AbstractPolicy() = default;

    virtual void click(const QPoint& point) = 0;

    virtual void move(const QPoint& point) = 0;

    virtual void commit(const QPoint& point) = 0;

    virtual void draw(QPainter& painter) const = 0;

    virtual void rollback() = 0;

    std::shared_ptr<TObjectContainer>& container() {
        return mContainer;
    }

   private:
    std::shared_ptr<TObjectContainer> mContainer;
};

#endif