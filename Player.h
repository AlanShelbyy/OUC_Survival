#pragma once
#include<iostream>

using namespace std;

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

private:
	//ouc_map * p_m;

	struct Player_Stats* p; //ָ��Player��ָ��
	int flag_major; //���ڿ���ʱ�����ѡרҵ	
	struct Player_Stats* p_equip;//ָ��װ��
	struct Player_Stats* p_equipment;//  ָ����������     
};