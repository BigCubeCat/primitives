#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "../canvas/canvas.hpp"

class TScene;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
   private slots:

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* mUi;
    TCanvas* mCanvas;
    std::shared_ptr<TScene> mScene;
};

#endif
