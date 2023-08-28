
#include"Game.h"
#include<iostream>
#include<fstream>
using namespace std;
void MUDGame::LoadLogo(){
    
     fstream file;
     file.open("date\\logo.dat");
    if(!file){
        cout<<"file open error";
        exit(1);
    }

     file.read(GameLogo,4096*sizeof('0'));

    // file.close();



}
void MUDGame::ShowLogo(){

    cout<<GameLogo;
}