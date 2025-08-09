#ifndef TSERIALIZATOR_HPP
#define TSERIALIZATOR_HPP

#include "engine/TScene.hpp"
#include "engine/figures/AbstractObject.hpp"
#include "engine/figures/TEdge.hpp"
#include "engine/figures/tag.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace serialization {
QString serializeTag(const EObjectTag& tag);

QJsonObject serializeObject(const std::shared_ptr<AbstractObject>& shape);

QJsonObject serializeEdge(
    const std::shared_ptr<TEdge>& edge,
    const std::unordered_map<std::shared_ptr<AbstractObject>, int>& indexMap);

QJsonObject serializeScene(const std::shared_ptr<TScene>& scene);

EObjectTag deserializeTag(const QString& tag);

std::shared_ptr<AbstractObject> deserializeObject(const QJsonObject& node);

std::shared_ptr<TEdge> deserializeEdge(
    const QJsonObject& node,
    const std::vector<std::shared_ptr<AbstractObject>>& objects);

std::shared_ptr<TScene> deserializeScene(const QJsonObject& node);

};

#endif
