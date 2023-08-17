#pragma once
#include "ObjectBase.h"
#define SASHI_SUPEED  20//サシの移動速度(仮）

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
	 void Update(float wx, float wy);
	 void Render(float wx, float wy);
	 void AddObject(ObjectDeta* tmpobjdeta);
	 void  moveingsashiobject(void);
};
