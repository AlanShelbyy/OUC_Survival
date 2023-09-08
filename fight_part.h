#ifndef FIGHT_H
#define FIGHT_H
#include"Player.h"
#include<vector>

typedef struct Tskill{
    char name[16];
    char description[1024];
    int  hardlvl;
    char choices[32];
    int  answer;

}Skill;

class npc{
public:
    npc();
    int Useskill(vector<Skill>& skills);
    int UseBossSkill();
    bool Check(int skill,int choice,vector<Skill>& skills);
    bool CheckEquip(int skill,int item_class,vector<Skill>& BossSkills);
    int Getter_hardlvl();
    void be_attack(bool right_item);
    void GivePoint(Player &player);
    void Debug_show();
    bool IsBoss();
    //ÎªÁË·½±ã
    int hardlvl;
    char Name[16];
    char Description[1024];
    int GiveMat;
    int GiveLog;
    int GiveProg;
    int GivePrac;
    int GiveLearnPinit;
private:
    bool _isBoss ; 
    bool _inround ;
    


};



void FightRound(Player thisPlayer, npc thisNpc);

#endif 