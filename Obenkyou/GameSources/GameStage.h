/*!
@file GameStage.h
@brief ゲームステージ
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス
	//--------------------------------------------------------------------------------------
	class GameStage : public Stage {
		//ビューの作成
		void CreateViewLight();
		//プレートの作成
		void CreatePlate();
		//プレイヤーの作成
		void CreatePlayer();
		//Boxの作成
		void CreateBox();
		//Spriteの作成
		void CreateSprite();
		//Sparkの作成
		void CreateSpark();

	public:
		//構築と破棄
		GameStage() :Stage() {}
		virtual ~GameStage() {}

		virtual void OnUpdate()override;
		//初期化
		virtual void OnCreate()override;
	};


}
//end basecross

