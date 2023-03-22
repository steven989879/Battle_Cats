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
	// �o��class���ѰʺA(�i�H����)���ϧ�
	// �C��Public Interface���Ϊk���n���AImplementation�i�H����
	/////////////////////////////////////////////////////////////////////////////

	class monster : public CMovingBitmap {
	public:
		monster();

		virtual int get_price();
		virtual int get_heart();
		virtual int get_attack_range();
		virtual int get_power();
		virtual int get_walk_speed();
		virtual int get_cool_time();
		virtual void set_name(int i);
	protected:
		int name;
		int price  ;
		int heart ;
		int attack_range ;
		int power ;
		int walk_speed ;
		int cool_time ;
	};

}

#endif
