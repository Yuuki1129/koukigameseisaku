#include "ObjectBase.h"
/*作った人　碇
* ゲーム中のオブジェクトのスーパークラス。

*/

bool CObjectBase::Load() {

	return 	m_Texture.Load(pName);
}
void CObjectBase::Initialize() {

 }
void CObjectBase::Update() {
	for (int i = 0; objDetavector.size() > i; i++) {
		objDetavector[i]->m_PosX += objDetavector[i]->m_MoveX;
		objDetavector[i]->m_PosY += objDetavector[i]->m_MoveY;
	}
}
void CObjectBase::Render(float wx, float wy) {
	for (int i = 0; objDetavector.size() > i; i++) {
		
		//描画位置
		float px = objDetavector[i]->m_PosX - wx;
		float py = objDetavector[i]->m_PosY - wy;
		//反転フラグがONの場合描画矩形を反転させる
		if (objDetavector[i]->m_bReverse)
		{
		}
		//テクスチャの描画
		m_Texture.RenderRotate(px, py, objDetavector[i]->m_rot);
	
	}
	
}
void CObjectBase::Release() {
	m_Texture.Release();
}