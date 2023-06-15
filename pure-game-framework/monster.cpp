#include "stdafx.h"
#include "../Core/game.h"
#include "../Core/MainFrm.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <direct.h>
#include <string.h>
#include ".\Source\.\Library\audio.h"
#include ".\Source\.\Library\gameutil.h"
#include ".\Source\.\Library\gamecore.h"
#include "Shlwapi.h"
#include "../Game/config.h"
#include "../Game/mygame.h"
#include <filesystem>
#include <experimental/filesystem> // Header file for pre-standard implementation
#include <comdef.h>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include"monster.h"
namespace game_framework {

	monster::monster(): CMovingBitmap()
	{
		
	}

	monster::monster(int type_ID)
	{
		if (type_ID == 1) {
			isBitmapLoaded = false;
			price = 50;
			heart = 30;
			attack_range = 10;
			power = 10;
			walk_speed = 2;
			attack_speed = 200;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
		if (type_ID == 2) { //坦克貓，但我的關卡2基本沒用
			isBitmapLoaded = false;
			price = 100;
			heart = 100;
			attack_range = 100;
			power = 5;
			walk_speed = 1;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 0;
		}
		if (type_ID == 3) { //斧頭貓，但我的關卡2基本沒用
			isBitmapLoaded = false;
			price = 200;
			heart = 50;
			attack_range = 10;
			power = 20;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
		if (type_ID == 11) {
			isBitmapLoaded = false;
			price = 50;//敵人
			heart = 30;//敵人
			attack_range = 5;
			power = 8;
			walk_speed = 1;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
		if (type_ID == 12) { //蛇
			isBitmapLoaded = false;
			price = 50;//敵人
			heart = 30;//敵人
			attack_range = 5;
			power = 10;
			walk_speed = 1;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}

		if (type_ID == 13) { //小人
			isBitmapLoaded = false;
			price = 50;//敵人
			heart = 30;//敵人
			attack_range = 5;
			power = 10;
			walk_speed = 2;
			if_attack = 0;
			type = 0;
			back_time = 0;
			whether_attack = false;
			single_attack = 1;
		}
	}

	int monster::get_type()
	{
		return type;
	}

	int monster::get_back_time()
	{
		return back_time;
	}

	bool monster::get_whether_attack()
	{
		return whether_attack;
	}

	int monster::get_price() 
	{
		return price ; 
	}

	int monster::get_heart()
	{
		return heart;
	}

	int monster::get_single_attack()
	{
		return single_attack;
	}

	int monster::get_attack_range()
	{
		return attack_range;
	}

	int monster::get_power()
	{
		return power;
	}

	int monster::get_walk_speed()
	{
		return walk_speed;
	}

	int monster::get_cool_time()
	{
		return cool_time;
	}

	int monster::get_if_attack()
	{
		return if_attack;
	}



}
