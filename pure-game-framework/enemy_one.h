#pragma once
#ifndef ENEMY_ONE_H
#define ENEMY_ONE_H

#include <list>
#include <vector>
#include <map>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include".\Source\.\Library\gameutil.h"
#include"monster.h"


using namespace std;

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供動態(可以移動)的圖形
	// 每個Public Interface的用法都要懂，Implementation可以不懂
	/////////////////////////////////////////////////////////////////////////////

	class enemy_one : public monster {
	public:
		enemy_one();
		~enemy_one() = default;
		enemy_one* create_enemy();
		
		int get_price();
		int get_heart();
		int get_single_attack();
		int get_attack_range();
		int get_power();
		int get_walk_speed();
		void set_name(int i);
		int price;
		int heart;
		int single_attack;
		int attack_range;
		int power;
		int walk_speed;


	protected:
		

	private:
		//vector<cat_one*> cat_one_friend;
	};

	
}

#endif
