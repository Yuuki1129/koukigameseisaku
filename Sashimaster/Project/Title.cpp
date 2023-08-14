#include "TItle.h"


CTitle::CTitle() :CSceneBase(), pfont()
{}

bool CTitle::Load()
{
	if (!background.Load("puyotitle.jpg"))
	{
		return false;
	}
	return true;
}
void CTitle::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CTitle::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = gameselectscene;
	}
	if (g_pInput->IsKeyPush(MOFKEY_T))
	{
		m_bEndScene = true;
		m_NextScene = optionscene;
	}

}
void CTitle::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "title");
}
void CTitle::Release()
{
	background.Release();
}