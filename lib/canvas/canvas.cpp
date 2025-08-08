#include "canvas.hpp"
#include <qt6/QtGui/qpen.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

#include <QDebug>
#include <utility>

TCanvas::TCanvas(std::shared_ptr<TScene> scene, QWidget* parent)
    : QWidget(parent), mScene(std::move(scene)) {}

void TCanvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
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
