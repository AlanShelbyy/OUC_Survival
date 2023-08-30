#include<iostream>
#include"Game.h"
using namespace std;

enum {start_menu,inroom,fighting,rest,bag,store} gamestate;

int main(){
    cout<<"test"<<endl;
    MUDGame thisgame;
    thisgame.LoadLogo();
    thisgame.ShowLogo();
    system("pause");

    int choice=0;
    gamestate = start_menu;
    while(thisgame.RunOrNot()){

        // cout<<"Running game"<<endl;
        // cout<<"closing"<<endl;
        // thisgame.ToffGame();
        // cout<<"turn off success"<<endl;
        switch(gamestate){
            case start_menu:cout<<"this is start"<<endl;
                            thisgame.ToffGame();break;
            case inroom: ;break;
            case fighting: ;break;
            case rest: ;break;
            case bag: ; break;
            case store: ;break;
            default: thisgame.ToffGame();
                    cout<<"esc unexpected";
            




        }
        


    }
   



    cout<<'#';
    system("pause");
    return 0;
}