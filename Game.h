
#include"Player.h"
#include"fight_part.h"
class MUDGame{
private:
char GameLogo[4096];
char GameMap[4096];
bool _Run;
Player player;
npc* NPCs;
//����
//��Ʒ
//�̵꣨��ѡ��


public:
MUDGame();
void ShowLogo();
void LoadLogo();
void ToffGame();
bool RunOrNot();
};