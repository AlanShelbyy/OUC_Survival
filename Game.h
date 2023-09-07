
#include"Player.h"
#include"fight_part.h"
class MUDGame{
private:
char GameLogo[4096];
char GameMap[4096];
bool _Run;
Player player;
vector<npc> NPCs;
vector<npc> Boss;

vector<Skill> skills;
vector<Skill> bossSkills;
//房间
//物品
//商店（可选）

//一些用来表示状态的
vector<int> npcindex;
int npcchoice ;

int bossindex;

public:
MUDGame();
//游戏加载行为
void LoadNpc();
void LoadLogo();
void LoadSkill();
void LoadBossSkill();
void LoadBoss();
void LoadMap();
//debug
void ShowNpcList();
void ShowLogo();

//游戏运行
//void GetMapNpc();
void ShowSkillList();
void ToffGame();
bool RunOrNot();
void RunGame();
};