#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <memory>

#include "../engine/TScene.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      mUi(new Ui::MainWindow),
      mScene(std::make_shared<TScene>()) {
    mUi->setupUi(this);

    mCanvas = new TCanvas(mScene);

    setCentralWidget(mCanvas);

    setupToolbar();
}

void MainWindow::setupToolbar() {
    mActionGroup = new QActionGroup(this);
    mActionGroup->setExclusive(true);
    for (QAction* a : mUi->menuFigure->actions()) {
        a->setCheckable(true);
        a->setActionGroup(mActionGroup);
        mUi->toolBar->addAction(a);
    }
    mUi->toolBar->addSeparator();
    for (QAction* a : mUi->menuAction->actions()) {
        a->setCheckable(true);
        a->setActionGroup(mActionGroup);
        mUi->toolBar->addAction(a);
    }
    mUi->toolBar->addSeparator();
    mUi->toolBar->addActions(mUi->menuFile->actions());
}

MainWindow::~MainWindow() {
    delete mCanvas;
    delete mActionGroup;
    delete mUi;
}

/* СЛОТЫ */

void MainWindow::setEllipse() {
    mScene->setTool(EToolTag::kCreate);
    mScene->setObject(EObjectTag::kEllipse);
}

void MainWindow::setRectangle() {
    mScene->setTool(EToolTag::kCreate);
    mScene->setObject(EObjectTag::kRectangle);
}

void MainWindow::setTriangle() {
    mScene->setTool(EToolTag::kCreate);
    mScene->setObject(EObjectTag::kTriangle);
}

void MainWindow::setJoin() {
    mScene->setTool(EToolTag::kJoin);
}

void MainWindow::setDelete() {
    mScene->setTool(EToolTag::kDelete);
}

void MainWindow::setMove() {
    mScene->setTool(EToolTag::kMove);
}
