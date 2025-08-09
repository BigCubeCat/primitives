#ifndef FIGURES_TJOINPOLICY_HPP
#define FIGURES_TJOINPOLICY_HPP

#include <memory>

#include "AbstractPolicy.hpp"

class TJoinPolicy final : public AbstractPolicy {
   public:
    explicit TJoinPolicy(const std::shared_ptr<TObjectContainer>& cont)
        : AbstractPolicy(cont) {}

    void click(const QPoint& point) override;

    void move(const QPoint& point) override;

    void commit(const QPoint& point) override;

    void draw(QPainter& painter) const override;

    void rollback() override;

   private:
    std::shared_ptr<AbstractShape> mCurrentObject;
    std::shared_ptr<TEdge> mCurrentEdge;
    QPoint mStartPoint;
};

#endif
