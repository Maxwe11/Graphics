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
    while (i % 4)
    {
        --i;
        ++k;
    }
    i /= 4;

    switch (k)
    {
    case 0:
        m_model[i].setX(m_spbox[i * 4 + k]->value());
        break;
    case 1:
        m_model[i].setY(m_spbox[i * 4 + k]->value());
        break;
    case 2:
        m_model[i].setZ(m_spbox[i * 4 + k]->value());
        break;
    case 3:
        m_model[i].setW(m_spbox[i * 4 + k]->value());
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

    char arr[] = { 'X', 'Y', 'Z', 'W' };
    int default_values[] = {   -30,  80,    0, 1,
                                -5,  75,  -10, 1,
                                20,  70,  -20, 1,
                                10,  45,  -10, 1,

                                 0, 200,  100, 1,
                                30, 195,   87, 1,
                                60, 190,   75, 1,
                                55, 120,   52, 1,

                                50,  70,   30, 1,
                               125, 105,  110, 1,
                               200, 140,  190, 1,
                               175, 100,  115, 1,

                               150, 140,   40, 1,
                               175, 115,  115, 1,
                               200,  90,  190, 1,
                               140, 150,  160, 1

    };

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            QFormLayout* layout = new QFormLayout();
            QString text = QString("%1%2").arg(i).arg(j);
            QVector4D vec;

            for (int k = 0; k < 4; ++k)
            {
                int index = i * 4 * 4 + j * 4 + k;
                int tmp;

                m_spbox[index] = new QSpinBox();
                if (k < 3)
                {
                    m_spbox[index]->setRange(-250, 250);
                    m_spbox[index]->setValue(default_values[index]);
                }
                else
                {
                //    m_spbox[index]->setRange(1, 10);
                    tmp = qrand() % 10 + 1;
                    m_spbox[index]->setValue(tmp);
                }

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
                case 3:
                    vec.setW(tmp);
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
