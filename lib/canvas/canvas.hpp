#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QMouseEvent>
#include <QWidget>
#include <memory>

#include "../engine/TScene.hpp"

class TCanvas : public QWidget {
   public:
    explicit TCanvas(std::shared_ptr<TScene> scene, QWidget* parent = nullptr);
    TCanvas(const TCanvas&) = delete;
    TCanvas(TCanvas&&) = delete;
    TCanvas& operator=(const TCanvas&) = delete;
    TCanvas& operator=(TCanvas&&) = delete;

    void setNewScene(const std::shared_ptr<TScene>& scene) { mScene = scene; }

   protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event) override;

    void keyPressEvent(QKeyEvent* event) override;

   private:
    std::shared_ptr<TScene> mScene;
};

#endif
