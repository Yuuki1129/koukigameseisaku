#include "Game.h"
#include "GameDefine.h"


CGame* G_Cgame;
CGame::CGame() :CSceneBase(), pfont()
{
	G_Cgame = this;	
}

bool CGame::Load()
{
	
	m_Sashiobj.Load();
	//プレイヤーの素材読み込み
	m_Player.Load();
	//ステージの素材読み込み
	m_Stage.Load("Stage1.txt");
	return true;
}
Vector2 CGame::getplayerpositon() {
	return Vector2(m_Player.getposx(), m_Player.getposy());
}
void CGame::Initialize()
{
	//サシの状態初期化
	m_Sashiobj.Initialize();
	
	//プレイヤーの状態初期化
	m_Player.Initialize();
	//ステージの状態初期化
	m_Stage.Initialize();
	pfont.Create(64, "MS ゴシック");
}
void CGame::Update()
{
	//サシの更新
	m_Sashiobj.Update();
	
	
	//プレイヤーの更新
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
	
	m_Sashiobj.Render(m_Stage.GetScrollX(), m_Stage.GetScrollY());
	
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
	//サシオブジェクトの解放
	m_Sashiobj.Release();
	background.Release();
}
void CGame::addobject() {
	auto aa = new ObjectDeta();
	aa->m_MoveX = 1;
	aa->m_MoveY = 1;
	aa->m_rot = atan(aa->m_MoveY / aa->m_MoveX);
	aa->m_objmode = getplayer;

	m_Sashiobj.AddObject(aa);
}
//サシを追加するメソッド

void CGame::moveingsashiobject() {
	m_Sashiobj.moveingsashiobject();
}
//サシのモードを切り替えるメソッド