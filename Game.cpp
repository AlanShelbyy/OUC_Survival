
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
        cout<<"��ʧ��"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.name;
        infile>>tmp.description;
        infile>>tmp.choices;
        infile>>tmp.answer;
        infile>>tmp.hardlvl;
         if(infile.eof()){
            cout<<"��ȡ����"<<endl;
            return ;
         }
        skills.push_back(tmp);
        // cout<<skills.size()<<'#';
    }
    return;
}

void MUDGame::ShowSkillList(){
    for(int i = 0;i < skills.size();i++){
        cout<<"��ӡ��";
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
            case start_menu:cout<<"��ʼ����"<<endl;//������Ϸ״̬
                            ShowLogo();
                            cout<<"һ������ĺ���ѧ��"<<endl;
                            cout<<"1. �µĿ�ʼ 2. ����ѧҵ 3.�˳���Ϸ"<<endl;
                            cin>>operate;
                            if(operate == 1){
                                system("cls");
                                player.ChooseMajor();
                                system("cls");
                                //cout<<"��ٵ�ѡרҵ"<<endl;
                                gamestate = adv;
                            }
                            else if(operate == 2){
                                //�浵δ���
                            }
                            else if(operate == 3){
                                //do nothing
                                return;
                            }
                            
                            //thisgame.ToffGame();
                            break;
            case adv:    cout<<"ð����"<<endl;
                            
                            // return;
                            system("pause");
                            break;
            case fighstu:   {cout<<"�����غ�"<<endl;
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
            case fightea:   cout<<"���Իغ�";
                            system("pause");
                            // //BOSS��ӡ����
                            // int bossskill = Boss[bossindex].Useskill(bossSkills);
                            // //���ʹ�ü���
                            // cout<<"ѡ���ж�"<<endl<<"1.��ͨ����hello world 2.ʹ����Ʒ";
                            // cin>>choice;
                            // if(choice==1){
                            //     Boss[bossindex].be_attack(false);
                            // }
                            // else if(choice ==2){
                            //     int item_class = 0;//select item
                            //     Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                            // }                           
                            
                            // if(player.Getter_learn()<0){
                            //     cout<<"������յ���һ��ѧҵ��ʾ";
                            // }
                            // else if(Boss[bossindex].Getter_hardlvl() < 0){
                            //     cout<<"��ͨ���˿���";

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