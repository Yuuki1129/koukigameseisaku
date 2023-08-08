#include "SceneBase.h"

CSceneBase::CSceneBase() :
	m_bEndScene(false),
	m_NextScene(0)
{}

int CSceneBase::GetNextScene() {
	return m_NextScene;
}

void CSceneBase::SetNextScene(int no) {
	m_NextScene = no;
}

bool CSceneBase::IsEndScene() {
	return m_bEndScene;
}