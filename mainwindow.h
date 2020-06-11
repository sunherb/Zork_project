#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QTextBrowser>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "ZorkUL.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "QLabel"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void goe();
    void gon();
    void gos();
    void gow();
    void ge();
    void gn();
    void gs();
    void gw();
    void tp();
    void tmap();
    void conn();
    void tpgo();
    void harb_fun();
    void npc_fun();
    void HuangBo_fun();
private slots:
//    void on_pushButton_2_clicked();

//   void on_pushButton_clicked();

    void on_harb_clicked();

    void on_pushButton_2_clicked();

    void on_npc_clicked();

    void on_HuangBo_clicked();

private:
    int jd=10;
    int flg=0;
    Room *now;
    Ui::MainWindow *ui;
    QPushButton *b,*a,*c,*d,*e,*m,*j;
    QLabel *l;
    QTextBrowser *t;
    ZorkUL *work;
};

#endif // MAINWINDOW_H
