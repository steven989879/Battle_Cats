#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "../../monster.h"
#include <string>
#include <ctime>
using namespace game_framework;

//此為選關卡的葉面，所有關卡都在此選擇

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
	/////////////////////////////////////
	// 設定敵對生物及貓咪移動停止參數
	/////////////////////////////////////
	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	taiwan.LoadBitmapByString({ "resources/choose_taiwan.bmp" }); //按開始遊戲，進入第一關
	hongkong.LoadBitmapByString({ "resources/choose_hongkong.bmp" });//按開始遊戲，進入第二關
	thailand.LoadBitmapByString({ "resources/choose_thailand.bmp" });//按開始遊戲，進入第三關
	taiwan.SetTopLeft(0, 0);
	hongkong.SetTopLeft(0, 0);
	thailand.SetTopLeft(0, 0);
	choose = 1; //當前選擇的關卡，init階端默認為第一關
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RIGHT && choose < 3) { //鍵盤右鍵，選擇的關卡+1
		choose += 1;
	}
	else if (nChar == VK_LEFT && choose >1) {//左鍵，選擇的關卡-1
		choose -= 1;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	///////////////////////////////////
	// 藉由點擊次數生成相應數量貓咪
	///////////////////////////////////
	if (point.x >= 1250 && point.x <= 1599 && point.y >= 488 && point.y <= 570) { //圖片中的戰鬥開始
		if (choose == 1) {
			GotoGameState(GAME_STATE_RUN_1);		// 根據choose切換至GAME_STATE_RUN_1
		}
		else if (choose == 2) {
			GotoGameState(GAME_STATE_RUN_2);		// 根據choose切換至GAME_STATE_RUN_2
		}
		else if (choose == 3) {
			GotoGameState(GAME_STATE_RUN_3);		// 根據choose切換至GAME_STATE_RUN_3
		}
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
	if (choose == 1) {
		taiwan.ShowBitmap();        // 根據choose顯示不同背景
	}
	else if (choose == 2) {
		hongkong.ShowBitmap();
	}
	else if (choose == 3) {
		thailand.ShowBitmap();
	}
	
	/////////////////////////////////////////////////////////////////////////////////
}
