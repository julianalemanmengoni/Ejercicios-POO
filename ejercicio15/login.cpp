#include "login.h"
#include "ui_login.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "ventana.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login) {
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos.");
    }
}

Login::~Login() {
    delete ui;
}

void Login::on_loginButton_clicked() {
    QString usuario = ui->userLineEdit->text();
    QString clave = ui->passLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT nombre, ultimo_ingreso FROM usuarios WHERE usuario = ? AND clave = ?");
    query.addBindValue(usuario);
    query.addBindValue(clave);

    if (query.exec() && query.next()) {
        QString nombre = query.value(0).toString();
        QString ultimoIngreso = query.value(1).toString();

        // Actualizar el último ingreso
        QSqlQuery update;
        QString ahora = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        update.prepare("UPDATE usuarios SET ultimo_ingreso = ? WHERE usuario = ?");
        update.addBindValue(ahora);
        update.addBindValue(usuario);
        update.exec();

        Ventana *v = new Ventana(nombre, ultimoIngreso);
        v->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}
