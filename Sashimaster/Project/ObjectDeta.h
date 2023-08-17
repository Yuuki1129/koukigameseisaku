#pragma once

enum objmode {
	getplayer,
	moving,
	idle,
	noRender
};

class ObjectDeta {
public:
	float					m_PosX;//X座標
	float					m_PosY;//Y座標
	float                   m_rot;//回転
	float					m_MoveX;//X加速度
	float					m_MoveY;//Y加速度
	bool					m_bReverse;//向きの反転
	objmode                 m_objmode;//オブジェクトの状態遷移用変数
};