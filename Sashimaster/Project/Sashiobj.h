#pragma once
#include "ObjectBase.h"


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
	 void Update(void);
	 void Render(float wx, float wy);
	 void AddObject(ObjectDeta* tmpobjdeta);
};
