#include "simpletext2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleText2 w;
    w.show();
    return a.exec();
}
