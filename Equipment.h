#pragma once
#include<string>
#include<vector>
using namespace std;

//װ����Ч��
struct Effect {
	int Player_AbilityofLearn;  //ѧϰ�� 
	int Player_AbilityofProgramming;  //�������ֵ 
	int Player_AbilityofMath;  // ��ѧ����ֵ 
	int Player_AbilityofLogic;  //�߼�����ֵ 
	int Player_AbilityofPractice;  //ʵ������ֵ 
	int Player_Action_Points;  //�ж��� 
};

//װ����״̬
struct Type {
	bool on;//�Ƿ�װ��
	bool immediate;//�Ƿ�������ʹ��װ��
};

//װ���Ķ�ȡ
class Equipment {
public:
	Equipment(string fname);
	void show();
	vector<string> player_equip();
private:
	string intro;//װ���ļ��
	string name;//װ��������
	Effect equip;//װ����Ч������
	int num;//����
	Type status;//װ��״̬����
	vector<string> to_player;//����װ������ 
};