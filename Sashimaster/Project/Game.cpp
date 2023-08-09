#include "Game.h"
#include "GameDefine.h"

CGame::CGame() :CSceneBase(), pfont()
{}

bool CGame::Load()
{
	//プレイヤーの素材読み込み
	m_Player.Load();
	//ステージの素材読み込み
	m_Stage.Load("Stage1.txt");
	return true;
}
void CGame::Initialize()
{
	//プレイヤーの状態初期化
	m_Player.Initialize();
	//ステージの状態初期化
	m_Stage.Initialize();
	pfont.Create(64, "MS ゴシック");
}
void CGame::Update()
{//プレイヤーの更新
	m_Player.Update();
	//ステージとプレイヤーの当たり判定
	float ox = 0, oy = 0;
	if (m_Stage.Collision(m_Player.GetRect(), ox, oy))
	{
		m_Player.CollisionStage(ox, oy);
	}
	//ステージの更新
	m_Stage.Update(m_Player);
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = resultscene;
	}
}
void CGame::Render()
{
	//ステージの描画
	m_Stage.Render();
	//プレイヤーの描画
	m_Player.Render(m_Stage.GetScrollX(), m_Stage.GetScrollY());

	//CGraphicsUtilities::RenderString(10,10,"ゲーム画面");
	//CGraphicsUtilities::RenderString(10,40,"F2キーでゲームクリア、F3キーでゲームオーバー");
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "game");
}
void CGame::Release()
{
	//ステージの解放
	m_Stage.Release();
	//プレイヤーの解放
	m_Player.Release();
	background.Release();
}
