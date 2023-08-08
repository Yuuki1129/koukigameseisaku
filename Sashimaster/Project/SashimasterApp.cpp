

//INCLUDE
#include	"SashimasterApp.h"
#include	"TItle.h"
#include	"Game.h"
#include	"GameOver.h"
#include	"GameSelect.h"
#include	"Option.h"
#include	"result.h"
#include	"Credit.h"
CSceneBase* gpScene = nullptr;

void CSashimasterApp::InitializeScene()
{
	gpScene->Load();
	gpScene->Initialize();
}
MofBool CSashimasterApp::Initialize(void){
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectory("Resource");
	gpScene = new CTitle();
	InitializeScene();
	return TRUE;
}

MofBool CSashimasterApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();
	gpScene->Update();
	if (gpScene->IsEndScene())
	{
		auto nextscene = gpScene->GetNextScene();

		gpScene->Release();
		delete gpScene;
		switch (nextscene)
		{
		case titlescene:
			gpScene = new CTitle;
			break;
		case gameselectscene:
			gpScene = new CGameSelect;
			break;
		case gamescene:
			gpScene = new CGame;
			break;
		case creditscene:
			gpScene = new CCredit;
			break;
		case resultscene:
			gpScene = new CResult;
		
		}
		InitializeScene();
	}
	return TRUE;
	return TRUE;
}

MofBool CSashimasterApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);
	gpScene->Render();
	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
MofBool CSashimasterApp::Release(void){
	gpScene->Release();
	return TRUE;
}