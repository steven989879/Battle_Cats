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
#include"cat_one.h"
namespace game_framework {

	cat_one::cat_one() : monster()
	{
		isBitmapLoaded = false;
		price = 50;
		heart = 30;
		attack_range = 5;
		power = 5;
		walk_speed = 2;
		cool_time = 5;
		if_attack = 0;
	}



	cat_one * cat_one::create_cat()
	{
		cat_one *temp1 = new cat_one();
		return(temp1);
	}

	int cat_one::get_price()
	{
		return price;
	}

	int cat_one::get_heart()
	{
		return heart;
	}

	int cat_one::get_single_attack()
	{
		return single_attack;
	}

	int cat_one::get_attack_range()
	{
		return attack_range;
	}

	int cat_one::get_power()
	{
		return power;
	}

	int cat_one::get_walk_speed()
	{
		return walk_speed;
	}

	int cat_one::get_cool_time()
	{
		return cool_time;
	}

	void cat_one::set_name(int i)
	{
		name = i;
	}

	int cat_one::get_if_attack()
	{
		return if_attack;
	}



}
