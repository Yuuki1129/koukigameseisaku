/*************************************************************************//*!
					
					@file	GamePad.h
					@brief	ゲームパッドでの入力の処理を行う基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__GAMEPAD__H__

#define		__GAMEPAD__H__

//INCLUDE
#include	"InputCommon.h"
#include	"../Common/DynamicArray.h"
#include	"../Math/Quaternion.h"

namespace Mof {
	
	/*******************************//*!
	@brief	ゲームパッド生成情報構造体

			ゲームパッドの生成に必要な情報をまとめた構造体

	@author	CDW
	*//********************************/
	typedef struct tag_GAMEPADCREATEINFO {
		MofU32					Size;			//!<構造体サイズ

		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		tag_GAMEPADCREATEINFO() : 
		Size(sizeof(tag_GAMEPADCREATEINFO)) {
		}
	}GAMEPADCREATEINFO,*LPGAMEPADCREATEINFO;

	/*******************************//*!
	@brief	ゲームパッド基底インターフェイス

			ゲームパッドの基底となるインターフェイス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGamePad : public IMofObject {
	protected:
	public:
		/*************************************************************************//*!
				@brief			ゲームパッドオブジェクトの生成
				@param[in]		pInfo		ゲームパッドの生成情報
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPGAMEPADCREATEINFO pInfo) = 0;
		
		/*************************************************************************//*!
				@brief			入力キー更新
				@param			None

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool RefreshKey(void) = 0;
				
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのPush(このフレームで入力された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPush(const MofU8 n) = 0;
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのHold(このフレームで入力されている)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyHold(const MofU8 n) = 0;
		/*************************************************************************//*!
				@brief			ゲームパッドキー入力状態判定<br>
								キー番号のキーのPull(このフレームで放された)判定を行う
				@param[in]		n				キー番号

				@return			TRUE			入力あり<br>
								FALSE			入力なし
		*//**************************************************************************/
		virtual MofBool IsKeyPull(const MofU8 n) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			パッド取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			パッド状態
		*//**************************************************************************/
		virtual MofGamePad GetPad(void) = 0;
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								使用しない環境で呼び出した場合NULLを返す。
				@param			None

				@return			パッド状態
		*//**************************************************************************/
		virtual MofGamePadState* GetPadState(void) = 0;
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								スティックの横への傾きを取得する。
				@param			None

				@return			スティック横入力量(-1.0〜1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickHorizontal(void) = 0;
		/*************************************************************************//*!
				@brief			パッド状態取得<br>
								スティックの縦への傾きを取得する。
				@param			None

				@return			スティック縦入力量(-1.0〜1.0)
		*//**************************************************************************/
		virtual MofFloat GetStickVertical(void) = 0;
	};

	//ポインタ置き換え
	typedef IGamePad*			LPGamePad;
	typedef CDynamicArray< LPGamePad > CGamePadArray,*LPGamePadArray;
}

#endif

//[EOF]