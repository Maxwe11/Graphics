#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QSpinBox>
#include <QtCore/QSignalMapper>
#include <QVector2D>
#include <QtGlobal>

#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_signal_mapper(0)
{
    ui->setupUi(this);

    m_signal_mapper = new QSignalMapper(this);
    QObject::connect(m_signal_mapper, SIGNAL(mapped(int)), this, SLOT(updateModel(int)));

    this->initializeController();

    this->setMinimumSize(size());

    ui->glWidget->setModel(&m_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateModel(int i)
{
    int curve = i > 7 ? 1 : 0;
    int j = i > 7 ? i - 8 : i;

    if (j % 2)
        m_model.curve[curve][j/2].setY(m_spbox[i]->value());
    else
        m_model.curve[curve][j/2].setX(m_spbox[i]->value());

    m_model.crv[0].clear();
    m_model.crv[1].clear();
    m_model.intersection.clear();

    ui->glWidget->updateGL();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->groupBox->move(10, height() - ui->groupBox->height() - 10);
    ui->glWidget->resize(width() - 20, height() - ui->groupBox->height() - 20);
}

void MainWindow::initializeController()
{
    QGridLayout* grid = new QGridLayout(ui->groupBox);

    char arr[] = { 'X', 'Y' };
    int default_values[] = {   501, 249,
                               422, 127,
                               126, 189,
                               278, 258,

                               493, 137,
                                40, 353,
                                 0, 356,
                               562, 244

    };

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            QFormLayout* form = new QFormLayout();
            QPointF point;
            for (int k = 0; k < 2; ++k)
            {
                int index = i * 2 * 4 + j * 2 + k;
                m_spbox[index] = new QSpinBox();
                m_spbox[index]->setRange(-500, 1000);
                m_spbox[index]->setValue(default_values[index]);

                if (k == 0)
                    point.setX(default_values[index]);
                else
                    point.setY(default_values[index]);

                QObject::connect(m_spbox[index], SIGNAL(valueChanged(int)), m_signal_mapper, SLOT(map()));
                m_signal_mapper->setMapping(m_spbox[index], index);

                form->addRow(QString("%1%2%3").arg(arr[k]).arg(i).arg(j), m_spbox[index]);
            }
            m_model.curve[i][j] = point;
            grid->addLayout(form, 0, i * 4 + j);
        }
    }
}
