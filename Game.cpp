
#include"Game.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Equipment.h"
#include"map.h"
#include"Bag.h"
#include"fight_part.h"
#include<windows.h>
#include<conio.h>
using namespace std;

enum {
    start_menu,
    adv,
    fighstu,
    fightea,
    rest,
    bag,
    store
    } gamestate;

extern vector<Equipment*> equipment_bag;
extern ouc_map Ouc_map[19];



void showMap();
void showInColor(char str[],int color,HANDLE console);
int GetInput();
int GetInput(int,int);
MUDGame::MUDGame(){
    _Run = true;
}

void MUDGame::LoadNpc(){
    fstream infile;
    npc tmp;
    infile.open("date\\npc.dat",ios::in);
    if(!infile){
        cout<<"打开失败"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.Name;
        infile>>tmp.Description;

        infile>>tmp.GiveMat;//cout<<tmp.GiveMat;
        infile>>tmp.GiveLog;//cout<<tmp.GiveLog;
        infile>>tmp.GiveProg;//cout<<tmp.GiveProg;
        infile>>tmp.GivePrac;//cout<<tmp.GivePrac;
        infile>>tmp.GiveLearnPinit;//cout<<tmp.GiveLearnPinit;
        infile>>tmp.hardlvl;
        //cout<<"##"<<endl;
        NPCs.push_back(tmp);
    }
    return;
}

void MUDGame::LoadSkill(){
    fstream infile;
    Skill tmp;
    string argus;
    infile.open("date\\normskill.dat",ios::in);
    if(!infile){
        cout<<"打开失败"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.name;
        infile>>tmp.description;
        infile>>tmp.choices;
        infile>>tmp.answer;
        infile>>tmp.hardlvl;
        skills.push_back(tmp);
    }
    return;
}

void MUDGame::LoadBoss(){
    fstream infile;
    npc tmp;
    infile.open("date\\boss.dat",ios::in);
    if(!infile){
        cout<<"打开失败"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.Name;
        infile>>tmp.Description;
        infile>>tmp.GiveMat;
        infile>>tmp.GiveLog;
        infile>>tmp.GiveProg;
        infile>>tmp.GivePrac;
        infile>>tmp.GiveLearnPinit;
        infile>>tmp.hardlvl;
        Boss.push_back(tmp);
    }
    return;
}
void MUDGame::LoadBossSkill(){
    fstream infile;
    Skill tmp;
    string argus;
    infile.open("date\\bossskill.dat",ios::in);
    if(!infile){
        cout<<"打开失败"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.name;
        infile>>tmp.description;
        infile>>tmp.choices;
        infile>>tmp.answer;
        infile>>tmp.hardlvl;
        bossSkills.push_back(tmp);
    }
    return;
}
//将地图文件加载入Ouc_map数组里
void MUDGame::LoadMap() {
    for (int i = 0; i < 19; i++) {
        ouc_map map(i + 1);
        Ouc_map[i] = map;
    }
}
void MUDGame::ShowNpcList(){
    for(int i = 0; i<NPCs.size();i++){
        cout<<NPCs[i].Name<<endl;
        cout<<NPCs[i].Description<<endl;
        cout<<NPCs[i].GiveLearnPinit<<endl;
        cout<<NPCs[i].GiveLog<<endl;
        cout<<NPCs[i].GiveMat<<endl;
        cout<<NPCs[i].GivePrac<<endl;
        cout<<NPCs[i].GiveProg<<endl;
    }

} 


void MUDGame::ShowSkillList(){
    for(int i = 0;i < skills.size();i++){
        cout<<"打印中";
        cout<<skills[i].name<<endl;
        cout<<skills[i].description<<endl;
        cout<<skills[i].choices<<endl;
        cout<<skills[i].answer<<endl;
        cout<<skills[i].hardlvl<<endl;
    }
    return;


}
// void MUDGame::GetMapNpc(){
//     vector<int> npcs = player.get_map()->getNpc_id();
//     for(int i =0;i < npcs.size();i++){
//         npcindex.push_back(npcs[i]);
//     }
// }
void MUDGame::RunGame(){
    LoadLogo();
    LoadSkill();
    //ShowSkillList();
    LoadBoss();
    LoadBossSkill();
    LoadNpc();
    LoadMap();
    //ShowNpcList();
    //cout<<"load end"<<endl;
    Bag bagsaver;
    thewindow = GetStdHandle( STD_OUTPUT_HANDLE );
    int choice=0;
    int operate;
    
    gamestate = start_menu;
    while(RunOrNot()){
        system("cls");
        
        switch(gamestate){ 
            case start_menu:cout<<"开始界面"<<endl;//各种游戏状态
                            
                            ShowLogo();
                            cout<<endl;
                            cout<<"一名坚毅的海大学生"<<endl;
                            cout<<"1. 新的开始 2. 继续学业 3.退出游戏"<<endl;
                            operate = GetInput(1,3);
                            if(operate == 1){
                                system("cls");
                                player.ChooseMajor();
                                player.State();
                                system("pause>nul");
                                
                                //cout<<"虚假的选专业"<<endl;
                                gamestate = adv;
                            }
                            else if(operate == 2){
                                cout<<"背包存档"<<endl;
                                bagsaver.bag_read();
                                gamestate = adv;
                                break;
                            }
                            else if(operate == 3){
                                
                                break;
                            }
                            
                            //thisgame.ToffGame();
                            break;
            case adv:   {cout<<"冒险中"<<endl;
                            player.get_map()->show();//展示地图信息,最好有地图介绍
                            //展示所有npc，带颜色
                            for(int i = 0; i<player.get_map()->getNpc_id().size(); i++){
                                //cout<<player.get_map()->getNpc_id()[i];
                                showInColor(NPCs[player.get_map()->getNpc_id()[i]].Name,1,thewindow);
                                cout<<endl;
                            }
                            //
                            
                            cout << "你要打算做什么 : " << endl;
                            cout << endl;
                            cout << "1. 查看状态  2.背包  3. 探索  4. 学习交流/申请考试  5.移动  6. 吃饭/睡觉  7. 地图 8.系统" << endl;
                            cout << endl;
                            int opt;
                            opt =GetInput(1,8);
                            if (opt == 1)
                            {
                                cout << "你的状态 : " << endl;
                                player.State();
                                system("pause>nul");
                                break;
                            }
                            else if (opt == 2)
                            {
                                if (!equipment_bag.size()) //背包为空
                                {
                                    cout << "你的背包里 空空如也 " << endl;
                                }
                                else
                                {
                                    cout << "以下是你背包中的物品 : " << endl;
                                    player.Backpack();
                                }
                                system("pause>nul");
                                break;
                                
                            }
                            else if (opt == 3)
                            {
                                map_explore(player);//探索地图
                                system("pause>nul");
                                break;

                            }
                            else if (opt == 4)
                            {
                                //cout<<"去别的地方看看吧"<<endl;
                                cout<<"测试中"<<endl;
                                if (player.get_map()->getNpc_id().empty())//该房间没有NPC
                                {
                                    cout << "这间教室貌似空无一人" << endl;
                                }
                                else
                                {
                                    //判断是否有老师
                                   if(player.getMap_id()==6||player.getMap_id()==9||player.getMap_id()==17)
                                   {
                                    
                                    cout<<"1. "<<Boss[player.get_map()->getBoss_id()[0]].Name<<endl;
                                    
                                    for(int i = 0 ;i<player.get_map()->getNpc_id().size();i++)
                                    {
                                        cout<<i+2<<". "<<NPCs[player.get_map()->getNpc_id()[i]].Name<<endl;
                                    }

                                    int choice;
                                    choice = GetInput(1,player.get_map()->getNpc_id().size()+1);
                                    
                                    
                                    if(choice!=1){ //学生
                                        cout<<"你现在学术交流/考试的对象是 "<<NPCs[player.get_map()->getNpc_id()[choice-1]].Name<<endl;
                                        npcchoice = player.get_map()->getNpc_id()[choice-1];
                                        gamestate=fighstu;
                                    }
                                    
                                    else {
                                        cout<<"你现在进行考试的对象是 "<<Boss[player.get_map()->getBoss_id()[0]].Name<<endl;
                                    }
                                   }//没有老师的话
                                   else{
                                    //依次打印名字
                                    cout<<"选择与谁交流"<<endl;
                                    for(int dz=0;dz<player.get_map()->getNpc_id().size();dz++)
                                    {
                                        cout<<dz+1<<' '<<NPCs[player.get_map()->getNpc_id()[dz]].Name;
                                    }
                                    //选择npc
                                    cout<<endl;
                                    int temp_dz2;
                                    temp_dz2 =GetInput(1,player.get_map()->getNpc_id().size());
                                    
                                    cout<<"你现在学术交流的对象是 "<<NPCs[player.get_map()->getNpc_id()[temp_dz2-1]].Name;
                                    npcchoice = player.get_map()->getNpc_id()[temp_dz2-1];
                                    gamestate = fighstu;
                                   }
                                }
                                
                                
                            }
                            else if (opt == 5)
                            {
                                // cout << endl;
                                // cout << "你当前所在地编号及名称为 ";
                                // player.get_map()->show();
                               // cout<<"你可以去的地方:"<<endl;
                                //打印
                                //选择
                                //移动
                                move(player);
                            }
                            else if (opt == 6)
                            {
                                player.Eat_orSleep();
                            }
                            else if (opt == 7)
                            {
                                showMap();
                                system("pause>nul");
                            }
                            else if(opt==8){
                                system("cls");
                                ShowLogo();
                                cout<<endl;
                                cout<<"1. 继续游戏 2. 保存进度 3. 退出游戏"<<endl;
                                int localOpt = 0;

                                //输入加检查
                                localOpt=GetInput(1,3);
                                switch(localOpt){
                                    case 1:
                                    case 2://背包
                                            bagsaver.bag_write();

                                    case 3:ToffGame();break;
                                    default: break;
                                }
                                cout<<"施工中"<<endl;

                            }         
                            break;
                        }
            case fighstu:   {
                            cout<<"交流回合"<<endl;
                            // system("pause");
                            
                            int skillindex =NPCs[npcchoice].Useskill(skills);
                            choice = GetInput(1,4);
                            if(NPCs[npcchoice].Check(skillindex,choice,skills)){
                               // NPCs[npcchoice].Debug_show();
                                NPCs[npcchoice].GivePoint(player);
                                cout<<"你英明神武的做出了完美的回答"<<endl;
                            }
                            else{
                                cout<<"回答错误"<<endl;
                            }


                            cout<<"接下来 1. 去冒险 2.继续交流"<<endl;
                            operate = GetInput(1,2);
                            if(operate == 1){
                                gamestate = adv;
                            }
                            break;}
            case fightea:  { 

                            cout<<"考试回合";
                            //system("pause");
                            //BOSS打印技能
                            int bossskill = Boss[bossindex].Useskill(bossSkills);
                            //玩家使用技能
                            
                            cout<<"选择行动"<<endl<<"1.普通攻击hello world 2.使用物品"<<endl;
                            
                            choice = GetInput(1,2);

                            if(choice==1){
                                Boss[bossindex].be_attack(false);
                                player.be_attack(2);
                            }
                            else if(choice ==2){
                                int item_class = 0;//select item

                                bool right = Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills);
                                if(right){
                                        Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                                }
                                else{
                                    player.be_attack(20);
                                }
                            }                           
                            if(player.Getter_learn()<0){
                                cout<<"你好像收到了一个学业警示";
                                //player.GetWarning();
                            }
                            else if(Boss[bossindex].Getter_hardlvl() < 0){
                                cout<<"你通过了考试";
                            }
                            break;}
            case rest: ;break;
            case bag: ; break;
            case store: ;break;
            default: this->ToffGame();
                    cout<<"esc unexpected";
                    break;
        }
    }
}

void MUDGame::ToffGame(){
    _Run = false;
}
bool MUDGame::RunOrNot(){
    return _Run;
}
void MUDGame::LoadLogo(){
    
     fstream file;
     file.open("date\\logo.dat",ios::in | ios::binary);
    if(!file){
        cout<<"file open error";
        exit(1);
    }

    int logolength;
    file.seekg(0,ios::end);
    logolength = (int)file.tellg();

    file.seekg(0,ios::beg);
    file.read(GameLogo,logolength);

     file.close();
    return ;


}
void MUDGame::ShowLogo(){
    SetConsoleTextAttribute(thewindow,FOREGROUND_BLUE);
    cout<<GameLogo;
    SetConsoleTextAttribute(thewindow,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
}
void showMap() {
	string line;
	ifstream file("data/map.dat");
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "无法打开文件" << endl;
	}
}

//带颜色的输出
void showInColor(char str[],int color,HANDLE console){
    SetConsoleTextAttribute(console,color);
    cout<<str;
    SetConsoleTextAttribute(console,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}
//输入检查
int GetInput(){
    char str[2];
    str[0] = getch();
    return atoi(str);
}
int GetInput(int min,int max){
    short n =GetInput();
    while(n<min||n>max){
        n = GetInput();
    }
    return n;
}

int SelectItem(){
    return 0;
}