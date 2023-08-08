#include "GameSelect.h"


CGameSelect::CGameSelect() :CSceneBase(), pfont()
{}

bool CGameSelect::Load()
{
	
	return true;
}
void CGameSelect::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CGameSelect::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = gamescene;
	}
}
void CGameSelect::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "gameselect");
}
void CGameSelect::Release()
{
	background.Release();
}
