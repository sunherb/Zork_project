#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
    //指令词类典
	CommandWords *commands;

public:
    //创建指令词典类对象
	Parser();
    //输入一行句子如果第一个单词是指令词，则创建的指令词对象的第一个值是第一个单词否则不是
	Command* getCommand();
    //展示全部指令词
	void showCommands();
};

#endif /*PARSER_H_*/
