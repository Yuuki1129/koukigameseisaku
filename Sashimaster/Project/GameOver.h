#pragma once
#include     "SceneBase.h"

class CGameOver : public CSceneBase
{
private:
	CFont	pfont;
public:
	CGameOver();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

