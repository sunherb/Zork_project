#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <time.h>
#include <ctime>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#include "ZorkUL.h"
#include "QDebug"
ZorkUL::ZorkUL() {
    res=new charres();
    Chara = new Character();
    createRooms();
    Chara->Ep=3;
    srand(time(0));
    int i1=rand()%5+1;
    Item *p=createItems(i1);
    p->setATK(3);
    Chara->bbs.push_back(p);
    Chara->setb();

//    Event *p=new Event();
//    currentRoom->ev=p;
//    p->show();
    //
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i,*j ;
    //creat room  and a ...

    a = new Room("a");
    b = new Room("b");
    srand(time(0));
    int p = rand()%4;
    b->ev=Createvent(p);
    c = new Room("c");
    p=rand()%4+2;
    c->ev=Createvent(p);
    p=rand()%4+3;
    d = new Room("d");
    p=rand()%4+4;
    d->ev=Createvent(p);
    e = new Room("e");
    p=rand()%4+5;
    e->ev=Createvent(p);
    p=rand()%4+6;
    f = new Room("f");
    f->ev=Createvent(p);
    p=rand()%4+7;
    g = new Room("g");
    g->ev=Createvent(p);
    p=rand()%4+8;
    h = new Room("h");
    h->ev=Createvent(p);
    p=rand()%4+9;
    i = new Room("i");
    i->ev=Createvent(p);
    //new room
    j =  new Room("j");
    j ->ev=Createvent(14);
//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, j , i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j ->setExits(d,NULL,NULL,NULL);
        currentRoom = a;
    //所有房间导入Rooms
    Rooms.push_back(a);
    Rooms.push_back(b);
    Rooms.push_back(c);
    Rooms.push_back(d);
    Rooms.push_back(e);
    Rooms.push_back(f);
    Rooms.push_back(g);
    Rooms.push_back(h);
    Rooms.push_back(i);
    Rooms.push_back(j);
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();
	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |                " << endl;
        cout << "         |                " << endl;
        cout << "        [j]               " << endl;
		}

//    a->setExits(f, b, d, c);
//    b->setExits(NULL, NULL, NULL, a);
//    c->setExits(NULL, a, NULL, NULL);
//    d->setExits(a, e, j , i);
//    e->setExits(NULL, NULL, NULL, d);
//    f->setExits(NULL, g, a, h);
//    g->setExits(NULL, NULL, NULL, f);
//    h->setExits(NULL, f, NULL, NULL);
//    i->setExits(NULL, d, NULL, NULL);
//    j ->setExits(d,NULL,NULL,NULL);






    else if (commandWord.compare("go") == 0){
    }
        //goRoom(command);
    //添加关键词teleport对比
    else if (commandWord.compare("teleport")==0){
        teleportRoom();
    }
    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  <= 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp()
{
	cout << "valid inputs are; " << endl;
	parser.showCommands();
}
class Variables{
private:
    int name_of_variables;
public:
    Variables(){
        name_of_variables = 0;
    }
    Variables(int n){
        name_of_variables = n;
    }
    void operator=(const Variables &N ){
        name_of_variables = N.name_of_variables;
    }
};

class Tips
{
   string NPC;
public:
   friend void printNote( Tips note );
   void setNote( string wid );
};

void Tips::setNote( string npc )
{
    NPC = npc;
}

void printNote(Tips note )
{
   cout << note.NPC <<endl;
}

class A{
    public :
    A(){}
    void f1()
    {
        cout<< "......" <<endl;
    }
    virtual void f()
    {
        cout<< "waiting" << endl;
    }

};// note of lry
// Polymorphism

class B : public A{
    public :
    B() {}
    void f()
    {
        cout<< "have a good day! " << endl;
    }
};
 //teleportRoom函数从房间中所有房间随机挑选一个进入
QString ZorkUL::teleportRoom(){
    int n=Rooms.size();
    srand(time(0));
    A *abc = new B();
    abc -> f1();
    abc -> f();

    int p = 0;
       Variables N1(p), N2(rand()%n);
       N1 = N2;
    currentRoom=Rooms[p];
    Tips note;
        note.setNote("The room of transmission is");
        printNote( note );
        return "SUCCESS! The room of transmission is ";
        //lry note:
}

QString ZorkUL::goRoom(Command * command)
{
    if (!command->hasSecondWord()) {
        //cout << "incomplete input"<< endl;
        return "incomplete input";
	}

    string direction = command->getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
        return "underdefined input";
	else {
		currentRoom = nextRoom;
        return this->fy();
	}
}

Room * ZorkUL::go(string direction)
{
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return NULL;
	else
	{
        return nextRoom;
	}
}
QString ZorkUL::fy()
{
    QString str;
    str=QString::fromStdString(currentRoom->longDescription());
    return str;
}
QString ZorkUL::roomname(){
    QString str;
    str=QString::fromStdString(currentRoom->shortDescription());
    return str;
}
Event * ZorkUL::Createvent(int i){
    if(i<=(int)res->rgw.size()&&i>=1){
        srand(time(0));
        int k2=rand()%(12-i)+i;
        if(k2>i+3){
            k2=i+3;
        }
        if(i==14){
            k2=12;
        }
        Item *w =createItems(k2);
        Event *p=new Event();
        p->icon=res->rgw[i-1].second;
        p->ne=QString::fromStdString(res->rgw[i-1].first);
        p->titem=w;
        int A=rand()%i+i+2;
        p->gwATK=A;
        int H=rand()%i+i+7;
        p->gwHP=H;
        return p;
    }
    else
    return NULL;
}
Item * ZorkUL::createItems(int i){
    if(i<=(int)res->rei.size()&&i>=1){
        srand(time(0));
        int A=rand()%i+i+1;
        int H=rand()%i+i+5;
        string d=res->rei[i-1].first;
        Item * p= new Item(d,A,H);
        p->icon=res->rei[i-1].second;
        return p;
    }
    else{
        return NULL;
    }
}
