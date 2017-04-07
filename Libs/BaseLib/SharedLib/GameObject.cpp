/*!
@file GameObject.cpp
@brief �Q�[���I�u�W�F�N�g�A�X�e�[�W����
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/

#include "stdafx.h"

namespace basecross {



	//--------------------------------------------------------------------------------------
	//	struct GameObject::Impl;
	//	�p�r: �R���|�[�l���gImpl�N���X
	//--------------------------------------------------------------------------------------
	struct GameObject::Impl {
		bool m_UpdateActive;	//update���邩�ǂ���
		bool m_DrawActive;		//Draw���邩�ǂ���
		bool m_AlphaActive;		//�������ǂ���
		int m_DrawLayer;	//�`�惌�C���[
		set<wstring> m_Tag;	//�^�O
		set<int> m_NumTag;	//�����^�O
		bool m_SpriteDraw;	//�X�v���C�g�Ƃ��ĕ`�悷�邩�ǂ���

		weak_ptr<Stage> m_Stage;	//�����X�e�[�W
		map<type_index, shared_ptr<Component> > m_CompMap;
		list<type_index> m_CompOrder;	//�R���|�[�l���g���s����

		shared_ptr<Rigidbody> m_Rigidbody;	//Rigidbody�͕ʂɂ���
		shared_ptr<Collision> m_Collision;	//Collision���ʂɂ���
		shared_ptr<Transform> m_Transform;	//Transform���ʂɂ���
		//�s���̃}�b�v
		map<type_index, shared_ptr<Behavior>> m_BehaviorMap;

		Impl(const shared_ptr<Stage>& StagePtr) :
			m_UpdateActive(true),
			m_DrawActive(true),
			m_AlphaActive(false),
			m_DrawLayer(0),
			m_SpriteDraw(false),
			m_Stage(StagePtr)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	///	�Q�[���z�u�I�u�W�F�N�g�e�N���X
	//--------------------------------------------------------------------------------------
	//private�����o
	shared_ptr<Component> GameObject::SearchComponent(type_index TypeIndex)const {
		auto it = pImpl->m_CompMap.find(TypeIndex);
		if (it != pImpl->m_CompMap.end()) {
			return it->second;
		}
		return nullptr;
	}

	shared_ptr<Transform> GameObject::GetTransform()const {
		return pImpl->m_Transform;

	}
	shared_ptr<Rigidbody> GameObject::GetRigidbody()const {
		return pImpl->m_Rigidbody;
	}
	shared_ptr<Collision> GameObject::GetCollision()const {
		return pImpl->m_Collision;
	}
	shared_ptr<CollisionSphere> GameObject::GetCollisionSphere()const {
		return dynamic_pointer_cast<CollisionSphere>(pImpl->m_Collision);
	}

	shared_ptr<CollisionCapsule> GameObject::GetCollisionCapsule()const {
		return dynamic_pointer_cast<CollisionCapsule>(pImpl->m_Collision);
	}


	shared_ptr<CollisionObb> GameObject::GetCollisionObb()const {
		return dynamic_pointer_cast<CollisionObb>(pImpl->m_Collision);
	}

	shared_ptr<CollisionTriangles> GameObject::GetCollisionTriangles()const {
		return dynamic_pointer_cast<CollisionTriangles>(pImpl->m_Collision);
	}


	shared_ptr<CollisionRect> GameObject::GetCollisionRect()const {
		return dynamic_pointer_cast<CollisionRect>(pImpl->m_Collision);
	}


	void GameObject::SetRigidbody(const shared_ptr<Rigidbody>& Ptr) {
		Ptr->AttachGameObject(GetThis<GameObject>());
		pImpl->m_Rigidbody = Ptr;
	}
	void GameObject::SetCollision(const shared_ptr<Collision>& Ptr) {
		Ptr->AttachGameObject(GetThis<GameObject>());
		pImpl->m_Collision = Ptr;
	}

	void GameObject::SetTransform(const shared_ptr<Transform>& Ptr) {
		Ptr->AttachGameObject(GetThis<GameObject>());
		pImpl->m_Transform = Ptr;
	}

	void GameObject::AddMakedComponent(type_index TypeIndex, const shared_ptr<Component>& Ptr) {
		if (!SearchComponent(TypeIndex)) {
			//���̃R���|�[�l���g���܂��Ȃ���ΐV�K�o�^
			pImpl->m_CompOrder.push_back(TypeIndex);
		}
		//map�ɒǉ��������͍X�V
		pImpl->m_CompMap[TypeIndex] = Ptr;
		Ptr->AttachGameObject(GetThis<GameObject>());
	}

	map<type_index, shared_ptr<Component> >& GameObject::GetCompoMap()const {
		return pImpl->m_CompMap;
	}

	void GameObject::RemoveTgtComponent(type_index TypeIndex) {
		//���ԃ��X�g�����؂��č폜
		auto it = pImpl->m_CompOrder.begin();
		while (it != pImpl->m_CompOrder.end()) {
			if (*it == TypeIndex) {
				auto it2 = pImpl->m_CompMap.find(*it);
				if (it2 != pImpl->m_CompMap.end()) {
					//�w��̌^�̃R���|�[�l���g����������
					//map�f�[�^���폜
					pImpl->m_CompMap.erase(it2);
				}
				pImpl->m_CompOrder.erase(it);
				return;
			}
			it++;
		}
	}

	map<type_index, shared_ptr<Behavior> >& GameObject::GetBehaviorMap() const {
		return pImpl->m_BehaviorMap;
	}

	shared_ptr<Behavior> GameObject::SearchBehavior(type_index TypeIndex)const {
		auto it = pImpl->m_BehaviorMap.find(TypeIndex);
		if (it != pImpl->m_BehaviorMap.end()) {
			return it->second;
		}
		return nullptr;

	}

	void GameObject::AddMakedBehavior(type_index TypeIndex, const shared_ptr<Behavior>& Ptr) {
		//map�ɒǉ��������͍X�V
		pImpl->m_BehaviorMap[TypeIndex] = Ptr;
	}







	GameObject::GameObject(const shared_ptr<Stage>& StagePtr) :
		ObjectInterface(),
		ShapeInterface(),
		pImpl(new Impl(StagePtr))
	{
	}
	GameObject::~GameObject() {}
	//�A�N�Z�T
	bool GameObject::IsUpdateActive() const { return pImpl->m_UpdateActive; }
	bool GameObject::GetUpdateActive() const { return pImpl->m_UpdateActive; }
	void GameObject::SetUpdateActive(bool b) { pImpl->m_UpdateActive = b; }

	bool GameObject::IsDrawActive() const { return pImpl->m_DrawActive; }
	bool GameObject::GetDrawActive() const { return pImpl->m_DrawActive; }
	void GameObject::SetDrawActive(bool b) { pImpl->m_DrawActive = b; }

	bool GameObject::IsAlphaActive() const { return pImpl->m_AlphaActive; }
	bool GameObject::GetAlphaActive() const { return pImpl->m_AlphaActive; }
	void GameObject::SetAlphaActive(bool b) { pImpl->m_AlphaActive = b; }


	//�X�v���C�g�Ƃ���Draw���邩�ǂ���
	bool  GameObject::IsSpriteDraw() const {return pImpl->m_SpriteDraw;}
	bool  GameObject::GetSpriteDraw() const {return pImpl->m_SpriteDraw;}
	void  GameObject::SetSpriteDraw(bool b) {pImpl->m_SpriteDraw = b;}
	//�`�惌�C���[�̎擾�Ɛݒ�
	int GameObject::GetDrawLayer() const {return pImpl->m_DrawLayer;}
	void  GameObject::SetDrawLayer(int l) {pImpl->m_DrawLayer = l;}
	//�^�O�̌��؂Ɛݒ�
	set<wstring>& GameObject::GetTagSet() const {
		return pImpl->m_Tag;
	}
	bool GameObject::FindTag(const wstring& tagstr) const {
		if (pImpl->m_Tag.find(tagstr) == pImpl->m_Tag.end()) {
			return false;
		}
		return true;
	}
	void  GameObject::AddTag(const wstring& tagstr) {
		if (tagstr == L"") {
			//�󔒂Ȃ��O
			throw BaseException(
				L"�ݒ肷��^�O����ł�",
				L"if (tagstr == L"")",
				L"GameObject::AddTag()"
			);
		}
		pImpl->m_Tag.insert(tagstr);
	}
	void  GameObject::RemoveTag(const wstring& tagstr) {
		pImpl->m_Tag.erase(tagstr);
	}
	//�����^�O�̌��؂Ɛݒ�
	set<int>& GameObject::GetNumTagSet() const {
		return pImpl->m_NumTag;
	}

	bool GameObject::FindNumTag(int numtag) const {
		if (pImpl->m_NumTag.find(numtag) == pImpl->m_NumTag.end()) {
			return false;
		}
		return true;
	}
	void  GameObject::AddNumTag(int numtag) {
		pImpl->m_NumTag.insert(numtag);
	}
	void  GameObject::RemoveNumTag(int numtag) {
		pImpl->m_NumTag.erase(numtag);
	}

	shared_ptr<Stage> GameObject::GetStage(bool ExceptionActive) const {
		auto shptr = pImpl->m_Stage.lock();
		if (shptr) {
			return shptr;
		}
		else {
			if (ExceptionActive) {
				throw BaseException(
					L"�����X�e�[�W��null�ł��B�������g���X�e�[�W�ł͂���܂��񂩁H",
					L"if (!shptr)",
					L"GameObject::GetStage()"
				);
			}
			else {
				return nullptr;
			}
		}
		// �����X�e�[�W��null������
		// �������g���X�e�[�W�̉\��������
		return nullptr;
	}
	void GameObject::SetStage(const shared_ptr<Stage>& stage) { pImpl->m_Stage = stage; }

	void GameObject::ComponentUpdate() {
		auto TMptr = GetComponent<Transform>();
		auto RigidPtr = GetComponent<Rigidbody>(false);
		//�}�b�v�����؂���Update
		list<type_index>::iterator it = pImpl->m_CompOrder.begin();
		while (it != pImpl->m_CompOrder.end()) {
			map<type_index, shared_ptr<Component> >::const_iterator it2;
			it2 = pImpl->m_CompMap.find(*it);
			if (it2 != pImpl->m_CompMap.end()) {
				//�w��̌^�̃R���|�[�l���g����������
				if (it2->second->IsUpdateActive()) {
					it2->second->OnUpdate();
				}
			}
			it++;
		}
		if (RigidPtr && RigidPtr->IsUpdateActive()) {
			//Rigidbody�������Update()
			RigidPtr->OnUpdate();
		}
		//Transform��Update
		if (TMptr->IsUpdateActive()) {
			TMptr->OnUpdate();
		}
	}

	void GameObject::CollisionReset() {
		auto CollisionPtr = GetComponent<Collision>(false);
		if (CollisionPtr) {
			CollisionPtr->SetToBeforeHitObject();
			CollisionPtr->ClearHitObject();
		}
	}


	void GameObject::ToMessageCollision() {
		auto CollisionPtr = GetComponent<Collision>(false);
		if (CollisionPtr) {
			auto& VecPtr = CollisionPtr->GetNewHitObjectVec();
			if (!VecPtr.empty()) {
				OnCollision(VecPtr);
			}
			VecPtr = CollisionPtr->GetExcuteHitObjectVec();
			if (!VecPtr.empty()) {
				OnCollisionExcute(VecPtr);
			}
			VecPtr = CollisionPtr->GetExitHitObjectVec();
			if (!VecPtr.empty()) {
				OnCollisionExit(VecPtr);
			}
		}
	}

	void GameObject::DrawShadowmap() {
		auto shadowptr = GetDynamicComponent<Shadowmap>(false);
		if (shadowptr) {
			shadowptr->OnDraw();
		}
	}

	void GameObject::ComponentDraw() {
		//Transform���Ȃ���Η�O
		auto Tptr = GetComponent<Transform>();
		auto RigidPtr = GetComponent<Rigidbody>(false);
		auto CollisionPtr = GetComponent<Collision>(false);
		//�}�b�v�����؂���Draw
		list<type_index>::iterator it = pImpl->m_CompOrder.begin();
		while (it != pImpl->m_CompOrder.end()) {
			map<type_index, shared_ptr<Component> >::const_iterator it2;
			it2 = pImpl->m_CompMap.find(*it);
			//�w��̌^�̃R���|�[�l���g����������
			if (it2 != pImpl->m_CompMap.end() && !dynamic_pointer_cast<Shadowmap>(it2->second)) {
				//�V���h�E�}�b�v�ȊO�Ȃ���s
				//���̃R���|�[�l���g�̎q�R���|�[�l���g�̕`��
				if (it2->second->IsDrawActive()) {
					it2->second->OnDraw();
				}
			}
			it++;
		}
		//�h���N���X�΍�
		if (RigidPtr && RigidPtr->IsDrawActive()) {
			//Rigidbody�������Draw()
			RigidPtr->OnDraw();
		}
		if (CollisionPtr && CollisionPtr->IsDrawActive()) {
			//Collision�������Draw()
			CollisionPtr->OnDraw();
		}

		//Transform��Draw
		if (Tptr->IsDrawActive()) {
			Tptr->OnDraw();
		}
	}

	void GameObject::OnPreCreate() {
		//Transform�K�{
		AddComponent<Transform>();
	}

	const shared_ptr<Camera>& GameObject::OnGetDrawCamera()const {
		//�f�t�H���g�̓r���[�̃J����������o��
		auto StageView = GetStage()->GetView();
		return StageView->GetTargetCamera();
	}

	const Light& GameObject::OnGetDrawLight()const {
		//�X�e�[�W���烉�C�g�����o��
		auto StageLight = GetStage()->GetLight();
		return StageLight->GetTargetLight();
	}


	void GameObject::OnGet2DDrawProjMatrix(Matrix4X4& ProjMatrix) const {
		auto viewport = GetStage()->GetView()->GetTargetViewport();
		float w = static_cast<float>(viewport.Width);
		float h = static_cast<float>(viewport.Height);
		ProjMatrix.OrthographicLH(w, h, viewport.MinDepth, viewport.MaxDepth);
	}



	void GameObject::OnDraw() {
		//�R���|�[�l���g�`��
		//�h���N���X�ő��d��`����ꍇ��
		//�R���|�[�l���g�`�悷��ꍇ��
		//GameObject::Draw()���Ăяo��
		ComponentDraw();
	}


	//--------------------------------------------------------------------------------------
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct GameObjectGroup::Impl {
		vector< weak_ptr<GameObject> > m_Group;
		Impl() {}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	//	class GameObjectGroup;
	//--------------------------------------------------------------------------------------
	GameObjectGroup::GameObjectGroup() :
		ObjectInterface(),
		pImpl(new Impl())
	{}
	GameObjectGroup::~GameObjectGroup() {}
	//�A�N�Z�T
	const vector< weak_ptr<GameObject> >& GameObjectGroup::GetGroupVector() const {
		return pImpl->m_Group;
	}
	shared_ptr<GameObject> GameObjectGroup::at(size_t index) {
		if (index >= pImpl->m_Group.size()) {
			wstring msg = Util::UintToWStr(index);
			msg += L" >= ";
			msg += Util::UintToWStr(pImpl->m_Group.size());
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł�",
				msg,
				L"GameObjectGroup::at()"
			);
		}
		if (pImpl->m_Group.at(index).expired()) {
			wstring msg = Util::UintToWStr(index);
			throw BaseException(
				L"���̃C���f�b�N�X�̃I�u�W�F�N�g�͖����ł��B",
				msg,
				L"GameObjectGroup::at()"
			);
		}
		return pImpl->m_Group.at(index).lock();
	}
	size_t GameObjectGroup::size() const {
		return pImpl->m_Group.size();
	}
	//����
	void GameObjectGroup::IntoGroup(const shared_ptr<GameObject>& Obj) {
		pImpl->m_Group.push_back(Obj);
	}

	void GameObjectGroup::AllClear() {
		pImpl->m_Group.clear();
	}

	//--------------------------------------------------------------------------------------
	//	struct Particle::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct Particle::Impl {
		DrawOption m_DrawOption;		//�\���I�v�V����
		vector<ParticleSprite> m_ParticleSpriteVec;	//�ۑ����Ă����X�v���C�g�̔z��
		Vector3 m_EmitterPos;			//�G�~�b�^�[�ʒu
		float m_TotalTime;				//�^�C�}�[���䂷��ꍇ�Ɏg�p����ϐ�
		float m_MaxTime;				//���̃p�[�e�B�N���W���̂̕\������
		weak_ptr<TextureResource> m_TextureResource;	//�e�N�X�`��
		Impl(size_t Count, DrawOption Option) :
			m_DrawOption(Option),
			m_ParticleSpriteVec(Count),
			m_EmitterPos(0, 0, 0),
			m_TotalTime(0),
			m_MaxTime(0)
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	//	class Particle;
	//	�p�r: �p�[�e�B�N��
	//	*1�̃G�~�b�^�[�������A������ParticleSprite��ێ�����
	//--------------------------------------------------------------------------------------
	Particle::Particle(size_t Count, DrawOption Option) :
		ObjectInterface(),
		pImpl(new Impl(Count, Option))
	{}
	Particle::~Particle() {}

	Particle::DrawOption Particle::GetDrawOption()const {
		return pImpl->m_DrawOption;
	}
	void Particle::SetDrawOption(DrawOption Option) {
		pImpl->m_DrawOption = Option;
	}

	const Vector3& Particle::GetEmitterPos() const {
		return pImpl->m_EmitterPos;
	}
	void Particle::SetEmitterPos(const Vector3& Pos) {
		pImpl->m_EmitterPos = Pos;
	}

	float Particle::GetTotalTime() const {
		return pImpl->m_TotalTime;
	}
	void Particle::SetTotalTime(float f) {
		pImpl->m_TotalTime = f;
	}
	void Particle::AddTotalTime(float f) {
		pImpl->m_TotalTime += f;
	}

	float Particle::GetMaxTime() const {
		return pImpl->m_MaxTime;
	}
	void Particle::SetMaxTime(float f) {
		pImpl->m_MaxTime = f;
	}



	bool Particle::IsActive() const {
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			if (Psp.m_Active) {
				//1�ł��A�N�e�B�u�������true
				return true;
			}
		}
		return false;
	}
	bool Particle::IsAllActive() const {
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			if (!Psp.m_Active) {
				//1�ł���A�N�e�B�u�������false
				return false;
			}
		}
		return true;
	}
	void Particle::SetAllActive() {
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			Psp.m_Active = true;
		}
	}
	void Particle::SetAllNoActive() {
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			Psp.m_Active = false;
		}
	}

	void Particle::Reflesh(size_t Count, Particle::DrawOption Option) {
		pImpl->m_DrawOption = Option;
		pImpl->m_EmitterPos = Vector3(0, 0, 0);
		pImpl->m_TotalTime = 0;
		pImpl->m_MaxTime = 0;
		pImpl->m_ParticleSpriteVec.clear();
		pImpl->m_ParticleSpriteVec.resize(Count);
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			Psp.Reflesh();
		}
	}

	vector<ParticleSprite>& Particle::GetParticleSpriteVec() const {
		return pImpl->m_ParticleSpriteVec;
	}

	shared_ptr<TextureResource> Particle::GetTextureResource(bool ExceptionActive) const {
		if (!pImpl->m_TextureResource.expired()) {
			return pImpl->m_TextureResource.lock();
		}
		else {
			if (ExceptionActive) {
				throw BaseException(
					L"�e�N�X�`�����\�[�X��������܂���",
					L"if (pImpl->m_Texture.expired())",
					L"Particle::GetTextureResource()"
				);
			}
		}
		return nullptr;
	}
	void Particle::SetTextureResource(const wstring& ResKey) {
		try {
			if (ResKey == L"") {
				throw BaseException(
					L"�e�N�X�`���L�[���󔒂ł�",
					L"if (ResKey == L\"\"",
					L"Particle::SetTextureResource()"
				);
			}
			pImpl->m_TextureResource = App::GetApp()->GetResource<TextureResource>(ResKey);
		}
		catch (...) {
			throw;
		}
	}
	void Particle::SetTextureResource(const shared_ptr<TextureResource>& TextureResourcePtr) {
		pImpl->m_TextureResource = TextureResourcePtr;
	}

	void Particle::Draw(const shared_ptr<ParticleManager>& Manager) {
		for (auto Psp : pImpl->m_ParticleSpriteVec) {
			if (Psp.m_Active && !pImpl->m_TextureResource.expired()) {
				Manager->AddParticle(Psp, GetDrawOption(),
					GetEmitterPos(), pImpl->m_TextureResource.lock());
			}
		}
	}


	//--------------------------------------------------------------------------------------
	//	struct MultiParticle::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct MultiParticle::Impl {
		vector< shared_ptr<Particle> > m_ParticleVec;
		//���Z�������邩�ǂ���
		bool m_AddType;
		Impl():
			m_AddType(false)
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	//	class MultiParticle : public GameObject;
	//	�p�r: �}���`�G�t�F�N�g 
	//--------------------------------------------------------------------------------------
	MultiParticle::MultiParticle(const shared_ptr<Stage>& StagePtr) :
		GameObject(StagePtr),
		pImpl(new Impl())
	{}
	MultiParticle::~MultiParticle() {}

	vector< shared_ptr<Particle> >& MultiParticle::GetParticleVec() const {
		return pImpl->m_ParticleVec;
	}

	bool  MultiParticle::GetAddType() const {
		return pImpl->m_AddType;
	}
	bool MultiParticle::IsAddType() const {
		return pImpl->m_AddType;
	}
	void MultiParticle::SetAddType(bool b) {
		pImpl->m_AddType = b;
	}



	shared_ptr<Particle> MultiParticle::InsertParticle(size_t Count, Particle::DrawOption Option) {
		for (size_t i = 0; i < pImpl->m_ParticleVec.size(); i++) {
			//������A�N�e�B�u�̃p�[�e�B�N��������Ώ��������ă��^�[��
			if (!pImpl->m_ParticleVec[i]->IsActive()) {
				pImpl->m_ParticleVec[i]->Reflesh(Count, Option);
				return pImpl->m_ParticleVec[i];
			}
		}
		//�V�����p�[�e�B�N����ǉ�
		shared_ptr<Particle> ParticlePtr = ObjectFactory::Create<Particle>(Count, Option);
		pImpl->m_ParticleVec.push_back(ParticlePtr);
		return ParticlePtr;
	}

	void MultiParticle::OnPreCreate() {
		GameObject::OnPreCreate();
		//���������̂ݎw�肵�Ă���
		SetAlphaActive(true);
	}


	void MultiParticle::OnUpdate() {
		//�O��̃^�[������̎���
		float ElapsedTime = App::GetApp()->GetElapsedTime();
		for (auto ParticlePtr : GetParticleVec()) {
			ParticlePtr->AddTotalTime(ElapsedTime);
			for (auto& rParticleSprite : ParticlePtr->GetParticleSpriteVec()) {
				if (rParticleSprite.m_Active) {
					//�ړ����x�ɏ]���Ĉړ�������
					rParticleSprite.m_LocalPos += rParticleSprite.m_Velocity * ElapsedTime;
					if (ParticlePtr->GetTotalTime() >= ParticlePtr->GetMaxTime()) {
						//�������ԂɂȂ�����
						rParticleSprite.m_Active = false;
					}
				}
			}
		}
	}


	void MultiParticle::OnDraw() {
		if (pImpl->m_ParticleVec.size() > 0) {
			for (auto Ptr : pImpl->m_ParticleVec) {
				if (Ptr->IsActive()) {
					Ptr->Draw(GetStage()->GetParticleManager(IsAddType()));
				}
			}
		}
	}

	//--------------------------------------------------------------------------------------
	//	struct ParticleManager::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct ParticleManager::Impl {
		bool m_ZBufferUse;				//Z�o�b�t�@���g�p���邩�ǂ���
		bool m_SamplerWrap;				//�T���v���[�̃��b�s���O���邩�ǂ���
		//���Z�������邩�ǂ���
		bool m_AddType;
		Impl(bool AddType) :
			m_ZBufferUse(true),
			m_SamplerWrap(false),
			m_AddType(AddType)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	//	class ParticleManager : public GameObject;
	//	�p�r: �p�[�e�B�N���}�l�[�W��
	//--------------------------------------------------------------------------------------
	//�\�z�Ə���
	ParticleManager::ParticleManager(const shared_ptr<Stage>& StagePtr, bool AddType) :
		GameObject(StagePtr),
		pImpl(new Impl(AddType))
	{}
	ParticleManager::~ParticleManager() {}

	//������
	void ParticleManager::OnCreate() {
		try {
			//���2000�Ń}�l�[�W���쐬
			AddComponent<PCTParticleDraw>(2000,pImpl->m_AddType);
			//���������̂ݎw�肵�Ă���
			SetAlphaActive(true);
		}
		catch (...) {
			throw;
		}

	}

	bool ParticleManager::GetZBufferUse() const {
		return pImpl->m_ZBufferUse;
	}
	bool ParticleManager::IsZBufferUse() const {
		return pImpl->m_ZBufferUse;
	}
	void ParticleManager::SetZBufferUse(bool b) {
		pImpl->m_ZBufferUse = b;
	}

	bool ParticleManager::GetSamplerWrap() const {
		return pImpl->m_SamplerWrap;
	}
	bool ParticleManager::IsSamplerWrap() const {
		return pImpl->m_SamplerWrap;
	}
	void ParticleManager::SetSamplerWrap(bool b) {
		pImpl->m_SamplerWrap = b;
	}

	void ParticleManager::AddParticle(const ParticleSprite& rParticleSprite, Particle::DrawOption Option,
		const Vector3& EmitterPos, const shared_ptr<TextureResource>& TextureRes) {
		auto DrawCom = GetComponent<PCTParticleDraw>();

		auto StageView = GetStage()->GetView();

		auto PtrCamera = StageView->GetTargetCamera();
		//�J�����̈ʒu
		Vector3 CameraEye = PtrCamera->GetEye();
		Vector3 CameraAt = PtrCamera->GetAt();


		Vector3 WorldPos = rParticleSprite.m_LocalPos + EmitterPos;
		float ToCaneraLength = Vector3EX::Length(CameraEye - WorldPos);

		Vector3 LocalScale;
		LocalScale.x = rParticleSprite.m_LocalScale.x;
		LocalScale.y = rParticleSprite.m_LocalScale.y;
		LocalScale.z = 1.0f;

		Vector3 Temp;
		Quaternion Qt;
		Matrix4X4 RotMatrix;
		Vector4 dammi(0, 0, 0, 0);
		Vector3 DefUp(0, 1.0f, 0);
		switch (Option) {
		case Particle::DrawOption::Billboard:
		{
			Temp = CameraAt - CameraEye;
			Vector2 TempVec2(Temp.x, Temp.z);
			if (Vector2EX::Length(TempVec2) < 0.1f) {
				DefUp = Vector3(0, 0, 1.0f);
			}
			Temp.Normalize();
			RotMatrix.LookAtLH(Vector3(0, 0, 0), Temp, DefUp);
			RotMatrix.Inverse(&dammi);
			Qt = RotMatrix.QtInMatrix();
			Qt.Normalize();
		}
		break;
		case Particle::DrawOption::Faceing:
		{
			Temp = WorldPos - CameraEye;
			Vector2 TempVec2(Temp.x, Temp.z);
			if (Vector2EX::Length(TempVec2) < 0.1f) {
				DefUp = Vector3(0, 0, 1.0f);
			}
			RotMatrix.LookAtLH(Vector3(0, 0, 0), Temp, DefUp);
			RotMatrix.Inverse(&dammi);
			Qt = RotMatrix.QtInMatrix();
			Qt.Normalize();
		}
		break;
		case Particle::DrawOption::FaceingY:
			Temp = WorldPos - CameraEye;
			Temp.Normalize();
			Qt.RotationRollPitchYaw(0, atan2(Temp.x, Temp.z), 0);
			Qt.Normalize();
			break;
		case Particle::DrawOption::Normal:
			Qt = rParticleSprite.m_LocalQt;
			Qt.Normalize();
			break;
		}

		Matrix4X4 matrix;
		matrix.DefTransformation(
			LocalScale,
			Qt,
			WorldPos
		);
		DrawCom->AddParticle(ToCaneraLength, matrix, TextureRes, rParticleSprite.m_Color);
	}

	void ParticleManager::OnDraw() {
		auto DrawCom = GetComponent<PCTParticleDraw>();
		DrawCom->OnDraw();
	}

	struct CillisionItem {
		shared_ptr<Collision> m_Collision;
		SPHERE m_EnclosingSphere;
		float m_MinX;
		float m_MaxX;
		float m_MinY;
		float m_MaxY;
		float m_MinZ;
		float m_MaxZ;
		bool operator==(const CillisionItem& other)const {
			if (this == &other) {
				return true;
			}
			return false;
		}

	};


	//--------------------------------------------------------------------------------------
	//	struct CollisionManager::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct CollisionManager::Impl {
		vector<CillisionItem> m_ItemVec;
		Impl()
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	//	�Փ˔���Ǘ���
	//--------------------------------------------------------------------------------------
	CollisionManager::CollisionManager(const shared_ptr<Stage>& StagePtr):
		GameObject(StagePtr),
		pImpl(new Impl())
	{}
	CollisionManager::~CollisionManager() {}

	void CollisionManager::OnCreate() {

	}

	void CollisionManager::CollisionSub(size_t SrcIndex) {
		CillisionItem& Src = pImpl->m_ItemVec[SrcIndex];
		for (auto& v : pImpl->m_ItemVec) {
			if (Src == v) {
				continue;
			}
			if (Src.m_MinX > v.m_MaxX || Src.m_MaxX < v.m_MinX) {
				continue;
			}
			if (Src.m_MinY > v.m_MaxY || Src.m_MaxY < v.m_MinY) {
				continue;
			}
			if (Src.m_MinZ > v.m_MaxZ || Src.m_MaxZ < v.m_MinZ) {
				continue;
			}
			//���肪���O�I�u�W�F�N�g�ɂȂ��Ă邩�ǂ���
			if (v.m_Collision->IsExcludeCollisionObject(Src.m_Collision->GetGameObject())) {
				continue;
			}
			if (Src.m_Collision->IsExcludeCollisionObject(v.m_Collision->GetGameObject())) {
				continue;
			}
			if (v.m_Collision->IsHitObject(Src.m_Collision->GetGameObject())) {
				continue;
			}
			//�Փ˔���(Dest�ɌĂ�ł��炤�B�_�u���f�X�p�b�`�Ăяo��)
			v.m_Collision->CollisionCall(Src.m_Collision);
		}
	}


	void CollisionManager::OnUpdate() {
		pImpl->m_ItemVec.clear();
		auto& ObjVec = GetStage()->GetGameObjectVec();
		for (auto& v : ObjVec) {
			if (v->IsUpdateActive()) {
				auto Col = v->GetComponent<Collision>(false);
				if (Col && Col->IsUpdateActive()) {
					CillisionItem Item;
					Item.m_Collision = Col;
					Item.m_EnclosingSphere = Col->GetEnclosingSphere();
					Item.m_MinX = Item.m_EnclosingSphere.m_Center.x - Item.m_EnclosingSphere.m_Radius;
					Item.m_MaxX = Item.m_EnclosingSphere.m_Center.x + Item.m_EnclosingSphere.m_Radius;

					Item.m_MinY = Item.m_EnclosingSphere.m_Center.y - Item.m_EnclosingSphere.m_Radius;
					Item.m_MaxY = Item.m_EnclosingSphere.m_Center.y + Item.m_EnclosingSphere.m_Radius;

					Item.m_MinZ = Item.m_EnclosingSphere.m_Center.z - Item.m_EnclosingSphere.m_Radius;
					Item.m_MaxZ = Item.m_EnclosingSphere.m_Center.z + Item.m_EnclosingSphere.m_Radius;

					pImpl->m_ItemVec.push_back(Item);
				}
			}
		}


		auto func = [&](CillisionItem& Left, CillisionItem& Right)->bool {
			auto PtrLeftVelo = Left.m_Collision->GetGameObject()->GetComponent<Transform>()->GetVelocity();
			auto PtrRightVelo = Right.m_Collision->GetGameObject()->GetComponent<Transform>()->GetVelocity();


			auto LeftLen = Vector3EX::Length(PtrLeftVelo);
			auto RightLen = Vector3EX::Length(PtrRightVelo);

			return (LeftLen < RightLen);
		};

		std::sort(pImpl->m_ItemVec.begin(), pImpl->m_ItemVec.end(), func);


		for (size_t i = 0; i < pImpl->m_ItemVec.size(); i++) {
			if (!pImpl->m_ItemVec[i].m_Collision->IsFixed()) {
				CollisionSub(i);
			}
		}
	}


	//--------------------------------------------------------------------------------------
	//	struct Stage::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct Stage::Impl {
		//update���邩�ǂ���
		bool m_UpdateActive;
		//�p�[�e�B�N���}�l�[�W��(��������)
		shared_ptr<ParticleManager> m_AlphaParticleManager;
		//�p�[�e�B�N���}�l�[�W��(���Z����)
		shared_ptr<ParticleManager> m_AddParticleManager;
		//�R���W�����Ǘ���
		shared_ptr<CollisionManager> m_CollisionManager;
		//�I�u�W�F�N�g�̔z��
		vector< shared_ptr<GameObject> > m_GameObjectVec;
		//�r���ɃI�u�W�F�N�g���ǉ����ꂽ�ꍇ�A�^�[���̊J�n�܂ő҂z��
		vector< shared_ptr<GameObject> > m_WaitAddObjectVec;
		//�r���ɃI�u�W�F�N�g���폜���ꂽ�ꍇ�A�^�[���̊J�n�܂ő҂z��
		vector< shared_ptr<GameObject> > m_WaitRemoveObjectVec;
		//Sprite�������łȂ����𕪗�����z��
		vector< shared_ptr<GameObject> > m_SpriteVec;
		vector< shared_ptr<GameObject> > m_Object3DVec;
		//3D�̓����Ɣ񓧖��𕪗�����z��
		vector< shared_ptr<GameObject> > m_Object3DNormalVec;
		vector< shared_ptr<GameObject> > m_Object3DAlphaVec;


		//����Draw����Ă���r���[�̃C���f�b�N�X
		size_t m_DrawViewIndex;
		//�r���[�̃|�C���^
		shared_ptr<ViewBase> m_ViewBase;
		//���C�g�̃|�C���^
		shared_ptr<LightBase> m_LightBase;
		//�V�F�A�I�u�W�F�N�g�|�C���^�̃}�b�v
		map<const wstring, weak_ptr<GameObject> > m_SharedMap;
		//�V�F�A�O���[�v�̃|�C���^�̃}�b�v
		map<const wstring, shared_ptr<GameObjectGroup> >  m_SharedGroupMap;
		vector< shared_ptr<Stage> > m_ChildStageVec;	//�q���X�e�[�W�̔z��
		weak_ptr<Stage> m_ParentStage;		//�e�X�e�[�W
		//�V���h�E�}�b�v���g�����ǂ���
		bool m_IsShadowmapDraw;

		Impl() :
			m_UpdateActive(true),
			m_DrawViewIndex(0),
			m_IsShadowmapDraw(true)
		{}
		~Impl() {}
		void RemoveTargetGameObject(const shared_ptr<GameObject>& targetobj);
	};
	void Stage::Impl::RemoveTargetGameObject(const shared_ptr<GameObject>& targetobj) {
		auto it = m_GameObjectVec.begin();
		while (it != m_GameObjectVec.end()) {
			if (*it == targetobj) {
				m_GameObjectVec.erase(it);
				return;
			}
			it++;
		}
	}


	//--------------------------------------------------------------------------------------
	//	�X�e�[�W�N���X
	//--------------------------------------------------------------------------------------
	Stage::Stage() :
		ObjectInterface(),
		ShapeInterface(),
		pImpl(new Impl())
	{}
	Stage::~Stage() {}

	//�v���C�x�[�g�T�u�֐�
	void Stage::PushBackGameObject(const shared_ptr<GameObject>& Ptr) {
		//���̃X�e�[�W�̓N���G�C�g��ł���
		if (IsCreated()) {
			pImpl->m_WaitAddObjectVec.push_back(Ptr);
		}
		else {
			//�N���G�C�g�O
			pImpl->m_GameObjectVec.push_back(Ptr);
		}
	}

	//�폜�I�u�W�F�N�g�̐ݒ�
	void Stage::RemoveBackGameObject(const shared_ptr<GameObject>& Ptr) {
		pImpl->m_WaitRemoveObjectVec.push_back(Ptr);
	}

	shared_ptr<GameObject> Stage::GetSharedGameObjectEx(const wstring& Key, bool ExceptionActive)const {
		map<const wstring, weak_ptr<GameObject> >::const_iterator it;
		//�d���L�[�̌���
		it = pImpl->m_SharedMap.find(Key);
		if (it != pImpl->m_SharedMap.end()) {
			if (it->second.expired()) {
				//���łɖ���
				if (ExceptionActive) {
					//��O����
					wstring keyerr = Key;
					throw BaseException(
						L"�I�u�W�F�N�g�������ł�",
						keyerr,
						L"Stage::GetSharedGameObject()"
					);
				}
			}
			return it->second.lock();
		}
		else {
			//�w��̖��O��������Ȃ�����
			if (ExceptionActive) {
				//��O����
				wstring keyerr = Key;
				throw BaseException(
					L"�I�u�W�F�N�g��������܂���",
					keyerr,
					L"Stage::GetSharedGameObject()"
				);
			}
		}
		return nullptr;
	}

	shared_ptr<ParticleManager> Stage::GetParticleManager(bool Addtype) const { 
		if (Addtype) {
			return pImpl->m_AddParticleManager;
		}
		else {
			return pImpl->m_AlphaParticleManager;
		}
	}

	vector< shared_ptr<GameObject> >& Stage::GetGameObjectVec() { return pImpl->m_GameObjectVec; }

	//�ǉ���폜�҂��ɂȂ��Ă�I�u�W�F�N�g��ǉ��E�폜����
	void Stage::SetWaitToObjectVec(){
		if (!pImpl->m_WaitRemoveObjectVec.empty()) {
			for (auto Ptr : pImpl->m_WaitRemoveObjectVec) {
				pImpl->RemoveTargetGameObject(Ptr);
			}
		}
		pImpl->m_WaitRemoveObjectVec.clear();
		if (!pImpl->m_WaitAddObjectVec.empty()){
			for (auto Ptr : pImpl->m_WaitAddObjectVec){
				pImpl->m_GameObjectVec.push_back(Ptr);
			}
		}
		pImpl->m_WaitAddObjectVec.clear();
	}



	shared_ptr<GameObject> Stage::GetSharedObject(const wstring& Key, bool ExceptionActive)const {
		shared_ptr<GameObject> Ptr = GetSharedGameObjectEx(Key, ExceptionActive);
		return Ptr;
	}


	void Stage::SetSharedGameObject(const wstring& Key, const shared_ptr<GameObject>& Ptr) {
		map<const wstring, weak_ptr<GameObject> >::iterator it;
		//�d���L�[�̌���
		it = pImpl->m_SharedMap.find(Key);
		if (it != pImpl->m_SharedMap.end()) {
			//���ɑ��݂���
			//��O����
			wstring keyerr = Key;
			throw BaseException(
				L"�����̃V�F�A�I�u�W�F�N�g������܂�",
				keyerr,
				L"Stage::SetSharedGameObjectEx()"
			);
		}
		else {
			pImpl->m_SharedMap[Key] = Ptr;
		}
	}

	shared_ptr<GameObjectGroup> Stage::CreateSharedObjectGroup(const wstring& Key) {
		try {
			map<const wstring, shared_ptr<GameObjectGroup> >::iterator it;
			//�d���L�[�̌���
			it = pImpl->m_SharedGroupMap.find(Key);
			if (it != pImpl->m_SharedGroupMap.end()) {
				//���ɑ��݂���
				//��O����
				wstring keyerr = Key;
				throw BaseException(
					L"�����̃V�F�A�I�u�W�F�N�g�z�񂪂���܂�",
					keyerr,
					L"Stage::CreateSharedObjectGroup()"
				);
			}
			else {
				auto Ptr = ObjectFactory::Create<GameObjectGroup>();
				pImpl->m_SharedGroupMap[Key] = Ptr;
				return Ptr;
			}
		}
		catch (...) {
			throw;
		}
	}

	shared_ptr<GameObjectGroup> Stage::GetSharedObjectGroup(const wstring& Key, bool ExceptionActive)const {
		//�d���L�[�̌���
		auto it = pImpl->m_SharedGroupMap.find(Key);
		if (it != pImpl->m_SharedGroupMap.end()) {
			//�y�A��second��Ԃ�
			return it->second;
		}
		else {
			//�w��̖��O��������Ȃ�����
			if (ExceptionActive) {
				//��O����
				wstring keyerr = Key;
				throw BaseException(
					L"�w��̃L�[��������܂���",
					keyerr,
					L"Stage::GetSharedObjectGroup() const"
				);
			}
		}
		return nullptr;
	}

	void Stage::SetSharedObjectGroup(const wstring& Key, const shared_ptr<GameObjectGroup>& NewPtr) {
		//�d���L�[�̌���
		auto it = pImpl->m_SharedGroupMap.find(Key);
		if (it != pImpl->m_SharedGroupMap.end()) {
			//��O����
			wstring keyerr = Key;
			throw BaseException(
				L"�����̃V�F�A�I�u�W�F�N�g�z�񂪂���܂�",
				keyerr,
				L"Stage::SetSharedObjectGroup()"
			);
		}
		else {
			//�w��̖��O��������Ȃ�����
			//�o�^�ł���
			pImpl->m_SharedGroupMap[Key] = NewPtr;
		}
	}


	vector< shared_ptr<Stage> >& Stage::GetChileStageVec() {
		return pImpl->m_ChildStageVec;
	}
	void Stage::AddChileStageBase(const shared_ptr<Stage>& ChildStage) {
		pImpl->m_ChildStageVec.push_back(ChildStage);
		ChildStage->SetParentStage(GetThis<Stage>());
	}

	shared_ptr<Stage> Stage::GetParentStage() const {
		if (!pImpl->m_ParentStage.expired()) {
			return  pImpl->m_ParentStage.lock();
		}
		return nullptr;
	}
	void Stage::SetParentStage(const shared_ptr<Stage>& ParentStage) {
		pImpl->m_ParentStage = ParentStage;
	}


	void Stage::SetView(const shared_ptr<ViewBase>& v) {
		pImpl->m_ViewBase = v;
	}

	const shared_ptr<ViewBase>& Stage::GetView(bool ExceptionActive)const {
		if (ExceptionActive) {
			if (!pImpl->m_ViewBase) {
				throw BaseException(
					L"�X�e�[�W�Ƀr���[���ݒ肳��Ă��܂���B",
					L"if (!pImpl->m_ViewBase)",
					L"Stage::GetView()"
				);
			}
		}
		return pImpl->m_ViewBase;
	}

	void Stage::SetLight(const shared_ptr<LightBase>& L) {
		pImpl->m_LightBase = L;

	}
	const shared_ptr<LightBase>& Stage::GetLight()const {
		if (!pImpl->m_LightBase) {
			throw BaseException(
				L"�X�e�[�W�Ƀ��C�g���ݒ肳��Ă��܂���B",
				L"if (!pImpl->m_LightBase)",
				L"Stage::GetLight()"
			);
		}
		return pImpl->m_LightBase;
	}


	//�A�N�Z�T
	bool Stage::IsUpdateActive() const { return pImpl->m_UpdateActive; }
	bool Stage::GetUpdateActive() const { return pImpl->m_UpdateActive; }
	void Stage::SetUpdateActive(bool b) { pImpl->m_UpdateActive = b; }

	void Stage::OnPreCreate() {
		//�p�[�e�B�N���}�l�[�W���̍쐬(��������)
		pImpl->m_AlphaParticleManager = ObjectFactory::Create<ParticleManager>(GetThis<Stage>(),false);
		//�p�[�e�B�N���}�l�[�W���̍쐬(���Z����)
		pImpl->m_AddParticleManager = ObjectFactory::Create<ParticleManager>(GetThis<Stage>(),true);
		//�R���W�����Ǘ��҂̍쐬
		pImpl->m_CollisionManager = ObjectFactory::Create<CollisionManager>(GetThis<Stage>());
	}


	//�X�e�[�W���̍X�V�i�V�[�������΂��j
	void Stage::UpdateStage() {
		//�ǉ��E�폜�܂��I�u�W�F�N�g�̒ǉ��ƍ폜
		SetWaitToObjectVec();
		//Transform�R���|�[�l���g�̒l���o�b�N�A�b�v�ɃR�s�[
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsUpdateActive()) {
				auto ptr2 = ptr->GetComponent<Transform>();
				ptr2->SetToBefore();
				auto RigidPtr = ptr->GetComponent<Rigidbody>(false);
				if (RigidPtr) {
					//Rigidbody������΃t�H�[�X��������
					RigidPtr->SetForce(0, 0, 0);
				}
			}
		}

		//�z�u�I�u�W�F�N�g�̍X�V����
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsUpdateActive()) {
				ptr->OnUpdate();
			}
		}
		//���g�̍X�V����
		if (IsUpdateActive()) {
			OnUpdate();
		}

		//�z�u�I�u�W�F�N�g�̃R���|�[�l���g�X�V
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsUpdateActive()) {
				ptr->ComponentUpdate();
			}
		}
		//�Փ˔���̍X�V�i�X�e�[�W����Ăԁj
		UpdateCollision();
		//�Փ˔���̃��b�Z�[�W���s�i�X�e�[�W����Ăԁj
		UpdateMessageCollision();
		//�z�u�I�u�W�F�N�g�̍X�V�㏈��
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsUpdateActive()) {
				ptr->OnUpdate2();
			}
		}
		//���g�̍X�V1
		if (IsUpdateActive()) {
			OnUpdate2();
		}
		//���g�̃r���[���A�b�v�f�[�g
		auto ViewPtr = GetView(false);
		if (ViewPtr && ViewPtr->IsUpdateActive()) {
			ViewPtr->OnUpdate();
		}

		//�R���W�����̃��Z�b�g
		for (auto ptr : GetGameObjectVec()) {
			ptr->CollisionReset();
		}
		//�q���X�e�[�W�̍X�V
		for (auto PtrChileStage : GetChileStageVec()) {
			PtrChileStage->UpdateStage();
		}
	}


	//�Փ˔���̍X�V�i�X�e�[�W����Ăԁj
	//�Փ˔�����J�X�^�}�C�Y���邽�߂ɂ�
	//���̊֐��𑽏d��`����
	void Stage::UpdateCollision() {
		//�Փ˔���Ǘ��҂�Update
		pImpl->m_CollisionManager->OnUpdate();
	}

	void Stage::UpdateMessageCollision() {
		//�z�u�I�u�W�F�N�g�̏Փ˃��b�Z�[�W���s
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsUpdateActive()) {
				ptr->ToMessageCollision();
			}
		}

	}

	//�V���h�E�}�b�v���g�����ǂ���
	bool Stage::IsShadowmapDraw() const {
		return pImpl->m_IsShadowmapDraw;
	}
	void Stage::SetShadowmapDraw(bool b) {
		pImpl->m_IsShadowmapDraw = b;
	}


	//�X�e�[�W���̃V���h�E�}�b�v�`��i�X�e�[�W�����΂��j
	void Stage::DrawShadowmapStage() {
		for (auto ptr : pImpl->m_GameObjectVec) {
			if (ptr->IsDrawActive()) {
				ptr->DrawShadowmap();
			}
		}
	}

	//�X�e�[�W���̕`��i�X�e�[�W�����΂��j
	void Stage::DrawStage() {
		//���C���[�̎擾�Ɛݒ�
		set<int> DrawLayers;
		//Sprite�������łȂ����𕪗�
		for (auto ptr : GetGameObjectVec()) {
			if (ptr->IsDrawActive()) {
				//�`�惌�C���[�ɓo�^
				DrawLayers.insert(ptr->GetDrawLayer());
				//Sprite�����̔h���N���X�Ȃ番��
				if (ptr->GetDynamicComponent<SpriteBaseDraw>(false) || ptr->IsSpriteDraw()) {
					pImpl->m_SpriteVec.push_back(ptr);
				}
				else {
					pImpl->m_Object3DVec.push_back(ptr);
				}
			}
		}
		//3D�̓����Ɣ񓧖��𕪗�
		for (auto ptr : pImpl->m_Object3DVec) {
			if (ptr->IsDrawActive()) {
				if (ptr->IsAlphaActive()) {
					pImpl->m_Object3DAlphaVec.push_back(ptr);
				}
				else {
					pImpl->m_Object3DNormalVec.push_back(ptr);
				}
			}
		}

		auto PtrCamera = pImpl->m_ViewBase->GetTargetCamera();
		//�J�����̈ʒu
		Vector3 CameraEye = PtrCamera->GetEye();
		//������3D�I�u�W�F�N�g���J��������̋����Ń\�[�g
		//�ȉ��́A�I�u�W�F�N�g�������Ɏ��bool��Ԃ������_��
		//--------------------------------------------------------
		auto func = [&](shared_ptr<GameObject>& Left, shared_ptr<GameObject>& Right)->bool {
			auto PtrLeftTrans = Left->GetComponent<Transform>();
			auto PtrRightTrans = Right->GetComponent<Transform>();

			auto LeftPos = PtrLeftTrans->GetWorldMatrix().PosInMatrixSt();
			auto RightPos = PtrRightTrans->GetWorldMatrix().PosInMatrixSt();

			auto LeftLen = Vector3EX::Length(LeftPos - CameraEye);
			auto RightLen = Vector3EX::Length(RightPos - CameraEye);

			return (LeftLen > RightLen);
		};

		std::sort(pImpl->m_Object3DAlphaVec.begin(), pImpl->m_Object3DAlphaVec.end(), func);

		//3D�m�[�}���I�u�W�F�N�g�̕`�揀��
		for (auto ptr : pImpl->m_Object3DNormalVec) {
			ptr->OnPreDraw();
		}
		//3D�����I�u�W�F�N�g�̕`�揀��
		for (auto ptr : pImpl->m_Object3DAlphaVec) {
			ptr->OnPreDraw();
		}
		//�p�[�e�B�N���̕`�揀���i�����j
		GetParticleManager(false)->OnPreDraw();
		//�p�[�e�B�N���̕`�揀���i���Z�j
		GetParticleManager(true)->OnPreDraw();
		//�X�v���C�g�I�u�W�F�N�g�̕`�揀��
		for (auto ptr : pImpl->m_SpriteVec) {
			ptr->OnPreDraw();
		}

		//--------------------------------------------------------
		//�X�v���C�g��Z���W�����Ń\�[�g
		//�ȉ��́A�I�u�W�F�N�g�������Ɏ��bool��Ԃ������_��
		//--------------------------------------------------------
		auto funcSprite = [&](shared_ptr<GameObject>& Left, shared_ptr<GameObject>& Right)->bool {
			auto PtrLeftTrans = Left->GetComponent<Transform>();
			auto PtrRightTrans = Right->GetComponent<Transform>();

			auto LeftPos = PtrLeftTrans->GetWorldMatrix().PosInMatrixSt();
			auto RightPos = PtrRightTrans->GetWorldMatrix().PosInMatrixSt();

			float LeftZ = LeftPos.z;
			float RightZ = RightPos.z;
			return (LeftZ > RightZ);
		};
		std::sort(pImpl->m_SpriteVec.begin(), pImpl->m_SpriteVec.end(), funcSprite);

		for (auto it = DrawLayers.begin(); it != DrawLayers.end(); it++) {
			int Tgt = *it;
			//3D�m�[�}���I�u�W�F�N�g�̕`��
			for (auto ptr : pImpl->m_Object3DNormalVec) {
				if (ptr->GetDrawLayer() == Tgt) {
					ptr->OnDraw();
				}
			}
			//3D�����I�u�W�F�N�g�̕`��
			for (auto ptr : pImpl->m_Object3DAlphaVec) {
				if (ptr->GetDrawLayer() == Tgt) {
					ptr->OnDraw();
				}
			}
			//�p�[�e�B�N���̕`��
			//�p�[�e�B�N���}�l�[�W���͕`�惌�C���[���Ƃɏ����������̂�
			//�����C���[�`�悷��
			//��������
			GetParticleManager(false)->OnDraw();
			//���Z����
			GetParticleManager(true)->OnDraw();
			//�X�v���C�g�I�u�W�F�N�g�̕`��
			for (auto ptr : pImpl->m_SpriteVec) {
				if (ptr->GetDrawLayer() == Tgt) {
					ptr->OnDraw();
				}
			}
		}
		//�X�e�[�W��Draw();
		OnDraw();
		//���[�N�p�z��̃N���A
		//���[�N�z��͖��^�[�����Ƃɏ���������邪�A
		//�ő�l�͌���Ȃ��̂�2��ڂ̃^�[���ȍ~�͍����ɓ��삷��
		pImpl->m_Object3DVec.clear();
		pImpl->m_SpriteVec.clear();
		pImpl->m_Object3DNormalVec.clear();
		pImpl->m_Object3DAlphaVec.clear();
	}

	//�X�e�[�W���̂��ׂĂ̕`��i�V�[�������΂��j
	void Stage::RenderStage() {
		//�`��f�o�C�X�̎擾
		auto Dev = App::GetApp()->GetDeviceResources();
		auto MultiPtr = dynamic_pointer_cast<MultiView>(GetView());
		if (MultiPtr) {
			for (size_t i = 0; i < MultiPtr->GetViewSize(); i++) {
				MultiPtr->SetTargetIndex(i);
				if (IsShadowmapDraw()) {
					Dev->ClearShadowmapViews();
					Dev->StartShadowmapDraw();
					DrawShadowmapStage();
					Dev->EndShadowmapDraw();
				}
				//�f�t�H���g�`��̊J�n
				Dev->StartDefaultDraw();
				RsSetViewport(MultiPtr->GetTargetViewport());
				DrawStage();
				//�f�t�H���g�`��̏I��
				Dev->EndDefaultDraw();
			}
			//�`�悪�I�������X�V�����p�ɐ擪�̃J�����Ƀ^�[�Q�b�g��ݒ肷��
			MultiPtr->SetTargetIndex(0);
		}
		else {
			if (IsShadowmapDraw()) {
				Dev->ClearShadowmapViews();
				Dev->StartShadowmapDraw();
				DrawShadowmapStage();
				Dev->EndShadowmapDraw();
			}
			//�f�t�H���g�`��̊J�n
			Dev->StartDefaultDraw();
			RsSetViewport(GetView()->GetTargetViewport());
			DrawStage();
			//�f�t�H���g�`��̏I��
			Dev->EndDefaultDraw();
		}
		//�q���X�e�[�W�̕`��
		for (auto PtrChileStage : pImpl->m_ChildStageVec) {
			PtrChileStage->RenderStage();
		}
	}



	//--------------------------------------------------------------------------------------
	//	struct SceneBase::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct SceneBase::Impl {
		//�A�N�e�B�u�ȃX�e�[�W
		shared_ptr<Stage> m_ActiveStage;
		//�N���A����F
		Color4 m_ClearColor;
		Impl():
			m_ActiveStage(),
			m_ClearColor(0,0,0,1.0f)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	///	�V�[���e�N���X
	//--------------------------------------------------------------------------------------

	void SceneBase::ConvertVertex(const vector<VertexPositionNormalTexture>& vertices,
		vector<VertexPositionColor>& new_pc_vertices,
		vector<VertexPositionTexture>& new_pt_vertices, vector<VertexPositionNormalTangentTexture>& new_pntnt_vertices) {
		new_pc_vertices.clear();
		new_pt_vertices.clear();
		new_pntnt_vertices.clear();
		for (size_t i = 0; i < vertices.size(); i++) {
			VertexPositionColor new_pc_v;
			VertexPositionTexture new_pt_v;
			VertexPositionNormalTangentTexture new_pntnt_v;

			new_pc_v.position = vertices[i].position;
			new_pc_v.color = Color4(1.0f, 1.0f, 1.0f, 1.0f);

			new_pt_v.position = vertices[i].position;
			new_pt_v.textureCoordinate = vertices[i].textureCoordinate;

			new_pntnt_v.position = vertices[i].position;
			new_pntnt_v.normal = vertices[i].normal;
			new_pntnt_v.textureCoordinate = vertices[i].textureCoordinate;
			Vector3 n = Vector3EX::Cross(new_pntnt_v.normal, Vector3(0, 1, 0));
			new_pntnt_v.tangent = n;
			new_pntnt_v.tangent.w = 0.0f;

			new_pc_vertices.push_back(new_pc_v);
			new_pt_vertices.push_back(new_pt_v);
			new_pntnt_vertices.push_back(new_pntnt_v);

		}
	}


	SceneBase::SceneBase() :
		SceneInterface(),
		pImpl(new Impl())
	{
		try {
			//�f�t�H���g�̃��\�[�X�̍쐬
			App::GetApp()->RegisterResource(L"DEFAULT_SQUARE", MeshResource::CreateSquare(1.0f));
			App::GetApp()->RegisterResource(L"DEFAULT_CUBE", MeshResource::CreateCube(1.0f));
			App::GetApp()->RegisterResource(L"DEFAULT_SPHERE", MeshResource::CreateSphere(1.0f, 18));
			App::GetApp()->RegisterResource(L"DEFAULT_CAPSULE", MeshResource::CreateCapsule(1.0f, 1.0f, 18));
			App::GetApp()->RegisterResource(L"DEFAULT_CYLINDER", MeshResource::CreateCylinder(1.0f, 1.0f, 18));
			App::GetApp()->RegisterResource(L"DEFAULT_CONE", MeshResource::CreateCone(1.0f, 1.0f, 18));
			App::GetApp()->RegisterResource(L"DEFAULT_TORUS", MeshResource::CreateTorus(1.0f, 0.3f, 18));
			App::GetApp()->RegisterResource(L"DEFAULT_TETRAHEDRON", MeshResource::CreateTetrahedron(1.0f));
			App::GetApp()->RegisterResource(L"DEFAULT_OCTAHEDRON", MeshResource::CreateOctahedron(1.0f));
			App::GetApp()->RegisterResource(L"DEFAULT_DODECAHEDRON", MeshResource::CreateDodecahedron(1.0f));
			App::GetApp()->RegisterResource(L"DEFAULT_ICOSAHEDRON", MeshResource::CreateIcosahedron(1.0f));

			vector<VertexPositionNormalTexture> vertices;
			vector<VertexPositionColor> new_pc_vertices;
			vector<VertexPositionTexture> new_pt_vertices;
			vector<VertexPositionNormalTangentTexture> new_pntnt_vertices;

			vector<uint16_t> indices;

			MeshUtill::CreateSquare(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_SQUARE", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_SQUARE", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_SQUARE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateCube(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_CUBE", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_CUBE", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_CUBE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateSphere(1.0f,18, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_SPHERE", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_SPHERE", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_SPHERE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			Vector3 PointA(0, -1.0f / 2.0f, 0);
			Vector3 PointB(0, 1.0f / 2.0f, 0);
			//Capsule�̍쐬(�w���p�[�֐��𗘗p)
			MeshUtill::CreateCapsule(1.0f, PointA, PointB,18, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_CAPSULE", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_CAPSULE", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_CAPSULE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateCylinder(1.0f, 1.0f, 18, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_CYLINDER", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_CYLINDER", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_CYLINDER", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateCone(1.0f, 1.0f, 18, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_CONE", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_CONE", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_CONE", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateTorus(1.0f, 0.3f, 18, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_TORUS", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_TORUS", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_TORUS", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateTetrahedron(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_TETRAHEDRON", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_TETRAHEDRON", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_TETRAHEDRON", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateOctahedron(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_OCTAHEDRON", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_OCTAHEDRON", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_OCTAHEDRON", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateDodecahedron(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_DODECAHEDRON", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_DODECAHEDRON", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_DODECAHEDRON", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();

			MeshUtill::CreateIcosahedron(1.0f, vertices, indices);
			ConvertVertex(vertices, new_pc_vertices, new_pt_vertices, new_pntnt_vertices);
			MeshUtill::SetNormalTangent(new_pntnt_vertices);
			App::GetApp()->RegisterResource(L"DEFAULT_PC_ICOSAHEDRON", MeshResource::CreateMeshResource(new_pc_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PT_ICOSAHEDRON", MeshResource::CreateMeshResource(new_pt_vertices, indices, false));
			App::GetApp()->RegisterResource(L"DEFAULT_PNTnT_ICOSAHEDRON", MeshResource::CreateMeshResource(new_pntnt_vertices, indices, false));
			vertices.clear();
			indices.clear();



		}
		catch (...) {
			throw;
		}
	}
	SceneBase::~SceneBase() {}

	shared_ptr<Stage> SceneBase::GetActiveStage() const {
		if (!pImpl->m_ActiveStage) {
			//�A�N�e�B�u�ȃX�e�[�W�������Ȃ�
			throw BaseException(
				L"�A�N�e�B�u�ȃX�e�[�W������܂���",
				L"if(!m_ActiveStage.get())",
				L"SceneBase::GetActiveStage()"
			);
		}
		return pImpl->m_ActiveStage;
	}
	void SceneBase::SetActiveStage(const shared_ptr<Stage>& stage) {
		pImpl->m_ActiveStage = stage;
	}

	Color4 SceneBase::GetClearColor() const {
		return pImpl->m_ClearColor;

	}
	void SceneBase::SetClearColor(const Color4& col) {
		pImpl->m_ClearColor = col;
	}


	void SceneBase::OnUpdate() {
		if (pImpl->m_ActiveStage) {
			//�X�e�[�W�̃A�b�v�f�[�g
			pImpl->m_ActiveStage->UpdateStage();
		}
	}
	void SceneBase::OnDraw() {
		if (pImpl->m_ActiveStage) {
			//�`��f�o�C�X�̎擾
			auto Dev = App::GetApp()->GetDeviceResources();
			Dev->ClearDefaultViews(GetClearColor());
			pImpl->m_ActiveStage->RenderStage();

		}
	}

	//--------------------------------------------------------------------------------------
	//	struct StageCellMap::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct StageCellMap::Impl {
		//�Z���̃|�C���^�̔z��i2�����j
		vector<vector<CellPiece>> m_CellVec;
		const UINT m_MaxCellSize = 100;
		//�Z����XZ�����̐�
		UINT m_SizeX;
		UINT m_SizeZ;
		//�Z��1�̃X�e�[�W��̃T�C�Y
		float m_PieceSize;
		//�f�t�H���g�̃R�X�g
		int m_DefaultCost;
		//�X�e�[�W��ł��̃Z���}�b�v��W�J����AABB
		AABB m_MapAABB;
		//���b�V��
		shared_ptr<MeshResource> m_LineMesh;
		//���b�V���쐬�̂��߂̒��_�̔z��
		vector<VertexPositionColor> m_Vertices;
		//�Z��������`�悷�邩�ǂ���
		bool m_IsCellStringActive;
		Impl() :
			m_IsCellStringActive(false)
		{}
		~Impl() {}
		void Init(const Vector3& MiniPos,
			float PieceSize, UINT PieceCountX, UINT PieceCountZ, int DefaultCost);
		void Create(const shared_ptr<MultiStringSprite>& StringPtr, const shared_ptr<Stage>& StagePtr);
	};
	void StageCellMap::Impl::Init(const Vector3& MiniPos,
		float PieceSize, UINT PieceCountX, UINT PieceCountZ, int DefaultCost) {
		m_PieceSize = PieceSize;
		m_DefaultCost = DefaultCost;
		m_SizeX = PieceCountX;
		if (m_SizeX <= 0) {
			m_SizeX = 1;
		}
		if (m_SizeX >= m_MaxCellSize) {
			throw BaseException(
				L"�Z����X�������ő�l�𒴂��܂���",
				L"if (m_SizeX >= m_MaxCellSize)",
				L"StageCellMap::Impl::Init()"
			);
		}
		m_SizeZ = PieceCountZ;
		if (m_SizeZ <= 0) {
			m_SizeZ = 1;
		}
		if (m_SizeZ >= m_MaxCellSize) {
			throw BaseException(
				L"�Z����Z�������ő�l�𒴂��܂���",
				L"if (m_SizeZ >= m_MaxCellSize)",
				L"StageCellMap::Impl::Init()"
			);
		}
		m_MapAABB.m_Min = MiniPos;
		m_MapAABB.m_Max.x = m_MapAABB.m_Min.x + m_PieceSize * (float)m_SizeX;
		m_MapAABB.m_Max.y = m_MapAABB.m_Min.y + m_PieceSize;
		m_MapAABB.m_Max.z = m_MapAABB.m_Min.z + m_PieceSize * (float)m_SizeZ;
		Vector3 PieceVec(m_PieceSize, m_PieceSize, m_PieceSize);
		//�z��̏�����
		m_CellVec.resize(m_SizeX);
		for (UINT x = 0; x < m_SizeX; x++) {
			m_CellVec[x].resize(m_SizeZ);
			for (UINT z = 0; z < m_SizeZ; z++) {
				m_CellVec[x][z].m_Index.x = x;
				m_CellVec[x][z].m_Index.z = z;
				m_CellVec[x][z].m_Cost = m_DefaultCost;
				AABB Piece;
				Piece.m_Min.x = m_MapAABB.m_Min.x + (float)x * m_PieceSize;
				Piece.m_Min.y = m_MapAABB.m_Min.y;
				Piece.m_Min.z = m_MapAABB.m_Min.z + (float)z * m_PieceSize;
				Piece.m_Max = Piece.m_Min + PieceVec;
				m_CellVec[x][z].m_PieceRange = Piece;
			}
		}
	}

	void StageCellMap::Impl::Create(const shared_ptr<MultiStringSprite>& StringPtr, const shared_ptr<Stage>& StagePtr) {
		Vector3 Min = m_MapAABB.m_Min;
		Vector3 Max = m_MapAABB.m_Max;
		Color4 Col(1.0f, 1.0f, 1.0f, 1.0f);

		Vector3 LineFrom(Min);
		Vector3 LineTo(Min);
		LineTo.x = Max.x;

		m_Vertices.clear();
		for (UINT z = 0; z <= m_SizeZ; z++) {
			m_Vertices.push_back(VertexPositionColor(LineFrom, Col));
			m_Vertices.push_back(VertexPositionColor(LineTo, Col));
			LineFrom.z += m_PieceSize;
			LineTo.z += m_PieceSize;
		}

		LineFrom = Min;
		LineTo = Min;
		LineTo.z = Max.z;
		for (UINT x = 0; x <= m_SizeX; x++) {
			m_Vertices.push_back(VertexPositionColor(LineFrom, Col));
			m_Vertices.push_back(VertexPositionColor(LineTo, Col));
			LineFrom.x += m_PieceSize;
			LineTo.x += m_PieceSize;
		}
		//���b�V���̍쐬�i�ύX�ł��Ȃ��j
		m_LineMesh = MeshResource::CreateMeshResource(m_Vertices, false);

		//�X�v���C�g������̏�����
		Matrix4X4 World, View, Proj;

		//���[���h�s��̌���
		Quaternion Qt;
		Qt.Normalize();
		World.AffineTransformation(
			Vector3(1.0, 1.0, 1.0),			//�X�P�[�����O
			Vector3(0, 0, 0),		//��]�̒��S�i�d�S�j
			Qt,				//��]�p�x
			Vector3(0, 0.01f, 0)				//�ʒu
		);

		auto PtrCamera = StagePtr->GetView()->GetTargetCamera();
		View = PtrCamera->GetViewMatrix();
		Proj = PtrCamera->GetProjMatrix();
		auto viewport = StagePtr->GetView()->GetTargetViewport();
		World *= View;
		World *= Proj;

		StringPtr->ClearTextBlock();
		for (UINT x = 0; x < m_CellVec.size(); x++) {
			for (UINT z = 0; z < m_CellVec[x].size(); z++) {
				Vector3 Pos = m_CellVec[x][z].m_PieceRange.GetCenter();

				Pos.y = m_CellVec[x][z].m_PieceRange.m_Min.y;
				Pos.WorldToSCreen(World, viewport.Width, viewport.Height);
				Rect2D<float> rect(Pos.x, Pos.y, Pos.x + 50, Pos.y + 20);

				wstring str(L"");
				str += Util::IntToWStr(x);
				str += L",";
				str += Util::IntToWStr(z);

				if (Pos.z < viewport.MinDepth || Pos.z > viewport.MaxDepth) {
					StringPtr->InsertTextBlock(rect, str, true);
				}
				else {
					StringPtr->InsertTextBlock(rect, str, false);
				}
			}
		}
	}


	//--------------------------------------------------------------------------------------
	//	�X�e�[�W�̃Z���}�b�v�i�h���N���X����邩�C���X�^���X���쐬����j
	//--------------------------------------------------------------------------------------



	StageCellMap::StageCellMap(const shared_ptr<Stage>& StagePtr, const Vector3& MiniPos,
		float PieceSize, UINT PieceCountX, UINT PieceCountZ, int DefaultCost):
		GameObject(StagePtr),
		pImpl(new Impl())
	{
		pImpl->Init(MiniPos, PieceSize, PieceCountX, PieceCountZ, DefaultCost);
	}



	StageCellMap::~StageCellMap() {}

	bool StageCellMap::IsCellStringActive() {
		return pImpl->m_IsCellStringActive;

	}
	void StageCellMap::SetCellStringActive(bool b) {
		pImpl->m_IsCellStringActive = b;
	}

	vector<vector<CellPiece>>& StageCellMap::GetCellVec() const {
		return pImpl->m_CellVec;
	}
	//������
	void StageCellMap::OnCreate(){
		pImpl->Create(AddComponent<MultiStringSprite>(), GetStage());
		SetDrawActive(false);
	}

	bool StageCellMap::FindCell(const Vector3& Pos, CellIndex& ret) {
		for (UINT x = 0; x < pImpl->m_CellVec.size(); x++) {
			for (UINT z = 0; z < pImpl->m_CellVec[x].size(); z++) {
				if (pImpl->m_CellVec[x][z].m_PieceRange.PtInAABB(Pos)) {
					ret = pImpl->m_CellVec[x][z].m_Index;
					return true;
				}
			}
		}
		return false;
	}

	void StageCellMap::FindNearCell(const Vector3& Pos, CellIndex& ret) {
		if (FindCell(Pos, ret)) {
			return;
		}
		float len = 0;
		bool isset = false;
		for (UINT x = 0; x < pImpl->m_CellVec.size(); x++) {
			for (UINT z = 0; z < pImpl->m_CellVec[x].size(); z++) {
				if (!isset) {
					auto cellcenter = pImpl->m_CellVec[x][z].m_PieceRange.GetCenter();
					len = Vector3EX::Length(Pos - cellcenter);
					ret = pImpl->m_CellVec[x][z].m_Index;
					isset = true;
				}
				else {
					auto cellcenter = pImpl->m_CellVec[x][z].m_PieceRange.GetCenter();
					auto templen = Vector3EX::Length(Pos - cellcenter);
					if (len > templen) {
						len = templen;
						ret = pImpl->m_CellVec[x][z].m_Index;
					}
				}
			}
		}
	}


	bool StageCellMap::FindAABB(const CellIndex& Index, AABB& ret) {
		for (UINT x = 0; x < pImpl->m_CellVec.size(); x++) {
			for (UINT z = 0; z < pImpl->m_CellVec[x].size(); z++) {
				if (pImpl->m_CellVec[x][z].m_Index == Index) {
					ret = pImpl->m_CellVec[x][z].m_PieceRange;
					return true;
				}
			}
		}
		return false;
	}

	void StageCellMap::FindNearAABB(const Vector3& Pos, AABB& ret) {
		CellIndex retcell;
		FindNearCell(Pos, retcell);
		ret = pImpl->m_CellVec[retcell.x][retcell.z].m_PieceRange;
	}


	void StageCellMap::GetMapAABB(AABB& ret) const {
		ret =  pImpl->m_MapAABB;
	}

	void StageCellMap::RefleshCellMap(const Vector3& MiniPos,
		float PieceSize, UINT PieceCountX, UINT PieceCountZ, int DefaultCost) {
		pImpl->Init(MiniPos,PieceSize,PieceCountX, PieceCountZ,DefaultCost);
		pImpl->Create(GetComponent<MultiStringSprite>(), GetStage());
	}



	void  StageCellMap::OnUpdate() {
		if (pImpl->m_IsCellStringActive) {
			auto StringPtr = GetComponent<MultiStringSprite>();
			Matrix4X4 World, View, Proj;
			World.Identity();
			auto PtrCamera = GetStage()->GetView()->GetTargetCamera();
			View = PtrCamera->GetViewMatrix();
			Proj = PtrCamera->GetProjMatrix();
			auto viewport = GetStage()->GetView()->GetTargetViewport();

			World *= View;
			World *= Proj;

			size_t count = 0;
			for (UINT x = 0; x < pImpl->m_CellVec.size(); x++) {
				for (UINT z = 0; z < pImpl->m_CellVec[x].size(); z++) {
					Vector3 Pos = pImpl->m_CellVec[x][z].m_PieceRange.GetCenter();
					Pos.y = pImpl->m_CellVec[x][z].m_PieceRange.m_Min.y;
					Pos.WorldToSCreen(World, viewport.Width, viewport.Height);

					Rect2D<float> rect(Pos.x, Pos.y, Pos.x + 50, Pos.y + 50);

					wstring str(L"");
					str += Util::IntToWStr(x);
					str += L",";
					str += Util::IntToWStr(z);
					str += L"\nCost: ";
					str += Util::IntToWStr(pImpl->m_CellVec[x][z].m_Cost);

					if (Pos.z < viewport.MinDepth || Pos.z > viewport.MaxDepth) {
						StringPtr->UpdateTextBlock(count, rect, str, true);
					}
					else {
						StringPtr->UpdateTextBlock(count, rect, str, false);
					}
					count++;
				}
			}
		}
	}


	void StageCellMap::OnDraw() {
		if (pImpl->m_IsCellStringActive) {
			GameObject::OnDraw();
		}

		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();

		//�s��̒�`
		Matrix4X4 World, View, Proj;
		//���[���h�s��̌���
		Quaternion Qt;
		Qt.Normalize();
		World.AffineTransformation(
			Vector3(1.0, 1.0, 1.0),			//�X�P�[�����O
			Vector3(0, 0, 0),		//��]�̒��S�i�d�S�j
			Qt,				//��]�p�x
			Vector3(0, 0.01f, 0)				//�ʒu
		);
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		View = CameraPtr->GetViewMatrix();
		//�]�u����
		View.Transpose();
		//�]�u����
		Proj = CameraPtr->GetProjMatrix();
		Proj.Transpose();

		//�R���X�^���g�o�b�t�@�̏���
		SimpleConstants sb;
		sb.World = World;
		sb.View = View;
		sb.Projection = Proj;
		//�G�~�b�V�u���Z�͍s��Ȃ��B
		sb.Emissive = Color4(0, 0, 0, 0);
		sb.Diffuse = Color4(1, 1, 1, 1);
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionColor);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, pImpl->m_LineMesh->GetVertexBuffer().GetAddressOf(), &stride, &offset);

		//�`����@�i���C���j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPCStatic::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPCStatic::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPCStatic::GetPtr()->GetInputLayout());
		//�u�����h�X�e�[�g
		pD3D11DeviceContext->OMSetBlendState(RenderState->GetOpaque(), nullptr, 0xffffffff);
		//�f�v�X�X�e���V���X�e�[�g
		pD3D11DeviceContext->OMSetDepthStencilState(RenderState->GetDepthDefault(), 0);
		//���X�^���C�U�X�e�[�g
		pD3D11DeviceContext->RSSetState(RenderState->GetCullNone());

		//�`��
		pD3D11DeviceContext->Draw(pImpl->m_Vertices.size(), 0);
		//��n��
		Dev->InitializeStates();

	}


}
//end basecross