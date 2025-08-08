#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <memory>

#include "../engine/TScene.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), mUi(new Ui::MainWindow) {
    mUi->setupUi(this);
    mScene = std::make_shared<TScene>();

    mCanvas = new TCanvas(mScene);

    setCentralWidget(mCanvas);

    mUi->toolBar->addActions(mUi->menuFigure->actions());

    mUi->toolBar->addSeparator();
    mUi->toolBar->addActions(mUi->menuAction->actions());

    mUi->toolBar->addSeparator();
    mUi->toolBar->addActions(mUi->menuFile->actions());
}

MainWindow::~MainWindow() {
    delete mUi;
}

/* СЛОТЫ */
