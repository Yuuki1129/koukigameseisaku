/*************************************************************************//*!
					
					@file	MP3File.h
					@brief	MP3ファイルの読み込みとデコードを行うクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MP3FILE__H__

#define		__MP3FILE__H__

//INCLUDE
#include	"../Sound.h"

namespace Mof {
	
	/*******************************//*!
	@brief	MP3ファイルの読み込みとデコードを行うクラス

			MP3ファイルの読み込みとデコードを行うクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMp3File : public IMofNamedObject {
	public:
		/*******************************//*!
		@brief	MP3エンコードビットレート

				MP3エンコードビットレート

		@author	CDW
		*//********************************/
		typedef enum tag_ENCODE
		{
			ENCODE_CBR,
			ENCODE_ABR,
			ENCODE_VBR,
		}Encode;
	protected:
		/*******************//*!
		MP3生ファイル
		*//********************/
		CReadBinaryFile*			m_pFile;
		/*******************//*!
		ACMドライバーハンドル
		*//********************/
		HACMDRIVER					m_hDriver;
		/*******************//*!
		デコード用ACMドライバーID
		*//********************/
		HACMDRIVERID				m_hDriverIdDec;
		/*******************//*!
		ACMストリームハンドル
		*//********************/
		HACMSTREAM					m_hAcmStream;
		/*******************//*!
		ACMストリームヘッダー
		*//********************/
		ACMSTREAMHEADER				m_AcmStreamHeader;
		/*******************//*!
		エンコードビットレートフラグ（CBR/ABR/VBR）
		*//********************/
		Encode						m_BitRateFlag;
		/*******************//*!
		MPEGバージョン番号
		*//********************/
		MofS32						m_Version;
		/*******************//*!
		ID3v1バージョン番号
		*//********************/
		MofU32						m_ID3v1Version;
		/*******************//*!
		ID3v2.2バージョン番号
		*//********************/
		MofU32						m_ID3v22Version;
		/*******************//*!
		ID3v2.3バージョン番号
		*//********************/
		MofU32						m_ID3v23Version;
		/*******************//*!
		ID3v2.4バージョン番号
		*//********************/
		MofU32						m_ID3v24Version;
		/*******************//*!
		MPEGレイヤー
		*//********************/
		MofS32						m_Layer;
		/*******************//*!
		VBR品質((高)0〜100(低))
		*//********************/
		MofU32						m_VBRQuality;
		/*******************//*!
		VBR TOCエントリー
		*//********************/
		MofU8						m_VBRTOC[100];
		/*******************//*!
		ビットレート
		*//********************/
		MofS32						m_BitRate;
		/*******************//*!
		平均ビットレート
		*//********************/
		MofS32						m_AverageBitRate;
		/*******************//*!
		ストリームサイズ
		*//********************/
		MofU32						m_StreamSize;
		/*******************//*!
		デコードデータサイズ
		*//********************/
		MofU32						m_DecodeSize;
		/*******************//*!
		フレーム数
		*//********************/
		MofU32						m_Frames;
		/*******************//*!
		フレームオフセット
		*//********************/
		MofU32						m_FrameOffset;
		/*******************//*!
		フレームサイズ
		*//********************/
		MofU32						m_FrameSize;
		/*******************//*!
		フレームサイズ
		*//********************/
		MofU32						m_FrameDecodeSize;
		/*******************//*!
		フレーム平均サイズ
		*//********************/
		MofU32						m_AveFrameDecodedSize;
		/*******************//*!
		現在位置
		*//********************/
		MofU32						m_Index;
		/*******************//*!
		MP3WAVEフォーマット
		*//********************/
		MPEGLAYER3WAVEFORMAT		m_Mp3WaveFormat;
		/*******************//*!
		WAVEフォーマット
		*//********************/
		WAVEFORMATEX				m_WaveFormat;
		/*******************//*!
		デコード済みデータ
		*//********************/
		CByteArray					m_DecodeBuffer;
		/*******************//*!
		ID3v1タグの生データ
		*//********************/
		CByteArray					m_ID3v1;
		/*******************//*!
		ID3v2.2タグの生データ
		*//********************/
		CByteArray					m_ID3v22;
		/*******************//*!
		ID3v2.3タグの生データ
		*//********************/
		CByteArray					m_ID3v23;
		/*******************//*!
		ID3v2.4タグの生データ
		*//********************/
		CByteArray					m_ID3v24;
		
		/*************************************************************************//*!
				@brief			ヘッダーを読み込む
				@param			None
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ReadHeader(void);
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMp3File();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーテクスチャ

				@return			None
		*//**************************************************************************/
		CMp3File(const CMp3File& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMp3File();
		/*************************************************************************//*!
				@brief			MP3ファイルを読み込む
				@param[in]		pName			ファイル名
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool Load(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			MP3ファイルを読み込む
				@param[in]		pName			名前
				@param[in]		pData			メモリアドレス
				@param[in]		Size			サイズ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		MofBool Load(LPCMofChar pName,LPMofVoid pData,MofU32 Size);
		/*************************************************************************//*!
				@brief			読み込み位置のリセット
				@param			None
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool ResetReadPosition(void);
		/*************************************************************************//*!
				@brief			内容をデコードする
				@param[in]		DSize			出力サイズ
				@param[out]		pData			出力バッファ
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool Decode(MofU32 DSize,LPMofU8 pData);
		/*************************************************************************//*!
				@brief			内容をデコードする
				@param[in]		SSize			元サイズ
				@param[in]		DSize			出力サイズ
				@param[out]		pData			出力バッファ
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool Decode(MofU32 SSize,MofU32 DSize,LPMofU8 pData);

		/*************************************************************************//*!
				@brief			MP3ファイルを読み込んで内容をすべてデコードする
				@param[in]		pName			ファイル名
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool LoadDecode(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			MP3ファイルを読み込んで内容をすべてデコードする
				@param[in]		pName			ファイル名
				@param[out]		pData			出力バッファ
				@param[out]		Size			出力サイズ
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool LoadDecode(LPCMofChar pName,LPMofU8* pData,MofU32* Size);
		/*************************************************************************//*!
				@brief			MP3ファイルを読み込んで内容をすべてデコードする
				@param[in]		pName			ファイル名
				@param[in]		pData			メモリアドレス
				@param[in]		Size			サイズ
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool LoadDecodeMemory(LPCMofChar pName,LPMofVoid pData,MofU32 Size);
		/*************************************************************************//*!
				@brief			MP3ファイルを読み込んで内容をすべてデコードする
				@param[in]		pName			ファイル名
				@param[in]		pFData			メモリアドレス
				@param[in]		FSize			サイズ
				@param[out]		pData			出力バッファ
				@param[out]		Size			出力サイズ
		
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		MofBool LoadDecodeMemory(LPCMofChar pName,LPMofVoid pFData,MofU32 FSize,LPMofU8* pData,MofU32* Size);

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			WAVEフォーマット取得
				@param			None

				@return			WAVEフォーマットの取得
		*//**************************************************************************/
		virtual LPWAVEFORMATEX GetWaveFormat(void);
		/*************************************************************************//*!
				@brief			フレームサイズ取得
				@param			None

				@return			フレームサイズの取得
		*//**************************************************************************/
		virtual MofU32 GetFrameSize(void);
		/*************************************************************************//*!
				@brief			フレームサイズ取得
				@param			None

				@return			フレームサイズの取得
		*//**************************************************************************/
		virtual MofU32 GetFrameDecodeSize(void);
		/*************************************************************************//*!
				@brief			ストリームサイズ取得
				@param			None

				@return			ストリームサイズの取得
		*//**************************************************************************/
		virtual MofU32 GetStreamSize(void);
		/*************************************************************************//*!
				@brief			ストリームサイズ取得
				@param			None

				@return			ストリームサイズの取得
		*//**************************************************************************/
		virtual MofU32 GetStreamDecodeSize(void);
		/*************************************************************************//*!
				@brief			サイズ取得
				@param			None

				@return			サイズの取得
		*//**************************************************************************/
		virtual MofU32 GetSize(void);
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CMp3File,MOF_MP3FILECLASS_ID);
	};
	
	typedef CMp3File* LPMp3File;

	#include	"MP3File.inl"
}

#endif

//[EOF]