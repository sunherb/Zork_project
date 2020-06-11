#include "charres.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <QString>
#include <algorithm>
charres::charres()
{
    rgw.push_back(std::make_pair("兔耳少女",":/new/gw/img/g1.jpg"));
    rgw.push_back(std::make_pair("城堡少女",":/new/gw/img/g2.jpg"));
    rgw.push_back(std::make_pair("时间少女",":/new/gw/img/g3.jpeg"));
    rgw.push_back(std::make_pair("星空少女",":/new/gw/img/g4.jpg"));
    rgw.push_back(std::make_pair("禁止少女",":/new/gw/img/g5.jpg"));
    rgw.push_back(std::make_pair("神秘大叔",":/new/gw/img/g6.jpg"));
    rgw.push_back(std::make_pair("阴阳",":/new/gw/img/g7.jpeg"));
    rgw.push_back(std::make_pair("云朵猎手",":/new/gw/img/g8.jpg"));
    rgw.push_back(std::make_pair("东京喰种",":/new/gw/img/g9.png"));
    rgw.push_back(std::make_pair("粉",":/new/gw/img/g10.jpg"));
    rgw.push_back(std::make_pair("黑色灵猫",":/new/gw/img/g11.jpeg"));
    rgw.push_back(std::make_pair("灼热之夏",":/new/gw/img/g12.jpeg"));
    rgw.push_back(std::make_pair("冬季者",":/new/gw/img/g13.jpeg"));
    rgw.push_back(std::make_pair("半身女",":/new/gw/img/g14.jpeg"));

    rei.push_back(std::make_pair("耳机终结者",":/new/zb/img/zb1.jpg"));
    rei.push_back(std::make_pair("天罗地网",":/new/zb/img/zb2.jpg"));
    rei.push_back(std::make_pair("皇族公主",":/new/zb/img/zb3.jpeg"));
    rei.push_back(std::make_pair("兽女",":/new/zb/img/zb4.jpg"));
    rei.push_back(std::make_pair("分辨率太大了要不要删掉啊",":/new/zb/img/zb5.jpeg"));
    rei.push_back(std::make_pair("激光炸裂",":/new/zb/img/zb6.jpeg"));
    rei.push_back(std::make_pair("剪刀女",":/new/zb/img/zb7.jpg"));
    rei.push_back(std::make_pair("黄金瞳",":/new/zb/img/zb8.jpeg"));
    rei.push_back(std::make_pair("塔兹米",":/new/zb/img/zb9.jpg"));
    rei.push_back(std::make_pair("赤瞳",":/new/zb/img/zb10.jpg"));
    rei.push_back(std::make_pair("恶鬼缠身",":/new/zb/img/zb11.jpg"));
    rei.push_back(std::make_pair("萌萌",":/new/zb/img/zb12.jpg"));
}
