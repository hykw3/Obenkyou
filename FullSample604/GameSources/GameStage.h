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
		void CreatePlateMesh();
		//プレートの作成
		void CreatePlate();
		//プレイヤーの作成
		void CreatePlayer();
		//カメラのターゲット作成

		void CreateCameraTg();
		///ステージナンバー
		int m_StageNum;
	public:
		//構築と破棄
		GameStage(int StageNum) :Stage(),m_StageNum(StageNum){}
		virtual ~GameStage() {}
		//初期化
		virtual void OnCreate()override;
	};


}
//end basecross

