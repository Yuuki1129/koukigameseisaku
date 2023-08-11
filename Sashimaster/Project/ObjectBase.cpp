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
	for (int i = 0; objDetavector.size() > i; i++) {
		objDetavector[i]->m_PosX += objDetavector[i]->m_MoveX;
		objDetavector[i]->m_PosY += objDetavector[i]->m_MoveY;
	}
}
void CObjectBase::Render(float wx, float wy) {
	for (int i = 0; objDetavector.size() > i; i++) {
		
		//�`��ʒu
		float px = objDetavector[i]->m_PosX - wx;
		float py = objDetavector[i]->m_PosY - wy;
		//���]�t���O��ON�̏ꍇ�`���`�𔽓]������
		if (objDetavector[i]->m_bReverse)
		{
		}
		//�e�N�X�`���̕`��
		m_Texture.RenderRotate(px, py, objDetavector[i]->m_rot);
	
	}
	
}
void CObjectBase::Release() {
	m_Texture.Release();
}