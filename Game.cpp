
#include"Game.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Equipment.h"
#include"map.h"
#include"Bag.h"
#include"fight_part.h"
#include<windows.h>
#include<conio.h>
using namespace std;

enum {
    start_menu,
    adv,
    fighstu,
    fightea,
    rest,
    bag,
    store
    } gamestate;

extern vector<Equipment*> equipment_bag;
extern ouc_map Ouc_map[19];



void showMap();
void showInColor(char str[],int color,HANDLE console);
int GetInput();
int GetInput(int,int);
MUDGame::MUDGame(){
    _Run = true;
}

void MUDGame::LoadNpc(){
    fstream infile;
    npc tmp;
    infile.open("date\\npc.dat",ios::in);
    if(!infile){
        cout<<"��ʧ��"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.Name;
        infile>>tmp.Description;

        infile>>tmp.GiveMat;//cout<<tmp.GiveMat;
        infile>>tmp.GiveLog;//cout<<tmp.GiveLog;
        infile>>tmp.GiveProg;//cout<<tmp.GiveProg;
        infile>>tmp.GivePrac;//cout<<tmp.GivePrac;
        infile>>tmp.GiveLearnPinit;//cout<<tmp.GiveLearnPinit;
        infile>>tmp.hardlvl;
        //cout<<"##"<<endl;
        NPCs.push_back(tmp);
    }
    return;
}

void MUDGame::LoadSkill(){
    fstream infile;
    Skill tmp;
    string argus;
    infile.open("date\\normskill.dat",ios::in);
    if(!infile){
        cout<<"��ʧ��"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.name;
        infile>>tmp.description;
        infile>>tmp.choices;
        infile>>tmp.answer;
        infile>>tmp.hardlvl;
        skills.push_back(tmp);
    }
    return;
}

void MUDGame::LoadBoss(){
    fstream infile;
    npc tmp;
    infile.open("date\\boss.dat",ios::in);
    if(!infile){
        cout<<"��ʧ��"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.Name;
        infile>>tmp.Description;
        infile>>tmp.GiveMat;
        infile>>tmp.GiveLog;
        infile>>tmp.GiveProg;
        infile>>tmp.GivePrac;
        infile>>tmp.GiveLearnPinit;
        infile>>tmp.hardlvl;
        Boss.push_back(tmp);
    }
    return;
}
void MUDGame::LoadBossSkill(){
    fstream infile;
    Skill tmp;
    string argus;
    infile.open("date\\bossskill.dat",ios::in);
    if(!infile){
        cout<<"��ʧ��"<<endl;
        exit(1);
    }
    while(!infile.eof()){
        infile>>tmp.name;
        infile>>tmp.description;
        infile>>tmp.choices;
        infile>>tmp.answer;
        infile>>tmp.hardlvl;
        bossSkills.push_back(tmp);
    }
    return;
}
//����ͼ�ļ�������Ouc_map������
void MUDGame::LoadMap() {
    for (int i = 0; i < 19; i++) {
        ouc_map map(i + 1);
        Ouc_map[i] = map;
    }
}
void MUDGame::ShowNpcList(){
    for(int i = 0; i<NPCs.size();i++){
        cout<<NPCs[i].Name<<endl;
        cout<<NPCs[i].Description<<endl;
        cout<<NPCs[i].GiveLearnPinit<<endl;
        cout<<NPCs[i].GiveLog<<endl;
        cout<<NPCs[i].GiveMat<<endl;
        cout<<NPCs[i].GivePrac<<endl;
        cout<<NPCs[i].GiveProg<<endl;
    }

} 


void MUDGame::ShowSkillList(){
    for(int i = 0;i < skills.size();i++){
        cout<<"��ӡ��";
        cout<<skills[i].name<<endl;
        cout<<skills[i].description<<endl;
        cout<<skills[i].choices<<endl;
        cout<<skills[i].answer<<endl;
        cout<<skills[i].hardlvl<<endl;
    }
    return;


}
// void MUDGame::GetMapNpc(){
//     vector<int> npcs = player.get_map()->getNpc_id();
//     for(int i =0;i < npcs.size();i++){
//         npcindex.push_back(npcs[i]);
//     }
// }
void MUDGame::RunGame(){
    LoadLogo();
    LoadSkill();
    //ShowSkillList();
    LoadBoss();
    LoadBossSkill();
    LoadNpc();
    LoadMap();
    //ShowNpcList();
    //cout<<"load end"<<endl;
    Bag bagsaver;
    thewindow = GetStdHandle( STD_OUTPUT_HANDLE );
    int choice=0;
    int operate;
    
    gamestate = start_menu;
    while(RunOrNot()){
        system("cls");
        
        switch(gamestate){ 
            case start_menu:cout<<"��ʼ����"<<endl;//������Ϸ״̬
                            
                            ShowLogo();
                            cout<<endl;
                            cout<<"һ������ĺ���ѧ��"<<endl;
                            cout<<"1. �µĿ�ʼ 2. ����ѧҵ 3.�˳���Ϸ"<<endl;
                            operate = GetInput(1,3);
                            if(operate == 1){
                                system("cls");
                                player.ChooseMajor();
                                player.State();
                                system("pause>nul");
                                
                                //cout<<"��ٵ�ѡרҵ"<<endl;
                                gamestate = adv;
                            }
                            else if(operate == 2){
                                cout<<"�����浵"<<endl;
                                bagsaver.bag_read();
                                gamestate = adv;
                                break;
                            }
                            else if(operate == 3){
                                
                                break;
                            }
                            
                            //thisgame.ToffGame();
                            break;
            case adv:   {cout<<"ð����"<<endl;
                            player.get_map()->show();//չʾ��ͼ��Ϣ,����е�ͼ����
                            //չʾ����npc������ɫ
                            for(int i = 0; i<player.get_map()->getNpc_id().size(); i++){
                                //cout<<player.get_map()->getNpc_id()[i];
                                showInColor(NPCs[player.get_map()->getNpc_id()[i]].Name,1,thewindow);
                                cout<<endl;
                            }
                            //
                            
                            cout << "��Ҫ������ʲô : " << endl;
                            cout << endl;
                            cout << "1. �鿴״̬  2.����  3. ̽��  4. ѧϰ����/���뿼��  5.�ƶ�  6. �Է�/˯��  7. ��ͼ 8.ϵͳ" << endl;
                            cout << endl;
                            int opt;
                            opt =GetInput(1,8);
                            if (opt == 1)
                            {
                                cout << "���״̬ : " << endl;
                                player.State();
                                system("pause>nul");
                                break;
                            }
                            else if (opt == 2)
                            {
                                if (!equipment_bag.size()) //����Ϊ��
                                {
                                    cout << "��ı����� �տ���Ҳ " << endl;
                                }
                                else
                                {
                                    cout << "�������㱳���е���Ʒ : " << endl;
                                    player.Backpack();
                                }
                                system("pause>nul");
                                break;
                                
                            }
                            else if (opt == 3)
                            {
                                map_explore(player);//̽����ͼ
                                system("pause>nul");
                                break;

                            }
                            else if (opt == 4)
                            {
                                //cout<<"ȥ��ĵط�������"<<endl;
                                cout<<"������"<<endl;
                                if (player.get_map()->getNpc_id().empty())//�÷���û��NPC
                                {
                                    cout << "������ò�ƿ���һ��" << endl;
                                }
                                else
                                {
                                    //�ж��Ƿ�����ʦ
                                   if(player.getMap_id()==6||player.getMap_id()==9||player.getMap_id()==17)
                                   {
                                    
                                    cout<<"1. "<<Boss[player.get_map()->getBoss_id()[0]].Name<<endl;
                                    
                                    for(int i = 0 ;i<player.get_map()->getNpc_id().size();i++)
                                    {
                                        cout<<i+2<<". "<<NPCs[player.get_map()->getNpc_id()[i]].Name<<endl;
                                    }

                                    int choice;
                                    choice = GetInput(1,player.get_map()->getNpc_id().size()+1);
                                    
                                    
                                    if(choice!=1){ //ѧ��
                                        cout<<"������ѧ������/���ԵĶ����� "<<NPCs[player.get_map()->getNpc_id()[choice-1]].Name<<endl;
                                        npcchoice = player.get_map()->getNpc_id()[choice-1];
                                        gamestate=fighstu;
                                    }
                                    
                                    else {
                                        cout<<"�����ڽ��п��ԵĶ����� "<<Boss[player.get_map()->getBoss_id()[0]].Name<<endl;
                                    }
                                   }//û����ʦ�Ļ�
                                   else{
                                    //���δ�ӡ����
                                    cout<<"ѡ����˭����"<<endl;
                                    for(int dz=0;dz<player.get_map()->getNpc_id().size();dz++)
                                    {
                                        cout<<dz+1<<' '<<NPCs[player.get_map()->getNpc_id()[dz]].Name;
                                    }
                                    //ѡ��npc
                                    cout<<endl;
                                    int temp_dz2;
                                    temp_dz2 =GetInput(1,player.get_map()->getNpc_id().size());
                                    
                                    cout<<"������ѧ�������Ķ����� "<<NPCs[player.get_map()->getNpc_id()[temp_dz2-1]].Name;
                                    npcchoice = player.get_map()->getNpc_id()[temp_dz2-1];
                                    gamestate = fighstu;
                                   }
                                }
                                
                                
                            }
                            else if (opt == 5)
                            {
                                // cout << endl;
                                // cout << "�㵱ǰ���ڵر�ż�����Ϊ ";
                                // player.get_map()->show();
                               // cout<<"�����ȥ�ĵط�:"<<endl;
                                //��ӡ
                                //ѡ��
                                //�ƶ�
                                move(player);
                            }
                            else if (opt == 6)
                            {
                                player.Eat_orSleep();
                            }
                            else if (opt == 7)
                            {
                                showMap();
                                system("pause>nul");
                            }
                            else if(opt==8){
                                system("cls");
                                ShowLogo();
                                cout<<endl;
                                cout<<"1. ������Ϸ 2. ������� 3. �˳���Ϸ"<<endl;
                                int localOpt = 0;

                                //����Ӽ��
                                localOpt=GetInput(1,3);
                                switch(localOpt){
                                    case 1:
                                    case 2://����
                                            bagsaver.bag_write();

                                    case 3:ToffGame();break;
                                    default: break;
                                }
                                cout<<"ʩ����"<<endl;

                            }         
                            break;
                        }
            case fighstu:   {
                            cout<<"�����غ�"<<endl;
                            // system("pause");
                            
                            int skillindex =NPCs[npcchoice].Useskill(skills);
                            choice = GetInput(1,4);
                            if(NPCs[npcchoice].Check(skillindex,choice,skills)){
                               // NPCs[npcchoice].Debug_show();
                                NPCs[npcchoice].GivePoint(player);
                                cout<<"��Ӣ������������������Ļش�"<<endl;
                            }
                            else{
                                cout<<"�ش����"<<endl;
                            }


                            cout<<"������ 1. ȥð�� 2.��������"<<endl;
                            operate = GetInput(1,2);
                            if(operate == 1){
                                gamestate = adv;
                            }
                            break;}
            case fightea:  { 

                            cout<<"���Իغ�";
                            //system("pause");
                            //BOSS��ӡ����
                            int bossskill = Boss[bossindex].Useskill(bossSkills);
                            //���ʹ�ü���
                            
                            cout<<"ѡ���ж�"<<endl<<"1.��ͨ����hello world 2.ʹ����Ʒ"<<endl;
                            
                            choice = GetInput(1,2);

                            if(choice==1){
                                Boss[bossindex].be_attack(false);
                                player.be_attack(2);
                            }
                            else if(choice ==2){
                                int item_class = 0;//select item

                                bool right = Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills);
                                if(right){
                                        Boss[bossindex].be_attack(Boss[bossindex].CheckEquip(bossskill,item_class,bossSkills));
                                }
                                else{
                                    player.be_attack(20);
                                }
                            }                           
                            if(player.Getter_learn()<0){
                                cout<<"������յ���һ��ѧҵ��ʾ";
                                //player.GetWarning();
                            }
                            else if(Boss[bossindex].Getter_hardlvl() < 0){
                                cout<<"��ͨ���˿���";
                            }
                            break;}
            case rest: ;break;
            case bag: ; break;
            case store: ;break;
            default: this->ToffGame();
                    cout<<"esc unexpected";
                    break;
        }
    }
}

void MUDGame::ToffGame(){
    _Run = false;
}
bool MUDGame::RunOrNot(){
    return _Run;
}
void MUDGame::LoadLogo(){
    
     fstream file;
     file.open("date\\logo.dat",ios::in | ios::binary);
    if(!file){
        cout<<"file open error";
        exit(1);
    }

    int logolength;
    file.seekg(0,ios::end);
    logolength = (int)file.tellg();

    file.seekg(0,ios::beg);
    file.read(GameLogo,logolength);

     file.close();
    return ;


}
void MUDGame::ShowLogo(){
    SetConsoleTextAttribute(thewindow,FOREGROUND_BLUE);
    cout<<GameLogo;
    SetConsoleTextAttribute(thewindow,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
}
void showMap() {
	string line;
	ifstream file("data/map.dat");
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "�޷����ļ�" << endl;
	}
}

//����ɫ�����
void showInColor(char str[],int color,HANDLE console){
    SetConsoleTextAttribute(console,color);
    cout<<str;
    SetConsoleTextAttribute(console,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}
//������
int GetInput(){
    char str[2];
    str[0] = getch();
    return atoi(str);
}
int GetInput(int min,int max){
    short n =GetInput();
    while(n<min||n>max){
        n = GetInput();
    }
    return n;
}

int SelectItem(){
    return 0;
}