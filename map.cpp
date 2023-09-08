#include <iostream>
#include <fstream>
#include <string>
#include "map.h"
#include<iomanip>
//#include"global.h"
#include"Equipment.h"
#include <time.h> 
#include"Player.h"
using namespace std;

extern ouc_map Ouc_map[19];
extern vector<Equipment*> equipment_bag;



ouc_map::ouc_map( int n ) {
    string fname = "data/map";
    string change;
    name = fname + "/" + to_string(n) + ".dat";
    ifstream readf(name);
    if (!readf)
        cout << "无法打开文件" << name << endl;
    getline(readf, name);
    getline(readf,change);
    map_id = stoi(change);
    getline(readf, change);
    neighbor[0] = stoi(change);
    getline(readf, change);
    neighbor[1] = stoi(change);
    getline(readf, change);
    neighbor[2] = stoi(change);
    getline(readf, change);
    neighbor[3] = stoi(change);
    getline(readf, change);
    neighbor[4] = stoi(change);
    getline(readf, change);
    neighbor[5] = stoi(change);
}



void ouc_map::show() {
    cout << map_id << ". " << name << endl;
}

ouc_map::ouc_map(ouc_map& d) {
    name = d.name;
    map_id = d.map_id;  
    for (int i = 0; i < 6; i++) {
        neighbor[i] = d.neighbor[i];
    }
    npc_id.assign(3, 3);
}

//将地图文件加载入Ouc_map数组里
void loadMap(ouc_map Ouc_map[]) {
    for (int i = 0; i < 19; i++) {
        ouc_map map(i + 1);
        Ouc_map[i] = map;
    }
}







bool MofE(int equip_id, int num, int a, int b, int c, int d, int e, int f, int g);








//打印当前位置的函数
void show_address(Player& you) {
    cout << setfill('=') << setw(25) << "地图节点" << setfill('=') << setw(25) << "" << endl;
    cout << "你当前处于——" << you.get_map()->getName() << endl;
    cout << "该节点地图编号是：" << you.get_map()->getId() << endl;
}


bool MofE(int equip_id, int num, int a, int b, int c, int d, int e , int f, int g) {
    bool theBool = 0;
    int probability;
    switch (equip_id) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            cout<<"prob"<<probability<<endl;
            if (probability < a) {
                bool isTrue = 0;

                //背包里存在该装备时
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一本" << equipment_bag[i]->get_name() << endl;

                        break;
                    }
                }
                //不存在时添加该装备
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment("data/Equipment",equip_id ));
                    cout<<"添加成功"<<endl;
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一本" << equipment_bag[equipment_bag.size() - 1]->get_name() << endl;
                }
                theBool = 1;

            }
        }
        break;
    case 7:
        probability = rand() % 100;
        if (probability < b) {
            bool isTrue = 0;

            //背包里存在该装备时
            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    equipment_bag[i]->num_plus();
                    cout << "意外之喜——你在移动过程中" << "拾取了一张" << equipment_bag[i]->get_name() << endl;
                    break;
                }
            }
            //不存在时添加该装备
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "意外之喜——你" << "拾取了一张" << equipment_bag[equipment_bag.size() - 1]->get_name() << endl;
            }
            theBool = 1;

        }
        break;
    case 8:
        probability = rand() % 100;
        if (probability < c) {
            bool isTrue = 0;

            //背包里存在该装备时
            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    equipment_bag[i]->num_plus();
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "捡到了一瓶" << equipment_bag[i]->get_name() << "，但你确定敢喝吗" << endl;
                    break;
                }
            }
            //不存在时添加该装备
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一瓶" << equipment_bag[equipment_bag.size() - 1]->get_name() << "，但你确定敢喝吗" << endl;
            }
            theBool = 1;

        }
        break;
    case 9:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < d) {
                bool isTrue = 0;

                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了" << equipment_bag[i]->get_name() << "，看起来似乎能使你对部分学习内容更加通透" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了" << equipment_bag[equipment_bag.size() - 1]->get_name() << "，看起来似乎能使你对部分学习内容更加通透" << endl;
                }
                theBool = 1;

            }
        }
        break;
    case 10:
        if (num == 10 || num == 11 || num == 12 || num == 13 || num == 14 || num == 15) {
            probability = rand() % 100;
            if (probability < d) {
                bool isTrue = 0;

                //背包里存在该装备时
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一副没人要的" << equipment_bag[i]->get_name() << "天上偶尔是会掉馅饼的，你就欣然接受吧" << endl;
                        break;
                    }
                }
                //不存在时添加该装备
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一副没人要的" << equipment_bag[equipment_bag.size() - 1]->get_name() << "天上偶尔是会掉馅饼的，你就欣然接受吧" << endl;
                }
                theBool = 1;

            }
        }
        break;
    case 11:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < e) {
                bool isTrue = 0;

                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一张大佬的" << equipment_bag[i]->get_name() << "，虽然有些潦草，但你还是一眼认出上面正写着困扰你许久的题目" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "找到了一张大佬的" << equipment_bag[equipment_bag.size() - 1]->get_name() << "，虽然有些潦草，但你还是一眼认出上面正写着困扰你许久的题目" << endl;
                }
                theBool = 1;

            }
        }
        break;
    case 12:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < f) {
                bool isTrue = 0;

                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "时，某位大佬对你相见如故，你获得了" << equipment_bag[i]->get_name() << "，在他的帮助下，你各方面都有了不少长进" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "意外之喜——你在" << Ouc_map[num - 1].getName() << "时，某位大佬对你相见如故，你获得了" << equipment_bag[equipment_bag.size() - 1]->get_name() << "，在他的帮助下，你各方面都有了不少长进" << endl;
                }
                theBool = 1;

            }
        }
        break;
    case 15:
        probability = rand() % 100;
        if (probability < g) {
            bool isTrue = 0;

            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    break;
                }
            }
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "意外之喜——你捡到了一双没人要的" << equipment_bag[equipment_bag.size() - 1]->get_name() << "，穿上它后你似乎能够跨节点移动了" << endl;
            }
            theBool = 1;

        }
        break;
    default:
        break;
    }

    return theBool;
}

