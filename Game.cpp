
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
            case start_menu:cout<<"��ʼ����"<<endl;//������Ϸ״̬
                            
                            //thisgame.ToffGame();
                            break;
            case adv:    cout<<"ð����";
                            // return;
                            break;
            case fighstu:   cout<<"�����غ�"<<endl;
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
            case fightea:   cout<<"���Իغ�";
                            //BOSS��ӡ����
                            int bossskill = Boss[bossindex].Useskill(bossSkills);
                            //���ʹ�ü���
                            cout<<"ѡ���ж�"<<endl<<"1.��ͨ����hello world 2.ʹ����Ʒ";
                            cin>>choice;
                            if(choice==1){
                                Boss[bossindex].be_attack(false);
                            }
                            else if(choice ==2){
                                int item_class = 0;//select item
                                Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                            }                           
                            
                            if(player.Getter_learn()<0){
                                cout<<"������յ���һ��ѧҵ��ʾ";
                            }
                            else if(Boss[bossindex].Getter_hardlvl() < 0){
                                cout<<"��ͨ���˿���";

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