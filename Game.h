class MUDGame{
private:
char GameLogo[4096];
char GameMap[4096];
bool _Run;



public:
MUDGame();
void ShowLogo();
void LoadLogo();
void ToffGame();
bool RunOrNot();
};