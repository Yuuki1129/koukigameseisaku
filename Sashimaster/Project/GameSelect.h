#pragma once
#include     "SceneBase.h"

class CGameSelect : public CSceneBase
{
private:
	CFont	pfont;
public:
	CGameSelect();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

