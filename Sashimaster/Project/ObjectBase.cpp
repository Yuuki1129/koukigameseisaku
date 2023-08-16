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
		//float wight = m_Texture.GetWidth();

		//���]�t���O��ON�̏ꍇ�`���`�𔽓]������
		if (objDetavector[i]->m_bReverse)
		{
		}

		//�`�揈���i�s�{�b�g�𒆐S�ɕς����j
		m_Texture.RenderRotate(px -
			(m_Texture.GetWidth() * cos(objDetavector[i]->m_rot) / 2 -
				m_Texture.GetHeight() * sin(objDetavector[i]->m_rot) / 2)
			, py -
			(m_Texture.GetWidth() * sin(objDetavector[i]->m_rot) / 2 +
				m_Texture.GetHeight() * cos(objDetavector[i]->m_rot) / 2)
			, objDetavector[i]->m_rot);
	}
	
}
void CObjectBase::Release() {
	m_Texture.Release();
}
std::vector<Rectpoint> CObjectBase::Getrectvec() {
	std::vector<Rectpoint> tmpans;
	for (int i = 0; objDetavector.size() > i; i++) {
		Vector2* aa =new Vector2(objDetavector[i]->m_PosX -
			(m_Texture.GetWidth() * cos(objDetavector[i]->m_rot) / 2 -
				m_Texture.GetHeight() * sin(objDetavector[i]->m_rot) / 2)
			, objDetavector[i]->m_PosY -
			(m_Texture.GetWidth() * sin(objDetavector[i]->m_rot) / 2 +
				m_Texture.GetHeight() * cos(objDetavector[i]->m_rot) / 2));


		Vector2* bb =new Vector2(objDetavector[i]->m_PosX +
			(m_Texture.GetWidth() * cos(-objDetavector[i]->m_rot) / 2 -
				m_Texture.GetHeight() * sin(-objDetavector[i]->m_rot) / 2)
			, objDetavector[i]->m_PosY -
			(m_Texture.GetWidth() * sin(-objDetavector[i]->m_rot) / 2 +
				m_Texture.GetHeight() * cos(-objDetavector[i]->m_rot) / 2));


		Vector2* cc =new Vector2(objDetavector[i]->m_PosX +
			(m_Texture.GetWidth() * cos(objDetavector[i]->m_rot) / 2 -
				m_Texture.GetHeight() * sin(objDetavector[i]->m_rot) / 2)
			, objDetavector[i]->m_PosY +
			(m_Texture.GetWidth() * sin(objDetavector[i]->m_rot) / 2 +
				m_Texture.GetHeight() * cos(objDetavector[i]->m_rot) / 2));


		Vector2* dd =new Vector2(objDetavector[i]->m_PosX -
			(m_Texture.GetWidth() * cos(-objDetavector[i]->m_rot) / 2 -
				m_Texture.GetHeight() * sin(-objDetavector[i]->m_rot) / 2)
			, objDetavector[i]->m_PosY +
			(m_Texture.GetWidth() * sin(-objDetavector[i]->m_rot) / 2 +
				m_Texture.GetHeight() * cos(-objDetavector[i]->m_rot) / 2));

		
		tmpans.push_back(Rectpoint(aa, bb, cc, dd));
	}
	return tmpans;
}
//���S�̃s�{�b�g����S�̒��_�����v���Ɏ擾���郁�\�b�h