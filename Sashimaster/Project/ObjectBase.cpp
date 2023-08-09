#include "ObjectBase.h"

bool CObjectBase::Load() {

	return 	m_Texture.Load(pName);
}
void CObjectBase::Initialize() {

 }
void CObjectBase::Update() {
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
}
void CObjectBase::Render(float wx, float wy) {
	//描画位置
	float px = m_PosX - wx;
	float py = m_PosY - wy;
	//反転フラグがONの場合描画矩形を反転させる
	if (m_bReverse)
	{
	}
	//テクスチャの描画
	m_Texture.RenderRotate(px, py, m_rot);
}
void CObjectBase::Release() {
	m_Texture.Release();
}