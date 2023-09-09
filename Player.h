#pragma once
#pragma warning( disable : 4996)
#include<iostream>
#include"map.h"
#include<cstring>
using namespace std;
class ouc_map;

struct Player_Stats
{
	int DateCount = 1; //���� 
	char Major[32];
	int Warning;
	int Player_AbilityofLearn;  //ѧϰ�� 
	int Player_AbilityofProgramming;  //�������ֵ 
	int Player_AbilityofMath;  // ��ѧ����ֵ 
	int Player_AbilityofLogic;  //�߼�����ֵ 
	int Player_AbilityofPractice;  //ʵ������ֵ 
	int Player_Action_Points;  //�ж���
		Player_Stats() {
		DateCount = 0;
		strcpy(Major, "nothing");
		Player_AbilityofLearn = 0;
		Player_AbilityofLogic = 0;
		Player_AbilityofMath = 0;
		Player_AbilityofPractice = 0;
		Player_AbilityofProgramming = 0;
		Player_Action_Points = 0;
		Player_Action_Points = 10;
		Warning = 0;
	}
};



class Player
{
public:
	Player(); //��ʼ�� 
	void ChooseMajor();
	void State() const;  //״̬  
	void Backpack() const; //����
	void Equip_equipments(int num_eq);//װ��/жװ��

	void Explore_items() const;  //̽����Ʒ 
	void Eat_orSleep() const; //������ʳ�ã��Է� 
	void Learn_with_classmates() const;  //��ͬѧNPCѧϰ���� 
	void Exam_with_teachers() const;  //���ʦNPC���� 
	void Tasks();
	void Settings();  //����
	void be_attack(int damage);//����ܹ���
	int  Getter_learn();
	void GetReward(int pro, int mat, int log, int pra, int lnp);
	void changep_m(int num);
	short getMap_id();
	ouc_map* get_map();

private:
	ouc_map* p_m;

	struct Player_Stats* p; //ָ��Player��ָ��
	int flag_major; //���ڿ���ʱ�����ѡרҵ	
	struct Player_Stats* p_equip;//ָ��װ��
	struct Player_Stats* p_equipment;//  ָ����������     

};

void move(Player& you);

void map_explore(Player& you);