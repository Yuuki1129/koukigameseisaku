#pragma once
#include	"Mof.h"
#include	"GameDefine.h"

/*作った人　碇
* ゲーム中のオブジェクトのスーパークラス。

*/

class CObjectBase {
protected:
	char*                   pName;//テクスチャの名前
	CTexture				m_Texture;//ロードするテクスチャ
	float					m_PosX;//X座標
	float					m_PosY;//Y座標
	float                   m_rot;//回転
	bool					m_bMove;//動く事を許可するか否か
	float					m_MoveX;//X加速度
	float					m_MoveY;//Y加速度
	bool					m_bReverse;//向きの反転

	
public:
	// CObjectBase();一応効果消しときます。
	
	virtual bool Load(void);
	virtual void Initialize(void);
	virtual void Update(void);
	virtual void Render(float wx, float wy);
	virtual void Release(void);
};
