#include "ObjectBase.h"
/*������l�@��
* �Q�[�����̃I�u�W�F�N�g�̃X�[�p�[�N���X�B

*/

bool CObjectBase::Load() {

	return 	m_Texture.Load(pName);
}
void CObjectBase::Initialize() {

 }
void CObjectBase::Update() {
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
}
void CObjectBase::Render(float wx, float wy) {
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
void CObjectBase::Release() {
	m_Texture.Release();
}