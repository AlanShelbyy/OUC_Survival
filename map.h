#pragma once
#include <string>
#include<vector>
using namespace std;
class ouc_map {
public:
	/*ouc_map(){};*/
	/*ouc_map(string name, short map_id, short neighbor[]);*/
	ouc_map( int n = 1);
	ouc_map(ouc_map& d);
	short getId() {
		return map_id;
	}
	void show();
	string getName() {
		return name;
	}
	void getNeib(short a[]) {
		for (int i = 0; i < 6; i++) {
			a[i] = neighbor[i];
		}
	}
private:
	string name;
	short map_id;//地图编号
	short neighbor[6];//相邻节点的编号
	vector<int> npc_id;//地图生成npc的编号
};





