/*************************************************************************//*!
					
					@file	Vector3.h
					@brief	3Dベクトル演算関連

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__VECTOR3__H__

#define		__VECTOR3__H__

//INCLUDE
#include	"Vector2.h"

namespace Mof {
	
	/*******************************//*!
	@brief	3D座標構造体

			3D座標を扱うための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Vector3Impl {
		union {
			float					fv[3];
			struct {
				MofFloat			x;						//!<X
				MofFloat			y;						//!<Y
				MofFloat			z;						//!<Z
			};
		};
	}Float3;
	
	/*******************************//*!
	@brief	3D座標構造体

			3D座標を扱うための構造体。

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Vector3 : public Vector3Impl {
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		Vector3();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z

				@return			None
		*//**************************************************************************/
		Vector3(MofFloat vx,MofFloat vy,MofFloat vz);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		Vector3(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		Vector3(const Vector3& pObj);
					
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
		Vector3& operator = ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		Vector3& operator = ( const Vector2Impl& v );
		/*************************************************************************//*!
				@brief			+取得
		*//**************************************************************************/
		Vector3 operator + () const;
		/*************************************************************************//*!
				@brief			-取得
		*//**************************************************************************/
		Vector3 operator - () const;
		/*************************************************************************//*!
				@brief			+=演算
		*//**************************************************************************/
		Vector3& operator += ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			-=演算
		*//**************************************************************************/
		Vector3& operator -= ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			floatとの*=演算
		*//**************************************************************************/
		Vector3& operator *= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector3との*=演算
		*//**************************************************************************/
		Vector3& operator *= ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			Matrix33との*=演算
		*//**************************************************************************/
		Vector3& operator *= ( const Matrix33& m );
		/*************************************************************************//*!
				@brief			Matrix44との*=演算
		*//**************************************************************************/
		Vector3& operator *= ( const Matrix44& m );
		/*************************************************************************//*!
				@brief			floatとの/=演算
		*//**************************************************************************/
		Vector3& operator /= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector3との/=演算
		*//**************************************************************************/
		Vector3& operator /= ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			+演算
		*//**************************************************************************/
		Vector3 operator + ( const Vector3Impl& v ) const;
		/*************************************************************************//*!
				@brief			-演算
		*//**************************************************************************/
		Vector3 operator - ( const Vector3Impl& v ) const;
		/*************************************************************************//*!
				@brief			floatとの*演算
		*//**************************************************************************/
		Vector3 operator * ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector3との*演算
		*//**************************************************************************/
		Vector3 operator * ( const Vector3Impl& v ) const;
		/*************************************************************************//*!
				@brief			Matrix33との*演算
		*//**************************************************************************/
		Vector3 operator * ( const Matrix33& m ) const;
		/*************************************************************************//*!
				@brief			Matrix44との*演算
		*//**************************************************************************/
		Vector3 operator * ( const Matrix44& m ) const;
		/*************************************************************************//*!
				@brief			floatとの/演算
		*//**************************************************************************/
		Vector3 operator / ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector3との/演算
		*//**************************************************************************/
		Vector3 operator / ( const Vector3Impl& v ) const;
		/*************************************************************************//*!
				@brief			配列指定によるVector3メンバへのアクセス
		*//**************************************************************************/
		MofFloat& operator [] ( int i );
		/*************************************************************************//*!
				@brief			配列指定によるVector3メンバへのアクセス
		*//**************************************************************************/
		const MofFloat& operator [] ( int i ) const;
		/*************************************************************************//*!
				@brief			==判断
		*//**************************************************************************/
		bool operator == ( const Vector3Impl& v ) const;
		/*************************************************************************//*!
				@brief			!=判断
		*//**************************************************************************/
		bool operator != ( const Vector3Impl& v ) const;
	}Vector3;
	
	/*************************************************************************//*!
			@brief			+演算
	*//**************************************************************************/
	Vector3 operator + (const Vector3Impl& v1, const Vector3Impl& v2);
	/*************************************************************************//*!
			@brief			+演算
	*//**************************************************************************/
	Vector3 operator - (const Vector3Impl& v1, const Vector3Impl& v2);

	/*******************************//*!
	@brief	3D座標演算クラス

			Vector3構造体を扱うためのスタティッククラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CVector3Utilities {
	public:
		/*************************************************************************//*!
				@brief			ベクトルの長さを調べる
				@param[in]		v			調べるベクトル

				@return			引数ベクトルの長さ
		*//**************************************************************************/
		static MofFloat Length(const Vector3Impl& v);
		/*************************************************************************//*!
				@brief			ベクトルの長さの2乗を調べる
				@param[in]		v			調べるベクトル

				@return			引数ベクトルの長さの2乗
		*//**************************************************************************/
		static MofFloat LengthSquare(const Vector3Impl& v);
		/*************************************************************************//*!
				@brief			ベクトル間の距離を調べる
				@param[in]		v1			調べるベクトル
				@param[in]		v2			調べるベクトル

				@return			引数ベクトルの長さ
		*//**************************************************************************/
		static MofFloat Distance(const Vector3Impl& v1, const Vector3Impl& v2);
		/*************************************************************************//*!
				@brief			ベクトルの内積を求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２

				@return			内積
		*//**************************************************************************/
		static MofFloat Dot(const Vector3Impl& v1,const Vector3Impl& v2);
		/*************************************************************************//*!
				@brief			ベクトルの内積から二つのベクトルのなす角度をラジアン単位で求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２

				@return			角度
		*//**************************************************************************/
		static MofFloat DotAngle(const Vector3Impl& v1,const Vector3Impl& v2);
		/*************************************************************************//*!
				@brief			単位ベクトルを求める
				@param[in]		v1			計算ベクトル
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void Normal(const Vector3Impl& v1,Vector3Impl& OutVec);
		/*************************************************************************//*!
				@brief			ベクトルの外積を求める
				@param[in]		v1			計算ベクトル１
				@param[in]		v2			計算ベクトル２
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void Cross(const Vector3Impl& v1,const Vector3Impl& v2,Vector3Impl& OutVec);

		/*************************************************************************//*!
				@brief			ベクトルをX軸で回転させる
				@param[in]		v			計算ベクトル
				@param[in]		Ang			角度
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void RotationX(const Vector3Impl& v,const MofFloat Ang,Vector3Impl& OutVec);
		/*************************************************************************//*!
				@brief			ベクトルをY軸で回転させる
				@param[in]		v			計算ベクトル
				@param[in]		Ang			角度
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void RotationY(const Vector3Impl& v,const MofFloat Ang,Vector3Impl& OutVec);
		/*************************************************************************//*!
				@brief			ベクトルをZ軸で回転させる
				@param[in]		v			計算ベクトル
				@param[in]		Ang			角度
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		static void RotationZ(const Vector3Impl& v,const MofFloat Ang,Vector3Impl& OutVec);

		/*************************************************************************//*!
				@brief			計算ベクトルの平面投影ベクトルを求める
				@param[in]		v			計算ベクトル
				@param[out]		p			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void PlaneSpace(const Vector3Impl& v,Vector3Impl& p);
		/*************************************************************************//*!
				@brief			計算ベクトルの平面投影ベクトルを求める
				@param[in]		v			計算ベクトル
				@param[out]		p			出力ベクトル
				@param[out]		q			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void PlaneSpace(const Vector3Impl& v,Vector3Impl& p,Vector3Impl& q);
		
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		v			計算ベクトル
				@param[in]		m			計算行列
				@param[out]		Out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void TransformCoord(const Vector3Impl& v,const Matrix33& m,Vector3Impl& Out);
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		v			計算ベクトル
				@param[in]		m			計算行列
				@param[out]		Out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void TransformCoord(const Vector3Impl& v,const Matrix44& m,Vector3Impl& Out);
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		v			計算ベクトル
				@param[in]		m			計算行列
				@param[out]		Out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void TransformNormal(const Vector3Impl& v,const Matrix44& m,Vector3Impl& Out);

		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		src			元ベクトル
				@param[in]		pivot		中心
				@param[in]		Angle		回転
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void RotateAround(Vector3& src, Vector3& pivot, Vector3& Angle, Vector3& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		src			元ベクトル
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void RotateAround(Vector3& src, Vector3& pivot, Vector3& Axis, MofFloat Angle, Vector3& out);

		/*************************************************************************//*!
				@brief			ベクトル１からベクトル２へとt(０〜１)の値で線形補間をおこなう
				@param[in]		v1			元ベクトル１
				@param[in]		v2			元ベクトル２
				@param[in]		t			変化率（０〜１の範囲を取る）

				@return			補間ベクトル
		*//**************************************************************************/
		static Vector3 Lerp(Vector3& v1, Vector3& v2, MofFloat t);
		/*************************************************************************//*!
				@brief			ベクトル１からベクトル２へとstepで移動をおこなう<br>
								stepの値がベクトル間の距離より大きい場合、v2の位置で停止する
				@param[in]		v1			元ベクトル１
				@param[in]		v2			元ベクトル２
				@param[in]		step		移動量

				@return			補間ベクトル
		*//**************************************************************************/
		static Vector3 Move(Vector3& v1, Vector3& v2, MofFloat step);

		/*************************************************************************//*!
				@brief			ベクトルの大きさを拡張
				@param[in,out]	src			元ベクトル
				@param[in]		l			大きさ

				@return			None
		*//**************************************************************************/
		static void Extension(Vector3& src, MofFloat l);
		/*************************************************************************//*!
				@brief			ベクトルの大きさを拡張
				@param[in]		src			元ベクトル
				@param[in]		l			大きさ
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		static void Extension(Vector3& src, MofFloat l, Vector3& out);
	private:
		//作成を禁止する
		CVector3Utilities(){};
		CVector3Utilities(const CVector3Utilities& pObj){};
	};

	/*******************************//*!
	@brief	3D座標クラス

			Vector3構造体を扱うための関数を含めたクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CVector3 : public Vector3 , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CVector3();
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z

				@return			None
		*//**************************************************************************/
		CVector3(MofFloat vx,MofFloat vy,MofFloat vz);
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param[in]		pv			座標

				@return			None
		*//**************************************************************************/
		CVector3(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		CVector3(const Vector3& pObj);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーベクトル

				@return			None
		*//**************************************************************************/
		CVector3(const CVector3& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		~CVector3();

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
		MofFloat Dot(const Vector3& v) const;
		/*************************************************************************//*!
				@brief			ベクトルの内積から二つのベクトルのなす角度をラジアン単位で求める
				@param[in]		v			計算ベクトル

				@return			角度
		*//**************************************************************************/
		MofFloat DotAngle(const Vector3& v) const;
		/*************************************************************************//*!
				@brief			単位ベクトルを求める
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		void Normal(Vector3& OutVec) const;
		/*************************************************************************//*!
				@brief			ベクトルの外積を求める
				@param[in]		v			計算ベクトル
				@param[out]		OutVec		出力ベクトル

				@return			None
		*//**************************************************************************/
		void Cross(const Vector3& v,Vector3& OutVec) const;
		
		/*************************************************************************//*!
				@brief			ベクトルをX軸で回転させる
				@param[in]		Ang			角度

				@return			None
		*//**************************************************************************/
		void RotationX(const MofFloat Ang);
		/*************************************************************************//*!
				@brief			ベクトルをY軸で回転させる
				@param[in]		Ang			角度

				@return			None
		*//**************************************************************************/
		void RotationY(const MofFloat Ang);
		/*************************************************************************//*!
				@brief			ベクトルをZ軸で回転させる
				@param[in]		Ang			角度

				@return			None
		*//**************************************************************************/
		void RotationZ(const MofFloat Ang);
		
		/*************************************************************************//*!
				@brief			計算ベクトルの平面投影ベクトルを求める
				@param[out]		p			出力ベクトル

				@return			None
		*//**************************************************************************/
		void PlaneSpace(Vector3& p);
		/*************************************************************************//*!
				@brief			計算ベクトルの平面投影ベクトルを求める
				@param[out]		p			出力ベクトル
				@param[out]		q			出力ベクトル

				@return			None
		*//**************************************************************************/
		void PlaneSpace(Vector3& p,Vector3& q);
		
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列

				@return			None
		*//**************************************************************************/
		void TransformCoord(const Matrix33& m);
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列
				@param[out]		Out			出力ベクトル

				@return			None
		*//**************************************************************************/
		void TransformCoord(const Matrix33& m,Vector3& Out) const;
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列

				@return			None
		*//**************************************************************************/
		void TransformCoord(const Matrix44& m);
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列
				@param[out]		Out			出力ベクトル

				@return			None
		*//**************************************************************************/
		void TransformCoord(const Matrix44& m,Vector3& Out) const;
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列

				@return			None
		*//**************************************************************************/
		void TransformNormal(const Matrix44& m);
		/*************************************************************************//*!
				@brief			指定行列で変換をする
				@param[in]		m			計算行列
				@param[out]		q			出力ベクトル

				@return			None
		*//**************************************************************************/
		void TransformNormal(const Matrix44& m,Vector3& Out) const;

		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転

				@return			None
		*//**************************************************************************/
		void RotateAround(Vector3& pivot, Vector3& Angle);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		pivot		中心
				@param[in]		Angle		回転
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		void RotateAround(Vector3& pivot, Vector3& Angle, Vector3& out);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度

				@return			None
		*//**************************************************************************/
		void RotateAround(Vector3& pivot, Vector3& Axis, MofFloat Angle);
		/*************************************************************************//*!
				@brief			指定した点を中心とした回転をした位置を求める
				@param[in]		pivot		中心
				@param[in]		Axis		回転軸
				@param[in]		Angle		回転角度
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		void RotateAround(Vector3& pivot, Vector3& Axis, MofFloat Angle, Vector3& out);
		
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
		void Cliping(const Vector3& l,const Vector3& h);

		/*************************************************************************//*!
				@brief			ベクトルの大きさを拡張
				@param[in]		l			大きさ

				@return			None
		*//**************************************************************************/
		void Extension(MofFloat l);
		/*************************************************************************//*!
				@brief			ベクトルの大きさを拡張
				@param[in]		l			大きさ
				@param[out]		out			出力ベクトル

				@return			None
		*//**************************************************************************/
		void Extension(MofFloat l, Vector3& out);

		/*************************************************************************//*!
				@brief			数値の設定
				@param[in]		vx			X
				@param[in]		vy			Y
				@param[in]		vz			Z

				@return			None
		*//**************************************************************************/
		void SetValue(MofFloat vx,MofFloat vy,MofFloat vz);
		/*************************************************************************//*!
				@brief			ベクトルの大きさを設定
				@param[in]		l			大きさ

				@return			None
		*//**************************************************************************/
		void SetLength(MofFloat l);
		
		/*************************************************************************//*!
				@brief			最大の数値の取得
				@param			None

				@return			X,Y,Zの最大値
		*//**************************************************************************/
		MofFloat GetMaxValue(void);
		/*************************************************************************//*!
				@brief			絶対値の最大の数値の取得
				@param			None

				@return			X,Y,Zの絶対値の最大値
		*//**************************************************************************/
		MofFloat GetMaxAbsValue(void);
		/*************************************************************************//*!
				@brief			最低の数値の取得
				@param			None

				@return			X,Y,Zの最小値
		*//**************************************************************************/
		MofFloat GetMinValue(void);
		/*************************************************************************//*!
				@brief			絶対値の最低の数値の取得
				@param			None

				@return			X,Y,Zの絶対値の最小値
		*//**************************************************************************/
		MofFloat GetMinAbsValue(void);

		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector3& operator = (const Vector2Impl& v);
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector3& operator = ( const Vector3Impl& v );
		/*************************************************************************//*!
				@brief			代入
		*//**************************************************************************/
		CVector3& operator = ( const Vector3& v );

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTEQUAL(CVector3,MOF_VECTOR3CLASS_ID);
	};
	
	//ポインタ置き換え
	typedef CVector3*			LPVector3;

	//INLINE INCLUDE
	#include	"Vector3.inl"

}

#endif

//[EOF]