#pragma once
#include "ObjectBase.h"
#define SASHI_SUPEED  20//�T�V�̈ړ����x(���j

/*������l�@��
* �Q�[�����̃T�V�̃I�u�W�F�N�g�B

*/

class CSashiobj :  public CObjectBase {

	
public:
	// CObjectBase();�ꉞ���ʏ����Ƃ��܂��B
	CSashiobj() {
		pName = "objkari01.png";
	}
	
	 void Initialize(void);
	 void Update(float wx, float wy);
	 void Render(float wx, float wy);
	 void AddObject(ObjectDeta* tmpobjdeta);
	 void  moveingsashiobject(void);
};
