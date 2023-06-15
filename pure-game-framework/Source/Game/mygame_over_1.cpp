#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver_1::CGameStateOver_1(CGame *g) : CGameState(g)
{
}

void CGameStateOver_1::OnMove()
{
	//GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver_1::OnBeginState()
{

}

void CGameStateOver_1::OnInit()
{
	background.LoadBitmapByString({"resources/end_win.bmp"});
	background.SetTopLeft(0, 0);
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66, "Initialize...");	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	//Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100, "OK!");

	//Sleep(1000);
}

void  CGameStateOver_1::OnLButtonDown(UINT nFlags, CPoint point)
{

}

void CGameStateOver_1::OnShow()
{	
	background.ShowBitmap();
}
