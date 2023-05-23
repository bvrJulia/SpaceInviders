#include "menu.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    QIcon ico(":/images/icon.png");
    a.setWindowIcon(ico);
    w.setWindowIcon(ico);
    w.show();
    return a.exec();
}
