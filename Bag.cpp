#include"Bag.h"
#include"Equipment.h"
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

extern vector<Equipment*> equipment_bag;

void Bag::bag_write() {
	int size = equipment_bag.size();
	int num = 0;
	cout << "��ʼ�浵" << endl;
	ofstream ofs("data/Bag/bag.dat", ios::out | ios::binary);
	if (!ofs)
		cout << "���Ĵ浵���������������ȥ��ʼ�µ���Ϸ�ɣ�" << endl;
	else {
		for (int i = 0; i < size; i++) {
			num = equipment_bag[i]->get_id();
			ofs.write(reinterpret_cast<char*>(&num), sizeof(num));
		}
	}
	cout << "�浵�ɹ�" << endl;
	equipment_bag.clear();//��ձ���
	ofs.close();
}
void Bag::bag_read() {
	ifstream ifs("data/Bag/bag.dat", ios::in | ios::binary);
	int num = 0;
	cout << "��ʼ��ȡ" << endl;
	while (!ifs.eof()) {
		ifs.read(reinterpret_cast<char*>(&num), sizeof(num));
		Equipment* l = new Equipment("data/Equipment", num);
		if (!ifs.eof()) {
			equipment_bag.push_back(l);
		}
	}
	cout << "��ȡ�ɹ�" << endl;
	ifs.close();
}