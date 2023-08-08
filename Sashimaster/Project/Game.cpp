#include "Game.h"


CGame::CGame() :CSceneBase(), pfont()
{}

bool CGame::Load()
{

	return true;
}
void CGame::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CGame::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = resultscene;
	}
}
void CGame::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "game");
}
void CGame::Release()
{
	background.Release();
}
