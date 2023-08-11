#pragma once
#include	"Mof.h"
#include	"GameDefine.h"
#include    "ObjectDeta.h"
#include    <vector>
/*作った人　碇
* ゲーム中のオブジェクトのスーパークラス。

*/

class CObjectBase {
protected:
	char*                    pName;//テクスチャの名前
	CTexture				 m_Texture;//ロードするテクスチャ
	std::vector<ObjectDeta*> objDetavector;//オブジェクトデータのベクター配列

	
public:
	// CObjectBase();一応効果消しときます。
	
	virtual bool Load(void);
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Render(float wx, float wy);
	virtual void Release(void);
};
