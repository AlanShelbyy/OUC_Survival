class Player_Options
{
public:
	Player_Options(); //��ʼ�� 
	void State() const;  //״̬  
	void Backpack() const; //���� 
	void Move() const;  //�ƶ� 
	void Explore_items() const;  //̽����Ʒ 
	void Eat_orSleep() const; //������ʳ�ã��Է� 
	void Learn_with_classmates() const;  //��ͬѧNPCѧϰ���� 
	void Exam_with_teachers() const;  //���ʦNPC���� 
	void Tasks();
	void Settings();  //���� 

private:
	struct Player* p; //ָ��Player��ָ��
	int flag_major; //���ڿ���ʱ�����ѡרҵ	
};