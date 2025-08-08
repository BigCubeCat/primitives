#include "object_factory.hpp"

TObjectFactory& TObjectFactory::instance() {
    static TObjectFactory instance;
    return instance;
}

std::shared_ptr<AbstractShape> TObjectFactory::createObject(
    const QPoint& topLeft, const QPoint& bottomRight, const EObjectTag& tag) {
    return mCreators[tag](topLeft, bottomRight);
}
