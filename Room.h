#ifndef ROOM_H_
#define ROOM_H_

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <QString>
#include <algorithm>
#include "item.h"
#include "event.h"
using namespace std;
using std::vector;

class Room {

private:
    //房间名
	string description;

    //出口地图，四个方向
	map<string, Room*> exits;

    //房间道具
    vector <Item> itemsInRoom;


public:
    Event *ev;

    //返回道具数量
    int numberOfItems();

    //返回下一个房间名称
    string exitString();

    //创建房间，房间提示为description
	Room(string description);

    //设置四个方向的出口
	void setExits(Room *north, Room *east, Room *south, Room *west);

    //返回description
	string shortDescription();

    //返回"room = " + description + ".\n" + displayItem() + exitString()房间详细信息
	string longDescription();

    //返回map下一个房间（实例）direction 东南西北（英文）
	Room* nextRoom(string direction);

    //将一个Item添加到itemsInRoom中
    void addItem(Item *inItem);

    //返回所有在房间中的道具
    string displayItem();

    //查找一个道具是否在房间中，如果在房间没有道具返回0，如果没有传入道具返回-1，如果有返回道具位置
    int isItemInRoom(string inString);

    //删除道具在房间中
    void removeItemFromRoom(int location);

    void addevent(Event *e);
};

#endif
