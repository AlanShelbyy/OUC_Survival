#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<algorithm>
#include"Player.h"
using namespace std;

struct Player
{
	int DateCount; //天数 
	char Major[32];
	int Player_AbilityofLearn;  //学习力 
	int Player_AbilityofProgramming;  //编程能力值 
	int Player_AbilityofMath;  // 数学能力值 
	int Player_AbilityofLogic;  //逻辑能力值 
	int Player_AbilityofPractice;  //实践能力值 
	int Player_Action_Points;  //行动点 
};



Player_Options::Player_Options()  //构造函数 
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
	}
}

void Player_Options::Tasks()
{
	cout << "在10个天数单位内，通过与同学 [交流学习] 和 [探索校园] 提升自己的学习力与各方面能力值" << endl;
	cout << "在有自信的把握下，向教师发起 [考试] 请求，累积到6个学分方可顺利毕业" << endl;
}

void Player_Options::State() const //展示玩家当前状态 
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

void Player_Options::Backpack() const
{
	if () //空 
	{

	}
	else
	{
		cout << "你背包内的物品有 : " << endl;

	}
}

void Player_Options::Eat_orSleep() const
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
		if () //不在食堂
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
		if ()//不在宿舍
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

void Player_Options::Learn_with_classmates() const
{

}

void Player_Options::Exam_with_teachers() const
{

}

void Player_Options::Explore_items() const
{

}

void Player_Options::Settings() 
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
		State();
	}
	else if (opt == 2)
	{
		if () //背包为空
		{
			cout << "你的背包里 空空如也 " << endl;
		}
		else
		{
			cout << "以下是你背包中的物品 : " << endl;
			Backpack();
		}
	}
	else if (opt == 3)
	{
		if () //无物品 
		{
			cout << "这间教室中无物品可拾取 " << endl;
		}
		else
		{
			cout << "以下是可拾取的物品 ：" << endl;
			//物品 
		}
	}
	else if (opt == 4)
	{
		if ()//NPC
		{
			cout << "这间教室貌似无人 " << endl;
		}
		else
		{
			cout << "当前教室有 : " << endl;
			//NPC 
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
		Eat_orSleep();
	}
	else if (opt == 7)
	{
		//地图 
	}
}