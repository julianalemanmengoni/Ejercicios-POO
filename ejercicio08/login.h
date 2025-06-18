#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void enviarLogin();
    void procesarRespuesta(QNetworkReply *reply);
    void solicitarProtegido();

private:
    QLineEdit *usuarioEdit;
    QLineEdit *claveEdit;
    QPushButton *botonLogin;
    QPushButton *botonProteger;
    QLabel *estadoLabel;

    QNetworkAccessManager *manager;
    QString token;
};

#endif // LOGIN_H
