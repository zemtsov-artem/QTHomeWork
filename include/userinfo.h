#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    QString userName;
    explicit UserInfo(QWidget *parent = 0);
    QString getName();
    ~UserInfo();

private slots:
    void on_SetButton_clicked();

private:
    Ui::UserInfo *ui;
};

#endif // USERINFO_H
