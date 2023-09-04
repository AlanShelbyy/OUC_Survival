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
		cout << "���Ĵ浵���������������ȥ��ʼ�µ���Ϸ�ɣ�" << endl;
	else {
		for (int i = 0; i < size; i++) {
			cout << size << endl;
			ofs.write(reinterpret_cast<char*>(equipment_bag[i]), sizeof(Equipment));
			equipment_bag[i]->show();
		}
	}
	cout << "�浵�ɹ�" << endl;
	ofs.close();
}


void Bag::bag_read() {
	ifstream ifs("data/Bag/bag.dat", ios::in | ios::binary);
	int i = 0;
	Equipment* l = new Equipment;
	cout << "��ʼ��ȡ" << endl;
	while (!ifs.eof()) {
		ifs.read(reinterpret_cast<char*>(l), sizeof(Equipment));
		if(!ifs.eof())
			equipment_bag.push_back(l);
		cout << "��ȡ�ɹ�" << endl;
		equipment_bag[i]->show();
		i++;
	}
}