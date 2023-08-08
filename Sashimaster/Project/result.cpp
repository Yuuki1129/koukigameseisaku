#include "result.h"


CResult::CResult() :CSceneBase(), pfont()
{}

bool CResult::Load()
{
	
	return true;
}
void CResult::Initialize()
{
	pfont.Create(64, "MS ƒSƒVƒbƒN");
}
void CResult::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = titlescene;
	}
}
void CResult::Render()
{
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "result");
}
void CResult::Release()
{
	background.Release();
}