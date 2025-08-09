#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QJsonDocument>
#include <QMessageBox>
#include <memory>

#include "../engine/TScene.hpp"
#include "../utils/io.hpp"
#include "../utils/serialization.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      mUi(new Ui::MainWindow),
      mScene(std::make_shared<TScene>()) {
    mUi->setupUi(this);

    mCanvas = new TCanvas(mScene);

    setCentralWidget(mCanvas);

    setupToolbar();
    connectSlots();
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

void MainWindow::connectSlots() {
    connect(mUi->actionEllipse, &QAction::triggered, this,
            &MainWindow::setEllipse);
    connect(mUi->actionRectangle, &QAction::triggered, this,
            &MainWindow::setRectangle);
    connect(mUi->actionTriangle, &QAction::triggered, this,
            &MainWindow::setTriangle);

    connect(mUi->actionEdge, &QAction::triggered, this, &MainWindow::setJoin);
    connect(mUi->actionMove, &QAction::triggered, this, &MainWindow::setMove);
    connect(mUi->actionDelete, &QAction::triggered, this,
            &MainWindow::setDelete);

    connect(mUi->actionSave, &QAction::triggered, this, &MainWindow::onSave);
    connect(mUi->actionSave_As, &QAction::triggered, this,
            &MainWindow::onSaveAs);
    connect(mUi->actionOpen, &QAction::triggered, this, &MainWindow::onOpen);
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

void MainWindow::onOpen() {
    const QString fileName = QFileDialog::getOpenFileName(
        this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if (fileName.isEmpty())
        return;
    mCurrentFilePath = fileName;
    mScene = io_utils::loadScene(mCurrentFilePath);
    mCanvas->setNewScene(mScene);
    statusBar()->showMessage(QFileInfo(mCurrentFilePath).fileName());
    mCanvas->update();
}

void MainWindow::onSave() {
    if (mCurrentFilePath.isEmpty()) {
        onSaveAs();
        return;
    }
    io_utils::saveScene(mScene, mCurrentFilePath);
}

void MainWindow::onSaveAs() {
    const QString fileName = QFileDialog::getSaveFileName(
        this, "Save File As", "", "Text Files (*.txt);;All Files (*)");
    if (fileName.isEmpty())
        return;
    mCurrentFilePath = fileName;
    io_utils::saveScene(mScene, mCurrentFilePath);
    statusBar()->showMessage(QFileInfo(mCurrentFilePath).fileName());
}