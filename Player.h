#pragma once
#include<iostream>

using namespace std;

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

private:
	//ouc_map * p_m;

	struct Player_Stats* p; //指向Player的指针
	int flag_major; //用于开局时玩家挑选专业	
	struct Player_Stats* p_equip;//指向装备
	struct Player_Stats* p_equipment;//  指针数组用来     
};
