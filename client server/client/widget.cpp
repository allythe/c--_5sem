#include "widget.h"
#include "ui_widget.h"

#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead, [&]() {
        QTextStream T(mSocket);
        ui->listWidget->addItem(T.readAll());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connect_clicked()
{
    mSocket->connectToHost("localhost", ui->door->value());
    ui->connect->setStyleSheet("background-color: #5ADBB0");
}

void Widget::on_quit_clicked()
{
    close();
}
