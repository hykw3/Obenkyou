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
		auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(5.0f, 7.0f, -15.0f));
		PtrLookAtCamera->SetAt(Vector3(5.0f, 7.0f, -10.0f));
		//�}���`���C�g�̍쐬
		auto PtrMultiLight = CreateLight<MultiLight>();
		//�f�t�H���g�̃��C�e�B���O���w��
		PtrMultiLight->SetDefaultLighting();
	}

	void GameStage::CreateCameraTg() {
		AddGameObject<CameraBox>(
			Vector3(1.0f, 1.0f, 1.0f),
			Vector3(0.0f, 0.0f, 0.0f),
			Vector3(5.0f, 7.0f, 0.0f)


			);
	
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
			CreateCameraTg();
		}
		catch (...) {
			throw;
		}
	}

}
//end basecross
