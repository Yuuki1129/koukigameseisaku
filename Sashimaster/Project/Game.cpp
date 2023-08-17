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
	//�v���C���[�̑f�ޓǂݍ���
	m_Player.Load();
	//�X�e�[�W�̑f�ޓǂݍ���
	m_Stage.Load("Stage1.txt");
	return true;
}
Vector2 CGame::getplayerpositon() {
	return Vector2(m_Player.getposx(), m_Player.getposy());
}
void CGame::Initialize()
{
	//�T�V�̏�ԏ�����
	m_Sashiobj.Initialize();
	
	//�v���C���[�̏�ԏ�����
	m_Player.Initialize();
	//�X�e�[�W�̏�ԏ�����
	m_Stage.Initialize();
	pfont.Create(64, "MS �S�V�b�N");
}
void CGame::Update()
{
	//�T�V�̍X�V
	m_Sashiobj.Update();
	
	
	//�v���C���[�̍X�V
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
	
	m_Sashiobj.Render(m_Stage.GetScrollX(), m_Stage.GetScrollY());
	
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
	//�T�V�I�u�W�F�N�g�̉��
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
//�T�V��ǉ����郁�\�b�h

void CGame::moveingsashiobject() {
	m_Sashiobj.moveingsashiobject();
}
//�T�V�̃��[�h��؂�ւ��郁�\�b�h