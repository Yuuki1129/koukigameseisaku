#include "Game.h"

/**
 * �R���X�g���N�^
 *
 */
CPlayer::CPlayer() :
m_Texture() ,
m_Motion() ,
m_PosX(0.0f) ,
m_PosY(0.0f) ,
m_bMove(false) ,
m_MoveX(0.0f) ,
m_MoveY(0.0f) ,
m_bJump(false) ,
m_bReverse(false) ,
m_SrcRect() {
}

extern CGame* G_Cgame;

/**
 * �f�X�g���N�^
 *
 */
CPlayer::~CPlayer(){
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CPlayer::Load(void){
	//�e�N�X�`���̓ǂݍ���
	if(!m_Texture.Load("player.png"))
	{
		return false;
	}
	//�A�j���[�V�������쐬
	SpriteAnimationCreate anim[] = {
		//�ҋ@
		{
			"�ҋ@",
			0,0,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}} 
		},
		//�ړ�
		{
			"�ړ�",
			0,70,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}} 
		},
		//�W�����v
		{
			"�W�����v�J�n",
			0,140,
			60,64,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}} 
		},
		{
			"�W�����v�I��",
			240,140,
			60,64,
			FALSE,{{2,0,0},{2,1,0}} 
		},
		//�U��
		{
			"�U��",
			0,350,
			90,64,
			FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0}} 
		},
	};
	m_Motion.Create(anim,MOTION_COUNT);
	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 * �v���C���[�̈ʒu�ȂǏ�Ԃ��������������Ƃ��Ɏ��s����B
 */
void CPlayer::Initialize(void){
	m_PosX = 200;
	m_PosY = 0;
	m_bMove = false;
	m_MoveX = 0.0f;
	m_MoveY = 0.0f;
	m_bReverse = false;
	m_bJump = false;
	m_Motion.ChangeMotion(MOTION_WAIT);
}

/**
 * �X�V
 *
 */
void CPlayer::Update(void){
	//�ړ��t���O�A���̃t���[���ł̈ړ�������������ۑ�
	m_bMove = false;
	//�U�����A���n�̏ꍇ�̓���
	if (m_Motion.GetMotionNo() == MOTION_ATTACK)
	{
		//�I���őҋ@�ɖ߂�
		if (m_Motion.IsEndMotion())
		{
			m_Motion.ChangeMotion(MOTION_WAIT);
		}
	}
	
	if( m_Motion.GetMotionNo() == MOTION_JUMPEND)
	{
		//�I���őҋ@�ɖ߂�
		if(m_Motion.IsEndMotion())
		{
			m_Motion.ChangeMotion(MOTION_WAIT);
		}
	}
	else
	{
		UpdateKey();
	}
	//�ړ��X�V
	UpdateMove();
	//���ۂɍ��W���ړ�������
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
	//�n�ʂɐڐG����ƃW�����v�I��(��U��ʉ��[�Œ�~����悤�ɐݒ������)
	if(m_PosY + m_SrcRect.GetHeight() >= g_pGraphics->GetTargetHeight())
	{
		m_PosY = g_pGraphics->GetTargetHeight() - m_SrcRect.GetHeight();
		m_MoveY = 0;
		if(m_bJump)
		{
			m_bJump = false;
			m_Motion.ChangeMotion(MOTION_JUMPEND);
		}
	}
	//�A�j���[�V�����̍X�V
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
}

/**
 * �L�[���͂ɂ�铮��X�V
 *
 */
void CPlayer::UpdateKey(void){
	//�L�[�{�[�h�ł̈ړ�
	//���͂Œ��ڍ��W�𓮂����̂ł͂Ȃ��A���x��ω�������B
	//�U�����͈ړ��ł��Ȃ��悤�ɂ���
	if(g_pInput->IsKeyHold(MOFKEY_LEFT)|| g_pInput->IsKeyHold(MOFKEY_A))
	{
		m_MoveX -= PLAYER_SPEED;
		m_bReverse = true;
		m_bMove = true;
		if(m_MoveX < -PLAYER_MAXSPEED)
		{
			m_MoveX = -PLAYER_MAXSPEED;
		}
		if(m_Motion.GetMotionNo() == MOTION_WAIT)
		{
			m_Motion.ChangeMotion(MOTION_MOVE);
		}
	}
	else if(g_pInput->IsKeyHold(MOFKEY_RIGHT) || g_pInput->IsKeyHold(MOFKEY_D))
	{
		m_MoveX += PLAYER_SPEED;
		m_bReverse = false;
		m_bMove = true;
		if(m_MoveX > PLAYER_MAXSPEED)
		{
			m_MoveX = PLAYER_MAXSPEED;
		}
		if(m_Motion.GetMotionNo() == MOTION_WAIT)
		{
			m_Motion.ChangeMotion(MOTION_MOVE);
		}
	}
	//��L�[�ŃW�����v
	if((g_pInput->IsKeyHold(MOFKEY_UP)|| g_pInput->IsKeyHold(MOFKEY_W)) && !m_bJump)
	{
		m_bJump = true;
		m_MoveY = PLAYER_JUMP;
		m_Motion.ChangeMotion(MOTION_JUMPSTART);
	}
	//SPACE�L�[�ōU��
	if(g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		G_Cgame->addobject();
		m_Motion.ChangeMotion(MOTION_ATTACK);
		
	}
	else if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON)) {
		G_Cgame->moveingsashiobject();
		m_Motion.ChangeMotion(MOTION_ATTACK);
	}
}

/**
 * �ړ��X�V
 *
 */
void CPlayer::UpdateMove(void){
	//���̃t���[���ł̈ړ����͂��Ȃ���Ό������������s����
	if(!m_bMove)
	{
		if(m_MoveX > 0)
		{
			m_MoveX -= PLAYER_SPEED;
			if(m_MoveX <= 0)
			{
				m_MoveX = 0;
			}
		}
		else if(m_MoveX < 0)
		{
			m_MoveX += PLAYER_SPEED;
			if(m_MoveX >= 0)
			{
				m_MoveX = 0;
			}
		}
		else if(m_Motion.GetMotionNo() == MOTION_MOVE)
		{
			m_Motion.ChangeMotion(MOTION_WAIT);
		}
	}
	//�d�͂ɂ�艺�ɏ�����������
	m_MoveY += GRAVITY;
	if(m_MoveY >= 20.0f)
	{
		m_MoveY = 20.0f;
	}
}

/**
 * �X�e�[�W�Ƃ̓�����
 *
 * ����
 * [in]			ox					X���܂��
 * [in]			oy					Y���܂��
 */
void CPlayer::CollisionStage(float ox,float oy){
	m_PosX += ox;
	m_PosY += oy;
	//�������̉����܂�A�W�����v���̏㖄�܂�̏ꍇ�͈ړ�������������B
	if(oy < 0 && m_MoveY > 0)
	{
		m_MoveY = 0;
		if(m_bJump)
		{
			m_bJump = false;
			m_Motion.ChangeMotion(MOTION_JUMPEND);
		}
	}
	else if(oy > 0 && m_MoveY < 0)
	{
		m_MoveY = 0;
	}
	//���ړ����̍����܂�A�E�ړ����̉E���܂�̏ꍇ�͈ړ�������������B
	if(ox < 0 && m_MoveX > 0)
	{
		m_MoveX = 0;
	}
	else if(ox > 0 && m_MoveX < 0)
	{
		m_MoveX = 0;
	}
}

/**
 * �`��
 *
 * ����
 * [in]			wx					���[���h�̕ω�
 * [in]			wy					���[���h�̕ω�
 */
void CPlayer::Render(float wx,float wy){
	//�`���`
	CRectangle dr = m_SrcRect;
	//�`��ʒu
	float px = m_PosX - wx;
	float py = m_PosY - wy;
	//���]�t���O��ON�̏ꍇ�`���`�𔽓]������
	if(m_bReverse)
	{
		float tmp = dr.Right;
		dr.Right = dr.Left;
		dr.Left = tmp;
		if(m_Motion.GetMotionNo() == MOTION_ATTACK)
		{
			px -= PLAYER_ATTACKWIDTH;
		}
	}
	//�e�N�X�`���̕`��
	m_Texture.Render(px,py,dr);
}

/**
 * �f�o�b�O�`��
 *
 * ����
 * [in]			wx					���[���h�̕ω�
 * [in]			wy					���[���h�̕ω�
 */
void CPlayer::RenderDebug(float wx,float wy){
	//�ʒu�̕`��
	CGraphicsUtilities::RenderString(10,70,"�v���C���[�ʒu X : %.0f , Y : %.0f",m_PosX,m_PosY);
	//�����蔻��̕\��
	CRectangle hr = GetRect();
	CGraphicsUtilities::RenderRect(hr.Left - wx,hr.Top - wy,hr.Right - wx,hr.Bottom - wy,MOF_XRGB(0,255,0));
	//�U���̓����蔻��\��
	if(IsAttack())
	{
		CRectangle hr = GetAttackRect();
		CGraphicsUtilities::RenderRect(hr.Left - wx,hr.Top - wy,hr.Right - wx,hr.Bottom - wy,MOF_XRGB(255,0,0));
	}
}

/**
 * ���
 *
 */
void CPlayer::Release(void){
	m_Texture.Release();
	m_Motion.Release();
}
