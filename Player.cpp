
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<algorithm>
#include"Player.h"
#include<vector>
#include"Equipment.h"
#include "map.h"
#include<fstream>
#include"Bag.h"

using namespace std;
extern vector<Equipment*> equipment_bag;
extern ouc_map Ouc_map[19];

struct Player_Stats
{
	int DateCount=1; //?? 
	char Major[32];
	int Player_AbilityofLearn;  //??? 
	int Player_AbilityofProgramming;  //????? 
	int Player_AbilityofMath;  // ????? 
	int Player_AbilityofLogic;  //????? 
	int Player_AbilityofPractice;  //????? 
	int Player_Action_Points;  //??? 
};

void Player::changep_m(int num) {
	p_m = &Ouc_map[num];
};//????
short Player::getMap_id() {
	return p_m->getId();
}
ouc_map* Player::get_map() {
	return p_m;
}

/*void clear()
{
	cout << endl;
	cout << endl;
	cout << endl;
	int temp_cl;
	cout << "???????...";
	cin >> temp_cl;
	if (temp_cl)
	{
		system("cls");
	}

}*/

void showMap() {
	string line;
	ifstream file("data/map.dat");
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "??????" << endl;
	}
}
Player::Player(){//????
	p = (struct Player_Stats*)new struct Player_Stats;
	
}
void Player::GetReward(int pro , int mat , int log , int pra , int lnp){
	p->Player_AbilityofLearn += lnp;
	p->Player_AbilityofLogic += log;
	p->Player_AbilityofMath += mat;
	p->Player_AbilityofPractice =+ pra;
	p->Player_AbilityofProgramming += pro;
}


// Player::Player()  //???? 
// {
// 	cout << endl;
// 	cout << "????? OUC ?? ?"; Sleep(400);
// 	cout << "????????????????? ????????????? : " << endl;
// 	cout << "1. ????????" << endl;
// 	cout << "2. ???????" << endl;
// 	cout << "3. ??????" << endl;
// 	cout << "4. ????" << endl;
// 	cout << endl;
// 	cout << "????????????? : " << endl;
// 	cin >> flag_major;
// 	if (flag_major == 1)
// 	{
// 		cout << "???? [????????] ?????  " << endl;
// 		Sleep(300);
// 		cout << "?????? ?????? ?????? ??????? " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 4;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 2;
// 		p->Player_AbilityofPractice = 2;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 2)
// 	{
// 		cout << "???? [???????] ?????  " << endl;
// 		Sleep(300);
// 		cout << "?????? ?????? ?????? ??????? " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 2;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 4;
// 		p->Player_AbilityofPractice = 2;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 3)
// 	{
// 		cout << "???? [??????] ?????  " << endl;
// 		Sleep(300);
// 		cout << "?????? ?????? ?????? ??????? " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 2;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 3;
// 		p->Player_AbilityofPractice = 3;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 4)
// 	{
// 		cout << "???? [????] ?????  " << endl;
// 		Sleep(300);
// 		cout << "?????? ?????? ?????? ??????? " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 4;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 2;
// 		p->Player_AbilityofPractice = 2;
// 		p->Player_Action_Points = 10;
// 	}
	
// }

void Player::ChooseMajor()
{

	cout << endl;
	cout << "????? OUC ?? ?"; Sleep(400);
	cout << "????????????????? ????????????? : " << endl;
	cout << "1. ????????" << endl;
	cout << "2. ???????" << endl;
	cout << "3. ??????" << endl;
	cout << "4. ????" << endl;
	cout << endl;
	cout << "????????????? : " << endl;
	cin >> flag_major;
	if (flag_major == 1)
	{
		cout << "???? [????????] ?????  " << endl;
		Sleep(300);
		cout << "?????? ?????? ?????? ??????? " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[????????]");
	}
	else if (flag_major == 2)
	{
		cout << "???? [???????] ?????  " << endl;
		Sleep(300);
		cout << "?????? ?????? ?????? ??????? " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 4;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[???????]");
	}
	else if (flag_major == 3)
	{
		cout << "???? [??????] ?????  " << endl;
		Sleep(300);
		cout << "?????? ?????? ?????? ??????? " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 3;
		p->Player_AbilityofPractice = 3;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[??????]");
	}
	else if (flag_major == 4)
	{
		cout << "???? [????] ?????  " << endl;
		Sleep(300);
		cout << "?????? ?????? ?????? ??????? " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[????]");
	}
	
}

int Player::Getter_learn(){
	return p->Player_AbilityofLearn;
}

void Player::be_attack(int damage){
	p->Player_AbilityofLearn -= damage ;
}
void Player::Tasks()
{
	cout << "?10???????????? [????] ? [????] ???????????????" << endl;
	cout << "?????????????? [??] ??????6?????????" << endl;
}

void Player::State() const //???????? 
{
	cout << endl;
	cout << "???? [" << p->Major << ']' << endl;
	cout << "??? : " << p->Player_AbilityofLearn << endl;
	cout << "??? : " << p->Player_Action_Points << endl;
	cout << "????? : " << p->Player_AbilityofProgramming << endl;
	cout << "????? : " << p->Player_AbilityofMath << endl;
	cout << "????? : " << p->Player_AbilityofLogic << endl;
	cout << "????? : " << p->Player_AbilityofPractice << endl;
	cout << "??????? : " << p->DateCount << endl;
}

void Player::Equip_equipments(int num_eq)
{
	Equipment player_equ;
	cout << endl;
	cout << " ?? [" << equipment_bag[num_eq-1] << "] ??? :" << endl;
	cout << "1. ?????" << endl;
	cout << "2. ???????" << endl;
	cout << "3. ?????" << endl;
	cout << "4. ????? " << endl;
	int flag_eq;
	cin >> flag_eq;
	if (flag_eq == 1)
	{
		cout << "?????????? : " << endl;
		p->Player_AbilityofLearn+= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //??? 
		this->p->Player_AbilityofProgramming += equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //????? 
		this->p->Player_AbilityofMath += equipment_bag[num_eq - 1]->get_AbilityofMath(); // ????? 
		this->p->Player_AbilityofLogic += equipment_bag[num_eq - 1]->get_AbilityofLogic();  //????? 
		this->p->Player_AbilityofPractice += equipment_bag[num_eq - 1]->get_AbilityofPractice();  //????? 
		equipment_bag[num_eq - 1]->show();
	}
	else if (flag_eq == 2)
	{
		equipment_bag[num_eq-1]->show();
	}
	else if (flag_eq == 3)
	{
		if (!equipment_bag[num_eq - 1]->get_on()) //????
		{
			cout << "??????? ????" << endl;
		}
		else
		{
			this->p->Player_AbilityofLearn -= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //??? 
			this->p->Player_AbilityofProgramming -= equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //????? 
			this->p->Player_AbilityofMath -= equipment_bag[num_eq - 1]->get_AbilityofMath(); // ????? 
			this->p->Player_AbilityofLogic -= equipment_bag[num_eq - 1]->get_AbilityofLogic();  //????? 
			this->p->Player_AbilityofPractice -= equipment_bag[num_eq - 1]->get_AbilityofPractice();  //????? 
			equipment_bag[num_eq - 1]->show();
		}
	}
	else if (flag_eq == 4)
	{
		cout << "????????" << endl;
		cout << "1. ??" << endl;

		cout << "2. ??" << endl;
		int flag_qr;
		cin >> flag_qr;
		if (flag_qr == 1)
		{
			int temp = num_eq - 1;
			equipment_bag.erase(equipment_bag.begin()+ temp);
		}
		else
		{
			//??
		}
	}
		
}

void Player::Backpack() const
{
	 if (!equipment_bag.empty()) //? ??
	{
		cout << "???????? " << endl;
	}
	else
	{
		cout << "???????? : " << endl;
		for (int i = 0; i < equipment_bag.size() ; i++)
		{
			cout << i + 1 << '. ' << equipment_bag[i]->get_name();
		}
	}
}

void Player::Eat_orSleep() const
{
	int flag_es;
	cout << endl;
	cout << "1. Eat in canteen" << endl;
	cout << "2. Sleep in dormitory" << endl;
	cin >> flag_es;
	if (flag_es == 1)
	{
		int flag_eat=1; //??????????  ??flag_eat??? 1 ???  
		srand(time(NULL));
		int temp1_Player_Action_Points = rand() % 4 + 2; //??????? 2~5???  
		if (p_m->getId()!=2) //????
		{
			cout << "?????? ??????? " << endl;
		}
		else if (!flag_eat)
		{
			cout << endl;
			cout << "?????  ??????? " << endl;
		}
		else
		{
			cout << endl;
			cout << "???? ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "????  ????? " << temp1_Player_Action_Points << ' ' << endl;
			p->Player_Action_Points += temp1_Player_Action_Points;
			flag_eat = 0;
		}
	}
	else if (flag_es == 2)
	{
		if (p_m->getId() != 1)//????
		{
			cout << endl;
			cout << "??????????" << endl;
		}
		else if (p->Player_Action_Points >= 5)// ???????5 ?????? ????
		{
			cout << endl;
			cout << "?????? ??????~" << endl;
		}
		else
		{
			srand(time(NULL));
			int temp2_Player_Action_Points = rand() % 7 + 10; //????? 10-16???  
			cout << endl;
			cout << "????? ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "????  ????? " << temp2_Player_Action_Points << ' ' << endl;
			p->Player_Action_Points += temp2_Player_Action_Points;
		}
	}

}

void Player::Learn_with_classmates() const
{

}

void Player::Exam_with_teachers() const
{

}

void Player::Explore_items() const
{

}

void Player::Settings() 
{
	cout << endl;
	cout << "????????" << endl;
	cout << endl;
	cout << "1. ????  2. ????  3. ???????  4.???? " << endl;
	cout << endl;
	int flag_set;
	cin >> flag_set;
	if (flag_set == 1)
	{
		mybag.bag_write();
	}
	else if (flag_set == 2)
	{
		cout << "???????? ????????\n1. ????\n2. ????";
			int temp_save;
			cin >> temp_save;
			if (temp_save == 1)
			{
				mybag.bag_write();
				//
			}
			else if (temp_save == 20)
			{
				//
			}
	}
	else if (flag_set == 3)
	{
		mybag.bag_write();
	}
	else if (flag_set == 4)
	{

	}
}


Player you;    //????? you
Bag mybag;


void Menu()
{
	cout << "??????? : " << endl;
	cout << endl;
	cout << "1. ????  2.??  3. ??  4. ????/????  5.??  6. ??/??  7. ?? " << endl;
	cout << endl;
	int opt;
	cin >> opt;
	if (opt == 1)
	{
		cout << "???? : " << endl;
		you.State();
	}
	else if (opt == 2)
	{
		if (!equipment_bag.size()) //????
		{
			cout << "????? ???? " << endl;
		}
		else
		{
			cout << "?????????? : " << endl;
			you.Backpack();
		}
	}
	else if (opt == 3)
	{
		you.get_map()->map_explore(you);
	}
	else if (opt == 4)
	{
		if (you.get_map()->get_npc_id().empty())//?????NPC
		{
			cout << "??????????" << endl;
		}
		else
		{
			cout << "????? : " << endl;
			for (int i = 0; i <you.get_map()->get_npc_id().size(); i++)
			{
				cout << i + 1 << '. ' <<
				//NPC 
			}
		}
	}
	else if (opt == 5)
	{
		cout << endl;
		cout << "???????????? ";
		you.get_map()->show();
	}
	else if (opt == 6)
	{
		you.Eat_orSleep();
	}
	else if (opt == 7)
	{
		showMap();
	}
}
