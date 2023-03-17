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
	if (character.GetLeft() + 60 + character.GetWidth() != character_enemy.GetLeft() && character.GetLeft() + 60 + character.GetWidth() < character_enemy.GetLeft()) {
		character.SetTopLeft(character.GetLeft() + 1, character.GetTop());
		character_enemy.SetTopLeft(character_enemy.GetLeft() - 1, character_enemy.GetTop());
	}
	else {
		character_cat_1.SetAnimation(200, 0);
		character_cat_2.SetAnimation(100, 0);
		character_cat_2_bump.SetAnimation(100, 0);
		character.SetFrameIndexOfBitmap(1);
		character_enemy.SetFrameIndexOfBitmap(1);
		
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"resources/game_background_1.bmp",
		});
	background.SetTopLeft(0, 0);

	character.LoadBitmapByString({
		"resources/cat_walk_1_inverse.bmp" , "resources/cat_walk_2_inverse.bmp" , "resources/cat_walk_3_inverse.bmp" ,"resources/cat_walk_2_inverse.bmp" 
		}, RGB(255, 255, 255));
	character.SetTopLeft(0, 420);
	character.SetAnimation(250, 0);

	character_enemy.LoadBitmapByString({
		"resources/cat_walk_1.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_3.bmp" , "resources/cat_walk_2.bmp" ,
		}, RGB(255, 255, 255));
	character_enemy.SetTopLeft(1000, 420);
	character_enemy.SetAnimation(250, 0);

	character_cat_1.LoadBitmapByString({
		"resources/cat_attack_1_inverse.bmp" , "resources/cat_attack_2_inverse.bmp" , "resources/cat_attack_1_inverse.bmp" , "resources/cat_attack_3_origin_inverse.bmp" , "resources/cat_attack_4_origin_inverse.bmp" , "resources/cat_attack_5_origin_inverse.bmp" ,
		"resources/cat_attack_6_origin_inverse.bmp" , "resources/cat_attack_7_origin_inverse.bmp" , "resources/cat_attack_8_inverse.bmp" , "resources/cat_attack_8_inverse.bmp" , "resources/cat_attack_8_inverse.bmp" , "resources/cat_attack_8_inverse.bmp" ,
		}, RGB(255, 255, 255));
	

	character_cat_2.LoadBitmapByString({
		"resources/cat_attack_1.bmp" , "resources/cat_attack_2.bmp" , "resources/cat_attack_1.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_attack_4.bmp" , "resources/cat_attack_5.bmp" ,
		"resources/cat_attack_6.bmp" , "resources/cat_attack_7.bmp" , "resources/cat_attack_8.bmp" , "resources/cat_attack_8.bmp" , "resources/cat_attack_8.bmp" , "resources/cat_attack_8.bmp" ,
		}, RGB(255, 255, 255));

	character_cat_2_bump.LoadBitmapByString({
		"resources/cat_attack_0_bump.bmp" , "resources/cat_attack_0_bump.bmp" , "resources/cat_attack_0_bump.bmp" , "resources/cat_attack_3_bump.bmp" , "resources/cat_attack_4_bump.bmp" , "resources/cat_attack_5_bump.bmp" ,
		"resources/cat_attack_6_bump.bmp" , "resources/cat_attack_7_bump.bmp" , "resources/cat_attack_0_bump.bmp" , "resources/cat_attack_0_bump.bmp" , "resources/cat_attack_0_bump.bmp" , "resources/cat_attack_0_bump.bmp" ,
		}, RGB(255, 255, 255));

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
	int i=0;
	background.ShowBitmap();
	if (character.GetLeft() + 60 + character.GetWidth() != character_enemy.GetLeft() && character.GetLeft() + 60 + character.GetWidth() < character_enemy.GetLeft()) {
		if (i == 1) {
			character.SetTopLeft(character_cat_1.GetLeft(), 420);
			character_enemy.SetTopLeft(character_cat_2.GetLeft(), 420);
			i = 0;
		}
		character.ShowBitmap();
		character_enemy.ShowBitmap();
	}
	else {
		if (i == 0) {
			character_cat_1.SetTopLeft(character.GetLeft(), 420);
			character_cat_2.SetTopLeft(character_enemy.GetLeft(), 420);
			character_cat_2_bump.SetTopLeft(character_enemy.GetLeft() - 162, 420);
			i = 1;
		}
		character_cat_2.ShowBitmap();
		character_cat_1.ShowBitmap();
		character_cat_2_bump.ShowBitmap();
	}
}
