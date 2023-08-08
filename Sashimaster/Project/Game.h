#pragma once
#include     "SceneBase.h"

class CGame : public CSceneBase
{
private:
	CFont	pfont;
public:
	CGame();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

