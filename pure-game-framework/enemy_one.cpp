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
//#include"cat_one.h"
#include "enemy_one.h"
namespace game_framework {

	enemy_one::enemy_one()
	{
	}

	enemy_one * enemy_one::create_enemy()
	{
		enemy_one *temp1 = new enemy_one();
		return(temp1);
	}

}
