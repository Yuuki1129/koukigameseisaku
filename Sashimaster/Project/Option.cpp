#include "Option.h"


COption::COption() :CSceneBase(), pfont()
{}

bool COption::Load()
{
	
	return true;
}
void COption::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void COption::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = gameselectscene;
	}
}
void COption::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "Press Enter Key");
}
void COption::Release()
{
	background.Release();
}