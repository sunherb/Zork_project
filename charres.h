#ifndef CHARRES_H
#define CHARRES_H
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
#include "QString"

class charres
{
public:
    std::vector<std::pair<std::string,QString>> rei;
    std::vector<std::pair<std::string,QString>> rgw;

    charres();
};

#endif // CHARRES_H
