#include <QtWidgets/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget wgt;
    wgt.show();
    return app.exec();
}
