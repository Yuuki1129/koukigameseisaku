#pragma once
#include     "SceneBase.h"

class CResult : public CSceneBase
{
private:
	CFont	pfont;
public:
	CResult();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

