#include <QApplication>
#include "interface.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    interface ui;

    return a.exec();
}
