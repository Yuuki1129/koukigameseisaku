#pragma once
#include	"Mof.h"
#include	"GameDefine.h"
#include    "ObjectDeta.h"
#include    <vector>
/*作った人　碇
* ゲーム中のオブジェクトのスーパークラス。

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
};//４つのポイントのベクトル配列を纏めるクラス

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
	virtual std::vector<Rectpoint> Getrectvec();
	virtual void Release(void);
};


