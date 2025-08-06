#include "mainwindow.hpp"
#include <qlogging.h>
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpinBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), mUi(new Ui::MainWindow) {

    mUi->setupUi(this);

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
