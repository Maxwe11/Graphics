#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT
public:
    explicit MainWidget(QWidget* parent = 0);
    ~MainWidget();
protected:
    void resizeEvent(QResizeEvent*);
private slots:
    void on_Translation_toggled(bool checked);
    void on_Rotation_toggled(bool checked);
    void on_AffineTr_toggled(bool checked);
    void on_ProjTr_toggled(bool checked);
private:
    void reset();
private:
    Ui::MainWidget* ui;
};

#endif // MAINWIDGET_H
