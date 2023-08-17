#pragma once
#include     "SceneBase.h"
#include	"Player.h"
#include	"Stage.h"
#include    <vector>
#include    "Sashiobj.h"

class CGame : public CSceneBase
{
private:

	CFont	pfont;
	//プレイヤー
	CPlayer		m_Player;
	//ステージ
	CStage		m_Stage;
	//サシのオブジェクト
	CSashiobj  m_Sashiobj;
public:
	CGame();
	bool Load(void);
	Vector2 getplayerpositon();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
	void addobject(void);
	void moveingsashiobject(void);
};

