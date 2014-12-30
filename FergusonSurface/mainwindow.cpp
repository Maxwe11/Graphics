#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QSpinBox>
#include <QtCore/QSignalMapper>
#include <QtGlobal>

#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_signal_mapper(0)
{
    ui->setupUi(this);
    ui->glWidget->setModel(&m_model);

    m_signal_mapper = new QSignalMapper(this);
    QObject::connect(m_signal_mapper, SIGNAL(mapped(int)), this, SLOT(updateModel(int)));

    this->initializeController();

    this->setMinimumSize(size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateModel(int i)
{
    int k = 0;
    while (i % 3)
    {
        --i;
        ++k;
    }
    i /= 3;

    switch (k)
    {
    case 0:
        m_model[i].setX(m_spbox[i * 3 + k]->value());
        break;
    case 1:
        m_model[i].setY(m_spbox[i * 3 + k]->value());
        break;
    case 2:
        m_model[i].setZ(m_spbox[i * 3 + k]->value());
        break;
    }

    ui->glWidget->updateGL();
//    qDebug() << m_model[i];
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->groupBox->move(10, height() - ui->groupBox->height() - 10);
    ui->glWidget->resize(width() - 20, height() - ui->groupBox->height() - 20);
}

void MainWindow::initializeController()
{
    QGridLayout* grid = new QGridLayout(ui->groupBox);

    char arr[] = { 'X', 'Y', 'Z' };
    int default_values[] = {    0,   0,    0,
                                0, 184,  102,
                              200,   0,  247,
                              200, 218,   96,

                               200, 200,    4,
                                 2,   2,    0,
                                 7, 138, -136,
                              -134, 137,  -57,


                               113, 142, -113,
                               200,  70,  -50,
                               200, -29, -124,
                               159, 115,  -45
    };

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            QFormLayout* layout = new QFormLayout();
            QString text = QString("%1%2").arg(i).arg(j);
            QVector3D vec;

            for (int k = 0; k < 3; ++k)
            {
                int index = i * 3 * 4 + j * 3 + k;

                m_spbox[index] = new QSpinBox();
                m_spbox[index]->setRange(-250, 250);
                m_spbox[index]->setValue(default_values[index]);

                switch (k)
                {
                case 0:
                    vec.setX(default_values[index]);
                    break;
                case 1:
                    vec.setY(default_values[index]);
                    break;
                case 2:
                    vec.setZ(default_values[index]);
                    break;
                }

                QObject::connect(m_spbox[index], SIGNAL(valueChanged(int)), m_signal_mapper, SLOT(map()));
                m_signal_mapper->setMapping(m_spbox[index], index);

                layout->addRow(QString("%1").arg(arr[k]).append(text), m_spbox[index]);
            }

            m_model[i * 4 + j] = vec;
            if (i % 2 == 0)
                grid->addLayout(layout, i / 2, j);
            else
                grid->addLayout(layout, i / 2, 4 + j);
        }
    }
}
