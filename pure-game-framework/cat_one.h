#ifndef CAT_ONE_H
#define CAT_ONE_H

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

	class cat_one : public monster {
	public:
		cat_one();
		~cat_one() = default;
		cat_one* create_cat();
		
		int get_price();
		int get_heart();
		int get_single_attack();
		int get_attack_range();
		int get_power();
		int get_walk_speed();
		int get_cool_time();
		void set_name(int i);
		int price;
		int heart;
		int single_attack;
		int attack_range;
		int power;
		int walk_speed;
		int cool_time;

	protected:
		/*
		int price = 50;
		int heart = 30;
		int single_attack = 1;
		int attack_range = 5;
		int power = 5;
		int walk_speed = 2;
		int cool_time = 5;
		*/
		/*
		int price ;
		int heart ;
		int single_attack ;
		int attack_range ;
		int power ;
		int walk_speed ;
		int cool_time ;
		*/
	private:
		//vector<cat_one*> cat_one_friend;
	};

/*
	class cat_one_vector : public monster {
	public:
		cat_one_vector();

		cat_one* create_cat();


	protected:
		

	private:
		//vector<cat_one*> cat_one_friend;
	};
*/
}

#endif
