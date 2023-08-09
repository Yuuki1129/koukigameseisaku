#pragma once
#include	"Mof.h"
#include	"GameDefine.h"

/*������l�@��
* �Q�[�����̃I�u�W�F�N�g�̃X�[�p�[�N���X�B

*/

class CObjectBase {
protected:
	char*                   pName;//�e�N�X�`���̖��O
	CTexture				m_Texture;//���[�h����e�N�X�`��
	float					m_PosX;//X���W
	float					m_PosY;//Y���W
	float                   m_rot;//��]
	bool					m_bMove;//�������������邩�ۂ�
	float					m_MoveX;//X�����x
	float					m_MoveY;//Y�����x
	bool					m_bReverse;//�����̔��]

	
public:
	// CObjectBase();�ꉞ���ʏ����Ƃ��܂��B
	
	virtual bool Load(void);
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Render(float wx, float wy);
	virtual void Release(void);
};
