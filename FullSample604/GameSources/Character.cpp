/*!
@file Character.cpp
@brief �L�����N�^�[�Ȃǎ���
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{


	//�\�z�Ɣj��
	TilingPlate::TilingPlate(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode):
		GameObject(StagePtr)
	{
		try {
			auto ScaleStr = XmlDocReader::GetAttribute(pNode, L"Scale");
			auto RotStr = XmlDocReader::GetAttribute(pNode, L"Rot");
			auto PosStr = XmlDocReader::GetAttribute(pNode, L"Pos");
			auto UPicStr = XmlDocReader::GetAttribute(pNode, L"UPic");
			auto VPicStr = XmlDocReader::GetAttribute(pNode, L"VPic");
			//�g�[�N���i�J�����j�̔z��
			vector<wstring> Tokens;
			//�g�[�N���i�J�����j�P�ʂŕ�����𒊏o(L','���f���~�^�Ƃ��ċ敪��)
			Tokens.clear();
			Util::WStrToTokenVector(Tokens, ScaleStr, L',');
			//�e�g�[�N���i�J�����j���X�P�[���A��]�A�ʒu�ɓǂݍ���
			m_Scale = Vector3(
				(float)_wtof(Tokens[0].c_str()),
				(float)_wtof(Tokens[1].c_str()),
				(float)_wtof(Tokens[2].c_str())
			);
			Tokens.clear();
			Util::WStrToTokenVector(Tokens, RotStr, L',');
			Vector3 Rot;
			//��]�́uXM_PIDIV2�v�̕�����ɂȂ��Ă���ꍇ������
			Rot.x = (Tokens[0] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[0].c_str());
			Rot.y = (Tokens[1] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[1].c_str());
			Rot.z = (Tokens[2] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[2].c_str());
			//�v���[�g�̉�]�̈����̓N�I�[�^�j�I���ɂȂ��Ă���̂ŕϊ�
			m_Qt.RotationRollPitchYawFromVector(Rot);
			Tokens.clear();
			Util::WStrToTokenVector(Tokens, PosStr, L',');
			m_Position = Vector3(
				(float)_wtof(Tokens[0].c_str()),
				(float)_wtof(Tokens[1].c_str()),
				(float)_wtof(Tokens[2].c_str())
			);
			m_UPic = (float)_wtof(UPicStr.c_str());
			m_VPic = (float)_wtof(VPicStr.c_str());
		}
		catch (...) {
			throw;
		}
	}

	TilingPlate::~TilingPlate() {

	}
	//������
	void TilingPlate::OnCreate() {
		auto PtrTrans = GetComponent<Transform>();
		PtrTrans->SetScale(m_Scale);
		PtrTrans->SetQuaternion(m_Qt);
		PtrTrans->SetPosition(m_Position);
		AddComponent<CollisionRect>();

		vector<VertexPositionNormalTexture> vertices;
		vector<uint16_t> indices;
		MeshUtill::CreateSquare(1.0f, vertices, indices);
		float UCount = m_Scale.x / m_UPic;
		float VCount = m_Scale.y / m_VPic;
		for (size_t i = 0; i < vertices.size(); i++) {
			if (vertices[i].textureCoordinate.x >= 1.0f) {
				vertices[i].textureCoordinate.x = UCount;
			}
			if (vertices[i].textureCoordinate.y >= 1.0f) {
				vertices[i].textureCoordinate.y = VCount;
			}
		}
		//�`��R���|�[�l���g�̒ǉ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`��R���|�[�l���g�Ɍ`��i���b�V���j��ݒ�
		PtrDraw->CreateOriginalMesh(vertices, indices);
		PtrDraw->SetOriginalMeshUse(true);
		PtrDraw->SetFogEnabled(true);
		//�����ɉe���f�肱�ނ悤�ɂ���
		PtrDraw->SetOwnShadowActive(true);
		//�`��R���|�[�l���g�e�N�X�`���̐ݒ�
		PtrDraw->SetTextureResource(L"SKY_TX");
		//�^�C�����O�ݒ�
		PtrDraw->SetSamplerState(SamplerState::LinearWrap);
	}

	TilingFixedBox::TilingFixedBox(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode) :
		GameObject(StagePtr)
	{
		auto ScaleStr = XmlDocReader::GetAttribute(pNode, L"Scale");
		auto RotStr = XmlDocReader::GetAttribute(pNode, L"Rot");
		auto PosStr = XmlDocReader::GetAttribute(pNode, L"Pos");
		auto UPicStr = XmlDocReader::GetAttribute(pNode, L"UPic");
		auto VPicStr = XmlDocReader::GetAttribute(pNode, L"VPic");
		//�g�[�N���i�J�����j�̔z��
		vector<wstring> Tokens;
		//�g�[�N���i�J�����j�P�ʂŕ�����𒊏o(L','���f���~�^�Ƃ��ċ敪��)
		Tokens.clear();
		Util::WStrToTokenVector(Tokens, ScaleStr, L',');
		//�e�g�[�N���i�J�����j���X�P�[���A��]�A�ʒu�ɓǂݍ���
		m_Scale = Vector3(
			(float)_wtof(Tokens[0].c_str()),
			(float)_wtof(Tokens[1].c_str()),
			(float)_wtof(Tokens[2].c_str())
		);
		Tokens.clear();
		Util::WStrToTokenVector(Tokens, RotStr, L',');
		//��]�́uXM_PIDIV2�v�̕�����ɂȂ��Ă���ꍇ������
		m_Rotation.x = (Tokens[0] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[0].c_str());
		m_Rotation.y = (Tokens[1] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[1].c_str());
		m_Rotation.z = (Tokens[2] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[2].c_str());
		Tokens.clear();
		Util::WStrToTokenVector(Tokens, PosStr, L',');
		m_Position = Vector3(
			(float)_wtof(Tokens[0].c_str()),
			(float)_wtof(Tokens[1].c_str()),
			(float)_wtof(Tokens[2].c_str())
		);
		m_UPic = (float)_wtof(UPicStr.c_str());
		m_VPic = (float)_wtof(VPicStr.c_str());
	}

	TilingFixedBox::TilingFixedBox
	(
		const shared_ptr<Stage>& StagePtr,
		const Vector3 & Scale, 
		const Vector3 & Rotation, 
		const Vector3 & Position
	):
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Rotation(Rotation),
		m_Position(Position)
	{}

	TilingFixedBox::~TilingFixedBox() {}
	//������
	void TilingFixedBox::OnCreate() {
		auto PtrTrans = GetComponent<Transform>();
		PtrTrans->SetScale(m_Scale);
		PtrTrans->SetRotation(m_Rotation);
		PtrTrans->SetPosition(m_Position);
		auto Coll = AddComponent<CollisionObb>();
		Coll->SetFixed(true);
		vector<VertexPositionNormalTexture> vertices;
		vector<uint16_t> indices;
		MeshUtill::CreateCube(1.0f, vertices, indices);
		float UCount = m_Scale.x / m_UPic;
		float VCount = m_Scale.y / m_VPic;
		for (size_t i = 0; i < vertices.size(); i++) {
			if (vertices[i].textureCoordinate.x >= 1.0f) {
				vertices[i].textureCoordinate.x = UCount;
			}
			if (vertices[i].textureCoordinate.y >= 1.0f) {
				vertices[i].textureCoordinate.y = VCount;
			}
		}
		//�`��R���|�[�l���g�̒ǉ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`��R���|�[�l���g�Ɍ`��i���b�V���j��ݒ�
		PtrDraw->CreateOriginalMesh(vertices, indices);
		PtrDraw->SetOriginalMeshUse(true);
		PtrDraw->SetFogEnabled(true);
		//�����ɉe���f�肱�ނ悤�ɂ���
		PtrDraw->SetOwnShadowActive(true);
		//�`��R���|�[�l���g�e�N�X�`���̐ݒ�
		PtrDraw->SetTextureResource(L"WALL_TX");
		//�^�C�����O�ݒ�
		PtrDraw->SetSamplerState(SamplerState::LinearWrap);

	}
	//--------------------------------------------------------------------------------------
	//	�p�r: �J����
	//--------------------------------------------------------------------------------------
	CameraBox::CameraBox(
		const shared_ptr<Stage>& StagePtr,
		const Vector3 & Scale,
		const Vector3 & Rotation,
		const Vector3 & Position
		) :
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Rotation(Rotation),
		m_Position(Position)
	{
	}
	CameraBox::~CameraBox() {}
	void CameraBox::OnCreate() {
		auto PtrTransform = GetComponent<Transform>();
		PtrTransform->SetPosition(m_Position);
		PtrTransform->SetScale(m_Scale);
		PtrTransform->SetRotation(m_Rotation);
		//�J�����𓾂�

		auto PtrCamera = dynamic_pointer_cast<LookAtCamera>(OnGetDrawCamera());
		if (PtrCamera) {
			//LookAtCamera�ł���
			//LookAtCamera�ɒ��ڂ���I�u�W�F�N�g�i�v���C���[�j�̐ݒ�
			PtrCamera->SetTargetObject(GetThis<GameObject>());
			PtrCamera->SetTargetToAt(Vector3(0, 0, -10.0f));
		}

	
	}


	//--------------------------------------------------------------------------------------
	///	�G�P
	//--------------------------------------------------------------------------------------
	Enemy1::Enemy1(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode):
		GameObject(StagePtr),
		m_NearFarChange(5.0f)
	{
		auto PosStr = XmlDocReader::GetAttribute(pNode, L"Pos");
		//�g�[�N���i�J�����j�̔z��
		vector<wstring> Tokens;
		Util::WStrToTokenVector(Tokens, PosStr, L',');
		m_StartPos = Vector3(
			(float)_wtof(Tokens[0].c_str()),
			(float)_wtof(Tokens[1].c_str()),
			(float)_wtof(Tokens[2].c_str())
		);
	}


	//������
	void Enemy1::OnCreate() {
		auto PtrTransform = GetComponent<Transform>();
		PtrTransform->SetPosition(m_StartPos);
		PtrTransform->SetScale(0.125f, 0.25f, 0.25f);
		PtrTransform->SetRotation(0.0f, 0.0f, 0.0f);
		//���ǌn�̍s��������ꍇ��Rigidbody������
		auto PtrRegid = AddComponent<Rigidbody>();

		//�I�u�W�F�N�g�̃O���[�v�𓾂�
		auto Group = GetStage()->GetSharedObjectGroup(L"EnemyGroup");
		//�O���[�v�Ɏ������g��ǉ�
		Group->IntoGroup(GetThis<GameObject>());
		//�����s��������
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->SetGameObjectGroup(Group);
		//Obb�̏Փ˔��������
		auto PtrColl = AddComponent<CollisionObb>();
		//�������̂ݔ���
		PtrColl->SetIsHitAction(IsHitAction::Auto);

		//�e������
		auto ShadowPtr = AddComponent<Shadowmap>();
		ShadowPtr->SetMeshResource(L"DEFAULT_CUBE");

		//�`��R���|�[�l���g�̐ݒ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`�悷�郁�b�V����ݒ�
		PtrDraw->SetMeshResource(L"DEFAULT_CUBE");
		//�`�悷��e�N�X�`����ݒ�
		PtrDraw->SetTextureResource(L"TRACE_TX");
		//��������
		SetAlphaActive(true);

		//�X�e�[�g�}�V���̍\�z
		m_StateMachine.reset(new StateMachine<Enemy1>(GetThis<Enemy1>()));
		//�ŏ��̃X�e�[�g��Enemy1FarState�ɐݒ�
		m_StateMachine->ChangeState(Enemy1FarState::Instance());
	}

	void Enemy1::OnUpdate() {
		//�X�e�[�g�ɂ���ĕς��Ȃ��s�������s
		auto PtrGrav = GetBehavior<Gravity>();
		PtrGrav->Execute();
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->Execute();
		//�X�e�[�g�}�V����Update���s��
		//���̒��ŃX�e�[�g�̐؂�ւ����s����
		m_StateMachine->Update();
	}

	void Enemy1::OnUpdate2() {
		auto PtrUtil = GetBehavior<UtilBehavior>();
		PtrUtil->RotToHead(0.2f);
	}


	//--------------------------------------------------------------------------------------
	///	Enemy1��Far�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy1FarState)

	void Enemy1FarState::Enter(const shared_ptr<Enemy1>& Obj) {
	}

	void Enemy1FarState::Execute(const shared_ptr<Enemy1>& Obj) {
		auto PtrSeek = Obj->GetBehavior<SeekSteering>();
		float f = PtrSeek->Execute(L"Player");
		if (f < Obj->GetNearFarChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy1NearState::Instance());
		}
	}

	void Enemy1FarState::Exit(const shared_ptr<Enemy1>& Obj) {
	}

	//--------------------------------------------------------------------------------------
	///	Enemy1��Near�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy1NearState)

	void Enemy1NearState::Enter(const shared_ptr<Enemy1>& Obj) {
	}

	void Enemy1NearState::Execute(const shared_ptr<Enemy1>& Obj) {
		auto PtrArrive = Obj->GetBehavior<ArriveSteering>();
		if (PtrArrive->Execute(L"Player") >= Obj->GetNearFarChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy1FarState::Instance());
		}
	}

	void Enemy1NearState::Exit(const shared_ptr<Enemy1>& Obj) {
	}


	//--------------------------------------------------------------------------------------
	///	�G2
	//--------------------------------------------------------------------------------------
	Enemy2::Enemy2(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode):
		GameObject(StagePtr),
		m_LongMediumChange(10.0f),
		m_MediumShortChange(5.0f)
	{
		auto PosStr = XmlDocReader::GetAttribute(pNode, L"Pos");
		//�g�[�N���i�J�����j�̔z��
		vector<wstring> Tokens;
		Util::WStrToTokenVector(Tokens, PosStr, L',');
		m_StartPos = Vector3(
			(float)_wtof(Tokens[0].c_str()),
			(float)_wtof(Tokens[1].c_str()),
			(float)_wtof(Tokens[2].c_str())
		);
	}

	//������
	void Enemy2::OnCreate() {
		auto PtrTransform = GetComponent<Transform>();
		PtrTransform->SetPosition(m_StartPos);
		PtrTransform->SetScale(0.25f, 0.25f, 0.25f);
		PtrTransform->SetRotation(0.0f, 0.0f, 0.0f);
		//���ǌn�̍s��������ꍇ��Rigidbody������
		auto PtrRegid = AddComponent<Rigidbody>();

		//�I�u�W�F�N�g�̃O���[�v�𓾂�
		auto Group = GetStage()->GetSharedObjectGroup(L"EnemyGroup");
		//�O���[�v�Ɏ������g��ǉ�
		Group->IntoGroup(GetThis<GameObject>());
		//�����s��������
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->SetGameObjectGroup(Group);

		auto PtrColl = AddComponent<CollisionSphere>();
		//�������̂ݔ���
		PtrColl->SetIsHitAction(IsHitAction::Auto);

		//�e������
		auto ShadowPtr = AddComponent<Shadowmap>();
		ShadowPtr->SetMeshResource(L"DEFAULT_SPHERE");

		//�`��R���|�[�l���g�̐ݒ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`�悷�郁�b�V����ݒ�
		PtrDraw->SetMeshResource(L"DEFAULT_SPHERE");
		//�`�悷��e�N�X�`����ݒ�
		PtrDraw->SetTextureResource(L"TRACE2_TX");
		//��������
		SetAlphaActive(true);


		//�X�e�[�g�}�V���̍\�z
		m_StateMachine.reset(new StateMachine<Enemy2>(GetThis<Enemy2>()));
		//�ŏ��̃X�e�[�g��Enemy2longState�ɐݒ�
		m_StateMachine->ChangeState(Enemy2longState::Instance());
	}

	void Enemy2::OnUpdate() {
		//�X�e�[�g�ɂ���ĕς��Ȃ��s�������s
		auto PtrGrav = GetBehavior<Gravity>();
		PtrGrav->Execute();
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->Execute();
		//�X�e�[�g�}�V����Update���s��
		//���̒��ŃX�e�[�g�̐؂�ւ����s����
		m_StateMachine->Update();
	}

	void Enemy2::OnUpdate2() {
		auto PtrUtil = GetBehavior<UtilBehavior>();
		PtrUtil->RotToHead(0.1f);
	}

	//�Փˎ�
	void Enemy2::OnCollision(vector<shared_ptr<GameObject>>& OtherVec) {
		if (m_StateMachine->GetCurrentState() == Enemy2MediumState::Instance()) {
			auto PtrGrav = GetBehavior<Gravity>();
			PtrGrav->StartJump(Vector3(0, 4.0f, 0));
		}
	}



	//--------------------------------------------------------------------------------------
	///	Enemy2��long�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy2longState)

	void Enemy2longState::Enter(const shared_ptr<Enemy2>& Obj) {
	}

	void Enemy2longState::Execute(const shared_ptr<Enemy2>& Obj) {
		auto PtrWait = Obj->GetBehavior<WaitBehavior>();
		float f = PtrWait->Execute(L"Player");
		if (f < Obj->GetLongMediumChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy2MediumState::Instance());
		}
	}

	void Enemy2longState::Exit(const shared_ptr<Enemy2>& Obj) {
		//�������Ȃ�
	}

	//--------------------------------------------------------------------------------------
	///	Enemy2��Medium�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy2MediumState)

	void Enemy2MediumState::Enter(const shared_ptr<Enemy2>& Obj) {
		auto PtrGrav = Obj->GetBehavior<Gravity>();
		PtrGrav->StartJump(Vector3(0, 4.0f, 0));
	}

	void Enemy2MediumState::Execute(const shared_ptr<Enemy2>& Obj) {
		auto PtrSeek = Obj->GetBehavior<SeekSteering>();
		float f = PtrSeek->Execute(L"Player");
		if (f < Obj->GetMediumShortChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy2ShortState::Instance());
		}
		else if (f >= Obj->GetLongMediumChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy2longState::Instance());
		}
	}

	void Enemy2MediumState::Exit(const shared_ptr<Enemy2>& Obj) {
	}

	//--------------------------------------------------------------------------------------
	///	Enemy2��Short�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy2ShortState)

	void Enemy2ShortState::Enter(const shared_ptr<Enemy2>& Obj) {
	}

	void Enemy2ShortState::Execute(const shared_ptr<Enemy2>& Obj) {
		auto PtrArrive = Obj->GetBehavior<ArriveSteering>();
		if (PtrArrive->Execute(L"Player") >= Obj->GetMediumShortChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy2MediumState::Instance());
		}
	}

	void Enemy2ShortState::Exit(const shared_ptr<Enemy2>& Obj) {
	}

	//--------------------------------------------------------------------------------------
	///	�G�R
	//--------------------------------------------------------------------------------------
	Enemy3::Enemy3(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode):
		GameObject(StagePtr),
		m_DefaultNearChange(7.0f)
	{
		auto PosStr = XmlDocReader::GetAttribute(pNode, L"Pos");
		//�g�[�N���i�J�����j�̔z��
		vector<wstring> Tokens;
		Util::WStrToTokenVector(Tokens, PosStr, L',');
		m_StartPos = Vector3(
			(float)_wtof(Tokens[0].c_str()),
			(float)_wtof(Tokens[1].c_str()),
			(float)_wtof(Tokens[2].c_str())
		);
	}

	//������
	void Enemy3::OnCreate() {
		auto PtrTransform = GetComponent<Transform>();
		PtrTransform->SetPosition(m_StartPos);
		PtrTransform->SetScale(0.25f, 0.25f, 0.25f);
		PtrTransform->SetRotation(0.0f, 0.0f, 0.0f);
		//���ǌn�̍s��������ꍇ��Rigidbody������
		auto PtrRegid = AddComponent<Rigidbody>();

		//�I�u�W�F�N�g�̃O���[�v�𓾂�
		auto Group = GetStage()->GetSharedObjectGroup(L"EnemyGroup");
		//�O���[�v�Ɏ������g��ǉ�
		Group->IntoGroup(GetThis<GameObject>());
		//�����s��������
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->SetGameObjectGroup(Group);

		auto PtrColl = AddComponent<CollisionSphere>();
		//�������̂ݔ���
		PtrColl->SetIsHitAction(IsHitAction::Auto);

		//�e������
		auto ShadowPtr = AddComponent<Shadowmap>();
		ShadowPtr->SetMeshResource(L"DEFAULT_SPHERE");

		//�`��R���|�[�l���g�̐ݒ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`�悷�郁�b�V����ݒ�
		PtrDraw->SetMeshResource(L"DEFAULT_SPHERE");
		//�`�悷��e�N�X�`����ݒ�
		PtrDraw->SetTextureResource(L"WALL_TX");
		//�X�e�[�g�}�V���̍\�z
		m_StateMachine.reset(new StateMachine<Enemy3>(GetThis<Enemy3>()));
		//�ŏ��̃X�e�[�g��Enemy3DefaultState�ɐݒ�
		m_StateMachine->ChangeState(Enemy3DefaultState::Instance());
	}

	void Enemy3::OnUpdate() {
		//�X�e�[�g�ɂ���ĕς��Ȃ��s�������s
		auto PtrGrav = GetBehavior<Gravity>();
		PtrGrav->Execute();
		auto PtrSep = GetBehavior<SeparationSteering>();
		PtrSep->Execute();
		//�X�e�[�g�}�V����Update���s��
		//���̒��ŃX�e�[�g�̐؂�ւ����s����
		m_StateMachine->Update();
	}

	void Enemy3::OnUpdate2() {
		auto PtrUtil = GetBehavior<UtilBehavior>();
		PtrUtil->RotToHead(0.1f);
	}


	//--------------------------------------------------------------------------------------
	///	Enemy3��Default�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy3DefaultState)

	void Enemy3DefaultState::Enter(const shared_ptr<Enemy3>& Obj) {
		//�������Ȃ�
	}

	void Enemy3DefaultState::Execute(const shared_ptr<Enemy3>& Obj) {
		auto PtrSeek = Obj->GetBehavior<SeekSteering>();
		float f = PtrSeek->Execute(L"Player");
		if (f < Obj->GetDefaultNearChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy3NearState::Instance());
		}
	}

	void Enemy3DefaultState::Exit(const shared_ptr<Enemy3>& Obj) {
		//�������Ȃ�
	}

	//--------------------------------------------------------------------------------------
	///	Enemy3��Near�X�e�[�g
	//--------------------------------------------------------------------------------------
	IMPLEMENT_SINGLETON_INSTANCE(Enemy3NearState)

	void Enemy3NearState::Enter(const shared_ptr<Enemy3>& Obj) {
		auto PtrGrav = Obj->GetBehavior<Gravity>();
		PtrGrav->StartJump(Vector3(0, 4.0f, 0));
	}

	void Enemy3NearState::Execute(const shared_ptr<Enemy3>& Obj) {
		auto PtrArrive = Obj->GetBehavior<ArriveSteering>();
		if (PtrArrive->Execute(L"Player") >= Obj->GetDefaultNearChange()) {
			Obj->GetStateMachine()->ChangeState(Enemy3DefaultState::Instance());
		}
	}

	void Enemy3NearState::Exit(const shared_ptr<Enemy3>& Obj) {
		//�������Ȃ�
	}


}
//end basecross
