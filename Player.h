class Player_Options
{
public:
	Player(); //??? 
	void State() const;  //??  
	void Backpack() const; //??
	void Equip_equipments(int num_eq);//??/???
	void Move() const;  //?? 
	void Explore_items() const;  //???? 
	void Eat_orSleep() const; //???????? 
	void Learn_with_classmates() const;  //???NPC???? 
	void Exam_with_teachers() const;  //???NPC?? 
	void Tasks();
	void Settings();  //?? 
	void GetReward(int pro , int mat , int log , int pra , int lnp);

private:
	//ouc_map * p_m;

	struct Player_Stats* p; //??Player???
	int flag_major; //???????????	
	struct Player_Stats* p_equip;//????
	struct Player_Stats* p_equipment;//  ??????     
};
