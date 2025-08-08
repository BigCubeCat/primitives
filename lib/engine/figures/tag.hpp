#ifndef TAG_HPP
#define TAG_HPP

enum class EObjectTag {
    /// Прямоугольник
    kRectangle,
    /// Треугольник
    kTriangle,
    /// Эллипс
    kEllipse
};

enum class EToolTag {
    kCreate,
    kJoin,
    kDelete,
    kMove
};

#endif
