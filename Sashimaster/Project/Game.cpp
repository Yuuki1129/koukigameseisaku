#include "Game.h"
#include "GameDefine.h"

CGame::CGame() :CSceneBase(), pfont()
{}

bool CGame::Load()
{
	//�v���C���[�̑f�ޓǂݍ���
	m_Player.Load();
	//�X�e�[�W�̑f�ޓǂݍ���
	m_Stage.Load("Stage1.txt");
	return true;
}
void CGame::Initialize()
{
	//�v���C���[�̏�ԏ�����
	m_Player.Initialize();
	//�X�e�[�W�̏�ԏ�����
	m_Stage.Initialize();
	pfont.Create(64, "MS �S�V�b�N");
}
void CGame::Update()
{//�v���C���[�̍X�V
	m_Player.Update();
	//�X�e�[�W�ƃv���C���[�̓����蔻��
	float ox = 0, oy = 0;
	if (m_Stage.Collision(m_Player.GetRect(), ox, oy))
	{
		m_Player.CollisionStage(ox, oy);
	}
	//�X�e�[�W�̍X�V
	m_Stage.Update(m_Player);
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndScene = true;
		m_NextScene = resultscene;
	}
}
void CGame::Render()
{
	//�X�e�[�W�̕`��
	m_Stage.Render();
	//�v���C���[�̕`��
	m_Player.Render(m_Stage.GetScrollX(), m_Stage.GetScrollY());

	//CGraphicsUtilities::RenderString(10,10,"�Q�[�����");
	//CGraphicsUtilities::RenderString(10,40,"F2�L�[�ŃQ�[���N���A�AF3�L�[�ŃQ�[���I�[�o�[");
	background.Render(0, 0);
	CGraphicsUtilities::RenderString(400, 500, MOF_COLOR_BLACK, "game");
}
void CGame::Release()
{
	//�X�e�[�W�̉��
	m_Stage.Release();
	//�v���C���[�̉��
	m_Player.Release();
	background.Release();
}
