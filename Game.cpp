
#include"Game.h"
#include<iostream>
#include<fstream>
using namespace std;
enum {start_menu,inroom,fighting,rest,bag,store} gamestate;
MUDGame::MUDGame(){
    _Run = true;


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
void MUDGame::RunGame(){
    system("pause");

    int choice=0;
    gamestate = start_menu;
    while(this->RunOrNot()){

        
        switch(gamestate){ 
            case start_menu:cout<<"this is start"<<endl;//各种游戏状态
                            gamestate = fighting;
                            //thisgame.ToffGame();
                            break;
            case inroom:cout<<"inroom";break;
            case fighting: cout<<"你选择了战斗！"<<endl;
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
}