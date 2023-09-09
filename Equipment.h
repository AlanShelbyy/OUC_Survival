#pragma once
#include<string>
#include<vector>
using namespace std;

//装备的效果
struct Effect {
	int Player_AbilityofLearn;  //学习力 
	int Player_AbilityofProgramming;  //编程能力值 
	int Player_AbilityofMath;  // 数学能力值 
	int Player_AbilityofLogic;  //逻辑能力值 
	int Player_AbilityofPractice;  //实践能力值 
	int Player_Action_Points;  //行动点 
	
};

//装备的状态
struct Type {
	bool on;//是否装上
	bool immediate;//是否是立即使用装备
	
};

//装备的读取
class Equipment {
public:

	Equipment(string fname = "data/Equipment", int n = 1);//初始化
	

	void show();//展示装备的各种属性
	void num_plus() {//装备数量加一
		num++;
	}
	int get_AbilityofLearn() {//返回装备学习力加成
		return equip.Player_AbilityofLearn;
	}
	int get_id() {//返回装备的id码
		return id;
	}
	int get_AbilityofPractice() {//返回装备的实践能力加成
		return equip.Player_AbilityofPractice;
	}
	int get_AbilityofLogic() {//返回装备的逻辑力加成
		return equip.Player_AbilityofLogic;
	}
	int get_AbilityofMath() {//返回装备的数学能力加成
		return equip.Player_AbilityofMath;
	}
	int get_AbilityofProgramming() {//返回装备的编程能力值
		return equip.Player_AbilityofProgramming;
	}
	int get_Action_Points() {//返回装备的行动点加成
		return equip.Player_Action_Points;
	}
	bool get_on() {//返回装备是否被装上
		return status.on;
	}
	bool get_imm() {//返回装备是否被得到即使用
		return status.immediate;
	}
	string get_name(){//返回装备的名字
		return name;
	}
	string get_intro() {//返回装备简介
		return intro;
	}
private:
	int id;//装备id
	string intro;//装备的简介
	string name;//装备的名字
	Effect equip;//装备的效果属性
	int num;//数量
	Type status;//装备状态属性
	vector<string> to_player;//储存装备属性 
};