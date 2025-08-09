#include "serialization.hpp"

QString serialization::serializeTag(const EObjectTag& tag) {
    static std::unordered_map<EObjectTag, QString> tagMap{
        {EObjectTag::kEllipse, "ellipse"},
        {EObjectTag::kTriangle, "triangle"},
        {EObjectTag::kRectangle, "rectangle"},
    };
    return tagMap.at(tag);
}

QJsonObject serialization::serializeObject(
    const std::shared_ptr<AbstractObject>& shape) {
    const auto box = shape->boundingBox();
    QJsonObject node;
    QJsonObject topLeft;
    topLeft["x"] = box.left();
    topLeft["y"] = box.top();
    QJsonObject bottomRight;
    bottomRight["x"] = box.right();
    bottomRight["y"] = box.bottom();
    node["top_left"] = topLeft;
    node["bottom_right"] = bottomRight;
    node["type"] = serializeTag(shape->type());
    return node;
}

QJsonObject serialization::serializeEdge(
    const std::shared_ptr<TEdge>& edge,
    const std::unordered_map<std::shared_ptr<AbstractObject>, int>& indexMap) {
    QJsonObject res;
    auto from = edge->from();
    if (!from.expired()) {
        res["from"] = indexMap.at(from.lock());
    } else {
        res["from"] = -1;
    }
    auto to = edge->to();
    if (!to.expired()) {
        res["to"] = indexMap.at(to.lock());
    } else {
        res["to"] = -1;
    }
    return res;
}

QJsonObject serialization::serializeScene(
    const std::shared_ptr<TScene>& scene) {
    const auto objectContainer = scene->objects();
    const auto shapes = objectContainer->objects();
    const auto edges = objectContainer->edges();
    QJsonObject result;
    QJsonArray objectsArray;
    QJsonArray edgeArray;
    std::unordered_map<std::shared_ptr<AbstractObject>, int> shapeIndexes(
        shapes.size());
    for (const auto& shape : shapes) {
        objectsArray.append(serializeObject(shape));
        shapeIndexes[shape] = objectsArray.size() - 1;
    }
    for (const auto& edge : edges) {
        edgeArray.append(serializeEdge(edge, shapeIndexes));
    }
    result["objects"] = objectsArray;
    result["links"] = edgeArray;
    return result;
}

EObjectTag serialization::deserializeTag(const QString& tag) {
    static std::unordered_map<QString, EObjectTag> tagMap{
        {"ellipse", EObjectTag::kEllipse},
        {"triangle", EObjectTag::kTriangle},
        {"rectangle", EObjectTag::kRectangle},
    };
    const auto value = tagMap.find(tag);
    if (value == tagMap.end()) {
        return EObjectTag::kTriangle;
    }
    return value->second;
}

std::shared_ptr<AbstractObject> serialization::deserializeObject(
    const QJsonObject& node) {
    auto& factory = TObjectFactory::instance();
    const auto topLeftNode = node["top_left"];
    const auto bottomRightNode = node["bottom_right"];
    const auto tagString = node["type"].toString();
    const auto tag = deserializeTag(tagString);

    const auto leftX = topLeftNode["x"].toInt();
    const auto topY = topLeftNode["y"].toInt();

    const auto rightX = bottomRightNode["x"].toInt();
    const auto bottomY = bottomRightNode["y"].toInt();

    return factory(QPoint(leftX, topY), QPoint(rightX, bottomY), tag);
}

std::shared_ptr<TEdge> serialization::deserializeEdge(
    const QJsonObject& node,
    const std::vector<std::shared_ptr<AbstractObject>>& objects) {
    const auto from = node["from"].toInt();
    const auto to = node["to"].toInt();
    const int size = static_cast<int>(objects.size());
    if (from < 0 || to < 0 || from >= size || to >= size) {
        return nullptr;
    }
    return std::make_shared<TEdge>(objects[from], objects[to]);
}

std::shared_ptr<TScene> serialization::deserializeScene(
    const QJsonObject& node) {
    auto mContainer = std::make_shared<TObjectContainer>();

    QJsonArray nodesArray = node["objects"].toArray();
    std::vector<std::shared_ptr<AbstractObject>> objects;
    for (const auto& nVal : nodesArray) {
        const auto objectJson = nVal.toObject();
        auto shape = deserializeObject(objectJson);
        mContainer->insert(shape);
        objects.push_back(shape);
    }
    QJsonArray linksArray = node["links"].toArray();
    for (const auto& lVal : linksArray) {
        QJsonObject lObj = lVal.toObject();
        auto edge = deserializeEdge(lObj, objects);
        if (edge) {
            mContainer->addEdge(edge);
        }
    }
    return std::make_shared<TScene>(mContainer);
}
