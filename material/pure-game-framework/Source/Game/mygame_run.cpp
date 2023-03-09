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
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if (character.GetLeft() + character.GetWidth() != character_enemy.GetLeft() && character.GetLeft() + character.GetWidth() < character_enemy.GetLeft()) {
		character.SetTopLeft(character.GetLeft() + 1, character.GetTop());
		character_enemy.SetTopLeft(character_enemy.GetLeft() - 1, character_enemy.GetTop());
	}
	else {
		character.SetFrameIndexOfBitmap(1);
		character_enemy.SetFrameIndexOfBitmap(1);
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"resources/game_background.bmp",
		});
	background.SetTopLeft(0, 0);

	character.LoadBitmapByString({
		"resources/cat_1_inverse.bmp" , "resources/cat_2_inverse.bmp" , "resources/cat_3_inverse.bmp" , 
		});
	character.SetTopLeft(0, 30);
	character.SetAnimation(300, 0);
	
	character_enemy.LoadBitmapByString({
		"resources/cat_1.bmp" , "resources/cat_2.bmp" , "resources/cat_3.bmp" ,
		});
	character_enemy.SetTopLeft(1000, 30);
	character_enemy.SetAnimation(300, 0);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	background.ShowBitmap();
	character.ShowBitmap();
	character_enemy.ShowBitmap();
}
