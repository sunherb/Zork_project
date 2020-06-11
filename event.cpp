#include "event.h"
#include "ui_event.h"
#include "QDebug"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "QMessageBox"
Event::Event(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Event)
{
    ui->setupUi(this);
    connect(ui->zd,&QPushButton::clicked,this,&Event::fight);
    connect(ui->bzd,&QPushButton::clicked,this,&Event::close);
}
void Event::connectn(){
    std::stringstream w1,w2;
    w1<<gwATK;
    w2<<gwHP;
    std::string p1,p2,ite;
    w1>>p1;
    w2>>p2;

    this->titem->getATK();
    ite=titem->getLongDescription();
    ui->ATK->setText(QString::fromStdString(p1));
    ui->HP->setText(QString::fromStdString(p2));
    ui->zbtex->setText(QString::fromStdString(ite));
    ui->name->setText(ne);
    ui->zb->setPixmap(QPixmap(titem->icon));
    ui->zb->setScaledContents(true);
    QString tpim="border-image: url(";
    tpim+=icon;
    tpim+=")";
    ui->img->setStyleSheet(tpim);

    //ui->img->setPixmap(QPixmap(icon));
    //ui->zb->setScaledContents(true);
}
Event::~Event()
{
    delete ui;
}
void Event::txzt(int Atk, int Hp){
    if(gwATK<=Atk&&gwHP<=Hp){
        rn=0;
        ui->zt->setText("TIP: 你绝对能打败怪物,冲啊勇士! ");
    }
    else if(gwATK<=Atk&&gwHP>Hp){
        rn=1;
        ui->zt->setText("TIP: 我承认有赌的成分! (大概率) ");
    }
    else if(gwATK>Atk&&gwHP<=Hp){
        rn=2;
        ui->zt->setText("TIP: 大战五百回合吧! (中概率) ");
    }
    else if(gwATK<=Hp){
        rn=3;
        ui->zt->setText("TIP: 命运女神何时眷顾我啊! ");
    }
    else{
        rn=4;
        ui->zt->setText("TIP: 算了算了,三十六计走为上...... (快去找你的伙伴一起打怪啊!)");
    }

}
void Event::fight(){
    srand(time(0));
    int p=rand()%4;
    if(p>=rn)
    {
        QMessageBox::information(this,"Result","战无不克 跟我走吧伙伴");
        emit win();
        this->close();
    }
    else{
        QMessageBox::information(this,"Result","死亡即是新的开始 ");
        emit lose();
        this->close();
    }
}
