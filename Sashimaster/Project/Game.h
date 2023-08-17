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
	//�v���C���[
	CPlayer		m_Player;
	//�X�e�[�W
	CStage		m_Stage;
	//�T�V�̃I�u�W�F�N�g
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

