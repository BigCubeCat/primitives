#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>
#include <utility>
#include "abstract_shape.hpp"
#include "drawable_iface.hpp"

class TEdge : public DrawableInterface {
   public:
    explicit TEdge(std::weak_ptr<AbstractShape> begin,
                   std::weak_ptr<AbstractShape> end)
        : DrawableInterface(), mBegin(std::move(begin)), mEnd(std::move(end)) {}

    ~TEdge() override = default;

    void move(const QPoint& delta) override {}

    void draw(QPainter& painter) const override;

   private:
    std::weak_ptr<AbstractShape> mBegin;
    std::weak_ptr<AbstractShape> mEnd;
};

#endif
