#ifndef MONSTER_H
#define MONSTER_H

#include <list>
#include <vector>
#include <map>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include".\Source\.\Library\gameutil.h"


using namespace std;

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供動態(可以移動)的圖形
	// 每個Public Interface的用法都要懂，Implementation可以不懂
	/////////////////////////////////////////////////////////////////////////////

	class monster : public CMovingBitmap {
	public:
		monster();
		monster(int type_ID);
		~monster() = default;

		int get_type();
		int get_back_time();
		bool get_whether_attack();

		int type;
		int back_time;
		bool whether_attack;
		CMovingBitmap attack;
		CMovingBitmap bump;
		//CMovingBitmap back;
		
		int get_price();
		int get_heart();
		int get_single_attack();
		int get_attack_range();
		int get_power();
		int get_walk_speed();
		int get_cool_time();
		int get_if_attack();
		int price;
		int heart;
		int single_attack;
		int attack_range;
		int power;
		int walk_speed;
		int cool_time;
		int if_attack;
	protected:
	};

}

#endif
