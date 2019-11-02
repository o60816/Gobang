#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <createchess.h>

class QPixmap;
class QLabel;
class piece;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,int color=0);
    ~MainWindow();

signals:
    void clicked();

private slots:
    void mousePressEventSlot();
    void newFile();
    void closeWindow();

private:
    void mousePressEvent(QMouseEvent*);
    QPixmap *pixma=0;
    QLabel *label1=0;
    QLabel *label=0;
    bool isChess[13][13][2]={{{false}}};
    int colorSelect=0;
    bool isFirst=false;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
