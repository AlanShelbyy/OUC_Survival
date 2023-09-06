#include <iostream>
#include <fstream>
#include <string>
#include "map.h"
#include<iomanip>
#include"global.h"
#include"Equipment.h"
#include <time.h> 
#include"Player.h"
using namespace std;

extern ouc_map Ouc_map[19];

int showMap() {
    string line;
    ifstream file("data/map.dat");
    if (file.is_open()) { 
        while (getline(file, line)) { 
            cout << line << endl; 
        }
        file.close(); 
    }
    else {
        cout << "无法打开文件" << endl;
    }
    return 0;
}

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


//玩家输入函数
int Player_scanf() {
    int a;
    cin >> a;
    return a;
}

bool MofE(int equip_id, int num, int a, int b, int c, int d, int e, int f, int g);


//移动函数
void move(Player& you) {
    int num;
    short neib[6];
    you.get_map()->getNeib(neib);
    cout << "有什么想去的地方吗？" << endl;
    //打印能移动到的节点
    int size = 0;//能移动节点的数量
    for (int i = 0; i < 6; i++) {
        if (neib[i] != 0) {
            cout << i + 1 << ". " << Ouc_map[neib[i] - 1].getName() << endl;
            size++;
        }
        else
            break;
    }
    //根据玩家选择移动
    int choice;
    choice = Player_scanf();
    while (choice < 1 || choice > size) {
        cout << "无效输入，请重新选择" << endl;
        choice = Player_scanf();
    }
    you.changep_m(neib[choice - 1] - 1);
    num = you.get_map()->getId();

    //移动时概率获取装备
    srand(time(NULL));
    int equip_id;
    int probability;
    equip_id = rand() % 19;
    MofE(equip_id, num, 15, 10, 20, 2, 5, 1, 30);
    
    //刷新0-3个npc 
    num = rand() % 4;
    for (int i = 0; i < num; i++) {
        bool isTrue = 0;
        int Npc_id = rand() % 4;
        for (int i = 0; i < you.get_map()->getNpc_id().size(); i++) {
            if (Npc_id == you.get_map()->getNpc_id()[i]) {
                isTrue = 1;
                break;
            }
        }
        if (!isTrue)
            you.get_map()->getNpc_id().push_back(Npc_id);
    }
    //固定刷新boss
    if (num = you.get_map()->getId() == 17)
        you.get_map()->getBoss_id().push_back(0);
    if (num = you.get_map()->getId() == 6)
        you.get_map()->getBoss_id().push_back(1);
    if (num = you.get_map()->getId() == 9)
        you.get_map()->getBoss_id().push_back(2);
}

void map_explore(Player& you) {
    srand(time(NULL));
    int equip_id = rand() % 19;
    bool theBool = 0;
    int num = you.get_map()->getId();
    theBool = MofE(equip_id, num, 30, 20, 40, 4, 10, 2, 60);
    if (!theBool)
        cout << "运气真差，似乎并没有找到什么有用的东西" << endl;
}

//快速移动的函数
void quick_move(Player& you, int num) {
    cout << "是想跑去哪里吗？";
    cout << setfill('=') << setw(25) << "地图节点" << setfill('=') << setw(25) << "" << endl;
    for (int i = 0; i < 19; i++) {
        Ouc_map[i].show();
    }
    int choice = Player_scanf();
    while (choice < 1 || choice>19) {
        cout << "别尝试选项以外的数字啦，怎么想也做不到的" << endl;
        choice = Player_scanf();
    }
    you.changep_m(choice);
}

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
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
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
