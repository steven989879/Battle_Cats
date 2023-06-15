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
	//ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	// 開始載入資料
	//Sleep(100);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	load_background();
	CAudio::Instance()->Load(OP_BGM, "resources/Audio/OP_BGM.wav");
	CAudio::Instance()->Load(Battle_BGM, "resources/Audio/Battle_BGM1.wav");
	CAudio::Instance()->Load(Menu_BGM, "resources/Audio/Menu_BGM.wav");
	CAudio::Instance()->Load(Hit_audio_1, "resources/Audio/Hit_audio.wav");
	CAudio::Instance()->Load(Hit_audio_2, "resources/Audio/Hit_audio.wav");
	CAudio::Instance()->Play(OP_BGM, true);
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
}

void CGameStateInit::OnShow()
{
	background.ShowBitmap();
	draw_text();
}
void CGameStateInit::load_background() {
	background.LoadBitmapByString({ "resources/background.bmp" });
	background.SetTopLeft(0, 0);
}

void CGameStateInit::draw_text() {
	CDC *pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 24, "Arial Black", RGB(50, 50, 50), 900);
	CTextDraw::Print(pDC, 540, 700, ("Author: ntut_Feng & Syun"));

	CDDraw::ReleaseBackCDC();
}