#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        flg=1;
        connect(ui->east,&QPushButton::clicked,this,&MainWindow::ge);
        connect(ui->west,&QPushButton::clicked,this,&MainWindow::gw);
        connect(ui->south,&QPushButton::clicked,this,&MainWindow::gs);
        connect(ui->north,&QPushButton::clicked,this,&MainWindow::gn);
        connect(ui->map,&QPushButton::clicked,this,&MainWindow::tmap);
        connect(ui->tp,&QPushButton::clicked,this,&MainWindow::tpgo);
        connect(ui->harb,&QPushButton::clicked,this,&MainWindow::harb_fun);
        connect(ui->npc,&QPushButton::clicked,this,&MainWindow::npc_fun);
        connect(ui->HuangBo,&QPushButton::clicked,this,&MainWindow::HuangBo_fun);
        work = new ZorkUL();

        connect(work->Rooms[9]->ev,&Event::win,this,[=](){
            if(jd == 90){
            QMessageBox::information(this,"GAME_OVER","恭喜您成功通关!");
            close();
            work->Chara->close();
            }
        });

        connect(work->Rooms[9]->ev,&Event::lose,work->Chara,&Character::kx);

        connect(work->Chara,&Character::youlose,this,[=](){
            QMessageBox::information(this,"GAME_OVER","很遗憾您止步于此. ");
           close();
           work->Chara->close();
        });

        ui->text1->append(work->fy());
        ui->text1->append("\n");

        connect(ui->pushButton,&QPushButton::clicked,this,[=](){
            work->Chara->show();

        });
        for(int i=1;i<9;i++){
            connect(work->Rooms[i]->ev,&Event::win,this,&MainWindow::conn);
            connect(work->Rooms[i]->ev,&Event::lose,work->Chara,&Character::kx);
        }

    }
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::tmap(){
    ui->text1->append("[h] --- [f] --- [g]");
    ui->text1->append("         |         ");
    ui->text1->append("         |         ");
    ui->text1->append("[c] --- [a] --- [b]");
    ui->text1->append("         |         ");
    ui->text1->append("         |         ");
    ui->text1->append("[i] --- [d] --- [e]");
    ui->text1->append("         |                 ");
    ui->text1->append("         |                 ");
    ui->text1->append("        [j]                ");
    QString p="Now Position Is ";
    p.append(work->roomname());
    p.append(" Room\n");
    ui->text1->append(p);
}
void  MainWindow::conn(){
    if(flg==1){
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)!=true){
             work->Chara->num.push_back(now->shortDescription());
             jd=jd+10;
             ui->jdt->setValue(jd);
        }

        goe();
        work->Chara->bbs.push_back(now->ev->titem);
        work->Chara->setb();
    }
    else if(flg==2){
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)!=true){
             work->Chara->num.push_back(now->shortDescription());
             jd=jd+10;
             ui->jdt->setValue(jd);
        }
        gon();
        work->Chara->bbs.push_back(now->ev->titem);
        work->Chara->setb();
    }
    else if(flg==3){
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)!=true){
             work->Chara->num.push_back(now->shortDescription());
             jd=jd+10;
             ui->jdt->setValue(jd);
        }
        gos();
        work->Chara->bbs.push_back(now->ev->titem);
        work->Chara->setb();
    }
    else {
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)!=true){
             work->Chara->num.push_back(now->shortDescription());
             jd=jd+10;
             ui->jdt->setValue(jd);
        }
        gow();
        work->Chara->bbs.push_back(now->ev->titem);
        work->Chara->setb();
    }
}
void MainWindow::ge(){
    std::string w2="east";
    now=work->go(w2);
    if(now==NULL||now->ev==NULL){
        goe();
    }
    else{
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)==true){
            goe();
        }
        else{
            now->ev->connectn();
            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
            now->ev->show();
        }
        flg=1;
    }

}
void MainWindow::gn(){
    std::string w2="north";
    now=work->go(w2);
    if(now==NULL||now->ev==NULL){
        gon();
    }
    else{
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)==true){
            gon();
        }
        else{
            now->ev->connectn();
            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
            now->ev->show();
        }

        flg=2;
    }

}

//void MainWindow::tpgo(){
//    std::string w2="west";
//    now=work->go(w2);
//    if(now==NULL||now->ev==NULL){
//        tp();
//    }
//    else{
//        std::string t=now->shortDescription();
//        if(work->Chara->findI(t)==true){
//            tp();
//        }
//        else{
//            now->ev->connectn();
//            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
//            now->ev->show();
//        }
//        flg=5;
//    }

//}
void MainWindow::gs(){
    std::string w2="south";
    now=work->go(w2);
    if(now==NULL||now->ev==NULL){
        gos();
    }
    else{
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)==true){
            gos();
        }
        else{
            now->ev->connectn();
            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
            now->ev->show();
        }
        flg=3;
    }
}
void MainWindow::gw(){
    std::string w2="west";
    now=work->go(w2);
    if(now==NULL||now->ev==NULL){
        gow();
    }
    else{
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)==true){
            gow();
        }
        else{
            now->ev->connectn();
            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
            now->ev->show();
        }
        flg=4;
    }
}


void MainWindow::goe(){
    std::string w1="go";
    std::string w2="east";
    ui->text1->append(work->goRoom(new Command(w1,w2)));
    ui->text1->append("\n");
}
void MainWindow::gon(){
    std::string w1="go";
    std::string w2="north";
    ui->text1->append(work->goRoom(new Command(w1,w2)));
    ui->text1->append("\n");
}
void MainWindow::gos(){
    std::string w1="go";
    std::string w2="south";
    ui->text1->append(work->goRoom(new Command(w1,w2)));
    ui->text1->append("\n");
}
void MainWindow::gow(){
    std::string w1="go";
    std::string w2="west";
    ui->text1->append(work->goRoom(new Command(w1,w2)));
    ui->text1->append("\n");
}

void MainWindow::tp()
{
    ui->text1->append(work->teleportRoom());
    ui->text1->append(work->fy());
    ui->text1->append("\n");
}

void MainWindow::tpgo()
{
    std::string w2="west";
    now=work->go(w2);
    if(now==NULL||now->ev==NULL){
        tp();
    }
    else{
        std::string t=now->shortDescription();
        if(work->Chara->findI(t)==true){
            tp();
        }
        else{
            now->ev->connectn();
            now->ev->txzt(work->Chara->Atk,work->Chara->Hp);
            now->ev->show();
        }

        flg=5;
    }

}

void MainWindow::harb_fun()
{
    ui->textEdit->append("这是游戏简介 ");
    ui->textEdit->append("你需要操控东西南北四个按钮 ");
    ui->textEdit->append("走到相应的房间 ");
    ui->textEdit->append("你可能会遇到强大的敌人 ");
    ui->textEdit->append("不要怕 带上在仓库中等待出征的队友 ");
    ui->textEdit->append("战胜他! ");
    ui-> textEdit->append("This is the introduction to the game ");
    ui-> textEdit->append("You need to control four buttons north, south, east, west ");
    ui-> textEdit->append("Walk to the appropriate room ");
    ui-> textEdit->append("You may encounter a powerful enemy ");
    ui-> textEdit->append("Don't be afraid to bring your teammates waiting in the warehouse ");
    ui-> textEdit->append("Beat him! ");
}
void MainWindow::on_harb_clicked()
{
   cout<<"神秘的字符需要灯火(Mysterious characters need lights)"<<endl;
}
void MainWindow::npc_fun(){

    ui->text1->append("希望人没事 (I hope you're okay.) ");
}
void MainWindow::on_pushButton_2_clicked()
{
    cout<<"人铁定出事 (Something bad is sure to happen) "<<endl;
}

void MainWindow::on_npc_clicked()
{
    cout<<"人铁定出事 (Something bad is sure to happen) "<<endl;
}

void MainWindow::HuangBo_fun(){
    ui->text1->append("正道的光 照在了大地上");
    ui->text1->append("The light of the path fell upon the earth");
    }
void MainWindow::on_HuangBo_clicked()
{
    cout<<"正道的光 照在了大地上 (The light of the path fell upon the earth)"<<endl;
}
