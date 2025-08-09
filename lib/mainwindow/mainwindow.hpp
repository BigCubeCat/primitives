#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QActionGroup>

#include "canvas/canvas.hpp"

class TScene;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
   private slots:
    void setEllipse();
    void setRectangle();
    void setTriangle();
    void setJoin();
    void setDelete();
    void setMove();

    void onOpen();
    void onSave();
    void onSaveAs();

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* mUi;
    TCanvas* mCanvas;
    QActionGroup* mActionGroup;
    std::shared_ptr<TScene> mScene;

    QString mCurrentFilePath;

    void setupToolbar();
    void connectSlots();
};

#endif
