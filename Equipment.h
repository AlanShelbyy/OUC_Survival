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
	Equipment(string fname);
	void show();
	vector<string> player_equip();
private:
	string intro;//装备的简介
	string name;//装备的名字
	Effect equip;//装备的效果属性
	int num;//数量
	Type status;//装备状态属性
	vector<string> to_player;//储存装备属性 
};