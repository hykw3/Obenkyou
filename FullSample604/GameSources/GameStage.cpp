/*!
@file GameStage.cpp
@brief �Q�[���X�e�[�W����
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	�Q�[���X�e�[�W�N���X����
	//--------------------------------------------------------------------------------------

	//�r���[�ƃ��C�g�̍쐬
	void GameStage::CreateViewLight() {
		auto PtrView = CreateView<SingleView>();
		//�r���[�̃J�����̐ݒ�
		//auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		//PtrView->SetCamera(PtrLookAtCamera);
		//PtrLookAtCamera->SetEye(Vector3(5.0f, 10.0f, -2.0f));
		//PtrLookAtCamera->SetAt(Vector3(5.0f, 5.0f, 1.0f));
		//PtrLookAtCamera->SetMaxArm(90.0f);
		
		auto PtrLookAtCamera = ObjectFactory::Create<MeCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(5.0f, 10.0f, -2.0f));
		PtrLookAtCamera->SetAt(Vector3(5.0f, 5.0f, 1.0f));


		//�}���`���C�g�̍쐬
		auto PtrMultiLight = CreateLight<MultiLight>();
		//�f�t�H���g�̃��C�e�B���O���w��
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
			//�v���[�g�p�̃��b�V�����쐬
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

	//�v���[�g�̍쐬
	void GameStage::CreatePlate() {
		//�X�e�[�W�ւ̃Q�[���I�u�W�F�N�g�̒ǉ�
		auto Ptr = AddGameObject<GameObject>();
		auto PtrTrans = Ptr->GetComponent<Transform>();
		Quaternion Qt;
		Qt.RotationRollPitchYawFromVector(Vector3(XM_PIDIV2, 0, 0));
		PtrTrans->SetScale(200.0f, 200.0f, 1.0f);
		PtrTrans->SetQuaternion(Qt);
		PtrTrans->SetPosition(0.0f, 0.0f, 0.0f);

		auto PtrCollision = Ptr->AddComponent<CollisionRect>();
		//�`��R���|�[�l���g�̒ǉ�
		auto DrawComp = Ptr->AddComponent<PNTStaticDraw>();
		//�`��R���|�[�l���g�Ɍ`��i���b�V���j��ݒ�
		DrawComp->SetMeshResource(L"DEFAULT_SQUARE");
		//�����ɉe���f�肱�ނ悤�ɂ���
		DrawComp->SetOwnShadowActive(true);

		//�`��R���|�[�l���g�e�N�X�`���̐ݒ�
		DrawComp->SetTextureResource(L"SKY_TX");

	}

	//�v���C���[�̍쐬
	void GameStage::CreatePlayer() {
		//�v���[���[�̍쐬
		auto PlayerPtr = AddGameObject<Player>();
		//�V�F�A�z��Ƀv���C���[��ǉ�
		SetSharedGameObject(L"Player", PlayerPtr);
	}

	void GameStage::OnCreate() {
		try {
			//�r���[�ƃ��C�g�̍쐬
			CreateViewLight();
			//�I�u�W�F�N�g�̃O���[�v���쐬����
			auto Group = CreateSharedObjectGroup(L"EnemyGroup");
			//�Q�[���I�u�W�F�N�g�r���_�[
			//GameObjecttXMLBuilder Builder;
			////�Q�[���I�u�W�F�N�g�̓o�^
			//Builder.Register<TilingPlate>(L"TilingPlate");
			//Builder.Register<TilingFixedBox>(L"TilingFixedBox");
			//Builder.Register<Enemy1>(L"Enemy1");
			//Builder.Register<Enemy2>(L"Enemy2");
			//Builder.Register<Enemy3>(L"Enemy3");
			//wstring DataDir;
			//App::GetApp()->GetDataDirectory(DataDir);
			////XML����Q�[���I�u�W�F�N�g�̍\�z
			//wstring XMLStr = DataDir + L"GameStage";
			//XMLStr += Util::IntToWStr(m_StageNum);
			//XMLStr += L".xml";
			//Builder.Build(GetThis<Stage>(), XMLStr, L"GameStage/GameObject");

			//Csv�I�u�W�F�N�g�z�u
			wstring DataDir;
			App::GetApp()->GetDataDirectory(DataDir);
			DataDir += L"StageCsv\\Stage1.csv";
			StageCreate stageCreate(GetThis<GameStage>(), DataDir, Pivot::LeftDown);
			stageCreate.OnCreate();

			//�v���[���[�̍쐬
			CreatePlayer();

			//�J�����̃^�[�Q�b�g�쐬
			//CreateCameraTg();

			//�v���[�g�̍쐬
			CreatePlate();

		}
		catch (...) {
			throw;
		}
	}

}
//end basecross
