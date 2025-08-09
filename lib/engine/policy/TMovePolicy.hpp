#ifndef FIGURES_TMOVEPOLICY_HPP
#define FIGURES_TMOVEPOLICY_HPP

#include "AbstractPolicy.hpp"

class TMovePolicy final : public AbstractPolicy {
   public:
    explicit TMovePolicy(const std::shared_ptr<TObjectContainer>& cont)
        : AbstractPolicy(cont) {}

    void click(const QPoint& point) override;

    void move(const QPoint& point) override;

    void commit([[maybe_unused]] const QPoint& point) override;

    void draw([[maybe_unused]] QPainter& painter) const override {};

    void rollback() override;

   private:
    QPoint mCurrentPoint;
    QPoint mTotalMove;
    std::shared_ptr<AbstractObject> mCurrentObject;
    bool mHasStarted = false;
};

#endif
