#include <QApplication>
#include "header/regexwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegExWindow w;
    w.show();

    return a.exec();
}
