#pragma once
#include "ObjectBase.h"


/*作った人　碇
* ゲーム中のサシのオブジェクト。

*/

class CSashiobj :  public CObjectBase {

	
public:
	// CObjectBase();一応効果消しときます。
	CSashiobj() {
		pName = "objkari01.png";
	}
	
	 void Initialize(void);
	 void Update(void);
	 void Render(float wx, float wy);
	 void AddObject(ObjectDeta* tmpobjdeta);
};
