/*!
@file DrawComponents.cpp
@brief �`��R���|�[�l���g����
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/
#include "stdafx.h"
#include "DrawComponents.h"

namespace basecross {

	//Shadowmap
	IMPLEMENT_DX11_CONSTANT_BUFFER(CBShadow)
	IMPLEMENT_DX11_VERTEX_SHADER(VSShadowmap, App::GetApp()->GetShadersPath() + L"VSShadowmap.cso")
	IMPLEMENT_DX11_VERTEX_SHADER(VSShadowmapBone, App::GetApp()->GetShadersPath() + L"VSShadowmapBone.cso")
	IMPLEMENT_DX11_VERTEX_SHADER(VSShadowmapBoneWithTan, App::GetApp()->GetShadersPath() + L"VSShadowmapBoneWithTan.cso")

	//�X�v���C�g�p
	IMPLEMENT_DX11_CONSTANT_BUFFER(CBSprite)

	//PCSprite
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCSprite, App::GetApp()->GetShadersPath() + L"VSPCSprite.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPCSprite, App::GetApp()->GetShadersPath() + L"PSPCSprite.cso")

	//PTSprite
	IMPLEMENT_DX11_VERTEX_SHADER(VSPTSprite, App::GetApp()->GetShadersPath() + L"VSPTSprite.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPTSprite, App::GetApp()->GetShadersPath() + L"PSPTSprite.cso")

	//PCTSprite
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCTSprite, App::GetApp()->GetShadersPath() + L"VSPCTSprite.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPCTSprite, App::GetApp()->GetShadersPath() + L"PSPCTSprite.cso")


	//CBSimple
	IMPLEMENT_DX11_CONSTANT_BUFFER(CBSimple)
	//PCStatic
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCStatic, App::GetApp()->GetShadersPath() + L"VSPCStatic.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPCStatic, App::GetApp()->GetShadersPath() + L"PSPCStatic.cso")
	//PTStatic
	IMPLEMENT_DX11_VERTEX_SHADER(VSPTStatic, App::GetApp()->GetShadersPath() + L"VSPTStatic.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPTStatic, App::GetApp()->GetShadersPath() + L"PSPTStatic.cso")
	//PCTStatic
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCTStatic, App::GetApp()->GetShadersPath() + L"VSPCTStatic.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPCTStatic, App::GetApp()->GetShadersPath() + L"PSPCTStatic.cso")
	//PNTStatic
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTStatic, App::GetApp()->GetShadersPath() + L"VSPNTStatic.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPNTStatic, App::GetApp()->GetShadersPath() + L"PSPNTStatic.cso")
	//PNTStaticShadow
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTStaticShadow, App::GetApp()->GetShadersPath() + L"VSPNTStaticShadow.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPNTStaticShadow, App::GetApp()->GetShadersPath() + L"PSPNTStaticShadow.cso")
	IMPLEMENT_DX11_PIXEL_SHADER(PSPNTStaticShadow2, App::GetApp()->GetShadersPath() + L"PSPNTStaticShadow2.cso")
	//PNTBone
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTBone, App::GetApp()->GetShadersPath() + L"VSPNTBone.cso")
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTBoneShadow, App::GetApp()->GetShadersPath() + L"VSPNTBoneShadow.cso")

	//PCStaticInstance
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCStaticInstance, App::GetApp()->GetShadersPath() + L"VSPCStaticInstance.cso")
	//PTStaticInstance
	IMPLEMENT_DX11_VERTEX_SHADER(VSPTStaticInstance, App::GetApp()->GetShadersPath() + L"VSPTStaticInstance.cso")
	//PCTStaticInstance
	IMPLEMENT_DX11_VERTEX_SHADER(VSPCTStaticInstance, App::GetApp()->GetShadersPath() + L"VSPCTStaticInstance.cso")
	//PNTStaticInstance
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTStaticInstance, App::GetApp()->GetShadersPath() + L"VSPNTStaticInstance.cso")
	IMPLEMENT_DX11_VERTEX_SHADER(VSPNTStaticInstanceShadow, App::GetApp()->GetShadersPath() + L"VSPNTStaticInstanceShadow.cso")



	//--------------------------------------------------------------------------------------
	//	struct DrawComponent::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct DrawComponent::Impl {
		BlendState m_BlendState;
		DepthStencilState m_DepthStencilState;
		RasterizerState m_RasterizerState;
		SamplerState m_SamplerState;
		Matrix4X4 m_MeshToTransformMatrix;

		Impl() :
			m_MeshToTransformMatrix()
		{}
	};

	//--------------------------------------------------------------------------------------
	///	�`��R���|�[�l���g�̐e�N���X����
	//--------------------------------------------------------------------------------------
	DrawComponent::DrawComponent(const shared_ptr<GameObject>& GameObjectPtr) :
		Component(GameObjectPtr),
		pImpl(new Impl())
	{}
	DrawComponent::~DrawComponent() {}


	BlendState DrawComponent::GetBlendState() const {
		return pImpl->m_BlendState;
	}

	DepthStencilState DrawComponent::GetDepthStencilState() const {
		return pImpl->m_DepthStencilState;
	}
	RasterizerState DrawComponent::GetRasterizerState() const {
		return pImpl->m_RasterizerState;
	}
	SamplerState DrawComponent::GetSamplerState() const {
		return pImpl->m_SamplerState;
	}


	void DrawComponent::SetBlendState(const BlendState state) {
		pImpl->m_BlendState = state;
	}
	void DrawComponent::SetDeviceBlendState() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderStatePtr = Dev->GetRenderState();
		switch (GetBlendState()) {
		case BlendState::Opaque:
			pID3D11DeviceContext->OMSetBlendState(RenderStatePtr->GetOpaque(), nullptr, 0xffffffff);
			break;
		case BlendState::AlphaBlend:
			pID3D11DeviceContext->OMSetBlendState(RenderStatePtr->GetAlphaBlendEx(), nullptr, 0xffffffff);
			break;
		case BlendState::Additive:
			pID3D11DeviceContext->OMSetBlendState(RenderStatePtr->GetAdditive(), nullptr, 0xffffffff);
			break;
		case BlendState::NonPremultiplied:
			pID3D11DeviceContext->OMSetBlendState(RenderStatePtr->GetNonPremultiplied(), nullptr, 0xffffffff);
			break;
		}
	}


	void DrawComponent::SetDepthStencilState(const DepthStencilState state) {
		pImpl->m_DepthStencilState = state;

	}

	void DrawComponent::SetDeviceDepthStencilState() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderStatePtr = Dev->GetRenderState();
		switch (GetDepthStencilState()) {
		case DepthStencilState::None:
			pID3D11DeviceContext->OMSetDepthStencilState(RenderStatePtr->GetDepthNone(), 0);
			break;
		case DepthStencilState::Default:
			pID3D11DeviceContext->OMSetDepthStencilState(RenderStatePtr->GetDepthDefault(), 0);
			break;
		case DepthStencilState::Read:
			pID3D11DeviceContext->OMSetDepthStencilState(RenderStatePtr->GetDepthRead(), 0);
			break;
		}

	}

	void DrawComponent::SetRasterizerState(const RasterizerState state) {
		pImpl->m_RasterizerState = state;
	}
	void DrawComponent::SetDeviceRasterizerState() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderStatePtr = Dev->GetRenderState();
		switch (GetRasterizerState()) {
		case RasterizerState::CullBack:
			pID3D11DeviceContext->RSSetState(RenderStatePtr->GetCullBack());
			break;
		case RasterizerState::CullFront:
			pID3D11DeviceContext->RSSetState(RenderStatePtr->GetCullFront());
			break;
		case RasterizerState::CullNone:
			pID3D11DeviceContext->RSSetState(RenderStatePtr->GetCullNone());
			break;
		}
	}


	void DrawComponent::SetSamplerState(const SamplerState state) {
		pImpl->m_SamplerState = state;
	}
	void DrawComponent::SetDeviceSamplerState() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderStatePtr = Dev->GetRenderState();
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pSampler = nullptr;
		switch (GetSamplerState()) {
		case SamplerState::SamplerNone:
			//�T���v���[���N���A
			pID3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
			return;
			break;
		case SamplerState::PointWrap:
			pSampler = RenderStatePtr->GetPointWrap();
			break;
		case SamplerState::PointClamp:
			pSampler = RenderStatePtr->GetPointClamp();
			break;
		case SamplerState::LinearWrap:
			pSampler = RenderStatePtr->GetLinearWrap();
			break;
		case SamplerState::LinearClamp:
			pSampler = RenderStatePtr->GetLinearClamp();
			break;
		case SamplerState::AnisotropicWrap:
			pSampler = RenderStatePtr->GetAnisotropicWrap();
			break;
		case SamplerState::AnisotropicClamp:
			pSampler = RenderStatePtr->GetAnisotropicClamp();
			break;
		case SamplerState::ComparisonLinear:
			pSampler = RenderStatePtr->GetComparisonLinear();
			break;
		}
		//�T���v���[��ݒ�
		pID3D11DeviceContext->PSSetSamplers(0, 1, &pSampler);
	}



	const Matrix4X4& DrawComponent::GetMeshToTransformMatrix() const {
		return pImpl->m_MeshToTransformMatrix;
	}
	void DrawComponent::SetMeshToTransformMatrix(const Matrix4X4& Mat) {
		pImpl->m_MeshToTransformMatrix = Mat;
	}



	//--------------------------------------------------------------------------------------
	//	struct Shadowmap::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct Shadowmap::Impl {
		static float m_LightHeight;	//���C�g�̍����i���������̒l�Ŋ|����j
		static float m_LightNear;	//���C�g��Near
		static float m_LightFar;		//���C�g��Far
		static float m_ViewWidth;
		static float m_ViewHeight;

		weak_ptr<MeshResource> m_MeshResource;	//���b�V�����\�[�X


		Impl()
		{}
		~Impl() {}
	};

	float Shadowmap::Impl::m_LightHeight(20.0f);
	float Shadowmap::Impl::m_LightNear(1.0f);
	float Shadowmap::Impl::m_LightFar(200.0f);
	float Shadowmap::Impl::m_ViewWidth(32.0f);
	float Shadowmap::Impl::m_ViewHeight(32.0f);



	//--------------------------------------------------------------------------------------
	//	class Shadowmap : public Component;
	//	�p�r: �V���h�E�}�b�v�R���|�[�l���g�i�O�����p�j
	//--------------------------------------------------------------------------------------
	Shadowmap::Shadowmap(const shared_ptr<GameObject>& GameObjectPtr) :
		DrawComponent(GameObjectPtr),
		pImpl(new Impl())
	{}
	Shadowmap::~Shadowmap() {}

	float Shadowmap::GetLightHeight() { return Impl::m_LightHeight; }
	float Shadowmap::GetLightNear() { return  Impl::m_LightNear; }
	float Shadowmap::GetLightFar() { return  Impl::m_LightFar; }
	float Shadowmap::GetViewWidth() { return  Impl::m_ViewWidth; }
	float Shadowmap::GetViewHeight() { return  Impl::m_ViewHeight; }

	void Shadowmap::SetLightHeight(float f) { Impl::m_LightHeight = f; }
	void Shadowmap::SetLightNear(float f) { Impl::m_LightNear = f; }
	void Shadowmap::SetLightFar(float f) { Impl::m_LightFar = f; }
	void Shadowmap::SetViewWidth(float f) { Impl::m_ViewWidth = f; }
	void Shadowmap::SetViewHeight(float f) { Impl::m_ViewHeight = f; }
	void Shadowmap::SetViewSize(float f) { Impl::m_ViewWidth = Impl::m_ViewHeight = f; }



	shared_ptr<MeshResource> Shadowmap::GetMeshResource(bool ExceptionActive) const {
		if (!pImpl->m_MeshResource.expired()) {
			return pImpl->m_MeshResource.lock();
		}
		else {
			if (ExceptionActive) {
				throw BaseException(
					L"���b�V�����\�[�X��������܂���",
					L"if (pImpl->m_MeshResource.expired())",
					L"ShadowmapComp::GetMeshResource()"
				);
			}
		}
		return nullptr;
	}


	void Shadowmap::SetMeshResource(const wstring& ResKey) {
		try {
			if (ResKey == L"") {
				throw BaseException(
					L"���b�V���L�[���󔒂ł�",
					L"if (ResKey == L\"\"",
					L"ShadowmapComp::SetMeshResource()"
				);
			}
			pImpl->m_MeshResource = App::GetApp()->GetResource<MeshResource>(ResKey);
		}
		catch (...) {
			throw;
		}
	}
	void Shadowmap::SetMeshResource(const shared_ptr<MeshResource>& MeshResourcePtr) {
		pImpl->m_MeshResource = MeshResourcePtr;
	}


	void Shadowmap::OnDraw() {
		auto PtrGameObject = GetGameObject();
		auto PtrStage = PtrGameObject->GetStage();
		if (!PtrStage) {
			return;
		}
		//���b�V�����\�[�X�̎擾
		auto PtrMeshResource = GetMeshResource(false);

		if (PtrMeshResource) {


			auto Dev = App::GetApp()->GetDeviceResources();
			auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
			//�X�e�[�^�X�̃|�C���^
			auto RenderStatePtr = Dev->GetRenderState();

			//�s��̒�`
			Matrix4X4 World, LightView, LightProj;
			//�s��̒�`
			auto PtrTrans = GetGameObject()->GetComponent<Transform>();

			//���C�g�̎擾
			auto StageLight = PtrGameObject->OnGetDrawLight();
			//�ʒu�̎擾
			auto Pos = PtrTrans->GetWorldMatrix().PosInMatrixSt();
			Vector3 PosSpan = StageLight.m_Directional;
			PosSpan *= 0.1f;
			Pos += PosSpan;
			//���[���h�s��̌���
			World.AffineTransformation(
				PtrTrans->GetScale(),			//�X�P�[�����O
				PtrTrans->GetPivot(),		//��]�̒��S�i�d�S�j
				PtrTrans->GetQuaternion(),				//��]�p�x
				Pos				//�ʒu
			);
			Matrix4X4 RealWorldMatrix = GetMeshToTransformMatrix() * World;
			//�r���[�s��̌���
			auto StageView = PtrStage->GetView();
			Vector3 LightDir = -1.0 * StageLight.m_Directional;
			Vector3 LightAt = StageView->GetTargetCamera()->GetAt();
			Vector3 LightEye = LightAt + (LightDir * GetLightHeight());
			//���C�g�̃r���[�Ǝˉe���v�Z
			LightView.LookAtLH(LightEye, LightAt, Vector3(0, 1.0f, 0));
			LightProj.OrthographicLH(GetViewWidth(), GetViewHeight(), GetLightNear(), GetLightFar());

			ShadowConstants Cb;
			Cb.mWorld = Matrix4X4EX::Transpose(RealWorldMatrix);
			Cb.mView = Matrix4X4EX::Transpose(LightView);
			Cb.mProj = Matrix4X4EX::Transpose(LightProj);

			bool IsSkin = false;
			bool IsSkinStride = false;
			if (PtrMeshResource->IsSkining()) {
				auto DrawCompPtr = GetGameObject()->GetDynamicComponent<DrawComponent>(false);
				if (auto* pLocalBoneVec = DrawCompPtr->GetVecLocalBonesPtr()) {
					if (pLocalBoneVec) {
						//�{�[���̐ݒ�
						size_t BoneSz = pLocalBoneVec->size();
						UINT cb_count = 0;
						for (size_t b = 0; b < BoneSz; b++) {
							Matrix4X4 mat = pLocalBoneVec->at(b);
							mat.Transpose();
							Cb.Bones[cb_count] = ((XMMATRIX)mat).r[0];
							Cb.Bones[cb_count + 1] = ((XMMATRIX)mat).r[1];
							Cb.Bones[cb_count + 2] = ((XMMATRIX)mat).r[2];
							cb_count += 3;
						}
						IsSkin = true;
					}
				}
				IsSkinStride = true;
			}
			//������`�揈��
			//�R���X�^���g�o�b�t�@�̍X�V
			pID3D11DeviceContext->UpdateSubresource(CBShadow::GetPtr()->GetBuffer(), 0, nullptr, &Cb, 0, 0);

			if (IsSkin) {
				//�X�g���C�h�ƃI�t�Z�b�g
				UINT stride = PtrMeshResource->GetNumStride();
				UINT offset = 0;
				if (stride == sizeof(VertexPositionNormalTangentTextureSkinning)) {
					//���_�V�F�[�_�[�̃Z�b�g
					pID3D11DeviceContext->VSSetShader(VSShadowmapBoneWithTan::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̃Z�b�g
					pID3D11DeviceContext->IASetInputLayout(VSShadowmapBoneWithTan::GetPtr()->GetInputLayout());
				}
				else {
					//���_�V�F�[�_�[�̃Z�b�g
					pID3D11DeviceContext->VSSetShader(VSShadowmapBone::GetPtr()->GetShader(), nullptr, 0);
					//�C���v�b�g���C�A�E�g�̃Z�b�g
					pID3D11DeviceContext->IASetInputLayout(VSShadowmapBone::GetPtr()->GetInputLayout());
				}
				//���_�o�b�t�@���Z�b�g
				pID3D11DeviceContext->IASetVertexBuffers(0, 1, PtrMeshResource->GetVertexBuffer().GetAddressOf(), &stride, &offset);
			}
			else {
				//�C���v�b�g���C�A�E�g�̃Z�b�g
				pID3D11DeviceContext->IASetInputLayout(VSShadowmap::GetPtr()->GetInputLayout());
				//�X�g���C�h�ƃI�t�Z�b�g
				UINT stride = PtrMeshResource->GetNumStride();
				UINT offset = 0;
				//���_�o�b�t�@���Z�b�g
				pID3D11DeviceContext->IASetVertexBuffers(0, 1, PtrMeshResource->GetVertexBuffer().GetAddressOf(), &stride, &offset);
				//���_�V�F�[�_�[�̃Z�b�g
				pID3D11DeviceContext->VSSetShader(VSShadowmap::GetPtr()->GetShader(), nullptr, 0);
			}



			//�C���f�b�N�X�o�b�t�@�̃Z�b�g
			pID3D11DeviceContext->IASetIndexBuffer(PtrMeshResource->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
			//�`����@�i3�p�`�j
			pID3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

			//�s�N�Z���V�F�[�_�̓Z�b�g���Ȃ��I
			pID3D11DeviceContext->PSSetShader(nullptr, nullptr, 0);
			//�W�I���g���V�F�[�_�̐ݒ�i�g�p���Ȃ��j
			pID3D11DeviceContext->GSSetShader(nullptr, nullptr, 0);

			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBShadow::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			pID3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�R���X�^���g�o�b�t�@���s�N�Z���V�F�[�_�ɃZ�b�g
			pID3D11DeviceContext->PSSetConstantBuffers(0, 1, &pNullConstantBuffer);
			//�`��
			pID3D11DeviceContext->DrawIndexed(PtrMeshResource->GetNumIndicis(), 0, 0);
			//��n��
			Dev->InitializeStates();

		}

	}



	//--------------------------------------------------------------------------------------
	//ParticleDraw�����̂��߂̍\����
	//--------------------------------------------------------------------------------------
	struct DrawParticleSprite {
		//�p�[�e�B�N���̃J�����܂ł̋���
		float m_ToCaneraLength;
		//���[���h�s��
		Matrix4X4 m_WorldMatrix;
		//�e�N�X�`��
		shared_ptr<TextureResource> m_TextureRes;
		//Diffuse�J���[
		Color4 m_Diffuse;
		DrawParticleSprite() :
			m_ToCaneraLength(0),
			m_Diffuse(1,1,1,1)

		{}
	};



	//--------------------------------------------------------------------------------------
	//	struct PCTParticleDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct PCTParticleDraw::Impl {
		//�`��R���e�L�X�g
		shared_ptr<MeshResource> m_MeshResource;	//���b�V�����\�[�X
		vector<DrawParticleSprite> m_DrawParticleSpriteVec;
		const size_t m_MaxInstance;				///<�C���X�^���X�ő�l
		ComPtr<ID3D11Buffer> m_MatrixBuffer;	///<�s��p�̒��_�o�b�t�@
		//���Z�������邩�ǂ���
		bool m_Addtype;
		Impl(size_t MaxInstance,bool AddType) :
			m_MaxInstance(MaxInstance),
			m_Addtype(AddType)
		{}
		~Impl() {}
		//���_�o�b�t�@�̍쐬
		void CreateParticleBuffers();
	};


	void PCTParticleDraw::Impl::CreateParticleBuffers() {
		try {
			float HelfSize = 0.5f;
			Vector4 col(1.0f, 1.0f, 1.0f, 1.0f);
			//���_�z��
			vector<VertexPositionColorTexture> vertices = {
				{ VertexPositionColorTexture(Vector3(-HelfSize, HelfSize, 0),  col,Vector2(0.0f, 0.0f)) },
				{ VertexPositionColorTexture(Vector3(HelfSize, HelfSize, 0), col, Vector2(1.0f, 0.0f)) },
				{ VertexPositionColorTexture(Vector3(-HelfSize, -HelfSize, 0),  col,Vector2(0.0f, 1.0f)) },
				{ VertexPositionColorTexture(Vector3(HelfSize, -HelfSize, 0),  col, Vector2(1.0f, 1.0f)) },
			};
			//�C���f�b�N�X�z��
			vector<uint16_t> indices = { 0, 1, 2, 1, 3, 2 };
			//���b�V���̍쐬
			m_MeshResource = MeshResource::CreateMeshResource(vertices, indices, false);

			//�C���X�^���X�s��o�b�t�@�̍쐬
			//Max�l�ō쐬����
			vector<Matrix4X4> matrices(m_MaxInstance, Matrix4X4());
			MeshResource::CreateDynamicVertexBuffer(m_MatrixBuffer, matrices);

		}
		catch (...) {
			throw;
		}
	}




	//--------------------------------------------------------------------------------------
	///	PCTParticle�`��R���|�[�l���g(�p�[�e�B�N���`��)
	//--------------------------------------------------------------------------------------
	PCTParticleDraw::PCTParticleDraw(const shared_ptr<GameObject>& GameObjectPtr, size_t MaxInstance, bool AddType) :
		DrawComponent(GameObjectPtr),
		pImpl(new Impl(MaxInstance, AddType))
	{}

	PCTParticleDraw::~PCTParticleDraw() {}

	void PCTParticleDraw::AddParticle(float ToCaneraLength, const Matrix4X4& WorldMatrix,
		const shared_ptr<TextureResource>& TextureRes,const Color4& Diffuse) {
		DrawParticleSprite Item;
		Item.m_ToCaneraLength = ToCaneraLength;
		Item.m_WorldMatrix = WorldMatrix;
		Item.m_TextureRes = TextureRes;
		Item.m_Diffuse = Diffuse;
		pImpl->m_DrawParticleSpriteVec.push_back(Item);
	}

	void PCTParticleDraw::OnCreate() {
		pImpl->CreateParticleBuffers();
	}

	struct InstanceDrawStr {
		size_t Start;
		size_t Count;
		shared_ptr<TextureResource> Tex;
		Color4 m_Diffuse;
		InstanceDrawStr(size_t s, size_t c, shared_ptr<TextureResource> t,
			const Color4& Diffuse) :
			Start(s), Count(c), Tex(t), m_Diffuse(Diffuse){}
	};

	void PCTParticleDraw::OnDraw() {
		auto PtrStage = GetGameObject()->GetStage();
		if (!PtrStage) {
			return;
		}
		if (pImpl->m_DrawParticleSpriteVec.size() <= 0) {
			return;
		}

		//�J�����ʒu�Ń\�[�g
		auto func = [](DrawParticleSprite& Left, DrawParticleSprite& Right)->bool {
			return (Left.m_ToCaneraLength > Right.m_ToCaneraLength);
		};
		std::sort(pImpl->m_DrawParticleSpriteVec.begin(), pImpl->m_DrawParticleSpriteVec.end(), func);
		//�f�o�C�X�ƃR���e�L�X�g�C���^�[�t�F�C�X�̎擾
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		//�擪�̃e�N�X�`���𓾂�
		auto  NowTexPtr = pImpl->m_DrawParticleSpriteVec[0].m_TextureRes;

		vector<InstanceDrawStr> m_InstancVec;
		size_t NowStartIndex = 0;
		size_t NowDrawCount = 0;

		shared_ptr<TextureResource> NowTexRes = pImpl->m_DrawParticleSpriteVec[0].m_TextureRes;
		Color4 NowDiffuse  = Color4(1,1,1,1);
		for (size_t i = 0; i < pImpl->m_DrawParticleSpriteVec.size(); i++) {
			if (pImpl->m_DrawParticleSpriteVec[i].m_TextureRes != NowTexRes || 
				pImpl->m_DrawParticleSpriteVec[i].m_Diffuse != NowDiffuse) {
				m_InstancVec.push_back(InstanceDrawStr(NowStartIndex, NowDrawCount, NowTexRes, NowDiffuse));
				NowStartIndex = i;
				NowDrawCount = 0;
				NowTexRes = pImpl->m_DrawParticleSpriteVec[i].m_TextureRes;
				NowDiffuse = pImpl->m_DrawParticleSpriteVec[i].m_Diffuse;
			}
			else {
				NowDrawCount++;
			}
		}
		m_InstancVec.push_back(InstanceDrawStr(NowStartIndex, NowDrawCount, NowTexRes, NowDiffuse));


		//�C���X�^���X�o�b�t�@�Ƀ}�b�v
		D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
		D3D11_MAPPED_SUBRESOURCE mappedBuffer;
		//�s��̃}�b�v
		if (FAILED(pD3D11DeviceContext->Map(pImpl->m_MatrixBuffer.Get(), 0, mapType, 0, &mappedBuffer))) {
			// Map���s
			throw BaseException(
				L"�s���Map�Ɏ��s���܂����B",
				L"if(FAILED(pD3D11DeviceContext->Map()))",
				L"PCTParticleDraw::OnDraw()"
			);
		}
		//�s��̕ύX
		auto* matrices = (Matrix4X4*)mappedBuffer.pData;
		Matrix4X4 World;
		for (size_t i = 0; i < pImpl->m_DrawParticleSpriteVec.size(); i++) {
			World = pImpl->m_DrawParticleSpriteVec[i].m_WorldMatrix;
			//�]�u����
			World.Transpose();
			matrices[i] = World;
		}
		//�A���}�b�v
		pD3D11DeviceContext->Unmap(pImpl->m_MatrixBuffer.Get(), 0);
		//�X�g���C�h�ƃI�t�Z�b�g
		//�`��̒��_�o�b�t�@�ƍs��o�b�t�@��ݒ�
		UINT stride[2] = { sizeof(VertexPositionColorTexture), sizeof(Matrix4X4) };
		UINT offset[2] = { 0, 0 };

		ID3D11Buffer* pBuf[2] = { pImpl->m_MeshResource->GetVertexBuffer().Get(), pImpl->m_MatrixBuffer.Get() };
		pD3D11DeviceContext->IASetVertexBuffers(0, 2, pBuf, stride, offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(pImpl->m_MeshResource->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);

		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPCTStaticInstance::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPCTStatic::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPCTStaticInstance::GetPtr()->GetInputLayout());

		//�u�����h�X�e�[�g
		if (pImpl->m_Addtype) {
			//���Z����
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetAdditive(), nullptr, 0xffffffff);
		}
		else {
			//��������
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
		}
		//�f�v�X�X�e���V���X�e�[�g
		pD3D11DeviceContext->OMSetDepthStencilState(RenderState->GetDepthRead(), 0);
		//�e�N�X�`���ƃT���v���[�̐ݒ�
		ID3D11ShaderResourceView* pNull[1] = { 0 };
		ID3D11SamplerState* pSampler = RenderState->GetLinearClamp();
		pD3D11DeviceContext->PSSetSamplers(0, 1, &pSampler);
		//���X�^���C�U�X�e�[�g�i�\�ʕ`��j
		pD3D11DeviceContext->RSSetState(RenderState->GetCullBack());

		//�r���[�s��̌���
		Matrix4X4 View, Proj;
		//�r���[�s��̌���
		auto StageView = PtrStage->GetView();
		View = StageView->GetTargetCamera()->GetViewMatrix();
		//�]�u����
		View.Transpose();
		//�ˉe�s��̌���
		Proj = StageView->GetTargetCamera()->GetProjMatrix();
		//�]�u����
		Proj.Transpose();


		//�R���X�^���g�o�b�t�@�̏���
		SimpleConstants sb;
		sb.World = Matrix4X4();	//���[���h�s��̓_�~�[
		sb.View = View;
		sb.Projection = Proj;
		//�G�~�b�V�u���Z�͍s��Ȃ��B
		sb.Emissive = Color4(0, 0, 0, 0);
		sb.ActiveFlg.x = 1;

		for (auto& v : m_InstancVec) {
			sb.Diffuse = v.m_Diffuse;
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);

			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
			ID3D11Buffer* pNullConstantBuffer = nullptr;
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);

			pD3D11DeviceContext->PSSetShaderResources(0, 1, v.Tex->GetShaderResourceView().GetAddressOf());
			//�`��
			pD3D11DeviceContext->DrawIndexedInstanced(pImpl->m_MeshResource->GetNumIndicis(), v.Count, 0, 0, v.Start);
		}
		//��n��
		Dev->InitializeStates();
		pImpl->m_DrawParticleSpriteVec.clear();
	}

	//--------------------------------------------------------------------------------------
	//	struct TextureDrawInterface::Impl;
	//--------------------------------------------------------------------------------------
	struct TextureDrawInterface::Impl {
		//�e�N�X�`��
		weak_ptr<TextureResource> m_TextureResource;
		Impl()
		{}
	};

	//--------------------------------------------------------------------------------------
	///	�e�N�X�`���`��C���^�[�t�F�C�X
	//--------------------------------------------------------------------------------------
	TextureDrawInterface::TextureDrawInterface():
		pImpl(new Impl())
	{}

	TextureDrawInterface::~TextureDrawInterface() {}

	void TextureDrawInterface::SetTextureResource(const shared_ptr<TextureResource>& TextureRes) {
		pImpl->m_TextureResource = TextureRes;
	}

	void TextureDrawInterface::SetTextureResource(const wstring& TextureKey) {
		auto Res = App::GetApp()->GetResource<TextureResource>(TextureKey);
		pImpl->m_TextureResource = Res;
	}

	shared_ptr<TextureResource> TextureDrawInterface::GetTextureResource() const {
		//�e�N�X�`�����Ȃ����null��Ԃ�
		auto shptr = pImpl->m_TextureResource.lock();
		if (!shptr) {
			return nullptr;
		}
		return shptr;
	}

	//--------------------------------------------------------------------------------------
	//	struct SpriteBaseDraw::Impl;
	//	�p�r: SpriteBaseDraw�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct SpriteBaseDraw::Impl {
		//���b�V��
		shared_ptr<MeshResource> m_SpriteMesh;
		//�G�~�b�V�u�F
		Color4 m_Emissive;
		//�f�t���[�Y�F
		Color4 m_Diffuse;
		Impl():
			m_Emissive(0, 0, 0, 0),
			m_Diffuse(1.0f, 1.0f, 1.0f, 1.0f)
		{}
	};

	//--------------------------------------------------------------------------------------
	//	class SpriteBaseDraw : public DrawComponent;
	//--------------------------------------------------------------------------------------
	SpriteBaseDraw::SpriteBaseDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		DrawComponent(GameObjectPtr),
		pImpl(new Impl())
	{}
	SpriteBaseDraw::~SpriteBaseDraw() {}


	shared_ptr<MeshResource> SpriteBaseDraw::GetMeshResource() const {
		return pImpl->m_SpriteMesh;
	}
	void SpriteBaseDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		pImpl->m_SpriteMesh = MeshRes;
	}


	Color4 SpriteBaseDraw::GetEmissive() const {
		return pImpl->m_Emissive;
	}
	void SpriteBaseDraw::SetEmissive(const Color4& col) {
		pImpl->m_Emissive = col;
	}

	Color4 SpriteBaseDraw::GetDiffuse() const {
		return pImpl->m_Diffuse;
	}
	void SpriteBaseDraw::SetDiffuse(const Color4& col) {
		pImpl->m_Diffuse = col;
	}


	//--------------------------------------------------------------------------------------
	//	struct PCSpriteDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCSpriteDraw::Impl {
		Impl()
		{}
	};



	//--------------------------------------------------------------------------------------
	///	PCSprite�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCSpriteDraw::PCSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��2D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::None);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	PCSpriteDraw::PCSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr,
		vector<VertexPositionColor>& Vertices, vector<uint16_t>& indices):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		try {
			//�p�C�v���C���X�e�[�g���f�t�H���g��2D
			SetBlendState(BlendState::Opaque);
			SetDepthStencilState(DepthStencilState::None);
			SetRasterizerState(RasterizerState::CullBack);
			SetSamplerState(SamplerState::LinearClamp);
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}

	PCSpriteDraw::~PCSpriteDraw() {}

	void PCSpriteDraw::CreateMesh(vector<VertexPositionColor>& Vertices, vector<uint16_t>& indices) {
		try {
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}

	void PCSpriteDraw::UpdateVertices(const vector<VertexPositionColor>& Vertices) {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!GetMeshResource())",
				L"PCSpriteDraw::UpdateVertices()"
			);

		}
		if (Vertices.size() > SpriteMesh->GetNumVertices()) {
			throw BaseException(
				L"�X�V���钸�_���傫�����܂�",
				L"if (Vertices.size() > SpriteMesh->GetNumVertices())",
				L"PCSpriteDraw::UpdateVertices()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();

		//���_�̕ύX
		//D3D11_MAP_WRITE_DISCARD�͏d�v�B���̏����ɂ��AGPU�Ɏז�����Ȃ�
		D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
		D3D11_MAPPED_SUBRESOURCE mappedBuffer;
		//���_�̃}�b�v
		if (FAILED(pD3D11DeviceContext->Map(SpriteMesh->GetVertexBuffer().Get(), 0, mapType, 0, &mappedBuffer))) {
			// Map���s
			throw BaseException(
				L"���_��Map�Ɏ��s���܂����B",
				L"if(FAILED(pID3D11DeviceContext->Map()))",
				L"PCSpriteDraw::UpdateVertices()"
			);
		}
		//���_�̕ύX
		VertexPositionColor* vertices
			= (VertexPositionColor*)mappedBuffer.pData;
		for (size_t i = 0; i < SpriteMesh->GetNumVertices(); i++) {
			vertices[i] = Vertices[i];
		}
		//�A���}�b�v
		pD3D11DeviceContext->Unmap(SpriteMesh->GetVertexBuffer().Get(), 0);
	}
	void PCSpriteDraw::OnCreate() {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			//�쐬����ĂȂ�������쐬����
			float HelfSize = 0.5f;
			//���_�z��
			vector<VertexPositionColor> Vertices = {
				{ VertexPositionColor(Vector3(-HelfSize, HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f)) },
				{ VertexPositionColor(Vector3(HelfSize, HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f)) },
				{ VertexPositionColor(Vector3(-HelfSize, -HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f)) },
				{ VertexPositionColor(Vector3(HelfSize, -HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f)) },
			};
			//�C���f�b�N�X�z��
			vector<uint16_t> indices = { 0, 1, 2, 1, 3, 2 };
			//���b�V���̍쐬�i�ύX�ł���j
			SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}

	}
	void PCSpriteDraw::OnDraw() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!SpriteMesh)",
				L"PCSpriteDraw::OnDraw()"
			);
		}

		//�s��̎擾
		auto PtrTrans = GetGameObject()->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, Proj;
		World = PtrTrans->Get2DWorldMatrix();
		//�ˉe�s��̌���
		GetGameObject()->OnGet2DDrawProjMatrix(Proj);
		//�s��̍���
		World *= Proj;
		//�R���X�^���g�o�b�t�@�̏���
		SpriteConstants sb;
		//�G�~�b�V�u
		sb.Emissive = GetEmissive();
		//�f�t�B�[�Y�͂��ׂĒʂ�
		sb.Diffuse = GetDiffuse();
		//�s��̐ݒ�
		sb.World = World;
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBSprite::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionColor);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, SpriteMesh->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(SpriteMesh->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);

		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBSprite::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPCSprite::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPCSprite::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPCSprite::GetPtr()->GetInputLayout());

		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		if (GetGameObject()->GetAlphaActive()) {
			//�u�����h�X�e�[�g
			//��������
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
			//���X�^���C�U�X�e�[�g
			pD3D11DeviceContext->RSSetState(RenderState->GetCullNone());
		}
		else {
			//�u�����h�X�e�[�g
			//�����������Ȃ�
			//�u�����h�X�e�[�g�͐ݒ�ɔC����
			SetDeviceBlendState();
			//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
			SetDeviceRasterizerState();
		}
		//�`��
		pD3D11DeviceContext->DrawIndexed(SpriteMesh->GetNumIndicis(), 0, 0);
		//��n��
		Dev->InitializeStates();
	}



	//--------------------------------------------------------------------------------------
	//	struct PTSpriteDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PTSpriteDraw::Impl {
		Impl()
		{}
	};

	//--------------------------------------------------------------------------------------
	///	PTSprite�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PTSpriteDraw::PTSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��2D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::None);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}

	PTSpriteDraw::PTSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr,
		vector<VertexPositionTexture>& Vertices, vector<uint16_t>& indices):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		try {
			//�p�C�v���C���X�e�[�g���f�t�H���g��2D
			SetBlendState(BlendState::Opaque);
			SetDepthStencilState(DepthStencilState::None);
			SetRasterizerState(RasterizerState::CullBack);
			SetSamplerState(SamplerState::LinearClamp);
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}

	PTSpriteDraw::~PTSpriteDraw() {}

	void PTSpriteDraw::CreateMesh(vector<VertexPositionTexture>& Vertices, vector<uint16_t>& indices) {
		try {
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}

	void PTSpriteDraw::UpdateVertices(const vector<VertexPositionTexture>& Vertices) {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!GetMeshResource())",
				L"PTSpriteDraw::UpdateVertices()"
			);

		}
		if (Vertices.size() > SpriteMesh->GetNumVertices()) {
			throw BaseException(
				L"�X�V���钸�_���傫�����܂�",
				L"if (Vertices.size() > SpriteMesh->GetNumVertices())",
				L"PTSpriteDraw::UpdateVertices()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();

		//���_�̕ύX
		//D3D11_MAP_WRITE_DISCARD�͏d�v�B���̏����ɂ��AGPU�Ɏז�����Ȃ�
		D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
		D3D11_MAPPED_SUBRESOURCE mappedBuffer;
		//���_�̃}�b�v
		if (FAILED(pD3D11DeviceContext->Map(SpriteMesh->GetVertexBuffer().Get(), 0, mapType, 0, &mappedBuffer))) {
			// Map���s
			throw BaseException(
				L"���_��Map�Ɏ��s���܂����B",
				L"if(FAILED(pID3D11DeviceContext->Map()))",
				L"PTSpriteDraw::UpdateVertices()"
			);
		}
		//���_�̕ύX
		VertexPositionTexture* vertices
			= (VertexPositionTexture*)mappedBuffer.pData;
		for (size_t i = 0; i < SpriteMesh->GetNumVertices(); i++) {
			vertices[i] = Vertices[i];
		}
		//�A���}�b�v
		pD3D11DeviceContext->Unmap(SpriteMesh->GetVertexBuffer().Get(), 0);
	}

	void PTSpriteDraw::OnCreate() {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			//�쐬����ĂȂ�������쐬����
			float HelfSize = 0.5f;
			//���_�z��
			vector<VertexPositionTexture> Vertices = {
				{ VertexPositionTexture(Vector3(-HelfSize, HelfSize, 0), Vector2(0.0f, 0.0f)) },
				{ VertexPositionTexture(Vector3(HelfSize, HelfSize, 0), Vector2(1.0f, 0.0f)) },
				{ VertexPositionTexture(Vector3(-HelfSize, -HelfSize, 0), Vector2(0.0f, 1.0f)) },
				{ VertexPositionTexture(Vector3(HelfSize, -HelfSize, 0), Vector2(1.0f, 1.0f)) },
			};
			//�C���f�b�N�X�z��
			vector<uint16_t> indices = { 0, 1, 2, 1, 3, 2 };
			//���b�V���̍쐬�i�ύX�ł���j
			SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
	}

	void PTSpriteDraw::OnDraw() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!SpriteMesh)",
				L"PTSpriteDraw::OnDraw()"
			);
		}
		//�e�N�X�`�����Ȃ���Ε`�悵�Ȃ�
		auto shTex = GetTextureResource();
		if (!shTex) {
			return;
		}
		//�s��̎擾
		auto PtrTrans = GetGameObject()->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, Proj;
		World = PtrTrans->Get2DWorldMatrix();
		//�ˉe�s��̌���
		GetGameObject()->OnGet2DDrawProjMatrix(Proj);
		//�s��̍���
		World *= Proj;
		//�R���X�^���g�o�b�t�@�̏���
		SpriteConstants sb;
		//�G�~�b�V�u
		sb.Emissive = GetEmissive();
		//�f�t�B�[�Y�͂��ׂĒʂ�
		sb.Diffuse = GetDiffuse();
		//�s��̐ݒ�
		sb.World = World;
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBSprite::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionTexture);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, SpriteMesh->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(SpriteMesh->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);

		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBSprite::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPTSprite::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPTSprite::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPTSprite::GetPtr()->GetInputLayout());

		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		if (GetGameObject()->GetAlphaActive()) {
			//�u�����h�X�e�[�g
			//��������
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
			//���X�^���C�U�X�e�[�g
			pD3D11DeviceContext->RSSetState(RenderState->GetCullNone());
		}
		else {
			//�u�����h�X�e�[�g
			//�����������Ȃ�
			//�u�����h�X�e�[�g�͐ݒ�ɔC����
			SetDeviceBlendState();
			//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
			SetDeviceRasterizerState();
		}
		//�e�N�X�`���ƃT���v���[�̐ݒ�
		pD3D11DeviceContext->PSSetShaderResources(0, 1, shTex->GetShaderResourceView().GetAddressOf());
		//�T���v���[�͐ݒ�ɔC����
		SetDeviceSamplerState();
		//�`��
		pD3D11DeviceContext->DrawIndexed(SpriteMesh->GetNumIndicis(), 0, 0);
		//��n��
		Dev->InitializeStates();
	}

	//--------------------------------------------------------------------------------------
	//	struct PCTSpriteDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCTSpriteDraw::Impl {
		Impl()
		{}
	};


	//--------------------------------------------------------------------------------------
	///	PCTSprite�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCTSpriteDraw::PCTSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��2D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::None);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	PCTSpriteDraw::PCTSpriteDraw(const shared_ptr<GameObject>& GameObjectPtr,
		vector<VertexPositionColorTexture>& Vertices, vector<uint16_t>& indices):
		SpriteBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		try {
			//�p�C�v���C���X�e�[�g���f�t�H���g��2D
			SetBlendState(BlendState::Opaque);
			SetDepthStencilState(DepthStencilState::None);
			SetRasterizerState(RasterizerState::CullBack);
			SetSamplerState(SamplerState::LinearClamp);
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}
	PCTSpriteDraw::~PCTSpriteDraw() {}


	void PCTSpriteDraw::CreateMesh(vector<VertexPositionColorTexture>& Vertices, vector<uint16_t>& indices) {
		try {
			//���b�V���̍쐬�i�ύX�ł���j
			auto SpriteMesh = MeshResource::CreateMeshResource(Vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
		catch (...) {
			throw;
		}
	}


	void PCTSpriteDraw::UpdateVertices(const vector<VertexPositionColorTexture>& Vertices) {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!SpriteMesh)",
				L"PCTSpriteDraw::UpdateVertices()"
			);

		}
		if (Vertices.size() > SpriteMesh->GetNumVertices()) {
			throw BaseException(
				L"�X�V���钸�_���傫�����܂�",
				L"if (Vertices.size() > SpriteMesh->GetNumVertices())",
				L"PCTSpriteDraw::UpdateVertices()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();

		//���_�̕ύX
		//D3D11_MAP_WRITE_DISCARD�͏d�v�B���̏����ɂ��AGPU�Ɏז�����Ȃ�
		D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
		D3D11_MAPPED_SUBRESOURCE mappedBuffer;
		//���_�̃}�b�v
		if (FAILED(pD3D11DeviceContext->Map(SpriteMesh->GetVertexBuffer().Get(), 0, mapType, 0, &mappedBuffer))) {
			// Map���s
			throw BaseException(
				L"���_��Map�Ɏ��s���܂����B",
				L"if(FAILED(pID3D11DeviceContext->Map()))",
				L"PCTSpriteDraw::UpdateVertices()"
			);
		}
		//���_�̕ύX
		VertexPositionColorTexture* vertices
			= (VertexPositionColorTexture*)mappedBuffer.pData;
		for (size_t i = 0; i < SpriteMesh->GetNumVertices(); i++) {
			vertices[i] = Vertices[i];
		}
		//�A���}�b�v
		pD3D11DeviceContext->Unmap(SpriteMesh->GetVertexBuffer().Get(), 0);


	}
	void PCTSpriteDraw::OnCreate() {
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			//�쐬����ĂȂ�������쐬����
			float HelfSize = 0.5f;
			//���_�z��
			vector<VertexPositionColorTexture> vertices = {
				{ VertexPositionColorTexture(Vector3(-HelfSize, HelfSize, 0),Color4(1.0f,1.0f,1.0f,1.0f), Vector2(0.0f, 0.0f)) },
				{ VertexPositionColorTexture(Vector3(HelfSize, HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f), Vector2(1.0f, 0.0f)) },
				{ VertexPositionColorTexture(Vector3(-HelfSize, -HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f), Vector2(0.0f, 1.0f)) },
				{ VertexPositionColorTexture(Vector3(HelfSize, -HelfSize, 0), Color4(1.0f,1.0f,1.0f,1.0f), Vector2(1.0f, 1.0f)) },
			};
			//�C���f�b�N�X�z��
			vector<uint16_t> indices = { 0, 1, 2, 1, 3, 2 };
			//���b�V���̍쐬�i�ύX�ł���j
			SpriteMesh = MeshResource::CreateMeshResource(vertices, indices, true);
			SetMeshResource(SpriteMesh);
		}
	}

	void PCTSpriteDraw::OnDraw() {
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		//���b�V�����Ȃ���Ε`�悵�Ȃ�
		auto SpriteMesh = GetMeshResource();
		if (!SpriteMesh) {
			throw BaseException(
				L"���b�V�����쐬����Ă��܂���",
				L"if (!SpriteMesh)",
				L"PCTSpriteDraw::OnDraw()"
			);
		}
		//�e�N�X�`�����Ȃ���Ε`�悵�Ȃ�
		auto shTex = GetTextureResource();
		if (!shTex) {
			return;
		}
		//�s��̎擾
		auto PtrTrans = GetGameObject()->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, Proj;
		World = PtrTrans->Get2DWorldMatrix();
		//�ˉe�s��̌���
		GetGameObject()->OnGet2DDrawProjMatrix(Proj);
		//�s��̍���
		World *= Proj;
		//�R���X�^���g�o�b�t�@�̏���
		SpriteConstants sb;
		//�G�~�b�V�u
		sb.Emissive = GetEmissive();
		//�f�t�B�[�Y�͂��ׂĒʂ�
		sb.Diffuse = GetDiffuse();
		//�s��̐ݒ�
		sb.World = World;
		//�R���X�^���g�o�b�t�@�̍X�V
		pD3D11DeviceContext->UpdateSubresource(CBSprite::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionColorTexture);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, SpriteMesh->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(SpriteMesh->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);

		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//�R���X�^���g�o�b�t�@�̐ݒ�
		ID3D11Buffer* pConstantBuffer = CBSprite::GetPtr()->GetBuffer();
		ID3D11Buffer* pNullConstantBuffer = nullptr;
		//���_�V�F�[�_�ɓn��
		pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�s�N�Z���V�F�[�_�ɓn��
		pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPCTSprite::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPCTSprite::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPCTSprite::GetPtr()->GetInputLayout());

		//�f�v�X�X�e���V���X�e�[�g�͐ݒ�ɔC����
		SetDeviceDepthStencilState();
		if (GetGameObject()->GetAlphaActive()) {
			//�u�����h�X�e�[�g
			//��������
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetAlphaBlendEx(), nullptr, 0xffffffff);
			//���X�^���C�U�X�e�[�g
			pD3D11DeviceContext->RSSetState(RenderState->GetCullNone());
		}
		else {
			//�u�����h�X�e�[�g
			//�����������Ȃ�
			//�u�����h�X�e�[�g�͐ݒ�ɔC����
			SetDeviceBlendState();
			//���X�^���C�U�X�e�[�g�͐ݒ�ɔC����
			SetDeviceRasterizerState();
		}

		//�e�N�X�`���ƃT���v���[�̐ݒ�
		pD3D11DeviceContext->PSSetShaderResources(0, 1, shTex->GetShaderResourceView().GetAddressOf());
		//�T���v���[�͐ݒ�ɔC����
		SetDeviceSamplerState();
		//�`��
		pD3D11DeviceContext->DrawIndexed(SpriteMesh->GetNumIndicis(), 0, 0);
		//��n��
		Dev->InitializeStates();
	}


	//--------------------------------------------------------------------------------------
	//	3D�p�V�F�[�_���ƕ`��\����
	//--------------------------------------------------------------------------------------
	struct Draw3DPrim {
		static void PCWireFrameDraw(const shared_ptr<GameObject>& GameObjectPtr, const shared_ptr<MeshResource>& MeshRes,
			const Color4& Emissive, const Color4& Diffuse, const Matrix4X4& MeshToTransformMatrix) {
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
			auto RenderState = Dev->GetRenderState();
			//�s��̒�`
			auto PtrTrans = GameObjectPtr->GetComponent<Transform>();
			//�s��̒�`
			Matrix4X4 World, ViewMat, ProjMat;
			//���[���h�s��̌���
			World = MeshToTransformMatrix * PtrTrans->GetWorldMatrix();
			//�]�u����
			World.Transpose();
			//�J�����𓾂�
			auto CameraPtr = GameObjectPtr->OnGetDrawCamera();
			//�r���[�Ǝˉe�s��𓾂�
			ViewMat = CameraPtr->GetViewMatrix();
			//�]�u����
			ViewMat.Transpose();
			//�]�u����
			ProjMat = CameraPtr->GetProjMatrix();
			ProjMat.Transpose();
			//�R���X�^���g�o�b�t�@�̏���
			SimpleConstants sb;
			sb.World = World;
			sb.View = ViewMat;
			sb.Projection = ProjMat;
			//�G�~�b�V�u
			sb.Emissive = Emissive;
			//�f�t�B�[�Y�͂��ׂĒʂ�
			sb.Diffuse = Diffuse;
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &sb, 0, 0);

			//�X�g���C�h�ƃI�t�Z�b�g
			UINT stride = sizeof(VertexPositionColor);
			UINT offset = 0;
			//���_�o�b�t�@�̃Z�b�g
			pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
			//�C���f�b�N�X�o�b�t�@�̃Z�b�g
			pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);

			//�`����@�i3�p�`�j
			pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

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
			//�����������Ȃ�
			pD3D11DeviceContext->OMSetBlendState(RenderState->GetOpaque(), nullptr, 0xffffffff);
			//�f�v�X�X�e���V���X�e�[�g
			pD3D11DeviceContext->OMSetDepthStencilState(RenderState->GetDepthDefault(), 0);
			//���X�^���C�U�X�e�[�g(���C�A�t���[��)
			pD3D11DeviceContext->RSSetState(RenderState->GetWireframe());
			pD3D11DeviceContext->DrawIndexed(MeshRes->GetNumIndicis(), 0, 0);
			//��n��
			Dev->InitializeStates();
		}
	};


	//--------------------------------------------------------------------------------------
	//	struct StaticBaseDraw::Impl;
	//	�p�r: StaticBaseDraw�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct StaticBaseDraw::Impl {
		//���b�V����weak_ptr
		weak_ptr<MeshResource> m_MeshResource;
		//���_�ύX����ꍇ�̃��b�V���i�I���W�i���j
		shared_ptr<MeshResource> m_OriginalMeshResource;
		//�I���W�i�����b�V�����g�����ǂ���
		bool m_UseOriginalMeshResource;
		///�G�~�b�V�u�F
		Color4 m_Emissive;
		/// �f�t���[�Y�F
		Color4 m_Diffuse;
		/// �X�y�L�����[�F
		Color4 m_Specular;
		Impl() :
			m_UseOriginalMeshResource(false),
			m_Emissive(0, 0, 0, 0),
			m_Diffuse(1.0f, 1.0f, 1.0f, 1.0f),
			m_Specular(0, 0, 0, 0)
		{}
	};


	//--------------------------------------------------------------------------------------
	///	static�`��R���|�[�l���g�̐e(���_��ύX����ꍇ����)
	//--------------------------------------------------------------------------------------
	StaticBaseDraw::StaticBaseDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		DrawComponent(GameObjectPtr),
		pImpl(new Impl())
	{}
	StaticBaseDraw::~StaticBaseDraw() {}

	void StaticBaseDraw::SetConstants(SimpleConstants& Cb, bool shadowUse) {
		//�s��̒�`
		auto PtrTrans = GetGameObject()->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, ViewMat, ProjMat;
		//���[���h�s��̌���
		World = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = GetGameObject()->OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		ViewMat = CameraPtr->GetViewMatrix();
		//�]�u����
		ViewMat.Transpose();
		//�]�u����
		ProjMat = CameraPtr->GetProjMatrix();
		ProjMat.Transpose();
		Cb.World = World;
		Cb.View = ViewMat;
		Cb.Projection = ProjMat;
		//�G�~�b�V�u
		Cb.Emissive = GetEmissive();
		//�f�t�B�[�Y
		Cb.Diffuse = GetDiffuse();
		//�X�y�L�����[
		Cb.Specular = GetSpecular();
		//���C�e�B���O
		auto StageLight = GetGameObject()->OnGetDrawLight();
		Cb.LightDir = StageLight.m_Directional;
		Cb.LightDir.w = 1.0f;
		Cb.EyePos = CameraPtr->GetEye();
		Cb.EyePos.w = 1.0f;
		if (shadowUse) {
			Vector3 CalcLightDir = -1.0 * StageLight.m_Directional;
			Vector3 LightAt = CameraPtr->GetAt();
			Vector3 LightEye = CalcLightDir;
			LightEye *= Shadowmap::GetLightHeight();
			LightEye = LightAt + LightEye;
			Cb.LightPos = LightEye;
			Cb.LightPos.w = 1.0f;
			Matrix4X4 LightView, LightProj;
			//���C�g�̃r���[�Ǝˉe���v�Z
			LightView.LookAtLH(LightEye, LightAt, Vector3(0, 1.0f, 0));
			LightProj.OrthographicLH(Shadowmap::GetViewWidth(), Shadowmap::GetViewHeight(),
				Shadowmap::GetLightNear(), Shadowmap::GetLightFar());
			Cb.LightView = Matrix4X4EX::Transpose(LightView);
			Cb.LightProjection = Matrix4X4EX::Transpose(LightProj);
		}
	}

	Color4 StaticBaseDraw::GetEmissive() const {
		return pImpl->m_Emissive;
	}
	void StaticBaseDraw::SetEmissive(const Color4& col) {
		pImpl->m_Emissive = col;
	}
	Color4 StaticBaseDraw::GetDiffuse() const {
		return pImpl->m_Diffuse;
	}
	void StaticBaseDraw::SetDiffuse(const Color4& col) {
		pImpl->m_Diffuse = col;
	}

	Color4 StaticBaseDraw::GetSpecular() const {
		return pImpl->m_Specular;
	}
	void StaticBaseDraw::SetSpecular(const Color4& col) {
		pImpl->m_Specular = col;
	}



	bool StaticBaseDraw::IsOriginalMeshUse() const {
		return pImpl->m_UseOriginalMeshResource;
	}

	void StaticBaseDraw::SetOriginalMeshUse(bool b) {
		pImpl->m_UseOriginalMeshResource = b;
	}

	shared_ptr<MeshResource> StaticBaseDraw::GetOriginalMeshResource() const {
		return pImpl->m_OriginalMeshResource;
	}
	void StaticBaseDraw::SetOriginalMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		pImpl->m_OriginalMeshResource = MeshRes;
	}
	shared_ptr<MeshResource> StaticBaseDraw::GetMeshResource() const {
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
	void StaticBaseDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		pImpl->m_MeshResource = MeshRes;
	}

	void StaticBaseDraw::SetMeshResource(const wstring& MeshKey) {
		SetMeshResource(App::GetApp()->GetResource<MeshResource>(MeshKey));
	}


	//--------------------------------------------------------------------------------------
	//	struct StaticInstanceDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct StaticInstanceDraw::Impl {
		size_t m_MaxInstance;
		///<�s��p�̒��_�o�b�t�@
		ComPtr<ID3D11Buffer> m_MatrixBuffer;
		//�s��̔z��
		vector<Matrix4X4> m_MatrixVec;
		//�s��������N���A���邩�ǂ���
		bool m_AutoClearMatrixVec;
		Impl() :
			m_MaxInstance(2000),
			m_AutoClearMatrixVec(false)
		{}
		~Impl() {}
	};


	//--------------------------------------------------------------------------------------
	///	�C���X�^���X�`��R���|�[�l���g�̐e
	//--------------------------------------------------------------------------------------
	StaticInstanceDraw::StaticInstanceDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticBaseDraw(GameObjectPtr),
		pImpl(new Impl()) {
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
		//���C�e�B���O�݂̂��Ƌɒ[�ɂȂ�̂Œ���
		SetEmissive(Color4(0.5f, 0.5f, 0.5f, 0.0f));
		SetDiffuse(Color4(0.6f, 0.6f, 0.6f, 1.0f));
		//�s��o�b�t�@�̍쐬
		CreateMatrixBuffer();
	}

	StaticInstanceDraw::~StaticInstanceDraw() {}

	//�s��o�b�t�@�̍쐬
	void StaticInstanceDraw::CreateMatrixBuffer() {
		//�C���X�^���X�s��o�b�t�@�̍쐬
		//Max�l�ō쐬����
		vector<Matrix4X4> matrices(pImpl->m_MaxInstance);
		for (auto& m : matrices) {
			m = Matrix4X4();
		}
		MeshResource::CreateDynamicVertexBuffer(pImpl->m_MatrixBuffer, matrices);
	}

	//�s��o�b�t�@�̃}�b�v
	void StaticInstanceDraw::MapMatrixBuffer() {
		//�f�o�C�X�̎擾
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pDx11Device = Dev->GetD3DDevice();
		auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
		//�C���X�^���X�o�b�t�@�Ƀ}�b�v
		D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
		D3D11_MAPPED_SUBRESOURCE mappedBuffer;
		//�s��̃}�b�v
		if (FAILED(pID3D11DeviceContext->Map(pImpl->m_MatrixBuffer.Get(), 0, mapType, 0, &mappedBuffer))) {
			// Map���s
			throw BaseException(
				L"�s���Map�Ɏ��s���܂����B",
				L"if(FAILED(pID3D11DeviceContext->Map()))",
				L"StaticInstanceDraw::MapMatrixBuffer()"
			);
		}
		//�s��̕ύX
		auto* matrices = (Matrix4X4*)mappedBuffer.pData;
		Matrix4X4 World;
		for (size_t i = 0; i < pImpl->m_MatrixVec.size(); i++) {
			//���[���h�s��
			World = pImpl->m_MatrixVec[i];
			//�]�u����
			World.Transpose();
			matrices[i] = World;
		}
		//�A���}�b�v
		pID3D11DeviceContext->Unmap(pImpl->m_MatrixBuffer.Get(), 0);

	}




	size_t StaticInstanceDraw::GetMaxInstance() const {
		return pImpl->m_MaxInstance;
	}

	void StaticInstanceDraw::ResizeMaxInstance(size_t NewSize) {
		pImpl->m_MaxInstance = NewSize;
		CreateMatrixBuffer();
	}

	void StaticInstanceDraw::AddMatrix(const Matrix4X4& NewMat) {
		if (pImpl->m_MatrixVec.size() >= GetMaxInstance()) {
			throw BaseException(
				L"�C���X�^���X����𒴂��Ă܂�",
				L"if (pImpl->m_MatrixVec.size() >= GetMaxInstance())",
				L"StaticInstanceDraw::AddMatrix()"
			);
		}
		pImpl->m_MatrixVec.push_back(NewMat);
	}

	void StaticInstanceDraw::UpdateMultiMatrix(const vector<Matrix4X4>& NewMatVec) {
		pImpl->m_MatrixVec.resize(NewMatVec.size());
		pImpl->m_MatrixVec = NewMatVec;
	}

	vector<Matrix4X4>& StaticInstanceDraw::GetMatrixVec() const {
		return pImpl->m_MatrixVec;
	}

	void StaticInstanceDraw::ClearMatrixVec() {
		pImpl->m_MatrixVec.clear();
	}

	bool StaticInstanceDraw::IsAutoClearMatrixVec() const {
		return pImpl->m_AutoClearMatrixVec;
	}
	void StaticInstanceDraw::SetAutoClearMatrixVec(bool b) {
		pImpl->m_AutoClearMatrixVec = b;
	}



	ComPtr<ID3D11Buffer>& StaticInstanceDraw::GetMatrixBuffer() const {
		return pImpl->m_MatrixBuffer;
	}



	//--------------------------------------------------------------------------------------
	//	struct PCStaticDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCStaticDraw::Impl {
		Impl()
		{}
	};



	//--------------------------------------------------------------------------------------
	///	PCStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCStaticDraw::PCStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}

	PCStaticDraw::~PCStaticDraw() {}

	void PCStaticDraw::OnDraw() {
		DrawStatic<VSPCStatic, PSPCStatic>(false, false);
	}


	//--------------------------------------------------------------------------------------
	//	struct PCStaticInstanceDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCStaticInstanceDraw::Impl {
		Impl()
		{}
	};

	//--------------------------------------------------------------------------------------
	///	PCStaticInstance�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCStaticInstanceDraw::PCStaticInstanceDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticInstanceDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}

	PCStaticInstanceDraw::~PCStaticInstanceDraw() {}

	void PCStaticInstanceDraw::OnDraw() {
		MapMatrixBuffer();
		DrawStaticInstance<VSPCStaticInstance, PSPCStatic>(false, false);
	}






	//--------------------------------------------------------------------------------------
	//	struct PTStaticDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PTStaticDraw::Impl {
		Impl()
		{}
	};
	//--------------------------------------------------------------------------------------
	///	PTStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PTStaticDraw::PTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	PTStaticDraw::~PTStaticDraw() {}

	void PTStaticDraw::OnDraw() {
		DrawStatic<VSPTStatic, PSPTStatic>(true, false);
	}



	//--------------------------------------------------------------------------------------
	//	struct PTStaticInstanceDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PTStaticInstanceDraw::Impl {
		Impl()
		{}
	};
	//--------------------------------------------------------------------------------------
	///	PTStaticInstance�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PTStaticInstanceDraw::PTStaticInstanceDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticInstanceDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}
	PTStaticInstanceDraw::~PTStaticInstanceDraw() {}

	void PTStaticInstanceDraw::OnDraw() {
		MapMatrixBuffer();
		DrawStaticInstance<VSPTStaticInstance, PSPTStatic>(true, false);
	}





	//--------------------------------------------------------------------------------------
	//	struct PCTStaticDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCTStaticDraw::Impl {
		Impl()
		{}
	};


	//--------------------------------------------------------------------------------------
	///	PCTStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCTStaticDraw::PCTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticBaseDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}

	PCTStaticDraw::~PCTStaticDraw() {}


	void PCTStaticDraw::OnDraw() {
		DrawStatic<VSPCTStatic, PSPCTStatic>(true, false);
	}


	//--------------------------------------------------------------------------------------
	//	struct PCTStaticInstanceDraw::Impl;
	//--------------------------------------------------------------------------------------
	struct PCTStaticInstanceDraw::Impl {
		Impl()
		{}
	};


	//--------------------------------------------------------------------------------------
	///	PCTStaticInstance�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PCTStaticInstanceDraw::PCTStaticInstanceDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticInstanceDraw(GameObjectPtr),
		pImpl(new Impl())
	{
		//�p�C�v���C���X�e�[�g���f�t�H���g��3D
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
	}

	PCTStaticInstanceDraw::~PCTStaticInstanceDraw() {}


	void PCTStaticInstanceDraw::OnDraw() {
		MapMatrixBuffer();
		DrawStaticInstance<VSPCTStaticInstance, PSPCTStatic>(true,false);
	}



	//--------------------------------------------------------------------------------------
	//	struct PNTStaticDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct PNTStaticDraw::Impl {
		bool m_OwnShadowActive;
		Impl() :
			m_OwnShadowActive(false)
		{}
		~Impl() {}
	};



	//--------------------------------------------------------------------------------------
	//	class PNTStaticDraw : public DrawComponent;
	//	�p�r: PNTStatic�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PNTStaticDraw::PNTStaticDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticBaseDraw(GameObjectPtr),
		pImpl(new Impl()) {
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
		//���C�e�B���O�݂̂��Ƌɒ[�ɂȂ�̂Œ���
		SetEmissive(Color4(0.5f,0.5f,0.5f,0.0f));
		SetDiffuse(Color4(0.6f, 0.6f, 0.6f, 1.0f));
	}

	PNTStaticDraw::~PNTStaticDraw() {}

	void PNTStaticDraw::OnCreate() {
	}


	bool PNTStaticDraw::GetOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	bool PNTStaticDraw::IsOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	void PNTStaticDraw::SetOwnShadowActive(bool b) {
		pImpl->m_OwnShadowActive = b;
	}

	void PNTStaticDraw::OnDraw() {
		if (GetOwnShadowActive()) {
			DrawStatic<VSPNTStaticShadow, PSPNTStaticShadow>(true, true);
		}
		else {
			DrawStatic<VSPNTStatic, PSPNTStatic>(true, false);
		}
	}

	//--------------------------------------------------------------------------------------
	//	struct PNTStaticInstanceDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct PNTStaticInstanceDraw::Impl {
		bool m_OwnShadowActive;
		Impl() :
			m_OwnShadowActive(false)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	///	PNTStatic�C���X�^���X�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PNTStaticInstanceDraw::PNTStaticInstanceDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		StaticInstanceDraw(GameObjectPtr),
		pImpl(new Impl()) {
		//�p�C�v���C���X�e�[�g���f�t�H���g�̂RD
		SetBlendState(BlendState::Opaque);
		SetDepthStencilState(DepthStencilState::Default);
		SetRasterizerState(RasterizerState::CullBack);
		SetSamplerState(SamplerState::LinearClamp);
		//���C�e�B���O�݂̂��Ƌɒ[�ɂȂ�̂Œ���
		SetEmissive(Color4(0.5f, 0.5f, 0.5f, 0.0f));
		SetDiffuse(Color4(0.6f, 0.6f, 0.6f, 1.0f));
	}

	PNTStaticInstanceDraw::~PNTStaticInstanceDraw() {}

	void PNTStaticInstanceDraw::OnCreate() {
		CreateMatrixBuffer();
	}


	bool PNTStaticInstanceDraw::GetOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	bool PNTStaticInstanceDraw::IsOwnShadowActive() const {
		return pImpl->m_OwnShadowActive;
	}
	void PNTStaticInstanceDraw::SetOwnShadowActive(bool b) {
		pImpl->m_OwnShadowActive = b;
	}


	void PNTStaticInstanceDraw::OnDraw() {
		MapMatrixBuffer();
		if (GetOwnShadowActive()) {
			DrawStaticInstance<VSPNTStaticInstanceShadow, PSPNTStaticShadow>(true, true);
		}
		else {
			DrawStaticInstance<VSPNTStaticInstance, PSPNTStatic>(true, false);
		}
	}




	//--------------------------------------------------------------------------------------
	//	struct PNTStaticModelDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct PNTStaticModelDraw::Impl {
		bool m_ModelDiffusePriority;
		bool m_ModelEmissivePriority;
		bool m_ModelTextureEnabled;
		Impl() :
			m_ModelDiffusePriority(false),
			m_ModelEmissivePriority(false),
			m_ModelTextureEnabled(true)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	//	class PNTStaticModelDraw : public DrawComponent;
	//	�p�r: PNTStaticModelDraw�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PNTStaticModelDraw::PNTStaticModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		PNTStaticDraw(GameObjectPtr),
		pImpl(new Impl()) {
	}

	PNTStaticModelDraw::~PNTStaticModelDraw() {}

	void PNTStaticModelDraw::OnCreate() {
	}


	bool PNTStaticModelDraw::GetModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	bool PNTStaticModelDraw::IsModelDiffusePriority() const {
		return pImpl->m_ModelDiffusePriority;

	}
	void PNTStaticModelDraw::SetModelDiffusePriority(bool b) {
		pImpl->m_ModelDiffusePriority = b;
	}
	bool PNTStaticModelDraw::GetModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	bool PNTStaticModelDraw::IsModelEmissivePriority() const {
		return pImpl->m_ModelEmissivePriority;
	}
	void PNTStaticModelDraw::SetModelEmissivePriority(bool b) {
		pImpl->m_ModelEmissivePriority = b;
	}

	bool PNTStaticModelDraw::GetModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;

	}
	bool PNTStaticModelDraw::IsModelTextureEnabled() const {
		return pImpl->m_ModelTextureEnabled;
	}
	void PNTStaticModelDraw::SeModelTextureEnabled(bool b) {
		pImpl->m_ModelTextureEnabled = b;
	}

	void PNTStaticModelDraw::DrawWithShadow() {
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
				L"PNTStaticModelDraw::OnDraw()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();

		auto GameObjectPtr = GetGameObject();


		//�s��̒�`
		auto PtrTrans = GameObjectPtr->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, ViewMat, ProjMat;
		//���[���h�s��̌���
		World = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = GameObjectPtr->OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		ViewMat = CameraPtr->GetViewMatrix();
		//�]�u����
		ViewMat.Transpose();
		//�]�u����
		ProjMat = CameraPtr->GetProjMatrix();
		ProjMat.Transpose();

		auto MeshPtr = GetMeshResource();
		auto& MatVec = MeshPtr->GetMaterialExVec();

		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�V�F�[�_�̐ݒ�
		if (GetGameObject()->GetComponent<Shadowmap>(false)) {
			//�V���h�E�}�b�v������Ύ��ȉe�h�~�p�̃s�N�Z���V�F�[�_
			pD3D11DeviceContext->VSSetShader(VSPNTStaticShadow::GetPtr()->GetShader(), nullptr, 0);
			pD3D11DeviceContext->PSSetShader(PSPNTStaticShadow2::GetPtr()->GetShader(), nullptr, 0);
		}
		else {
			pD3D11DeviceContext->VSSetShader(VSPNTStaticShadow::GetPtr()->GetShader(), nullptr, 0);
			pD3D11DeviceContext->PSSetShader(PSPNTStaticShadow::GetPtr()->GetShader(), nullptr, 0);
		}
		//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
		auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
		ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
		pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
		//�V���h�E�}�b�v�T���v���[
		ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
		pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);

		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPNTStatic::GetPtr()->GetInputLayout());
		//�f�v�X�X�e���V��
		SetDeviceDepthStencilState();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		SimpleConstants cb1;
		//�s��̐ݒ�(�]�u����)
		//�R���X�^���g�o�b�t�@�̐ݒ�
		cb1.World = World;
		cb1.View = ViewMat;
		cb1.Projection = ProjMat;

		//���C�e�B���O
		auto StageLight = GameObjectPtr->OnGetDrawLight();
		cb1.LightDir = StageLight.m_Directional;
		cb1.LightDir.w = 1.0f;
		Vector3 CalcLightDir = -1.0 * StageLight.m_Directional;
		Vector3 LightAt = CameraPtr->GetAt();
		Vector3 LightEye = CalcLightDir;
		LightEye *= Shadowmap::GetLightHeight();
		LightEye = LightAt + LightEye;

		cb1.LightPos = LightEye;
		cb1.LightPos.w = 1.0f;

		cb1.EyePos = CameraPtr->GetEye();
		cb1.EyePos.w = 1.0f;

		Matrix4X4 LightView, LightProj;
		//���C�g�̃r���[�Ǝˉe���v�Z
		LightView.LookAtLH(LightEye, LightAt, Vector3(0, 1.0f, 0));
		LightProj.OrthographicLH(Shadowmap::GetViewWidth(), Shadowmap::GetViewHeight(),
			Shadowmap::GetLightNear(), Shadowmap::GetLightFar());
		cb1.LightView = Matrix4X4EX::Transpose(LightView);
		cb1.LightProjection = Matrix4X4EX::Transpose(LightProj);

		cb1.Emissive = GetEmissive();
		cb1.Diffuse = GetDiffuse();

		for (auto& m : MatVec) {
			if (IsModelEmissivePriority()) {
				cb1.Emissive = m.m_Emissive;
				cb1.Emissive.w = 0;
			}
			if (IsModelDiffusePriority()) {
				cb1.Diffuse = m.m_Diffuse;
			}
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				cb1.ActiveFlg.x = 1;
			}
			else {
				cb1.ActiveFlg.x = 0;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &cb1, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);


			if (IsModelTextureEnabled() && m.m_TextureResource) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, m.m_TextureResource->GetShaderResourceView().GetAddressOf());
				//�T���v���[
				SetDeviceSamplerState();
			}
			else {
				ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
				ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, 1, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, 1, pNullSR);
			}
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

	void PNTStaticModelDraw::DrawNotShadow() {
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
				L"PNTStaticModelDraw::OnDraw()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();

		auto GameObjectPtr = GetGameObject();


		//�s��̒�`
		auto PtrTrans = GameObjectPtr->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, ViewMat, ProjMat;
		//���[���h�s��̌���
		World = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = GameObjectPtr->OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		ViewMat = CameraPtr->GetViewMatrix();
		//�]�u����
		ViewMat.Transpose();
		//�]�u����
		ProjMat = CameraPtr->GetProjMatrix();
		ProjMat.Transpose();

		auto MeshPtr = GetMeshResource();
		auto& MatVec = MeshPtr->GetMaterialExVec();

		ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
		ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };

		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = MeshRes->GetNumStride();
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPNTStatic::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPNTStatic::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPNTStatic::GetPtr()->GetInputLayout());
		//�f�v�X�X�e���V��
		SetDeviceDepthStencilState();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		SimpleConstants cb1;
		//�s��̐ݒ�(�]�u����)
		//�R���X�^���g�o�b�t�@�̐ݒ�
		cb1.World = World;
		cb1.View = ViewMat;
		cb1.Projection = ProjMat;
		//���C�e�B���O
		auto StageLight = GameObjectPtr->OnGetDrawLight();
		cb1.LightDir = StageLight.m_Directional;
		cb1.LightDir.w = 1.0f;
		cb1.Emissive = GetEmissive();
		cb1.Diffuse = GetDiffuse();

		for (auto& m : MatVec) {
			if (IsModelEmissivePriority()) {
				cb1.Emissive = m.m_Emissive;
				cb1.Emissive.w = 0;
			}
			if (IsModelDiffusePriority()) {
				cb1.Diffuse = m.m_Diffuse;
			}
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				cb1.ActiveFlg.x = 1;
			}
			else {
				cb1.ActiveFlg.x = 0;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &cb1, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);


			if (IsModelTextureEnabled() && m.m_TextureResource) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, m.m_TextureResource->GetShaderResourceView().GetAddressOf());
				//�T���v���[
				SetDeviceSamplerState();
			}
			else {
				ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
				ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
			}
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

	void PNTStaticModelDraw::OnDraw() {
		if (GetOwnShadowActive()) {
			DrawWithShadow();
		}
		else {
			DrawNotShadow();
		}
	}


	//--------------------------------------------------------------------------------------
	//	struct PNTBoneModelDraw::Impl;
	//	�p�r: Impl�C�f�B�I��
	//--------------------------------------------------------------------------------------
	struct PNTBoneModelDraw::Impl {
		bool m_OwnShadowActive;
		bool m_ModelDiffusePriority;
		bool m_ModelEmissivePriority;
		bool m_ModelTextureEnabled;
		//�V�F�[�_�ɓn���{�[���s��
		vector<Matrix4X4> m_LocalBonesMatrix;
		map<wstring, AnimationData> m_AnimationMap;
		wstring m_CurrentAnimeName;
		float m_CurrentAnimeTime;
		Impl() :
			m_OwnShadowActive(false),
			m_ModelDiffusePriority(false),
			m_ModelEmissivePriority(false),
			m_ModelTextureEnabled(true),
			m_CurrentAnimeName(L""),
			m_CurrentAnimeTime(0)
		{}
		~Impl() {}
	};

	//--------------------------------------------------------------------------------------
	//	class PNTBoneModelDraw : public StaticBaseDraw;
	//	�p�r: PNTBoneModelDraw�`��R���|�[�l���g
	//--------------------------------------------------------------------------------------
	PNTBoneModelDraw::PNTBoneModelDraw(const shared_ptr<GameObject>& GameObjectPtr) :
		PNTStaticModelDraw(GameObjectPtr),
		pImpl(new Impl()) {
	}

	PNTBoneModelDraw::~PNTBoneModelDraw() {}

	void PNTBoneModelDraw::OnCreate() {

	}


	void PNTBoneModelDraw::SetMeshResource(const shared_ptr<MeshResource>& MeshRes) {
		if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0) {
			throw BaseException(
				L"���b�V�����{�[�����b�V���ł͂���܂���",
				L"if (!MeshRes->IsSkining() || MeshRes->GetBoneCount() == 0 || MeshRes->GetSampleCount() == 0)",
				L"PNTBoneModelDraw::SetMeshResource()"
			);

		}
		//�擪�̃{�[�����̍s��ŏ�����
		pImpl->m_LocalBonesMatrix.resize(MeshRes->GetBoneCount());
		auto& SampleMatrixVec = MeshRes->GetSampleMatrixVec();
		for (UINT i = 0; i < pImpl->m_LocalBonesMatrix.size(); i++) {
			pImpl->m_LocalBonesMatrix[i] = SampleMatrixVec[i];
		}
		StaticBaseDraw::SetMeshResource(MeshRes);
	}

	void PNTBoneModelDraw::SetMeshResource(const wstring& MeshKey) {
		PNTBoneModelDraw::SetMeshResource(App::GetApp()->GetResource<MeshResource>(MeshKey));
	}

	const vector< Matrix4X4 >* PNTBoneModelDraw::GetVecLocalBonesPtr() const {
		return &pImpl->m_LocalBonesMatrix;
	}


	void PNTBoneModelDraw::AddAnimation(const wstring& Name, int StartSample, int SampleLength, bool Loop,
		float SamplesParSecond) {
		if (Name == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (Name == L\"\")",
				L"PNTBoneModelDraw::AddAnimation()"
			);
		}
		if (StartSample < 0 || SampleLength < 0) {
			throw BaseException(
				L"�J�n�T���v�����T���v������0�����ł�",
				L"if (StartSample < 0 || SampleLength < 0)",
				L"PNTBoneModelDraw::AddAnimation()"
			);
		}
		if (SamplesParSecond <= 0.0f) {
			throw BaseException(
				L"�T���v�����b��0�ȉ��ł�",
				L"if (SamplesParSecond <= 0.0f)",
				L"PNTBoneModelDraw::AddAnimation()"
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

	void PNTBoneModelDraw::ChangeCurrentAnimation(const wstring& AnemationName, float StartTime) {
		if (AnemationName == L"") {
			throw BaseException(
				L"�A�j���[�V���������󔒂ł�",
				L"if (AnemationName == L\"\")",
				L"PNTBoneModelDraw::SetCurrentAnimation()"
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
				L"PNTBoneModelDraw::SetCurrentAnimation()"
			);
		}
	}

	const wstring& PNTBoneModelDraw::GetCurrentAnimation() const {
		return pImpl->m_CurrentAnimeName;
	}

	bool PNTBoneModelDraw::UpdateAnimation(float ElapsedTime) {
		if (ElapsedTime < 0.0f) {
			throw BaseException(
				L"�A�j���[�V�����X�V�Ƀ}�C�i�X�͐ݒ�ł��܂���",
				L"if (ElapsedTime < 0.0f)",
				L"PNTBoneModelDraw::UpdateAnimation()"
			);
		}
		if (pImpl->m_CurrentAnimeName == L"") {
			//������Ȃ�
			throw BaseException(
				L"�J�����g�A�j���[�V�������ݒ肳��Ă܂���",
				L"if (pImpl->m_CurrentAnimeName == L\"\")",
				L"PNTBoneModelDraw::UpdateAnimation()"
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


	void PNTBoneModelDraw::InterpolationMatrix(const Matrix4X4& m1, const Matrix4X4& m2, float t, Matrix4X4& out) {
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

	void PNTBoneModelDraw::DrawWithShadow() {
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
				L"PNTBoneModelDraw::OnDraw()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		auto GameObjectPtr = GetGameObject();
		//�s��̒�`
		auto PtrTrans = GameObjectPtr->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, ViewMat, ProjMat;
		//���[���h�s��̌���
		World = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = GameObjectPtr->OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		ViewMat = CameraPtr->GetViewMatrix();
		//�]�u����
		ViewMat.Transpose();
		//�]�u����
		ProjMat = CameraPtr->GetProjMatrix();
		ProjMat.Transpose();
		auto MeshPtr = GetMeshResource();
		auto& MatVec = MeshPtr->GetMaterialExVec();
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionNormalTextureSkinning);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�V�F�[�_�̐ݒ�
		if (GetGameObject()->GetComponent<Shadowmap>(false)) {
			//�V���h�E�}�b�v������Ύ��ȉe�h�~�p�̃s�N�Z���V�F�[�_
			pD3D11DeviceContext->VSSetShader(VSPNTBoneShadow::GetPtr()->GetShader(), nullptr, 0);
			pD3D11DeviceContext->PSSetShader(PSPNTStaticShadow2::GetPtr()->GetShader(), nullptr, 0);
		}
		else {
			pD3D11DeviceContext->VSSetShader(VSPNTBoneShadow::GetPtr()->GetShader(), nullptr, 0);
			pD3D11DeviceContext->PSSetShader(PSPNTStaticShadow::GetPtr()->GetShader(), nullptr, 0);
		}
		//�V���h�E�}�b�v�̃����_���[�^�[�Q�b�g
		auto ShadowmapPtr = Dev->GetShadowMapRenderTarget();
		ID3D11ShaderResourceView* pShadowSRV = ShadowmapPtr->GetShaderResourceView();
		pD3D11DeviceContext->PSSetShaderResources(1, 1, &pShadowSRV);
		//�V���h�E�}�b�v�T���v���[
		ID3D11SamplerState* pShadowSampler = RenderState->GetComparisonLinear();
		pD3D11DeviceContext->PSSetSamplers(1, 1, &pShadowSampler);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPNTBone::GetPtr()->GetInputLayout());
		//�f�v�X�X�e���V��
		SetDeviceDepthStencilState();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		SimpleConstants cb1;
		//�s��̐ݒ�(�]�u����)
		//�R���X�^���g�o�b�t�@�̐ݒ�
		cb1.World = World;
		cb1.View = ViewMat;
		cb1.Projection = ProjMat;
		//���C�e�B���O
		auto StageLight = GameObjectPtr->OnGetDrawLight();
		cb1.LightDir = StageLight.m_Directional;
		cb1.LightDir.w = 1.0f;
		Vector3 CalcLightDir = -1.0 * StageLight.m_Directional;
		Vector3 LightAt = CameraPtr->GetAt();
		Vector3 LightEye = CalcLightDir;
		LightEye *= Shadowmap::GetLightHeight();
		LightEye = LightAt + LightEye;

		cb1.LightPos = LightEye;
		cb1.LightPos.w = 1.0f;

		cb1.EyePos = CameraPtr->GetEye();
		cb1.EyePos.w = 1.0f;

		Matrix4X4 LightView, LightProj;
		//���C�g�̃r���[�Ǝˉe���v�Z
		LightView.LookAtLH(LightEye, LightAt, Vector3(0, 1.0f, 0));
		LightProj.OrthographicLH(Shadowmap::GetViewWidth(), Shadowmap::GetViewHeight(),
			Shadowmap::GetLightNear(), Shadowmap::GetLightFar());
		cb1.LightView = Matrix4X4EX::Transpose(LightView);
		cb1.LightProjection = Matrix4X4EX::Transpose(LightProj);
		cb1.Emissive = GetEmissive();
		cb1.Diffuse = GetDiffuse();
		//�{�[���̐ݒ�
		size_t BoneSz = pImpl->m_LocalBonesMatrix.size();
		UINT cb_count = 0;
		for (size_t b = 0; b < BoneSz; b++) {
			Matrix4X4 mat = pImpl->m_LocalBonesMatrix[b];
			mat.Transpose();
			cb1.Bones[cb_count] = ((XMMATRIX)mat).r[0];
			cb1.Bones[cb_count + 1] = ((XMMATRIX)mat).r[1];
			cb1.Bones[cb_count + 2] = ((XMMATRIX)mat).r[2];
			cb_count += 3;
		}

		for (auto& m : MatVec) {
			if (IsModelEmissivePriority()) {
				cb1.Emissive = m.m_Emissive;
				cb1.Emissive.w = 0;
			}
			if (IsModelDiffusePriority()) {
				cb1.Diffuse = m.m_Diffuse;
			}
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				cb1.ActiveFlg.x = 1;
			}
			else {
				cb1.ActiveFlg.x = 0;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &cb1, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, m.m_TextureResource->GetShaderResourceView().GetAddressOf());
				//�T���v���[
				SetDeviceSamplerState();
			}
			else {
				ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
				ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, 1, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, 1, pNullSR);
			}
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

	void PNTBoneModelDraw::DrawNotShadow() {
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
				L"PNTBoneModelDraw::OnDraw()"
			);
		}
		auto Dev = App::GetApp()->GetDeviceResources();
		auto pD3D11DeviceContext = Dev->GetD3DDeviceContext();
		auto RenderState = Dev->GetRenderState();
		auto GameObjectPtr = GetGameObject();
		//�s��̒�`
		auto PtrTrans = GameObjectPtr->GetComponent<Transform>();
		//�s��̒�`
		Matrix4X4 World, ViewMat, ProjMat;
		//���[���h�s��̌���
		World = GetMeshToTransformMatrix() * PtrTrans->GetWorldMatrix();
		//�]�u����
		World.Transpose();
		//�J�����𓾂�
		auto CameraPtr = GameObjectPtr->OnGetDrawCamera();
		//�r���[�Ǝˉe�s��𓾂�
		ViewMat = CameraPtr->GetViewMatrix();
		//�]�u����
		ViewMat.Transpose();
		//�]�u����
		ProjMat = CameraPtr->GetProjMatrix();
		ProjMat.Transpose();
		auto& MatVec = MeshRes->GetMaterialExVec();
		//�X�g���C�h�ƃI�t�Z�b�g
		UINT stride = sizeof(VertexPositionNormalTextureSkinning);
		UINT offset = 0;
		//���_�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetVertexBuffers(0, 1, MeshRes->GetVertexBuffer().GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pD3D11DeviceContext->IASetIndexBuffer(MeshRes->GetIndexBuffer().Get(), DXGI_FORMAT_R16_UINT, 0);
		//�`����@�i3�p�`�j
		pD3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		//�V�F�[�_�̐ݒ�
		pD3D11DeviceContext->VSSetShader(VSPNTBone::GetPtr()->GetShader(), nullptr, 0);
		pD3D11DeviceContext->PSSetShader(PSPNTStatic::GetPtr()->GetShader(), nullptr, 0);
		//�C���v�b�g���C�A�E�g�̐ݒ�
		pD3D11DeviceContext->IASetInputLayout(VSPNTBone::GetPtr()->GetInputLayout());
		//�f�v�X�X�e���V��
		SetDeviceDepthStencilState();
		//�R���X�^���g�o�b�t�@�̐ݒ�
		SimpleConstants cb1;
		//�s��̐ݒ�(�]�u����)
		//�R���X�^���g�o�b�t�@�̐ݒ�
		cb1.World = World;
		cb1.View = ViewMat;
		cb1.Projection = ProjMat;
		//���C�e�B���O
		auto StageLight = GameObjectPtr->OnGetDrawLight();
		cb1.LightDir = StageLight.m_Directional;
		cb1.LightDir.w = 1.0f;
		cb1.Emissive = GetEmissive();
		cb1.Diffuse = GetDiffuse();
		//�{�[���̐ݒ�
		size_t BoneSz = pImpl->m_LocalBonesMatrix.size();
		UINT cb_count = 0;
		for (size_t b = 0; b < BoneSz; b++) {
			Matrix4X4 mat = pImpl->m_LocalBonesMatrix[b];
			mat.Transpose();
			cb1.Bones[cb_count] = ((XMMATRIX)mat).r[0];
			cb1.Bones[cb_count + 1] = ((XMMATRIX)mat).r[1];
			cb1.Bones[cb_count + 2] = ((XMMATRIX)mat).r[2];
			cb_count += 3;
		}
		for (auto& m : MatVec) {
			if (IsModelEmissivePriority()) {
				cb1.Emissive = m.m_Emissive;
				cb1.Emissive.w = 0;
			}
			if (IsModelDiffusePriority()) {
				cb1.Diffuse = m.m_Diffuse;
			}
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				cb1.ActiveFlg.x = 1;
			}
			else {
				cb1.ActiveFlg.x = 0;
			}
			//�R���X�^���g�o�b�t�@�̍X�V
			pD3D11DeviceContext->UpdateSubresource(CBSimple::GetPtr()->GetBuffer(), 0, nullptr, &cb1, 0, 0);
			//�R���X�^���g�o�b�t�@�̐ݒ�
			ID3D11Buffer* pConstantBuffer = CBSimple::GetPtr()->GetBuffer();
			//���_�V�F�[�_�ɓn��
			pD3D11DeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
			//�s�N�Z���V�F�[�_�ɓn��
			pD3D11DeviceContext->PSSetConstantBuffers(0, 1, &pConstantBuffer);
			if (IsModelTextureEnabled() && m.m_TextureResource) {
				pD3D11DeviceContext->PSSetShaderResources(0, 1, m.m_TextureResource->GetShaderResourceView().GetAddressOf());
				//�T���v���[
				SetDeviceSamplerState();
			}
			else {
				ID3D11ShaderResourceView* pNull[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { nullptr };
				ID3D11SamplerState* pNullSR[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT] = { nullptr };
				//�V�F�[�_�[���\�[�X���N���A
				pD3D11DeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pNull);
				//�T���v���[���N���A
				pD3D11DeviceContext->PSSetSamplers(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT, pNullSR);
			}
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
	void PNTBoneModelDraw::OnDraw() {
		if (GetOwnShadowActive()) {
			DrawWithShadow();
		}
		else {
			DrawNotShadow();
		}
	}


	//--------------------------------------------------------------------------------------
	///	�ėp�`��p�iPNTStatic�Œ�j
	//--------------------------------------------------------------------------------------
	GenericDraw::GenericDraw() :
		ObjectInterface() {}
	GenericDraw::~GenericDraw() {}
	void GenericDraw::OnCreate() {}

	void GenericDraw::DrawWireFrame(const shared_ptr<GameObject>& GameObj,
		const shared_ptr<MeshResource>& Mesh, const Matrix4X4& MeshToTransformMatrix) {
		Draw3DPrim::PCWireFrameDraw(GameObj, Mesh,
			Color4(0,0,0,0), Color4(1, 1, 1, 1), MeshToTransformMatrix);
	}

}
//end basecross

