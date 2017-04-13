/*!
@file TransHelper.h
@brief �Փ˔���A��ԏ����p���[�e�B���e�B
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/

#pragma once
#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	Lerp ��ԏ����v�Z�\����
	//--------------------------------------------------------------------------------------
	struct Lerp{
		enum rate{
			Linear,	//1���֐��i���`�j
			Easein,	//2���֐��������㏸
			EaseOut,//2���֐��Ōオ�������
			Cube,	//3���֐�
			Cos		//�R�T�C��
		};
		//--------------------------------------------------------------------------------------
		/*!
		@brief	T�^�̕�Ԍv�Z���s��
		@tparam	T	�v�Z����^
		@param[in]	Start	�J�n�l
		@param[in]	End	�I���l
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[in]	NowTime	���݂̎���
		@param[in]	r	�v�Z���@
		@return	T�^�̌v�Z����
		*/
		//--------------------------------------------------------------------------------------
		template<typename T>
		static T CalculateLerp(const T &Start, const T &End,
		float StartTime, float EndTime, float NowTime, rate r){
			float t = (NowTime - StartTime) / (EndTime - StartTime);
			if (t < 0.0f){
				t = 0;
			}
			if (t > 1.0f){
				t = 1.0f;
			}
			float cal_rate = t;   // 1���֐���Ԓl�ɕϊ�(�f�t�H���g)
			switch (r){
			case Linear:
				cal_rate = t;
				break;
			case Easein:
				cal_rate = t * t;
				break;
			case EaseOut:
				cal_rate = t * (2.0f - t);
				break;
			case Cube:
				cal_rate = t * t * (3.0f - 2.0f * t);
				break;
			case Cos:
				cal_rate = (1.0f - cos(t * XM_PI)) / 2.0f;
				break;
			default:
				break;
			}
			return Start * (1.0f - cal_rate) + End * cal_rate;
		}
	};

	//--------------------------------------------------------------------------------------
	///	XZ�|�C���g(Z�����v���X�̓_)
	//--------------------------------------------------------------------------------------
	struct POINT_XZ {
		float m_X;
		float m_Z;
		POINT_XZ() :
			m_X(0.0f), m_Z(0.0f)
		{}
		POINT_XZ(float x,float z) :
			m_X(x), m_Z(z)
		{}
		POINT_XZ(const POINT_XZ& other) :
			m_X(other.m_X),
			m_Z(other.m_Z)
		{}
		POINT_XZ(const Vector2& other) :
			m_X(other.x),
			m_Z(other.y)
		{}
		POINT_XZ(const Vector3& other) :
			m_X(other.x),
			m_Z(other.z)
		{}
		operator Vector2() {
			return Vector2(m_X,m_Z);
		}
		POINT_XZ& operator=(const POINT_XZ& other) {
			//���ȑ���̗}��
			if (this != &other) {
				m_X = other.m_X;
				m_Z = other.m_Z;
			}
			return *this;
		}
		POINT_XZ& operator=(const Vector2& other) {
			m_X = other.x;
			m_Z = other.y;
			return *this;
		}
		POINT_XZ& operator=(const Vector3& other) {
			m_X = other.x;
			m_Z = other.z;
			return *this;
		}
	};

	//--------------------------------------------------------------------------------------
	///	XZ�����̃Z���Ɏg�p����C���f�b�N�X
	//--------------------------------------------------------------------------------------
	struct CellIndex {
		int x;
		int z;
		CellIndex() :
			//�����l�ŏ�����
			x(-1), z(-1)
		{}
		CellIndex(int xx, int zz) :
			x(xx), z(zz)
		{
		}
		bool operator==(const CellIndex& other)const {
			return (x == other.x && z == other.z);
		}
		bool operator!=(const CellIndex& other)const {
			return ((x != other.x) || (z != other.z));
		}
		static int GetHeuristic(const CellIndex& Cell1, const CellIndex& Cell2) {
			int spanX = abs(Cell1.x - Cell2.x);
			int spanZ = abs(Cell1.z - Cell2.z);
			//�ǂ��炩�����ق���Ԃ�
			return (spanX >= spanZ) ? spanX : spanZ;
		}
	};


	//--------------------------------------------------------------------------------------
	///	XZ��`(Z�����v���X�̋�`)
	//--------------------------------------------------------------------------------------
	struct RECT_XZ {
		float m_Left;
		float m_Near;
		float m_Right;
		float m_Far;
		RECT_XZ() :
			m_Left(0.0f), m_Near(0.0f),
			m_Right(0.0f), m_Far(0.0f)
		{}
		RECT_XZ(float l,float n,float r,float f) :
			m_Left(l), m_Near(n),
			m_Right(r), m_Far(f)
		{}

		POINT_XZ CenterPoint() const{
			return POINT_XZ((m_Left + m_Right) / 2.0f, (m_Near + m_Far) / 2.0f);
		}
		void operator+=(const POINT_XZ& point){
			m_Left += point.m_X;
			m_Right += point.m_X;
			m_Near += point.m_Z;
			m_Far += point.m_Z;
		}
		RECT_XZ operator+(const POINT_XZ& point) const {
			RECT_XZ rect(*this);
			rect += point;
			return rect;
		}
		void operator-=(const POINT_XZ& point) {
			m_Left -= point.m_X;
			m_Right -= point.m_X;
			m_Near -= point.m_Z;
			m_Far -= point.m_Z;
		}
		RECT_XZ operator-(const POINT_XZ& point) const {
			RECT_XZ rect(*this);
			rect -= point;
			return rect;
		}
		bool IsRectEmpty()const{
			if (m_Left >= m_Right || m_Near >= m_Far) {
				return true;
			}
			return false;
		}
		bool PtInRect(const POINT_XZ& point) const{
			if (point.m_X >= m_Left && point.m_X < m_Right
				&& point.m_Z >= m_Near && point.m_Z < m_Far) {
				return true;
			}
			return false;
		}
		bool PtInRect(const Vector2& point) const {
			POINT_XZ p(point);
			return PtInRect(p);
		}
		bool Intersect(const RECT_XZ& rect2) const{
			if (IsRectEmpty() || rect2.IsRectEmpty()) {
				//�ǂ��炩����̏ꍇ��false
				return false;
			}
			if (m_Left > rect2.m_Right) {
				return false;
			}
			if (m_Right < rect2.m_Left) {
				return false;
			}
			if (m_Near > rect2.m_Far) {
				return false;
			}
			if (m_Far < rect2.m_Near) {
				return false;
			}
			return true;
		}


		RECT_XZ UnionRect(const RECT_XZ& rect1, const RECT_XZ& rect2) const{
			RECT_XZ ret;
			ret.m_Left = (rect1.m_Left <= rect2.m_Left) ? rect1.m_Left : rect2.m_Left;
			ret.m_Right = (rect1.m_Right >= rect2.m_Right) ? rect1.m_Right : rect2.m_Right;
			ret.m_Near = (rect1.m_Near <= rect2.m_Near) ? rect1.m_Near : rect2.m_Near;
			ret.m_Far = (rect1.m_Far >= rect2.m_Far) ? rect1.m_Far : rect2.m_Far;
			return ret;
		}
		RECT_XZ UnionRect(const RECT_XZ& other){
			RECT_XZ ret;
			ret.m_Left = (m_Left <= other.m_Left) ? m_Left : other.m_Left;
			ret.m_Right = (m_Right >= other.m_Right) ? m_Right : other.m_Right;
			ret.m_Near = (m_Near <= other.m_Near) ? m_Near : other.m_Near;
			ret.m_Far = (m_Far >= other.m_Far) ? m_Far : other.m_Far;
			*this = ret;
			return ret;
		}
		RECT_XZ operator|=(const RECT_XZ& other) {
			return UnionRect(other);
		}
		RECT_XZ operator|(const RECT_XZ& other) const{
			return UnionRect(*this,other);
		}
		float Width()const{
			return abs(m_Right - m_Left);
		}
		float Dipth()const{
			return abs(m_Far - m_Near);
		}
	};

	struct SPHERE;

	//--------------------------------------------------------------------------------------
	///	AABB�{�����[�����E
	//--------------------------------------------------------------------------------------
	struct AABB {
		Vector3 m_Min;     ///< �������ق��̍��W
		Vector3 m_Max;     ///< �傫���ق��̍��W
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		AABB():
			m_Min(0,0,0),
			m_Max(0, 0, 0){}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Min	�������ق��̍��W
		@param[in]	Max	�傫���ق��̍��W
		*/
		//--------------------------------------------------------------------------------------
		AABB(const Vector3& Min, const Vector3& Max)
			:m_Min(Min), m_Max(Max) {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Center	���S
		@param[in]	XSize	X�����T�C�Y
		@param[in]	YSize	Y�����T�C�Y
		@param[in]	ZSize	Z�����T�C�Y
		*/
		//--------------------------------------------------------------------------------------
		AABB(const Vector3& Center, float XSize, float YSize, float ZSize) {
			float xh = XSize / 2.0f;
			float yh = YSize / 2.0f;
			float zh = ZSize / 2.0f;

			m_Min.x = Center.x - xh;
			m_Max.x = Center.x + xh;

			m_Min.y = Center.y - yh;
			m_Max.y = Center.y + yh;

			m_Min.z = Center.z - zh;
			m_Max.z = Center.z + zh;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���S�𓾂�
		@param[out]	Pos	���S����������x�N�g��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void GetCenter(Vector3& Pos)const {
			Pos.x = (m_Min.x + m_Max.x) / 2.0f;
			Pos.y = (m_Min.y + m_Max.y) / 2.0f;
			Pos.z = (m_Min.z + m_Max.z) / 2.0f;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���S�𓾂�
		@return	���S�̃x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		Vector3 GetCenter() const{
			Vector3 ret;
			ret.x = (m_Min.x + m_Max.x) / 2.0f;
			ret.y = (m_Min.y + m_Max.y) / 2.0f;
			ret.z = (m_Min.z + m_Max.z) / 2.0f;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ړ�����
		@param[in]	MoveVec	�ړ��x�N�g��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void Move(const Vector3& MoveVec) {
			m_Min += MoveVec;
			m_Max += MoveVec;
		}
		bool PtInAABB(const Vector3& point) {
			if (
				point.x >= m_Min.x && point.x < m_Max.x
				&&
				point.y >= m_Min.y && point.y < m_Max.y
				&&
				point.z >= m_Min.z && point.z < m_Max.z
				) {
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			return RECT_XZ(m_Min.x, m_Min.z, m_Max.x, m_Max.z);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���SPHERE�𓾂�
		@return	SPHERE
		*/
		//--------------------------------------------------------------------------------------
		SPHERE GetWrappedSPHERE() const;

	};



	//--------------------------------------------------------------------------------------
	///	���{�����[�����E
	//--------------------------------------------------------------------------------------
	struct SPHERE {
		Vector3 m_Center;	///< ���S�_�̍��W
		float m_Radius;			///< ���a
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		SPHERE() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Center	���S
		@param[in]	Radius	���a
		*/
		//--------------------------------------------------------------------------------------
		SPHERE(const Vector3& Center, float Radius) :
			m_Center(Center),
			m_Radius(Radius) {}
		AABB GetWrappedAABB() const {
			AABB ret;
			ret.m_Min = Vector3(m_Center.x - m_Radius, m_Center.y - m_Radius, m_Center.z - m_Radius);
			ret.m_Max = Vector3(m_Center.x + m_Radius, m_Center.y + m_Radius, m_Center.z + m_Radius);
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			RECT_XZ ret;
			ret.m_Left = m_Center.x - m_Radius;
			ret.m_Near = m_Center.z - m_Radius;
			ret.m_Right = m_Center.x + m_Radius;
			ret.m_Far = m_Center.z + m_Radius;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���SPHERE�𓾂�
		@return	SPHERE
		*/
		//--------------------------------------------------------------------------------------
		SPHERE GetWrappedSPHERE() const {
			return *this;
		}

	};

	inline SPHERE AABB::GetWrappedSPHERE() const {
		SPHERE sp;
		auto Size = m_Max - m_Min;
		Size *= 0.5f;
		sp.m_Radius = Size.Length();
		sp.m_Center = GetCenter();
		return sp;
	}



	//--------------------------------------------------------------------------------------
	///	OBB�{�����[�����E
	//--------------------------------------------------------------------------------------
	struct OBB{
		Vector3 m_Center;     ///< ���S�_�̍��W
		Vector3 m_Rot[3];  ///< XYZ �̊e���W���̌X����\�������x�N�g��
		Vector3 m_Size;     ///< OBB �̊e���W���ɉ����������̔����i���S�_����ʂ܂ł̒����j
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�쐬���ꂽ�T�C�Y�ƕϊ��s�񂩂�AOBB����蒼��
		@param[in]	Size	�쐬�T�C�Y
		@param[in]	Matrix	�ϊ��s��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void CreateOBB(const Vector3& Size,const Matrix4X4& Matrix){
			m_Center.x = Matrix._41;
			m_Center.y = Matrix._42;
			m_Center.z = Matrix._43;
			Vector3 VecX(Matrix._11,Matrix._12,Matrix._13);
			Vector3 VecY(Matrix._21,Matrix._22,Matrix._23);
			Vector3 VecZ(Matrix._31,Matrix._32,Matrix._33);
			m_Size = Vector3(
				Size.x * VecX.Length(),
				Size.y * VecY.Length(),
				Size.z * VecZ.Length()
				);
			m_Size *= 0.5f;
			//��]�𓾂�
			m_Rot[0] = Vector3EX::Normalize(VecX);
			m_Rot[1] = Vector3EX::Normalize(VecY);
			m_Rot[2] = Vector3EX::Normalize(VecZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		OBB(){
			//�f�t�H���g��1��1.0��OBB
			Vector3 SizeVec(1.0f,1.0f,1.0f);
			//�s��̓A�C�f���e�B�e�B
			Matrix4X4 Matrix;
			CreateOBB(SizeVec,Matrix);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Size	�T�C�Y
		@param[in]	Rot	��]�x�N�g��
		@param[in]	Center	���S�ʒu
		*/
		//--------------------------------------------------------------------------------------
		OBB(const Vector3& Size,const Vector3& Rot,const Vector3& Center):
			m_Center(Center),
			m_Size(Size)
		{
			m_Size *= 0.5f;
			//��]�𓾂�
			Vector3 LocaRot = Rot;
			LocaRot.Normalize();
			Matrix4X4 mRot;
			mRot.Identity();
			mRot.RotationRollPitchYawFromVector(LocaRot);
			m_Rot[0] = Vector3(mRot._11,mRot._12,mRot._13);
			m_Rot[1] = Vector3(mRot._21,mRot._22,mRot._23);
			m_Rot[2] = Vector3(mRot._31,mRot._32,mRot._33);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Size	�T�C�Y
		@param[in]	Qt	��]�N�I�[�^�j�I��
		@param[in]	Center	���S�ʒu
		*/
		//--------------------------------------------------------------------------------------
		OBB(const Vector3& Size,const Quaternion& Qt,const Vector3& Center):
			m_Center(Center),
			m_Size(Size)
		{
			m_Size *= 0.5f;
			//��]�𓾂�
			Quaternion LocalQt = Qt;
			//�N�I�[�^�j�I���𐳋K��
			LocalQt.Normalize();
			//�N�I�[�^�j�I�������]�s����쐬
			Matrix4X4 mRot;
			mRot.Identity();
			mRot.RotationQuaternion(LocalQt);
			m_Rot[0] = Vector3(mRot._11,mRot._12,mRot._13);
			m_Rot[1] = Vector3(mRot._21,mRot._22,mRot._23);
			m_Rot[2] = Vector3(mRot._31,mRot._32,mRot._33);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^�i�쐬���ꂽ�T�C�Y�ƕϊ��s�񂩂�AOBB���쐬�j
		@param[in]	Size	�T�C�Y
		@param[in]	Matrix	�ϊ��s��
		*/
		//--------------------------------------------------------------------------------------
		OBB(const Vector3& Size,const Matrix4X4& Matrix)
		{
			m_Center.x = Matrix._41;
			m_Center.y = Matrix._42;
			m_Center.z = Matrix._43;
			Vector3 VecX(Matrix._11,Matrix._12,Matrix._13);
			Vector3 VecY(Matrix._21,Matrix._22,Matrix._23);
			Vector3 VecZ(Matrix._31,Matrix._32,Matrix._33);
			m_Size = Vector3(
				Size.x * VecX.Length(),
				Size.y * VecY.Length(),
				Size.z * VecZ.Length()
				);
			m_Size *= 0.5f;
			//��]�𓾂�
			m_Rot[0] = Vector3EX::Normalize(VecX);
			m_Rot[1] = Vector3EX::Normalize(VecY);
			m_Rot[2] = Vector3EX::Normalize(VecZ);

		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��]�s��𓾂�
		@return	��]�s��
		*/
		//--------------------------------------------------------------------------------------
		Matrix4X4 GetRotMatrix()const{
			Matrix4X4 ret;
			ret._11 = m_Rot[0].x;
			ret._12 = m_Rot[0].y;
			ret._13 = m_Rot[0].z;
			ret._21 = m_Rot[1].x;
			ret._22 = m_Rot[1].y;
			ret._23 = m_Rot[1].z;
			ret._31 = m_Rot[2].x;
			ret._32 = m_Rot[2].y;
			ret._33 = m_Rot[2].z;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s��𓾂�
		@return	���[���h�s��
		*/
		//--------------------------------------------------------------------------------------
		Matrix4X4 GetWorldMatrix()const {
			Matrix4X4 ret,Pos;
			ret.Identity();
			ret.Scaling(m_Size.x * 2.0f, m_Size.y * 2.0f, m_Size.z * 2.0f);
			ret *= GetRotMatrix();
			Pos.Translation(m_Center.x, m_Center.y, m_Center.z);
			ret *= Pos;
			return ret;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ԑ傫���ӂ̔��������𓾂�
		@return	��ԑ傫���ӂ̔����̒���
		*/
		//--------------------------------------------------------------------------------------
		float GetMaxHalfSize()const {
			float ret = m_Size.x;
			if (ret < m_Size.y) {
				ret = m_Size.y;
			}
			if (ret < m_Size.z) {
				ret = m_Size.z;
			}
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ԑ傫���ӂ̒����𓾂�
		@return	��ԑ傫���ӂ̒���
		*/
		//--------------------------------------------------------------------------------------
		float GetMaxSize()const {
			return GetMaxHalfSize() * 2.0f;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ԏ������ӂ̒��������𓾂�
		@return	��ԏ������ӂ̒����̔���
		*/
		//--------------------------------------------------------------------------------------
		float GetMinHalfSize() const {
			float ret = m_Size.x;
			if (ret > m_Size.y) {
				ret = m_Size.y;
			}
			if (ret > m_Size.z) {
				ret = m_Size.z;
			}
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ԏ������ӂ̒����𓾂�
		@return	��ԏ������ӂ̒���
		*/
		//--------------------------------------------------------------------------------------
		float GetMinSize() const {
			return  GetMinHalfSize() * 2.0f;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���Ɉ�ԋ߂���]�𓾂�
		@param[in]	Check	�`�F�b�N����x�N�g��
		@param[in]	Epsilon	�덷
		@param[out]	Ret	�߂����x�N�g��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void GetNearNormalRot(const Vector3& Check, float Epsilon,Vector3& Ret){
			for (int i = 0; i < 3; i++){
				if (Vector3EX::NearEqual(Check, m_Rot[i], Epsilon)){
					Ret = m_Rot[i];
					return;
				}
				if (Vector3EX::NearEqual(Check, -m_Rot[i], Epsilon)){
					Ret = -m_Rot[i];
					return;
				}
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB����]���ĂȂ����ǂ����𒲂ׂ�iAABB�Ƃ��Ďg���邩�ǂ����𒲂ׂ���j
		@return	��]���ĂȂ����true
		*/
		//--------------------------------------------------------------------------------------
		bool IsRotIdentity() const{
			if (m_Rot[0] == Vector3(1.0f, 0.0f, 0.0f) && m_Rot[1] == Vector3(0.0f, 1.0f, 0.0f) && m_Rot[2] == Vector3(0.0f, 0.0f, 1.0f)){
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			RECT_XZ ret;
			SPHERE sp;
			sp.m_Radius = m_Size.Length();
			sp.m_Center = m_Center;
			return sp.GetWrappedRECT_XZ();
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���SPHERE�𓾂�
		@return	SPHERE
		*/
		//--------------------------------------------------------------------------------------
		SPHERE GetWrappedSPHERE() const {
			SPHERE sp;
			sp.m_Radius = m_Size.Length();
			sp.m_Center = m_Center;
			return sp;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���AABB�𓾂�
		@return	AABB
		*/
		//--------------------------------------------------------------------------------------
		AABB GetWrappedAABB() const {
			float Half = 0.5f;
			Vector3 Vec[] = {
				Vector3(-Half,-Half,-Half),
				Vector3(Half,-Half,-Half),
				Vector3(Half,-Half,Half),
				Vector3(-Half,-Half,Half),

				Vector3(-Half,Half,-Half),
				Vector3(Half,Half,-Half),
				Vector3(Half,Half,Half),
				Vector3(-Half,Half,Half),
			};
			bool First = true;
			AABB ret;
			auto m = GetWorldMatrix();
			for (auto& v : Vec) {
				v.Transform(m);
				if (First) {
					ret.m_Min = v;
					ret.m_Max = v;
					First = false;
				}
				else {
					if (ret.m_Min.x > v.x) {
						ret.m_Min.x = v.x;
					}
					if (ret.m_Max.x < v.x) {
						ret.m_Max.x = v.x;
					}

					if (ret.m_Min.y > v.y) {
						ret.m_Min.y = v.y;
					}
					if (ret.m_Max.y < v.y) {
						ret.m_Max.y = v.y;
					}

					if (ret.m_Min.z > v.z) {
						ret.m_Min.z = v.z;
					}
					if (ret.m_Max.z < v.z) {
						ret.m_Max.z = v.z;
					}
				}
			}
			return ret;
		}

	};



	//--------------------------------------------------------------------------------------
	///	���z��f�[�^
	//--------------------------------------------------------------------------------------
	struct SPHERE_ARR{
		vector<SPHERE> m_SphereArr;
	};

	//--------------------------------------------------------------------------------------
	///	����
	//--------------------------------------------------------------------------------------
	struct PLANE{
		Vector3 m_Normal;	///< �@��
		float m_DotValue;	///< ���ϒl
		//--------------------------------------------------------------------------------------
		/*!
		@brief	3�̓_���畽�ʂ��쐬
		@param[in]	PointA	�_A
		@param[in]	PointB	�_B
		@param[in]	PointC	�_C
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void Set(const Vector3& PointA,const Vector3& PointB,const Vector3& PointC){
			m_Normal = Vector3EX::Normalize(Vector3EX::Cross(PointB - PointA,PointC - PointA));
			m_DotValue = Vector3EX::Dot(m_Normal,PointA);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		PLANE(){}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^�i3�̓_���畽�ʂ��쐬�j
		@param[in]	PointA	�_A
		@param[in]	PointB	�_B
		@param[in]	PointC	�_C
		*/
		//--------------------------------------------------------------------------------------
		PLANE(const Vector3& PointA,const Vector3& PointB,const Vector3& PointC){
			Set(PointA,PointB,PointC);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^�iPlane�^���畽�ʂ��쐬�j
		@param[in]	plane	Plane�^�̒l
		*/
		//--------------------------------------------------------------------------------------
		PLANE(const Plane& plane){
			m_Normal.x = plane.x;
			m_Normal.y = plane.x;
			m_Normal.z = plane.z;
			m_DotValue = -plane.w;
		}
	};


	//--------------------------------------------------------------------------------------
	///	�J�v�Z���{�����[�����E
	//--------------------------------------------------------------------------------------
	struct CAPSULE {
		float m_Radius;			///< ���a
		Vector3 m_PointBottom;		///< ���ԕ������̊J�n�_
		Vector3 m_PointTop;		///< ���ԕ������̏I���_
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		CAPSULE():
			m_Radius(0.5f),
			m_PointBottom(0,-0.5f,0),
			m_PointTop(0,0.5f,0)
		{
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	Radius	���a
		@param[in]	PointBottom	���ԕ������̊J�n�_
		@param[in]	PointTop	���ԕ������̏I���_
		*/
		//--------------------------------------------------------------------------------------
		CAPSULE(float Radius,const Vector3& PointBottom,const Vector3& PointTop):
			m_Radius(Radius),
			m_PointBottom(PointBottom),
			m_PointTop(PointTop)
		{}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	MakedRadius	�쐬���̔��a
		@param[in]	MakedPointBottom	�쐬���̒��ԕ������̊J�n�_
		@param[in]	MakedPointTop	�쐬���̒��ԕ������̏I���_
		@param[in]	Matrix	�ϊ��s��
		*/
		//--------------------------------------------------------------------------------------
		CAPSULE(float MakedRadius,const Vector3& MakedPointBottom,const Vector3& MakedPointTop,
			const Matrix4X4& Matrix):
			m_Radius(MakedRadius),
			m_PointBottom(MakedPointBottom),
			m_PointTop(MakedPointTop)
		{
			m_PointBottom.Transform(Matrix);
			m_PointTop.Transform(Matrix);
			//�X�P�[�����O�̂�1�����Ōv�Z
			Vector3 Scale = Matrix.ScaleInMatrix();
			m_Radius *= Scale.x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���S�_�𓾂�
		@return	���S�_
		*/
		//--------------------------------------------------------------------------------------
		Vector3 GetCenter() const{
			return m_PointBottom + ((m_PointTop - m_PointBottom) * 0.5f);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���S�_��ݒ肷��
		@param[in]	Center	���S�_
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetCenter(const Vector3& Center){
			Vector3 CenterToPointA = ((m_PointBottom - m_PointTop) * 0.5f);
			Vector3 CenterToPointB = ((m_PointTop - m_PointBottom) * 0.5f);
			m_PointBottom = Center + CenterToPointA;
			m_PointTop = Center + CenterToPointB;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�c�̔��a�𓾂�
		@return	�c�̔��a
		*/
		//--------------------------------------------------------------------------------------
		float GetHeightRadius()const{
			float PointLen = Vector3EX::Length(m_PointTop - m_PointBottom) * 0.5f;
			PointLen += m_Radius;
			return PointLen;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			RECT_XZ ret;
			POINT_XZ P1(m_PointBottom);
			POINT_XZ P2(m_PointTop);
			if (Vector2(P1).Length() <= Vector2(P2).Length()) {
				ret.m_Left = P1.m_X - m_Radius;
				ret.m_Right = P2.m_X + m_Radius;
				ret.m_Near = P1.m_Z - m_Radius;
				ret.m_Far = P2.m_Z + m_Radius;
			}
			else {
				ret.m_Left = P2.m_X - m_Radius;
				ret.m_Right = P1.m_X + m_Radius;
				ret.m_Near = P2.m_Z - m_Radius;
				ret.m_Far = P1.m_Z + m_Radius;
			}
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���SPHERE�𓾂�
		@return	SPHERE
		*/
		//--------------------------------------------------------------------------------------
		SPHERE GetWrappedSPHERE() const {
			SPHERE sp;
			auto Size = (m_PointTop - m_PointBottom).Length();
			Size *= 0.5f;
			Size += m_Radius;
			sp.m_Radius = Size;
			sp.m_Center = GetCenter();
			return sp;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���AABB�𓾂�
		@return	AABB
		*/
		//--------------------------------------------------------------------------------------
		AABB GetWrappedAABB() const;
	};

	//--------------------------------------------------------------------------------------
	///	�Փ˔���Ɏg�p����O�p�`�i���v���j
	//--------------------------------------------------------------------------------------
	struct TRIANGLE{
		Vector3 m_A;
		Vector3 m_B;
		Vector3 m_C;
		void Set(const Vector3& baseA, const Vector3& baseB, const Vector3& baseC,
			const Matrix4X4& m) {
			m_A = Vector3EX::Transform(baseA, m);
			m_B = Vector3EX::Transform(baseB, m);
			m_C = Vector3EX::Transform(baseC, m);
		}
		TRIANGLE(){}
		TRIANGLE(const Vector3& baseA, const Vector3& baseB, const Vector3& baseC,
			const Matrix4X4& m) {
			Set(baseA,baseB,baseC,m);
		}
		Vector3 GetNormal()const {
			Vector3 Ret =
				Vector3EX::Cross(
					m_B - m_A,
					m_C - m_A
				);
			return Ret;
		}
		PLANE GetPLANE() const {
			//3�_���g���Ėʂ��쐬
			PLANE ret(m_A, m_B, m_C);
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			RECT_XZ ret;
			POINT_XZ P1(m_A);
			POINT_XZ P2(m_B);
			POINT_XZ P3(m_C);

			ret.m_Left = P1.m_X;
			if (ret.m_Left < P2.m_X) {
				ret.m_Left = P2.m_X;
			}
			if (ret.m_Left < P3.m_X) {
				ret.m_Left = P3.m_X;
			}

			ret.m_Right = P1.m_X;
			if (ret.m_Right > P2.m_X) {
				ret.m_Right = P2.m_X;
			}
			if (ret.m_Right > P3.m_X) {
				ret.m_Right = P3.m_X;
			}

			ret.m_Near = P1.m_Z;
			if (ret.m_Near < P2.m_Z) {
				ret.m_Near = P2.m_Z;
			}
			if (ret.m_Near < P3.m_Z) {
				ret.m_Near = P3.m_Z;
			}

			ret.m_Far = P1.m_Z;
			if (ret.m_Far > P2.m_Z) {
				ret.m_Far = P2.m_Z;
			}
			if (ret.m_Far > P3.m_Z) {
				ret.m_Far = P3.m_Z;
			}
			return ret;
		}
	};


	//--------------------------------------------------------------------------------------
	///	�Փ˔���Ɏg�p����RECT
	//--------------------------------------------------------------------------------------
	struct COLRECT {
		Vector3 m_Center;     //���S�_�̍��W
		Vector3 m_Rot[2];  //XY �̊e���W���̌X����\�������x�N�g��
		float m_UVec[2];     //XY���W���ɉ����������̔����i���S�_����ʂ܂ł̒����j
		float m_BaseXSize;	//���쎞�̃T�C�YX�i�e��v�Z�Ɏg���j
		float m_BaseYSize;	//���쎞�̃T�C�YY�i�e��v�Z�Ɏg���j
		Matrix4X4 m_Matrix;	//�s��i�e��v�Z�Ɏg���j
		Vector3 m_Vertex[4];	//�s��ɂ���ĕϊ����ꂽ���_(�e��v�Z�Ɏg��)
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^<br />
		���̊�{�傫���A�c�̊�{�傫�����ƕϊ��s���^����RECT������������<br />
		COLRECT�̓f�t�H���g�R���X�g���N�^�͂Ȃ��B
		@param[in]	BaseXSize	�������̑傫��
		@param[in]	BaseYSize	�c�����̑傫��
		@param[in]	Matrix	�ϊ��s��
		*/
		//--------------------------------------------------------------------------------------
		COLRECT(float BaseXSize, float BaseYSize, const Matrix4X4& Matrix):
			m_BaseXSize(BaseXSize),
			m_BaseYSize(BaseYSize),
			m_Matrix(Matrix)
			{
			m_Center.x = Matrix._41;
			m_Center.y = Matrix._42;
			m_Center.z = Matrix._43;
			Vector3 VecX(Matrix._11, Matrix._12, Matrix._13);
			Vector3 VecY(Matrix._21, Matrix._22, Matrix._23);
			m_UVec[0] = BaseXSize * VecX.Length() * 0.5f;
			m_UVec[1] = BaseYSize * VecY.Length() * 0.5f;
			//��]�𓾂�
			m_Rot[0] = Vector3EX::Normalize(VecX);
			m_Rot[1] = Vector3EX::Normalize(VecY);

			//���_�̐ݒ�
			float HalfX = m_BaseXSize * 0.5f;
			float HalfY = m_BaseYSize * 0.5f;
			m_Vertex[0] = Vector3(-HalfX, HalfY, 0);
			m_Vertex[1] = Vector3(HalfX, HalfY, 0);
			m_Vertex[2] = Vector3(-HalfX, -HalfY, 0);
			m_Vertex[3] = Vector3(HalfX, -HalfY, 0);
			for (auto& v : m_Vertex) {
				v.Transform(m_Matrix);
			}
		}
		PLANE GetPLANE() const {
			//�\�ʏ��3�̓_���g����PLANE���쐬
			//1�ڂ̓_�͒��S
			Vector3 Point0 = m_Center;
			float MakedHalfX = m_BaseXSize * 0.5f;
			float MakedHalfY = m_BaseYSize * 0.5f;
			//2�ڂ�-0.5,-0.5,0�̓_�����[���h�ϊ���������
			Vector3 Point1(-MakedHalfX, -MakedHalfY,0);
			Point1.Transform(m_Matrix);
			//3�ڂ�-0.5,0.5,0�̓_�����[���h�ϊ���������
			Vector3 Point2(MakedHalfX, -MakedHalfY, 0);
			Point2.Transform(m_Matrix);
			//3�_���g���Ėʂ��쐬
			PLANE ret(Point0, Point1, Point2);
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���XZ��`�𓾂�
		@return	XZ��`
		*/
		//--------------------------------------------------------------------------------------
		RECT_XZ GetWrappedRECT_XZ() const {
			RECT_XZ ret;

			POINT_XZ P1(m_Vertex[0].x, m_Vertex[0].z);
			POINT_XZ P2(m_Vertex[1].x, m_Vertex[1].z);
			POINT_XZ P3(m_Vertex[2].x, m_Vertex[2].z);
			POINT_XZ P4(m_Vertex[3].x, m_Vertex[3].z);

			ret.m_Left = P1.m_X;
			if (ret.m_Left < P2.m_X) {
				ret.m_Left = P2.m_X;
			}
			if (ret.m_Left < P3.m_X) {
				ret.m_Left = P3.m_X;
			}
			if (ret.m_Left < P4.m_X) {
				ret.m_Left = P4.m_X;
			}


			ret.m_Right = P1.m_X;
			if (ret.m_Right > P2.m_X) {
				ret.m_Right = P2.m_X;
			}
			if (ret.m_Right > P3.m_X) {
				ret.m_Right = P3.m_X;
			}
			if (ret.m_Right > P4.m_X) {
				ret.m_Right = P4.m_X;
			}


			ret.m_Near = P1.m_Z;
			if (ret.m_Near < P2.m_Z) {
				ret.m_Near = P2.m_Z;
			}
			if (ret.m_Near < P3.m_Z) {
				ret.m_Near = P3.m_Z;
			}
			if (ret.m_Near < P4.m_Z) {
				ret.m_Near = P4.m_Z;
			}

			ret.m_Far = P1.m_Z;
			if (ret.m_Far > P2.m_Z) {
				ret.m_Far = P2.m_Z;
			}
			if (ret.m_Far > P3.m_Z) {
				ret.m_Far = P3.m_Z;
			}
			if (ret.m_Far > P4.m_Z) {
				ret.m_Far = P4.m_Z;
			}
			return ret;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���SPHERE�𓾂�
		@return	SPHERE
		*/
		//--------------------------------------------------------------------------------------
		SPHERE GetWrappedSPHERE() const {
			SPHERE sp;
			auto Size = (m_Vertex[1] - m_Vertex[2]).Length();
			Size *= 0.5f;
			sp.m_Radius = Size;
			sp.m_Center = m_Center;
			return sp;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	��ݍ���AABB�𓾂�
		@return	AABB
		*/
		//--------------------------------------------------------------------------------------
		AABB GetWrappedAABB() const {
			AABB ret;
			ret.m_Min = m_Vertex[0];
			ret.m_Max = m_Vertex[0];
			for (int i = 1; i < 4; i++) {
				if (ret.m_Min.x > m_Vertex[i].x) {
					ret.m_Min.x = m_Vertex[i].x;
				}
				if (ret.m_Max.x < m_Vertex[i].x) {
					ret.m_Max.x = m_Vertex[i].x;
				}

				if (ret.m_Min.y > m_Vertex[i].y) {
					ret.m_Min.y = m_Vertex[i].y;
				}
				if (ret.m_Max.y < m_Vertex[i].y) {
					ret.m_Max.y = m_Vertex[i].y;
				}

				if (ret.m_Min.z > m_Vertex[i].z) {
					ret.m_Min.z = m_Vertex[i].z;
				}
				if (ret.m_Max.z < m_Vertex[i].z) {
					ret.m_Max.z = m_Vertex[i].z;
				}
			}
			return ret;
		}
	};

	//--------------------------------------------------------------------------------------
	///	�Փ˔���p�̃��[�e�B���e�B�\����
	//--------------------------------------------------------------------------------------
	struct HitTest{
		HitTest(){}
		~HitTest(){}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	float�^�̃N�����v
		@param[in]	n	�N�����v����l
		@param[in]	min	�ŏ��l
		@param[in]	max	�ő�l
		@return	�N�����v���ꂽfloat
		*/
		//--------------------------------------------------------------------------------------
		static float floatClamp(float n,float min,float max){
			if(n < min) return min;
			if(n > max) return max;
			return n;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	chk��min_v�����max_v�Ɣ�r���čŏ��܂��͍ő�̃x�N�g����ݒ肷��
		@param[in]	chk	�`�F�b�N����x�N�g��
		@param[in,out]	min_v	��r���čŏ��l��ݒ肷��x�N�g��
		@param[in,out]	max_v	��r���čő�l��ݒ肷��x�N�g��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ChkSetMinMax(const Vector3& chk, Vector3& min_v, Vector3& max_v) {
			if (min_v.x > chk.x) {
				min_v.x = chk.x;
			}
			if (max_v.x < chk.x) {
				max_v.x = chk.x;
			}
			if (min_v.y > chk.y) {
				min_v.y = chk.y;
			}
			if (max_v.y < chk.y) {
				max_v.y = chk.y;
			}
			if (min_v.z > chk.z) {
				min_v.z = chk.z;
			}
			if (max_v.z < chk.z) {
				max_v.z = chk.z;
			}
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_���ʂ̗����ɂ��邩�ǂ�������
		@param[in]	p	���؂���_
		@param[in]	pl	��
		@return	�����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		static bool InsidePtPlane(const Vector3& p, const PLANE& pl){
			float dist = Vector3EX::Dot(p,pl.m_Normal) - pl.m_DotValue;
			return dist < 0.0f;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�������m�̍ŋߐړ_���v�Z����i�J�v�Z�����m�̔���Ɏg�p�j
		@param[in]	p1	�J�v�Z��1�̐����J�n�_
		@param[in]	q1	�J�v�Z��1�̐����I���_
		@param[in]	p2	�J�v�Z��2�̐����J�n�_
		@param[in]	q2	�J�v�Z��2�̐����I���_
		@param[out]	s	����1�̍ŋߐړ_�̃p�����[�^
		@param[out]	t	����2�̍ŋߐړ_�̃p�����[�^
		@param[out]	c1	�ŋߐړ_1
		@param[out]	c2	�ŋߐړ_2
		@return	�ŋߐړ_c1,c2���v�Z���A���̃p�����[�^s,t���v�Z���������m�̋����̕�����Ԃ�
		*/
		//--------------------------------------------------------------------------------------
		static float ClosestPtSegmentSegment(
			const Vector3& p1,const Vector3& q1,const Vector3& p2,const Vector3& q2,
			float& s,float& t,Vector3& c1,Vector3& c2){
			const float EPSILON = 1.175494e-37f;
			Vector3 d1 = q1 - p1;
			Vector3 d2 = q2 - p2;
			Vector3 r = p1 - p2;
			float a = Vector3EX::Dot(d1,d1);
			float e = Vector3EX::Dot(d2,d2);
			float f = Vector3EX::Dot(d2,r);

			if(f <= EPSILON && e <= EPSILON){
				s = t = 0.0f;
				c1 = p1;
				c2 = p2;
				return Vector3EX::Dot(c1 - c2,c1 - c2);
			}
			if(a <= EPSILON){
				s = 0.0f;
				t = f / e;
				t = floatClamp(t,0.0f,1.0f);
			}
			else{
				float c = Vector3EX::Dot(d1,r);
				if(e <= EPSILON){
					t = 0.0f;
					s = floatClamp(-c / a,0.0f,1.0f);
				}
				else{
					float b = Vector3EX::Dot(d1,d2);
					float denom = a * e - b * b;
					if(denom != 0.0f){
						s = floatClamp((b * f - c * e) / denom,0.0f,1.0f);
					}
					else{
						s = 0.0f;
					}
					t = (b * s + f) / e;
					if(t < 0.0f){
						t = 0.0f;
						s = floatClamp(-c / a,0.0f,1.0f);
					}
					else if(t > 1.0f){
						t = 1.0f;
						s = floatClamp((b - c) / a,0.0f,1.0f);
					}
				}
			}
			c1 = p1 + d1 * s;
			c2 = p2 + d2 * t;
			return Vector3EX::Dot(c1 - c2,c1 - c2);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_c�Ɛ���ab�̋����̕�����Ԃ�
		@param[in]	a	�����J�n�_
		@param[in]	b	�����I���_
		@param[in]	c	�v�Z�_
		@return	�_c�Ɛ���ab�̋����̕���
		*/
		//--------------------------------------------------------------------------------------
		static float SqDistPointSegment(const Vector3& a, const Vector3& b, const Vector3& c){
			Vector3 ab = b - a;
			Vector3 ac = c - a;
			Vector3 bc = c - b;
			float e = Vector3EX::Dot(ac,ab);
			if(e <= 0.0f){
				return Vector3EX::Dot(ac,ac);
			}
			float f = Vector3EX::Dot(ab,ab);
			if(e >= f){
				return Vector3EX::Dot(bc,bc);
			}
			return Vector3EX::Dot(ac,ac) - e * e / f;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_c�Ɛ���ab�̍ŋߐړ_��Ԃ�
		@param[in]	c	���ƂɂȂ�_
		@param[in]	a	�����J�n�_
		@param[in]	b	�����I���_
		@param[out]	t	�ŋߐړ_�̐�����̈ʒu�̊����̖߂�l
		@param[out]	d	�ŋߐړ_�̖߂�l
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ClosetPtPointSegment(const Vector3& c,
			const Vector3& a,const Vector3& b,
			float& t,Vector3& d){
			Vector3 ab = b - a;
			t = Vector3EX::Dot(c - a,ab) / Vector3EX::Dot(ab,ab);
			if(t < 0.0f){
				t = 0.0f;
			}
			if(t > 1.0f){
				t = 1.0f;
			}
			d = a + (ab * t);
		}

		static SPHERE SphereEnclosingSphere(const SPHERE& s0, const SPHERE& s1) {
			const float EPSILON = 1.175494e-37f;
			SPHERE s;
			Vector3 d = s1.m_Center - s0.m_Center;
			float dist2 = d.Dot(d);
			float f = s1.m_Radius - s0.m_Radius;
			XMVector vec0(f);
			vec0.Pow(2.0f);
			if (vec0.x >= dist2) {
				if (s1.m_Radius >= s0.m_Radius) {
					s = s1;
				}
				else {
					s = s0;
				}
			}
			else {
				XMVector vec(dist2);
				vec.Sqrt();
				float dist = vec.x;
				s.m_Radius = (dist + s0.m_Radius + s1.m_Radius) * 0.5f;
				s.m_Center = s0.m_Center;
				if (dist > EPSILON) {
					s.m_Center += ((s.m_Radius - s0.m_Radius) / dist) * d;
				}

			}
			return s;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ƃJ�v�Z���Ƃ̏Փ˔���
		@param[in]	sp	��
		@param[in]	cap	�J�v�Z��
		@param[out]	d	�ŋߐړ_�̖߂�l
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_CAPSULE(const SPHERE& sp, const CAPSULE& cap, Vector3& d){
			//�܂��ŋߐړ_��ݒ�
			float t;
			Vector3 ClosetPoint;
			ClosetPtPointSegment(sp.m_Center, cap.m_PointBottom, cap.m_PointTop, t, ClosetPoint);
			//ClosetPoint�́A�J�v�Z��������̓_�ł���
			Vector3 Normal = sp.m_Center - ClosetPoint;
			Normal.Normalize();
			Normal *= cap.m_Radius;
			//�ŋߐړ_��ݒ�
			d = ClosetPoint + Normal;
			//�Փ˂��Ă��邩����
			float dist2 = SqDistPointSegment(cap.m_PointBottom,cap.m_PointTop,sp.m_Center);
			float radius = sp.m_Radius + cap.m_Radius;
			return dist2 <= radius * radius;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z���ƃJ�v�Z���Ƃ̏Փ˔���
		@param[in]	cap1	�J�v�Z��1
		@param[in]	cap2	�J�v�Z��2
		@param[out]	retvec1	�J�v�Z��1�̍ŋߐړ_��Ԃ��Q��
		@param[out]	retvec2	�J�v�Z��2�̍ŋߐړ_��Ԃ��Q��
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CAPSULE_CAPSULE(
			const CAPSULE& cap1,
			const CAPSULE& cap2,
			Vector3& retvec1,
			Vector3& retvec2){
			float s,t;
			float dist2 = ClosestPtSegmentSegment(cap1.m_PointBottom,cap1.m_PointTop,cap2.m_PointBottom,cap2.m_PointTop,
				s,t,retvec1,retvec2);
			float radius = cap1.m_Radius + cap2.m_Radius;
			return dist2 <= radius * radius;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	point���猩���O�p�`�̍ŋߐړ_�𓾂�
		@param[in]	point	��_
		@param[in]	t	�O�p�`
		@param[out]	retvec	�ŋߐړ_��Ԃ��Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ClosestPtPointTriangle(const Vector3& point,const TRIANGLE& t,Vector3& retvec) {
			Vector3 ab = t.m_B - t.m_A;
			Vector3 ac = t.m_C - t.m_A;
			Vector3 ap = point - t.m_A;
			float d1 = ab.Dot(ap);
			float d2 = ac.Dot(ap);
			if (d1 <= 0.0f && d2 <= 0.0f) {
				retvec = t.m_A;
				return;
			}

			Vector3 bp = point - t.m_B;
			float d3 = ab.Dot(bp);
			float d4 = ac.Dot(bp);
			if (d3 >= 0.0f && d4 <= d3) {
				retvec = t.m_B;
				return;
			}
			float vc = d1 * d4 - d3 * d2;
			if (vc <= 0.0f && d1 >= 0.0f && d3 <= 0.0f) {
				float v = d1 / (d1 - d3);
				retvec = v * ab + t.m_A;
				return;
			}

			Vector3 cp = point - t.m_C;
			float d5 = ab.Dot(cp);
			float d6 = ac.Dot(cp);
			if (d6 >= 0.0f && d5 <= d6) {
				retvec = t.m_C;
				return;
			}
			float vb = d5 * d2 - d1 * d6;

			if (vb <= 0.0f && d2 >= 0.0f && d6 <= 0.0f) {
				float w = d2 / (d2 - d6);
				retvec = w * ac + t.m_A;
				return;
			}

			float va = d3 * d6 - d5 * d4;
			if (va <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f) {
				float w = (d4 - d3) / ((d4 - d3) + (d5 -d6));
				retvec = w * (t.m_C - t.m_B) + t.m_B;
				return;
			}
			float denon = 1.0f / (va + vb + vc);
			float v = vb * denon;
			float w = vc * denon;
			retvec = ab * v + ac * w + t.m_A;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	point���猩��OBB�̍ŋߐړ_�𓾂�
		@param[in]	point	��_
		@param[in]	obb	OBB
		@param[out]	retvec	�ŋߐړ_��Ԃ��Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ClosestPtPointOBB(const Vector3& point, const OBB& obb, Vector3& retvec){
			Vector3 d = point - obb.m_Center;
			retvec = obb.m_Center;
			float dist;
			for(int i = 0; i < 3; i++)
			{
				dist = Vector3EX::Dot(d,obb.m_Rot[i]);
				if(dist > obb.m_Size[i])
				{
					dist = obb.m_Size[i];
				}
				if(dist < -obb.m_Size[i])
				{
					dist = -obb.m_Size[i];
				}
				retvec +=  dist * obb.m_Rot[i];
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���Ƌ��Ƃ̏Փ˔���
		@param[in]	sp1	��1
		@param[in]	sp2	��2
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_SPHERE(const SPHERE& sp1, const SPHERE& sp2){
			Vector3 d = sp1.m_Center - sp2.m_Center;
			float dist2 = Vector3EX::Dot(d,d);
			float radiussum = sp1.m_Radius + sp2.m_Radius;
			return dist2 <= radiussum * radiussum;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���Ƌ��z��Ƃ̏Փ˔���
		@param[in]	sp1	��1
		@param[in]	sparr	���z��
		@param[out]	HitIndex	�Փ˂��Ă����ꍇ�̔z��̃C���f�b�N�X
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_SPHERE_ARR(const SPHERE& sp1, const SPHERE_ARR& sparr, size_t& HitIndex){
			size_t sz = sparr.m_SphereArr.size();
			for(size_t i = 0;i < sz;i++){
				if(SPHERE_SPHERE(sp1,sparr.m_SphereArr[i])){
					HitIndex = i;
					return true;
				}
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���z��Ƌ��z��Ƃ̏Փ˔���
		@param[in]	srcarr	���z��src
		@param[in]	destarr	���z��dest
		@param[out]	SrcHitIndex	�Փ˂��Ă����ꍇ��Src�z��̃C���f�b�N�X
		@param[out]	DestHitIndex	�Փ˂��Ă����ꍇ��Dest�z��̃C���f�b�N�X
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_ARR_SPHERE_ARR(const SPHERE_ARR& srcarr, const SPHERE_ARR& destarr,
			size_t& SrcHitIndex,size_t& DestHitIndex){
			size_t SrcSz = srcarr.m_SphereArr.size();
			size_t DestSz = destarr.m_SphereArr.size();
			for(size_t i = 0;i < SrcSz;i++){
				for(size_t j = 0;j < DestSz;j++){
					if(SPHERE_SPHERE(srcarr.m_SphereArr[i],destarr.m_SphereArr[j])){
						SrcHitIndex = i;
						DestHitIndex = j;
						return true;
					}
				}
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_��AABB�Ƃ̍ŋߐړ_�𓾂�
		@param[in]	p	�_
		@param[in]	b	AABB
		@param[out]	retvec	�ŋߐړ_����������Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ClosestPtPointAABB(const Vector3& p, const AABB& b,
			Vector3& retvec){
			for(int i = 0;i < 3;i++){
				float v = p[i];
				if(v < b.m_Min[i]){
					v = b.m_Min[i];
				}
				if(v > b.m_Max[i]){
					v = b.m_Max[i];
				}
				retvec[i] = v;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_��AABB�Ƃ̋����̕����𑪂�
		@param[in]	p	�_
		@param[in]	b	AABB
		@return	�_��AABB�Ƃ̋����̕���
		*/
		//--------------------------------------------------------------------------------------
		static float SqDistPointAABB(const Vector3& p, const AABB& b){
			float sqDist = 0.0f;
			for(int i = 0;i < 3;i++){
				float v = p[i];
				if(v < b.m_Min[i]){
					sqDist += (b.m_Min[i] - v) * (b.m_Min[i] - v);
				}
				if(v > b.m_Max[i]){
					sqDist += (v - b.m_Max[i]) * (v - b.m_Max[i]);
				}
			}
			return sqDist;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	����AABB�Ƃ̏Փ˔���
		@param[in]	sp	��
		@param[in]	b	AABB
		@param[out]	retvec	�ŋߐړ_����������Q��
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_AABB(const SPHERE& sp, const AABB& b,
			Vector3& retvec){
				//�ŋߐړ_�𓾂�
				ClosestPtPointAABB(sp.m_Center,b,retvec);
				//�����̕��������̔��a�̕������Ȃ�true
				if(SqDistPointAABB(sp.m_Center,b) <= (sp.m_Radius * sp.m_Radius)){
					return true;
				}
				return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	AABB��AABB�Ƃ̏Փ˔���
		@param[in]	a	AABB1
		@param[in]	b	AABB2
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool AABB_AABB(const AABB& a, const AABB& b){
			if(a.m_Max.x < b.m_Min.x || a.m_Min.x > b.m_Max.x)
				return false;
			if(a.m_Max.y < b.m_Min.y || a.m_Min.y > b.m_Max.y)
				return false;
			if(a.m_Max.z < b.m_Min.z || a.m_Min.z > b.m_Max.z)
				return false;
			return true;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	AABB��AABB�Ƃ̏Փ˔���(min��������max�������l��������Փ˂��ĂȂ�)
		@param[in]	a	AABB1
		@param[in]	b	AABB2
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool AABB_AABB_NOT_EQUAL(const AABB& a, const AABB& b) {
			if (a.m_Max.x <= b.m_Min.x || a.m_Min.x >= b.m_Max.x)
				return false;
			if (a.m_Max.y <= b.m_Min.y || a.m_Min.y >= b.m_Max.y)
				return false;
			if (a.m_Max.z <= b.m_Min.z || a.m_Min.z >= b.m_Max.z)
				return false;
			return true;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	AABB a��AABB ���Ɋ��S�Ɋ܂܂�邩����
		@param[in]	a	AABB1
		@param[in]	b	AABB2
		@return	���S�Ɋ܂܂���true
		*/
		//--------------------------------------------------------------------------------------
		static bool AABB_IN_AABB(const AABB& a, const AABB& b){
			if(a.m_Min.x < b.m_Min.x || a.m_Max.x > b.m_Max.x)
				return false;
			if(a.m_Min.y < b.m_Min.y || a.m_Max.y > b.m_Max.y)
				return false;
			if(a.m_Min.z < b.m_Min.z || a.m_Max.z > b.m_Max.z)
				return false;
			return true;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	AABB a��AABB ������AABB��Ԃ�
		@param[in]	a	AABB1
		@param[in]	b	AABB2
		@return	���S�Ɋ܂܂���true
		*/
		//--------------------------------------------------------------------------------------
		static AABB AABB_OR_AABB(const AABB& a, const AABB& b) {
			AABB ret;
			ret.m_Min.x = (a.m_Min.x <= b.m_Min.x) ? a.m_Min.x : b.m_Min.x;
			ret.m_Min.y = (a.m_Min.y <= b.m_Min.y) ? a.m_Min.y : b.m_Min.y;
			ret.m_Min.z = (a.m_Min.z <= b.m_Min.z) ? a.m_Min.z : b.m_Min.z;

			ret.m_Max.x = (a.m_Max.x >= b.m_Max.x) ? a.m_Max.x : b.m_Max.x;
			ret.m_Max.y = (a.m_Max.y >= b.m_Max.y) ? a.m_Max.y : b.m_Max.y;
			ret.m_Max.z = (a.m_Max.z >= b.m_Max.z) ? a.m_Max.z : b.m_Max.z;

			return ret;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	����OBB�Ƃ̏Փ˔���
		@param[in]	sp	��
		@param[in]	obb	OBB
		@param[out]	retvec	�ŋߐړ_����������Q��
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_OBB(const SPHERE& sp, const OBB& obb, Vector3& retvec){
			ClosestPtPointOBB(sp.m_Center,obb,retvec);
			Vector3 v = retvec - sp.m_Center;
			return Vector3EX::Dot(v,v) <= sp.m_Radius * sp.m_Radius;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB��OBB�Ƃ̏Փ˔���
		@param[in]	obb1	OBB1
		@param[in]	obb2	OBB2
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool OBB_OBB(const OBB& obb1, const OBB& obb2){
			const float EPSILON = 1.175494e-37f;
			float R[3][3], AbsR[3][3];
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					R[i][j] = Vector3EX::Dot(obb1.m_Rot[i], obb2.m_Rot[j]);
					AbsR[i][j] = fabsf(R[i][j]) + EPSILON;
				}
			}
			Vector3 t = obb2.m_Center - obb1.m_Center;
			t = Vector3(Vector3EX::Dot(t, obb1.m_Rot[0]),
							Vector3EX::Dot(t, obb1.m_Rot[1]),
							Vector3EX::Dot(t, obb1.m_Rot[2]));
			//��L=A0, L=A1, L=A2����
			float ra, rb;
			for(int i = 0; i < 3; i++){
				ra = obb1.m_Size[i];
				rb = obb2.m_Size[0] * AbsR[i][0] + obb2.m_Size[1] * AbsR[i][1] + obb2.m_Size[2] * AbsR[i][2];
				if(fabsf(t[i]) > ra + rb){
					return false;
				}
			}
			//��L=B0, L=B1, L=B2����
			for(int i = 0; i < 3; i++){
				ra = obb1.m_Size[0] * AbsR[0][i] + obb1.m_Size[1] * AbsR[1][i] + obb1.m_Size[2] * AbsR[2][i];
				rb = obb2.m_Size[i];
				if(fabsf(t[0] * R[0][i] + t[1] * R[1][i] + t[2] * R[2][i]) > ra + rb){
					return false;
				}
			}
			//��L=A0 X B0����
			ra = obb1.m_Size[1] * AbsR[2][0] + obb1.m_Size[2] * AbsR[1][0];
			rb = obb2.m_Size[1] * AbsR[0][2] + obb2.m_Size[2] * AbsR[0][1];
			if(fabsf(t[2] * R[1][0] - t[1] * R[2][0]) > ra + rb){
				return false;
			}
			//��L=A0 X B1����
			ra = obb1.m_Size[1] * AbsR[2][1] + obb1.m_Size[2] * AbsR[1][1];
			rb = obb2.m_Size[0] * AbsR[0][2] + obb2.m_Size[2] * AbsR[0][0];
			if(fabsf(t[2] * R[1][1] - t[1] * R[2][1]) > ra + rb){
				return false;
			}
			//��L=A0 X B2����
			ra = obb1.m_Size[1] * AbsR[2][2] + obb1.m_Size[2] * AbsR[1][2];
			rb = obb2.m_Size[0] * AbsR[0][1] + obb2.m_Size[1] * AbsR[0][0];
			if(fabsf(t[2] * R[1][2] - t[1] * R[2][2]) > ra + rb){
				return false;
			}
			//��L=A1 X B0����
			ra = obb1.m_Size[0] * AbsR[2][0] + obb1.m_Size[2] * AbsR[0][0];
			rb = obb2.m_Size[1] * AbsR[1][2] + obb2.m_Size[2] * AbsR[1][1];
			if(fabsf(t[0] * R[2][0] - t[2] * R[0][0]) > ra + rb){
				return false;
			}
			//��L=A1 X B1����
			ra = obb1.m_Size[0] * AbsR[2][1] + obb1.m_Size[2] * AbsR[0][1];
			rb = obb2.m_Size[0] * AbsR[1][2] + obb2.m_Size[2] * AbsR[1][0];
			if(fabsf(t[0] * R[2][1] - t[2] * R[0][1]) > ra + rb){
				return false;
			}
			//��L=A1 X B2����
			ra = obb1.m_Size[0] * AbsR[2][2] + obb1.m_Size[2] * AbsR[0][2];
			rb = obb2.m_Size[0] * AbsR[1][1] + obb2.m_Size[1] * AbsR[1][0];
			if(fabsf(t[0] * R[2][2] - t[2] * R[0][2]) > ra + rb){
				return false;
			}
			//��L=A2 X B0����
			ra = obb1.m_Size[0] * AbsR[1][0] + obb1.m_Size[1] * AbsR[0][0];
			rb = obb2.m_Size[1] * AbsR[2][2] + obb2.m_Size[2] * AbsR[2][1];
			if(fabsf(t[1] * R[0][0] - t[0] * R[1][0]) > ra + rb){
				return false;
			}
			//��L=A2 X B1����
			ra = obb1.m_Size[0] * AbsR[1][1] + obb1.m_Size[1] * AbsR[0][1];
			rb = obb2.m_Size[0] * AbsR[2][2] + obb2.m_Size[2] * AbsR[2][0];
			if(fabsf(t[1] * R[0][1] - t[0] * R[1][1]) > ra + rb){
				return false;
			}
			//��L=A2 X B2����
			ra = obb1.m_Size[0] * AbsR[1][2] + obb1.m_Size[1] * AbsR[0][2];
			rb = obb2.m_Size[0] * AbsR[2][1] + obb2.m_Size[1] * AbsR[2][0];
			if(fabsf(t[1] * R[0][2] - t[0] * R[1][2]) > ra + rb){
				return false;
			}
			return true;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	����ab�Ɩʔ���
		@param[in]	a	�����J�n�_
		@param[in]	b	�����I���_
		@param[in]	p	��
		@param[out]	t	�ŋߐړ_�̐�����̈ʒu�̊����̖߂�l
		@param[out]	q	�ŋߐړ_�̖߂�l
		@return	�������Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SEGMENT_PLANE(const Vector3& a, const Vector3& b,
			const PLANE& p,float& t,Vector3& q){
			Vector3 ab = b - a;
			t = (p.m_DotValue - Vector3EX::Dot(p.m_Normal,a)) / Vector3EX::Dot(p.m_Normal,ab);
			if(t >= 0.0f && t <= 1.0f){
				q = a + (ab * t);
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������AABB�̃��C����
		@param[in]	p0	�����J�n�_
		@param[in]	p1	�����I���_
		@param[in]	b	AABB
		@return	�������Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SEGMENT_AABB(const Vector3& p0, const Vector3& p1, const AABB& b){
			const float EPSILON = 1.175494e-37f;
			Vector3 c = (b.m_Min + b.m_Max) * 0.5f;
			Vector3 e = b.m_Max - c;
			Vector3 m = (p0 + p1) * 0.5f;
			Vector3 d = p1 - m;
			m = m - c;
			float adx = fabsf(d.x);
			if(fabsf(m.x) > e.x + adx){
				return false;
			}
			float ady = fabsf(d.y);
			if(fabsf(m.y) > e.y + ady){
				return false;
			}
			float adz = fabsf(d.z);
			if(fabsf(m.z) > e.z + adz){
				return false;
			}
			adx += EPSILON;
			ady += EPSILON;
			adz += EPSILON;
			if(fabsf(m.y * d.z - m.z * d.y) > e.y * adz + e.z * ady){
				return false;
			}
			if(fabsf(m.z * d.x - m.x * d.z) > e.x * adz + e.z * adx){
				return false;
			}
			if(fabsf(m.x * d.y - m.y * d.x) > e.x * ady + e.y * adx){
				return false;
			}
			return true;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������OBB�̃��C����
		@param[in]	p0	�����J�n�_
		@param[in]	p1	�����I���_
		@param[in]	obb	OBB
		@return	�������Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SEGMENT_OBB(const Vector3& p0, const Vector3& p1, const OBB& obb){
			const float EPSILON = 1.175494e-37f;

			Vector3 m = (p0 + p1) * 0.5f;
			Vector3 d = p1 - m;
			m = m - obb.m_Center;
			m = Vector3(Vector3EX::Dot(obb.m_Rot[0], m), Vector3EX::Dot(obb.m_Rot[1], m), Vector3EX::Dot(obb.m_Rot[2], m));
			d = Vector3(Vector3EX::Dot(obb.m_Rot[0], d), Vector3EX::Dot(obb.m_Rot[1], d), Vector3EX::Dot(obb.m_Rot[2], d));

			float adx = fabsf(d.x);
			if(fabsf(m.x) > obb.m_Size.x + adx) return false;
			float ady = fabsf(d.y);
			if(fabsf(m.y) > obb.m_Size.y + ady) return false;
			float adz = fabsf(d.z);
			if(fabsf(m.z) > obb.m_Size.z + adz) return false;
			adx += EPSILON; 
			ady += EPSILON; 
			adz += EPSILON;
        
			if(fabsf(m.y * d.z - m.z * d.y) > obb.m_Size.y * adz + obb.m_Size.z * ady ) return false;
			if(fabsf(m.z * d.x - m.x * d.z) > obb.m_Size.x * adz + obb.m_Size.z * adx ) return false;
			if(fabsf(m.x * d.y - m.y * d.x) > obb.m_Size.x * ady + obb.m_Size.y * adx ) return false;

			return true;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_��COLRECT�Ƃ̍ŋߐړ_�𓾂�
		@param[in]	p	�_
		@param[in]	rect	COLRECT
		@param[out]	retvec	�ŋߐړ_����������Q��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		static void ClosestPtPointCOLRECT(const Vector3& point, const COLRECT& rect,
			Vector3& retvec) {
			Vector3 d = point - rect.m_Center;
			retvec = rect.m_Center;
			for (int i = 0; i < 2; i++) {
				float dist = Vector3EX::Dot(d, rect.m_Rot[i]);
				if (dist > rect.m_UVec[i]) {
					dist = rect.m_UVec[i];
				}
				if (dist < -rect.m_UVec[i]) {
					dist = -rect.m_UVec[i];
				}
				retvec += rect.m_Rot[i] * dist;
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	����COLRECT�Ƃ̏Փ˔���
		@param[in]	sp	��
		@param[in]	rect	COLRECT
		@param[out]	retvec	�ŋߐړ_����������Q��
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_COLRECT(const SPHERE& sp, const COLRECT& rect, Vector3& retvec) {
			//�l�p�`�Ƃ̍ŋߐړ_�𓾂�
			ClosestPtPointCOLRECT(sp.m_Center, rect, retvec);
			//�ŋߐړ_�����a�ȉ��Ȃ�Փ˂��Ă���
			if (Vector3EX::Length(sp.m_Center - retvec) <= sp.m_Radius) {
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Rect�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestRect	Dest��`
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereRect(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const COLRECT& DestRect, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			Vector3 RetVec;
			if (!HitTest::SPHERE_COLRECT(SrcSp2, DestRect, RetVec)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereRect(SrcSp, SrcVelocity, DestRect, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestSphereRect(SrcSp, SrcVelocity, DestRect, mid, EndTime, HitTime);
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB��PLANE�Ƃ̏Փ˔���
		@param[in]	obb	OBB
		@param[in]	plane	PLANE
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool OBB_PLANE(const OBB& obb, const PLANE& plane) {
			float r = obb.m_Size.x * abs(Vector3EX::Dot(plane.m_Normal, obb.m_Rot[0]))
				+ obb.m_Size.y * abs(Vector3EX::Dot(plane.m_Normal, obb.m_Rot[1]))
				+ obb.m_Size.z * abs(Vector3EX::Dot(plane.m_Normal, obb.m_Rot[2]));
			float s = Vector3EX::Dot(plane.m_Normal, obb.m_Center) - plane.m_DotValue;
			return abs(s) <= r;
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB��COLRECT�Ƃ̏Փ˔���
		@param[in]	obb	OBB
		@param[in]	rect	COLRECT
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool OBB_COLRECT(const OBB& obb, const COLRECT& rect) {
			if (OBB_PLANE(obb, rect.GetPLANE())) {
				//���ʂƌ������Ă������̂�OBB�ƒ���
				OBB obb2(Vector3(rect.m_BaseXSize, rect.m_BaseYSize, 1.0f), rect.m_Matrix);
				return OBB_OBB(obb, obb2);
			}
			return false;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	SPHERE��TRIANGLE�Ƃ̏Փ˔���
		@param[in]	sp	SPHERE
		@param[in]	tri	TRIANGLE
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool SPHERE_TRIANGLE(const SPHERE& sp, const TRIANGLE& tri, Vector3& retvec) {
			ClosestPtPointTriangle(sp.m_Center, tri, retvec);
			Vector3 v = retvec - sp.m_Center;
			return v.Dot(v) <= sp.m_Radius * sp.m_Radius;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Triangle�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestRect	Dest��`
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereTriangle(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const TRIANGLE& DestTri, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			Vector3 RetVec;
			if (!HitTest::SPHERE_TRIANGLE(SrcSp2, DestTri, RetVec)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereTriangle(SrcSp, SrcVelocity, DestTri, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestSphereTriangle(SrcSp, SrcVelocity, DestTri, mid, EndTime, HitTime);
		}




		//--------------------------------------------------------------------------------------
		/*!
		@brief	Obb�Ɠ����Ȃ�Rect�̏Փ˔���
		@param[in]	SrcObb	Src��Obb
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestRect	Dest��`
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestObbRect(const OBB& SrcObb, const Vector3& SrcVelocity,
			const COLRECT& DestRect, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			OBB SrcObb2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcObb2.m_Center = SrcObb.m_Center + SrcVelocity * mid;
			//OBB�̊e�ӂ̒������g��
			SrcObb2.m_Size.x = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.x;
			SrcObb2.m_Size.y = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.y;
			SrcObb2.m_Size.z = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.z;
			if (!HitTest::OBB_COLRECT(SrcObb2, DestRect)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestObbRect(SrcObb, SrcVelocity, DestRect, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestObbRect(SrcObb, SrcVelocity, DestRect, mid, EndTime, HitTime);
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Sphere�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestSp	Dest��
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereSphere(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const SPHERE& DestSp, float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			if (!HitTest::SPHERE_SPHERE(SrcSp2, DestSp)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereSphere(SrcSp, SrcVelocity, DestSp, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestSphereSphere(SrcSp, SrcVelocity, DestSp, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Capsule�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestCap	Dest�J�v�Z��
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereCapsule(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const CAPSULE& DestCap,
			float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			Vector3 RetVec;
			if (!HitTest::SPHERE_CAPSULE(SrcSp2, DestCap, RetVec)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereCapsule(SrcSp, SrcVelocity, DestCap, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestSphereCapsule(SrcSp, SrcVelocity, DestCap, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Capsule�Ɠ����Ȃ�Capsule�̏Փ˔���
		@param[in]	SrcCap	Src�̃J�v�Z��
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestCap	Dest�J�v�Z��
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestCapsuleCapsule(const CAPSULE& SrcCapsule, const Vector3& SrcVelocity,
			const CAPSULE& DestCap,
			float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;

			CAPSULE SrcCapsule2 = SrcCapsule;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcCapsule2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcCapsule.m_Radius;
			float Scale = SrcCapsule2.m_Radius / SrcCapsule.m_Radius;

			//���S�����_�̌��̃J�v�Z�����쐬
			CAPSULE SrcBaseCapsule = SrcCapsule;
			SrcBaseCapsule.SetCenter(Vector3(0, 0, 0));
			//���_�J�v�Z���ŃX�P�[�����O
			//�X�P�[�����O�s��̍쐬
			Matrix4X4 ScalMat;
			ScalMat.Scaling(Scale, Scale, Scale);
			//�e���_���X�P�[�����O
			SrcCapsule2.m_PointBottom = Vector3EX::Transform(SrcBaseCapsule.m_PointBottom, ScalMat);
			SrcCapsule2.m_PointTop = Vector3EX::Transform(SrcBaseCapsule.m_PointTop, ScalMat);
			//���S���ړ�
			SrcCapsule2.SetCenter(SrcCapsule.GetCenter() + SrcVelocity * mid);

			Vector3 RetVec1, RetVec2;
			if (!HitTest::CAPSULE_CAPSULE(SrcCapsule2, DestCap, RetVec1, RetVec2)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestCapsuleCapsule(SrcCapsule, SrcVelocity, DestCap, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestCapsuleCapsule(SrcCapsule, SrcVelocity, DestCap, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Aabb�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestAabb	Dest��AABB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereAabb(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const AABB& DestAabb,
			float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			Vector3 RetVec;
			if (!HitTest::SPHERE_AABB(SrcSp2, DestAabb, RetVec)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereAabb(SrcSp, SrcVelocity, DestAabb, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestSphereAabb(SrcSp, SrcVelocity, DestAabb, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Sphere�Ɠ����Ȃ�Obb�̏Փ˔���
		@param[in]	SrcSp	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestObb	Dest��OBB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestSphereObb(const SPHERE& SrcSp, const Vector3& SrcVelocity,
			const OBB& DestObb,
			float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			SPHERE SrcSp2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcSp2.m_Center = SrcSp.m_Center + SrcVelocity * mid;
			SrcSp2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcSp.m_Radius;
			Vector3 RetVec;
			if (!HitTest::SPHERE_OBB(SrcSp2, DestObb, RetVec)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestSphereObb(SrcSp, SrcVelocity, DestObb, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestSphereObb(SrcSp, SrcVelocity, DestObb, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z����Obb�̍ŋߐړ_�𓾂�
		@param[in]	cp	�J�v�Z��
		@param[in]	obb	OBB
		@param[out]	flg	2���̂Ƃ̈ʒu�֌W
		@return	�ŋߐړ_
		*/
		//--------------------------------------------------------------------------------------
		static Vector3 ClosestPtCapsuleOBB(const CAPSULE& cp, const OBB& obb, int& flg){
			SPHERE Sp;
			Sp.m_Center = cp.m_PointBottom;
			Sp.m_Radius = cp.m_Radius;
			Vector3 retvec;
			//�X�^�[�g�ʒu�ōŋߐړ_�𓾂�
			HitTest::SPHERE_OBB(Sp, obb, retvec);
			//���ς�}��
			Vector3 Base = cp.m_PointTop - cp.m_PointBottom;
			Base.Normalize();
			Vector3 Dest = retvec - cp.m_PointBottom;
			float dot = Base.Dot(Dest);
			if (dot < 0){
				//�X�^�[�g�ʒu�̋��̂̊O��
				//retvec�͗L��
				flg = -1;
				return retvec;
			}
			float  size = Vector3EX::Length(cp.m_PointTop - cp.m_PointBottom);
			if (dot > size){
				//�I�_����ɂ���
				Sp.m_Center = cp.m_PointTop;
				HitTest::SPHERE_OBB(Sp, obb, retvec);
				//�I�_�ōŋߐړ_���Ƃ�
				flg = 1;
				return retvec;
			}
			//���S��obb�̍ŋߐړ_�𓾂�
			HitTest::ClosestPtPointOBB(cp.GetCenter(), obb, retvec);
			float t;
			Vector3 SegPoint;
			HitTest::ClosetPtPointSegment(retvec, cp.m_PointBottom, cp.m_PointTop, t, SegPoint);
			Vector3 Span = retvec - SegPoint;
			Span.Normalize();
			Span *= cp.m_Radius;
			SegPoint += Span;
			retvec = SegPoint;
			flg = 0;
			return retvec;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z����Aabb�̍ŋߐړ_�𓾂�
		@param[in]	cp	�J�v�Z��
		@param[in]	aabb	AABB
		@param[out]	flg	�ʒu�֌W
		@return	�ŋߐړ_
		*/
		//--------------------------------------------------------------------------------------
		static Vector3 ClosestPtCapsuleAABB(const CAPSULE& cp, const AABB& aabb, int& flg) {
			SPHERE Sp;
			Sp.m_Center = cp.m_PointBottom;
			Sp.m_Radius = cp.m_Radius;
			Vector3 retvec;
			//�X�^�[�g�ʒu�ōŋߐړ_�𓾂�
			HitTest::SPHERE_AABB(Sp, aabb, retvec);
			//���ς�}��
			Vector3 Base = cp.m_PointTop - cp.m_PointBottom;
			Base.Normalize();
			Vector3 Dest = retvec - cp.m_PointBottom;
			float dot = Base.Dot(Dest);
			if (dot < 0) {
				//�X�^�[�g�ʒu�̋��̂̊O��
				//retvec�͗L��
				flg = -1;
				return retvec;
			}
			float  size = Vector3EX::Length(cp.m_PointTop - cp.m_PointBottom);
			if (dot > size) {
				//�I�_����ɂ���
				Sp.m_Center = cp.m_PointTop;
				HitTest::SPHERE_AABB(Sp, aabb, retvec);
				//�I�_�ōŋߐړ_���Ƃ�
				flg = 1;
				return retvec;
			}
			//���S��aabb�̍ŋߐړ_�𓾂�
			HitTest::ClosestPtPointAABB(cp.GetCenter(), aabb, retvec);
			float t;
			Vector3 SegPoint;
			HitTest::ClosetPtPointSegment(retvec, cp.m_PointBottom, cp.m_PointTop, t, SegPoint);
			Vector3 Span = retvec - SegPoint;
			Span.Normalize();
			Span *= cp.m_Radius;
			SegPoint += Span;
			retvec = SegPoint;
			flg = 0;
			return retvec;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z����AABB�̏Փ˔���
		@param[in]	cp	�J�v�Z��
		@param[in]	aabb	AABB
		@param[out]	retvec	�ŋߐړ_
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CAPSULE_AABB(const CAPSULE& cp, const AABB& aabb, Vector3& retvec) {
			//�X�B�[�v�����鋅
			SPHERE StartSp, EndSp;
			StartSp.m_Center = cp.m_PointBottom;
			StartSp.m_Radius = cp.m_Radius;
			EndSp.m_Center = cp.m_PointTop;
			EndSp.m_Radius = cp.m_Radius;
			//�e�_��aabb�̍ŋߐړ_�𓾂�
			//�J�v�Z����AABB�̍ŋߐړ_�𓾂�i�Փ˂��Ă邩�ǂ����͊֌W�Ȃ��j
			int flg;
			retvec = ClosestPtCapsuleAABB(cp, aabb, flg);
			float HitTime;
			Vector3 Velocity = EndSp.m_Center - StartSp.m_Center;
			if (CollisionTestSphereAabb(StartSp, Velocity, aabb, 0, 1.0f, HitTime)) {
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z���Ɠ����Ȃ�AABB�̏Փ˔���
		@param[in]	SrcCapsule	Src�̃J�v�Z��
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestAabb	Dest��AABB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestCapsuleAabb(const CAPSULE& SrcCapsule, const Vector3& SrcVelocity,
			const AABB& DestAabb, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			CAPSULE SrcCapsule2 = SrcCapsule;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcCapsule2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcCapsule.m_Radius;
			float Scale = SrcCapsule2.m_Radius / SrcCapsule.m_Radius;
			//���S�����_�̌��̃J�v�Z�����쐬
			CAPSULE SrcBaseCapsule = SrcCapsule;
			SrcBaseCapsule.SetCenter(Vector3(0, 0, 0));
			//���_�J�v�Z���ŃX�P�[�����O
			//�X�P�[�����O�s��̍쐬
			Matrix4X4 ScalMat;
			ScalMat.Scaling(Scale, Scale, Scale);
			//�e���_���X�P�[�����O
			SrcCapsule2.m_PointBottom = Vector3EX::Transform(SrcBaseCapsule.m_PointBottom, ScalMat);
			SrcCapsule2.m_PointTop = Vector3EX::Transform(SrcBaseCapsule.m_PointTop, ScalMat);
			//���S���ړ�
			SrcCapsule2.SetCenter(SrcCapsule.GetCenter() + SrcVelocity * mid);
			Vector3 RetVec;
			if (!HitTest::CAPSULE_AABB(SrcCapsule2, DestAabb, RetVec)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestCapsuleAabb(SrcCapsule, SrcVelocity, DestAabb, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestCapsuleAabb(SrcCapsule, SrcVelocity, DestAabb, mid, EndTime, HitTime);
		}



		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z����Obb�̏Փ˔���
		@param[in]	cp	�J�v�Z��
		@param[in]	obb	OBB
		@param[out]	retvec	�ŋߐړ_
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CAPSULE_OBB(const CAPSULE& cp, const OBB& obb, Vector3& retvec){
			//�X�B�[�v�����鋅
			SPHERE StartSp, EndSp;
			StartSp.m_Center = cp.m_PointBottom;
			StartSp.m_Radius = cp.m_Radius;
			EndSp.m_Center = cp.m_PointTop;
			EndSp.m_Radius = cp.m_Radius;
			//�e�_��obb�̍ŋߐړ_�𓾂�
			//�J�v�Z����OBB�̍ŋߐړ_�𓾂�i�Փ˂��Ă邩�ǂ����͊֌W�Ȃ��j
			int flg;
			retvec = ClosestPtCapsuleOBB(cp, obb,flg);
			float HitTime;
			Vector3 Velocity = EndSp.m_Center - StartSp.m_Center;
			if (CollisionTestSphereObb(StartSp, Velocity,obb, 0,1.0f, HitTime)){
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�v�Z���Ɠ����Ȃ�Obb�̏Փ˔���
		@param[in]	SrcCapsule	Src�̃J�v�Z��
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestObb	Dest��OBB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestCapsuleObb(const CAPSULE& SrcCapsule, const Vector3& SrcVelocity,
			const OBB& DestObb, float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			CAPSULE SrcCapsule2 = SrcCapsule;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcCapsule2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcCapsule.m_Radius;
			float Scale = SrcCapsule2.m_Radius / SrcCapsule.m_Radius;
			//���S�����_�̌��̃J�v�Z�����쐬
			CAPSULE SrcBaseCapsule = SrcCapsule;
			SrcBaseCapsule.SetCenter(Vector3(0, 0, 0));
			//���_�J�v�Z���ŃX�P�[�����O
			//�X�P�[�����O�s��̍쐬
			Matrix4X4 ScalMat;
			ScalMat.Scaling(Scale, Scale, Scale);
			//�e���_���X�P�[�����O
			SrcCapsule2.m_PointBottom = Vector3EX::Transform(SrcBaseCapsule.m_PointBottom, ScalMat);
			SrcCapsule2.m_PointTop = Vector3EX::Transform(SrcBaseCapsule.m_PointTop, ScalMat);
			//���S���ړ�
			SrcCapsule2.SetCenter(SrcCapsule.GetCenter() + SrcVelocity * mid);
			Vector3 RetVec;
			if (!HitTest::CAPSULE_OBB(SrcCapsule2, DestObb, RetVec)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestCapsuleObb(SrcCapsule, SrcVelocity, DestObb, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestCapsuleObb(SrcCapsule, SrcVelocity, DestObb, mid, EndTime, HitTime);
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	CAPSULE��TRIANGLE�Ƃ̏Փ˔���
		@param[in]	cp	CAPSULE
		@param[in]	rect	COLRECT
		@param[in]	retvec	�ŋߐړ_
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CAPSULE_TRIANGLE(const CAPSULE& cp, const TRIANGLE& tri, Vector3& retvec) {
			//�X�B�[�v�����鋅
			SPHERE StartSp, EndSp;
			//�������
			StartSp.m_Center = cp.m_PointBottom;
			StartSp.m_Radius = cp.m_Radius;
			EndSp.m_Center = cp.m_PointTop;
			EndSp.m_Radius = cp.m_Radius;

			PLANE p = tri.GetPLANE();
			float t;
			Vector3 q;
			SEGMENT_PLANE(StartSp.m_Center, EndSp.m_Center, p, t, q);
			//���ɉ��̓_�ŏ�����
			Vector3 Centor = StartSp.m_Center;
			if (t <= 0) {
				Centor = StartSp.m_Center;
			}
			else if (t >= 1.0f) {
				Centor = EndSp.m_Center;
			}
			else {
				Centor = q;
			}
			//Center�́A����̖ʂƂ̍ŋߐړ_
			//�_��TRIANGLE�̍ŋߐړ_�𓾂�i�Փ˂��Ă邩�ǂ����͊֌W�Ȃ��j
			ClosestPtPointTriangle(Centor, tri, retvec);
			float HitTime;
			Vector3 Velocity = EndSp.m_Center - StartSp.m_Center;
			if (CollisionTestSphereTriangle(StartSp, Velocity, tri, 0, 1.0f, HitTime)) {
				return true;
			}
			return false;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	Capsule�Ɠ����Ȃ�Triangle�̏Փ˔���
		@param[in]	SrcCapsule	Src�̃J�v�Z��
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestTri		Dest�O�p�`
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestCapsuleTriangle(const CAPSULE& SrcCapsule, const Vector3& SrcVelocity,
			const TRIANGLE& DestTri, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			CAPSULE SrcCapsule2 = SrcCapsule;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcCapsule2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcCapsule.m_Radius;
			float Scale = SrcCapsule2.m_Radius / SrcCapsule.m_Radius;
			//���S�����_�̌��̃J�v�Z�����쐬
			CAPSULE SrcBaseCapsule = SrcCapsule;
			SrcBaseCapsule.SetCenter(Vector3(0, 0, 0));
			//���_�J�v�Z���ŃX�P�[�����O
			//�X�P�[�����O�s��̍쐬
			Matrix4X4 ScalMat;
			ScalMat.Scaling(Scale, Scale, Scale);
			//�e���_���X�P�[�����O
			SrcCapsule2.m_PointBottom = Vector3EX::Transform(SrcBaseCapsule.m_PointBottom, ScalMat);
			SrcCapsule2.m_PointTop = Vector3EX::Transform(SrcBaseCapsule.m_PointTop, ScalMat);
			//���S���ړ�
			SrcCapsule2.SetCenter(SrcCapsule.GetCenter() + SrcVelocity * mid);
			Vector3 RetVec;
			if (!HitTest::CAPSULE_TRIANGLE(SrcCapsule2, DestTri, RetVec)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestCapsuleTriangle(SrcCapsule, SrcVelocity, DestTri, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestCapsuleTriangle(SrcCapsule, SrcVelocity, DestTri, mid, EndTime, HitTime);
		}




		//--------------------------------------------------------------------------------------
		/*!
		@brief	CAPSULE��COLRECT�Ƃ̏Փ˔���
		@param[in]	cp	CAPSULE
		@param[in]	rect	COLRECT
		@param[in]	retvec	�ŋߐړ_
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CAPSULE_COLRECT(const CAPSULE& cp, const COLRECT& rect, Vector3& retvec) {
			//�X�B�[�v�����鋅
			SPHERE StartSp, EndSp;
			//�������
			StartSp.m_Center = cp.m_PointBottom;
			StartSp.m_Radius = cp.m_Radius;
			EndSp.m_Center = cp.m_PointTop;
			EndSp.m_Radius = cp.m_Radius;

			PLANE p = rect.GetPLANE();
			float t;
			Vector3 q;
			SEGMENT_PLANE(StartSp.m_Center, EndSp.m_Center, p, t, q);
			//���ɉ��̓_�ŏ�����
			Vector3 Centor = StartSp.m_Center;
			if (t <= 0) {
				Centor = StartSp.m_Center;
			}
			else if (t >= 1.0f) {
				Centor = EndSp.m_Center;
			}
			else {
				Centor = q;
			}
			//Center�́A����̖ʂƂ̍ŋߐړ_
			//���Ƃ�COLRECT�̍ŋߐړ_�𓾂�i�Փ˂��Ă邩�ǂ����͊֌W�Ȃ��j
			ClosestPtPointCOLRECT(Centor, rect, retvec);
			float HitTime;
			Vector3 Velocity = EndSp.m_Center - StartSp.m_Center;
			if (CollisionTestSphereRect(StartSp, Velocity, rect, 0, 1.0f, HitTime)) {
				return true;
			}
			return false;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Capsule�Ɠ����Ȃ�Rect�̏Փ˔���
		@param[in]	SrcCapsule	Src�̋�
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestRect	Dest��`
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestCapsuleRect(const CAPSULE& SrcCapsule, const Vector3& SrcVelocity,
			const COLRECT& DestRect, float StartTime, float EndTime, float& HitTime) {
			const float m_EPSILON = 0.005f;
			CAPSULE SrcCapsule2 = SrcCapsule;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcCapsule2.m_Radius = (mid - StartTime) * SrcVelocity.Length() + SrcCapsule.m_Radius;
			float Scale = SrcCapsule2.m_Radius / SrcCapsule.m_Radius;
			//���S�����_�̌��̃J�v�Z�����쐬
			CAPSULE SrcBaseCapsule = SrcCapsule;
			SrcBaseCapsule.SetCenter(Vector3(0, 0, 0));
			//���_�J�v�Z���ŃX�P�[�����O
			//�X�P�[�����O�s��̍쐬
			Matrix4X4 ScalMat;
			ScalMat.Scaling(Scale, Scale, Scale);
			//�e���_���X�P�[�����O
			SrcCapsule2.m_PointBottom = Vector3EX::Transform(SrcBaseCapsule.m_PointBottom, ScalMat);
			SrcCapsule2.m_PointTop = Vector3EX::Transform(SrcBaseCapsule.m_PointTop, ScalMat);
			//���S���ړ�
			SrcCapsule2.SetCenter(SrcCapsule.GetCenter() + SrcVelocity * mid);
			Vector3 RetVec;
			if (!HitTest::CAPSULE_COLRECT(SrcCapsule2, DestRect, RetVec)) {
				return false;
			}
			if (EndTime - StartTime < m_EPSILON) {
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestCapsuleRect(SrcCapsule, SrcVelocity, DestRect, StartTime, mid, HitTime)) {
				return true;
			}
			return CollisionTestCapsuleRect(SrcCapsule, SrcVelocity, DestRect, mid, EndTime, HitTime);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB�Ɠ����Ȃ�OBB�̏Փ˔���i�T�u�֐��Ƃ��Ď����j
		@param[in]	SrcObb	Src��Obb
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestObb	Dest��OBB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestObbObbSub(const OBB& SrcObb, const Vector3& SrcVelocity,
			const OBB& DestObb, float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			OBB SrcObb2;
			float mid = (StartTime + EndTime) * 0.5f;
			SrcObb2.m_Center = SrcObb.m_Center + SrcVelocity * mid;
			//OBB�̊e�ӂ̒������g��
			SrcObb2.m_Size.x = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.x;
			SrcObb2.m_Size.y = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.y;
			SrcObb2.m_Size.z = (mid - StartTime) * SrcVelocity.Length() + SrcObb.m_Size.z;
			if (!HitTest::OBB_OBB(SrcObb2, DestObb)){
				return false;
			}
			if (EndTime - StartTime < m_EPSILON){
				HitTime = StartTime;
				return true;
			}
			if (CollisionTestObbObbSub(SrcObb, SrcVelocity, DestObb, StartTime, mid, HitTime)){
				return true;
			}
			return CollisionTestObbObbSub(SrcObb, SrcVelocity, DestObb, mid, EndTime, HitTime);

		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	OBB�Ɠ����Ȃ�OBB�̏Փ˔���iSrcObb��SPHERE���ł���OBB�j
		@param[in]	SrcObb	Src��Obb
		@param[in]	SrcVelocity	�\�[�X���x
		@param[in]	DestObb	Dest��OBB
		@param[in]	StartTime	�J�n����
		@param[in]	EndTime	�I������
		@param[out]	HitTime	�q�b�g����
		@return	�Փ˂��Ă����true
		*/
		//--------------------------------------------------------------------------------------
		static bool CollisionTestObbObb(const OBB& SrcObb, const Vector3& SrcVelocity,
			const OBB& DestObb, float StartTime, float EndTime, float& HitTime){
			const float m_EPSILON = 0.005f;
			SPHERE BeforeSrcSphere;
			BeforeSrcSphere.m_Center = SrcObb.m_Center;
			BeforeSrcSphere.m_Radius = SrcObb.m_Size.Length();
			if (!CollisionTestSphereObb(BeforeSrcSphere, SrcVelocity, DestObb, StartTime, EndTime, HitTime)){
				//�Փ˂��Ȃ����OBB���Փ˂Ȃ�
				return false;
			}
			return CollisionTestObbObbSub(SrcObb, SrcVelocity,DestObb, StartTime, EndTime,HitTime);
		}
	};

	inline AABB CAPSULE::GetWrappedAABB() const {
		SPHERE sp_bottom, sp_top;
		sp_bottom.m_Center = m_PointBottom;
		sp_bottom.m_Radius = m_Radius;
		sp_top.m_Center = m_PointBottom;
		sp_top.m_Radius = m_Radius;
		return HitTest::AABB_OR_AABB(sp_bottom.GetWrappedAABB(), sp_top.GetWrappedAABB());

	}


}
//end of namespace basecross.


