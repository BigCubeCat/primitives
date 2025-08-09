#include "canvas.hpp"

#include <QFileDialog>
#include <QWidget>

#include <utility>

#include "../engine/TScene.hpp"

TCanvas::TCanvas(std::shared_ptr<TScene> scene, QWidget* parent)
    : QWidget(parent), mScene(std::move(scene)) {}

void TCanvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(Qt::NoBrush);
    mScene->draw(painter);
}

void TCanvas::mouseMoveEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        mScene->rollback();
        return;
    }
    mScene->move(event->pos());
    update();
}

void TCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        mScene->click(event->pos());
    }
}

void TCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        mScene->commit(event->pos());
        update();
    }
}
