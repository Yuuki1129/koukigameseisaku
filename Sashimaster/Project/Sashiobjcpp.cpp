#include "Game.h"
#include "Sashiobj.h"

extern CGame* G_Cgame;
void  CSashiobj::Initialize() {
	m_rot = MOF_MATH_HALFPI;
}
void  CSashiobj::Update() {

	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
	Vector2 tmpvec2 = G_Cgame->getplayerpositon();
	m_PosX = tmpvec2.x;
	m_PosY= tmpvec2.y;
	//m_rot+=0.1f;
}
void  CSashiobj::Render(float wx, float wy) {
	//�`��ʒu
	float px = m_PosX - wx;
	float py = m_PosY - wy;
	//���]�t���O��ON�̏ꍇ�`���`�𔽓]������
	if (m_bReverse)
	{
	}
	//�e�N�X�`���̕`��
	m_Texture.RenderRotate(px, py, m_rot);
}