#ifndef FIGURES_OBJECT_FACTORY_HPP
#define FIGURES_OBJECT_FACTORY_HPP

#include "figures/shapes.hpp"

class TObjectFactory {
   private:
    using creatorFunction = std::function<std::shared_ptr<AbstractShape>(
        const QPoint&, const QPoint&)>;
    std::unordered_map<EObjectTag, creatorFunction> mCreators = {
        {EObjectTag::kRectangle,
         [](const QPoint& a, const QPoint& b) {
             return std::make_shared<TRectangleShape>(a, b);
         }},
        {EObjectTag::kTriangle,
         [](const QPoint& a, const QPoint& b) {
             return std::make_shared<TTriangleShape>(a, b);
         }},
        {EObjectTag::kEllipse,
         [](const QPoint& a, const QPoint& b) {
             return std::make_shared<TEllipseShape>(a, b);
         }},

    };

    explicit TObjectFactory() = default;

   public:
    static TObjectFactory& instance();

    std::shared_ptr<AbstractShape> operator()(const QPoint& topLeft,
                                                const QPoint& bottomRight,
                                                const EObjectTag& tag);

    TObjectFactory(const TObjectFactory&) = delete;
    TObjectFactory& operator=(const TObjectFactory&) = delete;
    TObjectFactory(TObjectFactory&&) = delete;
    TObjectFactory& operator=(TObjectFactory&&) = delete;
    ~TObjectFactory() = default;
};

#endif
