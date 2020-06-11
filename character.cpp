#include "character.h"
#include "ui_character.h"
#include "QIcon"
#include "QDebug"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "charres.h"
Character::Character(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Character)
{
    ui->setupUi(this);
    setb();
    connectn();
}
Character::~Character()
{
    delete ui;
}
void Character::setb(){
    Hp=0;
    Atk=0;
    std::stringstream p1;
    std::stringstream p2;
    std::string H2;
    std::string A2;
    std::string H="HP:  ";
    std::string A="ATK: ";
    if(Zb1!=NULL)
    {
        ui->zb1->setIcon(QIcon(Zb1->icon));
        Atk+=Zb1->getATK();
        Hp+=Zb1->getHP();
        QString w=QString::fromStdString(Zb1->getLongDescription());
        ui->d1->setText(w);
    }
    else
    {
        ui->zb1->setIcon(QIcon(""));
        ui->d1->setText("");
    }
    if(Zb2!=NULL)
    {
        ui->zb2->setIcon(QIcon(Zb2->icon));
        Atk+=Zb2->getATK();
        Hp+=Zb2->getHP();
        QString w=QString::fromStdString(Zb2->getLongDescription());
        ui->d2->setText(w);
    }
    else
    {
        ui->zb2->setIcon(QIcon(""));
        ui->d2->setText("");
    }
        if(bbs.size()>=1)
        {
            ui->bb1->setIcon(QIcon(bbs[0]->icon));
        }
        else
        {
            ui->bb1->setIcon(QIcon(""));
        }
        if(bbs.size()>=2)
        {
            ui->bb2->setIcon(QIcon(bbs[1]->icon));
        }
        else
        {
            ui->bb2->setIcon(QIcon(""));
        }
        if(bbs.size()>=3)
        {
            ui->bb3->setIcon(QIcon(bbs[2]->icon));
        }

        else
        {
            ui->bb3->setIcon(QIcon(""));
        }
        if(bbs.size()>=4)
        {
            ui->bb4->setIcon(QIcon(bbs[3]->icon));
        }else{
            ui->bb4->setIcon(QIcon(""));
        }
        if(bbs.size()>=5){
            ui->bb5->setIcon(QIcon(bbs[4]->icon));
        }else{
            ui->bb5->setIcon(QIcon(""));
        }
        if(bbs.size()>=6){
            ui->bb6->setIcon(QIcon(bbs[5]->icon));
        }else{
            ui->bb6->setIcon(QIcon(""));
        }
        if(bbs.size()>=7){
            ui->bb7->setIcon(QIcon(bbs[6]->icon));
        }else{
            ui->bb7->setIcon(QIcon(""));
        }
        if(bbs.size()>=8){
            ui->bb8->setIcon(QIcon(bbs[7]->icon));
        }else{
            ui->bb8->setIcon(QIcon(""));
        }
        if(bbs.size()>=9){
            ui->bb9->setIcon(QIcon(bbs[8]->icon));
        }else{
            ui->bb9->setIcon(QIcon(""));
        }
        if(bbs.size()>=10){
            ui->bb10->setIcon(QIcon(bbs[9]->icon));
        }else{
            ui->bb10->setIcon(QIcon(""));
        }
        if(bbs.size()>=11){
            ui->bb11->setIcon(QIcon(bbs[10]->icon));
        }else{
            ui->bb11->setIcon(QIcon(""));
        }
        if(bbs.size()>=12){
            ui->bb12->setIcon(QIcon(bbs[11]->icon));
        }else{
            ui->bb12->setIcon(QIcon(""));
        }
        p1<<Atk;
        p2<<Hp;
        p1>>A2;
        p2>>H2;
        H=H+H2;
        A=A+A2;
        QString v1=QString::fromStdString(A);
        QString v2=QString::fromStdString(H);
        ui->ATK->setText(v1);
        ui->HP->setText(v2);
}
void Character::qh(QPushButton *B, int i){
    if((int)bbs.size()>=i){
        if(Zb1==NULL){
            B->setIcon(QIcon(bbs[i-1]->icon));
            std::vector<Item *>::iterator it=bbs.begin()+i-1;
            Zb1=*it;
            bbs.erase(it);
            setb();
        }
        else if(Zb2==NULL){
            B->setIcon(QIcon(bbs[i-1]->icon));
            std::vector<Item *>::iterator it=bbs.begin()+i-1;
            Zb2=*it;
            bbs.erase(it);
            setb();
        }
    }
}
void Character::connectn(){
    connect(ui->zb1,&QPushButton::clicked,this,[=](){
        if(Zb1!=NULL){
            bbs.push_back(Zb1);
            Zb1=NULL;
            setb();
        }
    });
    connect(ui->zb2,&QPushButton::clicked,this,[=](){
        if(Zb2!=NULL){
            bbs.push_back(Zb2);
            Zb2=NULL;
            setb();
        }
    });
    connect(ui->bb1,&QPushButton::clicked,this,[=](){
       qh(ui->bb1,1);
    });
    connect(ui->bb2,&QPushButton::clicked,this,[=](){
       qh(ui->bb2,2);
    });
    connect(ui->bb3,&QPushButton::clicked,this,[=](){
       qh(ui->bb3,3);
    });
    connect(ui->bb4,&QPushButton::clicked,this,[=](){
       qh(ui->bb4,4);
    });
    connect(ui->bb5,&QPushButton::clicked,this,[=](){
       qh(ui->bb5,5);
    });
    connect(ui->bb6,&QPushButton::clicked,this,[=](){
       qh(ui->bb6,6);
    });
    connect(ui->bb7,&QPushButton::clicked,this,[=](){
        qh(ui->bb7,7);
    });
    connect(ui->bb8,&QPushButton::clicked,this,[=](){
       qh(ui->bb8,8);
    });
    connect(ui->bb9,&QPushButton::clicked,this,[=](){
       qh(ui->bb9,9);
    });
    connect(ui->bb10,&QPushButton::clicked,this,[=](){
        qh(ui->bb10,10);
    });
    connect(ui->bb11,&QPushButton::clicked,this,[=](){
       qh(ui->bb11,11);
    });
    connect(ui->bb12,&QPushButton::clicked,this,[=](){
        qh(ui->bb12,12);
    });
}
void Character::kx(){
    Ep--;
    if(Ep==2){
        ui->E1->setHidden(true);
    }
    else if(Ep==1){
        ui->E2->setHidden(true);
    }
    else if(Ep==0){
        ui->E3->setHidden(true);
        emit youlose();
    }
}
bool Character::findI(std::string q){
    std::vector<std::string>::iterator t=std::find(num.begin(),num.end(),q);
    if(t!=num.end()){
        return true;
    }
    else{
        return false;
    }
}
