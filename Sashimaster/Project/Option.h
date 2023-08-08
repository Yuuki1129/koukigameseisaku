#pragma once
#include     "SceneBase.h"

class COption : public CSceneBase
{
private:
	CFont	pfont;
public:
	COption();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

