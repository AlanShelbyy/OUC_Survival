#include<iostream>
#include<random>
#include<ctime>
#include<cstring>
using namespace std;


#include"fight_part.h"

npc::npc(){
    _isBoss = false;
    strcpy(Name,"nobody");
    strcpy(Description, "a normal student");
    // Skill default_skill = {"��Ц","������������",0,"1. emm 2. emm? 3.aha",1};
    // skills.push_back(default_skill);


}
bool npc::IsBoss(){
    return _isBoss;
}

int npc::Useskill(vector<Skill> &skills){
    
    int choice;
    default_random_engine e;
    uniform_int_distribution<int> u(0,skills.size()-1);
    e.seed(time(0));
    choice = u(e);
    cout<<choice<<'#'<<endl;

    cout<<skills[choice].name<<endl;
    cout<<skills[choice].description<<endl;
    
    
    cout<<"ѡ����Ļش�"<<endl;
    cout<<skills[choice].choices<<endl;
    return choice;
    //cout<<"nothing"<<endl;

    
}

bool npc::Check(int skill_index,int choice,vector<Skill>& skills){
    if(skills[skill_index].answer == choice) return true;
    else return false;
}

bool npc::CheckEquip(int skill,int item_class,vector<Skill>& BossSkills){
    if(BossSkills[skill].answer == item_class)return true;
    else return false;

}

int npc::Getter_hardlvl(){
    return hardlvl;
}
void npc::GivePoint(Player player){

    cout<<"��û������"<<endl;
    
}
int npc::UseBossSkill(){

    return 0;
}

// void FightRound(Player thisPlayer,npc thisNpc){
//     cout<<"now you are fighting with nps";
//     //����ս��
//     if(thisNpc.IsBoss()){

//         //cout<<"ok";


//     }
//     else{
//         int choice = 0;
//         int sys_choice = 0;
//         int skill_index;
//         bool fight = true;
//         cout<<"һ��ѧ��������ʼ�ˣ���"<<endl;
//         while(fight){
//             skill_index = thisNpc.Useskill();
//             cin>>choice;
//             if(thisNpc.Check(skill_index,choice)){
//                 cout<<"��ɹ��ش�������"<<endl;
//                 //thisNpc.GivePoint();//������
//             }
//             cout<<"1. �������� 2. ��������"<<endl;
//             cin>>sys_choice;
//             if(sys_choice == 1){}
//             else if(sys_choice == 2){
//                 fight =false;
//             }
            

//         }
//     }
    
//     return;
// }