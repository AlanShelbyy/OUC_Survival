#include<iostream>
#include<vector>
#include<cstring>
#include"Game.h"
#include"map.h"
#include"Equipment.h"
#include"Player.h"
#include"fight_part.h"
using namespace std;

ouc_map Ouc_map[19];

vector<Equipment*> equipment_bag;
//²âÊÔÑùÀı
Player player;
npc testene;

int main(){
    
    MUDGame thisgame;
    
    thisgame.RunGame();



    cout<<'#';
    system("pause");
    return 0;
}