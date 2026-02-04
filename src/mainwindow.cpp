#include "mainwindow.h"

#include "engine.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), engine(new Engine) {
  ui->setupUi(this);

  engine->start();

  connect(&frameTimer, &QTimer::timeout, this, &MainWindow::onFrame);
  frameTimer.start(16);
}

MainWindow::~MainWindow() {
  engine->stop();
  delete engine;
  delete ui;
}

void MainWindow::onFrame() { engine->update(0.016f); }
