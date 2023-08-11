#pragma once
#include	"Mof.h"
#include	"GameDefine.h"
#include    "ObjectDeta.h"
#include    <vector>
/*������l�@��
* �Q�[�����̃I�u�W�F�N�g�̃X�[�p�[�N���X�B

*/

class CObjectBase {
protected:
	char*                    pName;//�e�N�X�`���̖��O
	CTexture				 m_Texture;//���[�h����e�N�X�`��
	std::vector<ObjectDeta*> objDetavector;//�I�u�W�F�N�g�f�[�^�̃x�N�^�[�z��

	
public:
	// CObjectBase();�ꉞ���ʏ����Ƃ��܂��B
	
	virtual bool Load(void);
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Render(float wx, float wy);
	virtual void Release(void);
};
