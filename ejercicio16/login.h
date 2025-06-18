#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>

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

private:
    Ui::Login *ui;
    QSqlDatabase db;
    QString md5(const QString &text);
};

#endif // LOGIN_H
