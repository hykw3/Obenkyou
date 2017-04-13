/*!
@file SharedResources.cpp
@brief ���L�̃��\�[�X�i�r���[�A�J�����A���C�g�Ȃǁj����
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/
#include "stdafx.h"

namespace basecross {
	//--------------------------------------------------------------------------------------
	//	struct Camera::Impl;
	//	�p�r: Impl�N���X
	//--------------------------------------------------------------------------------------
	struct Camera::Impl {
		Vector3 m_Eye;	//�J�����ʒu
		Vector3 m_At;	//���ړ_
		Vector3 m_Up;   //�J�����̌X���i�A�b�v�j
		bool m_Pers;	//���ߖ@���g�����ǂ���
		//�J��������̃I�u�W�F�N�g
		weak_ptr<GameObject> m_CameraObject;

		float m_FovY;   //�ˉe�p�x
		float m_Aspect;	//�A�X�y�N�g��

		float m_Width;	//���ߖ@���g��Ȃ��ꍇ�i���ˉe�j�̕�
		float m_Height;	//���ߖ@���g��Ȃ��ꍇ�i���ˉe�j�̍���
		float m_Near;	//��O�̍ŏ�����
		float m_Far;	//���̍ő勗��

		Matrix4X4 m_ViewMatrix;
		Matrix4X4 m_ProjMatrix;
		Impl() :
			m_Eye(0, 0.0f, -20.0f),	//�f�t�H���g�͌��
			m_At(0, 0, 0),
			m_Up(0, 1.0f, 0),
			m_Pers(true),
			m_FovY(XM_PIDIV4),
			m_Aspect(0),
			m_Width(0),
			m_Height(0),
			m_Near(0.5f),
			m_Far(1000.0f),
			m_ViewMatrix(),
			m_ProjMatrix()
		{
			try {
				m_Width = static_cast<float>(App::GetApp()->GetGameWidth());;
				m_Height = static_cast<float>(App::GetApp()->GetGameHeight());
				m_Aspect = m_Width / m_Height;
			}
			catch (...) {
				throw;
			}
		}
		~Impl() {}





	};

	//--------------------------------------------------------------------------------------
	//	class Camera : public Object, public ShapeInterface ;
	//	�p�r: �J�����i�R���|�[�l���g�ł͂Ȃ��j
	//--------------------------------------------------------------------------------------
	Camera::Camera()
		:ObjectInterface(),
		pImpl(new Impl())
	{

	}
	Camera::~Camera() {}

	//�A�N�Z�T
	const Vector3& Camera::GetEye() const { return pImpl->m_Eye; }
	void Camera::SetEye(const Vector3& Eye) { 
		pImpl->m_Eye = Eye;
		CalculateMatrix();
	}
	void Camera::SetEye(float x, float y, float z) { 
		pImpl->m_Eye = Vector3(x, y, z); 
		CalculateMatrix();
	}

	const Vector3& Camera::GetAt() const { return pImpl->m_At; }
	void Camera::SetAt(const Vector3& At) { 
		pImpl->m_At = At; 
		CalculateMatrix();
	}
	void Camera::SetAt(float x, float y, float z) { 
		pImpl->m_At = Vector3(x, y, z); 
		CalculateMatrix();
	}

	const Vector3& Camera::GetUp() const { return pImpl->m_Up;}
	void Camera::SetUp(const Vector3& Up) { 
		pImpl->m_Up = Up; 
		CalculateMatrix();
	}
	void Camera::SetUp(float x, float y, float z) { 
		pImpl->m_Up = Vector3(x, y, z); 
		CalculateMatrix();
	}

	bool Camera::IsPers()const { return pImpl->m_Pers; }
	bool Camera::GetPers()const { return pImpl->m_Pers; }
	void Camera::SetPers(bool b) { 
		pImpl->m_Pers = b; 
		CalculateMatrix();
	}

	float Camera::GetFovY() const { return pImpl->m_FovY; }
	void Camera::SetFovY(float f) { 
		pImpl->m_FovY = f; 
		CalculateMatrix();
	}

	float Camera::GetAspect() const { return pImpl->m_Aspect; }
	void Camera::SetAspect(float f) { 
		pImpl->m_Aspect = f; 
		CalculateMatrix();
	}

	float Camera::GetWidth() const { return pImpl->m_Width; }
	void Camera::SetWidth(float f) { 
		pImpl->m_Width = f; 
		CalculateMatrix();
	}

	float Camera::GetHeight() const { return pImpl->m_Height; }
	void Camera::SetHeight(float f) { 
		pImpl->m_Height = f; 
		CalculateMatrix();
	}

	float Camera::GetNear() const { return pImpl->m_Near; }
	void Camera::SetNear(float f) { 
		pImpl->m_Near = f; 
		CalculateMatrix();
	}

	float Camera::GetFar() const { return pImpl->m_Far; }
	void Camera::SetFar(float f) { 
		pImpl->m_Far = f; 
		CalculateMatrix();
	}

	shared_ptr<GameObject> Camera::GetCameraObject() const {
		if (auto sh = pImpl->m_CameraObject.lock()) {
			return sh;
		}
		else {
			return nullptr;
		}
	}
	void Camera::SetCameraObject(const shared_ptr<GameObject>& Obj) {
		if (!Obj) {
			pImpl->m_CameraObject.reset();
		}
		else {
			pImpl->m_CameraObject = Obj;
		}
		CalculateMatrix();
	}
	void Camera::ClearCameraObject() {
		SetCameraObject(nullptr);
	}

	void Camera::SetViewPort(const Viewport& v) {
		pImpl->m_Width = v.Width;
		pImpl->m_Height =v.Height;
		pImpl->m_Aspect = pImpl->m_Width / pImpl->m_Height;
		CalculateMatrix();
	}

	void Camera::CalculateMatrix() {
		if (auto ShPtr = pImpl->m_CameraObject.lock()) {
			auto TransPtr = ShPtr->GetComponent<Transform>();
			if (TransPtr) {
				pImpl->m_Eye = TransPtr->GetWorldPosition();
				pImpl->m_ViewMatrix.LookAtLH(pImpl->m_Eye, pImpl->m_At, pImpl->m_Up);
				if (pImpl->m_Pers) {
					pImpl->m_ProjMatrix.PerspectiveFovLH(pImpl->m_FovY, pImpl->m_Aspect, pImpl->m_Near, pImpl->m_Far);
				}
				else {
					pImpl->m_ProjMatrix.OrthographicLH(pImpl->m_Width, pImpl->m_Height, pImpl->m_Near, pImpl->m_Far);
				}
			}
		}
		else {
			if (pImpl->m_Pers) {
				pImpl->m_ViewMatrix.LookAtLH(pImpl->m_Eye, pImpl->m_At, pImpl->m_Up);
				pImpl->m_ProjMatrix.PerspectiveFovLH(pImpl->m_FovY, pImpl->m_Aspect, pImpl->m_Near, pImpl->m_Far);
			}
			else {
				pImpl->m_ViewMatrix.Identity();
				pImpl->m_ProjMatrix.OrthographicLH(pImpl->m_Width, pImpl->m_Height, pImpl->m_Near, pImpl->m_Far);
			}
		}
	}

	const Matrix4X4& Camera::GetViewMatrix() const { return pImpl->m_ViewMatrix; }
	const Matrix4X4& Camera::GetProjMatrix() const { return pImpl->m_ProjMatrix; }

	void Camera::OnCreate() {
		CalculateMatrix();
	}

	void Camera::OnUpdate() {
		CalculateMatrix();
	}


	//--------------------------------------------------------------------------------------
	//	struct LookAtCamera::Impl;
	//	�p�r: Impl�N���X
	//--------------------------------------------------------------------------------------
	struct LookAtCamera::Impl {
		weak_ptr<GameObject> m_TargetObject;	//�ڕW�ƂȂ�I�u�W�F�N�g
		float m_ToTargetLerp;	//�ڕW��ǂ�������ۂ̕�Ԓl
		Vector3 m_TargetToAt;	//�ڕW���王�_�𒲐�����ʒu�x�N�g��


		float m_RadY;
		float m_RadXZ;
		//�J�����̏㉺�X�s�[�h
		float m_CameraUpDownSpeed;
		//�J�����������鉺���p�x
		float m_CameraUnderRot;
		//�r�̒����̐ݒ�
		float m_ArmLen;
		float m_MaxArm;
		float m_MinArm;
		//��]�X�s�[�h
		float m_RotSpeed;
		//�Y�[���X�s�[�h
		float m_ZoomSpeed;

		Impl() :
			m_ToTargetLerp(1.0f),
			m_TargetToAt(0,0,0),
			m_RadY(0.5f),
			m_RadXZ(0),
			m_CameraUpDownSpeed(0.02f),
			m_CameraUnderRot(0.1f),
			m_ArmLen(5.0f),
			m_MaxArm(20.0f),
			m_MinArm(2.0f),
			m_RotSpeed(1.0f),
			m_ZoomSpeed(0.1f)
		{}
		~Impl() {}
	};



	//--------------------------------------------------------------------------------------
	//	class LookAtCamera : public Camera ;
	//	�p�r: LookAt�J�����i�R���|�[�l���g�ł͂Ȃ��j
	//--------------------------------------------------------------------------------------
	//�\�z�Ɣj��
	LookAtCamera::LookAtCamera() :
		Camera(),
		pImpl(new Impl())
	{}

	LookAtCamera::LookAtCamera(float ArmLen):
		Camera(),
		pImpl(new Impl())
	{
		pImpl->m_ArmLen = ArmLen;
	}

	LookAtCamera::~LookAtCamera() {}
	//�A�N�Z�T
	shared_ptr<GameObject> LookAtCamera::GetTargetObject() const {
		if (!pImpl->m_TargetObject.expired()) {
			return pImpl->m_TargetObject.lock();
		}
		return nullptr;
	}

	void LookAtCamera::SetTargetObject(const shared_ptr<GameObject>& Obj) {
		pImpl->m_TargetObject = Obj;
	}

	float LookAtCamera::GetToTargetLerp() const {
		return pImpl->m_ToTargetLerp;
	}
	void LookAtCamera::SetToTargetLerp(float f) {
		pImpl->m_ToTargetLerp = f;
	}

	float LookAtCamera::GetArmLengh() const {
		return pImpl->m_ArmLen;
	}

	void LookAtCamera::UpdateArmLengh() {
		auto Vec = GetEye() - GetAt();
		pImpl->m_ArmLen = Vec.Length();
		if (pImpl->m_ArmLen >= pImpl->m_MaxArm) {
			//m_MaxArm�ȏ㗣��Ȃ��悤�ɂ���
			pImpl->m_ArmLen = pImpl->m_MaxArm;
		}
		if (pImpl->m_ArmLen <= pImpl->m_MinArm) {
			//m_MinArm�ȉ��߂Â��Ȃ��悤�ɂ���
			pImpl->m_ArmLen = pImpl->m_MinArm;
		}
	}

	float LookAtCamera::GetMaxArm() const {
		return pImpl->m_MaxArm;

	}
	void LookAtCamera::SetMaxArm(float f) {
		pImpl->m_MaxArm = f;
	}
	float LookAtCamera::GetMinArm() const {
		return pImpl->m_MinArm;
	}
	void LookAtCamera::SetMinArm(float f) {
		pImpl->m_MinArm = f;
	}

	float LookAtCamera::GetRotSpeed() const {
		return pImpl->m_RotSpeed;

	}
	void LookAtCamera::SetRotSpeed(float f) {
		pImpl->m_RotSpeed = abs(f);
	}

	Vector3 LookAtCamera::GetTargetToAt() const {
		return pImpl->m_TargetToAt;

	}
	void LookAtCamera::SetTargetToAt(const Vector3& v) {
		pImpl->m_TargetToAt = v;
	}

	void LookAtCamera::SetAt(const Vector3& At) {
		Camera::SetAt(At);
		Vector3 ArmVec = GetEye() - GetAt();
		ArmVec.Normalize();
		ArmVec *= pImpl->m_ArmLen;
		Vector3 NewEye = GetAt() + ArmVec;
		SetEye(NewEye);
	}
	void LookAtCamera::SetAt(float x, float y, float z) {
		Camera::SetAt(x,y,z);
		Vector3 ArmVec = GetEye() - GetAt();
		ArmVec.Normalize();
		ArmVec *= pImpl->m_ArmLen;
		Vector3 NewEye = GetAt() + ArmVec;
		SetEye(NewEye);

	}


	void LookAtCamera::OnUpdate() {
		auto CntlVec = App::GetApp()->GetInputDevice().GetControlerVec();
		auto KeyData = App::GetApp()->GetInputDevice().GetKeyState();
		//�O��̃^�[������̎���
		float ElapsedTime = App::GetApp()->GetElapsedTime();
		Vector3 NewEye = GetEye();
		Vector3 NewAt = GetAt();
		//�v�Z�Ɏg�����߂̘r�p�x�i�x�N�g���j
		Vector3 ArmVec = NewEye - NewAt;
		//���K�����Ă���
		ArmVec.Normalize();
		if (CntlVec[0].bConnected) {
			//�㉺�p�x�̕ύX
			if (CntlVec[0].fThumbRY >= 0.1f || KeyData.m_bPushKeyTbl[VK_UP]) {
				pImpl->m_RadY += pImpl->m_CameraUpDownSpeed;
			}
			else if (CntlVec[0].fThumbRY <= -0.1f || KeyData.m_bPushKeyTbl[VK_DOWN]) {
				pImpl->m_RadY -= pImpl->m_CameraUpDownSpeed;
			}
			if (pImpl->m_RadY > XM_PI * 4 / 9.0f) {
				pImpl->m_RadY = XM_PI * 4 / 9.0f;
			}
			else if (pImpl->m_RadY <= pImpl->m_CameraUnderRot) {
				//�J���������E���ɉ��������炻��ȏ㉺����Ȃ�
				pImpl->m_RadY = pImpl->m_CameraUnderRot;
			}
			ArmVec.y = sin(pImpl->m_RadY);
			//������Y����]���쐬
			if (CntlVec[0].fThumbRX != 0 || KeyData.m_bPushKeyTbl[VK_LEFT] || KeyData.m_bPushKeyTbl[VK_RIGHT]) {
				//��]�X�s�[�h�𔽉f
				if (CntlVec[0].fThumbRX != 0) {
					pImpl->m_RadXZ += -CntlVec[0].fThumbRX * ElapsedTime * pImpl->m_RotSpeed;
				}
				else if (KeyData.m_bPushKeyTbl[VK_LEFT]) {
					pImpl->m_RadXZ += ElapsedTime * pImpl->m_RotSpeed;
				}
				else if (KeyData.m_bPushKeyTbl[VK_RIGHT]) {
					pImpl->m_RadXZ -= ElapsedTime * pImpl->m_RotSpeed;
				}
				if (abs(pImpl->m_RadXZ) >= XM_2PI) {
					//1�T�������0��]�ɂ���
					pImpl->m_RadXZ = 0;
				}
			}
			//�N�I�[�^�j�I����Y��]�i�܂�XZ�x�N�g���̒l�j���v�Z
			Quaternion QtXZ;
			QtXZ.RotationAxis(Vector3(0, 1.0f, 0), pImpl->m_RadXZ);
			QtXZ.Normalize();
			//�ړ���s�̍s��v�Z���邱�ƂŁAXZ�̒l���Z�o
			Matrix4X4 Mat;
			Mat.STRTransformation(
				Vector3(1.0f, 1.0f, 1.0f),
				Vector3(0.0f, 0.0f, -1.0f),
				QtXZ
			);

			Vector3 PosXZ = Mat.PosInMatrixSt();
			//XZ�̒l���킩�����̂Řr�p�x�ɑ��
			ArmVec.x = PosXZ.x;
			ArmVec.z = PosXZ.z;
			//�r�p�x�𐳋K��
			ArmVec.Normalize();

			auto TargetPtr = GetTargetObject();
			if (TargetPtr) {
				//�ڎw�������ꏊ
				Vector3 ToAt = TargetPtr->GetComponent<Transform>()->GetWorldMatrix().PosInMatrixSt();
				ToAt += pImpl->m_TargetToAt;
				NewAt = Lerp::CalculateLerp(GetAt(), ToAt, 0, 1.0f, 1.0, Lerp::Linear);
			}
			//�A�[���̕ύX
			//D�p�b�h��
			if (CntlVec[0].wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
				//�J�����ʒu������
				pImpl->m_ArmLen += pImpl->m_ZoomSpeed;
				if (pImpl->m_ArmLen >= pImpl->m_MaxArm) {
					//m_MaxArm�ȏ㗣��Ȃ��悤�ɂ���
					pImpl->m_ArmLen = pImpl->m_MaxArm;
				}
			}
			//D�p�b�h��
			if (CntlVec[0].wButtons & XINPUT_GAMEPAD_DPAD_UP) {
				//�J�����ʒu�����
				pImpl->m_ArmLen -= pImpl->m_ZoomSpeed;
				if (pImpl->m_ArmLen <= pImpl->m_MinArm) {
					//m_MinArm�ȉ��߂Â��Ȃ��悤�ɂ���
					pImpl->m_ArmLen = pImpl->m_MinArm;
				}
			}
			////�ڎw�������ꏊ�ɃA�[���̒l�Ƙr�x�N�g����Eye�𒲐�
			Vector3 ToEye = NewAt + ArmVec * pImpl->m_ArmLen;
			NewEye = Lerp::CalculateLerp(GetEye(), ToEye, 0, 1.0f, pImpl->m_ToTargetLerp, Lerp::Linear);
		}
		if (KeyData.m_bPressedKeyTbl[VK_LEFT]) {
			int a = 0;
		}



		SetAt(NewAt);
		SetEye(NewEye);
		UpdateArmLengh();
		Camera::OnUpdate();
	}




	//--------------------------------------------------------------------------------------
	//	�r���[�̃A�C�e��
	//--------------------------------------------------------------------------------------
	struct ViewItem {
		shared_ptr<Camera> m_Camera;
		Viewport m_Viewport;
		ViewItem() {
			m_Viewport.Width = static_cast<float>(App::GetApp()->GetGameWidth());
			m_Viewport.Height = static_cast<float>(App::GetApp()->GetGameHeight());
			m_Viewport.TopLeftX = 0;
			m_Viewport.TopLeftY = 0;
			m_Viewport.MinDepth = 0;
			m_Viewport.MaxDepth = 1.0f;
			m_Camera = ObjectFactory::Create<Camera>();
			m_Camera->SetViewPort(m_Viewport);
			m_Camera->CalculateMatrix();
		}
	};


	//--------------------------------------------------------------------------------------
	///	struct ViewBase::Impl;
	//--------------------------------------------------------------------------------------
	struct ViewBase::Impl {
		weak_ptr<Stage> m_Stage;
		bool m_UpdateActive;
		explicit Impl(const shared_ptr<Stage>& StagePtr) :
			m_Stage(StagePtr),
			m_UpdateActive(true)
		{}
		~Impl() {}
	};
	//--------------------------------------------------------------------------------------
	///	�r���[�i�e�j
	//--------------------------------------------------------------------------------------
	ViewBase::ViewBase(const shared_ptr<Stage>& StagePtr) :
		ObjectInterface(),
		ShapeInterface(),
		pImpl(new Impl(StagePtr))
	{
	}

	ViewBase::~ViewBase() {}

	//�A�N�Z�T
	bool ViewBase::IsUpdateActive() const { return pImpl->m_UpdateActive; }
	bool ViewBase::GetUpdateActive() const { return pImpl->m_UpdateActive; }
	void ViewBase::SetUpdateActive(bool b) { pImpl->m_UpdateActive = b; }


	//--------------------------------------------------------------------------------------
	///	struct SingleView::Impl;
	//--------------------------------------------------------------------------------------
	struct SingleView::Impl {
		ViewItem m_ViewItem;
		Impl()
		{
		}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	///	�V���O���r���[�R���|�[�l���g
	//--------------------------------------------------------------------------------------
	SingleView::SingleView(const shared_ptr<Stage>& StagePtr) :
		ViewBase(StagePtr), pImpl(new Impl())
	{}

	SingleView::~SingleView() {}

	void SingleView::OnCreate() {
	}

	void SingleView::OnUpdate() {
		//�J�����̌v�Z������
		pImpl->m_ViewItem.m_Camera->OnUpdate();
	}

	void SingleView::SetViewport(const Viewport& v) {
		pImpl->m_ViewItem.m_Viewport = v;
		pImpl->m_ViewItem.m_Camera->SetViewPort(v);
	}
	const Viewport& SingleView::GetViewport() const {
		return pImpl->m_ViewItem.m_Viewport;
	}
	void SingleView::SetCamera(const shared_ptr<Camera>& c) {
		pImpl->m_ViewItem.m_Camera = c;
		//�J�����̌v�Z������
		pImpl->m_ViewItem.m_Camera->CalculateMatrix();
	}
	const shared_ptr<Camera>& SingleView::GetCamera()const {
		return pImpl->m_ViewItem.m_Camera;
	}
	const shared_ptr<Camera>& SingleView::GetTargetCamera() const {
		return pImpl->m_ViewItem.m_Camera;
	}
	const Viewport& SingleView::GetTargetViewport() const {
		return pImpl->m_ViewItem.m_Viewport;
	}

	//--------------------------------------------------------------------------------------
	///	struct MultiView::Impl;
	//--------------------------------------------------------------------------------------
	struct MultiView::Impl {
		vector<ViewItem> m_ViewItemVec;
		size_t m_TargetIndex;
		Impl():
			m_TargetIndex(0)
		{
		}
		~Impl() {}
	};

	MultiView::MultiView(const shared_ptr<Stage>& StagePtr) :
		ViewBase(StagePtr), pImpl(new Impl())
	{}

	MultiView::~MultiView() {}

	size_t MultiView::AddView(const Viewport& v, const shared_ptr<Camera>& c) {
		ViewItem Item;
		Item.m_Viewport = v;
		Item.m_Camera = c;
		size_t ret = pImpl->m_ViewItemVec.size();
		pImpl->m_ViewItemVec.push_back(Item);
		return ret;
	}
	size_t MultiView::GetViewSize()const {
		return pImpl->m_ViewItemVec.size();
	}
	void MultiView::SetViewport(size_t Index, const Viewport& v) {
		if (Index >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(Index),
				L"MultiView::SetViewport()"
			);
		}
		pImpl->m_ViewItemVec[Index].m_Viewport = v;
	}
	const Viewport& MultiView::GetViewport(size_t Index) const {
		if (Index >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(Index),
				L"MultiView::GetViewport()"
			);
		}
		return pImpl->m_ViewItemVec[Index].m_Viewport;
	}
	void MultiView::SetCamera(size_t Index, const shared_ptr<Camera>& c) {
		if (Index >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(Index),
				L"MultiView::SetCamera()"
			);
		}
		pImpl->m_ViewItemVec[Index].m_Camera = c;
	}
	const shared_ptr<Camera>& MultiView::GetCamera(size_t Index)const {
		if (Index >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(Index),
				L"MultiView::GetCamera()"
			);
		}
		return pImpl->m_ViewItemVec[Index].m_Camera;
	}
	size_t MultiView::GetTargetIndex()const {
		if (pImpl->m_ViewItemVec.empty()) {
			throw BaseException(
				L"�r���[���ݒ肳��ĂȂ��̂ł��̃R�}���h�͖��Ӗ��ł�",
				L"if (pImpl->m_ViewItemVec.empty())",
				L"MultiView::GetTargetIndex()"
			);
		}
		return pImpl->m_TargetIndex;
	}
	void MultiView::SetTargetIndex(size_t Index) {
		if (Index >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(Index),
				L"MultiView::SetTargetIndex()"
			);
		}
		pImpl->m_TargetIndex = Index;
	}
	void MultiView::ChangeNextView() {
		pImpl->m_TargetIndex++;
		if (pImpl->m_TargetIndex >= pImpl->m_ViewItemVec.size()) {
			pImpl->m_TargetIndex = 0;
		}
	}
	const shared_ptr<Camera>& MultiView::GetTargetCamera() const {
		if (pImpl->m_TargetIndex >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(pImpl->m_TargetIndex),
				L"MultiView::GetTargetCamera()"
			);
		}
		return pImpl->m_ViewItemVec[pImpl->m_TargetIndex].m_Camera;
	}
	const Viewport& MultiView::GetTargetViewport() const {
		if (pImpl->m_TargetIndex >= pImpl->m_ViewItemVec.size()) {
			throw BaseException(
				L"�C���f�b�N�X���͈͊O�ł��B",
				Util::UintToWStr(pImpl->m_TargetIndex),
				L"MultiView::GetTargetViewport()"
			);
		}
		return pImpl->m_ViewItemVec[pImpl->m_TargetIndex].m_Viewport;
	}

	void MultiView::OnCreate() {
	}
	void MultiView::OnUpdate() {
		for (auto& v : pImpl->m_ViewItemVec) {
			v.m_Camera->OnUpdate();
		}
	}







	//--------------------------------------------------------------------------------------
	///	struct LightBase::Impl;
	//--------------------------------------------------------------------------------------
	struct LightBase::Impl {
		weak_ptr<Stage> m_Stage;
		Color4 m_AmbientLightColor;
		explicit Impl(const shared_ptr<Stage>& StagePtr) :
			m_Stage(StagePtr),
			m_AmbientLightColor(0, 0, 0, 0)
		{}
		~Impl() {}
	};
	//--------------------------------------------------------------------------------------
	///	�X�e�[�W�ɐݒ肷�郉�C�g�i�e�j
	//--------------------------------------------------------------------------------------
	LightBase::LightBase(const shared_ptr<Stage>& StagePtr) :
		ObjectInterface(),
		pImpl(new Impl(StagePtr))
	{
	}

	LightBase::~LightBase() {}

	Color4 LightBase::GetAmbientLightColor()const {
		return pImpl->m_AmbientLightColor;
	}

	void LightBase::SetAmbientLightColor(const Color4& value) {
		pImpl->m_AmbientLightColor = value;
	}


	//--------------------------------------------------------------------------------------
	///	struct SingleLight::Impl;
	//--------------------------------------------------------------------------------------
	struct SingleLight::Impl {
		Light m_Light;
		Impl() 
		{
		}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	///	�V���O�����C�g
	//--------------------------------------------------------------------------------------
	SingleLight::SingleLight(const shared_ptr<Stage>& StagePtr) :
		LightBase(StagePtr),
		pImpl(new Impl())
	{}

	SingleLight::~SingleLight() {}

	void SingleLight::SetLight(const Light& l) {
		pImpl->m_Light = l;
	}

	const Light& SingleLight::GetLight()const {
		return pImpl->m_Light;
	}

	Light& SingleLight::GetLight() {
		return pImpl->m_Light;
	}

	const Light& SingleLight::GetTargetLight() const {
		return pImpl->m_Light;
	}


	//--------------------------------------------------------------------------------------
	///	struct MultiLight::Impl;
	//--------------------------------------------------------------------------------------
	struct MultiLight::Impl {
		vector<Light> m_LightVec;
		size_t m_MainIndex;
		Impl():
			m_MainIndex(0)
		{
			m_LightVec.resize(3);
			for (auto& v : m_LightVec) {
				v.m_Directional = Vector3(0, -1, 0);
				v.m_DiffuseColor = Color4(1, 1, 1, 1);
				v.m_SpecularColor = Color4(1, 1, 1, 1);
			}
		}
		~Impl() {}
	};



	//--------------------------------------------------------------------------------------
	///	�}���`���C�g
	//--------------------------------------------------------------------------------------

	void MultiLight::ValidateLightIndex(size_t index)const
	{
		if (index >= 3)
		{
			throw BaseException(
				L"���C�g�̃C���f�b�N�X���͈͊O�ł��B0����2�̊ԂŎw�肵�Ă��������B",
				L"if (index >= 3)",
				L"MultiLight::ValidateLightIndex()"
			);
		}
	}

	MultiLight::MultiLight(const shared_ptr<Stage>& StagePtr) :
		LightBase(StagePtr),
		pImpl(new Impl())
	{
	}

	MultiLight::~MultiLight() {}

	void MultiLight::SetMainIndex(size_t index) {
		ValidateLightIndex(index);
		pImpl->m_MainIndex = index;
	}

	size_t  MultiLight::GetMainIndex()const {
		return pImpl->m_MainIndex;
	}

	void  MultiLight::SetLight(size_t index, const Light& l) {
		ValidateLightIndex(index);
		pImpl->m_LightVec[index] = l;
	}

	const Light& MultiLight::GetLight(size_t index)const {
		ValidateLightIndex(index);
		return pImpl->m_LightVec[index];
	}

	Light&  MultiLight::GetLight(size_t index) {
		ValidateLightIndex(index);
		return pImpl->m_LightVec[index];
	}

	void MultiLight::SetDefaultLighting() {
		static const Vector3 defaultDirections[3] =
		{
			{ -0.5265408f, -0.5735765f, -0.6275069f },
			{ 0.7198464f,  0.3420201f,  0.6040227f },
			{ 0.4545195f, -0.7660444f,  0.4545195f },
		};

		static const Color4 defaultDiffuse[3] =
		{
			{ 1.0000000f, 0.9607844f, 0.8078432f,0.0f },
			{ 0.9647059f, 0.7607844f, 0.4078432f,0.0f },
			{ 0.3231373f, 0.3607844f, 0.3937255f,0.0f },
		};

		static const Color4 defaultSpecular[3] =
		{
			{ 1.0000000f, 0.9607844f, 0.8078432f,0.0f },
			{ 0.0000000f, 0.0000000f, 0.0000000f,0.0f },
			{ 0.3231373f, 0.3607844f, 0.3937255f,0.0f },
		};
		static const Color4 defaultAmbient = { 0.05333332f, 0.09882354f, 0.1819608f ,0.0f };
		for (size_t i = 0; i < 3; i++) {
			pImpl->m_LightVec[i].m_Directional = defaultDirections[i];
			pImpl->m_LightVec[i].m_DiffuseColor = defaultDiffuse[i];
			pImpl->m_LightVec[i].m_SpecularColor = defaultSpecular[i];
		}
		SetAmbientLightColor(defaultAmbient);
		pImpl->m_MainIndex = 2;
	}

	void MultiLight::SetDefaultLighting2() {
		static const Vector3 defaultDirections[3] =
		{
			{ -0.5265408f, -0.5735765f, -0.6275069f },
			{ 0.7198464f,  0.3420201f,  0.6040227f },
			{ 0.4545195f, -0.7660444f,  0.4545195f },
		};

		static const Color4 defaultDiffuse[3] =
		{
			{ 0.3231373f, 0.3607844f, 0.3937255f,0.0f },
			{ 0.9647059f, 0.7607844f, 0.4078432f,0.0f },
			{ 1.0000000f, 0.9607844f, 0.8078432f,0.0f },
		};

		static const Color4 defaultSpecular[3] =
		{
			{ 0.3231373f, 0.3607844f, 0.3937255f,0.0f },
			{ 0.0000000f, 0.0000000f, 0.0000000f,0.0f },
			{ 1.0000000f, 0.9607844f, 0.8078432f,0.0f },
		};
		static const Color4 defaultAmbient = { 0.05333332f, 0.09882354f, 0.1819608f ,0.0f };
		for (size_t i = 0; i < 3; i++) {
			pImpl->m_LightVec[i].m_Directional = defaultDirections[i];
			pImpl->m_LightVec[i].m_DiffuseColor = defaultDiffuse[i];
			pImpl->m_LightVec[i].m_SpecularColor = defaultSpecular[i];
		}
		SetAmbientLightColor(defaultAmbient);
		pImpl->m_MainIndex = 2;
	}


	const Light& MultiLight::GetTargetLight() const {
		return pImpl->m_LightVec[pImpl->m_MainIndex];
	}








	//--------------------------------------------------------------------------------------
	//	struct Steering;
	//	�p�r: ���Ǌ֘A���[�e�B���e�B
	//	��static�Ăяo��������
	//--------------------------------------------------------------------------------------
	//�X�^�e�B�b�N�����o
	bool Steering::AccumulateForce(Vector3& Force, const Vector3& ForceToAdd, float MaxForce) {
		//���݂̗͂̒����𓾂�
		float MagnitudeSoFar = Force.Length();
		//�ő�l�Ƃ̍������߂�
		float magnitudeRemaining = MaxForce - MagnitudeSoFar;
		//����0�ȉ��i�܂�ő�l�𒴂��Ă�����j
		//�ǉ����Ȃ��Ń��^�[��
		if (magnitudeRemaining <= 0.0f) {
			return false;
		}
		//�ǉ�����͂̑傫�������߂�
		float MagnitudeToAdd = ForceToAdd.Length();
		//�͂̒ǉ�
		if (MagnitudeToAdd < magnitudeRemaining) {
			Force += ForceToAdd;
		}
		else {
			Force += (Vector3EX::Normalize(ForceToAdd) * MagnitudeToAdd);
		}
		//�ǉ����ꂽ�w�W��Ԃ�  
		return true;
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::Seek(const Vector3& Velocity, const Vector3& Target, const Vector3& Pos, float MaxSpeed) {
		Vector3 DesiredVelocity
			= Vector3EX::Normalize(Target - Pos) * MaxSpeed;
		return (DesiredVelocity - Velocity);
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::Flee(const Vector3& Velocity, const Vector3& Target,
		const Vector3& Pos, float MaxSpeed, float PanicDistance) {
		float PanicDistanceSq = PanicDistance * PanicDistance;
		if (Vector3EX::LengthSq(Pos - Target) > PanicDistanceSq) {
			return Vector3(0, 0, 0);
		}
		Vector3 DesiredVelocity
			= Vector3EX::Normalize(Pos - Target) * MaxSpeed;
		return (DesiredVelocity - Velocity);
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::Arrive(const Vector3& Velocity, const Vector3& Target, const Vector3& Pos, float MaxSpeed, float Decl) {
		Vector3 ToTarget = Target - Pos;
		float dist = ToTarget.Length();
		if (dist > 0) {
			const float DecelerationTweaker = 0.3f;
			float speed = dist / (Decl * DecelerationTweaker);
			speed = Util::Minimum(speed, MaxSpeed);
			Vector3 DesiredVelocity = ToTarget * speed / dist;
			return (DesiredVelocity - Velocity);
		}
		return Vector3(0, 0, 0);
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::Pursuit(const Vector3& Velocity, const Vector3& Pos, const Vector3& Rot, float MaxSpeed,
		const Vector3& TargetVelocity, const Vector3& Target, const Vector3& TargetRot) {
		Vector3 ToEvader = Target - Pos;
		double RelativeHeading = Rot.Dot(TargetRot);
		if ((ToEvader.Dot(Rot) > 0) &&
			(RelativeHeading < -0.95))  //acos(0.95)=18 degs
		{
			return Steering::Seek(Velocity, Target, Pos, MaxSpeed);
		}
		float LookAheadTime = ToEvader.Length() /
			(MaxSpeed + TargetVelocity.Length());
		return Steering::Seek(Velocity, Target + TargetVelocity * LookAheadTime, Pos, MaxSpeed);
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::Wander(const Matrix4X4 Matrix,
		float WanderRadius, float WanderDistance, float WanderJitter, Vector3& WanderTarget) {
		WanderTarget += Vector3(
			(Util::RandZeroToOne(true) * 2.0f - 1.0f)  * WanderJitter,
			0,
			(Util::RandZeroToOne(true) * 2.0f - 1.0f)  * WanderJitter
		);
		WanderTarget.Normalize();
		WanderTarget *= WanderRadius;
		Vector3 target_Local = WanderTarget + Vector3(0, 0, WanderDistance);
		Vector3 Scale,  Pos;
		Quaternion Qt;
		Matrix.Decompose(Scale, Qt, Pos);
		Matrix4X4 mat;
		mat.AffineTransformation(Scale, target_Local, Qt, Pos);
		target_Local.Transform(Matrix);
		return target_Local - Matrix.PosInMatrix();
	}

	struct ObstacleAvoidanceSphere {
		SPHERE m_Sp;
		float Len;
		ObstacleAvoidanceSphere(const SPHERE& Sp, float len) :
			m_Sp(Sp), Len(len) {}
	};

	//--------------------------------------------------------------------------------------
	bool SortSphereObstacleAvoidanceHandle(ObstacleAvoidanceSphere& Left, ObstacleAvoidanceSphere& Right) {
		return Left.Len < Right.Len;
	}

	//--------------------------------------------------------------------------------------
	Vector3 Steering::ObstacleAvoidance(const Matrix4X4 Matrix,
		const Vector3& Velocity, float MaxSpeed, float Width, float Height,
		const vector<SPHERE>& SphereVec) {
		//���݂̑��x�ƈʒu�Ɠ�������A�Փ˔���OBB���쐬����
		Vector3 Scale(Width, Height, Velocity.Length());
		Matrix4X4 ObbMat;
		ObbMat.DefTransformation(Scale, Matrix.QtInMatrix(), Matrix.PosInMatrix() + Velocity / 2.0f);
		OBB Obb(Vector3(1.0f, 1.0f, 1.0f), ObbMat);
		vector<ObstacleAvoidanceSphere> ChangeVec;
		for (size_t i = 0; i < SphereVec.size(); i++) {
			float len = Vector3EX::Length(SphereVec[i].m_Center - Matrix.PosInMatrix());
			ObstacleAvoidanceSphere Sp(SphereVec[i], len);
			ChangeVec.push_back(Sp);
		}
		//������ύX�\�[�g
		std::sort(ChangeVec.begin(), ChangeVec.end(), SortSphereObstacleAvoidanceHandle);
		//�߂����Ɍ������ĉ����ƏՓ˂��Ă�����A�^�[�Q�b�g������SEEK
		for (size_t i = 0; i < ChangeVec.size(); i++) {
			Vector3 RetVec;
			if (HitTest::SPHERE_OBB(ChangeVec[i].m_Sp, Obb, RetVec)) {
				//�i�s������OBB�ƏՓ˂���
				//OBB�i�s�����̐�����RetVec�Ƃ̍ŋߐړ_�����߂�
				float t;
				Vector3 d;
				HitTest::ClosetPtPointSegment(RetVec, Matrix.PosInMatrix(), Matrix.PosInMatrix() + Velocity, t, d);
				//�ޔ�������v�Z����
				Vector3 AvoidanceVec = (d - RetVec);
				//���K��
				AvoidanceVec.Normalize();
				AvoidanceVec *= (Width + MaxSpeed);
				return AvoidanceVec;
			}
		}
		return Vector3(0, 0, 0);
	}

	struct AvoidanceSegment {
		Vector3 m_PointA;
		Vector3 m_PointB;
		AvoidanceSegment() {}
		AvoidanceSegment(const Vector3& pa, const Vector3& pb) :
			m_PointA(pa),
			m_PointB(pb)
		{
		}
	};

	//--------------------------------------------------------------------------------------
	Vector3 Steering::WallAvoidance(const Matrix4X4 Matrix,
		const Vector3& Velocity, float MaxSpeed, const vector<PLANE>& PlaneVec) {
		//�܂��G�o�ɂȂ�����z����쐬
		float Len = Velocity.Length() * 0.5f;
		vector<AvoidanceSegment> Segments;
		Segments.push_back(AvoidanceSegment(Vector3(0, 0, Len), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(cos(XM_PIDIV4) * Len, 0, sin(XM_PIDIV4) * Len), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(-cos(XM_PIDIV4) * Len, 0, sin(XM_PIDIV4) * Len), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(Len, 0, 0), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(-Len, 0, 0), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(cos(XM_PIDIV4) * Len, 0, -sin(XM_PIDIV4) * Len), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(-cos(XM_PIDIV4) * Len, 0, -sin(XM_PIDIV4) * Len), Vector3(0, 0, 0)));
		Segments.push_back(AvoidanceSegment(Vector3(0, 0, -Len), Vector3(0, 0, 0)));
		for (size_t i = 0; i < Segments.size(); i++) {
			//�G�o�̊e���_�ɍs����v�Z���āA���[���h���W�ɕϊ�
			Segments[i].m_PointA.Transform(Matrix);
			Segments[i].m_PointB.Transform(Matrix);
			//�����ƕǂ̏Փ˔���
			Vector3 RetVec;
			float t;
			for (size_t j = 0; j < PlaneVec.size(); j++) {
				if (HitTest::InsidePtPlane(Matrix.PosInMatrix(), PlaneVec[j])) {
					return PlaneVec[j].m_Normal * MaxSpeed;
				}
				if (HitTest::SEGMENT_PLANE(Segments[i].m_PointA, Segments[i].m_PointB, PlaneVec[j], t, RetVec)) {
					//�����Ɩʂ��Փ˂��Ă���
					//�ʂ̖@���̕����Ɍ��݂̑��x�Ńt�H�[�X��Ԃ�
					return PlaneVec[j].m_Normal * Velocity.Length();
				}
			}
		}
		return Vector3(0, 0, 0);
	}



	//--------------------------------------------------------------------------------------
	Vector3 Steering::FollowPath(Path& rPath,
		float WaypointSeekDist,
		const Vector3& Pos, const Vector3& Velocity,
		float MaxSpeed, float Decl) {
		Vector3 Dis = Pos - rPath.GetCurWaypoint();
		float DisSq = Dis.LengthSq();
		float WaypointSeekDistSq = WaypointSeekDist * WaypointSeekDist;

		if (DisSq < WaypointSeekDistSq) {
			rPath.SetNextWaypoint();
		}
		if (!rPath.IsFinished()) {
			return Seek(Velocity, rPath.GetCurWaypoint(), Pos, MaxSpeed);
		}
		else {
			return Arrive(Velocity, rPath.GetCurWaypoint(), Pos, MaxSpeed, Decl);
		}
	}

	Vector3 Steering::Separation(const shared_ptr<GameObjectGroup>& Group, const shared_ptr<GameObject>& MyObj) {
		Vector3 SteeringForce(0, 0, 0);
		auto Vec = Group->GetGroupVector();
		for (auto Ptr : Vec) {
			if (!Ptr.expired()) {
				auto PtrObj = Ptr.lock();
				if (PtrObj != MyObj) {
					PtrObj->GetComponent<Transform>();
					Vector3 ToAgent
						= MyObj->GetComponent<Transform>()->GetWorldPosition()
						- PtrObj->GetComponent<Transform>()->GetWorldPosition();
					SteeringForce += Vector3EX::Normalize(ToAgent) / ToAgent.Length();
				}
			}
		}
		return SteeringForce;
	}




	//--------------------------------------------------------------------------------------
	//	static Vector3 Alignment(
	//	const shared_ptr<GameObjectGroup>& Group,	//�ݒ肷��O���[�v�̔z��
	//	const shared_ptr<GameObject>& MyObj				//�������g
	//	);
	//	�p�r: ����s��
	//	�߂�l: �t�H�[�X
	//--------------------------------------------------------------------------------------
	Vector3 Steering::Alignment(const shared_ptr<GameObjectGroup>& Group, const shared_ptr<GameObject>& MyObj) {
		Vector3 AverageHeading(0, 0, 0);
		auto Vec = Group->GetGroupVector();
		int count = 0;
		for (auto Ptr : Vec) {
			if (!Ptr.expired()) {
				auto PtrObj = Ptr.lock();
				if (PtrObj != MyObj) {
					auto PtrT = PtrObj->GetComponent<Transform>();
					AverageHeading += QuaternionEX::GetRotation(PtrT->GetQuaternion());
					count++;
				}
			}
		}
		if (count > 0) {
			AverageHeading /= (float)count;
			auto PtrT = MyObj->GetComponent<Transform>();
			AverageHeading -= QuaternionEX::GetRotation(PtrT->GetQuaternion());
		}
		return AverageHeading;
	}

	//--------------------------------------------------------------------------------------
	//	static Vector3 Cohesion(
	//	const shared_ptr<GameObjectGroup>& Group,	//�ݒ肷��O���[�v�̔z��
	//	const shared_ptr<GameObject>& MyObj			//�������g
	//	const Vector3& Velocity,	//���݂̑��x
	//	float MaxSpeed				//�ō����x
	//	);
	//	�p�r: �����s��
	//	�߂�l: �t�H�[�X
	//--------------------------------------------------------------------------------------
	Vector3 Steering::Cohesion(const shared_ptr<GameObjectGroup>& Group, const shared_ptr<GameObject>& MyObj,
		const Vector3& Velocity, float MaxSpeed) {
		auto Vec = Group->GetGroupVector();
		Vector3 SteeringForce(0, 0, 0);
		//�d�S
		Vector3 CenterOfMass(0, 0, 0);
		int count = 0;
		for (auto Ptr : Vec) {
			if (!Ptr.expired()) {
				auto PtrObj = Ptr.lock();
				if (PtrObj != MyObj) {
					auto PtrT = PtrObj->GetComponent<Transform>();
					CenterOfMass += PtrT->GetWorldPosition();
					count++;
				}
			}
		}
		if (count > 0) {
			CenterOfMass /= (float)count;
			auto PtrT = MyObj->GetComponent<Transform>();
			SteeringForce = Seek(Velocity, CenterOfMass, PtrT->GetWorldPosition(), MaxSpeed);
			SteeringForce.Normalize();
		}
		return SteeringForce;
	}



}
//end basecross
