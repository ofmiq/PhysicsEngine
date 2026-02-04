#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Engine;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void onFrame();

  void onEditButtonToggled(bool checked);
  void onPlayButtonToggled(bool checked);
  void onStartPauseButtonToggled(bool checked);

  void onFrictionSliderChanged();
  void onRestitutionSliderChanged();

  void onZoomInButtonClicked();
  void onZoomOutButtonClicked();

 private:
  void setupButtonGroups();
  void setupConnections();

 private:
  Ui::MainWindow* ui;

  QButtonGroup* toolButtonGroup;
  QButtonGroup* modeButtonGroup;
  QButtonGroup* tabButtonGroup;

  Engine* engine;
  QTimer frameTimer;
};

#endif  // MAINWINDOW_H
