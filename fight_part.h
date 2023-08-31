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
    int Useskill();
    bool Check(int skill,int choice);
    void UseBossSkill();
    void Leave();
    void GivePoint(Player player);
    bool IsBoss();
private:
    bool _isBoss ; 
    bool _inround ;
    
    char Name[16];
    char Description[1024];
    int GiveMat;
    int GiveLog;
    int GiveProg;
    int GivePrac;
    int GiveLearnPinit;
    vector<Skill> skills;
    vector<Skill> bossSkills;

};



void FightRound(Player thisPlayer, npc thisNpc);

#endif 