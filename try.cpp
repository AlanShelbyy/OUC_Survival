#include"Equipment.h"
#include"Bag.h"
#include<iostream>

vector<Equipment*> equipment_bag;

int main() {
	Equipment myequip("data/Equipment");
	myequip.show();
	equipment_bag.push_back(&myequip);
	Bag mybag;
	mybag.bag_write();
	mybag.bag_read();
	cout << equipment_bag.size() << endl;
	cout << equipment_bag[0]->get_AbilityofLearn() << endl;
	equipment_bag[1]->show();
}