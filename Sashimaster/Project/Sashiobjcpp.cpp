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
		objDetavector[i]->m_rot+=0.01f;
	}

	
}
void  CSashiobj::Render(float wx, float wy) {
	for (int i = 0; objDetavector.size() > i; i++) {
		//描画位置
		float px = objDetavector[i]->m_PosX - wx;
		float py = objDetavector[i]->m_PosY - wy;
		//float wight = m_Texture.GetWidth();

		//反転フラグがONの場合描画矩形を反転させる
		if (objDetavector[i]->m_bReverse)
		{
		}
		
		//描画処理（ピボットを中心に変えた）
		m_Texture.RenderRotate(px- 
			(m_Texture.GetWidth() *cos(objDetavector[i]->m_rot)/2-
			m_Texture.GetHeight() * sin(objDetavector[i]->m_rot) / 2)									
			, py-
			(m_Texture.GetWidth()* sin(objDetavector[i]->m_rot) / 2 +
			m_Texture.GetHeight() * cos(objDetavector[i]->m_rot) / 2)						
			, objDetavector[i]->m_rot);
	}
	std::vector<Rectpoint> debug= Getrectvec();
	for (int i = 0; debug.size() > i; i++) {
		for (int j = 0; 3 > j; j++) {
			CGraphicsUtilities::RenderLine(debug[i].point[j]->x, debug[i].point[j]->y, debug[i].point[j+1]->x, debug[i].point[j+1]->y, MOF_XRGB(255, 0, 0));
		}
		CGraphicsUtilities::RenderLine(debug[i].point[3]->x, debug[i].point[3]->y, debug[i].point[0]->x, debug[i].point[0]->y, MOF_XRGB(255, 0, 0));
	}
}

void CSashiobj::AddObject(ObjectDeta* tmpdeta) {
	objDetavector.push_back(tmpdeta);
}