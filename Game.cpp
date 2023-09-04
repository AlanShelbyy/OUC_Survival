
#include"Game.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Equipment.h"
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

vector<Equipment*> equipment_bag;

MUDGame::MUDGame(){
    _Run = true;
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
         if(infile.eof()){
            cout<<"读取结束"<<endl;
            return ;
         }
        skills.push_back(tmp);
        // cout<<skills.size()<<'#';
    }
    return;
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
void MUDGame::RunGame(){
    LoadLogo();
    LoadSkill();
    //ShowSkillList();
    cout<<"end"<<endl;
    int choice=0;
    int operate;
    npc* tmpNpc;
    gamestate = start_menu;
    while(RunOrNot()){

        
        switch(gamestate){ 
            case start_menu:cout<<"开始界面"<<endl;//各种游戏状态
                            ShowLogo();
                            cout<<"一名坚毅的海大学生"<<endl;
                            cout<<"1. 新的开始 2. 继续学业 3.退出游戏"<<endl;
                            cin>>operate;
                            if(operate == 1){
                                system("cls");
                                player.ChooseMajor();
                                system("cls");
                                //cout<<"虚假的选专业"<<endl;
                                gamestate = adv;
                            }
                            else if(operate == 2){
                                //存档未完成
                            }
                            else if(operate == 3){
                                //do nothing
                                return;
                            }
                            
                            //thisgame.ToffGame();
                            break;
            case adv:    cout<<"冒险中"<<endl;
                            
                            // return;
                            system("pause");
                            break;
            case fighstu:   {cout<<"交流回合"<<endl;
                            system("pause");
                            tmpNpc = &NPCs[npcindex[npcchoice]];
                            int skillindex =tmpNpc->Useskill(skills);
                            
                            cin>>choice;
                            if(tmpNpc->Check(skillindex,choice,skills)){
                                tmpNpc->GivePoint(player);
                            }

                            cin>>operate;
                            if(operate == 1){
                                gamestate = adv;
                                npcindex.erase(npcindex.begin(),npcindex.end());
                            }
                            else{

                            }

            
                            break;}
            case fightea:   cout<<"考试回合";
                            system("pause");
                            // //BOSS打印技能
                            // int bossskill = Boss[bossindex].Useskill(bossSkills);
                            // //玩家使用技能
                            // cout<<"选择行动"<<endl<<"1.普通攻击hello world 2.使用物品";
                            // cin>>choice;
                            // if(choice==1){
                            //     Boss[bossindex].be_attack(false);
                            // }
                            // else if(choice ==2){
                            //     int item_class = 0;//select item
                            //     Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                            // }                           
                            
                            // if(player.Getter_learn()<0){
                            //     cout<<"你好像收到了一个学业警示";
                            // }
                            // else if(Boss[bossindex].Getter_hardlvl() < 0){
                            //     cout<<"你通过了考试";

                            // }

                            



                            break;
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

    cout<<GameLogo;
}