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
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	//Sleep(100);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	load_background();
	CAudio::Instance()->Load(OP_BGM, "resources/Audio/OP_BGM.wav");
	CAudio::Instance()->Load(Battle_BGM, "resources/Audio/Battle_BGM1.wav");
	CAudio::Instance()->Load(Menu_BGM, "resources/Audio/Menu_BGM.wav");
	CAudio::Instance()->Load(Hit_audio_1, "resources/Audio/Hit_audio.wav");
	CAudio::Instance()->Load(Hit_audio_2, "resources/Audio/Hit_audio.wav");
	CAudio::Instance()->Play(OP_BGM, true);
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}


void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x >= 630 && point.x <= 1083 && point.y >= 432 && point.y <= 507) {
		CAudio::Instance()->Stop(OP_BGM);
		CAudio::Instance()->Play(Menu_BGM, true);
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
	/*
	else {
		GotoGameState(GAME_STATE_RUN_1);		// 切換至GAME_STATE_RUN_1
	}
	*/
}

void CGameStateInit::OnShow()
{
	background.ShowBitmap();
	//draw_text();
}
void CGameStateInit::load_background() {
	background.LoadBitmapByString({ "resources/background.bmp" });
	background.SetTopLeft(0, 0);
}

/*void CGameStateInit::draw_text() {
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	rint title 
	//CTextDraw::ChangeFontLog(pDC, fp, 28, "微軟正黑體", RGB(255, 255, 255));
	//CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	Print info 
	CTextDraw::ChangeFontLog(pDC, fp, 19, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();

}*/

