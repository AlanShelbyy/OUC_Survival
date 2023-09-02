
#include"Player.h"
#include"fight_part.h"
class MUDGame{
private:
char GameLogo[4096];
char GameMap[4096];
bool _Run;
Player player;
npc* NPCs;
//房间
//物品
//商店（可选）


public:
MUDGame();
void ShowLogo();
void LoadLogo();
void ToffGame();
bool RunOrNot();
};