#include "widget.h"
#include "server.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new Server(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connect_clicked()
{
    if (!mServer->listen(QHostAddress::Any, ui->door->value())) {
        QMessageBox::critical(this, "Error", mServer->errorString());
    } else {
        QMessageBox::information(this, "Server", "Starts");
    }
    ui->connect->setStyleSheet("background-color: #5ADBB0");
}

void Widget::on_send_clicked()
{
    mServer->send(ui->msg->text());
    ui->send->setStyleSheet("background-color: #BD5ADB");
    ui->msg->clear();
}

void Widget::on_quit_clicked()
{
    close();
}
