#include "nuo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nuo w;
    w.show();
    return a.exec();
}
