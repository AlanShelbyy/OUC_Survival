
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<algorithm>
#include"Player.h"
#include<vector>
#include"Equipment.h"
#include<ctime>
using namespace std;
Player::Player(){//测试用例
	p = (struct Player_Stats*)new struct Player_Stats;
	
}
void Player::GetReward(int pro , int mat , int log , int pra , int lnp){
	p->Player_AbilityofLearn += lnp;
	p->Player_AbilityofLogic += log;
	p->Player_AbilityofMath += mat;
	p->Player_AbilityofPractice =+ pra;
	p->Player_AbilityofProgramming += pro;
}





// Player::Player()  //构造函数 
void Player::ChooseMajor()
{

	cout << endl;
	cout << "欢迎你来到 OUC 信部 ！"; Sleep(400);
	cout << "想好计算机类分流后的专业去向了么？ 有以下四个分流专业供你挑选 : " << endl;
	cout << "1. 计算机科学与技术" << endl;
	cout << "2. 智能科学与技术" << endl;
	cout << "3. 网络空间安全" << endl;
	cout << "4. 软件工程" << endl;
	cout << endl;
	cout << "请选择一个适合你的分流专业 : " << endl;
	cin >> flag_major;
	if (flag_major == 1)
	{
		cout << "你已成为 [计算机科学与技术] 专业的学生  " << endl;
		Sleep(300);
		cout << "快去探索校园 不断交流学习 提高自身能力 争取顺利毕业吧 " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[计算机科学与技术]");
	}
	else if (flag_major == 2)
	{
		cout << "你已成为 [智能科学与技术] 专业的学生  " << endl;
		Sleep(300);
		cout << "快去探索校园 不断交流学习 提高自身能力 争取顺利毕业吧 " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 4;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[智能科学与技术]");
	}
	else if (flag_major == 3)
	{
		cout << "你已成为 [网络空间安全] 专业的学生  " << endl;
		Sleep(300);
		cout << "快去探索校园 不断交流学习 提高自身能力 争取顺利毕业吧 " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 2;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 3;
		p->Player_AbilityofPractice = 3;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[网络空间安全]");
	}
	else if (flag_major == 4)
	{
		cout << "你已成为 [软件工程] 专业的学生  " << endl;
		Sleep(300);
		cout << "快去探索校园 不断交流学习 提高自身能力 争取顺利毕业吧 " << endl;
		p->Player_AbilityofLearn = 1;
		p->Player_AbilityofProgramming = 4;
		p->Player_AbilityofMath = 2;
		p->Player_AbilityofLogic = 2;
		p->Player_AbilityofPractice = 2;
		p->Player_Action_Points = 10;
		strcpy(p->Major ,"[软件工程]");
	}
	
}

void Player::Tasks()
{
	cout << "在10个天数单位内，通过与同学 [交流学习] 和 [探索校园] 提升自己的学习力与各方面能力值" << endl;
	cout << "在有自信的把握下，向教师发起 [考试] 请求，累积到6个学分方可顺利毕业" << endl;
}

void Player::State() const //展示玩家当前状态 
{
	cout << endl;
	cout << "你的专业 [" << p->Major << ']' << endl;
	cout << "学习力 : " << p->Player_AbilityofLearn << endl;
	cout << "行动点 : " << p->Player_Action_Points << endl;
	cout << "编程能力值 : " << p->Player_AbilityofProgramming << endl;
	cout << "数学能力值 : " << p->Player_AbilityofMath << endl;
	cout << "逻辑能力值 : " << p->Player_AbilityofLogic << endl;
	cout << "实践能力值 : " << p->Player_AbilityofPractice << endl;
	cout << "在校已学习天数 : " << p->DateCount << endl;
}
int Player::Getter_learn(){
	return p->Player_AbilityofLearn;
}

void Player::be_attack(int damage){
	p->Player_AbilityofLearn -= damage ;
}

void Player::Equip_equipments(int num_eq)
{
	Equipment player_equ;
	cout << endl;
	//cout << " 对于 [" << equipment_bag[num_eq-1] << "] 你打算 :" << endl;
	cout << "1. 使用该物品" << endl;
	cout << "2. 查看该物品属性" << endl;
	cout << "3. 卸下该装备" << endl;
	cout << "4. 丢弃该物品 " << endl;
	int flag_eq;
	cin >> flag_eq;
	if (flag_eq == 1)
	{
		cout << "装备该物品后你的状态 : " << endl;
		//this->p->Player_AbilityofLearn+= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //学习力 
		// this->p->Player_AbilityofProgramming += equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //编程能力值 
		// this->p->Player_AbilityofMath += equipment_bag[num_eq - 1]->get_AbilityofMath(); // 数学能力值 
		// this->p->Player_AbilityofLogic += equipment_bag[num_eq - 1]->get_AbilityofLogic();  //逻辑能力值 
		// this->p->Player_AbilityofPractice += equipment_bag[num_eq - 1]->get_AbilityofPractice();  //实践能力值 
		//equipment_bag[num_eq - 1]->show();
	}
	// else if (flag_eq == 2)
	// {
	// 	equipment_bag[num_eq-1]->show();
	// }
	// else if (flag_eq == 3)
	// {
	// 	if (!equipment_bag[num_eq - 1]->get_on()) //还未使用
	// 	{
	// 		cout << "该物品仍未使用 无法卸下" << endl;
	// 	}
	// 	else
	// 	{
	// 		this->p->Player_AbilityofLearn -= equipment_bag[num_eq - 1]->get_AbilityofLearn();  //学习力 
	// 		this->p->Player_AbilityofProgramming -= equipment_bag[num_eq - 1]->get_AbilityofProgramming();  //编程能力值 
	// 		this->p->Player_AbilityofMath -= equipment_bag[num_eq - 1]->get_AbilityofMath(); // 数学能力值 
	// 		this->p->Player_AbilityofLogic -= equipment_bag[num_eq - 1]->get_AbilityofLogic();  //逻辑能力值 
	// 		this->p->Player_AbilityofPractice -= equipment_bag[num_eq - 1]->get_AbilityofPractice();  //实践能力值 
	// 		equipment_bag[num_eq - 1]->show();
	// 	}
	// }
	// else if (flag_eq == 4)
	// {
	// 	cout << "确认丢弃该物品?" << endl;
	// 	cout << "1. 丢弃" << endl;
	// 	cout << "2. 取消" << endl;
	// 	int flag_qr;
	// 	cin >> flag_qr;
	// 	if (flag_qr == 1)
	// 	{
			
	// 	}
	// 	else
	// 	{
	// 		//返回
	// 	}
	// }
		
}

void Player::Backpack() const
{
	//  if (!equipment_bag.empty()) //空 
	// {
	// 	cout << "你的背包空空如也 " << endl;
	// }
	// else
	// {
	// 	cout << "你背包内的物品有 : " << endl;
	// 	for (int i = 0; i < equipment_bag.size() ; i++)
	// 	{
	// 		cout << i + 1 <<'.' << equipment_bag[i]->get_name();
	// 	}
	// }
}

void Player::Eat_orSleep() const
{
	int flag_es;
	cout << endl;
	cout << "1. Eat in canteen" << endl;
	cout << "2. Sleep in dormitory" << endl;
	if (flag_es == 1)
	{
		int flag_eat; //一天仅仅可以用餐一次  转天flag_eat标注为 1 可用餐  
		srand(time(NULL));
		int temp1_Player_Action_Points = rand() % 4 + 2; //吃一次饭随机加 2~5行动点  
		if (false) //不在食堂
		{
			cout << "此处不可用餐 仅可在食堂用餐 " << endl;
		}
		else if (!flag_eat)
		{
			cout << endl;
			cout << "食堂关门啦  请转天再来光顾 " << endl;
		}
		else
		{
			cout << endl;
			cout << "正在用餐 ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "用餐结束  获得行动点 " << temp1_Player_Action_Points << ' ' << endl;
			p->Player_Action_Points += temp1_Player_Action_Points;
			flag_eat = 0;
		}
	}
	else if (flag_es == 2)
	{
		if (false)//不在宿舍
		{
			cout << endl;
			cout << "仅允许在宿舍睡大觉哦" << endl;
		}
		else if (p->Player_Action_Points >= 5)// 体力点大于等于5 防止摆烂玩家 不可睡觉
		{
			cout << endl;
			cout << "你的精力充沛 不妨多去走走~" << endl;
		}
		else
		{
			srand(time(NULL));
			int temp2_Player_Action_Points = rand() % 7 + 10; //睡觉随机加 10-16行动点  
			cout << endl;
			cout << "呼呼大睡中 ";
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(400);
			}
			cout << endl;
			cout << "睡眠结束  获得行动点 " << temp2_Player_Action_Points << ' ' << endl;
			p->Player_Action_Points += temp2_Player_Action_Points;
		}
	}

}

void Player::Learn_with_classmates() const
{

}

void Player::Exam_with_teachers() const//
{

}

void Player::Explore_items() const
{

}

void Player::Settings() 
{
	cout << endl;
	cout << "进入游戏系统菜单" << endl;
	cout << endl;
	cout << "1. 存储进度  2. 返回标题  3. 保存并退出游戏  4.继续游戏 " << endl;
	cout << endl;
	int flag_set;
	cin >> flag_set;
	if (flag_set == 1)
	{

	}
	else if (flag_set == 2)
	{

	}
	else if (flag_set == 3)
	{

	}
	else if (flag_set == 4)
	{

	}
}
Player you;    //实例化一个 you
void Menu()
{
	cout << "你要打算做什么 : " << endl;
	cout << endl;
	cout << "1. 查看状态  2.背包  3. 探索  4. 学习交流/申请考试  5.移动  6. 吃饭/睡觉  7. 地图 " << endl;
	cout << endl;
	int opt;
	cin >> opt;
	if (opt == 1)
	{
		cout << "你的状态 : " << endl;
		you.State();
	}
	else if (opt == 2)
	{
		if (false) //背包为空
		{
			cout << "你的背包里 空空如也 " << endl;
		}
		else
		{
			cout << "以下是你背包中的物品 : " << endl;
			you.Backpack();
		}
	}
	else if (opt == 3)
	{
		if (false) //无物品 
		{
			cout << "这间教室中无物品可拾取 " << endl;
		}
		else
		{
			cout << "以下是可拾取的物品 ：" << endl;
			/*for (int i = 0; i< ;i++)
		{
			cout<<i+1<<'. '<<

	*/
			//物品 
		}
	}
	else if (opt == 4)
	{
		if (false)//NPC
		{
			cout << "这间教室貌似空无一人" << endl;
		}
		else
		{
			cout << "当前教室有 : " << endl;
			/*for (int i = 0; i <; i++)
			{
				cout << i + 1 << '. ' <<
				//NPC 
			}*/
		}
	}
	else if (opt == 5)
	{
		cout << endl;
		cout << "你当前所在地为 ["; //地点 
			//地图 
	}
	else if (opt == 6)
	{
		you.Eat_orSleep();
	}
	else if (opt == 7)
	{
		//地图 
	}
} 
