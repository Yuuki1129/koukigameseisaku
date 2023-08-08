/*************************************************************************//*!
					
					@file	WriteChunkFile.inl
					@brief	チャンク管理を行うファイル書き込みクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

/*************************************************************************//*!
		@brief			ブロックサイズ設定
		@param[in]		bs				ブロックサイズ

		@return			TRUE			正常終了<br>
						それ以外		解放エラー、エラーコードを返す。
*//**************************************************************************/
FORCE_INLINE MofBool CWriteChunkFile::SetBlockSize(MofU32 bs){
	m_BlockSize = bs;
	return TRUE;
}
/*************************************************************************//*!
		@brief			ブロックサイズ取得
		@param			None

		@return			ブロックサイズ
*//**************************************************************************/
FORCE_INLINE MofU32 CWriteChunkFile::GetBlockSize(void){
	return m_BlockSize;
}

//[EOF]