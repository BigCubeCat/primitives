#ifndef TSERIALIZATOR_HPP
#define TSERIALIZATOR_HPP

#include "../engine/TScene.hpp"
#include "../engine/figures/abstract_shape.hpp"
#include "../engine/figures/edge.hpp"
#include "../engine/figures/tag.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace serialization {
QString serializeTag(const EObjectTag& tag);

QJsonObject serializeObject(const std::shared_ptr<AbstractShape>& shape);

QJsonObject serializeEdge(
    const std::shared_ptr<TEdge>& edge,
    const std::unordered_map<std::shared_ptr<AbstractShape>, int>& indexMap);

QJsonObject serializeScene(const std::shared_ptr<TScene>& scene);

EObjectTag deserializeTag(const QString& tag);

std::shared_ptr<AbstractShape> deserializeObject(const QJsonObject& node);

std::shared_ptr<TEdge> deserializeEdge(
    const QJsonObject& node,
    const std::vector<std::shared_ptr<AbstractShape>>& objects);

std::shared_ptr<TScene> deserializeScene(const QJsonObject& node);

};

#endif
