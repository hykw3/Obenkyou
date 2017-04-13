/*!
@file DrawComponentsEx.cpp
@brief �g���`��R���|�[�l���g����
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	///	DirectXTK��Effect�֘A�ڐA
	//--------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------
	///	Basic�V�F�[�_�[
	//--------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------
	/// �R���X�^���g�o�b�t�@
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_CONSTANT_BUFFER(CBBasic)


	//--------------------------------------------------------------------------------------
	/// PC���_�V�F�[�_
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPCStatic, App::GetApp()->GetShadersPath() + L"BcVSPCStatic.cso")

	//--------------------------------------------------------------------------------------
	/// PT���_�V�F�[�_
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPTStatic, App::GetApp()->GetShadersPath() + L"BcVSPTStatic.cso")

	//--------------------------------------------------------------------------------------
	/// PCT���_�V�F�[�_
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPCTStatic, App::GetApp()->GetShadersPath() + L"BcVSPCTStatic.cso")

	//--------------------------------------------------------------------------------------
	/// PC�p�s�N�Z���V�F�[�_
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPCStatic, App::GetApp()->GetShadersPath() + L"BcPSPCStatic.cso")


	//--------------------------------------------------------------------------------------
	/// PT,PCT�p�s�N�Z���V�F�[�_
	//--------------------------------------------------------------------------------------
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPTStatic, App::GetApp()->GetShadersPath() + L"BcPSPTStatic.cso")



	//--------------------------------------------------------------------------------------
	/// PNT���_�V�F�[�_(���_���C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticVL, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticVL.cso")
	//�e����Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBoneVL, App::GetApp()->GetShadersPath() + L"BcVSPNTBoneVL.cso")
	//�e�t��
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticVLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticVLShadow.cso")
	//�e�t��Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBoneVLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTBoneVLShadow.cso")


		

	//�o�C�A�X�t���e����
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticVLBn, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticVLBn.cso")
	//�o�C�A�X�t���e����Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBoneVLBn, App::GetApp()->GetShadersPath() + L"BcVSPNTBoneVLBn.cso")

	//�o�C�A�X�t���e�t��
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticVLBnShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticVLBnShadow.cso")

	//�o�C�A�X�t���e�t��Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBoneVLBnShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTBoneVLBnShadow.cso")


		
	//--------------------------------------------------------------------------------------
	/// PNT�s�N�Z���V�F�[�_(���_���C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTVL, App::GetApp()->GetShadersPath() + L"BcPSPNTVL.cso")
	//�e�t��
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTVLShadow, App::GetApp()->GetShadersPath() + L"BcPSPNTVLShadow.cso")


	//--------------------------------------------------------------------------------------
	/// PNT���_�V�F�[�_(�s�N�Z�����C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticPL, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticPL.cso")
	//�e����Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBonePL, App::GetApp()->GetShadersPath() + L"BcVSPNTBonePL.cso")
	//�e�t��
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticPLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticPLShadow.cso")
	//�e�t��Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBonePLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTBonePLShadow.cso")
		
	//�o�C�X�t���e����
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticPLBn, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticPLBn.cso")
	//�o�C�X�t���e����Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBonePLBn, App::GetApp()->GetShadersPath() + L"BcVSPNTBonePLBn.cso")

	//�o�C�X�t���e�t��
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTStaticPLBnShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTStaticPLBnShadow.cso")
	//�o�C�X�t���e�t��Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTBonePLBnShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTBonePLBnShadow.cso")


		

	//--------------------------------------------------------------------------------------
	/// PNT�s�N�Z���V�F�[�_(�s�N�Z�����C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTPL, App::GetApp()->GetShadersPath() + L"BcPSPNTPL.cso")
	//�e�t��
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTPLShadow, App::GetApp()->GetShadersPath() + L"BcPSPNTPLShadow.cso")


	//--------------------------------------------------------------------------------------
	/// PNTnT���_�V�F�[�_(�s�N�Z�����C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTnTStaticPL, App::GetApp()->GetShadersPath() + L"BcVSPNTnTStaticPL.cso")
	//�e����Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTnTBonePL, App::GetApp()->GetShadersPath() + L"BcVSPNTnTBonePL.cso")

	//�e��
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTnTStaticPLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTnTStaticPLShadow.cso")
	//�e��Bone
	IMPLEMENT_DX11_VERTEX_SHADER(BcVSPNTnTBonePLShadow, App::GetApp()->GetShadersPath() + L"BcVSPNTnTBonePLShadow.cso")


	//--------------------------------------------------------------------------------------
	/// PNTnT�s�N�Z���V�F�[�_(�s�N�Z�����C�e�B���O)
	//--------------------------------------------------------------------------------------
	//�e����
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTnTPL, App::GetApp()->GetShadersPath() + L"BcPSPNTnTPL.cso");
	//�e��
	IMPLEMENT_DX11_PIXEL_SHADER(BcPSPNTnTPLShadow, App::GetApp()->GetShadersPath() + L"BcPSPNTnTPLShadow.cso");




	//--------------------------------------------------------------------------------------
	//	BcStaticBaseDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcStaticBaseDraw::Impl {
		//���b�V�����\�[�X
		weak_ptr<MeshResource> m_MeshResource;
		//���_�ύX����ꍇ�̃��b�V���i�I���W�i���j
		shared_ptr<MeshResource> m_OriginalMeshResource;
		//�I���W�i�����b�V�����g�����ǂ���
		bool m_UseOriginalMeshResource;
		//�G�~�b�V�u�F
		Color4 m_Emissive;
		//�f�t���[�Y�F
		Color4 m_Diffuse;
		//�����x
		float m_Alpha;
		//�X�y�L�����[�ƃp���[�F
		Color4 m_SpecularColorAndPower;
		//���C�e�B���O���邩�ǂ���
		bool m_LightingEnabled;
		//�s�N�Z�����C�e�B���O�����邩�ǂ���
		bool m_PreferPerPixelLighting;
		//�@���Ƀo�C�A�X�������邩�ǂ���
		bool m_BiasedNormals;
		//�A���r�G���g
		Color4 m_AmbientLightColor;
		//���C�g��MAX
		static const int MaxDirectionalLights = 3;
		//���C�g���L�����ǂ���
		bool m_LightEnabled[MaxDirectionalLights];
		//���C�g�̌���
		Vector3 m_LightDirection[MaxDirectionalLights];
		//���C�g�̃f�t���[�Y�F
		Color4 m_LightDiffuseColor[MaxDirectionalLights];
		//���C�g�̃X�y�L�����[�F
		Color4 m_LightSpecularColor[MaxDirectionalLights];
		//�f�t�H���g�̃��C�e�B���O��ݒ肷��
		static void EnableDefaultLighting(BcStaticBaseDraw* Draw);
		//�t�H�O���L�����ǂ���
		bool m_FogEnabled;
		//�t�H�O�̊J�n�ʒu
		float m_FogStart;
		//�t�H�O�̏I���ʒu
		float m_FogEnd;
		//�t�H�O�F
		Color4 m_FogColor;
		//�t�H�O�x�N�g��
		Vector3 m_FogVector;
		Impl() :
			m_UseOriginalMeshResource(false),
			m_Emissive(0.0f, 0.0f, 0.0f, 0.0),
			m_Diffuse(1.0f, 1.0f, 1.0f, 1.0f),
			m_Alpha(1.0f),
			m_SpecularColorAndPower(0.0f, 0.0f, 0.0f, 1.0f),
			m_LightingEnabled(false),
			m_PreferPerPixelLighting(false),
			m_BiasedNormals(false),
			m_AmbientLightColor(0, 0, 0, 0),
			m_FogEnabled(false),
			m_FogStart(-25.0f),
			m_FogEnd(-40.0f),
			m_FogColor(0.8f, 0.8f, 0.8f, 1.0f),
			m_FogVector(0.0, 0.0, 1.0f)
		{
			static const XMVECTORF32 defaultSpecular = { 1, 1, 1, 16 };
			static const Vector3 defaultLightDirection = { 0, -1, 0 };
			m_SpecularColorAndPower = defaultSpecular;
			for (int i = 0; i < MaxDirectionalLights; i++)
			{
				m_LightDirection[i] = defaultLightDirection;
				m_LightDiffuseColor[i] =  g_XMZero;
				m_LightSpecularColor[i] =  g_XMZero;
			}
		}
	};

	//--------------------------------------------------------------------------------------
	///	Basic�`��R���|�[�l���g�̐e(3D�`��)
	//--------------------------------------------------------------------------------------
	BcStaticBaseDraw::BcStaticBaseDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		DrawComponent(GameObjectPtr),
		pImpl(new Impl()) {}

	BcStaticBaseDraw::~BcStaticBaseDraw() {}


	bool BcStaticBaseDraw::IsOriginalMeshUse() const {
		return pImpl->m_UseOriginalMeshResource;
	}

	void BcStaticBaseDraw::SetOriginalMeshUse(bool b) {
		pImpl->m_UseOriginalMeshResource = b;
	}

	shared_ptr<MeshResource> BcStaticBaseDraw::GetOriginalMeshResource() const {
		return pImpl->m_OriginalMeshResource;
	}
	void BcStaticBaseDraw::SetOriginalMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		pImpl->m_OriginalMeshResource = MeshRes;
	}


	shared_ptr<MeshResource> BcStaticBaseDraw::GetMeshResource() const {
		if (IsOriginalMeshUse()) {
			return pImpl->m_OriginalMeshResource;
		}
		else {
			auto shptr = pImpl->m_MeshResource.lock();
			if (shptr) {
				return shptr;
			}
		}
		return nullptr;
	}
	void BcStaticBaseDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		pImpl->m_MeshResource = MeshRes;
	}

	void BcStaticBaseDraw::SetMeshResource(const wstring& MeshKey) {
		this->SetMeshResource(App::GetApp()->GetResource<MeshResource>(MeshKey));
	}


	Color4 BcStaticBaseDraw::GetEmissive() const {
		return pImpl->m_Emissive;
	}
	void BcStaticBaseDraw::SetEmissive(const Color4& col) {
		pImpl->m_Emissive = col;
	}
	Color4 BcStaticBaseDraw::GetDiffuse() const {
		return pImpl->m_Diffuse;
	}
	void BcStaticBaseDraw::SetDiffuse(const Color4& col) {
		pImpl->m_Diffuse = col;
	}

	Color4 BcStaticBaseDraw::GetSpecularColor() const {
		Color4 ret = pImpl->m_SpecularColorAndPower;
		ret.w = 0.0f;
		return ret;
	}
	void BcStaticBaseDraw::SetSpecularColor(const Color4& col) {
		pImpl->m_SpecularColorAndPower = XMVectorSelect(pImpl->m_SpecularColorAndPower, col, g_XMSelect1110);
	}

	void BcStaticBaseDraw::DisableSpecular() {
		pImpl->m_SpecularColorAndPower = g_XMIdentityR3;
	}

	float BcStaticBaseDraw::GetSpecularPower() const {
		return pImpl->m_SpecularColorAndPower.w;
	}


	void BcStaticBaseDraw::SetSpecularPower(float pow) {
		pImpl->m_SpecularColorAndPower.w = pow;
	}



	Color4 BcStaticBaseDraw::GetSpecularColorAndPower() const {
		return pImpl->m_SpecularColorAndPower;
	}
	void BcStaticBaseDraw::SetSpecularColorAndPower(const Color4& col) {
		pImpl->m_SpecularColorAndPower = col;
	}

	float BcStaticBaseDraw::GetAlpha() const {
		return pImpl->m_Alpha;
	}

	void BcStaticBaseDraw::SetAlpha(float a) {
		pImpl->m_Alpha = a;
	}

	Color4 BcStaticBaseDraw::GetColorAndAlpha() const {
		Color4 ret = pImpl->m_Diffuse;
		ret.w = pImpl->m_Alpha;
		return ret;
	}

	void BcStaticBaseDraw::SetColorAndAlpha(const Color4& col) {
		pImpl->m_Diffuse = col;
		pImpl->m_Alpha = col.w;
	}
	bool BcStaticBaseDraw::IsLightingEnabled() const {
		return pImpl->m_LightingEnabled;
	}
	bool BcStaticBaseDraw::GetLightingEnabled() const {
		return pImpl->m_LightingEnabled;

	}
	void BcStaticBaseDraw::SetLightingEnabled(bool value) {
		pImpl->m_LightingEnabled = value;
	}
	bool BcStaticBaseDraw::GetPerPixelLighting() const {
		return pImpl->m_PreferPerPixelLighting;
	}

	bool BcStaticBaseDraw::IsPerPixelLighting() const {
		return pImpl->m_PreferPerPixelLighting;

	}
	void BcStaticBaseDraw::SetPerPixelLighting(bool value) {
		pImpl->m_PreferPerPixelLighting = value;
	}

	void BcStaticBaseDraw::SetLightingParamaters() {
		//���C�g�𓾂�
		auto PtrLightObj = GetGameObject()->GetStage()->GetLight();
		auto PtrMultiLight = dynamic_pointer_cast<MultiLight>(PtrLightObj);
		if (PtrMultiLight) {
			//�}���`���C�g������
			for (int i = 0; i < GetMaxDirectionalLights(); i++) {
				if (IsLightEnabled(i)) {
					SetLightDirection(i, PtrMultiLight->GetLight(i).m_Directional);
					SetLightDiffuseColor(i, PtrMultiLight->GetLight(i).m_DiffuseColor);
					SetLightSpecularColor(i, PtrMultiLight->GetLight(i).m_SpecularColor);
				}
			}
		}
		else {
			//�����ł͂Ȃ�
			auto LightPtr = GetGameObject()->OnGetDrawLight();
			SetLightEnabled(0, true);
			SetLightDirection(0, LightPtr.m_Directional);
			SetLightDiffuseColor(0, LightPtr.m_DiffuseColor);
			SetLightSpecularColor(0, LightPtr.m_SpecularColor);
			for (int i = 1; i < GetMaxDirectionalLights(); i++) {
				SetLightEnabled(i, false);
			}
		}
		SetAmbientLightColor(PtrLightObj->GetAmbientLightColor());
	}


	bool BcStaticBaseDraw::GetBiasedNormals() const {
		return pImpl->m_BiasedNormals;
	}

	bool BcStaticBaseDraw::IsBiasedNormals() const {
		return pImpl->m_BiasedNormals;
	}

	void BcStaticBaseDraw::SetBiasedNormals(bool value) {
		pImpl->m_BiasedNormals = value;
	}

	Color4 BcStaticBaseDraw::GetAmbientLightColor()const {
		return pImpl->m_AmbientLightColor;
	}

	void BcStaticBaseDraw::SetAmbientLightColor(const Color4& value) {
		pImpl->m_AmbientLightColor = value;
	}
	void BcStaticBaseDraw::ValidateLightIndex(int whichLight)
	{
		if (whichLight < 0 || whichLight >= Impl::MaxDirectionalLights)
		{
			throw BaseException(
				L"���C�g�̃C���f�b�N�X���͈͊O�ł�",
				L"if (whichLight < 0 || whichLight >= Impl::MaxDirectionalLights)",
				L"Bc3DDraw::ValidateLightIndex()"
			);
		}
	}

	int BcStaticBaseDraw::GetMaxDirectionalLights() {
		return Impl::MaxDirectionalLights;
	}

	bool BcStaticBaseDraw::GetLightEnabled(int whichLight)const {
		ValidateLightIndex(whichLight);
		return pImpl->m_LightEnabled[whichLight];
	}

	bool BcStaticBaseDraw::IsLightEnabled(int whichLight)const {
		ValidateLightIndex(whichLight);
		return pImpl->m_LightEnabled[whichLight];
	}
	void BcStaticBaseDraw::SetLightEnabled(int whichLight, bool value) {
		ValidateLightIndex(whichLight);
		pImpl->m_LightEnabled[whichLight] = value;
	}

	Vector3 BcStaticBaseDraw::GetLightDirection(int whichLight) const {
		ValidateLightIndex(whichLight);
		return pImpl->m_LightDirection[whichLight];
	}

	void BcStaticBaseDraw::SetLightDirection(int whichLight, const Vector3& value) {
		ValidateLightIndex(whichLight);
		pImpl->m_LightDirection[whichLight] = value;
	}

	Color4 BcStaticBaseDraw::GetLightDiffuseColor(int whichLight) const {
		ValidateLightIndex(whichLight);
		return pImpl->m_LightDiffuseColor[whichLight];
	}


	void BcStaticBaseDraw::SetLightDiffuseColor(int whichLight, const Color4& value) {
		ValidateLightIndex(whichLight);
		pImpl->m_LightDiffuseColor[whichLight] = value;
	}

	Color4 BcStaticBaseDraw::GetLightSpecularColor(int whichLight) const {
		ValidateLightIndex(whichLight);
		return pImpl->m_LightSpecularColor[whichLight];
	}

	void BcStaticBaseDraw::SetLightSpecularColor(int whichLight, const Color4& value) {
		ValidateLightIndex(whichLight);
		pImpl->m_LightSpecularColor[whichLight] = value;
	}


	bool BcStaticBaseDraw::GetFogEnabled() const {
		return pImpl->m_FogEnabled;

	}
	bool BcStaticBaseDraw::IsFogEnabled() const {
		return pImpl->m_FogEnabled;
	}
	void BcStaticBaseDraw::SetFogEnabled(bool b) {
		pImpl->m_FogEnabled = b;
	}

	float BcStaticBaseDraw::GetFogStart() const {
		return pImpl->m_FogStart;
	}

	void BcStaticBaseDraw::SetFogStart(float value) {
		//��Ƀ}�C�i�X�l
		pImpl->m_FogStart = -(abs(value));
	}

	float BcStaticBaseDraw::GetFogEnd() const {
		return pImpl->m_FogEnd;
	}
	void BcStaticBaseDraw::SetFogEnd(float value) {
		//��Ƀ}�C�i�X�l
		pImpl->m_FogEnd = -(abs(value));
	}



	Color4 BcStaticBaseDraw::GetFogColor() const {
		return pImpl->m_FogColor;
	}
	void BcStaticBaseDraw::SetFogColor(const Color4& col) {
		pImpl->m_FogColor = col;
	}

	void BcStaticBaseDraw::SetConstants(BasicConstants& BcCb, bool shadowUse) {
		//�s��̒�`
		auto PtrTrans = GetGameObject()->GetComponent<Transform>();
		//�J�����𓾂�
		auto CameraPtr = GetGameObject()->OnGetDrawCamera();
		//���C�g�𓾂�
		auto PtrLightObj = GetGameObject()->GetStage()->GetLight();
		auto PtrMultiLight = dynamic_pointer_cast<MultiLight>(PtrLightObj);
		if (PtrMultiLight) {
			//�}���`���C�g������
			BcCb.activeFlg.x = 3;
		}
		else {
			//�����ł͂Ȃ�
			BcCb.activeFlg.x = 1;
		}
		auto StageLight = GetGameObject()->OnGetDrawLight();
		//���[���h�s��
		Matrix4X4 world = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�r���[�s��
		Matrix4X4 view = CameraPtr->GetViewMatrix();
		//�ˉe�s��
		Matrix4X4 projection = CameraPtr->GetProjMatrix();

		//�s��̐ݒ�
		auto worldView = world * view;
		BcCb.worldViewProj = XMMatrixTranspose(XMMatrixMultiply(worldView, projection));

		//�t�H�O�̐ݒ�
		if (IsFogEnabled())
		{
			auto start = GetFogStart();
			auto end = GetFogEnd();
			if (start == end)
			{
				// Degenerate case: force everything to 100% fogged if start and end are the same.
				static const XMVECTORF32 fullyFogged = { 0, 0, 0, 1 };
				BcCb.fogVector = fullyFogged;
			}
			else
			{
				XMMATRIX worldViewTrans = worldView;
				// _13, _23, _33, _43
				XMVECTOR worldViewZ = XMVectorMergeXY(XMVectorMergeZW(worldViewTrans.r[0], worldViewTrans.r[2]),
					XMVectorMergeZW(worldViewTrans.r[1], worldViewTrans.r[3]));
				XMVECTOR wOffset = XMVectorSwizzle<1, 2, 3, 0>(XMLoadFloat(&start));
				BcCb.fogVector = (worldViewZ + wOffset) / (start - end);
			}
			BcCb.fogColor = GetFogColor();
		}
		else
		{
			BcCb.fogVector = g_XMZero;
			BcCb.fogColor = g_XMZero;

		}
		//���C�g�̐ݒ�
		if (IsLightingEnabled())
		{
			if (BcCb.activeFlg.x == 1) {
				BcCb.lightDirection[0] = GetLightDirection(0);
				BcCb.lightDiffuseColor[0] = GetLightDiffuseColor(0);
				BcCb.lightSpecularColor[0] = GetLightSpecularColor(0);
			}
			else {
				for (int i = 0; i < GetMaxDirectionalLights(); i++) {
					if (IsLightEnabled(i)) {
						BcCb.lightDirection[i] = GetLightDirection(i);
						BcCb.lightDiffuseColor[i] = GetLightDiffuseColor(i);
						BcCb.lightSpecularColor[i] = GetLightSpecularColor(i);
					}
				}
			}
			BcCb.world = XMMatrixTranspose(world);

			XMMATRIX worldInverse = XMMatrixInverse(nullptr, world);

			BcCb.worldInverseTranspose[0] = worldInverse.r[0];
			BcCb.worldInverseTranspose[1] = worldInverse.r[1];
			BcCb.worldInverseTranspose[2] = worldInverse.r[2];


			XMMATRIX viewInverse = XMMatrixInverse(nullptr, view);

			BcCb.eyePosition = viewInverse.r[3];
		}
		XMVECTOR diffuse = GetDiffuse();
		XMVECTOR alphaVector = XMVectorReplicate(GetAlpha());
		XMVECTOR emissiveColor = GetEmissive();
		XMVECTOR ambientLightColor = GetAmbientLightColor();
		if (IsLightingEnabled())
		{
			// Merge emissive and ambient light contributions.
			BcCb.emissiveColor = (emissiveColor + ambientLightColor * diffuse) * alphaVector;
			BcCb.specularColorAndPower = GetSpecularColorAndPower();
		}
		else
		{
			BcCb.activeFlg.x = 0;
			// Merge diffuse and emissive light contributions.
			diffuse += emissiveColor;
			BcCb.specularColorAndPower = GetSpecularColorAndPower();
		}
		// xyz = diffuse * alpha, w = alpha.
		BcCb.diffuseColor = XMVectorSelect(alphaVector, diffuse * alphaVector, g_XMSelect1110);

		//�e�p
		if (shadowUse) {
			Vector3 CalcLightDir = -1.0 * StageLight.m_Directional;
			Vector3 LightAt = CameraPtr->GetAt();
			Vector3 LightEye = CalcLightDir;
			LightEye *= Shadowmap::GetLightHeight();
			LightEye = LightAt + LightEye;
			Vector4 LightEye4 = LightEye;
			LightEye4.w = 1.0f;
			BcCb.lightPos = LightEye4;
			Vector4 eyePos4 = CameraPtr->GetEye();
			eyePos4.w = 1.0f;
			BcCb.eyePos = eyePos4;
			Matrix4X4 LightView, LightProj;
			//���C�g�̃r���[�Ǝˉe���v�Z
			LightView.LookAtLH(LightEye, LightAt, Vector3(0, 1.0f, 0));
			LightProj.OrthographicLH(Shadowmap::GetViewWidth(), Shadowmap::GetViewHeight(),
				Shadowmap::GetLightNear(), Shadowmap::GetLightFar());
			BcCb.lightView = Matrix4X4EX::Transpose(LightView);
			BcCb.lightProjection = Matrix4X4EX::Transpose(LightProj);
		}
	}

	void BcStaticBaseDraw::SetTextureAndSampler(ID3D11DeviceContext2* pD3D11DeviceContext, const shared_ptr<TextureResource>& TexRes) {
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//�e�N�X�`���ƃT���v���[
		if (TexRes) {
			pD3D11DeviceContext->PSSetShaderResources(0, 1, TexRes->GetShaderResourceView().GetAddressOf());
			//�T���v���[�͐ݒ�ɔC����
			SetDeviceSamplerState();
		}
		else {
			//�V�F�[�_�[���\�[�X���N���A
			pD3D11DeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pNull);
			//�T���v���[���N���A
			pD3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
		}
	}

	void BcStaticBaseDraw::SetTextureAndSamplerWithTangent(ID3D11DeviceContext2* pD3D11DeviceContext, bool IsOwnShadow,
		const shared_ptr<TextureResource>& TexRes,
		const shared_ptr<TextureResource>& NormalTexRes) {
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//�e�N�X�`���ƃT���v���[
		//�e�t�������ŃZ�b�g����ʒu���Ⴄ
		if (IsOwnShadow) {
			if (TexRes) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, TexRes->GetShaderResourceView().GetAddressOf());
				//�T���v���[�͐ݒ�ɔC����
				SetDeviceSamplerState();
			}
			else {
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
			}
			//�@���}�b�v
			//�Q�Ԗڂɓ����
			pD3D11DeviceContext->PSSetShaderResources(2, 1, NormalTexRes->GetShaderResourceView().GetAddressOf());
		}
		else {
			if (TexRes) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, TexRes->GetShaderResourceView().GetAddressOf());
				//�T���v���[�͐ݒ�ɔC����
				SetDeviceSamplerState();
			}
			else {
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
			}
			//�@���}�b�v
			//1�Ԗڂɓ����
			pD3D11DeviceContext->PSSetShaderResources(1, 1, NormalTexRes->GetShaderResourceView().GetAddressOf());
		}


	}




	//--------------------------------------------------------------------------------------
	//	BcPCStaticDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPCStaticDraw::Impl {
		Impl()
		{}
	};


	//--------------------------------------------------------------------------------------
	///	BcPCStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPCStaticDraw::BcPCStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcStaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPCStaticDraw::~BcPCStaticDraw() {}

	void BcPCStaticDraw::OnCreate() {
		SetLightingEnabled(false);
	}

	void BcPCStaticDraw::OnDraw() {
		DrawStaticNoLight<BcVSPCStatic, BcPSPCStatic>();
	}


	//--------------------------------------------------------------------------------------
	//	BcPTStaticDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPTStaticDraw::Impl {
		Impl() 
		{}
	};


	//--------------------------------------------------------------------------------------
	///	BcPTStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPTStaticDraw::BcPTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcStaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPTStaticDraw::~BcPTStaticDraw() {}

	void BcPTStaticDraw::OnCreate() {
		SetLightingEnabled(false);
	}

	void BcPTStaticDraw::OnDraw() {
		DrawStaticNoLight<BcVSPTStatic, BcPSPTStatic>();
	}

	//--------------------------------------------------------------------------------------
	//	BcPCTStaticDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPCTStaticDraw::Impl {
		Impl()
		{}
	};


	//--------------------------------------------------------------------------------------
	///	BasicPCT�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPCTStaticDraw::BcPCTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcStaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPCTStaticDraw::~BcPCTStaticDraw() {}

	void BcPCTStaticDraw::OnCreate() {
		SetLightingEnabled(false);
	}

	void BcPCTStaticDraw::OnDraw() {
		DrawStaticNoLight<BcVSPCTStatic, BcPSPTStatic>();
	}

	//--------------------------------------------------------------------------------------
	//	BcPNTStaticDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTStaticDraw::Impl {
		bool m_OwnShadowActive;
		Impl():
			m_OwnShadowActive(false)
		{}
	};
	//--------------------------------------------------------------------------------------
	///	BasicPNT�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPNTStaticDraw::BcPNTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcStaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTStaticDraw::~BcPNTStaticDraw() {}


	bool BcPNTStaticDraw::GetOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	bool BcPNTStaticDraw::IsOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	void BcPNTStaticDraw::SetOwnShadowActive(bool b) {
		pImpl->m_OwnShadowActive = b;
	}

	void BcPNTStaticDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTStaticDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTStaticDraw::OnDraw()"
			);
		}
		auto shTex = GetTextureResource();
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//���C�g��ݒ�
		SetLightingParamaters();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}
		if (shTex) {
			//�e�N�X�`��������
			BcCb.activeFlg.y = 1;
		}
		else {
			//�e�N�X�`�����Ȃ�
			BcCb.activeFlg.y = 0;
		}
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);

		//�V�F�[�_�̐ݒ�
		if (IsPerPixelLighting()) {
			//�s�N�Z�����C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPL::GetPtr()->GetShader(), nullptr, 0);
			}
		}
		else {
			//���_���C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVL::GetPtr()->GetShader(), nullptr, 0);
			}
		}

		//�e�N�X�`���ƃT���v���[
		SetTextureAndSampler(pD3D11DeviceContext, shTex);

		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		//���������Ȃ�
		if (GetGameObject()->GetAlphaActive()) {
			//�u�����h�X�e�[�g
			//��������
			if (GetBlendState() == BlendState::Additive) {
				pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
			}
			else {
				pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
			}
			//���X�^���C�U�X�e�[�g(���`��)
			pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
			//���X�^���C�U�X�e�[�g�i�\�`��j
			pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
		}
		else {
			//�����������Ȃ�
			//�u�����h�X�e�[�g�͐ݒ�ɔC����
			SetDeviceBlendState();
			//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
			SetDeviceRasterizerState();
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
		}
		//��n��
		Dev->InitializeStates();

	}

	//--------------------------------------------------------------------------------------
	//	BcPNTStaticModelDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTStaticModelDraw::Impl {
		bool m_ModelDiffusePriority;
		bool m_ModelEmissivePriority;
		bool m_ModelTextureEnabled;
		Impl() :
			m_ModelDiffusePriority(true),
			m_ModelEmissivePriority(true),
			m_ModelTextureEnabled(true)
		{}
	};


	//--------------------------------------------------------------------------------------
	///	BasicPNT���f���`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPNTStaticModelDraw::BcPNTStaticModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcPNTStaticDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTStaticModelDraw::~BcPNTStaticModelDraw() {}


	bool BcPNTStaticModelDraw::GetModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	bool BcPNTStaticModelDraw::IsModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	void BcPNTStaticModelDraw::SetModelDiffusePriority(bool b) {
		pImpl->m_ModelDiffusePriority = b;
	}
	bool BcPNTStaticModelDraw::GetModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	bool BcPNTStaticModelDraw::IsModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	void BcPNTStaticModelDraw::SetModelEmissivePriority(bool b) {
		pImpl->m_ModelEmissivePriority = b;
	}


	bool BcPNTStaticModelDraw::GetModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;

	}
	bool BcPNTStaticModelDraw::IsModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;
	}
	void BcPNTStaticModelDraw::SeModelTextureEnabled(bool b) {
		pImpl->m_ModelTextureEnabled = b;
	}




	void BcPNTStaticModelDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTStaticModelDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTStaticModelDraw::OnDraw()"
			);
		}
		//���C�g��ݒ�
		SetLightingParamaters();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}



		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//�V�F�[�_�̐ݒ�
		if (IsPerPixelLighting()) {
			//�s�N�Z�����C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticPL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticPL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPL::GetPtr()->GetShader(), nullptr, 0);
			}
		}
		else {
			//���_���C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTStaticVL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTStaticVL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVL::GetPtr()->GetShader(), nullptr, 0);
			}
		}
		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		//������}�e���A�����Ƃ̕`��
		auto& MatVec = MeshRes->GetMaterialExVec();
		for (auto& m : MatVec) {
			if (m.m_TextureResource && IsModelTextureEnabled()) {
				//�e�N�X�`��������e�N�X�`�����L���ł���
				BcCb.activeFlg.y = 1;
			}
			else {
				//�e�N�X�`�����Ȃ�
				BcCb.activeFlg.y = 0;
			}
			if (IsModelDiffusePriority()) {
				BcCb.diffuseColor = m.m_Diffuse;
			}
			if (IsModelEmissivePriority()) {
				Color4 Em4 = m.m_Emissive;
				Em4.w = 0.0f;
				BcCb.emissiveColor = Em4;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�e�N�X�`���ƃT���v���[
			SetTextureAndSampler(pD3D11DeviceContext, m.m_TextureResource);
			//���������Ȃ�
			if (GetGameObject()->GetAlphaActive()) {
				//�u�����h�X�e�[�g
				//��������
				if (GetBlendState() == BlendState::Additive) {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
				}
				else {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
				}
				//���X�^���C�U�X�e�[�g(���`��)
				pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
				//���X�^���C�U�X�e�[�g�i�\�`��j
				pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
			else {
				//�����������Ȃ�
				//�u�����h�X�e�[�g�͐ݒ�ɔC����
				SetDeviceBlendState();
				//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
				SetDeviceRasterizerState();
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
		}
		//��n��
		Dev->InitializeStates();
	}


	//--------------------------------------------------------------------------------------
	//	BcPNTBoneModelDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTBoneModelDraw::Impl {
		vector<Matrix4X4> m_LocalBonesMatrix;
		map<wstring, AnimationData> m_AnimationMap;
		wstring m_CurrentAnimeName;
		float m_CurrentAnimeTime;
		Impl() :
			m_CurrentAnimeName(L""),
			m_CurrentAnimeTime(0)
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	///	BcPNTBoneModelDraw�`��R���|�[�l���g�i�{�[�����f���`��p�j
	//--------------------------------------------------------------------------------------
	BcPNTBoneModelDraw::BcPNTBoneModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcPNTStaticModelDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTBoneModelDraw::~BcPNTBoneModelDraw() {}


	void BcPNTBoneModelDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0) {
			throw BaseException(
				L"���b�V�����{�[�����b�V���ł͂���܂���",
				L"if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0)",
				L"BcPNTBoneModelDraw::SetMeshResource()"
			);

		}
		//�擪�̃{�[�����̍s��ŏ�����
		pImpl->m_LocalBonesMatrix.resize(MeshRes->GetBoneCount());
		auto& SampleMatrixVec = MeshRes->GetSampleMatrixVec();
		for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
			pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[i];
		}
		BcStaticBaseDraw::SetMeshResource(MeshRes);
	}

	void BcPNTBoneModelDraw::SetMeshResource(const wstring& MeshKey) {
		BcPNTBoneModelDraw::SetMeshResource(App::GetApp()->GetResource<MeshResource>(MeshKey));
	}



	void BcPNTBoneModelDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTBoneModelDraw::AddAnimation(const wstring& Name, int StartSample, int SampleLength, bool Loop,
		float SamplesParSecond) {
		if (Name == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (Name == L\"\")",
				L"BcPNTBoneModelDraw::AddAnimation()"
			);
		}
		if (StartSample < 0 || SampleLength < 0) {
			throw BaseException(
				L"�J�n�T���v�����T���v������0�����ł�",
				L"if (StartSample < 0 || SampleLength < 0)",
				L"BcPNTBoneModelDraw::AddAnimation()"
			);
		}
		if (SamplesParSecond <= 0.0f) {
			throw BaseException(
				L"�T���v�����b��0�ȉ��ł�",
				L"if (SamplesParSecond <= 0.0f)",
				L"BcPNTBoneModelDraw::AddAnimation()"
			);
		}
		//�d���L�[������΍����ւ���
		AnimationData Data((UINT)StartSample, (UINT)SampleLength, Loop, SamplesParSecond);
		pImpl->m_AnimationMap[Name] = Data;
		if (pImpl->m_AnimationMap.size() == 1) {
			//1�����o�^���Ȃ�������A�J�����g�A�j���͊Y���A�j���ƂȂ�
			ChangeCurrentAnimation(Name, 0);
		}


	}

	void BcPNTBoneModelDraw::ChangeCurrentAnimation(const wstring& AnemationName, float StartTime) {
		if (AnemationName == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (AnemationName == L\"\")",
				L"BcPNTBoneModelDraw::SetCurrentAnimation()"
			);
		}
		auto it = pImpl->m_AnimationMap.find(AnemationName);
		if (it != pImpl->m_AnimationMap.end()) {
			//�w��̖��O����������
			pImpl->m_CurrentAnimeName = AnemationName;
			pImpl->m_CurrentAnimeTime = StartTime;
			//�A�j���[�V�����͏I�����Ă��Ȃ�
			it->second.m_IsAnimeEnd = false;
		}
		else {
			//������Ȃ�
			throw BaseException(
				L"�w��̃A�j���[�V�����͓o�^����Ă܂���",
				AnemationName,
				L"BcPNTBoneModelDraw::SetCurrentAnimation()"
			);
		}
	}

	const wstring& BcPNTBoneModelDraw::GetCurrentAnimation() const {
		return pImpl->m_CurrentAnimeName;
	}

	bool BcPNTBoneModelDraw::UpdateAnimation(float ElapsedTime) {
		if (ElapsedTime < 0.0f) {
			throw BaseException(
				L"�A�j���[�V�����X�V�Ƀ}�C�i�X�͐ݒ�ł��܂���",
				L"if (ElapsedTime < 0.0f)",
				L"BcPNTBoneModelDraw::UpdateAnimation()"
			);
		}
		if (pImpl->m_CurrentAnimeName == L"") {
			//������Ȃ�
			throw BaseException(
				L"�J�����g�A�j���[�V�������ݒ肳��Ă܂���",
				L"if (pImpl->m_CurrentAnimeName == L\"\")",
				L"BcPNTBoneModelDraw::UpdateAnimation()"
			);
		}
		auto PtrMesh = GetMeshResource();
		UINT SampleCount = PtrMesh->GetSampleCount();
		auto& SampleMatrixVec = PtrMesh->GetSampleMatrixVec();
		UINT BoneCount = PtrMesh->GetBoneCount();
		auto& TgtAnimeData = pImpl->m_AnimationMap[pImpl->m_CurrentAnimeName];
		if (TgtAnimeData.m_StartSample >= SampleCount) {
			//�X�^�[�g�̃T���v�����Ō�̃T���v���ȍ~������
			TgtAnimeData.m_StartSample = SampleCount - 1;
			TgtAnimeData.m_SampleLength = 0;
			UINT UITgtSample = TgtAnimeData.m_StartSample;
			//�Ō�̃T���v����\��
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[BoneCount * UITgtSample + i];
			}
			pImpl->m_CurrentAnimeTime = 0;
			if (TgtAnimeData.m_IsLoop) {
				TgtAnimeData.m_IsAnimeEnd = false;
				return false;
			}
			else {
				TgtAnimeData.m_IsAnimeEnd = true;
				return true;
			}
		}
		//���łɃA�j�����I�����Ă���
		if (TgtAnimeData.m_IsAnimeEnd) {
			//���݂̃��[�J���s����g�p
			return true;
		}
		//�J�����g�^�C�����X�V
		pImpl->m_CurrentAnimeTime += ElapsedTime;
		//�X�^�[�g�ʒu���v�Z
		auto FLOATTgtSample = (float)TgtAnimeData.m_StartSample + pImpl->m_CurrentAnimeTime * TgtAnimeData.m_SamplesParSecond;
		UINT UITgtSample = (UINT)FLOATTgtSample;
		UINT UILastSample = TgtAnimeData.m_StartSample + TgtAnimeData.m_SampleLength;
		if (UILastSample >= SampleCount) {
			UILastSample = SampleCount - 1;
		}
		if (UITgtSample >= UILastSample) {
			UITgtSample = UILastSample - 1;
			//�Ō�̃T���v����\��
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[BoneCount * UITgtSample + i];
			}
			if (TgtAnimeData.m_IsLoop) {
				TgtAnimeData.m_IsAnimeEnd = false;
				//���[�v����̂ŃJ�����g�^�C����0�ɂ���
				pImpl->m_CurrentAnimeTime = 0;
				return false;
			}
			else {
				pImpl->m_CurrentAnimeTime = TgtAnimeData.m_SampleLength / TgtAnimeData.m_SamplesParSecond;
				TgtAnimeData.m_IsAnimeEnd = true;
				return true;
			}
		}
		else {
			//�T���v���ƃT���v���̊Ԃ̊������v�Z
			FLOATTgtSample -= (float)UITgtSample;
			UINT UINextSample = UITgtSample + 1;
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				InterpolationMatrix(
					SampleMatrixVec[BoneCount * UITgtSample + i],
					SampleMatrixVec[BoneCount * UINextSample + i],
					FLOATTgtSample, pImpl->m_LocalBonesMatrix[i]);
			}
			//�A�j���͏I����ĂȂ�
			return false;
		}
	}


	void BcPNTBoneModelDraw::InterpolationMatrix(const Matrix4X4& m1, const Matrix4X4& m2, float t, Matrix4X4& out) {
		Vector3 Scale1, Pos1;
		Quaternion Qt1;
		m1.Decompose(Scale1, Qt1, Pos1);
		Qt1.Normalize();

		Vector3 Scale2, Pos2;
		Quaternion Qt2;

		m2.Decompose(Scale2, Qt2, Pos2);
		Qt2.Normalize();

		Vector3 ScaleOut, PosOut;
		Quaternion QtOut;

		ScaleOut = Lerp::CalculateLerp(Scale1, Scale2, 0.0f, 1.0f, t, Lerp::Linear);
		PosOut = Lerp::CalculateLerp(Pos1, Pos2, 0.0f, 1.0f, t, Lerp::Linear);
		QtOut = QuaternionEX::Slerp(Qt1, Qt2, t);
		out.DefTransformation(ScaleOut, QtOut, PosOut);
	}


	const vector< Matrix4X4 >* BcPNTBoneModelDraw::GetVecLocalBonesPtr() const {
		return &pImpl->m_LocalBonesMatrix;
	}


	void BcPNTBoneModelDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTStaticModelDraw::OnDraw()"
			);
		}
		//���C�g��ݒ�
		SetLightingParamaters();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}

		//�{�[���̐ݒ�
		size_t BoneSz = pImpl->m_LocalBonesMatrix.size();
		UINT cb_count = 0;
		for (size_t b = 0; b < BoneSz; b++) {
			Matrix4X4 mat = pImpl->m_LocalBonesMatrix[b];
			mat.Transpose();
			BcCb.bones[cb_count] = ((XMMATRIX)mat).r[0];
			BcCb.bones[cb_count + 1] = ((XMMATRIX)mat).r[1];
			BcCb.bones[cb_count + 2] = ((XMMATRIX)mat).r[2];
			cb_count += 3;
		}


		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//�V�F�[�_�̐ݒ�
		if (IsPerPixelLighting()) {
			//�s�N�Z�����C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTBonePLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBonePLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTBonePLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBonePLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTBonePLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBonePLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTBonePL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBonePL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTPL::GetPtr()->GetShader(), nullptr, 0);
			}
		}
		else {
			//���_���C�e�B���O
			if (IsOwnShadowActive()) {
				//�e�t��
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTBoneVLBnShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBoneVLBnShadow::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTBoneVLShadow::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBoneVLShadow::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVLShadow::GetPtr()->GetShader(), nullptr, 0);
			}
			else {
				//�e����
				if (IsBiasedNormals()) {
					//�o�C�A�X�t��
					pD3D11DeviceContext->VSSetShader(BcVSPNTBoneVLBn::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBoneVLBn::GetPtr()->GetInputLayout());
				}
				else {
					//�o�C�A�X����
					pD3D11DeviceContext->VSSetShader(BcVSPNTBoneVL::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̐ݒ�
					pD3D11DeviceContext->IASetInputLayout(BcVSPNTBoneVL::GetPtr()->GetInputLayout());
				}
				pD3D11DeviceContext->PSSetShader(BcPSPNTVL::GetPtr()->GetShader(), nullptr, 0);
			}
		}
		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();

		//������}�e���A�����Ƃ̕`��
		auto& MatVec = MeshRes->GetMaterialExVec();
		for (auto& m : MatVec) {
			if (m.m_TextureResource && IsModelTextureEnabled()) {
				//�e�N�X�`��������e�N�X�`�����L���ł���
				BcCb.activeFlg.y = 1;
			}
			else {
				//�e�N�X�`�����Ȃ�
				BcCb.activeFlg.y = 0;
			}
			if (IsModelDiffusePriority()) {
				BcCb.diffuseColor = m.m_Diffuse;
			}
			if (IsModelEmissivePriority()) {
				Color4 Em4 = m.m_Emissive;
				Em4.w = 0.0f;
				BcCb.emissiveColor = Em4;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�e�N�X�`���ƃT���v���[
			SetTextureAndSampler(pD3D11DeviceContext, m.m_TextureResource);
			//���������Ȃ�
			if (GetGameObject()->GetAlphaActive()) {
				//�u�����h�X�e�[�g
				//��������
				if (GetBlendState() == BlendState::Additive) {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
				}
				else {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
				}
				//���X�^���C�U�X�e�[�g(���`��)
				pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
				//���X�^���C�U�X�e�[�g�i�\�`��j
				pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
			else {
				//�����������Ȃ�
				//�u�����h�X�e�[�g�͐ݒ�ɔC����
				SetDeviceBlendState();
				//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
				SetDeviceRasterizerState();
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
		}
		//��n��
		Dev->InitializeStates();
	}



	//--------------------------------------------------------------------------------------
	//	BcPNTnTStaticDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTnTStaticDraw::Impl {
		//NormalMap�e�N�X�`��
		weak_ptr<TextureResource> m_NormalMapTextureResource;

		bool m_OwnShadowActive;
		Impl() :
			m_OwnShadowActive(false)
		{}
	};
	//--------------------------------------------------------------------------------------
	///	BasicPNT�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPNTnTStaticDraw::BcPNTnTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcStaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTnTStaticDraw::~BcPNTnTStaticDraw() {}


	bool BcPNTnTStaticDraw::GetOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	bool BcPNTnTStaticDraw::IsOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	void BcPNTnTStaticDraw::SetOwnShadowActive(bool b) {
		pImpl->m_OwnShadowActive = b;
	}

	shared_ptr<TextureResource> BcPNTnTStaticDraw::GetNormalMapTextureResource() const {
		auto shptr = pImpl->m_NormalMapTextureResource.lock();
		if (shptr) {
			return shptr;
		}
		return nullptr;
	}
	void BcPNTnTStaticDraw::SetNormalMapTextureResource(const shared_ptr<TextureResource>& TextureRes) {
		pImpl->m_NormalMapTextureResource = TextureRes;

	}
	void BcPNTnTStaticDraw::SetNormalMapTextureResource(const wstring& TextureKey) {
		pImpl->m_NormalMapTextureResource = App::GetApp()->GetResource<TextureResource>(TextureKey);
	}



	void BcPNTnTStaticDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTnTStaticDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTnTStaticDraw::OnDraw()"
			);
		}
		auto shNormalTex = GetNormalMapTextureResource();
		if (!shNormalTex) {
			throw BaseException(
				L"�@���}�b�v�̃e�N�X�`��������܂���",
				L"if (!shNormalTex)",
				L"BcPNTnTStaticDraw::OnDraw()"
			);
		}

		auto shTex = GetTextureResource();

		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//���C�g��ݒ�
		SetLightingParamaters();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}
		if (shTex) {
			//�e�N�X�`��������
			BcCb.activeFlg.y = 1;
		}
		else {
			//�e�N�X�`�����Ȃ�
			BcCb.activeFlg.y = 0;
		}
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);

		//�V�F�[�_�̐ݒ�
		//�s�N�Z�����C�e�B���O�̂�
		if (IsOwnShadowActive()) {
			//�e�t��
			//�o�C�A�X����
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTStaticPLShadow::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTStaticPLShadow::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPLShadow::GetPtr()->GetShader(), nullptr, 0);
		}
		else {
			//�e����
			//�o�C�A�X����
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTStaticPL::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTStaticPL::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPL::GetPtr()->GetShader(), nullptr, 0);
		}
		//�e�N�X�`���ƃT���v���[
		SetTextureAndSamplerWithTangent(pD3D11DeviceContext, IsOwnShadowActive(), shTex, shNormalTex);
		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			//���1�Ԗ�
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}


		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		//���������Ȃ�
		if (GetGameObject()->GetAlphaActive()) {
			//�u�����h�X�e�[�g
			//��������
			if (GetBlendState() == BlendState::Additive) {
				pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
			}
			else {
				pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
			}
			//���X�^���C�U�X�e�[�g(���`��)
			pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
			//���X�^���C�U�X�e�[�g�i�\�`��j
			pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
		}
		else {
			//�����������Ȃ�
			//�u�����h�X�e�[�g�͐ݒ�ɔC����
			SetDeviceBlendState();
			//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
			SetDeviceRasterizerState();
			//�`��
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
		}
		//��n��
		Dev->InitializeStates();

	}


	//--------------------------------------------------------------------------------------
	//	BcPNTnTStaticModelDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTnTStaticModelDraw::Impl {
		bool m_ModelDiffusePriority;
		bool m_ModelEmissivePriority;
		bool m_ModelTextureEnabled;
		Impl() :
			m_ModelDiffusePriority(true),
			m_ModelEmissivePriority(true),
			m_ModelTextureEnabled(true)
		{}
	};


	//--------------------------------------------------------------------------------------
	///	BasicPNTnT���f���`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	BcPNTnTStaticModelDraw::BcPNTnTStaticModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcPNTnTStaticDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTnTStaticModelDraw::~BcPNTnTStaticModelDraw() {}


	bool BcPNTnTStaticModelDraw::GetModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	bool BcPNTnTStaticModelDraw::IsModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	void BcPNTnTStaticModelDraw::SetModelDiffusePriority(bool b) {
		pImpl->m_ModelDiffusePriority = b;
	}
	bool BcPNTnTStaticModelDraw::GetModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	bool BcPNTnTStaticModelDraw::IsModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	void BcPNTnTStaticModelDraw::SetModelEmissivePriority(bool b) {
		pImpl->m_ModelEmissivePriority = b;
	}


	bool BcPNTnTStaticModelDraw::GetModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;

	}
	bool BcPNTnTStaticModelDraw::IsModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;
	}
	void BcPNTnTStaticModelDraw::SeModelTextureEnabled(bool b) {
		pImpl->m_ModelTextureEnabled = b;
	}




	void BcPNTnTStaticModelDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTnTStaticModelDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTStaticModelDraw::OnDraw()"
			);
		}
		auto shNormalTex = GetNormalMapTextureResource();
		if (!shNormalTex) {
			throw BaseException(
				L"�@���}�b�v�̃e�N�X�`��������܂���",
				L"if (!shNormalTex)",
				L"BcPNTnTStaticModelDraw::OnDraw()"
			);
		}


		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//���C�g��ݒ�
		SetLightingParamaters();
		//�V�F�[�_�̐ݒ�
		//�s�N�Z�����C�e�B���O�̂�
		if (IsOwnShadowActive()) {
			//�e�t��
			//�o�C�A�X�����̂�
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTStaticPLShadow::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTStaticPLShadow::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPLShadow::GetPtr()->GetShader(), nullptr, 0);
		}
		else {
			//�e����
			//�o�C�A�X�����̂�
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTStaticPL::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTStaticPL::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPL::GetPtr()->GetShader(), nullptr, 0);
		}

		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();

		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}

		//������}�e���A�����Ƃ̕`��
		auto& MatVec = MeshRes->GetMaterialExVec();
		for (auto& m : MatVec) {
			if (m.m_TextureResource && IsModelTextureEnabled()) {
				//�e�N�X�`��������e�N�X�`�����L���ł���
				BcCb.activeFlg.y = 1;
			}
			else {
				//�e�N�X�`�����Ȃ�
				BcCb.activeFlg.y = 0;
			}
			if (IsModelDiffusePriority()) {
				BcCb.diffuseColor = m.m_Diffuse;
			}
			if (IsModelEmissivePriority()) {
				Color4 Em4 = m.m_Emissive;
				Em4.w = 0.0f;
				BcCb.emissiveColor = Em4;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�e�N�X�`���ƃT���v���[
			SetTextureAndSamplerWithTangent(pD3D11DeviceContext, IsOwnShadowActive(), m.m_TextureResource, shNormalTex);
			//���������Ȃ�
			if (GetGameObject()->GetAlphaActive()) {
				//�u�����h�X�e�[�g
				//��������
				if (GetBlendState() == BlendState::Additive) {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
				}
				else {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
				}
				//���X�^���C�U�X�e�[�g(���`��)
				pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
				//���X�^���C�U�X�e�[�g�i�\�`��j
				pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
			else {
				//�����������Ȃ�
				//�u�����h�X�e�[�g�͐ݒ�ɔC����
				SetDeviceBlendState();
				//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
				SetDeviceRasterizerState();
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
		}
		//��n��
		Dev->InitializeStates();
	}



	//--------------------------------------------------------------------------------------
	//	BcPNTnTBoneModelDraw::Impl
	//--------------------------------------------------------------------------------------
	struct BcPNTnTBoneModelDraw::Impl {
		vector<Matrix4X4> m_LocalBonesMatrix;
		map<wstring, AnimationData> m_AnimationMap;
		wstring m_CurrentAnimeName;
		float m_CurrentAnimeTime;
		Impl() :
			m_CurrentAnimeName(L""),
			m_CurrentAnimeTime(0)
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	///	BcPNTnTBoneModelDraw�`��R���|�[�l���g�i�{�[�����f���`��p�j
	//--------------------------------------------------------------------------------------
	BcPNTnTBoneModelDraw::BcPNTnTBoneModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		BcPNTnTStaticModelDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	BcPNTnTBoneModelDraw::~BcPNTnTBoneModelDraw() {}


	void BcPNTnTBoneModelDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0) {
			throw BaseException(
				L"���b�V�����{�[�����b�V���ł͂���܂���",
				L"if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0)",
				L"BcPNTnTBoneModelDraw::SetMeshResource()"
			);

		}
		//�擪�̃{�[�����̍s��ŏ�����
		pImpl->m_LocalBonesMatrix.resize(MeshRes->GetBoneCount());
		auto& SampleMatrixVec = MeshRes->GetSampleMatrixVec();
		for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
			pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[i];
		}
		BcStaticBaseDraw::SetMeshResource(MeshRes);
	}

	void BcPNTnTBoneModelDraw::SetMeshResource(const wstring& MeshKey) {
		BcPNTnTBoneModelDraw::SetMeshResource(App::GetApp()->GetResource<MeshResource>(MeshKey));
	}



	void BcPNTnTBoneModelDraw::OnCreate() {
		SetLightingEnabled(true);
		//�}���`���C�g�̐ݒ�
		for (int i = 0; i < GetMaxDirectionalLights(); i++) {
			SetLightEnabled(i, true);
		}
	}

	void BcPNTnTBoneModelDraw::AddAnimation(const wstring& Name, int StartSample, int SampleLength, bool Loop,
		float SamplesParSecond) {
		if (Name == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (Name == L\"\")",
				L"BcPNTnTBoneModelDraw::AddAnimation()"
			);
		}
		if (StartSample < 0 || SampleLength < 0) {
			throw BaseException(
				L"�J�n�T���v�����T���v������0�����ł�",
				L"if (StartSample < 0 || SampleLength < 0)",
				L"BcPNTnTBoneModelDraw::AddAnimation()"
			);
		}
		if (SamplesParSecond <= 0.0f) {
			throw BaseException(
				L"�T���v�����b��0�ȉ��ł�",
				L"if (SamplesParSecond <= 0.0f)",
				L"BcPNTnTBoneModelDraw::AddAnimation()"
			);
		}
		//�d���L�[������΍����ւ���
		AnimationData Data((UINT)StartSample, (UINT)SampleLength, Loop, SamplesParSecond);
		pImpl->m_AnimationMap[Name] = Data;
		if (pImpl->m_AnimationMap.size() == 1) {
			//1�����o�^���Ȃ�������A�J�����g�A�j���͊Y���A�j���ƂȂ�
			ChangeCurrentAnimation(Name, 0);
		}
	}

	void BcPNTnTBoneModelDraw::ChangeCurrentAnimation(const wstring& AnemationName, float StartTime) {
		if (AnemationName == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (AnemationName == L\"\")",
				L"BcPNTnTBoneModelDraw::SetCurrentAnimation()"
			);
		}
		auto it = pImpl->m_AnimationMap.find(AnemationName);
		if (it != pImpl->m_AnimationMap.end()) {
			//�w��̖��O����������
			pImpl->m_CurrentAnimeName = AnemationName;
			pImpl->m_CurrentAnimeTime = StartTime;
			//�A�j���[�V�����͏I�����Ă��Ȃ�
			it->second.m_IsAnimeEnd = false;
		}
		else {
			//������Ȃ�
			throw BaseException(
				L"�w��̃A�j���[�V�����͓o�^����Ă܂���",
				AnemationName,
				L"BcPNTnTBoneModelDraw::SetCurrentAnimation()"
			);
		}
	}

	const wstring& BcPNTnTBoneModelDraw::GetCurrentAnimation() const {
		return pImpl->m_CurrentAnimeName;
	}

	bool BcPNTnTBoneModelDraw::UpdateAnimation(float ElapsedTime) {
		if (ElapsedTime < 0.0f) {
			throw BaseException(
				L"�A�j���[�V�����X�V�Ƀ}�C�i�X�͐ݒ�ł��܂���",
				L"if (ElapsedTime < 0.0f)",
				L"BcPNTnTBoneModelDraw::UpdateAnimation()"
			);
		}
		if (pImpl->m_CurrentAnimeName == L"") {
			//������Ȃ�
			throw BaseException(
				L"�J�����g�A�j���[�V�������ݒ肳��Ă܂���",
				L"if (pImpl->m_CurrentAnimeName == L\"\")",
				L"BcPNTnTBoneModelDraw::UpdateAnimation()"
			);
		}
		auto PtrMesh = GetMeshResource();
		UINT SampleCount = PtrMesh->GetSampleCount();
		auto& SampleMatrixVec = PtrMesh->GetSampleMatrixVec();
		UINT BoneCount = PtrMesh->GetBoneCount();
		auto& TgtAnimeData = pImpl->m_AnimationMap[pImpl->m_CurrentAnimeName];
		if (TgtAnimeData.m_StartSample >= SampleCount) {
			//�X�^�[�g�̃T���v�����Ō�̃T���v���ȍ~������
			TgtAnimeData.m_StartSample = SampleCount - 1;
			TgtAnimeData.m_SampleLength = 0;
			UINT UITgtSample = TgtAnimeData.m_StartSample;
			//�Ō�̃T���v����\��
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[BoneCount * UITgtSample + i];
			}
			pImpl->m_CurrentAnimeTime = 0;
			if (TgtAnimeData.m_IsLoop) {
				TgtAnimeData.m_IsAnimeEnd = false;
				return false;
			}
			else {
				TgtAnimeData.m_IsAnimeEnd = true;
				return true;
			}
		}
		//���łɃA�j�����I�����Ă���
		if (TgtAnimeData.m_IsAnimeEnd) {
			//���݂̃��[�J���s����g�p
			return true;
		}
		//�J�����g�^�C�����X�V
		pImpl->m_CurrentAnimeTime += ElapsedTime;
		//�X�^�[�g�ʒu���v�Z
		auto FLOATTgtSample = (float)TgtAnimeData.m_StartSample + pImpl->m_CurrentAnimeTime * TgtAnimeData.m_SamplesParSecond;
		UINT UITgtSample = (UINT)FLOATTgtSample;
		UINT UILastSample = TgtAnimeData.m_StartSample + TgtAnimeData.m_SampleLength;
		if (UILastSample >= SampleCount) {
			UILastSample = SampleCount - 1;
		}
		if (UITgtSample >= UILastSample) {
			UITgtSample = UILastSample - 1;
			//�Ō�̃T���v����\��
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[BoneCount * UITgtSample + i];
			}
			if (TgtAnimeData.m_IsLoop) {
				TgtAnimeData.m_IsAnimeEnd = false;
				//���[�v����̂ŃJ�����g�^�C����0�ɂ���
				pImpl->m_CurrentAnimeTime = 0;
				return false;
			}
			else {
				pImpl->m_CurrentAnimeTime = TgtAnimeData.m_SampleLength / TgtAnimeData.m_SamplesParSecond;
				TgtAnimeData.m_IsAnimeEnd = true;
				return true;
			}
		}
		else {
			//�T���v���ƃT���v���̊Ԃ̊������v�Z
			FLOATTgtSample -= (float)UITgtSample;
			UINT UINextSample = UITgtSample + 1;
			for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
				InterpolationMatrix(
					SampleMatrixVec[BoneCount * UITgtSample + i],
					SampleMatrixVec[BoneCount * UINextSample + i],
					FLOATTgtSample, pImpl->m_LocalBonesMatrix[i]);
			}
			//�A�j���͏I����ĂȂ�
			return false;
		}
	}


	void BcPNTnTBoneModelDraw::InterpolationMatrix(const Matrix4X4& m1, const Matrix4X4& m2, float t, Matrix4X4& out) {
		Vector3 Scale1, Pos1;
		Quaternion Qt1;
		m1.Decompose(Scale1, Qt1, Pos1);
		Qt1.Normalize();

		Vector3 Scale2, Pos2;
		Quaternion Qt2;

		m2.Decompose(Scale2, Qt2, Pos2);
		Qt2.Normalize();

		Vector3 ScaleOut, PosOut;
		Quaternion QtOut;

		ScaleOut = Lerp::CalculateLerp(Scale1, Scale2, 0.0f, 1.0f, t, Lerp::Linear);
		PosOut = Lerp::CalculateLerp(Pos1, Pos2, 0.0f, 1.0f, t, Lerp::Linear);
		QtOut = QuaternionEX::Slerp(Qt1, Qt2, t);
		out.DefTransformation(ScaleOut, QtOut, PosOut);
	}


	const vector< Matrix4X4 >* BcPNTnTBoneModelDraw::GetVecLocalBonesPtr() const {
		return &pImpl->m_LocalBonesMatrix;
	}


	void BcPNTnTBoneModelDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto MeshRes = GetMeshResource();
		if (!MeshRes) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!MeshRes)",
				L"BcPNTnTBoneModelDraw::OnDraw()"
			);
		}
		auto shNormalTex = GetNormalMapTextureResource();
		if (!shNormalTex) {
			throw BaseException(
				L"�@���}�b�v�̃e�N�X�`��������܂���",
				L"if (!shNormalTex)",
				L"BcPNTnTBoneModelDraw::OnDraw()"
			);
		}


		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		//���C�g��ݒ�
		SetLightingParamaters();
		//�V�F�[�_�̐ݒ�
		//�s�N�Z�����C�e�B���O�̂�
		if (IsOwnShadowActive()) {
			//�e�t��
			//�o�C�A�X�����̂�
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTBonePLShadow::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTBonePLShadow::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPLShadow::GetPtr()->GetShader(), nullptr, 0);
		}
		else {
			//�e����
			//�o�C�A�X�����̂�
			pD3D11DeviceContext->VSSetShader(BcVSPNTnTBonePL::GetPtr()->GetShader(), nullptr, 0);
			//�C���v�b�g���C�A�E�g�̐ݒ�
			pD3D11DeviceContext->IASetInputLayout(BcVSPNTnTBonePL::GetPtr()->GetInputLayout());
			pD3D11DeviceContext->PSSetShader(BcPSPNTnTPL::GetPtr()->GetShader(), nullptr, 0);
		}

		//�e�ƃT���v���[
		if (IsOwnShadowActive()) {
			//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
			auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
			ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
			pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
			//�V���h�E�}�b�v�T���v���[
			ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
			pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		}

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();

		//�R���X�^���g�o�b�t�@�̐ݒ�
		BasicConstants BcCb;
		ZeroMemory(&BcCb, sizeof(BcCb));
		if (IsOwnShadowActive()) {
			SetConstants(BcCb, true);
		}
		else {
			SetConstants(BcCb);
		}

		//������}�e���A�����Ƃ̕`��
		auto& MatVec = MeshRes->GetMaterialExVec();
		for (auto& m : MatVec) {
			if (m.m_TextureResource && IsModelTextureEnabled()) {
				//�e�N�X�`��������e�N�X�`�����L���ł���
				BcCb.activeFlg.y = 1;
			}
			else {
				//�e�N�X�`�����Ȃ�
				BcCb.activeFlg.y = 0;
			}
			if (IsModelDiffusePriority()) {
				BcCb.diffuseColor = m.m_Diffuse;
			}
			if (IsModelEmissivePriority()) {
				Color4 Em4 = m.m_Emissive;
				Em4.w = 0.0f;
				BcCb.emissiveColor = Em4;
			}
			//�{�[���̐ݒ�
			size_t BoneSz = pImpl->m_LocalBonesMatrix.size();
			UINT cb_count = 0;
			for (size_t b = 0; b < BoneSz; b++) {
				Matrix4X4 mat = pImpl->m_LocalBonesMatrix[b];
				mat.Transpose();
				BcCb.bones[cb_count] = ((XMMATRIX)mat).r[0];
				BcCb.bones[cb_count + 1] = ((XMMATRIX)mat).r[1];
				BcCb.bones[cb_count + 2] = ((XMMATRIX)mat).r[2];
				cb_count += 3;
			}

			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBBasic::GetPtr()->GetBuffer(), 0, nullptr, &BcCb, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBBasic::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�e�N�X�`���ƃT���v���[
			SetTextureAndSamplerWithTangent(pD3D11DeviceContext, IsOwnShadowActive(), m.m_TextureResource, shNormalTex);
			//���������Ȃ�
			if (GetGameObject()->GetAlphaActive()) {
				//�u�����h�X�e�[�g
				//��������
				if (GetBlendState() == BlendState::Additive) {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
				}
				else {
					pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
				}
				//���X�^���C�U�X�e�[�g(���`��)
				pD3D11DeviceContext->RSSetState(RenderState->GetCullFront());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
				//���X�^���C�U�X�e�[�g�i�\�`��j
				pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
			else {
				//�����������Ȃ�
				//�u�����h�X�e�[�g�͐ݒ�ɔC����
				SetDeviceBlendState();
				//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
				SetDeviceRasterizerState();
				//�`��
				pD3D11DeviceContext->DrawIndexed(m.m_IndexCount, m.m_StartIndex, 0);
			}
		}
		//��n��
		Dev->InitializeStates();
	}


}

//end basecross
