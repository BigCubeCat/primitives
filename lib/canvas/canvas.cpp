#include "canvas.hpp"

#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

#include <QDebug>

TCanvas::TCanvas(QWidget* parent) : QWidget(parent) {}

void TCanvas::paintEvent([[maybe_unused]] QPaintEvent* event) {
    QPainter painter(this);
    painter.drawEllipse(0, 0, 20, 20);
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
