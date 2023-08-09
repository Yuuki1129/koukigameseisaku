#pragma once
#include     "SceneBase.h"
#include	"Player.h"
#include	"Stage.h"

class CGame : public CSceneBase
{
private:
	CFont	pfont;
	//�v���C���[
	CPlayer		m_Player;
	//�X�e�[�W
	CStage		m_Stage;
public:
	CGame();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

