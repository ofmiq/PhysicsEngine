#include "mainwindow.h"

#include "engine.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), engine(new Engine) {
  ui->setupUi(this);

  setupButtonGroups();
  setupConnections();

  onFrictionSliderChanged();
  onRestitutionSliderChanged();

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

void MainWindow::onEditButtonToggled(bool checked) {
  if (checked) {
    ui->startPauseButton->setChecked(false);
  }
}

void MainWindow::onPlayButtonToggled(bool checked) {
  if (checked) {
    ui->startPauseButton->setChecked(true);
  }
}

void MainWindow::onStartPauseButtonToggled(bool checked) {
  if (checked) {
    ui->playButton->setChecked(true);
    ui->editButton->setChecked(false);
  } else {
    ui->playButton->setChecked(false);
    ui->editButton->setChecked(true);
  }
}

void MainWindow::onFrictionSliderChanged() {
  double value = ui->frictionSlider->value() / 100.0;
  ui->frictionValueLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::onRestitutionSliderChanged() {
  double value = ui->restitutionSlider->value() / 100.0;
  ui->restitutionValueLabel->setText(QString::number(value, 'f', 2));
}

void MainWindow::onZoomInButtonClicked() {
  int value = ui->scaleLabel->text().remove('%').toInt();
  value += 10;
  ui->scaleLabel->setText(QString::number(value) + "%");
}

void MainWindow::onZoomOutButtonClicked() {
  int value = ui->scaleLabel->text().remove('%').toInt();
  value -= 10;
  if (value < 10) {
    value = 10;
  }
  ui->scaleLabel->setText(QString::number(value) + "%");
}

void MainWindow::setupConnections() {
  connect(ui->startPauseButton, &QPushButton::toggled, this,
          &MainWindow::onStartPauseButtonToggled);

  connect(ui->editButton, &QPushButton::toggled, this,
          &MainWindow::onEditButtonToggled);

  connect(ui->playButton, &QPushButton::toggled, this,
          &MainWindow::onPlayButtonToggled);

  connect(ui->frictionSlider, &QSlider::valueChanged, this,
          &MainWindow::onFrictionSliderChanged);

  connect(ui->restitutionSlider, &QSlider::valueChanged, this,
          &MainWindow::onRestitutionSliderChanged);

  connect(ui->zoomInButton, &QPushButton::clicked, this,
          &MainWindow::onZoomInButtonClicked);

  connect(ui->zoomOutButton, &QPushButton::clicked, this,
          &MainWindow::onZoomOutButtonClicked);
}

void MainWindow::setupButtonGroups() {
  toolButtonGroup = new QButtonGroup(this);
  toolButtonGroup->addButton(ui->selectToolButton);
  toolButtonGroup->addButton(ui->circleToolButton);
  toolButtonGroup->addButton(ui->rectangleToolButton);
  toolButtonGroup->addButton(ui->polygonToolButton);
  toolButtonGroup->addButton(ui->moveToolButton);
  toolButtonGroup->addButton(ui->deleteToolButton);
  toolButtonGroup->setExclusive(true);

  modeButtonGroup = new QButtonGroup(this);
  modeButtonGroup->addButton(ui->editButton);
  modeButtonGroup->addButton(ui->playButton);
  modeButtonGroup->setExclusive(true);

  tabButtonGroup = new QButtonGroup(this);
  tabButtonGroup->addButton(ui->propertiesTab);
  tabButtonGroup->addButton(ui->materialsTab);
  tabButtonGroup->setExclusive(true);
}
