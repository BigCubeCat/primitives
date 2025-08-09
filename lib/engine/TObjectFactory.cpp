#include "TObjectFactory.hpp"

TObjectFactory& TObjectFactory::instance() {
    static TObjectFactory instance;
    return instance;
}

std::shared_ptr<AbstractObject> TObjectFactory::operator() (
    const QPoint& topLeft, const QPoint& bottomRight, const EObjectTag& tag) {
    return mCreators[tag](topLeft, bottomRight);
}
