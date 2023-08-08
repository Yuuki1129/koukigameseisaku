#pragma once
#include	"Sashimasterdefine.h"
#include <Mof.h>

class CSceneBase {
protected:

	CTexture background;

	bool	m_bEndScene;
	int		m_NextScene;
public:
public:
	CSceneBase();
	virtual bool Load() = 0;
	virtual void Initialize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;
	virtual void Release(void) = 0;

	int GetNextScene();
	void SetNextScene(int no);
	bool IsEndScene();
};