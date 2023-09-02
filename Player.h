#pragma once
#include<iostream>
#include<cstring>
using namespace std;


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
	Player_Stats(){ 
		DateCount = 0;
		strcpy(Major,"nothing");
		Player_AbilityofLearn =0;
		Player_AbilityofLogic = 0;
		Player_AbilityofMath = 0;
		Player_AbilityofPractice = 0;
		Player_AbilityofProgramming  = 0;
		Player_Action_Points = 0;
		Player_Action_Points = 10;
	} 
};


class Player
{
public:
	Player(); //��ʼ�� 
	void State() const;  //״̬  
	void Backpack() const; //����
	void Equip_equipments(int num_eq);//װ��/жװ��
	void Move() const;  //�ƶ� 
	void Explore_items() const;  //̽����Ʒ 
	void Eat_orSleep() const; //������ʳ�ã��Է� 
	void Learn_with_classmates() const;  //��ͬѧNPCѧϰ���� 
	void Exam_with_teachers() const;  //���ʦNPC���� 
	void Tasks();
	void Settings();  //���� 
	void GetReward(int pro , int mat , int log , int pra , int lnp);

private:
	//ouc_map * p_m;

	struct Player_Stats* p; //ָ��Player��ָ��
	int flag_major; //���ڿ���ʱ�����ѡרҵ	
	struct Player_Stats* p_equip;//ָ��װ��
	struct Player_Stats* p_equipment;//  ָ����������     
};
