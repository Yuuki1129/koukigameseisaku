#pragma once
#include     "SceneBase.h"

class CTitle : public CSceneBase
{
private:
	CFont	pfont;
public:
	CTitle();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

