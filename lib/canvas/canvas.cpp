#include "canvas.hpp"

#include <QFileDialog>
#include <QWidget>

#include <utility>

#include "../engine/TScene.hpp"

TCanvas::TCanvas(std::shared_ptr<TScene> scene, QWidget* parent)
    : QWidget(parent), mScene(std::move(scene)) {}

void TCanvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.setBrush(Qt::NoBrush);
    mScene->draw(painter);
}

void TCanvas::mouseMoveEvent(QMouseEvent* event) {
    if (!(event->buttons() & Qt::LeftButton)) {
        return;
    }
    update();
}

void TCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {}
}

void TCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        update();
    }
}
