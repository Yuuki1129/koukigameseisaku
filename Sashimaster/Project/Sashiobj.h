#pragma once
#include "ObjectBase.h"


/*������l�@��
* �Q�[�����̃I�u�W�F�N�g�̃X�[�p�[�N���X�B

*/

class CSashiobj :  public CObjectBase {

	
public:
	// CObjectBase();�ꉞ���ʏ����Ƃ��܂��B
	CSashiobj() {
		pName = "objkari01.png";
	}
	
	 void Initialize(void);
	 void Update(void);
	 void Render(float wx, float wy);
	
};
