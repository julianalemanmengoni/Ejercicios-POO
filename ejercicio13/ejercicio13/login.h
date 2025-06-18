#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void fondoDescargado(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QNetworkAccessManager *manager;
    QPixmap fondo;
};

#endif // LOGIN_H
