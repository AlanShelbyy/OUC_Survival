#include<iostream>
#include"Game.h"
using namespace std;

enum{start_menu,inroom};

int main(){
    cout<<"test"<<endl;
    MUDGame thisgame;
    thisgame.LoadLogo();
    thisgame.ShowLogo();
    
   


    cout<<'#';
    system("pause");
    return 0;
}