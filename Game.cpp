
#include"Game.h"
#include<iostream>
#include<fstream>
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

MUDGame::MUDGame(){
    _Run = true;
}
void MUDGame::RunGame(){
    this->LoadLogo();
    this->ShowLogo();
    system("pause");

    int choice=0;
    int operate;
    npc* tmpNpc;
    gamestate = start_menu;
    while(this->RunOrNot()){

        
        switch(gamestate){ 
            case start_menu:cout<<"开始界面"<<endl;//各种游戏状态
                            
                            //thisgame.ToffGame();
                            break;
            case adv:    cout<<"冒险中";
                            // return;
                            break;
            case fighstu:   cout<<"交流回合"<<endl;
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

            
                            break;
            case fightea:   cout<<"考试回合";
                            //BOSS打印技能
                            int bossskill = Boss[bossindex].Useskill(bossSkills);
                            //玩家使用技能
                            cout<<"选择行动"<<endl<<"1.普通攻击hello world 2.使用物品";
                            cin>>choice;
                            if(choice==1){
                                Boss[bossindex].be_attack(false);
                            }
                            else if(choice ==2){
                                int item_class = 0;//select item
                                Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                            }                           
                            
                            if(player.Getter_learn()<0){
                                cout<<"你好像收到了一个学业警示";
                            }
                            else if(Boss[bossindex].Getter_hardlvl() < 0){
                                cout<<"你通过了考试";

                            }

                            



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