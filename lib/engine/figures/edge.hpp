#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>
#include <utility>
#include "abstract_shape.hpp"
#include "drawable_iface.hpp"

class TEdge : public DrawableInterface {
   public:
    explicit TEdge(std::weak_ptr<AbstractShape> begin)
        : DrawableInterface(), mBegin(std::move(begin)) {}

    ~TEdge() override = default;

    void draw(QPainter& painter) const override;

    void move(const QPoint& delta) override;

    void setEnd(std::weak_ptr<AbstractShape> endShape);

   private:
    std::weak_ptr<AbstractShape> mBegin;
    std::weak_ptr<AbstractShape> mEnd;
    bool mNotTemporary = false;
    QPoint mCurrentEnd;
};

#endif
