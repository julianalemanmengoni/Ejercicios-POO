#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <cstdlib>
#include "sensor.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Sensor s;

    const int repeticiones = 10000000;

    QElapsedTimer timer;

    // getValorBruto()
    timer.start();
    for (int i = 0; i < repeticiones; ++i)
        s.getValorBruto();
    qDebug() << "getValorBruto (inline implícito):" << timer.elapsed() << "ms";

    // getValorBrutoOffline()
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        s.getValorBrutoOffline();
    qDebug() << "getValorBrutoOffline (función normal):" << timer.elapsed() << "ms";

    // getValorNormalizado()
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        s.getValorNormalizado();
    qDebug() << "getValorNormalizado (inline explícito):" << timer.elapsed() << "ms";

    // getValorNormalizadoOffline()
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        s.getValorNormalizadoOffline();
    qDebug() << "getValorNormalizadoOffline (función normal):" << timer.elapsed() << "ms";

    return 0;
}
