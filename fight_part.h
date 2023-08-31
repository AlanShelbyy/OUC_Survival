class npc{
public:
    void Useskill();
    void Leave();
    void GivePoint(/*player*/);

private:
    bool _IsBoss ; 
    bool _inround ;
    bool _inroom ;
    char Name[16];
    char Description[1024];
    int GiveMat;
    int GiveLog;
    int GiveProg;
    int GivePrac;
    int GiveLearnPinit;
    //problem

};

struct problem{
    char name[16];
    char description[1024];
    int hardlvl;

};