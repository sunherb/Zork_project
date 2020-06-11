#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include <string>
using namespace std;

class Command {
private:
    //建
	string commandWord;
    //值
	string secondWord;

public:
    //第一个值是commandWord，第二个是secondWord
	Command(string firstWord, string secondWord);
    //返回commandWord
	string getCommandWord();
    //返回secondWord
	string getSecondWord();
    //commandWord是空则是未知词，返回他是否为空
	bool isUnknown();
    //返回secondWord是否为空
	bool hasSecondWord();
};

#endif /*COMMAND_H_*/
