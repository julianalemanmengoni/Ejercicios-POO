#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Pintura w;
    w.show();
    return a.exec();
}
