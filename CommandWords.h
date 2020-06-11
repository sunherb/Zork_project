#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <QString>
#include <algorithm>
using namespace std;

class CommandWords {
private:
	//Define a static vector for our valid command words.
	//We'll populate this in the class constructor
	static vector<string> validCommands;

public:
    //放入指令词在validCommands中
	CommandWords();
    //判断字符串是否是指令词
	bool isCommand(string aString);
    //输出全部指令词
	void showAll();
};


#endif /*COMMANDWORDS_H_*/
