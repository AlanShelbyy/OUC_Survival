#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include"Equipment.h"
using namespace std;

Equipment::Equipment(string fname1,int n) {
	string change;
	name = fname1 + "/" + to_string(n) + ".dat";
	ifstream readf(name);
	if (!readf)
		cout << "�޷���" << name<<endl;
	getline(readf, change);
	id = stoi(change);
	getline(readf, intro);
	to_player.push_back(intro);
	getline(readf, name);
	to_player.push_back(name);
	getline(readf, change);
	equip.Player_AbilityofLearn = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	equip.Player_AbilityofProgramming = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	equip.Player_AbilityofMath = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	equip.Player_AbilityofLogic = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	equip.Player_AbilityofPractice = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	equip.Player_Action_Points = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	num = stoi(change);
	to_player.push_back(change);
	getline(readf, change);
	status.on = change == "true" ? true : false;
	getline(readf, change);
	status.immediate = change == "true" ? true : false;
	readf.close();
}

void Equipment::show() {
	cout << setfill('=')<<setw(25)<< "װ???" <<setfill('=') << setw(25) << "" << endl;
	cout << intro << endl;
	cout << name << endl;
	cout <<"ѧϰ???" << equip.Player_AbilityofLearn << endl;
	cout << "�������"<<equip.Player_AbilityofProgramming << endl;
	cout << "��???��"<<equip.Player_AbilityofMath << endl;
	cout << "�߼�???"<<equip.Player_AbilityofLogic << endl;
	cout << "ʵ��???"<<equip.Player_AbilityofPractice << endl;
	cout << "�ж�???"<<equip.Player_Action_Points << endl;
	cout << "����"<<num << endl;
}