/*!
@file GameObject.h
@brief �Q�[���I�u�W�F�N�g�A�X�e�[�W
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/
#pragma once
#include "stdafx.h"

namespace basecross {



	//--------------------------------------------------------------------------------------
	///	�Q�[���z�u�I�u�W�F�N�g�e�N���X
	//--------------------------------------------------------------------------------------
	class GameObject :public ObjectInterface, public ShapeInterface {
		shared_ptr<Component> SearchComponent(type_index TypeIndex)const;
		shared_ptr<Transform> GetTransform()const;
		shared_ptr<Rigidbody> GetRigidbody()const;
		shared_ptr<Collision> GetCollision()const;
		shared_ptr<CollisionSphere> GetCollisionSphere()const;
		shared_ptr<CollisionCapsule> GetCollisionCapsule()const;
		shared_ptr<CollisionObb> GetCollisionObb()const;
		shared_ptr<CollisionTriangles> GetCollisionTriangles()const;
		shared_ptr<CollisionRect> GetCollisionRect()const;

		void SetRigidbody(const shared_ptr<Rigidbody>& Ptr);
		void SetTransform(const shared_ptr<Transform>& Ptr);
		void SetCollision(const shared_ptr<Collision>& Ptr);
		void AddMakedComponent(type_index TypeIndex, const shared_ptr<Component>& Ptr);
		template<typename T>
		shared_ptr<T> SearchDynamicComponent()const {
			auto mapPtr = GetCompoMap();
			auto it = mapPtr.begin();
			while (it != mapPtr.end()) {
				auto Ptr = dynamic_pointer_cast<T>(it->second);
				if (Ptr) {
					return Ptr;
				}
				it++;
			}
			return nullptr;
		}
		map<type_index, shared_ptr<Component> >& GetCompoMap() const;
		void RemoveTgtComponent(type_index TypeIndex);

		map<type_index, shared_ptr<Behavior> >& GetBehaviorMap() const;
		shared_ptr<Behavior> SearchBehavior(type_index TypeIndex)const;
		void AddMakedBehavior(type_index TypeIndex, const shared_ptr<Behavior>& Ptr);



	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	StagePtr	�X�e�[�W
		*/
		//--------------------------------------------------------------------------------------
		explicit GameObject(const shared_ptr<Stage>& StagePtr);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObject();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ����𓾂�
		@return	�X�V�������L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool IsUpdateActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ����𓾂�
		@return	�X�V�������L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool GetUpdateActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ�����ݒ肷��
		@param[in]	b	�X�V�������L���Ȃ�Ȃ�true
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetUpdateActive(bool b);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`�揈�����L�����ǂ����𓾂�
		@return	�`�揈�����L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool IsDrawActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`�揈�����L�����ǂ����𓾂�
		@return	�`�揈�����L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool GetDrawActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`�揈�����L�����ǂ�����ݒ肷��
		@param[in]	b	�`�揈�����L���Ȃ�Ȃ�true
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetDrawActive(bool b);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���������i�������܂ށj���L�����ǂ����𓾂�
		@return	���������i�������܂ށj���L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool IsAlphaActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���������i�������܂ށj���L�����ǂ����𓾂�
		@return	���������i�������܂ށj���L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool GetAlphaActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���������i�������܂ށj���L�����ǂ�����ݒ肷��
		@param[in]	b	���������i�������܂ށj���L���Ȃ�Ȃ�true
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetAlphaActive(bool b);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�v���C�g�Ƃ���Draw���邩�ǂ����𓾂�
		@return	�X�v���C�g�Ƃ���Draw����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool IsSpriteDraw() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�v���C�g�Ƃ���Draw���邩�ǂ����𓾂�
		@return	�X�v���C�g�Ƃ���Draw����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool GetSpriteDraw() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�v���C�g�Ƃ���Draw���邩�ǂ�����ݒ肷��
		@param[in]	b	�X�v���C�g�Ƃ���Draw����Ȃ�true
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetSpriteDraw(bool b);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`�惌�C���[�𓾂�i�f�t�H���g0�j
		@return	�`�惌�C���[
		*/
		//--------------------------------------------------------------------------------------
		int GetDrawLayer() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`�惌�C���[��ݒ肷��
		@param[in]	l	�`�惌�C���[�i�}�C�i�X�ݒ�j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void  SetDrawLayer(int l);

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�^�O�̃Z�b�g�𓾂�
		@return	�^�O�̃Z�b�g
		*/
		//--------------------------------------------------------------------------------------
		set<wstring>& GetTagSet() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷��^�O�����݂��邩�ǂ����𓾂�
		@param[in]	tagstr	���؂���^�O
		@return	���݂����true
		*/
		//--------------------------------------------------------------------------------------
		bool FindTag(const wstring& tagstr) const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷��^�O��ǉ�����
		@param[in]	tagstr	�ǉ�����^�O
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void  AddTag(const wstring& tagstr);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷��^�O�����݂�����폜����i���݂��Ȃ��ꍇ�͉������Ȃ��j
		@param[in]	tagstr	�폜����^�O
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void  RemoveTag(const wstring& tagstr);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����^�O�̃Z�b�g�𓾂�
		@return	�����^�O�̃Z�b�g
		*/
		//--------------------------------------------------------------------------------------
		set<int>& GetNumTagSet() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷�鐔���^�O�����݂��邩�ǂ����𓾂�
		@param[in]	numtag	���؂��鐔���^�O
		@return	���݂����true
		*/
		//--------------------------------------------------------------------------------------
		bool FindNumTag(int numtag) const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷�鐔���^�O��ǉ�����
		@param[in]	numtag	�ǉ����鐔���^�O
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void  AddNumTag(int numtag);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肷�鐔���^�O�����݂�����폜����i���݂��Ȃ��ꍇ�͉������Ȃ��j
		@param[in]	numtag	�폜���鐔���^�O
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void  RemoveNumTag(int numtag);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��������X�e�[�W�𓾂�
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	��������X�e�[�W
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<Stage> GetStage(bool ExceptionActive = true) const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��������X�e�[�W�𓾂�(�^�`�F�b�N����)
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	��������X�e�[�W
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		shared_ptr<T> GetTypeStage(bool ExceptionActive = true) const {
			auto StagePtr = GetStage(ExceptionActive);
			if (!StagePtr) {
				return nullptr;
			}
			auto TargetPtr = dynamic_pointer_cast<T>(StagePtr);
			if (!TargetPtr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�X�e�[�W������܂������A�^�L���X�g�ł��܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::GetTypeStage<T>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return TargetPtr;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��������X�e�[�W��ݒ肷��
		@param[in]	stage	��������X�e�[�W
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetStage(const shared_ptr<Stage>& stage);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���|�[�l���g�̎擾
		@tparam	T	�擾����^
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <typename T>
		shared_ptr<T> GetComponent(bool ExceptionActive = true)const {
			auto Ptr = SearchComponent(type_index(typeid(T)));
			if (Ptr) {
				//�w��̌^�̃R���|�[�l���g����������
				auto RetPtr = dynamic_pointer_cast<T>(Ptr);
				if (RetPtr) {
					return RetPtr;
				}
				else {
					throw BaseException(
						L"�R���|�[�l���g������܂������A�^�L���X�g�ł��܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::GetComponent<T>()"
					);
				}
			}
			else {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::GetComponent<T>()"
					);
				}
			}
			return nullptr;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	Rigidbody�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Rigidbody> GetComponent<Rigidbody>(bool ExceptionActive)const {
			auto Ptr = GetRigidbody();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"Rigidbody",
						L"GameObject::GetComponent<Rigidbody>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Collision�R���|�[�l���g�̎擾�B�e�N���X�Ȃ̂�Get�̂ݗp��
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Collision> GetComponent<Collision>(bool ExceptionActive)const {
			auto Ptr = GetCollision();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"Collision",
						L"GameObject::GetComponent<Collision>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionSphere�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionSphere> GetComponent<CollisionSphere>(bool ExceptionActive)const {
			auto Ptr = GetCollisionSphere();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"CollisionSphere",
						L"GameObject::GetComponent<CollisionSphere>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionCapsule�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionCapsule> GetComponent<CollisionCapsule>(bool ExceptionActive)const {
			auto Ptr = GetCollisionCapsule();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"CollisionCapsule",
						L"GameObject::GetComponent<CollisionCapsule>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionObb�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionObb> GetComponent<CollisionObb>(bool ExceptionActive)const {
			auto Ptr = GetCollisionObb();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"CollisionObb",
						L"GameObject::GetComponent<CollisionObb>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionTriangles�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionTriangles> GetComponent<CollisionTriangles>(bool ExceptionActive)const {
			auto Ptr = GetCollisionTriangles();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"CollisionTriangles",
						L"GameObject::GetComponent<CollisionTriangles>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionRect�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionRect> GetComponent<CollisionRect>(bool ExceptionActive)const {
			auto Ptr = GetCollisionRect();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"CollisionRect",
						L"GameObject::GetComponent<CollisionRect>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Transform�R���|�[�l���g�̎擾
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Transform> GetComponent<Transform>(bool ExceptionActive)const {
			auto Ptr = GetTransform();
			if (!Ptr) {
				if (ExceptionActive) {
					throw BaseException(
						L"�R���|�[�l���g��������܂���",
						L"Transform",
						L"GameObject::GetComponent<Transform>()"
					);
				}
				else {
					return nullptr;
				}
			}
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	DynamicCast�𗘗p�����R���|�[�l���g�̎擾�B�R���|�[�l���g�̔h���N���X�g�p���Ɏg��
		@tparam	T	�擾����^�iT�Ɍ^�ϊ��ł�����́j
		@param[in]	ExceptionActive	�Ώۂ�null�������ꍇ�ɗ�O�������邩�ǂ���
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <typename T>
		shared_ptr<T> GetDynamicComponent(bool ExceptionActive = true)const {
			auto Ptr = SearchDynamicComponent<T>();
			if (Ptr) {
				return Ptr;
			}
			else {
				if (ExceptionActive) {
					throw BaseException(
						L"�^�L���X�g�ł���R���|�[�l���g��������܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::GetDynamicComponent<T>()"
					);
				}
			}
			return nullptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���|�[�l���g�̒ǉ��B�V�K�ɃR���|�[�l���g�N���X�����ꍇ�A�R���X�g���N�^�̑�1������GameObject�Ƃ��č쐬����B
		@tparam	T	�ǉ�����^
		@tparam	Ts	�ϒ��ϐ��̌^
		@param[in]	params	���̃R���|�[�l���g���\�z����̂Ɏg�p����p�����[�^�B�i��2�p�����[�^�ȍ~�j
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template<typename T, typename... Ts>
		shared_ptr<T> AddComponent(Ts&&... params) {
			auto Ptr = SearchComponent(type_index(typeid(T)));
			//�w��̌^�̃R���|�[�l���g����������
			if (Ptr) {
				auto RetPtr = dynamic_pointer_cast<T>(Ptr);
				if (RetPtr) {
					return RetPtr;
				}
				else {
					throw BaseException(
						L"���łɃR���|�[�l���g������܂������A�^�L���X�g�ł��܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::AddComponent<T>()"
					);
				}
			}
			else {
				//������Ȃ��B�V���ɍ쐬����
				shared_ptr<T> newPtr = ObjectFactory::Create<T>(GetThis<GameObject>(), params...);
				AddMakedComponent(type_index(typeid(T)), newPtr);
				return newPtr;
			}
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	Rigidbody�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Rigidbody> AddComponent<Rigidbody>() {
			auto Ptr = GetRigidbody();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto RigidbodyPtr = ObjectFactory::Create<Rigidbody>(GetThis<GameObject>());
				SetRigidbody(RigidbodyPtr);
				return RigidbodyPtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Collision�R���|�[�l���g�̒ǉ��B�Q�Ƃ͂ł��邪�A���ڍ쐬�͂ł��Ȃ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Collision> AddComponent<Collision>() {
			auto Ptr = GetCollision();
			if (Ptr) {
				return Ptr;
			}
			else {
				//�����Ă��쐬�ł��Ȃ�
				throw BaseException(
					L"���̃R���|�[�l���g�͍쐬�ł��܂���B",
					L"Collision",
					L"GameObject::AddComponent<Collision>()"
				);
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionSphere�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionSphere> AddComponent<CollisionSphere>() {
			auto Ptr = GetCollisionSphere();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto CollisionSpherePtr = ObjectFactory::Create<CollisionSphere>(GetThis<GameObject>());
				SetCollision(CollisionSpherePtr);
				return CollisionSpherePtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionCapsule�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionCapsule> AddComponent<CollisionCapsule>() {
			auto Ptr = GetCollisionCapsule();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto CollisionCapsulePtr = ObjectFactory::Create<CollisionCapsule>(GetThis<GameObject>());
				SetCollision(CollisionCapsulePtr);
				return CollisionCapsulePtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionObb�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionObb> AddComponent<CollisionObb>() {
			auto Ptr = GetCollisionObb();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto CollisionObbPtr = ObjectFactory::Create<CollisionObb>(GetThis<GameObject>());
				SetCollision(CollisionObbPtr);
				return CollisionObbPtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionTriangles�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionTriangles> AddComponent<CollisionTriangles>() {
			auto Ptr = GetCollisionTriangles();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto CollisionTrianglesPtr = ObjectFactory::Create<CollisionTriangles>(GetThis<GameObject>());
				SetCollision(CollisionTrianglesPtr);
				return CollisionTrianglesPtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CollisionRect�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<CollisionRect> AddComponent<CollisionRect>() {
			auto Ptr = GetCollisionRect();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto CollisionRectPtr = ObjectFactory::Create<CollisionRect>(GetThis<GameObject>());
				SetCollision(CollisionRectPtr);
				return CollisionRectPtr;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Transform�R���|�[�l���g�̒ǉ�
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <>
		shared_ptr<Transform> AddComponent<Transform>() {
			auto Ptr = GetTransform();
			if (Ptr) {
				return Ptr;
			}
			else {
				//������ΐV���ɐ��삷��
				auto TransformPtr = ObjectFactory::Create<Transform>(GetThis<GameObject>());
				SetTransform(TransformPtr);
				return TransformPtr;
			}
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���|�[�l���g�̍폜
		@tparam	T	�폜����^
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template <typename T>
		void RemoveComponent() {
			RemoveTgtComponent(type_index(typeid(T)));
		}

		//RemoveComponent�͓��ꉻ�͗p�ӂ��Ȃ�
		//�Œ�R���|�[�l���g�𖳌��ɂ���ꍇ��
		//UpdaetActive��false�ɂ��ׂ��ł���

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s���̎擾�B���݂��Ȃ���΍쐬����
		@tparam	T	�擾����^
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template <typename T>
		shared_ptr<T> GetBehavior() {
			auto Ptr = SearchBehavior(type_index(typeid(T)));
			if (Ptr) {
				//�w��̌^�̍s������������
				auto RetPtr = dynamic_pointer_cast<T>(Ptr);
				if (RetPtr) {
					return RetPtr;
				}
				else {
					throw BaseException(
						L"�s��������܂������A�^�L���X�g�ł��܂���",
						Util::GetWSTypeName<T>(),
						L"GameObject::GetBehavior<T>()"
					);
				}
			}
			else {
				//������ΐV���ɐ��삷��
				shared_ptr<T> newPtr = ObjectFactory::Create<T>(GetThis<GameObject>());
				AddMakedBehavior(type_index(typeid(T)), newPtr);
				return newPtr;
			}
			return nullptr;
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s���̌����B
		@tparam	T	�擾����^
		@return	���݂����true
		*/
		//--------------------------------------------------------------------------------------
		template <typename T>
		bool FindBehavior() {
			auto Ptr = SearchBehavior(type_index(typeid(T)));
			if (Ptr) {
				//�w��̌^�̍s������������
				auto RetPtr = dynamic_pointer_cast<T>(Ptr);
				if (RetPtr) {
					return true;
				}
				else {
					return false;
				}
			}
			return false;
		}



		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���|�[�l���g�̍X�V����
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void ComponentUpdate();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Փ˃I�u�W�F�N�g�̃��Z�b�g�iBeforHit�Ɉڂ����j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void CollisionReset();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̕`�揈��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void DrawShadowmap();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���|�[�l���g�̕`�揈���i���Draw�R���|�[�l���g�����j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void ComponentDraw();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O������
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnPreCreate()override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�������i�f�t�H���g�͉������Ȃ��j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�i�f�t�H���g�͉������Ȃ��j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnUpdate()override {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Փ˃��b�Z�[�W�̔��s�i�X�e�[�W���Ă΂��j�B
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void ToMessageCollision();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Փ˔��������̃C�x���g�i�f�t�H���g�͉������Ȃ��j
		@param[in]	OtherVec	�V�����Փ˂�������̔z��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCollision(vector<shared_ptr<GameObject>>& OtherVec) {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Փ˂������鑊�肪�������ꍇ�̃C�x���g�i�f�t�H���g�͉������Ȃ��j
		@param[in]	OtherVec	�Փ˂�����������̔z��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCollisionExcute(vector<shared_ptr<GameObject>>& OtherVec) {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Փ˂𔲂������肪�������ꍇ�̃C�x���g�i�f�t�H���g�͉������Ȃ��j
		@param[in]	OtherVec	�Փ˂𔲂�������̔z��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCollisionExit(vector<shared_ptr<GameObject>>& OtherVec) {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`��O�����i�f�t�H���g�͉������Ȃ��j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnPreDraw() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���̃I�u�W�F�N�g��`�悷�邽�߂̃J�����𓾂�i�f�t�H���g�̓X�e�[�W�̃r���[����擾�j
		@return	�J������shared_ptr
		*/
		//--------------------------------------------------------------------------------------
		virtual const shared_ptr<Camera>& OnGetDrawCamera()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���̃I�u�W�F�N�g��`�悷�邽�߃��C�g�𓾂�i�f�t�H���g�̓X�e�[�W�̃��C�g�x�[�X����擾�j
		@return	���C�g�̎���
		*/
		//--------------------------------------------------------------------------------------
		virtual  const Light& OnGetDrawLight() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���̃I�u�W�F�N�g��2D�`�悷�邽�߂̎ˉe�s��𓾂�i�f�t�H���g�̓X�e�[�W�̃r���[����擾�j
		@param[out]	ProjMatrix	�ˉe�s��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnGet2DDrawProjMatrix(Matrix4X4& ProjMatrix) const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnDraw()override;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	//--------------------------------------------------------------------------------------
	///	�Q�[���I�u�W�F�N�g��weak_ptr���O���[�v����������
	//--------------------------------------------------------------------------------------
	class GameObjectGroup : public ObjectInterface {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		GameObjectGroup();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjectGroup();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�v���̃Q�[���I�u�W�F�N�g��weak_ptr�̔z��𓾂�
		@return	�O���[�v���̃Q�[���I�u�W�F�N�g��weak_ptr�̔z��
		*/
		//--------------------------------------------------------------------------------------
		const vector< weak_ptr<GameObject> >& GetGroupVector() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�v���̃Q�[���I�u�W�F�N�g�𓾂�
		@param[in]	index	�O���[�v���I�u�W�F�N�g�̃C���f�b�N�X
		@return	�O���[�v���̃Q�[���I�u�W�F�N�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<GameObject> at(size_t index);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�v���̃Q�[���I�u�W�F�N�g�̐��𓾂�
		@return	�O���[�v���̃Q�[���I�u�W�F�N�g�̐�
		*/
		//--------------------------------------------------------------------------------------
		size_t size() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�v�ɃQ�[���I�u�W�F�N�g��ǉ�����
		@param[in]	Obj	�ǉ�����Q�[���I�u�W�F�N�g
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void IntoGroup(const shared_ptr<GameObject>& Obj);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�v���N���A����
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void AllClear();

		//������
		virtual void OnCreate()override {}

	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	//--------------------------------------------------------------------------------------
	///	�p�[�e�B�N�����́A1�̃X�v���C�g������킷�\����
	//--------------------------------------------------------------------------------------
	struct ParticleSprite {
		bool m_Active;				//�A�N�e�B�u���ǂ���
		Color4 m_Color;				//�F�i����������ꍇ��a��0�ɂ���j
		Vector2 m_LocalScale;		//���[�J���X�P�[�����O�iZ��1.0�Œ�j		
		Quaternion m_LocalQt;		//���[�J����]�B�蓮�̂Ƃ��̂ݎg�p
		Vector3 m_LocalPos;			//���[�J���ʒu
		Vector2 m_UVLeftTop;		//UV�̍���
		Vector2 m_UVRightBottom;	//UV�̉E��
		Vector3 m_Velocity;			//���x(�K�v�ɉ����Ďg�p)
		ParticleSprite() :
			m_Active(true),
			m_Color(1.0f, 1.0f, 1.0f, 1.0f),
			m_LocalScale(1.0f, 1.0f),
			m_LocalQt(),
			m_LocalPos(0, 0, 0),
			m_UVLeftTop(0, 0),
			m_UVRightBottom(1.0f, 1.0f),
			m_Velocity(0, 0, 0)
		{}
		void Reflesh() {
			m_Active = true;
			m_Color = Color4(1.0f, 1.0f, 1.0f, 1.0f);
			m_LocalScale = Vector2(1.0f, 1.0f);
			m_LocalQt.Identity();
			m_LocalPos = Vector3(0, 0, 0);
			m_UVLeftTop = Vector2(0, 0);
			m_UVRightBottom = Vector2(1.0f, 1.0f);
			m_Velocity = Vector3(0, 0, 0);
		}
	};
	class ParticleManager;
	//--------------------------------------------------------------------------------------
	//	class Particle: public Object;
	//	�p�r: �p�[�e�B�N��
	//	*1�̃G�~�b�^�[�������A������ParticleSprite��ێ�����
	//--------------------------------------------------------------------------------------
	class Particle : public ObjectInterface {
	public:
		enum DrawOption {
			Billboard,	//�r���{�[�h
			Faceing,	//�t�F�C�V���O
			FaceingY,	//�t�F�C�V���O(Y���̂�)
			Normal		//�ʏ�(�蓮)
		};
		explicit Particle(size_t Count, DrawOption Option = DrawOption::Billboard);
		virtual ~Particle();
		//�A�N�Z�T
		DrawOption GetDrawOption()const;
		void SetDrawOption(DrawOption Option);

		bool IsActive() const;
		bool IsAllActive() const;
		void SetAllActive();
		void SetAllNoActive();

		void Reflesh(size_t Count, Particle::DrawOption Option = Particle::DrawOption::Billboard);

		vector<ParticleSprite>& GetParticleSpriteVec() const;

		const Vector3& GetEmitterPos() const;
		void SetEmitterPos(const Vector3& Pos);

		float GetTotalTime() const;
		void SetTotalTime(float f);
		void AddTotalTime(float f);

		float GetMaxTime() const;
		void SetMaxTime(float f);


		shared_ptr<TextureResource> GetTextureResource(bool ExceptionActive = true) const;
		void SetTextureResource(const wstring& ResKey);
		void SetTextureResource(const shared_ptr<TextureResource>& TextureResourcePtr);

		//����
		//--------------------------------------------------------------------------------------
		/*!
		@brief ���������s���i���z�֐��j<br />
		��this�|�C���^���K�v�ȃI�u�W�F�N�g�͂��̊֐��𑽏d��`���āA�擾�ł���
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override{}
		virtual void Draw(const shared_ptr<ParticleManager>& Manager);

	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};


	//--------------------------------------------------------------------------------------
	//	class MultiParticle : public GameObject;
	//	�p�r: �}���`�G�t�F�N�g 
	//--------------------------------------------------------------------------------------
	class MultiParticle : public GameObject {
	public:
		explicit MultiParticle(const shared_ptr<Stage>& StagePtr);
		virtual ~MultiParticle();
		//�A�N�Z�T
		vector< shared_ptr<Particle> >& GetParticleVec() const;

		bool GetAddType() const;
		bool IsAddType() const;
		void SetAddType(bool b);

		//����
		virtual void OnPreCreate() override;
		shared_ptr<Particle> InsertParticle(size_t Count, Particle::DrawOption Option = Particle::DrawOption::Billboard);
		virtual void OnUpdate()override;
		virtual void OnDraw()override;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};



	//--------------------------------------------------------------------------------------
	//	class ParticleManager : public GameObject;
	//	�p�r: �p�[�e�B�N���}�l�[�W��
	//--------------------------------------------------------------------------------------
	class ParticleManager : public GameObject {
	public:
		//�\�z�Ə���
		explicit ParticleManager(const shared_ptr<Stage>& StagePtr,bool AddType);
		virtual ~ParticleManager();
		//������
		virtual void OnCreate() override;

		//�A�N�Z�T
		bool GetZBufferUse() const;
		bool IsZBufferUse() const;
		void SetZBufferUse(bool b);

		bool GetSamplerWrap() const;
		bool IsSamplerWrap() const;
		void SetSamplerWrap(bool b);

		//����
		void AddParticle(const ParticleSprite& rParticleSprite, Particle::DrawOption Option,
			const Vector3& EmitterPos, const shared_ptr<TextureResource>& TextureRes);

		virtual void OnUpdate() override {}
		virtual void OnDraw()override;
	private:
		//Impl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	//--------------------------------------------------------------------------------------
	//	�Փ˔���Ǘ���
	//--------------------------------------------------------------------------------------
	class CollisionManager : public GameObject {
		void CollisionSub(size_t SrcIndex);
	public:
		//�\�z�Ə���
		explicit CollisionManager(const shared_ptr<Stage>& StagePtr);
		virtual ~CollisionManager();
		//������
		virtual void OnCreate() override;
		virtual void OnUpdate() override;
	private:
		//Impl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	struct CellIndex;
	//--------------------------------------------------------------------------------------
	//	�X�e�[�W�̃Z���}�b�v�Ŏg�p����Z���\����
	//--------------------------------------------------------------------------------------
	struct CellPiece{
		CellIndex m_Index;
		CellIndex m_ParentIndex;
		int m_Cost;
		AABB m_PieceRange;
		CellPiece(){}
	};

	//--------------------------------------------------------------------------------------
	//	�X�e�[�W�̃Z���}�b�v�i�h���N���X����邩�C���X�^���X���쐬����j
	//--------------------------------------------------------------------------------------
	class StageCellMap : public GameObject {
	public:
		StageCellMap(const shared_ptr<Stage>& StagePtr,const Vector3& MiniPos,
			float PieceSize, UINT PieceCountX, UINT PieceCountZ,int DefaultCost = 1);
		virtual ~StageCellMap();
		bool IsCellStringActive();
		void SetCellStringActive(bool b);
		bool FindCell(const Vector3& Pos,CellIndex& ret);
		void FindNearCell(const Vector3& Pos, CellIndex& ret);
		bool FindAABB(const CellIndex& Index,AABB& ret);
		void FindNearAABB(const Vector3& Pos, AABB& ret);
		void GetMapAABB(AABB& ret) const;
		vector<vector<CellPiece>>& GetCellVec() const;
		void RefleshCellMap(const Vector3& MiniPos,
			float PieceSize, UINT PieceCountX, UINT PieceCountZ, int DefaultCost = 1);
		//������
		virtual void OnCreate() override;
		virtual void OnUpdate() override;
		virtual void OnDraw() override;
	private:
		//Impl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};






	//--------------------------------------------------------------------------------------
	//	�X�e�[�W�N���X
	//--------------------------------------------------------------------------------------
	class Stage :public ObjectInterface, public ShapeInterface {
		//�v���C�x�[�g�T�u�֐�
		void PushBackGameObject(const shared_ptr<GameObject>& Ptr);
		void RemoveBackGameObject(const shared_ptr<GameObject>& Ptr);
		shared_ptr<GameObject> GetSharedGameObjectEx(const wstring& Key, bool ExceptionActive) const;
		void SetParentStage(const shared_ptr<Stage>& ParentStage);
		void AddChileStageBase(const shared_ptr<Stage>& ChildStage);
	protected:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		Stage();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~Stage();
	public:
		//�A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ����𓾂�
		@return	�X�V�������L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool IsUpdateActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ����𓾂�
		@return	�X�V�������L���Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		bool GetUpdateActive() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�������L�����ǂ�����ݒ肷��
		@param[in]	b	�X�V�������L���Ȃ�Ȃ�true
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetUpdateActive(bool b);

		shared_ptr<ParticleManager> GetParticleManager(bool AddType) const;

		vector< shared_ptr<GameObject> >& GetGameObjectVec();


		vector< shared_ptr<Stage> >& GetChileStageVec();
		template<typename T>
		shared_ptr<Stage> AddChileStage() {
			auto Ptr = ObjectFactory::Create<T>();
			auto StagePtr = dynamic_pointer_cast<Stage>(Ptr);
			if (!StagePtr) {
				throw BaseException(
					L"�ȉ���Stage�Ɍ^�L���X�g�ł��܂���B",
					Util::GetWSTypeName<T>(),
					L"Stage::AddChileStage<T>()"
				);
			}
			AddChileStageBase(Ptr);
			return Ptr;
		}

		shared_ptr<Stage> GetParentStage() const;


		//GameObject�̐V�K�ǉ�
		template<typename T, typename... Ts>
		shared_ptr<T> AddGameObject(Ts&&... params) {
			try {
				auto Ptr = ObjectFactory::Create<T>(GetThis<Stage>(), params...);
				PushBackGameObject(Ptr);
				return Ptr;
			}
			catch (...) {
				throw;
			}
		}

		template<typename T, typename... Ts>
		shared_ptr<T> AddGameObjectWithParam(Ts&&... params) {
			try {
				auto Ptr = ObjectFactory::CreateGameObjectWithParam<T>(GetThis<Stage>(), params...);
				PushBackGameObject(Ptr);
				return Ptr;
			}
			catch (...) {
				throw;
			}
		}

		template<typename T>
		bool FindGameObject(const shared_ptr<GameObject>& Obj) {
			auto shptr = dynamic_pointer_cast<T>(Obj);
			if (shptr) {
				for (auto ptr : GetGameObjectVec()) {
					if (Obj == ptr) {
						return true;
					}
				}
			}
			return false;
		}


		template<typename T>
		void RemoveGameObject(const shared_ptr<GameObject>& Obj) {
			if (FindGameObject<T>(Obj)) {
				RemoveBackGameObject(Obj);
			}
		}


		//�ǉ��҂��ɂȂ��Ă�I�u�W�F�N�g��ǉ�����
		void SetWaitToObjectVec();


		template<typename T>
		shared_ptr<T> GetSharedGameObject(const wstring& Key, bool ExceptionActive = true)const {
			shared_ptr<T> Ptr = dynamic_pointer_cast<T>(GetSharedGameObjectEx(Key, ExceptionActive));
			if (Ptr) {
				return Ptr;
			}
			else {
				//�L���X�g�ł��Ȃ�
				if (ExceptionActive) {
					//��O����
					wstring keyerr = Key;
					wstring str = L"�I�u�W�F�N�g��";
					str += Util::GetWSTypeName<T>();
					str += L"�^�ɃL���X�g�ł��܂���";
					throw BaseException(
						str,
						keyerr,
						L"Stage::GetSharedGameObject()"
					);
				}
			}
			return nullptr;
		}
		shared_ptr<GameObject> GetSharedObject(const wstring& Key, bool ExceptionActive = true)const;
		void SetSharedGameObject(const wstring& Key, const shared_ptr<GameObject>& Ptr);

		shared_ptr<GameObjectGroup> CreateSharedObjectGroup(const wstring& Key);
		shared_ptr<GameObjectGroup> GetSharedObjectGroup(const wstring& Key, bool ExceptionActive = true)const;
		template<typename T>
		shared_ptr<T> GetSharedObjectGroup(const wstring& Key, bool ExceptionActive = true)const {
			auto RetPtr = dynamic_pointer_cast<T>(GetSharedObjectGroup(Key, ExceptionActive));
			if (RetPtr) {
				return RetPtr;
			}
			else {
				if (ExceptionActive) {
					//��O����
					wstring keyerr = Key;
					throw BaseException(
						L"�w��̂��[�̃O���[�v��T�^�ɕϊ��ł��܂���",
						keyerr,
						L"Stage::GetSharedObjectGroup<T>()"
					);
				}
			}
			return nullptr;
		}


		void SetSharedObjectGroup(const wstring& Key, const shared_ptr<GameObjectGroup>& NewPtr);



		void SetView(const shared_ptr<ViewBase>& v);
		const shared_ptr<ViewBase>& GetView(bool ExceptionActive = true)const;

		void SetLight(const shared_ptr<LightBase>& L);
		const shared_ptr<LightBase>& GetLight()const;


		template<typename T, typename... Ts>
		shared_ptr<T> CreateView(Ts&&... params) {
			//�V���ɍ쐬����
			shared_ptr<T> newPtr = ObjectFactory::Create<T>(GetThis<Stage>(), params...);
			SetView(newPtr);
			return newPtr;
		}

		template<typename T, typename... Ts>
		shared_ptr<T> CreateLight(Ts&&... params) {
			//�V���ɍ쐬����
			shared_ptr<T> newPtr = ObjectFactory::Create<T>(GetThis<Stage>(), params...);
			SetLight(newPtr);
			return newPtr;
		}

		//�X�e�[�W���̍X�V�i�V�[�������΂��j
		virtual void UpdateStage();
		//�Փ˔���̍X�V�i�X�e�[�W����Ăԁj
		virtual void UpdateCollision();
		//�Փ˃��b�Z�[�W�̔��s
		virtual void UpdateMessageCollision();

		//�V���h�E�}�b�v���g�����ǂ���
		bool IsShadowmapDraw() const;
		void SetShadowmapDraw(bool b);


		//�X�e�[�W���̃V���h�E�}�b�v�`��i�X�e�[�W�����΂��j
		virtual void DrawShadowmapStage();
		//�X�e�[�W���̕`��i�X�e�[�W�����΂��j
		virtual void DrawStage();
		//�X�e�[�W���̂��ׂĂ̕`��i�V�[�������΂��j
		virtual void RenderStage();


		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O������
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnPreCreate()override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�V�i�f�t�H���g�͉������Ȃ��j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnUpdate()override {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`��i�f�t�H���g�͉������Ȃ��j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnDraw()override {}
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};



	//--------------------------------------------------------------------------------------
	///	�V�[���e�N���X
	//--------------------------------------------------------------------------------------
	class SceneBase :public SceneInterface {
		void SetActiveStage(const shared_ptr<Stage>& stage);
		void ConvertVertex(const vector<VertexPositionNormalTexture>& vertices,
			vector<VertexPositionColor>& new_pc_vertices,
			vector<VertexPositionTexture>& new_pt_vertices,
			vector<VertexPositionNormalTangentTexture>& new_pntnt_vertices
			);
	protected:
		SceneBase();
		virtual ~SceneBase();
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���݂̃X�e�[�W�𓾂�
		@return	���݂̃X�e�[�W�i���s����O�j
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<Stage> GetActiveStage() const;

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ʂ��N���A����F�𓾂�
		@return	��ʂ��N���A����F
		*/
		//--------------------------------------------------------------------------------------
		Color4 GetClearColor() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ʂ��N���A����F��ݒ肷��
		@param[in]	params	���̃X�e�[�W���\�z����̂Ɏg�p����p�����[�^�B
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetClearColor(const Color4& col);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w��̌^�̌��݂̃X�e�[�W�𓾂�
		@tparam	T	�擾����^
		@return	�w��̌^�̃X�e�[�W�i���s����O�j
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		shared_ptr<T> GetActiveTypeStage() const {
			auto TypeStagePtr = dynamic_pointer_cast<T>(GetActiveStage());
			if (!TypeStagePtr) {
				throw BaseException(
					L"�ȉ��Ɍ^�L���X�g�ł��܂���B",
					Util::GetWSTypeName<T>(),
					L"SceneBase::GetActiveTypeStage<T>()"
				);
			}
			return TypeStagePtr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�A�N�e�B�u�ȃX�e�[�W��ݒ肵�ď���������
		@tparam	T	�擾����^�iStage�Ɍ^�ϊ��ł�����́j
		@tparam	Ts	�ϒ��ϐ��̌^
		@param[in]	params	���̃X�e�[�W���\�z����̂Ɏg�p����p�����[�^�B
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template<typename T, typename... Ts>
		shared_ptr<T> ResetActiveStage(Ts&&... params) {
			auto Ptr = ObjectFactory::Create<T>(params...);
			auto StagePtr = dynamic_pointer_cast<Stage>(Ptr);
			if (!StagePtr) {
				throw BaseException(
					L"�ȉ���Stage�Ɍ^�L���X�g�ł��܂���B",
					Util::GetWSTypeName<T>(),
					L"SceneBase::ResetActiveStage<T>()"
				);
			}
			SetActiveStage(StagePtr);
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�A�N�e�B�u�ȃX�e�[�W��ݒ肵�ď���������
		@tparam	T	�擾����^�iStage�Ɍ^�ϊ��ł�����́j
		@tparam	Ts	�ϒ��ϐ��̌^
		@param[in]	params	���̃X�e�[�W���\�z����̂Ɏg�p����p�����[�^�B
		@return	�R���|�[�l���g
		*/
		//--------------------------------------------------------------------------------------
		template<typename T, typename... Ts>
		shared_ptr<T> ResetActiveStageWithParam(Ts&&... params) {
			auto Ptr = ObjectFactory::CreateWithParam<T>(params...);
			auto StagePtr = dynamic_pointer_cast<Stage>(Ptr);
			if (!StagePtr) {
				throw BaseException(
					L"�ȉ���Stage�Ɍ^�L���X�g�ł��܂���B",
					Util::GetWSTypeName<T>(),
					L"SceneBase::ResetActiveStageWithParam<T>()"
				);
			}
			SetActiveStage(StagePtr);
			return Ptr;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V�[����ω�������
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnUpdate()override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V�[����`�悷��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnDraw()override;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�N���G�[�^�[CSV(�e)
	//--------------------------------------------------------------------------------------
	class GameObjectCreatorBaseCSV {
	protected:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		explicit GameObjectCreatorBaseCSV() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjectCreatorBaseCSV() {}
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Q�[���I�u�W�F�N�g���쐬����i�������z�֐��j
		@param[in]	StagePtr	�X�e�[�W
		@param[in]	Line	1�s����CSV������
		@return	�Q�[���I�u�W�F�N�g�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		virtual shared_ptr<GameObject> Create(const shared_ptr<Stage>& StagePtr, const wstring& Line) = 0;
	};
	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�N���G�[�^�[CSV
	//--------------------------------------------------------------------------------------
	template<typename T>
	class GameObjectCreatorCSV : public GameObjectCreatorBaseCSV {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		explicit GameObjectCreatorCSV() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjectCreatorCSV() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Q�[���I�u�W�F�N�g���쐬����i���z�֐��j
		@param[in]	StagePtr	�X�e�[�W
		@param[in]	Line	1�s����CSV������
		@return	�Q�[���I�u�W�F�N�g�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<GameObject> Create(const shared_ptr<Stage>& StagePtr, const wstring& Line)override {
			return StagePtr->AddGameObject<T>(Line);
		}
	};

	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�r���_�[CSV
	//--------------------------------------------------------------------------------------
	class GameObjecttCSVBuilder {
		map<wstring, shared_ptr<GameObjectCreatorBaseCSV>>& GetCreatorMap() const;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		GameObjecttCSVBuilder();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjecttCSVBuilder();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N���G�[�^�[��o�^����
		@tparam	T	�o�^����^�i�Q�[���I�u�W�F�N�g�̔h���j
		@param[in]	ClsName	�^�̎��ʖ��i�ʏ�͌^���𕶎���ɂ������́j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		void Register(const wstring& ClsName) {
			GetCreatorMap()[ClsName] = shared_ptr<GameObjectCreatorCSV<T>>(new GameObjectCreatorCSV<T>());
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�^�̎��ʖ����g���ăQ�[���I�u�W�F�N�g���\�z����
		@param[in]	ClsName	�^�̎��ʖ��i�ʏ�͌^���𕶎���ɂ������́j
		@param[in]	StagePtr	��������X�e�[�W
		@param[in]	Line	1�s����CSV������
		@return	�쐬�����Q�[���I�u�W�F�N�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<GameObject> CreateFromCSV(const wstring& ClsName, const shared_ptr<Stage>& StagePtr, const wstring& Line);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	CSV����Q�[���I�u�W�F�N�g���\�z����
		@param[in]	StagePtr	��������X�e�[�W
		@param[in]	CSVFileName	CSV�t�@�C����
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void Build(const shared_ptr<Stage>& StagePtr, const wstring& CSVFileName);
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};


	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�N���G�[�^�[XML(�e)
	//--------------------------------------------------------------------------------------
	class GameObjectCreatorBaseXML {
	protected:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		explicit GameObjectCreatorBaseXML() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjectCreatorBaseXML() {}
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Q�[���I�u�W�F�N�g���쐬����i�������z�֐��j
		@param[in]	StagePtr	�X�e�[�W
		@param[in]	pNode	XML�m�[�h
		@return	�Q�[���I�u�W�F�N�g�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		virtual shared_ptr<GameObject> Create(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode) = 0;
	};
	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�N���G�[�^�[XML
	//--------------------------------------------------------------------------------------
	template<typename T>
	class GameObjectCreatorXML : public GameObjectCreatorBaseXML {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		explicit GameObjectCreatorXML() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjectCreatorXML() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Q�[���I�u�W�F�N�g���쐬����i���z�֐��j
		@param[in]	StagePtr	�X�e�[�W
		@param[in]	pNode	XML�m�[�h
		@return	�Q�[���I�u�W�F�N�g�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<GameObject> Create(const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode)override {
			return StagePtr->AddGameObject<T>(pNode);
		}
	};

	//--------------------------------------------------------------------------------------
	//	�Q�[���I�u�W�F�N�g�r���_�[XML
	//--------------------------------------------------------------------------------------
	class GameObjecttXMLBuilder {
		map<wstring, shared_ptr<GameObjectCreatorBaseXML>>& GetCreatorMap() const;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		GameObjecttXMLBuilder();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~GameObjecttXMLBuilder();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N���G�[�^�[��o�^����
		@tparam	T	�o�^����^�i�Q�[���I�u�W�F�N�g�̔h���j
		@param[in]	ClsName	�^�̎��ʖ��i�ʏ�͌^���𕶎���ɂ������́j
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		void Register(const wstring& ClsName) {
			GetCreatorMap()[ClsName] = shared_ptr<GameObjectCreatorXML<T>>(new GameObjectCreatorXML<T>());
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�^�̎��ʖ����g���ăQ�[���I�u�W�F�N�g���\�z����
		@param[in]	ClsName	�^�̎��ʖ��i�ʏ�͌^���𕶎���ɂ������́j
		@param[in]	StagePtr	��������X�e�[�W
		@param[in]	pNode	XML�m�[�h
		@return	�쐬�����Q�[���I�u�W�F�N�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<GameObject> CreateFromXML(const wstring& ClsName, const shared_ptr<Stage>& StagePtr, IXMLDOMNodePtr pNode);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	XML����Q�[���I�u�W�F�N�g���\�z����
		@param[in]	StagePtr	��������X�e�[�W
		@param[in]	XMLFileName	XML�t�@�C����
		@param[in]	GameObjectsPath	�Q�[���I�u�W�F�N�g(����)�̃m�[�h�ւ̃p�X
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void Build(const shared_ptr<Stage>& StagePtr, const wstring& XMLFileName, const wstring& GameObjectsPath);
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};







}
//end basecross
