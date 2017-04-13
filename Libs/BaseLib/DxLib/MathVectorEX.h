/*!
@file MathVectorEX.h
@brief �x�N�g���̂�namespace�ɂ��v�Z<br />
XNAMATH �̃��b�s���O�֐��Q
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/

#pragma once

#include "stdafx.h"

namespace basecross{

	void Vector2::Transform(const Matrix4X4& m) {
		*this = XMVector2Transform(XMVECTOR(*this), XMMATRIX(m));

	}

	//--------------------------------------------------------------------------------------
	///	Vector2EX�i2�����x�N�g���j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace Vector2EX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����񂩂�쐬����
		@param[in]	x_str	X���l�ɕϊ��ł��镶����
		@param[in]	y_str	Y���l�ɕϊ��ł��镶����
		@return	�쐬�����x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 WStr2ToVec2(wstring& x_str, wstring& y_str) {
			return
				Vector2(
					(float)_wtof(x_str.c_str()),
					(float)_wtof(y_str.c_str())
					);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline bool Equal(const Vector2& Vec, const Vector2& other) {
			return XMVector2Equal(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���B<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline bool EqualInt(const Vector2& Vec, const Vector2& other) {
			return XMVector2EqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�傫�����true
		*/
		//--------------------------------------------------------------------------------------
		inline bool Greater(const Vector2& Vec, const Vector2& other) {
			return XMVector2Greater(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȏ�̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȏ�̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool GreaterOrEqual(const Vector2& Vec, const Vector2& other) {
			return XMVector2GreaterOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g�����l�̂����ꂩ���������̖����傩�ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���������̖�����Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool IsInfinite(const Vector2& Vec) {
			return XMVector2IsInfinite(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒l�̂����ꂩ���񐔁i�����l�j���ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���񐔁i�����l�j�Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool IsNaN(const Vector2& Vec) {
			return XMVector2IsNaN(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g����菬�������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline bool Less(const Vector2& Vec, const Vector2& other) {
			return XMVector2Less(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȉ��̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȉ��̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool LessOrEqual(const Vector2& Vec, const Vector2& other) {
			return XMVector2LessOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����߂��傫�����ǂ��������؂���B
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@param[in]	Epsilon	��r����ő勖�e��
		@return	�߂��傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool NearEqual(const Vector2& Vec, const Vector2& other, float Epsilon) {
			float temp = Epsilon;
			XMVECTOR VecEp = XMLoadFloat(&temp);
			return XMVector2NearEqual(XMVECTOR(Vec), XMVECTOR(other), VecEp);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline bool NotEqual(const Vector2& Vec, const Vector2& other) {
			return XMVector2NotEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline bool NotEqualInt(const Vector2& Vec, const Vector2& other) {
			return XMVector2NotEqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z����B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline float AngleBetweenNormals(const Vector2& Vec1, const Vector2& Vec2) {
			return ((Vector2)XMVector2AngleBetweenNormals(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z�\������B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline float AngleBetweenNormalsEst(const Vector2& Vec1, const Vector2& Vec2) {
			return ((Vector2)XMVector2AngleBetweenNormalsEst(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃x�N�g���Ԃ̃��W�A���p���v�Z����
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline float AngleBetweenVectors(const Vector2& Vec1, const Vector2& Vec2) {
			return ((Vector2)XMVector2AngleBetweenVectors(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMin	�����̍ŏ��l
		@param[in]	LengthMax	�����̍ő�l
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 ClampLength(const Vector2& Vec, float LengthMin, float LengthMax) {
			return (Vector2)XMVector2ClampLength(XMVECTOR(Vec), LengthMin, LengthMax);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMinV	�����̍ŏ��l(�x�N�g��)
		@param[in]	LengthMaxV	�����̍ő�l(�x�N�g��)
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 ClampLengthV(const Vector2& Vec, const Vector2& LengthMinV, const Vector2& LengthMaxV) {
			return (Vector2)XMVector2ClampLengthV(XMVECTOR(Vec), XMVECTOR(LengthMinV), XMVECTOR(LengthMaxV));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O�ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	�O��
		*/
		//--------------------------------------------------------------------------------------
		inline float Cross(const Vector2& Vec1, const Vector2& Vec2) {
			return ((Vector2)XMVector2Cross(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline float Dot(const Vector2& Vec1, const Vector2& Vec2) {
			return ((Vector2)XMVector2Dot(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ׂĂ̗v�f���A�ݒ肳�ꂽ���E�x�N�g�����ɂ���ꍇ��true��Ԃ�
		@param[in]	Vec1	��r���x�N�g��
		@param[in]	Vec2	��r����x�N�g��
		@return	���E���ɂ���ꍇ��true
		*/
		//--------------------------------------------------------------------------------------
		inline bool InBounds(const Vector2& Vec1, const Vector2& Vec2) {
			return XMVector2InBounds(XMVECTOR(Vec1), XMVECTOR(Vec2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒���
		*/
		//--------------------------------------------------------------------------------------
		inline float Length(const Vector2& Vec) {
			return ((Vector2)XMVector2Length(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����\�z���ĕԂ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̗\�z
		*/
		//--------------------------------------------------------------------------------------
		inline float LengthEst(const Vector2& Vec) {
			return ((Vector2)XMVector2LengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����2���Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒�����2��
		*/
		//--------------------------------------------------------------------------------------
		inline float LengthSq(const Vector2& Vec) {
			return ((Vector2)XMVector2LengthSq(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���𐳋K������
		@param[in]	Vec	�x�N�g��
		@return	���K�������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 Normalize(const Vector2& Vec) {
			return (Vector2)XMVector2Normalize(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K���̗\�z�x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	���K���̗\�z�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 NormalizeEst(const Vector2& Vec) {
			return (Vector2)XMVector2NormalizeEst(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����ȃx�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�����ȃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector2 Orthogonal(const Vector2& Vec) {
			return (Vector2)XMVector2Orthogonal(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t��
		*/
		//--------------------------------------------------------------------------------------
		inline float ReciprocalLength(const Vector2& Vec) {
			return ((Vector2)XMVector2ReciprocalLength(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t���̗\���l��Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t���̗\���l
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLengthEst(const Vector2& Vec) {
			return ((Vector2)XMVector2ReciprocalLengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���Ĕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	�@���x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector2 Reflect(const Vector2& Vec, const Vector2& Normal) {
			return (Vector2)XMVector2Reflect(XMVECTOR(Vec), XMVECTOR(Normal));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ�
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector2 Refract(const Vector2& Vec, const Vector2& Normal, float RefractionIndex) {
			return (Vector2)XMVector2Refract(XMVECTOR(Vec), XMVECTOR(Normal), RefractionIndex);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��x�N�g���i���ׂĂ̗v�f�������l�j�Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ��x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector2 RefractV(const Vector2& Vec, const Vector2& Normal, const Vector2& RefractionIndex) {
			return (Vector2)XMVector2RefractV(XMVECTOR(Vec), XMVECTOR(Normal),
				XMVECTOR(RefractionIndex));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector2 Transform(const Vector2& Vec, const XMMATRIX& m) {
			return (Vector2)XMVector2Transform(XMVECTOR(Vec), m);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector2 Transform(const Vector2& Vec, const Matrix4X4& m) {
			return (Vector2)XMVector2Transform(XMVECTOR(Vec), XMMATRIX(m));
		}
	};
	// end Vector2EX

	void Vector3::Transform(const Matrix4X4& m) {
		*this = XMVector3Transform(XMVECTOR(*this), XMMATRIX(m));
	}


	//--------------------------------------------------------------------------------------
	///	Vector3EX�i3�����x�N�g���j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace Vector3EX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����񂩂�쐬����
		@param[in]	x_str	X���l�ɕϊ��ł��镶����
		@param[in]	y_str	Y���l�ɕϊ��ł��镶����
		@param[in]	z_str	Z���l�ɕϊ��ł��镶����
		@return	�쐬�����x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline Vector3 WStr3ToVec3(wstring& x_str, wstring& y_str, wstring& z_str) {
			return
				Vector3(
					(float)_wtof(x_str.c_str()),
					(float)_wtof(y_str.c_str()),
					(float)_wtof(z_str.c_str())
					);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Equal(const Vector3& Vec, const Vector3& other) {
			return XMVector3Equal(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���B<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool EqualInt(const Vector3& Vec, const Vector3& other) {
			return XMVector3EqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�傫�����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Greater(const Vector3& Vec, const Vector3& other) {
			return XMVector3Greater(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȏ�̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȏ�̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool GreaterOrEqual(const Vector3& Vec, const Vector3& other) {
			return XMVector3GreaterOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g�����l�̂����ꂩ���������̖����傩�ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���������̖�����Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Vector3& Vec) {
			return XMVector3IsInfinite(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒l�̂����ꂩ���񐔁i�����l�j���ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���񐔁i�����l�j�Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Vector3& Vec) {
			return XMVector3IsNaN(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g����菬�������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Less(const Vector3& Vec, const Vector3& other) {
			return XMVector3Less(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȉ��̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȉ��̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool LessOrEqual(const Vector3& Vec, const Vector3& other) {
			return XMVector3LessOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����߂��傫�����ǂ��������؂���B
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@param[in]	Epsilon	��r����ő勖�e��
		@return	�߂��傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NearEqual(const Vector3& Vec, const Vector3& other, float Epsilon) {
			float temp = Epsilon;
			XMVECTOR VecEp = XMLoadFloat(&temp);
			return XMVector3NearEqual(XMVECTOR(Vec), XMVECTOR(other), VecEp);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqual(const Vector3& Vec, const Vector3& other) {
			return XMVector3NotEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqualInt(const Vector3& Vec, const Vector3& other) {
			return XMVector3NotEqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z����B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenNormals(const Vector3& Vec1, const Vector3& Vec2) {
			return ((Vector3)XMVector3AngleBetweenNormals(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z�\������B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenNormalsEst(const Vector3& Vec1, const Vector3& Vec2) {
			return ((Vector3)XMVector3AngleBetweenNormalsEst(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃x�N�g���Ԃ̃��W�A���p���v�Z����
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenVectors(const Vector3& Vec1, const Vector3& Vec2) {
			return ((Vector3)XMVector3AngleBetweenVectors(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMin	�����̍ŏ��l
		@param[in]	LengthMax	�����̍ő�l
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 ClampLength(const Vector3& Vec, float LengthMin, float LengthMax) {
			return (Vector3)XMVector3ClampLength(XMVECTOR(Vec), LengthMin, LengthMax);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMinV	�����̍ŏ��l(�x�N�g��)
		@param[in]	LengthMaxV	�����̍ő�l(�x�N�g��)
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 ClampLengthV(const Vector3& Vec, const Vector3& LengthMinV, const Vector3& LengthMaxV) {
			return (Vector3)XMVector3ClampLengthV(XMVECTOR(Vec), XMVECTOR(LengthMinV), XMVECTOR(LengthMaxV));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O�ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	�O��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Cross(const Vector3& Vec1, const Vector3& Vec2) {
			return (Vector3)XMVector3Cross(XMVECTOR(Vec1), XMVECTOR(Vec2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline  float Dot(const Vector3& Vec1, const Vector3& Vec2) {
			return ((Vector3)XMVector3Dot(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ׂĂ̗v�f���A�ݒ肳�ꂽ���E�x�N�g�����ɂ���ꍇ��true��Ԃ�
		@param[in]	Vec1	��r���x�N�g��
		@param[in]	Vec2	��r����x�N�g��
		@return	���E���ɂ���ꍇ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool InBounds(const Vector3& Vec1, const Vector3& Vec2) {
			return XMVector3InBounds(XMVECTOR(Vec1), XMVECTOR(Vec2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒���
		*/
		//--------------------------------------------------------------------------------------
		inline float Length(const Vector3& Vec) {
			return ((Vector3)XMVector3Length(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����\�z���ĕԂ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̗\�z
		*/
		//--------------------------------------------------------------------------------------
		inline  float LengthEst(const Vector3& Vec) {
			return ((Vector3)XMVector3LengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����2���Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒�����2��
		*/
		//--------------------------------------------------------------------------------------
		inline  float LengthSq(const Vector3& Vec) {
			return ((Vector3)XMVector3LengthSq(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���𐳋K������
		@param[in]	Vec	�x�N�g��
		@return	���K�������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Normalize(const Vector3& Vec) {
			return (Vector3)XMVector3Normalize(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K���̗\�z�x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	���K���̗\�z�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 NormalizeEst(const Vector3& Vec) {
			return (Vector3)XMVector3NormalizeEst(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����ȃx�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�����ȃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Orthogonal(const Vector3& Vec) {
			return (Vector3)XMVector3Orthogonal(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t��
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLength(const Vector3& Vec) {
			return ((Vector3)XMVector3ReciprocalLength(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t���̗\���l��Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t���̗\���l
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLengthEst(const Vector3& Vec) {
			return ((Vector3)XMVector3ReciprocalLengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���Ĕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	�@���x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Reflect(const Vector3& Vec, const Vector3& Normal) {
			return (Vector3)XMVector3Reflect(XMVECTOR(Vec), XMVECTOR(Normal));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ�
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Refract(const Vector3& Vec, const Vector3& Normal, float RefractionIndex) {
			return (Vector3)XMVector3Refract(XMVECTOR(Vec), XMVECTOR(Normal), RefractionIndex);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��x�N�g���i���ׂĂ̗v�f�������l�j�Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ��x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 RefractV(const Vector3& Vec, const Vector3& Normal, const Vector3& RefractionIndex) {
			return (Vector3)XMVector3RefractV(XMVECTOR(Vec), XMVECTOR(Normal),
				XMVECTOR(RefractionIndex));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���Ɩ@���x�N�g������X���C�h����x�N�g���𓾂�B
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	�@���x�N�g��
		@param[in]	RefractionIndex	���ܗ�
		@return	�X���C�h�������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Slide(const Vector3& Vec, const Vector3& Norm) {
			//this�Ɩ@�����璼�s���̒����i���ςŋ��߂�j
			float Len = Dot(Vec,Norm);
			//���̒����ɐL�΂�
			Vector3 Contact = Norm * Len;
			//�X���C�h��������͌��݂̃x�N�g����������Z
			return (Vec - Contact);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Transform(const Vector3& Vec, const XMMATRIX& m) {
			return (Vector3)XMVector3Transform(XMVECTOR(Vec), m);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 Transform(const Vector3& Vec, const Matrix4X4& m) {
			return (Vector3)XMVector3Transform(XMVECTOR(Vec), XMMATRIX(m));
		}
	};
	//end Vector3EX

	void Vector4::Transform(const Matrix4X4& m) {
		*this = XMVector4Transform(XMVECTOR(*this), XMMATRIX(m));
	}


	//--------------------------------------------------------------------------------------
	///	Vector4EX�i4�����x�N�g���j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace Vector4EX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����񂩂�쐬����
		@param[in]	x_str	X���l�ɕϊ��ł��镶����
		@param[in]	y_str	Y���l�ɕϊ��ł��镶����
		@param[in]	z_str	Z���l�ɕϊ��ł��镶����
		@param[in]	w_str	W���l�ɕϊ��ł��镶����
		@return	�쐬�����x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 WStr4ToVec4(wstring& x_str, wstring& y_str, wstring& z_str, wstring& w_str) {
			return
				Vector4(
					(float)_wtof(x_str.c_str()),
					(float)_wtof(y_str.c_str()),
					(float)_wtof(z_str.c_str()),
					(float)_wtof(w_str.c_str())
					);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Equal(const Vector4& Vec, const Vector4& other) {
			return XMVector4Equal(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ��������ǂ��������؂���B<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool EqualInt(const Vector4& Vec, const Vector4& other) {
			return XMVector4EqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�傫�����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Greater(const Vector4& Vec, const Vector4& other) {
			return XMVector4Greater(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȏ�̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȏ�̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool GreaterOrEqual(const Vector4& Vec, const Vector4& other) {
			return XMVector4GreaterOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g�����l�̂����ꂩ���������̖����傩�ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���������̖�����Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Vector4& Vec) {
			return XMVector4IsInfinite(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒l�̂����ꂩ���񐔁i�����l�j���ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@return	�l�̂����ꂩ���񐔁i�����l�j�Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Vector4& Vec) {
			return XMVector4IsNaN(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g����菬�������ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Less(const Vector4& Vec, const Vector4& other) {
			return XMVector4Less(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���ȉ��̑傫�����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�ȉ��̑傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool LessOrEqual(const Vector4& Vec, const Vector4& other) {
			return XMVector4LessOrEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g�����߂��傫�����ǂ��������؂���B
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@param[in]	Epsilon	��r����ő勖�e��
		@return	�߂��傫���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NearEqual(const Vector4& Vec, const Vector4& other, float Epsilon) {
			float temp = Epsilon;
			XMVECTOR VecEp = XMLoadFloat(&temp);
			return XMVector4NearEqual(XMVECTOR(Vec), XMVECTOR(other), VecEp);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqual(const Vector4& Vec, const Vector4& other) {
			return XMVector4NotEqual(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����������̃x�N�g���Ɠ������Ȃ����ǂ��������؂���<br />
		���ꂼ��̗v�f�͕����Ȃ������Ƃ��Ĉ���
		@param[in]	Vec	�x�N�g��
		@param[in]	other	��r����x�N�g��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqualInt(const Vector4& Vec, const Vector4& other) {
			return XMVector4NotEqualInt(XMVECTOR(Vec), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z����B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenNormals(const Vector4& Vec1, const Vector4& Vec2) {
			return ((Vector4)XMVector4AngleBetweenNormals(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�������x�N�g�����m�̃��W�A���p�x���v�Z�\������B���K���͂��Ȃ��̂ŁA�����͂͂��炩���ߐ��K�����Ă���<br />
		�x�N�g���̃��W�A���p�v�Z�ł́A���K�����Ȃ�������
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenNormalsEst(const Vector4& Vec1, const Vector4& Vec2) {
			return ((Vector4)XMVector4AngleBetweenNormalsEst(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃x�N�g���Ԃ̃��W�A���p���v�Z����
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	���W�A���p
		*/
		//--------------------------------------------------------------------------------------
		inline  float AngleBetweenVectors(const Vector4& Vec1, const Vector4& Vec2) {
			return ((Vector4)XMVector4AngleBetweenVectors(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMin	�����̍ŏ��l
		@param[in]	LengthMax	�����̍ő�l
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 ClampLength(const Vector4& Vec, float LengthMin, float LengthMax) {
			return (Vector4)XMVector4ClampLength(XMVECTOR(Vec), LengthMin, LengthMax);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒������w�肵���傫���ɃN�����v����
		@param[in]	Vec	�x�N�g��
		@param[in]	LengthMinV	�����̍ŏ��l(�x�N�g��)
		@param[in]	LengthMaxV	�����̍ő�l(�x�N�g��)
		@return	�N�����v�������ʃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 ClampLengthV(const Vector4& Vec, const Vector4& LengthMinV, const Vector4& LengthMaxV) {
			return (Vector4)XMVector4ClampLengthV(XMVECTOR(Vec), XMVECTOR(LengthMinV), XMVECTOR(LengthMaxV));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O�ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@param[in]	Vec3	�x�N�g��3
		@return	�O��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Cross(const Vector4& Vec1, const Vector4& Vec2, const Vector4& Vec3) {
			return (Vector4)XMVector4Cross(XMVECTOR(Vec1), XMVECTOR(Vec2), XMVECTOR(Vec3));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ς��v�Z���ĕԂ�
		@param[in]	Vec1	�x�N�g��1
		@param[in]	Vec2	�x�N�g��2
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline  float Dot(const Vector4& Vec1, const Vector4& Vec2) {
			return ((Vector4)XMVector4Dot(XMVECTOR(Vec1), XMVECTOR(Vec2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���ׂĂ̗v�f���A�ݒ肳�ꂽ���E�x�N�g�����ɂ���ꍇ��true��Ԃ�
		@param[in]	Vec1	��r���x�N�g��
		@param[in]	Vec2	��r����x�N�g��
		@return	���E���ɂ���ꍇ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool InBounds(const Vector4& Vec1, const Vector4& Vec2) {
			return XMVector4InBounds(XMVECTOR(Vec1), XMVECTOR(Vec2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒���
		*/
		//--------------------------------------------------------------------------------------
		inline  float Length(const Vector4& Vec) {
			return ((Vector4)XMVector4Length(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����\�z���ĕԂ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̗\�z
		*/
		//--------------------------------------------------------------------------------------
		inline  float LengthEst(const Vector4& Vec) {
			return ((Vector4)XMVector4LengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒�����2���Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒�����2��
		*/
		//--------------------------------------------------------------------------------------
		inline  float LengthSq(const Vector4& Vec) {
			return ((Vector4)XMVector4LengthSq(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���𐳋K������
		@param[in]	Vec	�x�N�g��
		@return	���K�������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Normalize(const Vector4& Vec) {
			return (Vector4)XMVector4Normalize(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K���̗\�z�x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	���K���̗\�z�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 NormalizeEst(const Vector4& Vec) {
			return (Vector4)XMVector4NormalizeEst(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�����ȃx�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�����ȃx�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Orthogonal(const Vector4& Vec) {
			return (Vector4)XMVector4Orthogonal(XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t����Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t��
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLength(const Vector4& Vec) {
			return ((Vector4)XMVector4ReciprocalLength(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���̒����̋t���̗\���l��Ԃ�
		@param[in]	Vec	�x�N�g��
		@return	�x�N�g���̒����̋t���̗\���l
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLengthEst(const Vector4& Vec) {
			return ((Vector4)XMVector4ReciprocalLengthEst(XMVECTOR(Vec))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���Ĕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	�@���x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Reflect(const Vector4& Vec, const Vector4& Normal) {
			return (Vector4)XMVector4Reflect(XMVECTOR(Vec), XMVECTOR(Normal));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ�
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Refract(const Vector4& Vec, const Vector4& Normal, float RefractionIndex) {
			return (Vector4)XMVector4Refract(XMVECTOR(Vec), XMVECTOR(Normal), RefractionIndex);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����@���x�N�g���ɂ���ċ��ܗ��x�N�g���i���ׂĂ̗v�f�������l�j�Ŕ��˂������x�N�g��(���˃x�N�g��)��Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	Normal	���܂�����@���x�N�g��
		@param[in]	RefractionIndex	���ܗ��x�N�g��
		@return	���˂������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 RefractV(const Vector4& Vec, const Vector4& Normal, const Vector4& RefractionIndex) {
			return (Vector4)XMVector4RefractV(XMVECTOR(Vec), XMVECTOR(Normal),
				XMVECTOR(RefractionIndex));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Transform(const Vector4& Vec, const XMMATRIX& m) {
			return (Vector4)XMVector4Transform(XMVECTOR(Vec), m);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g����m�ɂ���ăg�����X�t�H�[���������x�N�g����Ԃ�
		@param[in]	Vec	�x�N�g��
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[���������x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Transform(const Vector4& Vec, const Matrix4X4& m) {
			return (Vector4)XMVector4Transform(XMVECTOR(Vec), XMMATRIX(m));
		}


	};
	//end Vector4EX

	void Vector3::WorldToSCreen(const Matrix4X4& m, float ViewWidth, float ViewHeight) {
		Vector4 Pos4 = *this;
		Pos4.w = 1.0f;
		//���W�ϊ�
		Pos4.Transform(m);
		//����
		Pos4.x /= Pos4.w;
		Pos4.y /= Pos4.w;
		Pos4.z /= Pos4.w;
		//���W�P�ʂ̏C��
		Pos4.x += 1.0f;
		Pos4.y += 1.0f;
		Pos4.y = 2.0f - Pos4.y;
		//�r���[�|�[�g�ϊ�
		Pos4.x *= (ViewWidth * 0.5f);
		Pos4.y *= (ViewHeight * 0.5f);
		*this = XMVECTOR(Pos4);
	}




}
//end of namespace basecross.



