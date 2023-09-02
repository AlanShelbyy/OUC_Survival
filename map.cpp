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

ouc_map Ouc_map[19];

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
        cout << "�޷����ļ�" << endl;
    }
    return 0;
}

ouc_map::ouc_map( int n ) {
    string fname = "data/map";
    string change;
    name = fname + "/" + to_string(n) + ".dat";
    ifstream readf(name);
    if (!readf)
        cout << "�޷����ļ�" << name << endl;
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

//����ͼ�ļ�������Ouc_map������
void loadMap(ouc_map Ouc_map[]) {
    for (int i = 0; i < 19; i++) {
        ouc_map map(i + 1);
        Ouc_map[i] = map;
    }
}



int main() {
    loadMap(Ouc_map);
 /*   for (int i = 0; i < 19; i++) {
        Ouc_map[i].show();
    }*/
    short neib[6];
    Ouc_map[18].getNeib(neib);
    for (int i = 0; i < 6; i++) {
        if (neib[i] != 0)
            cout << i + 1 << ". " << Ouc_map[neib[i]-1].getName() << endl;
        else
            break;
    }
    return 0;
}

//������뺯��
int Player_scanf() {
    int a;
    cin >> a;
    return a;
}

//�ƶ�����
void move(Player& you) {
    int num;
    short neib[6];
    you.get_map()->getNeib(neib);
    cout << "��ʲô��ȥ�ĵط���" << endl;
    //��ӡ���ƶ����Ľڵ�
    int size = 0;//���ƶ��ڵ������
    for (int i = 0; i < 6; i++) {
        if (neib[i] != 0) {
            cout << i + 1 << ". " << Ouc_map[neib[i] - 1].getName() << endl;
            size++;
        }
        else
            break;
    }
    //�������ѡ���ƶ�
    int choice;
    choice = Player_scanf();
    while (choice < 1 || choice > size) {
        cout << "��Ч���룬������ѡ��" << endl;
        choice = Player_scanf();
    }
    you.changep_m(neib[choice - 1] - 1);
    num = you.get_map()->getId();

    //�ƶ�ʱ���ʻ�ȡװ��
    srand(time(NULL));
    int equip_id;
    int probability;
    equip_id = rand() % 10;
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
            if (probability < 15) {
                bool isTrue = 0;
                //��������ڸ�װ��ʱ
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ��" << equipment_bag[i]->get_name() << endl;
                        break;
                    }
                }
                //������ʱ��Ӹ�װ��
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ��" << equipment_bag[equipment_bag.size() - 1]->get_name() << endl;
                }
            }
        }
        break;
    case 7:
        probability = rand() % 100;
        if (probability < 10) {
            bool isTrue = 0;
            //��������ڸ�װ��ʱ
            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    equipment_bag[i]->num_plus();
                    cout << "����֮ϲ���������ƶ�������" << "ʰȡ��һ��" << equipment_bag[i]->get_name() << endl;
                    break;
                }
            }
            //������ʱ��Ӹ�װ��
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "����֮ϲ���������ƶ�������" << "ʰȡ��һ��" << equipment_bag[equipment_bag.size() - 1]->get_name() << endl;
            }
        }
        break;
    case 8:
        probability = rand() % 100;
        if (probability < 20) {
            bool isTrue = 0;
            //��������ڸ�װ��ʱ
            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    equipment_bag[i]->num_plus();
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "����һƿ" << equipment_bag[i]->get_name() << "������ȷ���Һ���" << endl;
                    break;
                }
            }
            //������ʱ��Ӹ�װ��
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һƿ" << equipment_bag[equipment_bag.size() - 1]->get_name() << "������ȷ���Һ���" << endl;
            }
        }
        break;
    case 9:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < 2) {
                bool isTrue = 0;
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���" << equipment_bag[i]->get_name() << "���������ƺ���ʹ��Բ���ѧϰ���ݸ���ͨ͸" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���" << equipment_bag[equipment_bag.size() - 1]->get_name() << "���������ƺ���ʹ��Բ���ѧϰ���ݸ���ͨ͸" << endl;
                }
            }
        }
        break;
    case 10:
        if (num == 10 || num == 11 || num == 12 || num == 13 || num == 14 || num == 15) {
            probability = rand() % 100;
            if (probability < 2) {
                bool isTrue = 0;
                //��������ڸ�װ��ʱ
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ��û��Ҫ��" << equipment_bag[i]->get_name() << "����ż���ǻ���ڱ��ģ������Ȼ���ܰ�" << endl;
                        break;
                    }
                }
                //������ʱ��Ӹ�װ��
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ��û��Ҫ��" << equipment_bag[equipment_bag.size() - 1]->get_name() << "����ż���ǻ���ڱ��ģ������Ȼ���ܰ�" << endl;
                }
            }
        }
        break;
    case 11:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < 5) {
                bool isTrue = 0;
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ�Ŵ��е�" << equipment_bag[i]->get_name() << "����Ȼ��Щ�ʲݣ����㻹��һ���ϳ�������д����������õ���Ŀ" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "�ҵ���һ�Ŵ��е�" << equipment_bag[equipment_bag.size() - 1]->get_name() << "����Ȼ��Щ�ʲݣ����㻹��һ���ϳ�������д����������õ���Ŀ" << endl;
                }
            }
        }
        break;
    case 12:
        if (num == 4 || num == 16 || num == 17 || num == 18 || num == 5 || num == 6) {
            probability = rand() % 100;
            if (probability < 1) {
                bool isTrue = 0;
                for (int i = 0; i < equipment_bag.size(); i++) {
                    if (equipment_bag[i]->get_id() == equip_id) {
                        isTrue = 1;
                        equipment_bag[i]->num_plus();
                        cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "ʱ��ĳλ���ж��������ʣ�������" << equipment_bag[i]->get_name() << "�������İ����£�������涼���˲��ٳ���" << endl;
                        break;
                    }
                }
                if (!isTrue) {
                    equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                    cout << "����֮ϲ��������" << Ouc_map[num - 1].getName() << "ʱ��ĳλ���ж��������ʣ�������" << equipment_bag[equipment_bag.size() - 1]->get_name() << "�������İ����£�������涼���˲��ٳ���" << endl;
                }
            }
        }
        break;
    case 17:
        probability = rand() % 100;
        if (probability < 30) {
            bool isTrue = 0;
            for (int i = 0; i < equipment_bag.size(); i++) {
                if (equipment_bag[i]->get_id() == equip_id) {
                    isTrue = 1;
                    break;
                }
            }
            if (!isTrue) {
                equipment_bag.push_back(new Equipment{ "data/Equipment",equip_id });
                cout << "����֮ϲ���������ƶ�ʱ������һ˫û��Ҫ��" << equipment_bag[equipment_bag.size() - 1]->get_name() << "�������������ƺ��ܹ���ڵ��ƶ���" << endl;
            }
        }
    }
 
    
}

//�����ƶ��ĺ���
void quick_move(Player& you, int num) {
    cout << "������ȥ������";
    cout << setfill('=') << setw(25) << "��ͼ�ڵ�" << setfill('=') << setw(25) << "" << endl;
    for (int i = 0; i < 19; i++) {
        Ouc_map[i].show();
    }
    int choice = Player_scanf();
    while (choice < 1 || choice>19) {
        cout << "����ѡ�����������������ô��Ҳ��������" << endl;
        choice = Player_scanf();
    }
    you.changep_m(choice);
}

//��ӡ��ǰλ�õĺ���
void show_address(Player& you) {
    cout << setfill('=') << setw(25) << "��ͼ�ڵ�" << setfill('=') << setw(25) << "" << endl;
    cout << "�㵱ǰ���ڡ���" << you.get_map()->getName() << endl;
    cout << "�ýڵ��ͼ����ǣ�" << you.get_map()->getId() << endl;
}