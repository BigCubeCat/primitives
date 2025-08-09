#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>
#include <utility>
#include "abstract_shape.hpp"
#include "drawable_iface.hpp"

class TEdge : public IObject {
   public:
    explicit TEdge(std::weak_ptr<AbstractShape> begin)
        : IObject(), mBegin(std::move(begin)) {
        mCurrentEnd = mBegin.lock()->center();
    }

    explicit TEdge(std::weak_ptr<AbstractShape> begin,
                   std::weak_ptr<AbstractShape> end)
        : IObject(),
          mBegin(std::move(begin)),
          mEnd(std::move(end)),
          mNotTemporary(true) {}

    ~TEdge() override = default;

    void draw(QPainter& painter) const override;

    void move(const QPoint& newEnd) override;

    void setEnd(std::weak_ptr<AbstractShape> endShape);

    bool isAlive() const;

    bool operator<(const TEdge& rhs) const;

    std::weak_ptr<AbstractShape> from() const;

    std::weak_ptr<AbstractShape> to() const;

   private:
    std::weak_ptr<AbstractShape> mBegin;
    std::weak_ptr<AbstractShape> mEnd;
    bool mNotTemporary = false;
    QPoint mCurrentEnd;
};

#endif
