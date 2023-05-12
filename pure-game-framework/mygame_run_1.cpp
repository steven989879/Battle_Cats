#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "./Source/Game/mygame.h"
#include "../../monster.h"
#include <string>
#include <ctime>
using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun_1::CGameStateRun_1(CGame *g) : CGameState(g)
{
}

CGameStateRun_1::~CGameStateRun_1()
{
}

void CGameStateRun_1::OnBeginState()
{
}

void CGameStateRun_1::OnMove()							// 移動遊戲元素
{
	/////////////////////////////////////
	// 設定敵對生物及貓咪移動停止參數
	/////////////////////////////////////
	for (int d = 0; d < enemy_one_v.size(); d++) {
		int t = 0;
		for (int i = 0; i < cat_one_friend.size(); i++) {
			if (enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < cat_one_friend[i].GetLeft() || cat_one_friend_if_death[i]) {
				t += 1;
			}
		}
		if ((t == cat_one_friend.size() || cat_one_friend.size() == 0) && enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < character_tower_1.GetLeft() && enemy_one_v[d].get_type() != 2 && !(enemy_one_v_if_death[d])) {
			enemy_one_v[d].SetTopLeft(enemy_one_v[d].GetLeft() + 1, enemy_one_v[d].GetTop());
		}
		else {
			enemy_one_v[d].SetFrameIndexOfBitmap(1);
		}
	}

	for (int i = 0; i < cat_one_friend.size(); i++) {
		int t = 0;
		for (int d = 0; d < enemy_one_v.size(); d++) {
			if (enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < cat_one_friend[i].GetLeft() || enemy_one_v_if_death[d]) {
				t += 1;
			}
		}
		if ((t == enemy_one_v.size() || enemy_one_v.size() == 0) && cat_one_friend[i].GetLeft() > character_tower_2.GetLeft() + 50 + character_tower_2.GetWidth() && cat_one_friend[i].get_type() != 2) {
			cat_one_friend[i].SetTopLeft(cat_one_friend[i].GetLeft() - 2, cat_one_friend[i].GetTop());
		}
		else {
			cat_one_friend[i].SetFrameIndexOfBitmap(1);
		}
	}
	// 錢
	if (money_30 < max_money_30) {
		money += money_persecond;
	}
	money_30 = money / 30;
	if (money_30 >= base_1.get_price() && cat_1_cool.GetFrameIndexOfBitmap() == 24) {
		character_call_cat_1.SetFrameIndexOfBitmap(0);
	}

	///////////////////////
	// 敵對生物自動生成
	///////////////////////
	if (enemy - 450 >= 0) {        // 計數達指定次數生成敵對生物
		enemy_one_v_if_death.push_back(false);

		monster enemy1(11);
		enemy_one_v.push_back(enemy1);
		enemy_one_v[enemy_one_v.size() - 1].LoadBitmapByString({
		"resources/dog_walk_1.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_3.bmp" , "resources/dog_walk_2.bmp"        // 載入敵對狗走路動畫
			}, RGB(255, 255, 255));
		enemy_one_v[enemy_one_v.size() - 1].SetTopLeft(170, 430);
		enemy_one_v[enemy_one_v.size() - 1].SetAnimation(250, 0);

		enemy_one_v[enemy_one_v.size() - 1].attack.LoadBitmapByString({
		"resources/dog_attack_1.bmp" , "resources/dog_attack_2.bmp" , "resources/dog_attack_1.bmp" ,
		"resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" ,
		"resources/dog_attack_3.bmp" , "resources/dog_attack_3.bmp" , "resources/dog_walk_2.bmp" ,
		"resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" ,
		"resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" ,
		"resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp" , "resources/dog_walk_2.bmp"        // 載入敵對狗攻擊動畫
			}, RGB(255, 255, 255));

		enemy_one_v[enemy_one_v.size() - 1].bump.LoadBitmapByString({
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_1_inverse.bmp" , "resources/bump_2_inverse.bmp" , "resources/bump_3_inverse.bmp" ,
		"resources/bump_4_inverse.bmp" , "resources/bump_5_inverse.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp"        // 載入敵對狗攻擊爆炸動畫
			}, RGB(255, 255, 255));

		monster enemy1_back(11);
		enemy_one_v_back.push_back(enemy1_back);
		enemy_one_v_back[enemy_one_v_back.size() - 1].LoadBitmapByString({
		"resources/dog_back_0.bmp" , "resources/dog_back_1.bmp" , "resources/dog_back_2.bmp" ,
		"resources/dog_back_3.bmp" , "resources/dog_back_4.bmp" , "resources/dog_back_5.bmp" ,
		"resources/dog_back_6.bmp" , "resources/dog_back_7.bmp" , "resources/dog_back_8.bmp" ,
		"resources/dog_back_9.bmp" , "resources/dog_back_10.bmp" , "resources/dog_back_11.bmp" ,
		"resources/dog_back_12.bmp" , "resources/dog_back_13.bmp" , "resources/dog_back_14.bmp" ,
		"resources/dog_back_15.bmp" , "resources/dog_back_16.bmp" , "resources/dog_back_17.bmp" ,
		"resources/dog_back_18.bmp" , "resources/dog_back_19.bmp" , "resources/dog_back_20.bmp" ,
		"resources/dog_back_21.bmp" , "resources/dog_back_22.bmp" , "resources/dog_back_23.bmp" ,
		"resources/dog_back_24.bmp" , "resources/dog_back_25.bmp" , "resources/dog_back_26.bmp" ,
		"resources/dog_back_27.bmp" , "resources/dog_back_28.bmp" , "resources/dog_back_29.bmp" ,
		"resources/dog_back_30.bmp" , "resources/dog_back_31.bmp" , "resources/dog_back_32.bmp" ,
		"resources/dog_back_33.bmp" , "resources/dog_back_34.bmp" , "resources/dog_back_35.bmp"
			}, RGB(255, 255, 255));

		monster enemy1_death(11);
		enemy_one_v_death.push_back(enemy1_death);
		enemy_one_v_death[enemy_one_v_death.size() - 1].LoadBitmapByString({
		"resources/death_1.bmp" , "resources/death_2.bmp" , "resources/death_3.bmp" ,
		"resources/death_4.bmp" , "resources/death_5.bmp" , "resources/death_6.bmp" ,
		"resources/death_7.bmp" , "resources/death_8.bmp" , "resources/death_9.bmp" ,
		"resources/death_10.bmp" , "resources/death_11.bmp" , "resources/death_12.bmp" ,
		"resources/death_13.bmp" , "resources/death_14.bmp" , "resources/death_15.bmp" ,
		"resources/death_16.bmp" , "resources/death_17.bmp" , "resources/death_18.bmp" ,
		"resources/death_19.bmp" , "resources/death_20.bmp" , "resources/death_21.bmp" ,
		"resources/death_22.bmp" , "resources/death_23.bmp" , "resources/death_24.bmp" ,
		"resources/death_25.bmp" , "resources/death_26.bmp" , "resources/death_27.bmp" ,
		"resources/death_28.bmp" , "resources/death_29.bmp" , "resources/death_30.bmp" ,
		"resources/death_31.bmp" , "resources/death_32.bmp" , "resources/death_33.bmp" ,
		"resources/death_34.bmp" , "resources/death_35.bmp" , "resources/death_36.bmp" ,
		"resources/death_37.bmp" , "resources/death_38.bmp" , "resources/death_39.bmp" ,
		"resources/death_40.bmp" , "resources/death_41.bmp" , "resources/death_42.bmp" ,
		"resources/death_43.bmp" , "resources/death_44.bmp" , "resources/death_45.bmp" ,
		"resources/death_46.bmp" , "resources/death_47.bmp" , "resources/death_48.bmp" ,
		"resources/death_49.bmp" , "resources/death_50.bmp" , "resources/death_51.bmp" ,
		"resources/death_52.bmp" , "resources/death_53.bmp" , "resources/death_54.bmp" ,
		"resources/death_55.bmp" , "resources/death_56.bmp" , "resources/death_57.bmp" ,
		"resources/death_58.bmp" , "resources/death_59.bmp" , "resources/death_60.bmp" ,
		"resources/death_61.bmp"
			}, RGB(255, 255, 255));


		enemy = 0;        // 計數歸零
	}
	enemy += 1;        // 時間計數每秒+30
}

void CGameStateRun_1::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"resources/game_background_1.bmp"        // 載入關卡背景
		});
	background.SetTopLeft(0, 0);

	money_map.LoadBitmapByString({
		"resources/money.bmp"
		}, RGB(255, 255, 255));
	money_map.SetTopLeft(1505, 10);

	////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////
	Level_dark.LoadBitmapByString({
		"resources/Level_1_dark.bmp" , "resources/Level_2_dark.bmp" , "resources/Level_3_dark.bmp" ,
		"resources/Level_4_dark.bmp" , "resources/Level_5_dark.bmp" , "resources/Level_6_dark.bmp" ,
		"resources/Level_7_dark.bmp" , "resources/Level_8.bmp"
		}, RGB(255, 255, 255));
	Level_dark.SetTopLeft(50, 636);

	Level_shine[0].LoadBitmapByString({
		"resources/Level_1_shine_1.bmp" , "resources/Level_1_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[0].SetTopLeft(50, 636);

	Level_shine[1].LoadBitmapByString({
		"resources/Level_2_shine_1.bmp" , "resources/Level_2_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[1].SetTopLeft(50, 636);

	Level_shine[2].LoadBitmapByString({
		"resources/Level_3_shine_1.bmp" , "resources/Level_3_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[2].SetTopLeft(50, 636);

	Level_shine[3].LoadBitmapByString({
		"resources/Level_4_shine_1.bmp" , "resources/Level_4_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[3].SetTopLeft(50, 636);

	Level_shine[4].LoadBitmapByString({
		"resources/Level_5_shine_1.bmp" , "resources/Level_5_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[4].SetTopLeft(50, 636);

	Level_shine[5].LoadBitmapByString({
		"resources/Level_6_shine_1.bmp" , "resources/Level_6_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[5].SetTopLeft(50, 636);

	Level_shine[6].LoadBitmapByString({
		"resources/Level_7_shine_1.bmp" , "resources/Level_7_shine_2.bmp"
		}, RGB(255, 255, 255));
	Level_shine[6].SetTopLeft(50, 636);
	////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////

	character_call_cat_1.LoadBitmapByString({
		"resources/call_cat_2.bmp" , "resources/call_cat_1.bmp" , "resources/call_cat_load.bmp"        // 載入招喚貓咪1按鈕
		}, RGB(255, 255, 255));
	character_call_cat_1.SetTopLeft(470, 680);
	character_call_cat_1.SetFrameIndexOfBitmap(1);

	cat_1_cool.LoadBitmapByString({
		"resources/load_1.bmp" , "resources/load_2.bmp" , "resources/load_3.bmp" ,
		"resources/load_4.bmp" , "resources/load_5.bmp" , "resources/load_6.bmp" ,
		"resources/load_7.bmp" , "resources/load_8.bmp" , "resources/load_9.bmp" ,
		"resources/load_10.bmp" , "resources/load_11.bmp" , "resources/load_12.bmp" ,
		"resources/load_13.bmp" , "resources/load_14.bmp" , "resources/load_15.bmp" ,
		"resources/load_16.bmp" , "resources/load_17.bmp" , "resources/load_18.bmp" ,
		"resources/load_19.bmp" , "resources/load_20.bmp" , "resources/load_21.bmp" ,
		"resources/load_22.bmp" , "resources/load_23.bmp" , "resources/load_24.bmp" ,
		"resources/load_25.bmp"
		}, RGB(255, 255, 255));
	cat_1_cool.SetTopLeft(477, 757);
	cat_1_cool.SetFrameIndexOfBitmap(24);

	character_call_cat_2.LoadBitmapByString({
		"resources/call_cat_empty.bmp"        // 載入召喚貓咪2(空)按鈕
		}, RGB(255, 255, 255));
	character_call_cat_2.SetTopLeft(625, 680);

	character_call_cat_3.LoadBitmapByString({
		"resources/call_cat_empty.bmp"        // 載入召喚貓咪3(空)按鈕
		}, RGB(255, 255, 255));
	character_call_cat_3.SetTopLeft(780, 680);

	character_call_cat_4.LoadBitmapByString({
		"resources/call_cat_empty.bmp"        // 載入召喚貓咪4(空)按鈕
		}, RGB(255, 255, 255));
	character_call_cat_4.SetTopLeft(935, 680);

	character_call_cat_5.LoadBitmapByString({
		"resources/call_cat_empty.bmp"        // 載入召喚貓咪5(空)按鈕
		}, RGB(255, 255, 255));
	character_call_cat_5.SetTopLeft(1090, 680);

	character_tower_1.LoadBitmapByString({
		"resources/tower_1.bmp"        // 載入己方防禦塔
		}, RGB(255, 255, 255));
	character_tower_1.SetTopLeft(1400, 175);

	character_tower_2.LoadBitmapByString({
		"resources/tower_2.bmp"        // 載入敵方防禦塔
		}, RGB(255, 255, 255));
	character_tower_2.SetTopLeft(100, 163);

	esc.LoadBitmapByString({
		"resources/esc.bmp"        // 載入敵方防禦塔
		}, RGB(255, 255, 255));
	esc.SetTopLeft(0, 0);

	base_1 = monster(1);

	base_11 = monster(11);

	friend_tower = 1000;
	enemy_tower = 500;
}

void CGameStateRun_1::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) // 按esc快速返回
{
	if (nChar == VK_ESCAPE) {
		//esc.ShowBitmap();
		GotoGameState(GAME_STATE_RUN);
	}
}

void CGameStateRun_1::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun_1::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	///////////////////////////////////
	// 藉由點擊次數生成相應數量貓咪
	///////////////////////////////////
	if (point.x >= 470 && point.x <= 614 && point.y >= 680 && point.y <= 789 && money_30 >= base_1.get_price() && cat_1_cool.GetFrameIndexOfBitmap() == 24) {
		money_30 = money_30 - base_1.get_price();
		money = money - (base_1.get_price() * 30);
		character_call_cat_1.SetFrameIndexOfBitmap(2);
		cat_1_cool.SetFrameIndexOfBitmap(0);
		cat_1_cool.SetAnimation(250, 0);
		cat_one_friend_if_death.push_back(false);

		monster temp1(1);
		cat_one_friend.push_back(temp1);
		cat_one_friend[cat_one_friend.size() - 1].LoadBitmapByString({
		"resources/cat_walk_1.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_3.bmp" , "resources/cat_walk_2.bmp"        // 載入貓咪1走路動畫
			}, RGB(255, 255, 255));
		cat_one_friend[cat_one_friend.size() - 1].SetTopLeft(1400, 430);
		cat_one_friend[cat_one_friend.size() - 1].SetAnimation(125, 0);

		cat_one_friend[cat_one_friend.size() - 1].attack.LoadBitmapByString({
		"resources/cat_attack_1.bmp" , "resources/cat_attack_2.bmp" , "resources/cat_attack_1.bmp" ,
		"resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" ,
		"resources/cat_attack_3.bmp" , "resources/cat_attack_3.bmp" , "resources/cat_walk_2.bmp" ,
		"resources/cat_walk_2.bmp" , "resources/cat_walk_2.bmp" , "resources/cat_walk_2.bmp"        // 載入貓咪1攻擊動畫
			}, RGB(255, 255, 255));

		cat_one_friend[cat_one_friend.size() - 1].bump.LoadBitmapByString({
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_1.bmp" , "resources/bump_2.bmp" , "resources/bump_3.bmp" ,
		"resources/bump_4.bmp" , "resources/bump_5.bmp" , "resources/bump_0.bmp" ,
		"resources/bump_0.bmp" , "resources/bump_0.bmp" , "resources/bump_0.bmp"        // 載入貓咪1攻擊爆炸動畫
			}, RGB(255, 255, 255));

		monster back1(1);
		cat_one_friend_back.push_back(back1);
		cat_one_friend_back[cat_one_friend_back.size() - 1].LoadBitmapByString({
		"resources/cat_back_0.bmp" , "resources/cat_back_1.bmp" , "resources/cat_back_2.bmp" ,
		"resources/cat_back_3.bmp" , "resources/cat_back_4.bmp" , "resources/cat_back_5.bmp" ,
		"resources/cat_back_6.bmp" , "resources/cat_back_7.bmp" , "resources/cat_back_8.bmp" ,
		"resources/cat_back_9.bmp" , "resources/cat_back_10.bmp" , "resources/cat_back_11.bmp" ,
		"resources/cat_back_12.bmp" , "resources/cat_back_13.bmp" , "resources/cat_back_14.bmp" ,
		"resources/cat_back_15.bmp" , "resources/cat_back_16.bmp" , "resources/cat_back_17.bmp" ,
		"resources/cat_back_18.bmp" , "resources/cat_back_19.bmp" , "resources/cat_back_20.bmp" ,
		"resources/cat_back_21.bmp" , "resources/cat_back_22.bmp" , "resources/cat_back_23.bmp" ,
		"resources/cat_back_24.bmp" , "resources/cat_back_25.bmp" , "resources/cat_back_26.bmp" ,
		"resources/cat_back_27.bmp" , "resources/cat_back_28.bmp" , "resources/cat_back_29.bmp" ,
		"resources/cat_back_30.bmp" , "resources/cat_back_31.bmp" , "resources/cat_back_32.bmp" ,
		"resources/cat_back_33.bmp" , "resources/cat_back_34.bmp" , "resources/cat_back_35.bmp"
			}, RGB(255, 255, 255));

		monster death1(1);
		cat_one_friend_death.push_back(death1);
		cat_one_friend_death[cat_one_friend_death.size() - 1].LoadBitmapByString({
		"resources/death_1.bmp" , "resources/death_2.bmp" , "resources/death_3.bmp" ,
		"resources/death_4.bmp" , "resources/death_5.bmp" , "resources/death_6.bmp" ,
		"resources/death_7.bmp" , "resources/death_8.bmp" , "resources/death_9.bmp" ,
		"resources/death_10.bmp" , "resources/death_11.bmp" , "resources/death_12.bmp" ,
		"resources/death_13.bmp" , "resources/death_14.bmp" , "resources/death_15.bmp" ,
		"resources/death_16.bmp" , "resources/death_17.bmp" , "resources/death_18.bmp" ,
		"resources/death_19.bmp" , "resources/death_20.bmp" , "resources/death_21.bmp" ,
		"resources/death_22.bmp" , "resources/death_23.bmp" , "resources/death_24.bmp" ,
		"resources/death_25.bmp" , "resources/death_26.bmp" , "resources/death_27.bmp" ,
		"resources/death_28.bmp" , "resources/death_29.bmp" , "resources/death_30.bmp" ,
		"resources/death_31.bmp" , "resources/death_32.bmp" , "resources/death_33.bmp" ,
		"resources/death_34.bmp" , "resources/death_35.bmp" , "resources/death_36.bmp" ,
		"resources/death_37.bmp" , "resources/death_38.bmp" , "resources/death_39.bmp" ,
		"resources/death_40.bmp" , "resources/death_41.bmp" , "resources/death_42.bmp" ,
		"resources/death_43.bmp" , "resources/death_44.bmp" , "resources/death_45.bmp" ,
		"resources/death_46.bmp" , "resources/death_47.bmp" , "resources/death_48.bmp" ,
		"resources/death_49.bmp" , "resources/death_50.bmp" , "resources/death_51.bmp" ,
		"resources/death_52.bmp" , "resources/death_53.bmp" , "resources/death_54.bmp" ,
		"resources/death_55.bmp" , "resources/death_56.bmp" , "resources/death_57.bmp" ,
		"resources/death_58.bmp" , "resources/death_59.bmp" , "resources/death_60.bmp" ,
		"resources/death_61.bmp"
			}, RGB(255, 255, 255));
	}

	if (point.x > 50 && point.x < 292 && point.y > 636 && point.y < 800 && money_30 >= now_Level * 40 && now_Level < 8) {
		money_persecond += 1;
		max_money_30 += 50;
		money_30 -= now_Level * 40;
		money -= (now_Level * 40 * 30);
		Level_shine[now_Level - 1].SetFrameIndexOfBitmap(0);
		now_Level += 1;
		Level_dark.SetFrameIndexOfBitmap(now_Level - 1);
	}
}

void CGameStateRun_1::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun_1::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun_1::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun_1::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun_1::OnShow()
{
	background.ShowBitmap();        // 顯示關卡背景
	money_map.ShowBitmap();
	if (money_30 < now_Level * 40 && now_Level <= 8) {
		Level_dark.ShowBitmap();
	}
	else if (money_30 >= now_Level * 40 && now_Level < 8) {
		Level_shine[now_Level - 1].SetAnimation(100, 0);
		Level_shine[now_Level - 1].ShowBitmap();
	}
	draw_text();
	if (cat_1_cool.GetFrameIndexOfBitmap() > 23) {        // 顯示招喚貓咪1按鈕與冷卻
		if (money_30 < base_1.get_price()) {
			character_call_cat_1.SetFrameIndexOfBitmap(1);
		}
		character_call_cat_1.ShowBitmap();
		cat_1_cool.SetFrameIndexOfBitmap(24);
	}
	else {
		character_call_cat_1.ShowBitmap();
		cat_1_cool.ShowBitmap();
	}

	character_call_cat_2.ShowBitmap();        // 顯示召喚貓咪2(空)按鈕
	character_call_cat_3.ShowBitmap();        // 顯示召喚貓咪3(空)按鈕
	character_call_cat_4.ShowBitmap();        // 顯示召喚貓咪4(空)按鈕
	character_call_cat_5.ShowBitmap();        // 顯示召喚貓咪5(空)按鈕
	character_tower_1.ShowBitmap();        // 顯示己方防禦塔
	character_tower_2.ShowBitmap();        // 顯示敵方防禦塔

	///////////////////////////////////////////
	// 顯示敵對生物及貓咪所有動畫、動畫切換
	///////////////////////////////////////////
	for (int d = 0; d < enemy_one_v.size(); d++) {
		int t = 0;
		for (int i = 0; i < cat_one_friend.size(); i++) {
			if (enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < cat_one_friend[i].GetLeft() || cat_one_friend_if_death[i]) {
				t += 1;
			}
		}
		if ((t == cat_one_friend.size() || cat_one_friend.size() == 0) && enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < character_tower_1.GetLeft() && enemy_one_v[d].get_type() != 2) {
			if (enemy_one_v[d].get_type() == 1) {
				enemy_one_v[d].SetTopLeft(enemy_one_v[d].attack.GetLeft(), enemy_one_v[d].attack.GetTop());
				enemy_one_v[d].type = 0;
			}
			if (!(enemy_one_v_if_death[d])) {
				enemy_one_v[d].SetAnimation(250, 0);
				enemy_one_v[d].ShowBitmap();
			}
		}
		else {
			if (enemy_one_v[d].get_type() != 2 && !(enemy_one_v_if_death[d])) {
				if (enemy_one_v[d].get_type() == 0) {
					enemy_one_v[d].attack.SetTopLeft(enemy_one_v[d].GetLeft(), enemy_one_v[d].GetTop());
					enemy_one_v[d].type = 1;
				}
				enemy_one_v[d].attack.SetAnimation(100, 0);
				enemy_one_v[d].bump.SetTopLeft(enemy_one_v[d].GetLeft() + 100, enemy_one_v[d].GetTop() - 25);
				enemy_one_v[d].bump.SetAnimation(100, 0);
				enemy_one_v[d].bump.ShowBitmap();
				enemy_one_v[d].attack.SetAnimation(100, 0);
				enemy_one_v[d].attack.ShowBitmap();
				enemy_one_v[d].whether_attack = true;

				if (enemy_one_v[d].attack.GetFrameIndexOfBitmap() == 1) {
					enemy_one_v[d].if_attack = 0;
				}

				int now_position_cat;
				int now_position = 1900;

				for (int j = 0; j < cat_one_friend.size(); j++) {
					if (cat_one_friend[j].GetLeft() < now_position) {
						now_position = enemy_one_v[j].GetLeft() + enemy_one_v[j].GetWidth();
						now_position_cat = j;
					}
				}
				if (enemy_one_v[d].attack.GetFrameIndexOfBitmap() == 4 && enemy_one_v[d].get_type() == 1 && enemy_one_v[d].get_if_attack() == 0) { //設定攻擊動畫扣血
					if (cat_one_friend.size() > 0) {
						if (enemy_one_v[now_position_cat].GetLeft() > 1400) {
							friend_tower -= enemy_one_v[d].get_power();
							enemy_one_v[d].if_attack = 1;
							if (friend_tower <= 0) {
								GotoGameState(GAME_STATE_OVER);
							}
						}
						else {
							cat_one_friend[now_position_cat].heart -= enemy_one_v[now_position_cat].power;
							enemy_one_v[d].if_attack = 1;
							if (cat_one_friend[now_position_cat].heart <= 0) {
								enemy_one_v[d].attack.SetFrameIndexOfBitmap(0);
								enemy_one_v[d].bump.SetFrameIndexOfBitmap(0);
								cat_one_friend_if_death[now_position_cat] = true;
								cat_one_friend_back[now_position_cat].SetTopLeft(cat_one_friend[now_position_cat].GetLeft(), cat_one_friend[now_position_cat].GetTop() - 50);
								cat_one_friend_death[now_position_cat].SetTopLeft(cat_one_friend[now_position_cat].GetLeft() + 136, 0);
								cat_one_friend_back[now_position_cat].SetAnimation(20, 0);
								cat_one_friend.erase(cat_one_friend.begin() + now_position_cat);
							}
							else if (cat_one_friend[now_position_cat].heart <= 15 && cat_one_friend[now_position_cat].get_back_time() == 0) {
								cat_one_friend[now_position_cat].back_time = 1;
								cat_one_friend[now_position_cat].type = 2;
								enemy_one_v[d].attack.SetFrameIndexOfBitmap(0);
								enemy_one_v[d].bump.SetFrameIndexOfBitmap(0);
								cat_one_friend_back[now_position_cat].SetTopLeft(cat_one_friend[now_position_cat].GetLeft(), cat_one_friend[now_position_cat].GetTop() - 50);
								cat_one_friend[now_position_cat].SetTopLeft(cat_one_friend[now_position_cat].GetLeft() + 136, cat_one_friend[now_position_cat].GetTop());
								cat_one_friend[now_position_cat].attack.SetTopLeft(cat_one_friend[now_position_cat].GetLeft(), cat_one_friend[now_position_cat].GetTop());
								cat_one_friend[now_position_cat].attack.SetFrameIndexOfBitmap(0);
								cat_one_friend[now_position_cat].bump.SetFrameIndexOfBitmap(0);
								cat_one_friend_back[now_position_cat].SetAnimation(20, 0);
							}
						}
					}
					else {
						friend_tower -= enemy_one_v[d].get_power();
						enemy_one_v[d].if_attack = 1;
						if (friend_tower <= 0) {
							GotoGameState(GAME_STATE_OVER);
						}
					}
				}
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < cat_one_friend_back.size(); i++) {
		if (!(cat_one_friend_if_death[i])) {
			if (cat_one_friend_back[i].IsAnimation() && cat_one_friend[i].get_type() == 2) {
				cat_one_friend_back[i].ShowBitmap();
			}
			if (cat_one_friend_back[i].GetFrameIndexOfBitmap() > 33 && cat_one_friend[i].get_type() == 2) {
				cat_one_friend_back[i].SetFrameIndexOfBitmap(0);
				cat_one_friend[i].type = 1;
			}
		}
	}
	for (int i = 0; i < cat_one_friend_back.size(); i++) {
		if (cat_one_friend_back[i].IsAnimation() && cat_one_friend_if_death[i]) {
			cat_one_friend_back[i].ShowBitmap();
		}
		if (cat_one_friend_back[i].GetFrameIndexOfBitmap() > 33 && cat_one_friend_if_death[i]) {
			cat_one_friend_death[i].SetAnimation(15, 0);
			cat_one_friend_back.erase(cat_one_friend_back.begin() + i);
			cat_one_friend_if_death.erase(cat_one_friend_if_death.begin() + i);
			i -= 1;
		}
	}
	for (int i = 0; i < cat_one_friend_death.size(); i++) {
		if (cat_one_friend_death[i].IsAnimation()) {
			cat_one_friend_death[i].ShowBitmap();
		}
		if (cat_one_friend_death[i].GetFrameIndexOfBitmap() > 59) {
			cat_one_friend_death.erase(cat_one_friend_death.begin() + i);
			i -= 1;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < cat_one_friend.size(); i++) {
		int t = 0;
		for (int d = 0; d < enemy_one_v.size(); d++) {
			if (enemy_one_v[d].GetLeft() + 50 + enemy_one_v[d].GetWidth() < cat_one_friend[i].GetLeft() || enemy_one_v_if_death[d]) {
				t += 1;
			}
		}
		if ((t == enemy_one_v.size() || enemy_one_v.size() == 0) && cat_one_friend[i].GetLeft() > character_tower_2.GetLeft() + 50 + character_tower_2.GetWidth() && cat_one_friend[i].get_type() != 2) {
			if (cat_one_friend[i].get_type() == 1) {
				cat_one_friend[i].SetTopLeft(cat_one_friend[i].attack.GetLeft(), cat_one_friend[i].attack.GetTop());
				cat_one_friend[i].type = 0;
			}
			cat_one_friend[i].SetAnimation(125, 0);
			cat_one_friend[i].ShowBitmap();
		}
		else {
			if (cat_one_friend[i].get_type() != 2) {
				if (true) {
					cat_one_friend[i].attack.SetTopLeft(cat_one_friend[i].GetLeft(), cat_one_friend[i].GetTop());
					cat_one_friend[i].type = 1;
				}
				cat_one_friend[i].bump.SetTopLeft(cat_one_friend[i].GetLeft() - 150, cat_one_friend[i].GetTop() - 25);
				cat_one_friend[i].attack.SetAnimation(100, 0);
				cat_one_friend[i].bump.SetAnimation(100, 0);
				cat_one_friend[i].attack.ShowBitmap();
				cat_one_friend[i].bump.ShowBitmap();
				if (cat_one_friend[i].attack.GetFrameIndexOfBitmap() == 1) {
					cat_one_friend[i].if_attack = 0;
				}
				int now_position_enemy;
				int now_position = 0;

				for (int j = 0; j < enemy_one_v.size(); j++) {
					if (enemy_one_v[j].GetLeft() + enemy_one_v[j].GetWidth() > now_position) {
						now_position = enemy_one_v[j].GetLeft() + enemy_one_v[j].GetWidth();
						now_position_enemy = j;
					}
				}
				if (cat_one_friend[i].attack.GetFrameIndexOfBitmap() == 4 && cat_one_friend[i].get_type() == 1 && cat_one_friend[i].get_if_attack() == 0) { //設定攻擊動畫扣血	
					if (enemy_one_v.size() > 0) {
						if (enemy_one_v[now_position_enemy].GetLeft() < 100) {//如果都在塔後
							enemy_tower -= cat_one_friend[i].get_power();
							cat_one_friend[i].if_attack = 1;
							for (int j = 0; j < enemy_one_v.size(); j++) {
								if (enemy_one_v[j].GetLeft() + enemy_one_v[j].GetWidth() > cat_one_friend[i].GetLeft() - cat_one_friend[i].get_attack_range() && cat_one_friend[i].get_single_attack() == 1) {
									enemy_one_v[j].heart -= cat_one_friend[i].get_power();
								}
							}
							if (enemy_tower <= 0) {
								GotoGameState(GAME_STATE_OVER);
							}
						}
						else {
							if (cat_one_friend[i].get_single_attack() == 1) {
								enemy_one_v[now_position_enemy].heart -= cat_one_friend[i].power;
								cat_one_friend[i].if_attack = 1;
								if (enemy_one_v[now_position_enemy].heart <= 0 && !(enemy_one_v_if_death[now_position_enemy])) {
									cat_one_friend[i].attack.SetFrameIndexOfBitmap(0);
									cat_one_friend[i].bump.SetFrameIndexOfBitmap(0);
									enemy_one_v_if_death[now_position_enemy] = true;
									enemy_one_v_back[now_position_enemy].SetTopLeft(enemy_one_v[now_position_enemy].GetLeft() - 136, enemy_one_v[now_position_enemy].GetTop() - 50);
									enemy_one_v_death[now_position_enemy].SetTopLeft(enemy_one_v[now_position_enemy].GetLeft() - 136, 0);
									enemy_one_v_back[now_position_enemy].SetAnimation(20, 0);
									//enemy_one_v.erase(enemy_one_v.begin() + now_position_enemy);
								}
								else if (enemy_one_v[now_position_enemy].heart <= 15 && enemy_one_v[now_position_enemy].get_back_time() == 0) {
									enemy_one_v[now_position_enemy].back_time = 1;
									enemy_one_v[now_position_enemy].type = 2;
									cat_one_friend[i].attack.SetFrameIndexOfBitmap(0);
									cat_one_friend[i].bump.SetFrameIndexOfBitmap(0);
									enemy_one_v[now_position_enemy].SetTopLeft(enemy_one_v[now_position_enemy].GetLeft() - 136, enemy_one_v[now_position_enemy].GetTop());
									enemy_one_v[now_position_enemy].attack.SetTopLeft(enemy_one_v[now_position_enemy].GetLeft(), enemy_one_v[now_position_enemy].GetTop());
									enemy_one_v_back[now_position_enemy].SetTopLeft(enemy_one_v[now_position_enemy].GetLeft(), enemy_one_v[now_position_enemy].GetTop() - 50);
									enemy_one_v[now_position_enemy].attack.SetFrameIndexOfBitmap(0);
									enemy_one_v[now_position_enemy].bump.SetFrameIndexOfBitmap(0);
									enemy_one_v_back[now_position_enemy].SetAnimation(20, 0);
								}
							}
							else if (cat_one_friend[i].get_single_attack() == 0) {
								cat_one_friend[i].if_attack = 1;
								for (int j = 0; j < enemy_one_v.size(); j++) {
									if ((enemy_one_v[j].GetLeft() + enemy_one_v[j].GetWidth() > cat_one_friend[i].GetLeft() - cat_one_friend[i].get_attack_range()) && !(enemy_one_v_if_death[j])) {
										enemy_one_v[j].heart -= cat_one_friend[i].get_power();
									}

									if (enemy_one_v[j].heart <= 0 && !(enemy_one_v_if_death[j])) {

										cat_one_friend[i].attack.SetFrameIndexOfBitmap(0);
										cat_one_friend[i].bump.SetFrameIndexOfBitmap(0);
										enemy_one_v_if_death[j] = true;
										enemy_one_v_back[j].SetTopLeft(enemy_one_v[j].GetLeft() - 136, enemy_one_v[j].GetTop() - 50);
										enemy_one_v_death[j].SetTopLeft(enemy_one_v[j].GetLeft() - 136, 0);
										enemy_one_v[j].SetTopLeft(enemy_one_v[j].GetLeft() - 136, enemy_one_v[j].GetTop());
										enemy_one_v[j].attack.SetTopLeft(enemy_one_v[j].GetLeft(), enemy_one_v[j].GetTop());
										enemy_one_v[j].bump.SetTopLeft(enemy_one_v[j].GetLeft(), enemy_one_v[j].GetTop());
										enemy_one_v_back[j].SetAnimation(20, 0);
										enemy_one_v_back[j].ShowBitmap();
									}
									else if (enemy_one_v[j].heart <= 15 && enemy_one_v[j].get_back_time() == 0) {

										enemy_one_v[j].back_time = 1;
										enemy_one_v[j].type = 2;
										cat_one_friend[i].attack.SetFrameIndexOfBitmap(0);
										cat_one_friend[i].bump.SetFrameIndexOfBitmap(0);
										enemy_one_v[j].SetTopLeft(enemy_one_v[j].GetLeft() - 136, enemy_one_v[j].GetTop());
										enemy_one_v[j].attack.SetTopLeft(enemy_one_v[j].GetLeft(), enemy_one_v[j].GetTop());
										enemy_one_v_back[j].SetTopLeft(enemy_one_v[j].GetLeft(), enemy_one_v[j].GetTop() - 50);
										enemy_one_v[j].attack.SetFrameIndexOfBitmap(0);
										enemy_one_v[j].bump.SetFrameIndexOfBitmap(0);
										enemy_one_v_back[j].SetAnimation(20, 0);
									}
								}
							}
						}
					}
					else {
						enemy_tower -= cat_one_friend[i].get_power();
						cat_one_friend[i].if_attack = 1;
						if (enemy_tower <= 0) {
							GotoGameState(GAME_STATE_OVER);
						}
					}
				}
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////
	for (int d = 0; d < enemy_one_v_back.size(); d++) {
		if (!(enemy_one_v_if_death[d])) {
			if (enemy_one_v_back[d].IsAnimation() && enemy_one_v[d].get_type() == 2) {
				enemy_one_v_back[d].ShowBitmap();
			}
			if (enemy_one_v_back[d].GetFrameIndexOfBitmap() > 33 && enemy_one_v[d].get_type() == 2) {
				enemy_one_v_back[d].SetFrameIndexOfBitmap(0);
				enemy_one_v[d].type = 1;
			}
		}
	}
	for (int d = 0; d < enemy_one_v_back.size(); d++) {
		if (enemy_one_v_back[d].IsAnimation() && enemy_one_v_if_death[d] && enemy_one_v_back[d].GetFrameIndexOfBitmap() != 34) {
			enemy_one_v_back[d].ShowBitmap();
		}
		if (enemy_one_v_back[d].GetFrameIndexOfBitmap() > 33 && enemy_one_v_if_death[d]) {
			enemy_one_v_death[d].SetAnimation(15, 0);
			enemy_one_v_back[d].SetFrameIndexOfBitmap(34);
		}
	}
	for (int d = 0; d < enemy_one_v_death.size(); d++) {
		if (enemy_one_v_death[d].IsAnimation()) {
			enemy_one_v_death[d].ShowBitmap();
		}
		if (enemy_one_v_death[d].GetFrameIndexOfBitmap() > 59) {
			enemy_one_v_back.erase(enemy_one_v_back.begin() + d);
			enemy_one_v_if_death.erase(enemy_one_v_if_death.begin() + d);
			enemy_one_v.erase(enemy_one_v.begin() + d);
			enemy_one_v_death.erase(enemy_one_v_death.begin() + d);
			d -= 1;
		}
	}
	for (int d = 0; d < enemy_one_v.size(); d++) {
		if (enemy_one_v[d].get_whether_attack()) {
			enemy_one_v[d].bump.ShowBitmap();
			enemy_one_v[d].whether_attack = false;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////
}

void CGameStateRun_1::draw_text() {
	int Px = 1390;
	CDC *pDC = CDDraw::GetBackCDC();
	//CFont* fp;
	s = std::to_string(money_30);
	s2 = std::to_string(max_money_30);
	int move = 0;
	std::string  print = s + "/" + s2;
	CTextDraw::ChangeFontLog(pDC, 30, "Arial Black", RGB(255, 200, 0), 900);
	if (money_30 > 9) {
		Px -= 25;
		if (money_30 > 99) {
			Px -= 25;
		}
	}
	CTextDraw::Print(pDC, Px, 3, print);

	CTextDraw::ChangeFontLog(pDC, 20, "Arial Black", RGB(0, 0, 0), 900);
	show_friend_tower = std::to_string(friend_tower);
	CTextDraw::Print(pDC, 1290, 175, (show_friend_tower + "/1000"));
	show_enemy_tower = std::to_string(enemy_tower);
	CTextDraw::Print(pDC, 255, 175, (show_enemy_tower + "/500"));

	/*if (enemy_one_v.size() >= 1 && cat_one_friend.size() >= 1)
	{
		std::string s1 = std::to_string(enemy_one_v[0].get_heart());
		std::string s2 = std::to_string(cat_one_friend[0].get_heart());
		std::string s3 = s1 + "//" + s2;
		int Px = 500;
		CTextDraw::ChangeFontLog(pDC, 30, "Arial Black", RGB(255, 200, 0), 900);
		CTextDraw::Print(pDC, Px, 3, s3);

		Px = 700;
		std::string s4 = std::to_string(enemy_one_v[0].get_power());
		CTextDraw::ChangeFontLog(pDC, 30, "Arial Black", RGB(255, 200, 0), 900);
		CTextDraw::Print(pDC, Px, 3, s4);;
	}*/

	CDDraw::ReleaseBackCDC();
}