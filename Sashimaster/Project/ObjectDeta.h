#pragma once

enum objmode {
	getplayer,
	moving,
	idle,
	noRender
};

class ObjectDeta {
public:
	float					m_PosX;//X���W
	float					m_PosY;//Y���W
	float                   m_rot;//��]
	float					m_MoveX;//X�����x
	float					m_MoveY;//Y�����x
	bool					m_bReverse;//�����̔��]
	objmode                 m_objmode;//�I�u�W�F�N�g�̏�ԑJ�ڗp�ϐ�
};