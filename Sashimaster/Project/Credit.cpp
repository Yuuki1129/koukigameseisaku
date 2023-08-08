#include "Credit.h"


CCredit::CCredit() :CSceneBase(), pfont()
{}

bool CCredit::Load()
{
	
	return true;
}
void CCredit::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CCredit::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = gameselectscene;
	}
}
void CCredit::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "Press Enter Key");
}
void CCredit::Release()
{
	background.Release();
}
