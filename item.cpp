#include "item.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
Item::Item (string inDescription, int inATK, int inHP/**, int weaponCheck*/) {
    description = inDescription;
    setATK(inATK);
    HP = inHP;
	/**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription) {
    description = inDescription;
}

float Item::getHP(){
   return this->HP;
}

int Item::getATK(){
    return this->ATK;
}
void Item::setATK(int inATK)
{
    if (inATK > 9999 || inATK < 0)
       cout << "weight invalid, it must be 0< weight <9999 " ;
    else
       ATK = inATK;
}

void Item::setHP(int inHP)
{
    if (inHP > 9999 || inHP < 0)
       cout << "HP invalid, it must be 0 < HP < 9999 " ;
    else
       HP = inHP;
}

void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon <=5 && isWeapon >=1)
        this->weaponCheck=isWeapon ;
    else
        cout << "Item is a not weapon" ;
}

int Item::getWeaponCheck(){
   return this->weaponCheck;
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    stringstream t1;
    stringstream t2;
    string a1,a2;
    t1<<HP;
    t2<<ATK;
    t1>>a1;
    t2>>a2;
    return "item(s): " + description + ".\n" + "HP is " +a1 +"\n"+"ATK is " +a2+"\n";
}

