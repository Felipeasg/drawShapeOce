#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "occview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void on_drawBox();
    void on_drawCone();
    void on_drawSphere();

private:
    Ui::MainWindow *ui;

    OccView* occView;

    QPushButton *pushButtonDrawBox;
    QPushButton *pushButtonDrawSphere;
    QPushButton *pushButtonDrawCone;
};

#endif // MAINWINDOW_H
