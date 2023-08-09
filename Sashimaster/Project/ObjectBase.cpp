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
	//`ζΚu
	float px = m_PosX - wx;
	float py = m_PosY - wy;
	//½]tOͺONΜκ`ζι`π½]³Ήι
	if (m_bReverse)
	{
	}
	//eNX`Μ`ζ
	m_Texture.RenderRotate(px, py, m_rot);
}
void CObjectBase::Release() {
	m_Texture.Release();
}