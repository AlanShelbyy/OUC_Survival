#include<iostream>
#include<cstring>
#include"Game.h"
#include"Player.h"
#include"fight_part.h"
using namespace std;

enum {start_menu,inroom,fighting,rest,bag,store} gamestate;
//��������
Player player;
npc testene;

int main(){
    cout<<"test"<<endl;
    MUDGame thisgame;
    thisgame.LoadLogo();
    thisgame.ShowLogo();
    system("pause");

    int choice=0;
    gamestate = start_menu;
    while(thisgame.RunOrNot()){

        
        switch(gamestate){ 
            case start_menu:cout<<"this is start"<<endl;//������Ϸ״̬
                            gamestate = fighting;
                            //thisgame.ToffGame();
                            break;
            case inroom:cout<<"inroom";break;
            case fighting: cout<<"��ѡ����ս����"<<endl;
                            FightRound(player,testene);
                            
                            gamestate = inroom;
            
                            break;
            case rest: ;break;
            case bag: ; break;
            case store: ;break;
            default: thisgame.ToffGame();
                    cout<<"esc unexpected";
                    break;
            




        }
        


    }
   



    cout<<'#';
    system("pause");
    return 0;
}