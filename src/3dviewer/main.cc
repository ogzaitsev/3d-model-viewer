#include "controller/Controller.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Controller w;
    w.show();
    w.setPreferences();
    a.exec();

    return 0;
    //  IT WAS:
    // QApplication a(argc, argv);
    // Controller w;
    // w.show();
    // return a.exec();
}
