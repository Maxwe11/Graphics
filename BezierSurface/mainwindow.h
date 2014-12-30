#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

class QSignalMapper;
class QSpinBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateModel(int);
protected:
    void resizeEvent(QResizeEvent*);
private:
    void initializeController();
private:
    Ui::MainWindow* ui;
    QSignalMapper* m_signal_mapper;
    QSpinBox* m_spbox[27];
    Model m_model;
};

#endif // MAINWINDOW_H
