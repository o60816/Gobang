#include <QLabel>
#include <QPixmap>
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pixmap(":new/prefix1/black.jpg");
    QPixmap pixmap1(":new/prefix1/white.jpg");
    label1 = new QLabel(this);
    label1->setPixmap(pixmap);
    label1->setGeometry(40,30,20,21);
    label1->show();
    label2 = new QLabel(this);
    label2->setPixmap(pixmap1);
    label2->setGeometry(110,30,20,21);
    label2->show();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_radioButton_clicked()
{
    MainWindow *w = new MainWindow(0,0);
    w->show();
    this->deleteLater();
}

void Dialog::on_radioButton_2_clicked()
{
    MainWindow *w = new MainWindow(0,1);
    w->show();
    this->deleteLater();
}
