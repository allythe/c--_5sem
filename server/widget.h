#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
class Server;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_quit_clicked();

    void on_send_clicked();

    void on_connect_clicked();

private:
    Ui::Widget *ui;
    Server *mServer;
};
#endif // WIDGET_H
