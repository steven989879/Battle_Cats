#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "../../monster.h"
#include "../../cat_one.h"
#include "../../cat_factory.h"
#include "../../enemy_one.h"

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
	if (call_cat_number > 0) {
		character_call_cat_1.SetFrameIndexOfBitmap(1);
	}
	else {
		character_call_cat_1.SetFrameIndexOfBitmap(0);
	}

	/*
	if (cat_one_friend[cat_one_friend.size() - 1]->GetLeft() + 60 + cat_one_friend[cat_one_friend.size() - 1]->GetWidth() != character_enemy.GetLeft() && cat_one_friend[cat_one_friend.size() - 1]->GetLeft() + 60 + cat_one_friend[cat_one_friend.size() - 1]->GetWidth() < character_enemy.GetLeft()) {
		cat_one_friend[cat_one_friend.size() - 1]->SetTopLeft(cat_one_friend[cat_one_friend.size() - 1]->GetLeft() + 1, cat_one_friend[cat_one_friend.size() - 1]->GetTop());
	}
	*/

	if (cat_one_friend.size() >= 1) {
		for (int i = 0,t = 0; i < cat_one_friend.size(); i++) {
			if (character.GetLeft() + 50 + character.GetWidth() != cat_one_friend[i]->GetLeft() && character.GetLeft() + 50 + character.GetWidth() < cat_one_friend[i]->GetLeft()) {
				cat_one_friend[i]->SetTopLeft(cat_one_friend[i]->GetLeft() - 2, cat_one_friend[i]->GetTop());
				if (t == 0) {
					character.SetTopLeft(character.GetLeft() + 1, character.GetTop());
					t = 1;
				}
			}
			else {
				cat_one_friend[i]->SetFrameIndexOfBitmap(1);
				if (t == 0) {
					character.SetFrameIndexOfBitmap(1);
					t = 1;
				}
			}
		}
<<<<<<< HEAD
		// 敵對貓自動生成 待修 
		/*
		enemy_one *enemy1 = new enemy_one();
		enemy_one_v.push_back(enemy1);
		enemy_one_v[enemy_one_v.size() - 1]->set_name(enemy_one_v.size());
		enemy_one_v[enemy_one_v.size() - 1]->LoadBitmapByString({
		"resources/cat_walk_1_inverse.bmp" , "resources/cat_walk_2_inverse.bmp" , "resources/cat_walk_3_inverse.bmp" , "resources/cat_walk_2_inverse.bmp"
			}, RGB(255, 255, 255));
		enemy_one_v[enemy_one_v.size() - 1]->SetTopLeft(400, 420);
		enemy_one_v[enemy_one_v.size() - 1]->SetAnimation(250, 0);
		*/
=======
	}
>>>>>>> d55ef94ff7d55386158a0970df970153883aafd9
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"resources/game_background_1.bmp",
		});
	background.SetTopLeft(0, 0);

	character_call_cat_1.LoadBitmapByString({
		"resources/call_cat_2.bmp" , "resources/call_cat_1.bmp" ,
		}, RGB(255, 255, 255));
	character_call_cat_1.SetTopLeft(470, 680);

	character_call_cat_2.LoadBitmapByString({
		"resources/call_cat_empty.bmp" , 
		}, RGB(255, 255, 255));
	character_call_cat_2.SetTopLeft(625, 680);

	character_call_cat_3.LoadBitmapByString({
		"resources/call_cat_empty.bmp" ,
		}, RGB(255, 255, 255));
	character_call_cat_3.SetTopLeft(780, 680);

	character_call_cat_4.LoadBitmapByString({
		"resources/call_cat_empty.bmp" ,
		}, RGB(255, 255, 255));
	character_call_cat_4.SetTopLeft(935, 680);

	character_call_cat_5.LoadBitmapByString({
		"resources/call_cat_empty.bmp" ,
		}, RGB(255, 255, 255));
	character_call_cat_5.SetTopLeft(1090, 680);

	character_tower_1.LoadBitmapByString({
		"resources/tower_1.bmp" ,
		}, RGB(255, 255, 255));
	character_tower_1.SetTopLeft(1400, 175);

	character_tower_2.LoadBitmapByString({
		"resources/tower_2.bmp" ,
		}, RGB(255, 255, 255));
	character_tower_2.SetTopLeft(100, 163);

	character.LoadBitmapByString({
		"resources/dog_walk_1.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_3.bmp" ,"resources/dog_walk_2.bmp" 
		}, RGB(255, 255, 255));
	character.SetTopLeft(285, 430);
	character.SetAnimation(250, 0);

	character_attack.LoadBitmapByString({
		"resources/dog_attack_1.bmp" , "resources/dog_attack_2.bmp" , "resources/dog_attack_1.bmp" , "resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" ,
		"resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" ,
		"resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , 
		}, RGB(255, 255, 255));

	character_bump.LoadBitmapByString({
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_1_inverse.bmp" , "resources/bump_2_inverse.bmp" , "resources/bump_3_inverse.bmp" ,
		"resources/bump_4_inverse.bmp" , "resources/bump_5_inverse.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
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
	if (point.x >= 470 && point.x <= 614 && point.y >= 680 && point.y <= 789) {
		cat_one_friend_type.push_back(0);

		cat_one *temp1 = new cat_one();
		cat_one_friend.push_back(temp1);
		cat_one_friend[cat_one_friend.size() - 1]->set_name(cat_one_friend.size());
		cat_one_friend[cat_one_friend.size() - 1]->LoadBitmapByString({
		"resources/cat_walk_1.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_3.bmp" , "resources/cat_walk_2.bmp"
			}, RGB(255, 255, 255));
		cat_one_friend[cat_one_friend.size() - 1]->SetTopLeft(1300, 430);
		cat_one_friend[cat_one_friend.size() - 1]->SetAnimation(125, 0);

		cat_one *attack1 = new cat_one();
		cat_one_friend_attack.push_back(attack1);
		cat_one_friend_attack[cat_one_friend_attack.size() - 1]->set_name(cat_one_friend_attack.size());
		cat_one_friend_attack[cat_one_friend_attack.size() - 1]->LoadBitmapByString({
		"resources/cat_attack_1.bmp" , "resources/cat_attack_2.bmp" , "resources/cat_attack_1.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" ,
		"resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_2.bmp" ,
			}, RGB(255, 255, 255));

		cat_one *bump1 = new cat_one();
		cat_one_friend_bump.push_back(bump1);
		cat_one_friend_bump[cat_one_friend_bump.size() - 1]->set_name(cat_one_friend_bump.size());
		cat_one_friend_bump[cat_one_friend_bump.size() - 1]->LoadBitmapByString({
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_1.bmp" , "resources/bump_2.bmp" , "resources/bump_3.bmp" ,
		"resources/bump_4.bmp" , "resources/bump_5.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
			}, RGB(255, 255, 255));
	}
	if (point.x >= 470 && point.x <= 614 && point.y >= 680 && point.y <= 789) {
		call_cat_number += 1;
	}
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
	character_call_cat_1.ShowBitmap();
	character_call_cat_2.ShowBitmap();
	character_call_cat_3.ShowBitmap();
	character_call_cat_4.ShowBitmap();
	character_call_cat_5.ShowBitmap();
	character_tower_1.ShowBitmap();
	character_tower_2.ShowBitmap();
	int j = 0;
	if (cat_one_friend.size() >= 1) {
		for (int i = 0,t = 0; i < cat_one_friend.size(); i++) {
			if (character.GetLeft() + 50 + character.GetWidth() != cat_one_friend[i]->GetLeft() && character.GetLeft() + 50 + character.GetWidth() < cat_one_friend[i]->GetLeft()) {
				if (cat_one_friend_type[i] == 1) {
					cat_one_friend[i]->SetTopLeft(cat_one_friend_attack[i]->GetLeft(), cat_one_friend_attack[i]->GetTop());
					cat_one_friend[i]->SetAnimation(125, 0);
					cat_one_friend_type[i] = 0;
				}
				if (t == 0) {
					if (j == 1) {
						character.SetTopLeft(character_attack.GetLeft(), character_attack.GetTop());
						j = 0;
					}
					character.ShowBitmap();
					t = 1;
				}
				cat_one_friend[i]->ShowBitmap();
			}
			else {
				if (cat_one_friend_type[i] == 0) {
					cat_one_friend_attack[i]->SetTopLeft(cat_one_friend[i]->GetLeft(), cat_one_friend[i]->GetTop());
					cat_one_friend_attack[i]->SetAnimation(100, 0);
					cat_one_friend_bump[i]->SetTopLeft(cat_one_friend[i]->GetLeft() - 150, cat_one_friend[i]->GetTop() - 25);
					cat_one_friend_bump[i]->SetAnimation(100, 0);
					cat_one_friend_type[i] = 1;
				}
				cat_one_friend_attack[i]->ShowBitmap();
				if (t == 0) {
					if (j == 0) {
						character_attack.SetTopLeft(character.GetLeft(), character.GetTop());
						character_attack.SetAnimation(150, 0);
						character_bump.SetTopLeft(character.GetLeft() + 100, character.GetTop() - 25);
						character_bump.SetAnimation(150, 0);
						j = 1;
					}
					character_attack.ShowBitmap();
					t = 1;
				}
				character_bump.ShowBitmap();
				cat_one_friend_bump[i]->ShowBitmap();
			}
		}
	}
<<<<<<< HEAD

	if (enemy_one_v.size() >= 1) {
		for (int i = 0; i < enemy_one_v.size(); i++) {
			enemy_one_v[i]->ShowBitmap();
		}
	}
=======
>>>>>>> d55ef94ff7d55386158a0970df970153883aafd9
}
