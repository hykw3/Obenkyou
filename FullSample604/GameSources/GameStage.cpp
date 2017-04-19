/*!
@file GameStage.cpp
@brief ゲームステージ実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス実体
	//--------------------------------------------------------------------------------------

	//ビューとライトの作成
	void GameStage::CreateViewLight() {
		auto PtrView = CreateView<SingleView>();
		//ビューのカメラの設定
		auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(5.0f, 7.0f, -15.0f));
		PtrLookAtCamera->SetAt(Vector3(5.0f, 7.0f, -10.0f));
		//マルチライトの作成
		auto PtrMultiLight = CreateLight<MultiLight>();
		//デフォルトのライティングを指定
		PtrMultiLight->SetDefaultLighting();
	}

	void GameStage::CreateCameraTg() {
		AddGameObject<CameraBox>(
			Vector3(1.0f, 1.0f, 1.0f),
			Vector3(0.0f, 0.0f, 0.0f),
			Vector3(5.0f, 7.0f, 0.0f)


			);
	
	}



	//プレイヤーの作成
	void GameStage::CreatePlayer() {
		//プレーヤーの作成
		auto PlayerPtr = AddGameObject<Player>();
		//シェア配列にプレイヤーを追加
		SetSharedGameObject(L"Player", PlayerPtr);
	}

	void GameStage::OnCreate() {
		try {
			//ビューとライトの作成
			CreateViewLight();
			//オブジェクトのグループを作成する
			auto Group = CreateSharedObjectGroup(L"EnemyGroup");
			//ゲームオブジェクトビルダー
			//GameObjecttXMLBuilder Builder;
			////ゲームオブジェクトの登録
			//Builder.Register<TilingPlate>(L"TilingPlate");
			//Builder.Register<TilingFixedBox>(L"TilingFixedBox");
			//Builder.Register<Enemy1>(L"Enemy1");
			//Builder.Register<Enemy2>(L"Enemy2");
			//Builder.Register<Enemy3>(L"Enemy3");
			//wstring DataDir;
			//App::GetApp()->GetDataDirectory(DataDir);
			////XMLからゲームオブジェクトの構築
			//wstring XMLStr = DataDir + L"GameStage";
			//XMLStr += Util::IntToWStr(m_StageNum);
			//XMLStr += L".xml";
			//Builder.Build(GetThis<Stage>(), XMLStr, L"GameStage/GameObject");

			//Csvオブジェクト配置
			wstring DataDir;
			App::GetApp()->GetDataDirectory(DataDir);
			DataDir += L"StageCsv\\Stage1.csv";
			StageCreate stageCreate(GetThis<GameStage>(), DataDir, Pivot::LeftDown);
			stageCreate.OnCreate();

			//プレーヤーの作成
			CreatePlayer();
			//カメラのターゲット作成
			CreateCameraTg();
		}
		catch (...) {
			throw;
		}
	}

}
//end basecross
