#include "Game.h"
#include "Sashiobj.h"

extern CGame* G_Cgame;
void  CSashiobj::Initialize() {
	for (int i = 0; objDetavector.size() > i; i++) {
		objDetavector[i]->m_rot = MOF_MATH_HALFPI;
	}
	
}
void  CSashiobj::Update() {
	for (int i = 0; objDetavector.size() > i; i++) {
		objDetavector[i]->m_PosX += objDetavector[i]->m_MoveX;

		objDetavector[i]->m_PosY += objDetavector[i]->m_MoveY;
		Vector2 tmpvec2 = G_Cgame->getplayerpositon();
		objDetavector[i]->m_PosX = tmpvec2.x;
		objDetavector[i]->m_PosY = tmpvec2.y;
		//m_rot+=0.1f;
	}

	
}
void  CSashiobj::Render(float wx, float wy) {
	for (int i = 0; objDetavector.size() > i; i++) {
		//•`‰æˆÊ’u
		float px = objDetavector[i]->m_PosX - wx;
		float py = objDetavector[i]->m_PosY - wy;
		//”½“]ƒtƒ‰ƒO‚ªON‚Ìê‡•`‰æ‹éŒ`‚ð”½“]‚³‚¹‚é
		if (objDetavector[i]->m_bReverse)
		{
		}
		//ƒeƒNƒXƒ`ƒƒ‚Ì•`‰æ
		m_Texture.RenderRotate(px, py, objDetavector[i]->m_rot);
	}
	
}

void CSashiobj::AddObject(ObjectDeta* tmpdeta) {
	objDetavector.push_back(tmpdeta);
}