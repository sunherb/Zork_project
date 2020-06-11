#ifndef EVENT_H
#define EVENT_H
#include <QWidget>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include"item.h"
namespace Ui {
class Event;
}

class Event : public QWidget
{
    Q_OBJECT

public:
    QString icon;
    QString ne;
    int gwATK;
    int gwHP;
    Item * titem;
    explicit Event(QWidget *parent = 0);
    void connectn();
    void txzt(int Hp,int Atk);
    void fight();
    int rn;
    ~Event();
signals:
    void win();
    void lose();
private:
    Ui::Event *ui;
};

#endif // EVENT_H
