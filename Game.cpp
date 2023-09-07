
#include"Game.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Equipment.h"
#include"map.h"
#include"fight_part.h"
#include<windows.h>
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
        infile>>tmp.GiveMat;
        infile>>tmp.GiveLog;
        infile>>tmp.GiveProg;
        infile>>tmp.GivePrac;
        infile>>tmp.GiveLearnPinit;
        infile>>tmp.hardlvl;
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
    cout<<"load end"<<endl;
    thewindow = GetStdHandle( STD_OUTPUT_HANDLE );
    int choice=0;
    int operate;
    npc* tmpNpc;
    gamestate = start_menu;
    while(RunOrNot()){
        system("cls");
        
        switch(gamestate){ 
            case start_menu:cout<<"��ʼ����"<<endl;//������Ϸ״̬
                            
                            ShowLogo();
                            
                            cout<<"һ������ĺ���ѧ��"<<endl;
                            cout<<"1. �µĿ�ʼ 2. ����ѧҵ 3.�˳���Ϸ"<<endl;
                            cin>>operate;
                            if(operate == 1){
                                system("cls");
                                player.ChooseMajor();
                                player.State();
                                system("pause");
                                
                                //cout<<"��ٵ�ѡרҵ"<<endl;
                                gamestate = adv;
                            }
                            else if(operate == 2){
                                //�浵δ���
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
                            cin >> opt;
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
                                //     //�ж��Ƿ�����ʦ
                                //    if(player.getMap_id()==6||player.getMap_id()==9||player.getMap_id()==17)
                                //    {
                                //     int dz;
                                //     cout<<"1. "<<Boss[player.get_map()->getBoss_id()[0]].Name;
                                //     for(dz=0;dz<player.get_map()->getNpc_id().size();dz++)
                                //     {
                                //         cout<<dz+1<<' '<<NPCs[player.get_map()->getNpc_id()[dz]].Name;
                                //     }

                                //     int temp_dz;
                                    
                                //     cin>>temp_dz;
                                    
                                    
                                //     if(temp_dz!=1){ //ѧ��
                                //         cout<<"������ѧ������/���ԵĶ����� "<<NPCs[player.get_map()->getNpc_id()[temp_dz+1]].Name;
                                //         gamestate=fighstu;
                                //     }
                                    
                                //     else {
                                //         cout<<"�����ڽ��п��ԵĶ����� "<<Boss[player.get_map()->getBoss_id()[0]].Name;
                                //     }
                                //    }//û����ʦ�Ļ�
                                //    else{
                                    //���δ�ӡ����
                                    cout<<"ѡ����˭����"<<endl;
                                    for(int dz=0;dz<player.get_map()->getNpc_id().size();dz++)
                                    {
                                        cout<<dz+1<<' '<<NPCs[player.get_map()->getNpc_id()[dz]].Name;
                                    }
                                    //ѡ��npc
                                    
                                    int temp_dz2;
                                    cin>>temp_dz2;
                                    //�����飿

                                    cout<<"������ѧ�������Ķ����� "<<NPCs[player.get_map()->getNpc_id()[temp_dz2-1]].Name;
                                    npcchoice = player.get_map()->getNpc_id()[temp_dz2];
                                    gamestate = fighstu;
                                    

                                  // }
                                }
                                system("pause>nul");
                                break;
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
                                cout<<"1. ������Ϸ 2. ������� 3. �˳���Ϸ"<<endl;
                                int localOpt = 0;
                                //����Ӽ��

                            }         
                            break;
                        }
            case fighstu:   {
                            cout<<"�����غ�"<<endl;
                           
                            
                            system("pause");

                            tmpNpc = &NPCs[npcchoice];
                            int skillindex =tmpNpc->Useskill(skills);
                            
                            cin>>choice;
                            if(tmpNpc->Check(skillindex,choice,skills)){
                                tmpNpc->GivePoint(player);
                            }
                            else{
                                cout<<"�ش����"<<endl;
                            }
                            cout<<"ѡ�� 1. ȥð�� 2.��������"<<endl;
                            cin>>operate;
                            if(operate == 1){
                                gamestate = adv;
                                
                            }
                            else{

                            }

            
                            break;}
            case fightea:  { 
                            cout<<"���Իغ�";
                            system("pause");
                            //BOSS��ӡ����
                            int bossskill = Boss[bossindex].Useskill(bossSkills);
                            //���ʹ�ü���
                            cout<<"ѡ���ж�"<<endl<<"1.��ͨ����hello world 2.ʹ����Ʒ";
                            cin>>choice;
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