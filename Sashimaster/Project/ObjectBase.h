#pragma once
#include	"Mof.h"
#include	"GameDefine.h"
#include    "ObjectDeta.h"
#include    <vector>
/*������l�@��
* �Q�[�����̃I�u�W�F�N�g�̃X�[�p�[�N���X�B

*/
class Rectpoint {
public: 
	Vector2*                 point[4];
	Rectpoint(Vector2* a, Vector2* b, Vector2* c, Vector2* d) {
		point[0] = a;
		point[1] = b;
		point[2] = c;
		point[3] = d;
}
};//�S�̃|�C���g�̃x�N�g���z���Z�߂�N���X

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
	virtual std::vector<Rectpoint> Getrectvec();
	virtual void Release(void);
};


