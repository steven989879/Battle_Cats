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

		int get_price();
		int get_heart();
		int get_attack_range();
		int get_power();
		int get_walk_speed();
		int get_cool_time();
	protected:
		int price ;
		int heart ;
		int attack_range ;
		int power ;
		int walk_speed ;
		int cool_time ;

	};

}

#endif
