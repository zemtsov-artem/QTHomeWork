#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    userName ="default user";
    ui->setupUi(this);
}

UserInfo::~UserInfo()
{
    delete ui;
}

QString UserInfo::getName()
{
    return userName;
}

void UserInfo::on_SetButton_clicked()
{

    userName = ui->lineEdit->text();
    hide();
}
