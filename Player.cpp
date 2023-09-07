
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
	int DateCount=1; //���� 
	char Major[32];
	int Player_AbilityofLearn;  //ѧϰ�� 
	int Player_AbilityofProgramming;  //�������ֵ 
	int Player_AbilityofMath;  // ��ѧ����ֵ 
	int Player_AbilityofLogic;  //�߼�����ֵ 
	int Player_AbilityofPractice;  //ʵ������ֵ 
	int Player_Action_Points;  //�ж��� 
};

void Player::changep_m(int num) {
	p_m = &Ouc_map[num];
};//�ƶ�λ��
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
	cout << "�밴���������...";
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
		cout << "�޷����ļ�" << endl;
	}
}
Player::Player(){//��������
	p = (struct Player_Stats*)new struct Player_Stats;
	
}
void Player::GetReward(int pro , int mat , int log , int pra , int lnp){
	p->Player_AbilityofLearn += lnp;
	p->Player_AbilityofLogic += log;
	p->Player_AbilityofMath += mat;
	p->Player_AbilityofPractice =+ pra;
	p->Player_AbilityofProgramming += pro;
}


// Player::Player()  //���캯�� 
// {
// 	cout << endl;
// 	cout << "��ӭ������ OUC �Ų� ��"; Sleep(400);
// 	cout << "��ü������������רҵȥ����ô�� �������ĸ�����רҵ������ѡ : " << endl;
// 	cout << "1. �������ѧ�뼼��" << endl;
// 	cout << "2. ���ܿ�ѧ�뼼��" << endl;
// 	cout << "3. ����ռ䰲ȫ" << endl;
// 	cout << "4. �������" << endl;
// 	cout << endl;
// 	cout << "��ѡ��һ���ʺ���ķ���רҵ : " << endl;
// 	cin >> flag_major;
// 	if (flag_major == 1)
// 	{
// 		cout << "���ѳ�Ϊ [�������ѧ�뼼��] רҵ��ѧ��  " << endl;
// 		Sleep(300);
// 		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 4;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 2;
// 		p->Player_AbilityofPractice = 2;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 2)
// 	{
// 		cout << "���ѳ�Ϊ [���ܿ�ѧ�뼼��] רҵ��ѧ��  " << endl;
// 		Sleep(300);
// 		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 2;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 4;
// 		p->Player_AbilityofPractice = 2;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 3)
// 	{
// 		cout << "���ѳ�Ϊ [����ռ䰲ȫ] רҵ��ѧ��  " << endl;
// 		Sleep(300);
// 		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
// 		p->Player_AbilityofLearn = 1;
// 		p->Player_AbilityofProgramming = 2;
// 		p->Player_AbilityofMath = 2;
// 		p->Player_AbilityofLogic = 3;
// 		p->Player_AbilityofPractice = 3;
// 		p->Player_Action_Points = 10;
// 	}
// 	else if (flag_major == 4)
// 	{
// 		cout << "���ѳ�Ϊ [�������] רҵ��ѧ��  " << endl;
// 		Sleep(300);
// 		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
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
	cout << "��ӭ������ OUC �Ų� ��"; Sleep(400);
	cout << "��ü������������רҵȥ����ô�� �������ĸ�����רҵ������ѡ : " << endl;
	cout << "1. �������ѧ�뼼��" << endl;
	cout << "2. ���ܿ�ѧ�뼼��" << endl;
	cout << "3. ����ռ䰲ȫ" << endl;
	cout << "4. �������" << endl;
	cout << endl;
	cout << "��ѡ��һ���ʺ���ķ���רҵ : " << endl;
	cin >> flag_major;
	if (flag_major == 1)
	{
		cout << "���ѳ�Ϊ [�������ѧ�뼼��] רҵ��ѧ��  " << endl;
		Sleep(300);
		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[�������ѧ�뼼��]");
	}
	else if (flag_major == 2)
	{
		cout << "���ѳ�Ϊ [���ܿ�ѧ�뼼��] רҵ��ѧ��  " << endl;
		Sleep(300);
		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 4;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[���ܿ�ѧ�뼼��]");
	}
	else if (flag_major == 3)
	{
		cout << "���ѳ�Ϊ [����ռ䰲ȫ] רҵ��ѧ��  " << endl;
		Sleep(300);
		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 3;
		p->Player_AbilityofPractice = 3;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[����ռ䰲ȫ]");
	}
	else if (flag_major == 4)
	{
		cout << "���ѳ�Ϊ [�������] רҵ��ѧ��  " << endl;
		Sleep(300);
		cout << "��ȥ̽��У԰ ���Ͻ���ѧϰ ����������� ��ȡ˳����ҵ�� " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[�������]");
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
	cout << "��10��������λ�ڣ�ͨ����ͬѧ [����ѧϰ] �� [̽��У԰] �����Լ���ѧϰ�������������ֵ" << endl;
	cout << "�������ŵİ����£����ʦ���� [����] �����ۻ���6��ѧ�ַ���˳����ҵ" << endl;
}

void Player::State() const //չʾ��ҵ�ǰ״̬ 
{
	cout << endl;
	cout << "���רҵ [" << p->Major << ']' << endl;
	cout << "ѧϰ�� : " << p->Player_AbilityofLearn << endl;
	cout << "�ж��� : " << p->Player_Action_Points << endl;
	cout << "�������ֵ : " << p->Player_AbilityofProgramming << endl;
	cout << "��ѧ����ֵ : " << p->Player_AbilityofMath << endl;
	cout << "�߼�����ֵ : " << p->Player_AbilityofLogic << endl;
	cout << "ʵ������ֵ : " << p->Player_AbilityofPractice << endl;
	cout << "��У��ѧϰ���� : " << p->DateCount << endl;
}

void Player::Equip_equipments(int num_eq)
{
	Equipment player_equ;
	cout << endl;
	cout << " ���� [" << equipment_bag[num_eq-1] << "] ����� :" << endl;
	cout << "1. ʹ�ø���Ʒ" << endl;
	cout << "2. �鿴����Ʒ����" << endl;
	cout << "3. ж�¸�װ��" << endl;
	cout << "4. ��������Ʒ " << endl;
	int flag_eq;
	cin >> flag_eq;
	if (flag_eq == 1)
	{
		cout << "װ������Ʒ�����״̬ : " << endl;
		p->Player_AbilityofLearn+= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //ѧϰ�� 
		this->p->Player_AbilityofProgramming += equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //�������ֵ 
		this->p->Player_AbilityofMath += equipment_bag[num_eq - 1]->get_AbilityofMath(); // ��ѧ����ֵ 
		this->p->Player_AbilityofLogic += equipment_bag[num_eq - 1]->get_AbilityofLogic();  //�߼�����ֵ 
		this->p->Player_AbilityofPractice += equipment_bag[num_eq - 1]->get_AbilityofPractice();  //ʵ������ֵ 
		equipment_bag[num_eq - 1]->show();
	}
	else if (flag_eq == 2)
	{
		equipment_bag[num_eq-1]->show();
	}
	else if (flag_eq == 3)
	{
		if (!equipment_bag[num_eq - 1]->get_on()) //��δʹ��
		{
			cout << "����Ʒ��δʹ�� �޷�ж��" << endl;
		}
		else
		{
			this->p->Player_AbilityofLearn -= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //ѧϰ�� 
			this->p->Player_AbilityofProgramming -= equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //�������ֵ 
			this->p->Player_AbilityofMath -= equipment_bag[num_eq - 1]->get_AbilityofMath(); // ��ѧ����ֵ 
			this->p->Player_AbilityofLogic -= equipment_bag[num_eq - 1]->get_AbilityofLogic();  //�߼�����ֵ 
			this->p->Player_AbilityofPractice -= equipment_bag[num_eq - 1]->get_AbilityofPractice();  //ʵ������ֵ 
			equipment_bag[num_eq - 1]->show();
		}
	}
	else if (flag_eq == 4)
	{
		cout << "ȷ�϶�������Ʒ?" << endl;
		cout << "1. ����" << endl;

		cout << "2. ȡ��" << endl;
		int flag_qr;
		cin >> flag_qr;
		if (flag_qr == 1)
		{
			int temp = num_eq - 1;
			equipment_bag.erase(equipment_bag.begin()+ temp);
		}
		else
		{
			//����
		}
	}
		
}

void Player::Backpack() const
{
	 if (!equipment_bag.empty()) //�� ����
	{
		cout << "��ı����տ���Ҳ " << endl;
	}
	else
	{
		cout << "�㱳���ڵ���Ʒ�� : " << endl;
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
		int flag_eat=1; //һ����������ò�һ��  ת��flag_eat��עΪ 1 ���ò�  
		srand(time(NULL));
		int temp1_Player_Action_Points = rand() % 4 + 2; //��һ�η������ 2~5�ж���  
		if (p_m->getId()!=2) //����ʳ��
		{
			cout << "�˴������ò� ������ʳ���ò� " << endl;
		}
		else if (!flag_eat)
		{
			cout << endl;
			cout << "ʳ�ù�����  ��ת��������� " << endl;
		}
		else
		{
			cout << endl;
			cout << "�����ò� ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "�òͽ���  ����ж��� " << temp1_Player_Action_Points << ' ' << endl;
			p->Player_Action_Points += temp1_Player_Action_Points;
			flag_eat = 0;
		}
	}
	else if (flag_es == 2)
	{
		if (p_m->getId() != 1)//��������
		{
			cout << endl;
			cout << "������������˯���Ŷ" << endl;
		}
		else if (p->Player_Action_Points >= 5)// ��������ڵ���5 ��ֹ������� ����˯��
		{
			cout << endl;
			cout << "��ľ������� ������ȥ����~" << endl;
		}
		else
		{
			srand(time(NULL));
			int temp2_Player_Action_Points = rand() % 7 + 10; //˯������� 10-16�ж���  
			cout << endl;
			cout << "������˯�� ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "˯�߽���  ����ж��� " << temp2_Player_Action_Points << ' ' << endl;
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
	cout << "������Ϸϵͳ�˵�" << endl;
	cout << endl;
	cout << "1. �洢����  2. ���ر���  3. ���沢�˳���Ϸ  4.������Ϸ " << endl;
	cout << endl;
	int flag_set;
	cin >> flag_set;
	if (flag_set == 1)
	{
		mybag.bag_write();
	}
	else if (flag_set == 2)
	{
		cout << "��ѡ�񷵻ر���ǰ �Ƿ�Ҫ�洢���ȣ�\n1. �洢����\n2. ������ȥ";
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


Player you;    //ʵ����һ�� you
Bag mybag;


void Menu()
{
	cout << "��Ҫ������ʲô : " << endl;
	cout << endl;
	cout << "1. �鿴״̬  2.����  3. ̽��  4. ѧϰ����/���뿼��  5.�ƶ�  6. �Է�/˯��  7. ��ͼ " << endl;
	cout << endl;
	int opt;
	cin >> opt;
	if (opt == 1)
	{
		cout << "���״̬ : " << endl;
		you.State();
	}
	else if (opt == 2)
	{
		if (!equipment_bag.size()) //����Ϊ��
		{
			cout << "��ı����� �տ���Ҳ " << endl;
		}
		else
		{
			cout << "�������㱳���е���Ʒ : " << endl;
			you.Backpack();
		}
	}
	else if (opt == 3)
	{
		map_explore(you);
	}
	else if (opt == 4)
	{
		if (you.get_map()->getNpc_id().empty())//�÷���û��NPC
		{
			cout << "������ò�ƿ���һ��" << endl;
		}
		else
		{
			cout << "��ǰ������ : " << endl;
			for (int i = 0; i <you.get_map()->getNpc_id().size(); i++)
			{
				cout << i + 1 << '. ' ;//npc������
				//NPC 
			}
		}
	}
	else if (opt == 5)
	{
		cout << endl;
		cout << "�㵱ǰ���ڵر�ż�����Ϊ ";
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
