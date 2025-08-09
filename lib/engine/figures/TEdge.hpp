#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>
#include <utility>
#include "AbstractObject.hpp"
#include "IObject.hpp"

class TEdge : public IObject {
   public:
    explicit TEdge(std::weak_ptr<AbstractObject> begin)
        : IObject(), mBegin(std::move(begin)) {
        mCurrentEnd = mBegin.lock()->center();
    }

    explicit TEdge(std::weak_ptr<AbstractObject> begin,
                   std::weak_ptr<AbstractObject> end)
        : IObject(),
          mBegin(std::move(begin)),
          mEnd(std::move(end)),
          mNotTemporary(true) {}

    ~TEdge() override = default;

    void draw(QPainter& painter) const override;

    void move(const QPoint& newEnd) override;

    void setEnd(std::weak_ptr<AbstractObject> endShape);

    bool isAlive() const;

    bool operator<(const TEdge& rhs) const;

    std::weak_ptr<AbstractObject> from() const;

    std::weak_ptr<AbstractObject> to() const;

   private:
    std::weak_ptr<AbstractObject> mBegin;
    std::weak_ptr<AbstractObject> mEnd;
    bool mNotTemporary = false;
    QPoint mCurrentEnd;
};

#endif
