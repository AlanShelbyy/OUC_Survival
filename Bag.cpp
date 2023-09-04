#include"Bag.h"
#include"Equipment.h"
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

extern vector<Equipment*> equipment_bag;

void Bag::bag_write() {
	int size = equipment_bag.size();
	ofstream ofs("data/Bag/bag.dat", ios::out | ios::binary);
	if (!ofs)
		cout << "您的存档喝了孟婆汤，请快去开始新的游戏吧！" << endl;
	else {
		for (int i = 0; i < size; i++) {
			cout << size << endl;
			ofs.write(reinterpret_cast<char*>(equipment_bag[i]), sizeof(Equipment));
			equipment_bag[i]->show();
		}
	}
	cout << "存档成功" << endl;
	ofs.close();
}


void Bag::bag_read() {
	ifstream ifs("data/Bag/bag.dat", ios::in | ios::binary);
	int i = 0;
	Equipment* l = new Equipment;
	cout << "开始读取" << endl;
	while (!ifs.eof()) {
		ifs.read(reinterpret_cast<char*>(l), sizeof(Equipment));
		if(!ifs.eof())
			equipment_bag.push_back(l);
		cout << "读取成功" << endl;
		equipment_bag[i]->show();
		i++;
	}
}