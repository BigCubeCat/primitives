#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class TCanvas : public QWidget {
   private:
   public:
    explicit TCanvas(QWidget* parent = nullptr);
    TCanvas(const TCanvas&) = delete;
    TCanvas(TCanvas&&) = delete;
    TCanvas& operator=(const TCanvas&) = delete;
    TCanvas& operator=(TCanvas&&) = delete;

   protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event) override;
};

#endif
