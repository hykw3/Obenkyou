/*!
@file DeviceResources.h
@brief �e�N�X�`���A���b�V���ADx11�f�o�C�X���\�[�X
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/

#pragma once
#include "stdafx.h"

namespace basecross {


	//--------------------------------------------------------------------------------------
	///	�e�N�X�`�����\�[�X
	//--------------------------------------------------------------------------------------
	class TextureResource : public BaseResource {
		friend class ObjectFactory;
		explicit TextureResource(const wstring& FileName, const wstring& TexType = L"WIC");
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�N�X�`���쐬�p��static�֐�
		@param[in]	FileName	�t�@�C����
		@param[in]	TexType	�e�N�X�`���^�C�v
		*/
		//--------------------------------------------------------------------------------------
		static  shared_ptr<TextureResource> CreateTextureResource(const wstring& FileName, const wstring& TexType = L"WIC");
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~TextureResource();
		//�A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V�F�[�_�[���\�[�X�r���[�̎擾
		@return	���̃e�N�X�`���̃V�F�[�_�[���\�[�X�r���[
		*/
		//--------------------------------------------------------------------------------------
		ComPtr<ID3D11ShaderResourceView>& GetShaderResourceView() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�N�X�`���̃t�@�C�����̎擾
		@return	���̃e�N�X�`���̃t�@�C����
		*/
		//--------------------------------------------------------------------------------------
		const wstring& GetTextureFileName() const;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};

	//--------------------------------------------------------------------------------------
	///	���b�V�����\�[�X
	//--------------------------------------------------------------------------------------
	class MeshResource : public BaseResource {
		friend class ObjectFactory;
		ComPtr<ID3D11Buffer> m_VertexBuffer;	//���_�o�b�t�@
		ComPtr<ID3D11Buffer> m_IndexBuffer;	//�C���f�b�N�X�o�b�t�@
		UINT m_NumVertices;				//���_�̐�
		UINT m_NumIndicis;				//�C���f�b�N�X�̐�
		type_index m_MeshTypeIndex;		//���̃��b�V���̌`
		UINT m_NumStride;				//�X�g���C�h��
		shared_ptr<BackupDataBase> m_BackUpData;
		vector<MaterialEx> m_MaterialExVec;	//�}�e���A���̔z��i���f���Ŏg�p�j
		//�ȉ��A�{�[���p
		bool m_IsSkining;
		UINT m_BoneCount;	//�{�[���̐�
		UINT m_SampleCount;	//�T���v�����O��
		vector<Matrix4X4> m_SampleMatrixVec;	//�T���v�����O���ꂽ�{�[���s��
	protected:
		//�h���N���X����̂݃A�N�Z�X�ł���A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�o�b�t�@�̐ݒ�
		@param[in]	VertexBuffer	���_�o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetVertexBuffer(ComPtr<ID3D11Buffer>& VertexBuffer) {
			m_VertexBuffer = VertexBuffer;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_���̐ݒ�<br />
		���_�o�b�t�@�̐��ƍ��킹�Ȃ���΂Ȃ�Ȃ��̂ŁA�T�d�Ɏg�p����
		@param[in]	NumVertices	���_��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetNumVertices(UINT NumVertices) {
			m_NumVertices = NumVertices;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C���f�b�N�X�o�b�t�@�̐ݒ�
		@param[in]	IndexBuffer	�C���f�b�N�X�o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetIndexBuffer(ComPtr<ID3D11Buffer>& IndexBuffer) {
			m_IndexBuffer = IndexBuffer;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C���f�b�N�X���̐ݒ�<br />
		�C���f�b�N�X�o�b�t�@�̐��ƍ��킹�Ȃ���΂Ȃ�Ȃ��̂ŁA�T�d�Ɏg�p����
		@param[in]	IndexBuffer	�C���f�b�N�X�o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetNumIndicis(UINT NumIndicis) {
			m_NumIndicis = NumIndicis;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�̌^�ƃX�g���C�h��ݒ肷��
		@tparam	T	���_�̌^
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		void SetVertexType() {
			m_MeshTypeIndex = typeid(T);
			m_NumStride = sizeof(T);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�v���e�N�g�R���X�g���N�^<br />
		�\�z�̓X�^�e�B�b�N�֐��𗘗p����
		*/
		//--------------------------------------------------------------------------------------
		MeshResource();
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~MeshResource();
		//�A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�o�b�t�@�̎擾
		@return	���_�o�b�t�@
		*/
		//--------------------------------------------------------------------------------------
		ComPtr<ID3D11Buffer> GetVertexBuffer() const {
			return m_VertexBuffer;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C���f�b�N�X�o�b�t�@�̎擾
		@return	�C���f�b�N�X�o�b�t�@
		*/
		//--------------------------------------------------------------------------------------
		ComPtr<ID3D11Buffer> GetIndexBuffer() const {
			return m_IndexBuffer;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_���̎擾
		@return	���_��
		*/
		//--------------------------------------------------------------------------------------
		UINT GetNumVertices() const {
			return m_NumVertices;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C���f�b�N�X���̎擾
		@return	�C���f�b�N�X��
		*/
		//--------------------------------------------------------------------------------------
		UINT GetNumIndicis() const {
			return m_NumIndicis;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�g���C�h���̎擾
		@return	�X�g���C�h��
		*/
		//--------------------------------------------------------------------------------------
		UINT GetNumStride() const {
			return m_NumStride;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	type_index�̎擾
		@return	type_index
		*/
		//--------------------------------------------------------------------------------------
		type_index GetTypeIndex() const {
			return m_MeshTypeIndex;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�}�e���A���z��̎擾
		@return	�}�e���A���̔z��
		*/
		//--------------------------------------------------------------------------------------
		const vector<MaterialEx>& GetMaterialExVec()const {
			return m_MaterialExVec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�}�e���A���z��̎擾(�������ݗp)
		@return	�}�e���A���̔z��
		*/
		//--------------------------------------------------------------------------------------
		vector<MaterialEx>& GetMaterialExVec(){
			return m_MaterialExVec;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�L�j���O���邩�ǂ���.<br />
		���z�֐��Ȃ̂ŁA�h���N���X�œƎ��ɑ��d��`����
		@return	�X�L�j���O����ꍇ��true
		*/
		//--------------------------------------------------------------------------------------
		virtual bool IsSkining() const { return m_IsSkining; }
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�{�[�����𓾂�
		@return	�{�[����
		*/
		//--------------------------------------------------------------------------------------
		UINT GetBoneCount() const {
			return m_BoneCount;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�T���v�����O���𓾂�
		@return	�T���v�����O��
		*/
		//--------------------------------------------------------------------------------------
		UINT GetSampleCount() const {
			return m_SampleCount;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�T���v�����O���ꂽ�s��̔z��𓾂�
		@return	�T���v�����O���ꂽ�s��̔z��̎Q��
		*/
		//--------------------------------------------------------------------------------------
		const vector<Matrix4X4>& GetSampleMatrixVec() const {
			return m_SampleMatrixVec;
		}
		//���\�[�X�\�z
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�o�b�t�@���쐬����
		@param[in]	pDx11Device	�f�o�C�X
		@param[in]	pBufferDesc	�o�b�t�@�f�X�N�v���^
		@param[in]	pDataDesc	�f�[�^�f�X�N�v���^
		@param[out]	pBuffer	���_�o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void CreatePrimitiveBuffer(ID3D11Device* pDx11Device, const D3D11_BUFFER_DESC* pBufferDesc, const D3D11_SUBRESOURCE_DATA* pDataDesc, ID3D11Buffer** pBuffer) {
			if (FAILED(pDx11Device->CreateBuffer(pBufferDesc, pDataDesc, pBuffer))) {
				// ���������s
				throw BaseException(
					L"�o�b�t�@�쐬�Ɏ��s���܂����B",
					L"if(FAILED(pDx11Device->CreateBuffer()))",
					L"VertexUtil::CreatePrimitiveBuffer()"
				);
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�o�b�t�@���쐬����
		@tparam	T	�f�[�^�̌^
		@param[in]	pDx11Device	�f�o�C�X
		@param[in]	data	�f�[�^
		@param[in]	bindFlags	�o�C���h�t���O
		@param[out]	pBuffer	�o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static void CreatePrimitiveBuffer(ID3D11Device* pDx11Device, T const& data, D3D11_BIND_FLAG bindFlags, ID3D11Buffer** pBuffer) {
			D3D11_BUFFER_DESC bufferDesc = { 0 };
			bufferDesc.ByteWidth = (UINT)data.size() * sizeof(T::value_type);
			bufferDesc.BindFlags = bindFlags;
			bufferDesc.Usage = D3D11_USAGE_DEFAULT;

			D3D11_SUBRESOURCE_DATA dataDesc = { 0 };
			dataDesc.pSysMem = &data.front();

			if (FAILED(pDx11Device->CreateBuffer(&bufferDesc, &dataDesc, pBuffer))) {
				// ���������s
				throw BaseException(
					L"�o�b�t�@�쐬�Ɏ��s���܂����B",
					L"if(FAILED(pDx11Device->CreateBuffer()))",
					L"VertexUtil::CreatePrimitiveBuffer()"
				);
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�o�b�t�@���쐬����
		@tparam	T	���_�̌^
		@param[out]	VertexBuffer	�Ԃ����o�b�t�@
		@param[in]	data	�f�[�^
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static void CreateVertexBuffer(ComPtr<ID3D11Buffer>& VertexBuffer, T const& data) {
			mutex Mutex;
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pDx11Device = Dev->GetD3DDevice();
			Util::DemandCreate(VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
			{
				//���_�o�b�t�@�̍쐬
				MeshResource::CreatePrimitiveBuffer(pDx11Device, data, D3D11_BIND_VERTEX_BUFFER, pResult);
			});
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C���f�b�N�X�o�b�t�@���쐬����
		@tparam	T	�C���f�b�N�X�̌^
		@param[out]	IndexBuffer	�Ԃ����o�b�t�@
		@param[in]	data	�f�[�^
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static void CreateIndexBuffer(ComPtr<ID3D11Buffer>& IndexBuffer, T const& data) {
			mutex Mutex;
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pDx11Device = Dev->GetD3DDevice();
			Util::DemandCreate(IndexBuffer, Mutex, [&](ID3D11Buffer** pResult)
			{
				//�C���f�b�N�X�o�b�t�@�̍쐬
				MeshResource::CreatePrimitiveBuffer(pDx11Device, data, D3D11_BIND_INDEX_BUFFER, pResult);
			});
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�f�[�^��ύX�ł��钸�_�o�b�t�@���쐬����
		@tparam	T	���_�̌^
		@param[in]	pDx11Device	�f�o�C�X
		@param[in]	data	�f�[�^
		@param[out]	pBuffer	�Ԃ����o�b�t�@
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static void CreateDynamicPrimitiveVertexBuffer(ID3D11Device* pDx11Device, T const& data, ID3D11Buffer** pBuffer) {
			D3D11_BUFFER_DESC bufferDesc = { 0 };
			bufferDesc.ByteWidth = (UINT)data.size() * sizeof(T::value_type);
			bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
			bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

			D3D11_SUBRESOURCE_DATA dataDesc = { 0 };
			dataDesc.pSysMem = &data.front();

			if (FAILED(pDx11Device->CreateBuffer(&bufferDesc, &dataDesc, pBuffer))) {
				// ���������s
				throw BaseException(
					L"�o�b�t�@�쐬�Ɏ��s���܂����B",
					L"if(FAILED(pDx11Device->CreateBuffer()))",
					L"VertexUtil::CreateDynamicVertexBuffer()"
				);
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�f�[�^��ύX�ł��钸�_�o�b�t�@���쐬����
		@tparam	T	���_�̌^
		@param[out]	VertexBuffer	�Ԃ����o�b�t�@
		@param[in]	data	�f�[�^
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static void CreateDynamicVertexBuffer(ComPtr<ID3D11Buffer>& VertexBuffer, T const& data) {
			mutex Mutex;
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pDx11Device = Dev->GetD3DDevice();
			Util::DemandCreate(VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
			{
				//���_�o�b�t�@�̍쐬
				MeshResource::CreateDynamicPrimitiveVertexBuffer(pDx11Device, data, pResult);
			});
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	4�p�`���ʂ̍쐬
		@param[in]	size		1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateSquare(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�L���[�u�i�����́j�̍쐬
		@param[in]	size	1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateCube(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���̂̍쐬
		@param[in]	Diameter	���a
		@param[in]	Tessellation	������
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateSphere(float Diameter, size_t Tessellation, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z���̍쐬
		@param[in]	Diameter	���a
		@param[in]	Height	����
		@param[in]	Tessellation	������
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateCapsule(float Diameter, float Height, size_t Tessellation, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V�����_�[�̍쐬
		@param[in]	Height	����
		@param[in]	Diameter	���a
		@param[in]	Tessellation	������
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateCylinder(float Height, float Diameter, size_t Tessellation, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R�[���̍쐬
		@param[in]	Diameter	���a
		@param[in]	Height	����
		@param[in]	Tessellation	������
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateCone(float Diameter, float Height, size_t Tessellation, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�g�[���X�̍쐬
		@param[in]	Diameter	���a
		@param[in]	Thickness	�h�[�i�b�c�̑���
		@param[in]	Tessellation	������
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateTorus(float Diameter, float Thickness, size_t Tessellation, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��4�ʑ̂̍쐬
		@param[in]	Size	1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateTetrahedron(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��8�ʑ̂̍쐬
		@param[in]	Size	1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateOctahedron(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��12�ʑ̂̍쐬
		@param[in]	Size	1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateDodecahedron(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��20�ʑ̂̍쐬
		@param[in]	Size	1�ӂ̃T�C�Y
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateIcosahedron(float Size, bool AccessWrite = false);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I���W�i�����b�V���f�[�^�̓ǂݍ��݁i�X�^�e�B�b�N���b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[out]	vertices	���_�̎Q��
		@param[out]	indices	�C���f�b�N�X�̎Q��
		@param[out]	materials	�}�e���A���̎Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ReadBaseData(const wstring& BinDataDir, const wstring& BinDataFile,
			vector<VertexPositionNormalTexture>& vertices, vector<VertexPositionNormalTangentTexture>& vertices_withtan,
			vector<uint16_t>& indices, vector<MaterialEx>& materials);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I���W�i�����b�V���f�[�^�̓ǂݍ��݁i�{�[�����b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[out]	vertices	���_�̎Q��
		@param[out]	indices	�C���f�b�N�X�̎Q��
		@param[out]	materials	�}�e���A���̎Q��
		@param[out]	bonematrix	�{�[���s��̎Q��
		@param[out]	BoneCount	�{�[�����̎Q��
		@param[out]	SampleCount	�T���v�����̎Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ReadBaseBoneData(const wstring& BinDataDir, const wstring& BinDataFile,
			vector<VertexPositionNormalTextureSkinning>& vertices, vector<VertexPositionNormalTangentTextureSkinning>& vertices_withtan,
			vector<uint16_t>& indices, vector<MaterialEx>& materials,
			vector<Matrix4X4>& bonematrix, UINT& BoneCount, UINT& SampleCount);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I���W�i�����b�V���̍쐬�i�X�^�e�B�b�N���b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateStaticModelMesh(const wstring& BinDataDir,
			const wstring& BinDataFile, bool AccessWrite = false);

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�^���W�F���g�t���I���W�i�����b�V���̍쐬�i�X�^�e�B�b�N���b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateStaticModelMeshWithTangent(const wstring& BinDataDir,
			const wstring& BinDataFile, bool AccessWrite = false);


		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I���W�i�����b�V���̍쐬�i�{�[�����b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateBoneModelMesh(const wstring& BinDataDir,
			const wstring& BinDataFile, bool AccessWrite = false);

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I���W�i�����b�V���̍쐬�i�{�[�����b�V���j
		@param[in]	BinDataDir	��f�B���N�g��
		@param[in]	BinDataFile	�f�[�^�t�@�C����
		@param[in]	AccessWrite = false	���_��ύX�ł��邩�ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		static shared_ptr<MeshResource> CreateBoneModelMeshWithTangent(const wstring& BinDataDir,
			const wstring& BinDataFile, bool AccessWrite = false);

		//--------------------------------------------------------------------------------------
		/*!
		@brief	���b�V�����\�[�X�̍쐬
		@tparam	T	���_�^
		@param[in]	vertices	���_�̔z��
		@param[in]	AccessWrite	�㏑���\���ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static  shared_ptr<MeshResource> CreateMeshResource(const vector<T>& vertices, bool AccessWrite) {
			std::mutex Mutex;
			//�f�o�C�X�̎擾
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pDx11Device = Dev->GetD3DDevice();
			auto Ptr = ObjectFactory::Create<MeshResource>();
			//�o�b�t�@�̍쐬
			if (AccessWrite) {
				Util::DemandCreate(Ptr->m_VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
				{
					auto PtrBackup = shared_ptr< BackupData<T> >(new  BackupData<T>());
					for (auto& v : vertices) {
						PtrBackup->m_Vertices.push_back(v);
					}
					Ptr->m_BackUpData = PtrBackup;
					//���_�o�b�t�@�̍쐬
					MeshResource::CreateDynamicPrimitiveVertexBuffer(pDx11Device, vertices, pResult);
				});
			}
			else {
				Util::DemandCreate(Ptr->m_VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
				{
					//���_�o�b�t�@�̍쐬
					MeshResource::CreatePrimitiveBuffer(pDx11Device, vertices, D3D11_BIND_VERTEX_BUFFER, pResult);
				});
			}
			//���_���̐ݒ�
			Ptr->m_NumVertices = static_cast<UINT>(vertices.size());
			Ptr->m_MeshTypeIndex = typeid(T);
			Ptr->m_NumStride = sizeof(T);
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���b�V�����\�[�X�̍쐬
		@tparam	T	���_�̌^
		@param[in]	vertices	���_�̔z��
		@param[in]	indices	�C���f�b�N�X�̔z��
		@param[in]	AccessWrite	�㏑���\���ǂ���
		@return	���\�[�X�̃X�}�[�g�|�C���^
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static  shared_ptr<MeshResource> CreateMeshResource(const vector<T>& vertices, const vector<uint16_t>& indices, bool AccessWrite) {
			std::mutex Mutex;
			//�f�o�C�X�̎擾
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pDx11Device = Dev->GetD3DDevice();
			auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
			auto Ptr = ObjectFactory::Create<MeshResource>();
			//�o�b�t�@�̍쐬
			if (AccessWrite) {
				Util::DemandCreate(Ptr->m_VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
				{
					auto PtrBackup = shared_ptr< BackupData<T> >(new  BackupData<T>());
					for (auto& v : vertices) {
						PtrBackup->m_Vertices.push_back(v);
					}
					Ptr->m_BackUpData = PtrBackup;
					//���_�o�b�t�@�̍쐬
					MeshResource::CreateDynamicPrimitiveVertexBuffer(pDx11Device, vertices, pResult);
				});
			}
			else {
				Util::DemandCreate(Ptr->m_VertexBuffer, Mutex, [&](ID3D11Buffer** pResult)
				{
					//���_�o�b�t�@�̍쐬
					MeshResource::CreatePrimitiveBuffer(pDx11Device, vertices, D3D11_BIND_VERTEX_BUFFER, pResult);
				});
			}
			//���_���̐ݒ�
			Ptr->m_NumVertices = static_cast<UINT>(vertices.size());
			//�C���f�b�N�X�̍쐬
			Util::DemandCreate(Ptr->m_IndexBuffer, Mutex, [&](ID3D11Buffer** pResult)
			{
				//�C���f�b�N�X�o�b�t�@�̍쐬
				MeshResource::CreatePrimitiveBuffer(pDx11Device, indices, D3D11_BIND_INDEX_BUFFER, pResult);
			});
			//�C���f�b�N�X���̐ݒ�
			Ptr->m_NumIndicis = static_cast<UINT>(indices.size());
			Ptr->m_MeshTypeIndex = typeid(T);
			Ptr->m_NumStride = sizeof(T);
			return Ptr;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�o�b�N�A�b�v�f�[�^�̎擾<br />
		AccessWrite��true�ō쐬���ꂽ���\�[�X�́A���_�̔z��ɂ���Ē��_��ύX�ł���B<br />
		AccessWrite��true�łȂ��ꍇ�́A�o�b�N�A�b�v�͋�ł���B
		@tparam	T	���_�̌^
		@param	�Ȃ�
		@return	�o�b�N�A�b�v�f�[�^�̔z��B
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		vector<T>& GetBackupVerteces() const {
			auto Ptr = dynamic_pointer_cast< BackupData<T> >(m_BackUpData);
			if (!Ptr) {
				throw BaseException(
					L"�o�b�N�A�b�v��T�^�ɃL���X�g�ł��܂���",
					Util::GetWSTypeName<T>(),
					L"MeshResource::GetBackupVerteces<T>()"
				);
			}
			return Ptr->m_Vertices;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���_�̕ύX.<br />
		AccessWrite��true�ō쐬���ꂽ���\�[�X�́A���_�̔z��ɂ���Ē��_��ύX����B
		@tparam	T	���_�̌^
		@param[in]	NewBuffer	���_�̔z��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		void UpdateVirtexBuffer(const vector<T>& NewBuffer) {
			auto Ptr = dynamic_pointer_cast< BackupData<T> >(m_BackUpData);
			if (!Ptr) {
				throw BaseException(
					L"�o�b�N�A�b�v��T�^�ɃL���X�g�ł��܂���",
					Util::GetWSTypeName<T>(),
					L"MeshResource::UpdateVirtexBuffer<T>()"
				);
			}

			if (NewBuffer.size() != Ptr->m_Vertices.size()) {
				// Map���s
				throw BaseException(
					L"�ύX���钸�_�̐����o�b�N�A�b�v�ƈႢ�܂�",
					L"if (NewBuffer.size() != Ptr->m_Vertices.size())",
					L"MeshResource::UpdateVirtexBuffer<T>()"
				);
			}
			//���W��ύX����
			auto Dev = App::GetApp()->GetDeviceResources();
			auto pID3D11DeviceContext = Dev->GetD3DDeviceContext();
			//���_�o�b�t�@�����\�[�X������o��
			auto pVertexBuffer = GetVertexBuffer().Get();

			//D3D11_MAP_WRITE_DISCARD�͏d�v�B���̏����ɂ��AGPU�Ɏז�����Ȃ�
			D3D11_MAP mapType = D3D11_MAP_WRITE_DISCARD;
			D3D11_MAPPED_SUBRESOURCE mappedBuffer;
			//���_�̃}�b�v
			if (FAILED(pID3D11DeviceContext->Map(pVertexBuffer, 0, mapType, 0, &mappedBuffer))) {
				// Map���s
				throw BaseException(
					L"���_��Map�Ɏ��s���܂����B",
					L"if(FAILED(pID3D11DeviceContext->Map()))",
					L"MeshResource::UpdateVirtexBuffer<T>()"
				);
			}
			//���_�̕ύX
			T* vertices = (T*)mappedBuffer.pData;
			for (size_t i = 0; i < NewBuffer.size(); i++) {
				vertices[i] = NewBuffer[i];
			}
			//�A���}�b�v
			pID3D11DeviceContext->Unmap(pVertexBuffer, 0);

		}
	};

	class AudioResource;
	//--------------------------------------------------------------------------------------
	///	�}���`�T�E���h�Ŏg�p����A�C�e��
	//--------------------------------------------------------------------------------------
	struct SoundItem {
		weak_ptr<AudioResource> m_AudioResource;
//		ComPtr<IXAudio2SourceVoice> m_SourceVoice;
		IXAudio2SourceVoice* m_SourceVoice;
		SoundItem() :
			m_SourceVoice(nullptr)
		{}
		~SoundItem() {
		}
	};

	//--------------------------------------------------------------------------------------
	//	�}���`�I�[�f�B�I
	// ���R���|�[�l���g�ł͂Ȃ��̂ŃV�[���Ɏ������邱�Ƃ��ł���
	//--------------------------------------------------------------------------------------
	class MultiAudioObject : public ObjectInterface {
	public:
		//�\�z�Ɣj��
		MultiAudioObject();
		virtual ~MultiAudioObject();
		//�A�N�Z�T
		shared_ptr<AudioResource> GetAudioResource(const wstring& ResKey, bool ExceptionActive = true) const;
		//����
		shared_ptr<AudioResource> AddAudioResource(const wstring& ResKey);
		void RemoveAudioResource(const wstring& ResKey);
		void Start(const wstring& ResKey, const XAUDIO2_BUFFER& Buffer, float Volume = 1.0f);
		void Start(const wstring& ResKey, size_t LoopCount = 0, float Volume = 1.0f);
		void Stop(const wstring& ResKey);

		virtual void OnCreate() override {}
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};



	//�ėp�I�Ȑݒ�p��`

	//--------------------------------------------------------------------------------------
	///	�u�����h�X�e�[�g
	//--------------------------------------------------------------------------------------
	enum class BlendState {
		Opaque,
		AlphaBlend,
		Additive,
		NonPremultiplied,
	};

	//--------------------------------------------------------------------------------------
	///	�f�v�X�X�e���V���X�e�[�g
	//--------------------------------------------------------------------------------------
	enum class DepthStencilState {
		None,
		Default,
		Read,
	};

	//--------------------------------------------------------------------------------------
	///	���X�^���C�U�X�e�[�g
	//--------------------------------------------------------------------------------------
	enum class RasterizerState {
		CullNone,
		CullFront,
		CullBack,
		Wireframe,
	};

	//--------------------------------------------------------------------------------------
	///	�T���v���[�X�e�[�g
	//--------------------------------------------------------------------------------------
	enum class SamplerState {
		SamplerNone,
		PointWrap,
		PointClamp,
		LinearWrap,
		LinearClamp,
		AnisotropicWrap,
		AnisotropicClamp,
		ComparisonLinear,
	};


	//--------------------------------------------------------------------------------------
	///	�p�C�v���C����`
	//--------------------------------------------------------------------------------------
	struct PipeLineDesc {
		//--------------------------------------------------------------------------------------
		//	�u�����h�X�e�[�g
		//--------------------------------------------------------------------------------------
		BlendState m_BlendState;
		//--------------------------------------------------------------------------------------
		//	�f�v�X�X�e���V���X�e�[�g
		//--------------------------------------------------------------------------------------
		DepthStencilState m_DepthStencilState;
		//--------------------------------------------------------------------------------------
		//	���X�^���C�U�X�e�[�g
		//--------------------------------------------------------------------------------------
		RasterizerState m_RasterizerState;
	};

	class DefaultRenderTarget;
	class ShadowMapRenderTarget;
	class RenderState;
	//--------------------------------------------------------------------------------------
	///	DirectX11�f�o�C�X�N���X
	//--------------------------------------------------------------------------------------
	class DeviceResources {
	public:
		//�\�z�Ɣj��
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	hWnd	�E�C���h�E�̃n���h��
		@param[in]	isFullScreen	�t���X�N���[�����ǂ���
		@param[in]	Width	��
		@param[in]	Height	����
		*/
		//--------------------------------------------------------------------------------------
		DeviceResources(HWND hWnd, bool isFullScreen, UINT Width, UINT Height);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~DeviceResources();
		//--------------------------------------------------------------------------------------
		/*!
		@brief �R���e���c�̍쐬��̏����iDx12�ƌ݊�����ۂ��߂ɂ���j
		@param[in]	ShadowActive	�e���L�����ǂ���
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void AfterInitContents(bool ShadowActive) {}
		//D3D�A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D3D11Device2�C���^�[�t�F�C�X�̎擾
		@return	D3D11Device2�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		ID3D11Device2* GetD3DDevice() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D3D11DeviceContext2�C���^�[�t�F�C�X�̎擾
		@return	D3D11DeviceContext2�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DeviceContext2* GetD3DDeviceContext() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	DXGISwapChain1�C���^�[�t�F�C�X�̎擾
		@return	DXGISwapChain1�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		IDXGISwapChain1* GetSwapChain() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D3D_FEATURE_LEVEL�̎擾
		@return	D3D_FEATURE_LEVEL
		*/
		//--------------------------------------------------------------------------------------
		D3D_FEATURE_LEVEL GetFeatureLevel() const;
		// D2D �A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D2D1Factory2�C���^�[�t�F�C�X�̎擾
		@return	D2D1Factory2�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		ID2D1Factory2* GetD2DFactory() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D2D1Device1�C���^�[�t�F�C�X�̎擾
		@return	D2D1Device1�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		ID2D1Device1* GetD2DDevice() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	D2D1DeviceContext1�C���^�[�t�F�C�X�̎擾
		@return	D2D1DeviceContext1�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		ID2D1DeviceContext1* GetD2DDeviceContext() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	DWriteFactory2�C���^�[�t�F�C�X�̎擾
		@return	DWriteFactory2�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		IDWriteFactory2* GetDWriteFactory() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	WICImagingFactory2�C���^�[�t�F�C�X�̎擾
		@return	WICImagingFactory2�C���^�[�t�F�C�X
		*/
		//--------------------------------------------------------------------------------------
		IWICImagingFactory2* GetWicImagingFactory() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̃N���A
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void ClearShadowmapViews();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�`��̊J�n
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void StartShadowmapDraw();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�`��̏I��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void EndShadowmapDraw();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ʏ�`��̃N���A
		@param[in]	col	�N���A�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void ClearDefaultViews(const Color4& col = Color4(0, 0, 0, 1.0f));
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ʏ�`��̊J�n
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void StartDefaultDraw();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ʏ�`��̏I��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void EndDefaultDraw();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�`��̌�n��<br />
		���ׂẴp�C�v���C���ݒ���f�t�H���g�ɖ߂�
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void InitializeStates();
		//--------------------------------------------------------------------------------------
		/*!
		@brief �f�t�H���g�̃����_�����O�^�[�Q�b�g�̎擾
		@return	�f�t�H���g�̃����_�����O�^�[�Q�b�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<DefaultRenderTarget> GetDefaultRenderTarget();
		//--------------------------------------------------------------------------------------
		/*!
		@brief �V���h�E�}�b�v�̃����_�����O�^�[�Q�b�g�̎擾
		@return	�V���h�E�}�b�v�̃����_�����O�^�[�Q�b�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<ShadowMapRenderTarget> GetShadowMapRenderTarget(float ShadowMapDimension = 2048.0f);
		//--------------------------------------------------------------------------------------
		/*!
		@brief �����_�����O�X�e�[�g�̎擾
		@return	�����_�����O�X�e�[�g
		*/
		//--------------------------------------------------------------------------------------
		shared_ptr<RenderState> GetRenderState()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief �t�����g�o�b�t�@�ɓ]��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void Present(unsigned int SyncInterval, unsigned int  Flags);

	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
		//�R�s�[�֎~
		DeviceResources(const DeviceResources&) = delete;
		DeviceResources& operator=(const DeviceResources&) = delete;
		//���[�u�֎~
		DeviceResources(const DeviceResources&&) = delete;
		DeviceResources& operator=(const DeviceResources&&) = delete;
	};



	//--------------------------------------------------------------------------------------
	///	�����_�����O�X�e�[�g�N���X
	//--------------------------------------------------------------------------------------
	class RenderState {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		RenderState();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~RenderState();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�h��Ԃ��̃u�����h�X�e�[�g�̎擾
		@return	�u�����h�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11BlendState* GetOpaque()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�P���ȓ��������̎擾
		@return	�u�����h�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11BlendState* GetAlphaBlend()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����������̎擾
		@return	�u�����h�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11BlendState* GetAlphaBlendEx()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���Z�����̎擾
		@return	�u�����h�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11BlendState* GetAdditive()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�A���t�@���g�p�������̃f�[�^�ƑΏۃf�[�^���u�����h�����̎擾
		@return	�u�����h�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11BlendState* GetNonPremultiplied()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�[�x�����Ȃ��̃f�v�X�X�e���V���X�e�[�g�̎擾
		@return	�f�v�X�X�e���V���X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DepthStencilState* GetDepthNone()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ʏ�[�x�̃f�v�X�X�e���V���X�e�[�g�̎擾
		@return	�f�v�X�X�e���V���X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DepthStencilState* GetDepthDefault()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ǂݎ���p�̃f�v�X�X�e���V���X�e�[�g�̎擾
		@return	�f�v�X�X�e���V���X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DepthStencilState* GetDepthRead()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�����O�Ȃ��̃��X�^���C�U�X�e�[�g�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullNone()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�����O�Ȃ��̃��X�^���C�U�X�e�[�g�i�V�[�T�[�����j�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullNoneScissor()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�����g�J�����O�i�w�ʕ`��̂݁j�̃��X�^���C�U�X�e�[�g�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullFront()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�����g�J�����O�i�w�ʕ`��̂݁j�̃��X�^���C�U�X�e�[�g�i�V�[�T�[�����j�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullFrontScissor()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�o�b�N�J�����O�i�O�ʕ`��̂݁j�̃��X�^���C�U�X�e�[�g�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullBack()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�o�b�N�J�����O�i�O�ʕ`��̂݁j�̃��X�^���C�U�X�e�[�g�i�V�[�T�[�����j�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetCullBackScissor()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���C�A�t���[���̃��X�^���C�U�X�e�[�g�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetWireframe()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���C�A�t���[���̃��X�^���C�U�X�e�[�g�i�V�[�T�[�����j�̎擾
		@return	���X�^���C�U�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RasterizerState* GetWireframeScissor()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_�t�B���^�����O�ƃe�N�X�`���[���W���b�v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetPointWrap()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_�t�B���^�����O�ƃe�N�X�`���[���W�N�����v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetPointClamp()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���`�t�B���^�����O�ƃe�N�X�`���[���W���b�v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetLinearWrap()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���`�t�B���^�����O�ƃe�N�X�`���[���W�N�����v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetLinearClamp()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ٕ����t�B���^�����O�ƃe�N�X�`���[���W���b�v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetAnisotropicWrap()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ٕ����t�B���^�����O�ƃe�N�X�`���[���W�N�����v�̃T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetAnisotropicClamp()const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���`�t�B���^�����O���g������r�T���v���[�X�e�[�g�̎擾
		@return	�T���v���[�X�e�[�g�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11SamplerState* GetComparisonLinear()const;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
		//�R�s�[�֎~
		RenderState(const RenderState&) = delete;
		RenderState& operator=(const RenderState&) = delete;
		//���[�u�֎~
		RenderState(const RenderState&&) = delete;
		RenderState& operator=(const RenderState&&) = delete;
	};

	//--------------------------------------------------------------------------------------
	///	�����_�[�^�[�Q�b�g���N���X
	//--------------------------------------------------------------------------------------
	class RenderTarget {
	protected:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�v���e�N�g�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		RenderTarget();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�v���e�N�g�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~RenderTarget();
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�r���[�|�[�g�𓾂�
		@return	�r���[�|�[�g
		*/
		//--------------------------------------------------------------------------------------
		const D3D11_VIEWPORT& GetViewport() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief �r���[�|�[�g�̐ݒ�
		@param[in]	Viewport	�r���[�|�[�g
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetViewport(const D3D11_VIEWPORT& Viewport);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���N���A���鏃�����z�֐�
		@param[in]	col	�N���A�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void ClearViews(const Color4& col = Color4(0, 0, 0, 1.0f)) = 0;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���J�n���鏃�����z�֐�
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void StartRenderTarget() = 0;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���I�����鏃�����z�֐�
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void EndRenderTarget() = 0;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
		//�R�s�[�֎~
		RenderTarget(const RenderTarget&) = delete;
		RenderTarget& operator=(const RenderTarget&) = delete;
		//���[�u�֎~
		RenderTarget(const RenderTarget&&) = delete;
		RenderTarget& operator=(const RenderTarget&&) = delete;
	};

	class View;
	class Stage;

	//--------------------------------------------------------------------------------------
	///	�V���h�E�}�b�v�̃����_�����O�^�[�Q�b�g
	//--------------------------------------------------------------------------------------
	class ShadowMapRenderTarget : public RenderTarget {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	ShadowMapDimension	�V���h�E�}�b�v�̑傫��
		*/
		//--------------------------------------------------------------------------------------
		ShadowMapRenderTarget(float ShadowMapDimension);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~ShadowMapRenderTarget();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̑傫���𓾂�
		@return	�V���h�E�}�b�v�̑傫��
		*/
		//--------------------------------------------------------------------------------------
		float GetShadowMapDimension() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̃V�F�[�_���\�[�X�r���[�𓾂�
		@return	�V���h�E�}�b�v�̃V�F�[�_���\�[�X�r���[�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11ShaderResourceView* GetShaderResourceView() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̃f�v�X�X�e���V���e�N�X�`���𓾂�
		@return	�V���h�E�}�b�v�̃f�v�X�X�e���V���e�N�X�`���C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11Texture2D*		GetDepthStencil() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�V���h�E�}�b�v�̃f�v�X�X�e���V���V�F�[�_���\�[�X�r���[�𓾂�
		@return	�V���h�E�}�b�v�̃f�v�X�X�e���V���V�F�[�_���\�[�X�r���[�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DepthStencilView*	GetDepthStencilView() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���N���A���鉼�z�֐�
		@param[in]	col	�N���A�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void ClearViews(const Color4& col = Color4(0, 0, 0, 1.0f)) override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���J�n����
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void StartRenderTarget()override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���I������
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void EndRenderTarget()override;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};


	//--------------------------------------------------------------------------------------
	///	�f�t�H���g�̃����_�����O�^�[�Q�b�g
	//--------------------------------------------------------------------------------------
	class DefaultRenderTarget : public RenderTarget {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		explicit DefaultRenderTarget();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~DefaultRenderTarget();
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g�r���[�𓾂�
		@return	�����_�����O�^�[�Q�b�g�r���[�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11RenderTargetView* GetRenderTargetView() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�v�X�X�e���V���e�N�X�`���𓾂�
		@return	�f�v�X�X�e���V���e�N�X�`���C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11Texture2D*		GetDepthStencil() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�v�X�X�e���V���r���[�𓾂�
		@return	�f�v�X�X�e���V���r���[�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID3D11DepthStencilView*	GetDepthStencilView() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�����^�[�Q�b�g�̃r�b�g�}�b�v�𓾂�
		@return	2�����^�[�Q�b�g�̃r�b�g�}�b�v�C���^�[�t�F�C�X�̃|�C���^
		*/
		//--------------------------------------------------------------------------------------
		ID2D1Bitmap1*			GetD2DTargetBitmap() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���N���A���鉼�z�֐��i�X�N���[���S�̂��N���A����j
		@param[in]	col	�N���A�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void ClearViews(const Color4& col = Color4(0, 0, 0, 1.0f)) override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���J�n����
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void StartRenderTarget()override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����_�����O�^�[�Q�b�g���I������
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		virtual void EndRenderTarget()override;
	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};




	//--------------------------------------------------------------------------------------
	///	�V�F�[�_�֘A���\�[�X�̃C���^�[�t�F�C�X
	//--------------------------------------------------------------------------------------
	class ShaderResource {
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	protected:
		ShaderResource();
		virtual ~ShaderResource();
	public:
		static const int m_LightMax{ 3 };
		//--------------------------------------------------------------------------------------
		//	static void ReadBinaryFile(
		//		const wstring& fileName,		//�t�@�C����
		//		unique_ptr<uint8_t[]>& Data,	//�o�C�i���f�[�^�̖߂�
		//		size_t& CsoSz					//�T�C�Y�̖߂�
		//	);
		//	�p�r: �o�C�i���t�@�C����ǂݍ���
		//--------------------------------------------------------------------------------------
		static void ReadBinaryFile(const wstring& fileName, unique_ptr<uint8_t[]>& Data, size_t& CsoSz);
		//--------------------------------------------------------------------------------------
		//	static void CreateVertexShader(
		//		unique_ptr<uint8_t[]>& Data,	//�o�C�i���f�[�^
		//		size_t CsoSz,					//�T�C�Y
		//		ID3D11VertexShader** pResult			//�󂯎��V�F�[�_
		//	);
		//	�p�r: �o�C�i���f�[�^���璸�_�V�F�[�_���쐬����
		//--------------------------------------------------------------------------------------
		static void CreateVertexShader(unique_ptr<uint8_t[]>& Data, size_t CsoSz, ID3D11VertexShader** pResult);
		//--------------------------------------------------------------------------------------
		//	static void CreateInputLayout(
		//		unique_ptr<uint8_t[]>& Data,	//���_�V�F�[�_�̃o�C�i���f�[�^
		//		size_t CsoSz,					//�T�C�Y
		//		const D3D11_INPUT_ELEMENT_DESC* pElement,	//���_��`
		//		UINT NumElement,							//���_��`�̐�
		//		ID3D11InputLayout** pResult			//�󂯎�郌�C�A�E�g
		//	);
		//	�p�r: �o�C�i���f�[�^����C���v�b�g���C�A�E�g���쐬����
		//--------------------------------------------------------------------------------------
		static void CreateInputLayout(unique_ptr<uint8_t[]>& Data, size_t CsoSz,
			const D3D11_INPUT_ELEMENT_DESC* pElement, UINT NumElement, ID3D11InputLayout** pResult);
		//--------------------------------------------------------------------------------------
		//	static void CreatePixelShader(
		//		unique_ptr<uint8_t[]>& Data,	//�o�C�i���f�[�^
		//		size_t CsoSz,					//�T�C�Y
		//		ID3D11PixelShader** pResult			//�󂯎��V�F�[�_
		//	);
		//	�p�r: �o�C�i���f�[�^����s�N�Z���V�F�[�_���쐬����
		//--------------------------------------------------------------------------------------
		static void CreatePixelShader(unique_ptr<uint8_t[]>& Data, size_t CsoSz, ID3D11PixelShader** pResult);
		//--------------------------------------------------------------------------------------
		//	static void CreateGeometryShader(
		//		unique_ptr<uint8_t[]>& Data,	//�o�C�i���f�[�^
		//		size_t CsoSz,					//�T�C�Y
		//		ID3D11GeometryShader** pResult			//�󂯎��V�F�[�_
		//	);
		//	�p�r: �o�C�i���f�[�^����W�I���g���V�F�[�_���쐬����
		//--------------------------------------------------------------------------------------
		static void CreateGeometryShader(unique_ptr<uint8_t[]>& Data, size_t CsoSz, ID3D11GeometryShader** pResult);

		static void CreateGeometryShader(unique_ptr<uint8_t[]>& Data, size_t CsoSz,
			const vector<D3D11_SO_DECLARATION_ENTRY>& SOEntries, UINT Stride, UINT NumStride, ID3D11GeometryShader** pResult);

		//--------------------------------------------------------------------------------------
		//	static void CreateComputeShader(
		//		unique_ptr<uint8_t[]>& Data,	//�o�C�i���f�[�^
		//		size_t CsoSz,					//�T�C�Y
		//		ID3D11ComputeShader** pResult			//�󂯎��V�F�[�_
		//	);
		//	�p�r: �o�C�i���f�[�^����R���s���[�g�V�F�[�_���쐬����
		//--------------------------------------------------------------------------------------
		static void CreateComputeShader(unique_ptr<uint8_t[]>& Data, size_t CsoSz, ID3D11ComputeShader** pResult);
		//--------------------------------------------------------------------------------------
		//	static void CreateConstantBuffer(
		//		UINT BuffSize,					//�T�C�Y
		//		ID3D11Buffer** pResult			//�󂯎��V�F�[�_
		//	);
		//	�p�r: �R���X�^���g�o�b�t�@���쐬����
		//--------------------------------------------------------------------------------------
		static void CreateConstantBuffer(UINT BuffSize, ID3D11Buffer** pResult);
	protected:
		//�~���[�e�b�N�X
		std::mutex MutexBase;
		//�s�N�Z���V�F�[�_�A�N�Z�b�T
		ID3D11PixelShader* GetPixelShaderBase(const wstring& Filename, ComPtr<ID3D11PixelShader>& PSPtr) {
			return Util::DemandCreate(PSPtr, MutexBase, [&](ID3D11PixelShader** pResult)
			{
				std::unique_ptr<uint8_t[]> data;
				//�V�F�[�_�̓ǂݍ���
				size_t cso_sz = 0;
				ShaderResource::ReadBinaryFile(Filename, data, cso_sz);
				ShaderResource::CreatePixelShader(data, cso_sz, pResult);
			});
		}

		//�W�I���g���V�F�[�_�A�N�Z�b�T
		ID3D11GeometryShader* GetGeometryShaderBase(const wstring& Filename, ComPtr<ID3D11GeometryShader>& GSPtr) {
			return Util::DemandCreate(GSPtr, MutexBase, [&](ID3D11GeometryShader** pResult)
			{
				std::unique_ptr<uint8_t[]> data;
				//�V�F�[�_�̓ǂݍ���
				size_t cso_sz = 0;
				ShaderResource::ReadBinaryFile(Filename, data, cso_sz);
				ShaderResource::CreateGeometryShader(data, cso_sz, pResult);
			});
		}


		ID3D11GeometryShader* GetGeometryShaderBase(const wstring& Filename,
			const vector<D3D11_SO_DECLARATION_ENTRY>& SOEntries,
			UINT Stride, UINT NumStride,
			ComPtr<ID3D11GeometryShader>& GSPtr) {
			return Util::DemandCreate(GSPtr, MutexBase, [&](ID3D11GeometryShader** pResult)
			{
				std::unique_ptr<uint8_t[]> data;
				//�V�F�[�_�̓ǂݍ���
				size_t cso_sz = 0;
				ShaderResource::ReadBinaryFile(Filename, data, cso_sz);
				ShaderResource::CreateGeometryShader(data, cso_sz, SOEntries, Stride, NumStride, pResult);
			});
		}

		//�R���s���[�g�V�F�[�_�A�N�Z�b�T
		ID3D11ComputeShader* GetComputeShaderBase(const wstring& Filename, ComPtr<ID3D11ComputeShader>& CSPtr) {
			return Util::DemandCreate(CSPtr, MutexBase, [&](ID3D11ComputeShader** pResult)
			{
				std::unique_ptr<uint8_t[]> data;
				//�V�F�[�_�̓ǂݍ���
				size_t cso_sz = 0;
				ShaderResource::ReadBinaryFile(Filename, data, cso_sz);
				ShaderResource::CreateComputeShader(data, cso_sz, pResult);
			});
		}

		//���_�V�F�[�_�A�N�Z�b�T
		ID3D11VertexShader* GetVertexShaderBase(const wstring& Filename, ComPtr<ID3D11VertexShader>& VSPtr);
		//�C���v�b�g���C�A�E�g�A�N�Z�b�T
		ID3D11InputLayout* GetInputLayoutBase2(const wstring& Filename, ComPtr<ID3D11InputLayout>& ILPtr,
			const D3D11_INPUT_ELEMENT_DESC* pElem, UINT NumElements);
		//�R���X�^���g�o�b�t�@�A�N�Z�b�T
		ID3D11Buffer* GetConstantBufferBase(UINT BuffSize, ComPtr<ID3D11Buffer>& Buffer);
	private:
		//�R�s�[�֎~
		ShaderResource(const ShaderResource&) = delete;
		ShaderResource& operator=(const ShaderResource&) = delete;
		//���[�u�֎~
		ShaderResource(const ShaderResource&&) = delete;
		ShaderResource& operator=(const ShaderResource&&) = delete;
	};

	//--------------------------------------------------------------------------------------
	//	template<typename ShaderType, typename ConstantType>
	//	class ConstantBuffer : public ShaderResource;
	//	�p�r: �R���X�^���g�o�b�t�@
	//--------------------------------------------------------------------------------------
	template<typename ShaderType, typename ConstantType>
	class ConstantBuffer : public ShaderResource {
	protected:
		//�f���[�^�[
		struct Deleter
		{
			void operator()(ShaderType *p) { delete p; }
		};
		ComPtr<ID3D11Buffer> m_Buffer;
		//�~���[�e�b�N�X
		std::mutex Mutex;
		//�\�z�Ɣj��
		ConstantBuffer<ShaderType, ConstantType>() : ShaderResource() {}
		virtual ~ConstantBuffer() {}
		static unique_ptr<ShaderType, Deleter> m_Ptr;
		//�R�s�[�֎~
		ConstantBuffer<ShaderType, ConstantType>(ConstantBuffer const&);
		ConstantBuffer<ShaderType, ConstantType>& operator=(ConstantBuffer<ShaderType, ConstantType> const&);
	public:
		//���J�A�N�Z�b�T
		ID3D11Buffer* GetBuffer() {
			return GetConstantBufferBase(sizeof(ConstantType), m_Buffer);
		}
		//�C���X�^���X�擾
		static unique_ptr<ShaderType, Deleter>& GetPtr() {
			if (!m_Ptr) {
				m_Ptr.reset(new ShaderType());
			}
			return m_Ptr;
		}
	};


	//--------------------------------------------------------------------------------------
	//	template<typename ConstantType>
	//	class CBuffer : public ShaderResource;
	//	�p�r: �R���X�^���g�o�b�t�@
	//--------------------------------------------------------------------------------------
	template<typename ConstantType>
	class CBuffer : public ShaderResource {
		ComPtr<ID3D11Buffer> m_Buffer;
		//�R�s�[�֎~
		CBuffer(CBuffer const&);
		CBuffer& operator=(CBuffer<ConstantType> const&);
	public:
		//�\�z�Ɣj��
		CBuffer() : ShaderResource() {
			GetConstantBufferBase(sizeof(ConstantType), m_Buffer);
		}
		virtual ~CBuffer() {}
		//���J�A�N�Z�b�T
		ID3D11Buffer* GetBuffer() {
			return GetConstantBufferBase(sizeof(ConstantType), m_Buffer);
		}
	};



	//--------------------------------------------------------------------------------------
	//	class VertexShader : public ShaderResource;
	//	�p�r: ���_�V�F�[�_
	//--------------------------------------------------------------------------------------
	template<typename ShaderType, typename VirtexType>
	class VertexShader : public ShaderResource {
		wstring m_Filename;
	protected:
		//�f���[�^�[
		struct Deleter
		{
			void operator()(ShaderType *p) { delete p; }
		};
		ComPtr<ID3D11VertexShader> m_VSPtr;
		ComPtr<ID3D11InputLayout> m_ILPtr;
		//�~���[�e�b�N�X
		std::mutex Mutex;
		//�\�z�Ɣj��
		VertexShader<ShaderType, VirtexType>(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {}
		virtual ~VertexShader() {}
		static unique_ptr<ShaderType, Deleter> m_Ptr;
	public:
		//���_�V�F�[�_���J�A�N�Z�b�T
		ID3D11VertexShader* GetShader() {
			return GetVertexShaderBase(m_Filename, m_VSPtr);
		}
		//�C���v�b�g���C�A�E�g���J�A�N�Z�b�T
		ID3D11InputLayout* GetInputLayout() {
			return GetInputLayoutBase2(m_Filename, m_ILPtr, VirtexType::GetVertexElement(), VirtexType::GetNumElements());
		}
		//�C���X�^���X�擾
		static unique_ptr<ShaderType, Deleter>& GetPtr() {
			if (!m_Ptr) {
				m_Ptr.reset(new ShaderType());
			}
			return m_Ptr;
		}
	};

	//--------------------------------------------------------------------------------------
	//template<typename VirtexType>
	//	class VShader : public ShaderResource;
	//	�p�r: �V���O���g�����������Ȃ����_�V�F�[�_�i�N���C�A���g�Œ��ڎg�p�ł���j
	//--------------------------------------------------------------------------------------
	template<typename VirtexType>
	class VShader : public ShaderResource {
		wstring m_Filename;
		ComPtr<ID3D11VertexShader> m_VSPtr;
		ComPtr<ID3D11InputLayout> m_ILPtr;
	public:
		VShader() : ShaderResource(), m_Filename() {}
		VShader(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {
			GetVertexShaderBase(m_Filename, m_VSPtr);
			GetInputLayoutBase2(m_Filename, m_ILPtr, VirtexType::GetVertexElement(), VirtexType::GetNumElements());
		}
		virtual ~VShader() {}
		void Create(const wstring& Filename) {
			m_Filename = Filename;
			m_VSPtr = nullptr;
			m_ILPtr = nullptr;
			GetVertexShaderBase(m_Filename, m_VSPtr);
			GetInputLayoutBase2(m_Filename, m_ILPtr, VirtexType::GetVertexElement(), VirtexType::GetNumElements());
		}
		//���_�V�F�[�_���J�A�N�Z�b�T
		ID3D11VertexShader* GetShader() {
			return GetVertexShaderBase(m_Filename, m_VSPtr);
		}
		//�C���v�b�g���C�A�E�g���J�A�N�Z�b�T
		ID3D11InputLayout* GetInputLayout() {
			return GetInputLayoutBase2(m_Filename, m_ILPtr, VirtexType::GetVertexElement(), VirtexType::GetNumElements());
		}
	};

	//--------------------------------------------------------------------------------------
	//	template<typename ShaderType>
	//	class PixelShader : public ShaderResource;
	//	�p�r: �s�N�Z���V�F�[�_
	//--------------------------------------------------------------------------------------
	template<typename ShaderType>
	class PixelShader : public ShaderResource {
		wstring m_Filename;
	protected:
		//�f���[�^�[
		struct Deleter
		{
			void operator()(ShaderType *p) { delete p; }
		};
		ComPtr<ID3D11PixelShader> m_PSPtr;
		//�~���[�e�b�N�X
		std::mutex Mutex;
		//�\�z�Ɣj��
		PixelShader<ShaderType>(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {}
		virtual ~PixelShader() {}
		static unique_ptr<ShaderType, Deleter> m_Ptr;
	public:
		//�s�N�Z���V�F�[�_���J�A�N�Z�b�T
		ID3D11PixelShader* GetShader() {
			return GetPixelShaderBase(m_Filename, m_PSPtr);
		}
		//�C���X�^���X�擾
		static unique_ptr<ShaderType, Deleter>& GetPtr() {
			if (!m_Ptr) {
				m_Ptr.reset(new ShaderType());
			}
			return m_Ptr;
		}
	};

	//--------------------------------------------------------------------------------------
	//	class PShader : public ShaderResource;
	//	�p�r: �s�N�Z���V�F�[�_
	//--------------------------------------------------------------------------------------
	class PShader : public ShaderResource {
		wstring m_Filename;
		ComPtr<ID3D11PixelShader> m_PSPtr;
	public:
		//�\�z�Ɣj��
		PShader() : ShaderResource(), m_Filename() {}
		PShader(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {
			GetPixelShaderBase(m_Filename, m_PSPtr);
		}
		virtual ~PShader() {}
		void Create(const wstring& Filename) {
			m_Filename = Filename;
			m_PSPtr = nullptr;
			GetPixelShaderBase(m_Filename, m_PSPtr);
		}
		//�s�N�Z���V�F�[�_���J�A�N�Z�b�T
		ID3D11PixelShader* GetShader() {
			return GetPixelShaderBase(m_Filename, m_PSPtr);
		}
	};



	//--------------------------------------------------------------------------------------
	//	template<typename ShaderType>
	//	class GeometryShader : public ShaderResource;
	//	�p�r: �W�I���g���V�F�[�_
	//--------------------------------------------------------------------------------------
	template<typename ShaderType>
	class GeometryShader : public ShaderResource {
		wstring m_Filename;
		vector<D3D11_SO_DECLARATION_ENTRY> m_SOEntries;
		UINT m_Stride;
		UINT m_NumStride;
	protected:
		//�f���[�^�[
		struct Deleter
		{
			void operator()(ShaderType *p) { delete p; }
		};
		ComPtr<ID3D11GeometryShader> m_GSPtr;
		//�~���[�e�b�N�X
		std::mutex Mutex;
		//�\�z�Ɣj��
		GeometryShader<ShaderType>(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {}
		virtual ~GeometryShader() {}
		static unique_ptr<ShaderType, Deleter> m_Ptr;
		//�X���b�g�G���g���̓o�^
		void SetSOEntries(const vector<D3D11_SO_DECLARATION_ENTRY>& SOEntries,
			UINT Stride, UINT NumStride) {
			m_SOEntries.clear();
			for (auto& rEntry : SOEntries) {
				D3D11_SO_DECLARATION_ENTRY Dest = rEntry;
				m_SOEntries.push_back(Dest);
			}
			m_Stride = Stride;
			m_NumStride = NumStride;
		}
	public:
		//�W�I���g���V�F�[�_���J�A�N�Z�b�T
		ID3D11GeometryShader* GetShader() {
			if (m_SOEntries.size() > 0) {
				return GetGeometryShaderBase(m_Filename, m_SOEntries, m_Stride, m_NumStride, m_GSPtr);
			}
			else {
				return GetGeometryShaderBase(m_Filename, m_GSPtr);
			}
		}
		//�C���X�^���X�擾
		static unique_ptr<ShaderType, Deleter>& GetPtr() {
			if (!m_Ptr) {
				m_Ptr.reset(new ShaderType());
			}
			return m_Ptr;
		}
	};


	//--------------------------------------------------------------------------------------
	//	class GShader : public ShaderResource;
	//	�p�r: �W�I���g���V�F�[�_
	//--------------------------------------------------------------------------------------
	class GShader : public ShaderResource {
		ComPtr<ID3D11GeometryShader> m_GSPtr;
		wstring m_Filename;
		vector<D3D11_SO_DECLARATION_ENTRY> m_SOEntries;
		UINT m_Stride;
		UINT m_NumStride;
	public:
		//�\�z�Ɣj��
		GShader() : ShaderResource(), m_Filename() {}
		GShader(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {}
		virtual ~GShader() {}
		//�X���b�g�G���g���̓o�^
		void SetSOEntries(const vector<D3D11_SO_DECLARATION_ENTRY>& SOEntries,
			UINT Stride, UINT NumStride) {
			m_SOEntries.clear();
			for (auto& rEntry : SOEntries) {
				D3D11_SO_DECLARATION_ENTRY Dest = rEntry;
				m_SOEntries.push_back(Dest);
			}
			m_Stride = Stride;
			m_NumStride = NumStride;
		}
		void Create(const wstring& Filename) {
			m_Filename = Filename;
			m_GSPtr = nullptr;
			if (m_SOEntries.size() > 0) {
				GetGeometryShaderBase(m_Filename, m_SOEntries, m_Stride, m_NumStride, m_GSPtr);
			}
			else {
				GetGeometryShaderBase(m_Filename, m_GSPtr);
			}
		}
		//�W�I���g���V�F�[�_���J�A�N�Z�b�T
		ID3D11GeometryShader* GetShader() {
			if (m_SOEntries.size() > 0) {
				return GetGeometryShaderBase(m_Filename, m_SOEntries, m_Stride, m_NumStride, m_GSPtr);
			}
			else {
				return GetGeometryShaderBase(m_Filename, m_GSPtr);
			}
		}
	};


	//--------------------------------------------------------------------------------------
	//	template<typename ShaderType>
	//	class ComputeShader : public ShaderResource;
	//	�p�r: �R���s���[�g�V�F�[�_
	//--------------------------------------------------------------------------------------
	template<typename ShaderType>
	class ComputeShader : public ShaderResource {
		wstring m_Filename;
	protected:
		//�f���[�^�[
		struct Deleter
		{
			void operator()(ShaderType *p) { delete p; }
		};
		ComPtr<ID3D11ComputeShader> m_CSPtr;
		//�~���[�e�b�N�X
		std::mutex Mutex;
		//�\�z�Ɣj��
		ComputeShader<ShaderType>(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {}
		virtual ~ComputeShader() {}
		static unique_ptr<ShaderType, Deleter> m_Ptr;
	public:
		//�R���s���[�g�V�F�[�_���J�A�N�Z�b�T
		ID3D11ComputeShader* GetShader() {
			return GetComputeShaderBase(m_Filename, m_CSPtr);
		}
		//�C���X�^���X�擾
		static unique_ptr<ShaderType, Deleter>& GetPtr() {
			if (!m_Ptr) {
				m_Ptr.reset(new ShaderType());
			}
			return m_Ptr;
		}
	};

	//--------------------------------------------------------------------------------------
	//	class CShader : public ShaderResource;
	//	�p�r: �R���s���[�g�V�F�[�_
	//--------------------------------------------------------------------------------------
	class CShader : public ShaderResource {
		wstring m_Filename;
		ComPtr<ID3D11ComputeShader> m_CSPtr;
	public:
		//�\�z�Ɣj��
		CShader() : ShaderResource(), m_Filename() {}
		CShader(const wstring& Filename) : ShaderResource(), m_Filename(Filename) {
			GetComputeShaderBase(m_Filename, m_CSPtr);
		}
		virtual ~CShader() {}
		void Create(const wstring& Filename) {
			m_Filename = Filename;
			m_CSPtr = nullptr;
			GetComputeShaderBase(m_Filename, m_CSPtr);
		}
		//�R���s���[�g�V�F�[�_���J�A�N�Z�b�T
		ID3D11ComputeShader* GetShader() {
			return GetComputeShaderBase(m_Filename, m_CSPtr);
		}
	};

	//������ʃV�F�[�_�[
	//�R���X�^���g�o�b�t�@�錾�p�}�N��
#define DECLARE_DX11_CONSTANT_BUFFER(CBName,CBStruct) class CBName : public ConstantBuffer<CBName,CBStruct> { public: };

	//�V�F�[�_�錾�p�}�N��
#define DECLARE_DX11_VERTEX_SHADER(ShaderName,VertexType) class ShaderName : public VertexShader<ShaderName,VertexType>{ public: ShaderName(); };

#define DECLARE_DX11_PIXEL_SHADER(ShaderName) class ShaderName : public PixelShader<ShaderName>{ public: ShaderName(); };

#define DECLARE_DX11_GEOMETRY_SHADER(ShaderName) class ShaderName : public GeometryShader<ShaderName>{ public: ShaderName(); };

	//�R���X�^���g�o�b�t�@���̗p�}�N
#define IMPLEMENT_DX11_CONSTANT_BUFFER(CBName) unique_ptr<CBName, CBName::Deleter> CBName::m_Ptr;

	//�V�F�[�_���̗p�}�N��
#define IMPLEMENT_DX11_VERTEX_SHADER(ShaderName,CsoFilename) unique_ptr<ShaderName, ShaderName::Deleter> ShaderName::m_Ptr; ShaderName::ShaderName() : VertexShader(CsoFilename){}

#define IMPLEMENT_DX11_PIXEL_SHADER(ShaderName,CsoFilename) unique_ptr<ShaderName, ShaderName::Deleter> ShaderName::m_Ptr; ShaderName::ShaderName() : PixelShader(CsoFilename){}

#define IMPLEMENT_DX11_GEOMETRY_SHADER(ShaderName,CsoFilename)	unique_ptr<ShaderName, ShaderName::Deleter> ShaderName::m_Ptr; ShaderName::ShaderName() : GeometryShader(CsoFilename){}




}
//end basecross
