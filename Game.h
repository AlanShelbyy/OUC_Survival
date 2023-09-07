
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
//����
//��Ʒ
//�̵꣨��ѡ��

//һЩ������ʾ״̬��
vector<int> npcindex;
int npcchoice ;

int bossindex;

public:
MUDGame();
//��Ϸ������Ϊ
void LoadNpc();
void LoadLogo();
void LoadSkill();
void LoadBossSkill();
void LoadBoss();
void LoadMap();
//debug
void ShowNpcList();
void ShowLogo();

//��Ϸ����
//void GetMapNpc();
void ShowSkillList();
void ToffGame();
bool RunOrNot();
void RunGame();
};