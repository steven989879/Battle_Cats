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
	// �o��class���ѰʺA(�i�H����)���ϧ�
	// �C��Public Interface���Ϊk���n���AImplementation�i�H����
	/////////////////////////////////////////////////////////////////////////////

	class enemy_one : public monster {
	public:
		enemy_one();
		~enemy_one() = default;
		enemy_one* create_enemy();
		int price = 50;
		int heart = 30;
		int single_attack;
		int attack_range = 5;
		int power = 5;
		int walk_speed = 2;
		int cool_time = 5;


	protected:
		

	private:
		//vector<cat_one*> cat_one_friend;
	};

	
}

#endif
