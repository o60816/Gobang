#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Dialog *ui;
    QLabel *label1=0;
    QLabel *label2=0;
};

#endif // DIALOG_H
