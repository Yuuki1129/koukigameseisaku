#pragma once
#include     "SceneBase.h"
#include	"Player.h"
#include	"Stage.h"
#include    <vector>
#include    "Sashiobj.h"

class CGame : public CSceneBase
{
private:
	//�Q�[���I�u�W�F�N�g�ϔz��
	std::vector<CSashiobj*> playerobjitem;
	CFont	pfont;
	//�v���C���[
	CPlayer		m_Player;
	//�X�e�[�W
	CStage		m_Stage;
public:
	CGame();
	bool Load(void);
	Vector2 getplayerpositon();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
	void addobject(void);
};

