/*!
@file stage_title.h
@brief ゲームステージ
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス
	//--------------------------------------------------------------------------------------
	class stage_title : public Stage {
		//ビューの作成
		void CreateViewLight();
		//プレートの作成
		void CreatePlate();
		//プレイヤーの作成
		void CreatePlayer();
		//Boxの作成
		void CreateBox();
		//Spriteの作成a
		void CreateSprite();


	public:
		//構築と破棄
		stage_title() :Stage() {}
		virtual ~stage_title() {}
		//初期化
		virtual void OnCreate()override;
		virtual void OnUpdate()override;
	};


}
//end basecross

