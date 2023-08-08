#include "GameOver.h"


CGameOver::CGameOver() :CSceneBase(), pfont()
{}

bool CGameOver::Load()
{
	
	return true;
}
void CGameOver::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CGameOver::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = gameselectscene;
	}
}
void CGameOver::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "Press Enter Key");
}
void CGameOver::Release()
{
	background.Release();
}
