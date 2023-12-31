/*************************************************************************//*!
					
					@file	Vector4.h
					@brief	4Dベクトル演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__VECTOR4__H__

#define		__VECTOR4__H__

//INCLUDE
#include	"Vector3.h"

namespace Mof {
	
	
	/*******************************//*!
	@brief	4D座標構造体

			4D座標を扱うための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Vector4Impl {
		union {

			float					fv[4];
			struct {
				union {
					MofFloat		r;						//!<XもしくはR
					MofFloat		x;						//!<XもしくはR
				};
				union {
					MofFloat		g;						//!<YもしくはG
					MofFloat		y;						//!<YもしくはG
				};
				union {
					MofFloat		b;						//!<ZもしくはB
					MofFloat		z;						//!<ZもしくはB
				};
				union {
					MofFloat		a;						//!<WもしくはA
					MofFloat		w;						//!<WもしくはA
				};
			};
		};
	}Vector4Impl,Float4;

	/*******************************//*!
	@brief	4D座標構造体

			4D座標を扱うための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Vector4 : public Vector4Impl {
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		Vector4();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z
				@param[in]		vw			W

				@return			None
		*//**************************************************************************/
		Vector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		Vector4(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		Vector4(const Vector4& pObj);
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			floatキャスト<br>
								内部の座標をfloatポインタとしてそのまま返す。
		*//**************************************************************************/
		operator LPMofFloat ();
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		Vector4& operator = ( const Vector4Impl& v );
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		Vector4& operator = ( const Vector2Impl& v );
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		Vector4& operator = ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			+取得
		*//**************************************************************************/
		Vector4 operator + () const;
		/*************************************************************************//*!
				@brief			-取得
		*//**************************************************************************/
		Vector4 operator - () const;
		/*************************************************************************//*!
				@brief			+=演算
		*//**************************************************************************/
		Vector4& operator += ( const Vector4Impl& v );
		/*************************************************************************//*!
				@brief			-=演算
		*//**************************************************************************/
		Vector4& operator -= ( const Vector4Impl& v );
		/*************************************************************************//*!
				@brief			floatとの*=演算
		*//**************************************************************************/
		Vector4& operator *= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector4との*=演算
		*//**************************************************************************/
		Vector4& operator *= ( const Vector4Impl& v );
		/*************************************************************************//*!
				@brief			Matrix44との*=演算
		*//**************************************************************************/
		Vector4& operator *= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			floatとの/=演算
		*//**************************************************************************/
		Vector4& operator /= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector4との/=演算
		*//**************************************************************************/
		Vector4& operator /= ( const Vector4Impl& v );
		/*************************************************************************//*!
				@brief			+演算
		*//**************************************************************************/
		Vector4 operator + ( const Vector4Impl& v ) const;
		/*************************************************************************//*!
				@brief			-演算
		*//**************************************************************************/
		Vector4 operator - ( const Vector4Impl& v ) const;
		/*************************************************************************//*!
				@brief			floatとの*演算
		*//**************************************************************************/
		Vector4 operator * ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector4との*演算
		*//**************************************************************************/
		Vector4 operator * ( const Vector4Impl& v ) const;
		/*************************************************************************//*!
				@brief			Matrix44との*演算
		*//**************************************************************************/
		Vector4 operator * ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			floatとの/演算
		*//**************************************************************************/
		Vector4 operator / ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector4との/演算
		*//**************************************************************************/
		Vector4 operator / ( const Vector4Impl& v ) const;
		/*************************************************************************//*!
				@brief			配列指定によるVector4メンバへのアクセス
		*//**************************************************************************/
		MofFloat& operator [] ( int i );
		/*************************************************************************//*!
				@brief			配列指定によるVector4メンバへのアクセス
		*//**************************************************************************/
		const MofFloat& operator [] ( int i ) const;
		/*************************************************************************//*!
				@brief			==判断
		*//**************************************************************************/
		bool operator == ( const Vector4Impl& v ) const;
		/*************************************************************************//*!
				@brief			!=判断
		*//**************************************************************************/
		bool operator != ( const Vector4Impl& v ) const;
	}Vector4,Color;
	
	/*************************************************************************//*!
			@brief			+演算
	*//**************************************************************************/
	Vector3 operator + (const Vector3Impl& v1, const Vector3Impl& v2);
	/*************************************************************************//*!
			@brief			+演算
	*//**************************************************************************/
	Vector3 operator - (const Vector3Impl& v1, const Vector3Impl& v2);

	/*******************************//*!
	@brief	4D座標演算クラス

			Vector4構造体を扱うためのスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CVector4Utilities {
	public:
		/*************************************************************************//*!
				@brief			ベクトルの長さを調べる
				@param[in]		v			調べるベクトル

				@return			引数ベクトルの長さ
		*//**************************************************************************/
		static MofFloat Length(const Vector4Impl& v);
		/*************************************************************************//*!
				@brief			ベクトルの長さの2乗を調べる
				@param[in]		v			調べるベクトル

				@return			引数ベクトルの長さの2乗
		*//**************************************************************************/
		static MofFloat LengthSquare(const Vector4Impl& v);
		/*************************************************************************//*!
				@brief			ベクトルの内積を求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２

				@return			内積
		*//**************************************************************************/
		static MofFloat Dot(const Vector4Impl& v1,const Vector4Impl& v2);
		/*************************************************************************//*!
				@brief			単位ベクトルを求める
				@param[in]		v1			計算ベクトル
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void Normal(const Vector4Impl& v1,Vector4Impl& OutVec);
		/*************************************************************************//*!
				@brief			ベクトルの外積を求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２
				@param[in]		v3			計算ベクトル３
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void Cross(const Vector4Impl& v1,const Vector4Impl& v2,const Vector4Impl& v3,Vector4Impl& OutVec);

		/*************************************************************************//*!
				@brief			ベクトル１からベクトル２へとt(０〜１)の値で線形補間をおこなう
				@param[in]		v1			元ベクトル１
				@param[in]		v2			元ベクトル２
				@param[in]		t			変化率（０〜１の範囲を取る）

				@return			補間ベクトル
		*//**************************************************************************/
		static Vector4 Lerp(Vector4& v1, Vector4& v2, MofFloat t);
		/*************************************************************************//*!
				@brief			ベクトル１からベクトル２へとstepで移動をおこなう<br>
								stepの値がベクトル間の距離より大きい場合、v2の位置で停止する
				@param[in]		v1			元ベクトル１
				@param[in]		v2			元ベクトル２
				@param[in]		step		移動量

				@return			補間ベクトル
		*//**************************************************************************/
		static Vector4 Move(Vector4& v1, Vector4& v2, MofFloat step);

		/*************************************************************************//*!
				@brief			U32カラーから変換
				@param[in]		col			色
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void SetU32Color(MofU32 col,Vector4Impl& OutVec);
		/*************************************************************************//*!
				@brief			U32カラーへの変換
				@param[in]		v			変換ベクトル

				@return			U32カラー
		*//**************************************************************************/
		static MofU32 ToU32Color(const Vector4Impl& v);

	private:
		//作成を禁止する
		CVector4Utilities(){};
		CVector4Utilities(const CVector4Utilities& pObj){};
	};

	/*******************************//*!
	@brief	4D座標クラス

			Vector4構造体を扱うための関数を含めたクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CVector4 : public Vector4 , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CVector4();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z
				@param[in]		vw			W

				@return			None
		*//**************************************************************************/
		CVector4(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		CVector4(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		CVector4(const Vector4& pObj);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		CVector4(const CVector4& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~CVector4();
		
		/*************************************************************************//*!
				@brief			ベクトルの長さを調べる
				@param			None

				@return			ベクトルの長さ
		*//**************************************************************************/
		MofFloat Length(void) const;
		/*************************************************************************//*!
				@brief			ベクトルの長さの2乗を調べる
				@param			None

				@return			ベクトルの長さの2乗
		*//**************************************************************************/
		MofFloat LengthSquare(void) const;
		/*************************************************************************//*!
				@brief			ベクトルの内積を求める
				@param[in]		v			計算ベクトル

				@return			内積
		*//**************************************************************************/
		MofFloat Dot(const Vector4& v) const;
		/*************************************************************************//*!
				@brief			単位ベクトルを求める
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		void Normal(Vector4& OutVec) const;
		/*************************************************************************//*!
				@brief			ベクトルの外積を求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		void Cross(const Vector4& v1,const Vector4& v2,Vector4& OutVec);
		
		/*************************************************************************//*!
				@brief			U32カラーから変換
				@param[in]		col			色

				@return			None
		*//**************************************************************************/
		void SetU32Color(MofU32 col);
		/*************************************************************************//*!
				@brief			U32カラーへの変換
				@param			None

				@return			U32カラー
		*//**************************************************************************/
		MofU32 ToU32Color(void) const;
		
		/*************************************************************************//*!
				@brief			値を絶対値にする
				@param			None

				@return			None
		*//**************************************************************************/
		void Absolute(void);
		/*************************************************************************//*!
				@brief			値のクリッピング
				@param[in]		l			最小値
				@param[in]		h			最大値

				@return			None
		*//**************************************************************************/
		void Cliping(const MofFloat l,const MofFloat h);
		/*************************************************************************//*!
				@brief			値のクリッピング
				@param[in]		l			最小値
				@param[in]		h			最大値

				@return			None
		*//**************************************************************************/
		void Cliping(const Vector4& l,const Vector4& h);
		
		/*************************************************************************//*!
				@brief			数値の設定
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z
				@param[in]		vw			W

				@return			None
		*//**************************************************************************/
		void SetValue(MofFloat vx,MofFloat vy,MofFloat vz,MofFloat vw);
		
		/*************************************************************************//*!
				@brief			最大の数値の取得
				@param			None

				@return			X,Y,Z,Wの最大値
		*//**************************************************************************/
		MofFloat GetMaxValue(void);
		/*************************************************************************//*!
				@brief			絶対値の最大の数値の取得
				@param			None

				@return			X,Y,Z,Wの絶対値の最大値
		*//**************************************************************************/
		MofFloat GetMaxAbsValue(void);
		/*************************************************************************//*!
				@brief			最低の数値の取得
				@param			None

				@return			X,Y,Z,Wの最小値
		*//**************************************************************************/
		MofFloat GetMinValue(void);
		/*************************************************************************//*!
				@brief			絶対値の最低の数値の取得
				@param			None

				@return			X,Y,Z,Wの絶対値の最小値
		*//**************************************************************************/
		MofFloat GetMinAbsValue(void);

		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector4& operator = (const Vector2Impl& v);
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector4& operator = (const Vector3Impl& v);
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector4& operator = (const Vector4Impl& v);
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector4& operator = ( const Vector4& v );

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTEQUAL(CVector4,MOF_VECTOR4CLASS_ID);
	};
	
	//ポインタ置き換え
	typedef CVector4*			LPVector4;

	//INLINE INCLUDE
	#include	"Vector4.inl"

}

#endif

//[EOF]