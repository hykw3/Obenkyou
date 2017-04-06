/*!
@file Character.h
@brief キャラクターなど
*/

#pragma once
#include "stdafx.h"

namespace basecross{
\
	//--------------------------------------------------------------------------------------
	//	class FixedBox : public GameObject;
	//	用途: 固定のボックス
	//--------------------------------------------------------------------------------------
	class FixedBox : public GameObject {
		Vector3 m_Scale;
		Vector3 m_Rotation;
		Vector3 m_Position;
		
	public:



		//構築と破棄
		//--------------------------------------------------------------------------------------
		/*!
		@brief コンストラクタ
		@param[in]	Scale	スケール
		@param[in]	Rotation	回転
		@param[in]	Position	位置
		*/
		//--------------------------------------------------------------------------------------

		FixedBox(const shared_ptr<Stage>& StagePtr,
			const Vector3& Scale,
			const Vector3& Rotation,
			const Vector3& Position
		);

		/*!
		@brief デストラクタ
		*/
		virtual ~FixedBox();
		//初期化
		virtual void OnCreate() override;
		//操作
	};

	//--------------------------------------------------------------------------------------
	///	壁模様のスプライト
	//--------------------------------------------------------------------------------------
	class WallSprite : public GameObject {
		bool m_Trace;
		Vector2 m_StartScale;
		Vector2 m_StartPos;
		wstring m_TextureKey;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief コンストラクタ
		@param[in]	StagePtr	ステージ
		@param[in]	TextureKey	テクスチャキー
		@param[in]	Trace	透明処理するかどうか
		@param[in]	StartScale	初期スケール
		@param[in]	StartPos	初期位置
		*/
		//--------------------------------------------------------------------------------------
		WallSprite(const shared_ptr<Stage>& StagePtr, const wstring& TextureKey, bool Trace,
			const Vector2& StartScale, const Vector2& StartPos);
		//--------------------------------------------------------------------------------------
		/*!
		@brief デストラクタ
		*/
		//--------------------------------------------------------------------------------------
		virtual ~WallSprite();
		//--------------------------------------------------------------------------------------
		/*!
		@brief 初期化
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief 更新
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnUpdate()override;
	};



	class MultiSpark : public MultiParticle {
	public:
		//構成と破棄
		MultiSpark(shared_ptr<Stage>& StagePtr);
		virtual ~MultiSpark();
		//初期化
		virtual void OnCreate() override;
		void InsertSpark(const Vector3& Pos);




	};


}
//end basecross
