
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
                            
                            
                            
                            
            
                            break;
            case fightea:   cout<<"���Իغ�";
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