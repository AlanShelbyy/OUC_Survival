#pragma once
#include<iostream>
#include<cstring>
using namespace std;


struct Player_Stats
{
	int DateCount=1; //天数 
	char Major[32];
	int Player_AbilityofLearn;  //学习力 
	int Player_AbilityofProgramming;  //编程能力值 
	int Player_AbilityofMath;  // 数学能力值 
	int Player_AbilityofLogic;  //逻辑能力值 
	int Player_AbilityofPractice;  //实践能力值 
	int Player_Action_Points;  //行动点
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
	Player(); //初始化 
	void State() const;  //状态  
	void Backpack() const; //背包
	void Equip_equipments(int num_eq);//装备/卸装备
	void Move() const;  //移动 
	void Explore_items() const;  //探索物品 
	void Eat_orSleep() const; //（仅在食堂）吃饭 
	void Learn_with_classmates() const;  //与同学NPC学习交流 
	void Exam_with_teachers() const;  //与教师NPC考试 
	void Tasks();
	void Settings();  //设置 
	void GetReward(int pro , int mat , int log , int pra , int lnp);

private:
	//ouc_map * p_m;

	struct Player_Stats* p; //指向Player的指针
	int flag_major; //用于开局时玩家挑选专业	
	struct Player_Stats* p_equip;//指向装备
	struct Player_Stats* p_equipment;//  指针数组用来     
};
