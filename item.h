#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <map>
#include <algorithm>
using namespace std;

class Item {
private:
    //道具名
    string description;

    //完整道具信息
    string longDescription;

    //重量
    int ATK;
    int HP;


    //道具类型
    int weaponCheck;

public:
    QString icon;
    //名称，重量，属性的构造方法
    Item (string description, int inATK, int inHP);
    //名称的构造方法
    Item (string description);
    //返回description
    string getShortDescription();
    //返回道具完整信息
    string getLongDescription();
    //返回ATK
    int getATK();
    //设置ATK
    void setATK(int ATK);
    //返回HP
    float getHP();
    //设置HP
    void setHP(int HP);
    //返回weaponCheck
	int getWeaponCheck();
    //设置weaponCheck
    void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
