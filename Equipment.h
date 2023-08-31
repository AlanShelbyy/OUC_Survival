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
	Equipment(string fname = "data/Equipment", int n = 1);
	void show();
	int get_AbilityofLearn() {
		return equip.Player_AbilityofLearn;
	}
	int get_AbilityofPractice() {
		return equip.Player_AbilityofPractice;
	}
	int get_AbilityofLogic() {
		return equip.Player_AbilityofLogic;
	}
	int get_AbilityofMath() {
		return equip.Player_AbilityofMath;
	}
	int get_AbilityofProgramming() {
		return equip.Player_AbilityofProgramming;
	}
	int get_Action_Points() {
		return equip.Player_Action_Points;
	}
	bool get_on() {
		return status.on;
	}
	bool get_imm() {
		return status.immediate;
	}
	string get_name()
	{
		return name;
	}
private:
	string intro;//װ���ļ��
	string name;//װ��������
	Effect equip;//װ����Ч������
	int num;//����
	Type status;//װ��״̬����
	vector<string> to_player;//����װ������ 
};

static vector<Equipment*> equipment_bag;