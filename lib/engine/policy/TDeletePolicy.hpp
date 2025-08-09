#ifndef FIGURES_TDELETEPOLICY_HPP
#define FIGURES_TDELETEPOLICY_HPP

#include "AbstractPolicy.hpp"

class TDeletePolicy final : public AbstractPolicy {
   public:
    explicit TDeletePolicy(const std::shared_ptr<TObjectContainer>& cont)
        : AbstractPolicy(cont) {}

    void click(const QPoint& point) override;

    void move([[maybe_unused]] const QPoint& point) override {}

    void commit([[maybe_unused]] const QPoint& point) override {}

    void draw([[maybe_unused]] QPainter& painter) const override {}

    void rollback() override {}
};

#endif
