#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include <QWidget>
#include "item.h"
#include "QPushButton"
namespace Ui {
class Character;
}

class Character : public QWidget
{
    Q_OBJECT

public:
    std::vector<Item *> bbs;
    Item *Zb1;//装备1
    Item *Zb2;//装备2
    int Atk;
    int Hp;
    int Ep;//经验值,
    std::vector<std::string> num;
    explicit Character(QWidget *parent = 0);
    void setb();
    void connectn();
    void kx();
    void qh(QPushButton *B,int i);
    bool findI(std::string);
 ~Character();
signals:
   void youlose();
private:
    Ui::Character *ui;
};

#endif // CHARACTER_H
