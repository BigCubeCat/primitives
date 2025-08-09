#include "io.hpp"

#include <QFile>
#include <QMessageBox>

#include "serialization.hpp"

void io_utils::saveScene(const std::shared_ptr<TScene>& scene,
                         const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(nullptr, "Error", "Cannot open file \n");
    }
    const auto jsonObject = serialization::serializeScene(scene);
    const QJsonDocument doc(jsonObject);
    file.write(doc.toJson(QJsonDocument::Indented));
}

std::shared_ptr<TScene> io_utils::loadScene(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, "Error", "Cannot open file \n");
    }
    const auto doc = QJsonDocument::fromJson(file.readAll());
    return serialization::deserializeScene(doc.object());
}
