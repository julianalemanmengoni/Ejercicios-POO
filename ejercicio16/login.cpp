#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QCryptographicHash>

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos.");
    } else {
        QSqlQuery q("SELECT ultimo_usuario FROM configuracion LIMIT 1");
        if (q.next()) {
            ui->userLineEdit->setText(q.value(0).toString());
        }
    }
}

Login::~Login() {
    delete ui;
}

QString Login::md5(const QString &text) {
    return QString(QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5).toHex());
}

void Login::on_loginButton_clicked() {
    QString usuario = ui->userLineEdit->text();
    QString clave = ui->passLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = ? AND clave = ?");
    query.addBindValue(usuario);
    query.addBindValue(md5(clave));

    if (query.exec() && query.next()) {
        QSqlQuery update;
        update.prepare("UPDATE configuracion SET ultimo_usuario = ?");
        update.addBindValue(usuario);
        update.exec();

        QMessageBox::information(this, "Éxito", "Inicio de sesión exitoso.");
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos.");
    }
}
