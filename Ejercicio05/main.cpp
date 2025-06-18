#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLabel *label = new QLabel;
    QPixmap imagen("imagen.jpg");

    if (!imagen.isNull()) {
        label->setPixmap(imagen.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        label->setAlignment(Qt::AlignCenter);
    }

    label->setWindowTitle("Imagen en QLabel");
    label->showMaximized();

    QTimer::singleShot(3000, &a, &QApplication::quit);

    return a.exec();
}
