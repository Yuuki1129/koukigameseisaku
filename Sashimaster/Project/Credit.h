#pragma once
#include     "SceneBase.h"

class CCredit : public CSceneBase
{
private:
	CFont	pfont;
public:
	CCredit();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

