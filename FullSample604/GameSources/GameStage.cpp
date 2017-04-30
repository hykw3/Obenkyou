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
		//auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		//PtrView->SetCamera(PtrLookAtCamera);
		//PtrLookAtCamera->SetEye(Vector3(5.0f, 10.0f, -2.0f));
		//PtrLookAtCamera->SetAt(Vector3(5.0f, 5.0f, 1.0f));
		//PtrLookAtCamera->SetMaxArm(90.0f);
		
		auto PtrLookAtCamera = ObjectFactory::Create<MeCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(5.0f, 10.0f, -2.0f));
		PtrLookAtCamera->SetAt(Vector3(5.0f, 5.0f, 1.0f));


		//マルチライトの作成
		auto PtrMultiLight = CreateLight<MultiLight>();
		//デフォルトのライティングを指定
		PtrMultiLight->SetDefaultLighting();
	}


	void GameStage::CreateCameraTg() {
		AddGameObject<CameraBox>(
			Vector3(1.0f, 1.0f, 1.0f),
			Vector3(0.0f, 0.0f, 0.0f),
			Vector3(5.0f, 0.0f, 7.0f)


			);
	
	}




	void GameStage::CreatePlateMesh(){
		if (!App::GetApp()->CheckResource<MeshResource>(L"MY_PNTnT_SQUARE")) {
			//プレート用のメッシュを作成
			vector<VertexPositionNormalTexture> vertices;
			vector<VertexPositionNormalTangentTexture> new_pntnt_vertices;
			vector<uint16_t> indices;
			MeshUtill::CreateSquare(1.0f, vertices, indices);
			for (size_t i = 0; i < vertices.size(); i++) {
				VertexPositionNormalTangentTexture new_pntnt_v;
				new_pntnt_v.position = vertices[i].position;
				new_pntnt_v.normal = vertices[i].normal;
				if (vertices[i].textureCoordinate.x == 1.0f) {
					new_pntnt_v.textureCoordinate.x = 20.0f;
				}
				if (vertices[i].textureCoordinate.y == 1.0f) {
					new_pntnt_v.textureCoordinate.y = 20.0f;
				}
				Vector3 n = Vector3EX::Cross(new_pntnt_v.normal, Vector3(0, 1, 0));
				new_pntnt_v.tangent = n;
				new_pntnt_v.tangent.w = 0.0f;
				new_pntnt_vertices.push_back(new_pntnt_v);
			}
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"MY_PNTnT_SQUARE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
		}
	}

	//プレートの作成
	void GameStage::CreatePlate() {
		//ステージへのゲームオブジェクトの追加
		auto Ptr = AddGameObject<GameObject>();
		auto PtrTrans = Ptr->GetComponent<Transform>();
		Quaternion Qt;
		Qt.RotationRollPitchYawFromVector(Vector3(XM_PIDIV2, 0, 0));
		PtrTrans->SetScale(200.0f, 200.0f, 1.0f);
		PtrTrans->SetQuaternion(Qt);
		PtrTrans->SetPosition(0.0f, 0.0f, 0.0f);

		auto PtrCollision = Ptr->AddComponent<CollisionRect>();
		//描画コンポーネントの追加
		auto DrawComp = Ptr->AddComponent<PNTStaticDraw>();
		//描画コンポーネントに形状（メッシュ）を設定
		DrawComp->SetMeshResource(L"DEFAULT_SQUARE");
		//自分に影が映りこむようにする
		DrawComp->SetOwnShadowActive(true);

		//描画コンポーネントテクスチャの設定
		DrawComp->SetTextureResource(L"SKY_TX");

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
			//CreateCameraTg();

			//プレートの作成
			CreatePlate();

		}
		catch (...) {
			throw;
		}
	}

}
//end basecross
