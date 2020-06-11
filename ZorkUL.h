#ifndef ZORKUL_H_
#define ZORKUL_H_
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "character.h"
#include "charres.h"
#include "event.h"
using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;

    //创建房间
	void createRooms();
    //输出初始
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();

    void displayItems();
    //teleportRoom函数从房间中所有房间随机挑选一个进入

public:
    //存储当前所有房间
    vector <Room*> Rooms;
    int be;
    charres *res;
    Character *Chara;
    QString teleportRoom();
    QString goRoom(Command * command);
	ZorkUL();
	void play();
    Room * go(string direction);
    QString fy();
    QString roomname();
    Event * Createvent(int i);
    Item * createItems(int i);
};

#endif /*ZORKUL_H_*/
