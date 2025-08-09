#ifndef FIGURES_TCREATEPOLICY_HPP
#define FIGURES_TCREATEPOLICY_HPP

#include "engine/object_factory.hpp"
#include "AbstractPolicy.hpp"

class TCreatePolicy final : public AbstractPolicy {
   public:
    explicit TCreatePolicy(const std::shared_ptr<TObjectContainer>& cont)
        : AbstractPolicy(cont), mObjectFactory(TObjectFactory::instance()) {}

    void setTag(const EObjectTag& tag);

    void click(const QPoint& point) override;

    void move(const QPoint& point) override;

    void commit(const QPoint& point) override;

    void draw(QPainter& painter) const override;

    void rollback() override;

   private:
    TObjectFactory& mObjectFactory;
    QPoint mStartPoint;
    std::shared_ptr<AbstractShape> mCurrentObject;

    EObjectTag mTag = EObjectTag::kRectangle;
};

#endif
