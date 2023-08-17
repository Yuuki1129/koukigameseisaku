#include "Game.h"
#include "Sashiobj.h"

extern CGame* G_Cgame;
void  CSashiobj::Initialize() {
	for (int i = 0; objDetavector.size() > i; i++) {
		objDetavector[i]->m_MoveX = 1;
		objDetavector[i]->m_MoveY = 1;
		objDetavector[i]->m_rot = atan(objDetavector[i]->m_MoveY / objDetavector[i]->m_MoveX);
		objDetavector[i]->m_objmode = noRender;
	}
	
}
//あんまりいらない初期化（多分）

void  CSashiobj::Update(float wx, float wy) {
	for (int i = 0; objDetavector.size() > i; i++) {
		switch (objDetavector[i]->m_objmode)
		{
		case getplayer:
		{//座標の固定
			Vector2 tmpplayerpos = G_Cgame->getplayerpositon();
		objDetavector[i]->m_PosX = tmpplayerpos.x;
		objDetavector[i]->m_PosY = tmpplayerpos.y;

		//マウスのポジションからの移動時速度向き計算
		MofFloat a, b;
		g_pInput->GetMousePos(a, b);
		if (a - objDetavector[i]->m_PosX+ wx > 0) {
			objDetavector[i]->m_rot = atan((b - objDetavector[i]->m_PosY+ wy) / (a - objDetavector[i]->m_PosX+ wx));
			Vector2 invec, outvec;
			 invec = Vector2{ (a - objDetavector[i]->m_PosX+ wx),(b - objDetavector[i]->m_PosY+ wy) };
			CVector2Utilities::Normal(invec,outvec);
			outvec *= SASHI_SUPEED;
			objDetavector[i]->m_MoveX = outvec.x;
			objDetavector[i]->m_MoveY = outvec.y;
		}
		else if(a - objDetavector[i]->m_PosX+ wx < 0) {
			objDetavector[i]->m_rot = atan((b - objDetavector[i]->m_PosY+ wy) / (a - objDetavector[i]->m_PosX+ wx))+MOF_MATH_PI;
			Vector2 invec, outvec;
			invec = Vector2{ (a - objDetavector[i]->m_PosX+ wx),(b - objDetavector[i]->m_PosY+ wy) };
			CVector2Utilities::Normal(invec, outvec);
			outvec *= SASHI_SUPEED;
			objDetavector[i]->m_MoveX = outvec.x;
			objDetavector[i]->m_MoveY = outvec.y;
		}
		else {

		}
	
		
		}
			//objDetavector[i]->m_rot+=0.01f;			
		case moving:
		{objDetavector[i]->m_PosX += objDetavector[i]->m_MoveX;
		objDetavector[i]->m_PosY += objDetavector[i]->m_MoveY; }			
		case idle:			
		case noRender:			
		default:	
			break;
		}

		
	
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
		switch (objDetavector[i]->m_objmode)
		{
		case noRender:
			break;
		default:
		{//描画処理（ピボットを中心に変えた）
			m_Texture.RenderRotate(px -
				(m_Texture.GetWidth() * cos(objDetavector[i]->m_rot) / 2 -
					m_Texture.GetHeight() * sin(objDetavector[i]->m_rot) / 2)
				, py -
				(m_Texture.GetWidth() * sin(objDetavector[i]->m_rot) / 2 +
					m_Texture.GetHeight() * cos(objDetavector[i]->m_rot) / 2)
				, objDetavector[i]->m_rot); }
		}
		
	}
	std::vector<Rectpoint> debug= Getrectvec();
	for (int i = 0; debug.size() > i; i++) {
		for (int j = 0; 3 > j; j++) {
			CGraphicsUtilities::RenderLine(debug[i].point[j]->x - wx, debug[i].point[j]->y - wy, debug[i].point[j+1]->x - wx, debug[i].point[j+1]->y - wy, MOF_XRGB(255, 0, 0));
		}
		CGraphicsUtilities::RenderLine(debug[i].point[3]->x - wx, debug[i].point[3]->y - wy, debug[i].point[0]->x - wx, debug[i].point[0]->y - wy, MOF_XRGB(255, 0, 0));
	}
}

void CSashiobj::AddObject(ObjectDeta* tmpdeta) {
	objDetavector.push_back(tmpdeta);
}
//サシを追加するメソッド
void  CSashiobj::moveingsashiobject() {
	for (int i = 0; objDetavector.size() > i; i++) {
		if (objDetavector[i]->m_objmode == getplayer) {
			objDetavector[i]->m_objmode = moving;
		}

	}
}
//サシを動かす状態にするメソッド