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

	Equipment(string fname = "data/Equipment", int n = 1);//��ʼ��
	

	void show();//չʾװ���ĸ�������
	void num_plus() {//װ��������һ
		num++;
	}
	int get_AbilityofLearn() {//����װ��ѧϰ���ӳ�
		return equip.Player_AbilityofLearn;
	}
	int get_id() {//����װ����id��
		return id;
	}
	int get_AbilityofPractice() {//����װ����ʵ�������ӳ�
		return equip.Player_AbilityofPractice;
	}
	int get_AbilityofLogic() {//����װ�����߼����ӳ�
		return equip.Player_AbilityofLogic;
	}
	int get_AbilityofMath() {//����װ������ѧ�����ӳ�
		return equip.Player_AbilityofMath;
	}
	int get_AbilityofProgramming() {//����װ���ı������ֵ
		return equip.Player_AbilityofProgramming;
	}
	int get_Action_Points() {//����װ�����ж���ӳ�
		return equip.Player_Action_Points;
	}
	bool get_on() {//����װ���Ƿ�װ��
		return status.on;
	}
	bool get_imm() {//����װ���Ƿ񱻵õ���ʹ��
		return status.immediate;
	}
	string get_name(){//����װ��������
		return name;
	}
	string get_intro() {//����װ�����
		return intro;
	}
private:
	int id;//װ��id
	string intro;//װ���ļ��
	string name;//װ��������
	Effect equip;//װ����Ч������
	int num;//����
	Type status;//װ��״̬����
	vector<string> to_player;//����װ������ 
};