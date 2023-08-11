#pragma once
class ObjectDeta {
public:
	float					m_PosX;//X座標
	float					m_PosY;//Y座標
	float                   m_rot;//回転
	bool					m_bMove;//動く事を許可するか否か
	float					m_MoveX;//X加速度
	float					m_MoveY;//Y加速度
	bool					m_bReverse;//向きの反転

};