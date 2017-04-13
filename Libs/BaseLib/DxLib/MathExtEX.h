/*!
@file MathExtEX.h
@brief �s��A�N�I�[�^�j�I���A�J���[�Ȃǂ�namespace�ɂ��v�Z<br />
XNAMATH �̃��b�s���O�֐��Q
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/

#pragma once

#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	PlaneEX�i���ʁj�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace PlaneEX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane��Vector4�̓��ς�Ԃ��B���ʂƓ������W�̊֌W�𔻒肷��Ƃ��ɖ𗧂B<br />
		���Ƃ��΁A���̊֐����g�p���Ă�����W������̕��ʏ�ɑ��݂��邩�A<br />
		�܂��͍��W�����ʂ̂ǂ��瑤�ɑ��݂��邩�Ȃǂ𔻒�ł���B
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	�v�Z����Vector4
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline float Dot(const Plane& plane, const Vector4& other) {
			return ((Vector4)XMPlaneDot(XMVECTOR(plane), XMVECTOR(other))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane��Vector3�̓��ς��v�Z���Ԃ�<br/>
		����|�C���g���畽�ʂ܂ł̕����t�����������߂�̂ɕ֗��ł���
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	�v�Z����Vector3
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline float DotCoord(const Plane& plane, const Vector3& other) {
			return  ((Vector4)XMPlaneDotCoord(XMVECTOR(plane), XMVECTOR(other))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�̖@���x�N�g���� 3D �x�N�g���̊Ԃ̓��ς��v�Z���Ԃ�<br/>
		���ʂ̖@���x�N�g���ƕʂ̖@���x�N�g���Ƃ̊p�x���Z�o����Ƃ��ɖ𗧂�
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	�v�Z����Vector3
		@return	����
		*/
		//--------------------------------------------------------------------------------------
		inline float DotNormal(const Plane& plane, const Vector3& other) {
			return ((Vector4)XMPlaneDotNormal(XMVECTOR(plane), XMVECTOR(other))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�Ƒ���̕��ʂ��������ǂ����𒲂ׂ�
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	�����Plane
		@return	�����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline bool Equal(const Plane& plane, const Plane& other) {
			return XMPlaneEqual(XMVECTOR(plane), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�_�Ɩ@�����畽�ʂ��쐬���āA�Ԃ�
		@param[in]	Point	���ʏ�̓_
		@param[in]	Normal	�@��
		@return	�쐬����Plane
		*/
		//--------------------------------------------------------------------------------------
		inline  Plane FromPointNormal(const Vector3& Point, const Vector3& Normal) {
			return (Plane)XMPlaneFromPointNormal(XMVECTOR(Point), XMVECTOR(Normal));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R�_���畽�ʂ��쐬���āA�Ԃ�
		@param[in]	Point1	���_1
		@param[in]	Point2	���_2
		@param[in]	Point3	���_3
		@return	�쐬����Plane
		*/
		//--------------------------------------------------------------------------------------
		inline  Plane FromPoints(const Vector3& Point1, const Vector3& Point2, const Vector3& Point3) {
			return (Plane)XMPlaneFromPoints(XMVECTOR(Point1), XMVECTOR(Point2), XMVECTOR(Point3));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�ƂQ�̒��_���쐬���钼���̌������钸�_��Ԃ�<br />
		���ʂƒ��������s�̏ꍇ�́A�߂�e�l��QNaN�i�񐔁j �ɂȂ�̂ŁA<br />
		Vector3::IsNaN()�ȂǂŃ`�F�b�N����
		@param[in]	plane	�v�Z���̕���
		@param[in]	LinePoint1	���_1
		@param[in]	LinePoint2	���_2
		@return	plane�ƌ�������R�c�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 IntersectLine(const Plane& plane,
			const Vector3& LinePoint1, const Vector3& LinePoint2) {
			return (Vector3)XMPlaneIntersectLine(XMVECTOR(plane),
				XMVECTOR(LinePoint1), XMVECTOR(LinePoint2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�Ƃ�����̖ʂ���������2�̒��_���v�Z����<br />
		RetLinePoint1��RetLinePoint2�Ɍ������钸�_��Ԃ�<br />
		2�̕��ʂ����s�̏ꍇ�́A�߂�e�l��QNaN�i�񐔁j �ɂȂ�̂ŁA<br />
		Vector3::IsNaN()�ȂǂŃ`�F�b�N����
		@param[out]	RetLinePoint1	�Ԃ���钸�_1
		@param[out]	RetLinePoint2	�Ԃ���钸�_2
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	plane�Ɣ�ׂ��������̖�
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		inline  void IntersectPlane(Vector3& RetLinePoint1, Vector3& RetLinePoint2,
			const Plane& plane, const Plane& other) {
			XMVECTOR Temp1, Temp2;
			XMPlaneIntersectPlane(&Temp1, &Temp2, XMVECTOR(plane), XMVECTOR(other));
			RetLinePoint1 = (Vector3)Temp1;
			RetLinePoint2 = (Vector3)Temp2;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�̗v�f�̂����ꂩ�����܂��͕��̖����傩�ǂ����𒲂ׂ�
		@param[in]	plane	�v�Z���̕���
		@return	���܂��͕��̖�����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Plane& plane) {
			return XMPlaneIsInfinite(XMVECTOR(plane));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Plane�̗v�f�̂����ꂩ�� NaN���ǂ����𒲂ׂ�
		@param[in]	plane	�v�Z���̕���
		@return	NaN�Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Plane& plane) {
			return XMPlaneIsNaN(XMVECTOR(plane));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�Ƃ�����̕��ʂ��قړ��������ǂ������ׂ�
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	plane�Ɣ�ׂ��������̖�
		@param[in]	Epsilon	�e�v�f�̋��e�͈�
		@return	�قړ��������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NearEqual(const Plane& plane, const Plane& other, const Vector4& Epsilon) {
			return XMPlaneNearEqual(XMVECTOR(plane), XMVECTOR(other), Epsilon);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�𐳋K������
		@param[in]	plane	�v�Z���̕���
		@return	���K����������
		*/
		//--------------------------------------------------------------------------------------
		inline  Plane Normalize(const Plane& plane) {
			return (Plane)XMPlaneNormalize(XMVECTOR(plane));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane��x,y,z�̌W�����P�ʂ̖@���x�N�g�����`������悤�ɁA���ʂ̌W����\��
		@param[in]	plane	�v�Z���̕���
		@return	�\����������
		*/
		//--------------------------------------------------------------------------------------
		inline  Plane NormalizeEst(const Plane& plane) {
			return (Plane)XMPlaneNormalizeEst(XMVECTOR(plane));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane�Ƒ���̕��ʂ��������Ȃ����ǂ����𒲂ׂ�
		@param[in]	plane	�v�Z���̕���
		@param[in]	other	����̕���
		@return	�������Ȃ��Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqual(const Plane& plane, const Plane& other) {
			return XMPlaneNotEqual(XMVECTOR(plane), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	plane��m�Ńg�����X�t�H�[������
		@param[in]	plane	�v�Z���̕���
		@param[in]	m	�g�����X�t�H�[������s��
		@return	�g�����X�t�H�[����������
		*/
		//--------------------------------------------------------------------------------------
		inline  Plane Transform(const Plane& plane, const XMMATRIX& m) {
			return (Plane)XMPlaneTransform(XMVECTOR(plane), m);
		}
		//�@XMPlaneTransformStream�֐��́A���b�s���O�֐��͗p�ӂ��Ȃ�
		//�@���R�F�p�����[�^�ɔz���n���K�v������A���b�s���O�ɂ���āA�œK�������Ȃ���
	}
	//end PlaneEX

	//--------------------------------------------------------------------------------------
	///	Color4EX�i�J���[�j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace Color4EX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[�Ɠ��������ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Equal(const Color4& Col, const Color4& other) {
			return XMColorEqual(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[�Ɠ������Ȃ����ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqual(const Color4& Col, const Color4& other) {
			return XMColorNotEqual(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[���傫�����ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	�傫�����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Greater(const Color4& Col, const Color4& other) {
			return XMColorGreater(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[�ȏォ�ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	�ȏ�ł����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool GreaterOrEqual(const Color4& Col, const Color4& other) {
			return XMColorGreaterOrEqual(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[�ȉ����ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	�ȉ��ł����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool LessOrEqual(const Color4& Col, const Color4& other) {
			return XMColorLessOrEqual(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��������̃J���[��菬�������ǂ��������؂���
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	other	��r����J���[
		@return	��菬�������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Less(const Color4& Col, const Color4& other) {
			return XMColorLess(XMVECTOR(Col), XMVECTOR(other));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[�̂����ꂩ�̐��������܂��͕��̖����傩�ǂ������e�X�g����
		@param[in]	Col	�v�Z���̃J���[
		@return	�J���[�̂����ꂩ�̐��������܂��͕��̖�����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Color4& Col) {
			return XMColorIsInfinite(XMVECTOR(Col));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[�̂����ꂩ�̐�����NaN���ǂ������e�X�g����
		@param[in]	Col	�v�Z���̃J���[
		@return	�J���[�̂����ꂩ�̐�����NaN�Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Color4& Col) {
			return XMColorIsNaN(XMVECTOR(Col));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[��0.0����1.0�͈̔͂ɒ�������B�͈͊O�̗v�f��0.0��1.0�ɐݒ肳���
		@param[in]	Col	�v�Z���̃J���[
		@return	���������J���[
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 AdjustRange(const Color4& Col) {
			Color4 temp = Col;
			if (temp.x <= 0) {
				temp.x = 0;
			}
			if (temp.y <= 0) {
				temp.y = 0;
			}
			if (temp.z <= 0) {
				temp.z = 0;
			}
			if (temp.w <= 0) {
				temp.w = 0;
			}
			if (temp.x >= 1.0f) {
				temp.x = 1.0f;
			}
			if (temp.y >= 1.0f) {
				temp.y = 1.0f;
			}
			if (temp.z >= 1.0f) {
				temp.z = 1.0f;
			}
			if (temp.w >= 1.0f) {
				temp.w = 1.0f;
			}
			return temp;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[�̃R���g���X�g�𒲐߂���B�J���[��0.0����1.0�͈̔͂ɒ�������A�v�Z�����
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	Contrast	�R���g���X�g�͈�
		@return	���������J���[
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 AdjustContrast(const Color4& Col, float Contrast) {
			Color4 temp = Col;
			temp.AdjustRange();
			return (Color4)XMColorAdjustContrast(XMVECTOR(temp), Contrast);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[�̍ʓx�𒲐߂���B�J���[��0.0����1.0�͈̔͂ɒ�������A�v�Z�����B<br />
		�ʓx�l��0�̏ꍇ�̓O���[�X�P�[���A1.0�̏ꍇ�͂��Ƃ̐F�ɂȂ�
		@param[in]	Col	�v�Z���̃J���[
		@param[in]	Saturation	�ʓx�l
		@return	���������J���[
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 AdjustSaturation(const Color4& Col, float Saturation) {
			Color4 temp = Col;
			temp.AdjustRange();
			return (Color4)XMColorAdjustSaturation(XMVECTOR(temp), Saturation);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�Ή����鐬������Z����2�̃J���[���u�����h����B
		@param[in]	Col1	�J���[1
		@param[in]	Col2	�J���[2
		@return	�u�����h�����J���[
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 Modulate(const Color4& Col1, const Color4& Col2) {
			return (Color4)XMColorModulate(XMVECTOR(Col1), XMVECTOR(Col2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J���[�̕��� RGB �J���[�l�����߂�B�J���[��0.0����1.0�͈̔͂ɒ�������A�v�Z�����B
		@param[in]	Col	�v�Z���̃J���[
		@return	����RGB�J���[�l
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 Negative(const Color4& Col) {
			Color4 temp = Col;
			temp.AdjustRange();
			return (Color4)XMColorNegative(XMVECTOR(temp));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�O���[�̃J���[�𓾂�B
		@return	�O���[�̃J���[�l�i0.5,0.5,0.5,1.0�j
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 GrayColor() {
			return Color4(0.5f, 0.5f, 0.5f, 1.0f);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���̃J���[�𓾂�B
		@return	���̃J���[�l�i1.0,1.0,1.0,1.0�j
		*/
		//--------------------------------------------------------------------------------------
		inline  Color4 WhiteColor() {
			return Color4(1.0f, 1.0f, 1.0f, 1.0f);
		}
	}
	//end Color4EX

	//--------------------------------------------------------------------------------------
	///	QuaternionEX�i�N�I�[�^�j�I���j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace QuaternionEX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I�������������ǂ��������؂���
		@param[in]	Qt1	�N�I�[�^�j�I��1
		@param[in]	Qt2	�N�I�[�^�j�I��2
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool Equal(const Quaternion& Qt1, const Quaternion& Qt2) {
			return XMQuaternionEqual(XMVECTOR(Qt1), XMVECTOR(Qt2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I�����������Ȃ����ǂ��������؂���
		@param[in]	Qt1	�N�I�[�^�j�I��1
		@param[in]	Qt2	�N�I�[�^�j�I��2
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool NotEqual(const Quaternion& Qt1, const Quaternion& Qt2) {
			return XMQuaternionNotEqual(XMVECTOR(Qt1), XMVECTOR(Qt2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���� �P�ʃN�I�[�^�j�I��(0, 0, 0, 1)���ǂ��������؂���B
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�P�ʃN�I�[�^�j�I���Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsIdentity(const Quaternion& Qt) {
			return XMQuaternionIsIdentity(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̒l�̂����ꂩ���������̖����傩�ǂ��������؂���B
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�l�̂����ꂩ���������̖�����Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Quaternion& Qt) {
			return XMQuaternionIsInfinite(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̒l�̂����ꂩ��NaN���ǂ��������؂���B
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�l�̂����ꂩ��NaN�Ȃ��true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Quaternion& Qt) {
			return XMQuaternionIsNaN(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I������]�x�N�g���ɂ��ǉ���]����
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@param[in]	other	�ǉ���]�����]�x�N�g��
		@return	�v�Z���ʂ̃N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion AddRotation(const Quaternion& Qt, const Vector3& other) {
			Quaternion Span;
			Span.RotationRollPitchYawFromVector(other);
			return (Quaternion)XMQuaternionMultiply(XMVECTOR(Qt), XMVECTOR(Span));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I�������]�x�N�g���ɕϊ����ĕԂ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	��]�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 GetRotation(const Quaternion& Qt) {
			Quaternion Temp = Qt;
			Temp.Normalize();
			Matrix4X4 mt;
			mt.RotationQuaternion(Temp);
			Vector3 Rot;
			if (mt._32 == 1.0f) {
				Rot.x = XM_PI / 2.0f;
				Rot.y = 0;
				Rot.z = -atan2(mt._21, mt._11);
			}
			else if (mt._32 == -1.0f) {
				Rot.x = -XM_PI / 2.0f;
				Rot.y = 0;
				Rot.z = -atan2(mt._21, mt._11);
			}
			else {
				Rot.x = -asin(mt._32);
				Rot.y = -atan2(-mt._31, mt._33);
				Rot.z = atan2(mt._12, mt._11);
			}
			return Rot;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肳�ꂽ�N�I�[�^�j�I�����g�p���āA�d�S���W�̃|�C���g��Ԃ�
		@param[in]	Q0	�O�p�`��1�ڂ̃N�I�[�^�j�I��
		@param[in]	Q1	�O�p�`��2�ڂ̃N�I�[�^�j�I��
		@param[in]	Q2	�O�p�`��3�ڂ̃N�I�[�^�j�I��
		@param[in]	f	���d�W��
		@param[in]	g	���d�W��
		@return	�d�S���W�̃N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion BaryCentric(const Quaternion& Q0, const Quaternion& Q1, const Quaternion& Q2, float f, float g) {
			return (Quaternion)XMQuaternionBaryCentric(XMVECTOR(Q0), XMVECTOR(Q1), XMVECTOR(Q2), f, g);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肳�ꂽ�N�I�[�^�j�I���ƃx�N�g�����g�p���āA�d�S���W�̃|�C���g��Ԃ�
		@param[in]	Q0	�O�p�`��1�ڂ̃N�I�[�^�j�I��
		@param[in]	Q1	�O�p�`��2�ڂ̃N�I�[�^�j�I��
		@param[in]	Q2	�O�p�`��3�ڂ̃N�I�[�^�j�I��
		@param[in]	f	���d�W���x�N�g���i���ꂼ��v�f�������l�ɂ���j
		@param[in]	g	���d�W���x�N�g���i���ꂼ��v�f�������l�ɂ���j
		@return	�d�S���W�̃N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion BaryCentricV(const Quaternion& Q0, const Quaternion& Q1, const Quaternion& Q2,
			const Vector4& f, const Vector4& g) {
			return (Quaternion)XMQuaternionBaryCentricV(XMVECTOR(Q0), XMVECTOR(Q1), XMVECTOR(Q2), XMVECTOR(f), XMVECTOR(g));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̋�����Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̋���
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Conjugate(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionConjugate(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I���̓��ς�Ԃ�
		@param[in]	Qt1	�N�I�[�^�j�I��1
		@param[in]	Qt2	�N�I�[�^�j�I��2
		@return	�N�I�[�^�j�I���̓���
		*/
		//--------------------------------------------------------------------------------------
		inline  float Dot(const Quaternion& Qt1, const Quaternion& Qt2) {
			return ((Vector4)XMQuaternionDot(XMVECTOR(Qt1), XMVECTOR(Qt2))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̎w����Ԃ��B���͂�w�v�f�͖��������
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̎w��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Exp(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionExp(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�P�ʃN�I�[�^�j�I����Ԃ�
		@return	�P�ʃN�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Identity() {
			return (Quaternion)XMQuaternionIdentity();
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̔��]��Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	���]�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Inverse(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionInverse(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̒�����Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̒���
		*/
		//--------------------------------------------------------------------------------------
		inline  float Length(const Quaternion& Qt) {
			return ((Vector4)XMQuaternionLength(XMVECTOR(Qt))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̒�����2���Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̒�����2��
		*/
		//--------------------------------------------------------------------------------------
		inline  float LengthSq(const Quaternion& Qt) {
			return ((Vector4)XMQuaternionLengthSq(XMVECTOR(Qt))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̎��R�ΐ���Ԃ��i���͂͐��K�����Ă����j�B
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̎��R�ΐ�
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Ln(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionLn(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I������Z���ĕԂ�
		@param[in]	Qt1	�v�Z���̃N�I�[�^�j�I��
		@param[in]	Qt2	��Z����N�I�[�^�j�I��
		@return	�N�I�[�^�j�I������Z��������
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Multiply(const Quaternion& Qt1, const Quaternion& Qt2) {
			return (Quaternion)XMQuaternionMultiply(XMVECTOR(Qt1), XMVECTOR(Qt2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���𐳋K�����ĕԂ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	���K�������N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Normalize(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionNormalize(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���𐳋K���o�[�W�����̗\���l��Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	���K���o�[�W�����̗\���l
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion NormalizeEst(const Quaternion& Qt) {
			return (Quaternion)XMQuaternionNormalizeEst(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I���̒����̋t����Ԃ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�N�I�[�^�j�I���̒����̋t��
		*/
		//--------------------------------------------------------------------------------------
		inline  float ReciprocalLength(const Quaternion& Qt) {
			return ((Vector4)XMQuaternionReciprocalLength(XMVECTOR(Qt))).x;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��]���Ɗp�x����N�I�[�^�j�I�����쐬����
		@param[in]	Vec	��]����\���R�c�x�N�g��
		@param[in]	Angle	��]�p�x�i���v��胉�W�A���j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion RotationAxis(const Vector3& Vec, float Angle) {
			return (Quaternion)XMQuaternionRotationAxis(XMVECTOR(Vec), Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	��]�s�񂩂�N�I�[�^�j�I�����쐬����
		@param[in]	m	��]�s��
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion RotationMatrix(const XMMATRIX& m) {
			return (Quaternion)XMQuaternionRotationMatrix(m);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���K�����ꂽ��]���Ɗp�x����N�I�[�^�j�I�����쐬����
		@param[in]	Vec	��]����\�����K�����ꂽ�R�c�x�N�g��
		@param[in]	Angle	��]�p�x�i���v��胉�W�A���j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion RotationNormal(const Vector3& Vec, float Angle) {
			return (Quaternion)XMQuaternionRotationNormal(XMVECTOR(Vec), Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e���̉�]����N�I�[�^�j�I�����쐬����B��]��RollPitchYaw�iZ,Y,X�j�̏��ōs����B
		@param[in]	Pitch	X����]�i���W�A���j
		@param[in]	Yaw		Y����]�i���W�A���j
		@param[in]	Roll	Z����]�i���W�A���j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion RotationRollPitchYaw(float Pitch, float Yaw, float Roll) {
			return (Quaternion)XMQuaternionRotationRollPitchYaw(Pitch, Yaw, Roll);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	3D��]�x�N�g������N�I�[�^�j�I�����쐬����B��]��RollPitchYaw�iZ,Y,X�j�̏��ōs����B
		@param[in]	Vec	��]����\���R�c�x�N�g��
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion RotationRollPitchYawFromVector(const Vector3& Vec) {
			return (Quaternion)XMQuaternionRotationRollPitchYawFromVector(Vec);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I������W���ŕ�Ԃ��ꂽ�N�I�[�^�j�I�����쐬����B<br />
		�W����0�̏ꍇ��Q0�A1.0�Ȃ�Q1�Ɠ������̂�Ԃ�
		@param[in]	Qt0	��Ԍ��i���K�����ꂽ�N�I�[�^�j�I���j
		@param[in]	Qt1	��Ԑ�i���K�����ꂽ�N�I�[�^�j�I���j
		@param[in]	t	��ԌW���i0.0f����1.0f�̊Ԃ��w��j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Slerp(const Quaternion& Qt0, const Quaternion& Qt1, float t) {
			return (Quaternion)XMQuaternionSlerp(XMVECTOR(Qt0), XMVECTOR(Qt1), t);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̃N�I�[�^�j�I������W��(�x�N�g��)�ŕ�Ԃ��ꂽ�N�I�[�^�j�I�����쐬����B<br />
		�W����0�̏ꍇ��Q0�A1.0�Ȃ�Q1�Ɠ������̂�Ԃ�
		@param[in]	Qt0	��Ԍ��i���K�����ꂽ�N�I�[�^�j�I���j
		@param[in]	Qt1	��Ԑ�i���K�����ꂽ�N�I�[�^�j�I���j
		@param[in]	Vec	��ԌW���i���ׂĂ̗v�f��0.0f����1.0f�̊Ԃ̓����l���w��j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion SlerpV(const Quaternion& Qt0, const Quaternion& Qt1, const Vector4& Vec) {
			return (Quaternion)XMQuaternionSlerpV(XMVECTOR(Qt0), XMVECTOR(Qt1), XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���󕽕���Ԃ��g�p���āA4 �̒P�ʃN�I�[�^�j�I���Ԃ��Ԃ���<br />
		Q1�AQ2�AQ3��QuaternionEX::SquadSetup�֐��ō쐬����
		@param[in]	Qt0	���K�����ꂽ�N�I�[�^�j�I��0
		@param[in]	Qt1	���K�����ꂽ�N�I�[�^�j�I��1
		@param[in]	Qt2	���K�����ꂽ�N�I�[�^�j�I��2
		@param[in]	Qt3	���K�����ꂽ�N�I�[�^�j�I��3
		@param[in]	t	��Ԑ���W��
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Squad(const Quaternion& Qt0, const Quaternion& Qt1, const Quaternion& Qt2, const Quaternion& Qt3, float t) {
			return (Quaternion)XMQuaternionSquad(XMVECTOR(Qt0), XMVECTOR(Qt1), XMVECTOR(Qt2), XMVECTOR(Qt3), t);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���󕽕���Ԃ̂��߂̃Z�b�g�A�b�v���s��<br />
		pA�ApB�ApC�͂��ꂼ��Squad()�ASquadV()�֐���Qt1�AQt2�AQt3�ɓ��͂���
		@param[out]	pA	���ʂ��󂯂�N�I�[�^�j�I��A
		@param[out]	pB	���ʂ��󂯂�N�I�[�^�j�I��B
		@param[out]	pC	���ʂ��󂯂�N�I�[�^�j�I��C
		@param[in]	Qt0	���K�����ꂽ�N�I�[�^�j�I��0
		@param[in]	Qt1	���K�����ꂽ�N�I�[�^�j�I��1
		@param[in]	Qt2	���K�����ꂽ�N�I�[�^�j�I��2
		@param[in]	Qt3	���K�����ꂽ�N�I�[�^�j�I��2
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  void SquadSetup(Quaternion* pA, Quaternion* pB, Quaternion* pC,
			const Quaternion& Qt0, const Quaternion& Qt1, const Quaternion& Qt2, const Quaternion& Qt3) {
			XMVECTOR A(*pA);
			XMVECTOR B(*pB);
			XMVECTOR C(*pC);
			XMQuaternionSquadSetup(&A, &B, &C,
				XMVECTOR(Qt0), XMVECTOR(Qt1), XMVECTOR(Qt2), XMVECTOR(Qt3));
			*pA = A;
			*pB = B;
			*pC = C;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	���󕽕���Ԃ��g�p���āA4 �̒P�ʃN�I�[�^�j�I���Ԃ��Ԃ���<br />
		Q1�AQ2�AQ3��QuaternionEX::SquadSetup�֐��ō쐬����
		@param[in]	Qt0	���K�����ꂽ�N�I�[�^�j�I��0
		@param[in]	Qt1	���K�����ꂽ�N�I�[�^�j�I��1
		@param[in]	Qt2	���K�����ꂽ�N�I�[�^�j�I��2
		@param[in]	Qt3	���K�����ꂽ�N�I�[�^�j�I��3
		@param[in]	Vec	��Ԑ���W���i���ׂĂ̗v�f��0.0f����1.0f�̊Ԃ̓����l���w��j
		@return	�쐬�����N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion SquadV(const Quaternion& Qt0, const Quaternion& Qt1, const Quaternion& Qt2, const Quaternion& Qt3, const Vector4& Vec) {
			return (Quaternion)XMQuaternionSquadV(XMVECTOR(Qt0), XMVECTOR(Qt1), XMVECTOR(Qt2), XMVECTOR(Qt3), XMVECTOR(Vec));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I������A��]���Ɖ�]�p�x�𓾂�<br />
		pVec�ɂ͉�]���x�N�g���ApAngle�ɂ͊p�x���ݒ肳���
		@param[out]	pVec	��]���𓾂�R�c�x�N�g��
		@param[out]	pAngle	��]�p�x�𓾂�ϐ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		inline  void ToAxisAngle(Vector3* pVec, float* pAngle, const Quaternion& Qt) {
			XMVECTOR Vec(*pVec);
			XMQuaternionToAxisAngle(&Vec, pAngle, XMVECTOR(Qt));
			*pVec = Vec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I������A��]���Ɖ�]�p�x�𓾂�<br />
		rVec�ɂ͉�]���x�N�g���ArAngle�ɂ͊p�x���ݒ肳���
		@param[out]	rVec	��]���𓾂�R�c�x�N�g��
		@param[out]	rAngle	��]�p�x�𓾂�ϐ�
		@param[in]	Qt	�v�Z���̃N�I�[�^�j�I��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		inline  void ToAxisAngle(Vector3& rVec, float& rAngle, const Quaternion& Qt) {
			XMVECTOR Vec(rVec);
			XMQuaternionToAxisAngle(&Vec, &rAngle, XMVECTOR(Qt));
			rVec = Vec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Line�ɑ΂��ăr���{�[�h�p�x��ݒ肵���N�I�[�^�j�I���𓾂�
		@param[in]	Line	�v�Z���ƂȂ��
		@return	�N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Billboard(const Vector3& Line) {
			Vector3 Temp = Line;
			Matrix4X4 RotMatrix;
			Vector4 dammi(0, 0, 0, 0);
			Vector3 DefUp(0, 1.0f, 0);
			Vector2 TempVec2(Temp.x, Temp.z);
			if (TempVec2.Length() < 0.1f) {
				DefUp = Vector3(0, 0, 1.0f);
			}
			Temp.Normalize();
			RotMatrix.LookAtLH(Vector3(0, 0, 0), Temp, DefUp);
			RotMatrix.Inverse(&dammi);
			Quaternion Qt;
			Qt = RotMatrix.QtInMatrix();
			Qt.Normalize();
			return Qt;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Line�ɑ΂��ăt�F�C�V���O�p�x��ݒ肵���N�I�[�^�j�I���𓾂�
		@param[in]	Line	�v�Z���ƂȂ��(�I�u�W�F�N�g����J�����ʒu������������)
		@return	�N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion Faceing(const Vector3& Line) {
			Vector3 Temp = Line;
			Matrix4X4 RotMatrix;
			Vector4 dammi(0, 0, 0, 0);
			Vector3 DefUp(0, 1.0f, 0);
			Vector2 TempVec2(Temp.x, Temp.z);
			if (TempVec2.Length() < 0.1f) {
				DefUp = Vector3(0, 0, 1.0f);
			}
			RotMatrix.LookAtLH(Vector3(0, 0, 0), Temp, DefUp);
			RotMatrix.Inverse(&dammi);
			Quaternion Qt;
			Qt = RotMatrix.QtInMatrix();
			Qt.Normalize();
			return Qt;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Line�ɑ΂���Y���t�F�C�V���O�p�x��ݒ肵���N�I�[�^�j�I���𓾂�
		@param[in]	Line	�v�Z���ƂȂ��(�I�u�W�F�N�g����J�����ʒu������������)
		@return	�N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion FaceingY(const Vector3& Line) {
			Vector3 Temp = Line;
			Temp.Normalize();
			Quaternion Qt;
			Qt.Identity();
			Qt.RotationRollPitchYaw(0, atan2(Temp.x, Temp.z), 0);
			Qt.Normalize();
			return Qt;
		}
	}
	//end QuaternionEX


	//--------------------------------------------------------------------------------------
	///	Matrix4X4EX�i4X4�s��j�l�[���X�y�[�X
	//--------------------------------------------------------------------------------------
	namespace Matrix4X4EX {
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̍s�񂪓��������ǂ��������؂���
		@param[in]	m1	��r��
		@param[in]	m2	��r��
		@return	���������true
		*/
		//--------------------------------------------------------------------------------------
		inline bool Equal(const Matrix4X4& m1, const Matrix4X4& m2){
			return (m1 == m2);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̍s�񂪓������Ȃ����ǂ��������؂���
		@param[in]	m1	��r��
		@param[in]	m2	��r��
		@return	�������Ȃ����true
		*/
		//--------------------------------------------------------------------------------------
		inline bool NotEqual(const Matrix4X4& m1, const Matrix4X4& m2){
			return (m1 != m2);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s����̈ʒu�����擾����(���ڍs�񂩂���o��)
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�ʒu�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 PosInMatrixSt(const Matrix4X4& m) {
			Vector3 Vec;
			Vec.x = m._41;
			Vec.y = m._42;
			Vec.z = m._43;
			return Vec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s����̈ʒu�����擾����(XMMAth�֐����g�p)
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�ʒu�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 PosInMatrix(const Matrix4X4& m) {
			Vector3 Vec(0, 0, 0);
			XMVECTOR Scale;
			XMVECTOR Qt;
			XMVECTOR Translation;
			if (XMMatrixDecompose(&Scale, &Qt, &Translation, XMMATRIX(m))) {
				Vec = Translation;
			}
			return Vec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s����̃X�P�[�����O���擾����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�X�P�[�����O�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 ScaleInMatrix(const Matrix4X4& m) {
			Vector3 Vec(1.0f, 1.0f, 1.0f);
			XMVECTOR Scale;
			XMVECTOR Qt;
			XMVECTOR Translation;
			if (XMMatrixDecompose(&Scale, &Qt, &Translation, XMMATRIX(m))) {
				Vec = Scale;
			}
			return Vec;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s����̉�]���擾����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	��]�N�I�[�^�j�I��
		*/
		//--------------------------------------------------------------------------------------
		inline  Quaternion QtInMatrix(const Matrix4X4& m) {
			Quaternion RetQt;
			XMVECTOR Scale;
			XMVECTOR Qt;
			XMVECTOR Translation;
			if (XMMatrixDecompose(&Scale, &Qt, &Translation, XMMATRIX(m))) {
				RetQt = Qt;
			}
			return RetQt;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s�����X����]���擾����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	X���̉�]�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 RotXInMatrix(const Matrix4X4& m) {
			Vector3 ret(m._11, m._12, m._13);
			Vector3 Scale = ScaleInMatrix(m);
			Matrix4X4::GetSafeScale(Scale);
			ret.x /= Scale.x;
			ret.y /= Scale.x;
			ret.z /= Scale.x;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s�����Y����]���擾����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	Y���̉�]�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 RotYInMatrix(const Matrix4X4& m) {
			Vector3 ret(m._21, m._22, m._23);
			Vector3 Scale = ScaleInMatrix(m);
			Matrix4X4::GetSafeScale(Scale);
			ret.x /= Scale.y;
			ret.y /= Scale.y;
			ret.z /= Scale.y;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s�����Z����]���擾����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	Z���̉�]�x�N�g��
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector3 RotZInMatrix(const Matrix4X4& m) {
			Vector3 ret(m._31, m._32, m._33);
			Vector3 Scale = ScaleInMatrix(m);
			Matrix4X4::GetSafeScale(Scale);
			ret.x /= Scale.z;
			ret.y /= Scale.z;
			ret.z /= Scale.z;
			return ret;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	2�̍s����׈ړ��݂̂̈Ⴂ�ł����true��Ԃ�(�S�������ꍇ��true)
		@param[in]	m1	��r��
		@param[in]	m2	��r��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		inline bool IsNotTranslationOnly(const Matrix4X4& m1, const Matrix4X4& m2){
			return m1.IsNotTranslationOnly(m2);
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	�A�t�B���ϊ��i�X�P�[�����O�A��]�̒��S���W�A�N�I�[�^�j�I���A���s�ړ��j����s����쐬����
		@param[in]	Scaling	�X�P�[�����O
		@param[in]	RotOrigin	��]�̒��S
		@param[in]	RotationQuaternion	�N�I�[�^�j�I��
		@param[in]	Translation	���s�ړ�
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 AffineTransformation(const Vector3& Scaling, const Vector3& RotOrigin,
			const Quaternion& RotationQuaternion, const Vector3& Translation) {
			return (Matrix4X4)XMMatrixAffineTransformation(XMVECTOR(Scaling), XMVECTOR(RotOrigin),
				XMVECTOR(RotationQuaternion), XMVECTOR(Translation));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�A�t�B���ϊ��i�X�P�[�����O�A��]�̒��S���W�A��]�l�i���W�A���j�A���s�ړ��j����2D�s������쐬����
		@param[in]	Scaling	�X�P�[�����O
		@param[in]	RotOrigin	��]�̒��S
		@param[in]	Rotation	��]�l�i���W�A���j
		@param[in]	Translation	���s�ړ�
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 AffineTransformation2D(const Vector2& Scaling,
			const Vector2& RotOrigin, float Rotation, const Vector2& Translation) {
			return (Matrix4X4)XMMatrixAffineTransformation2D(XMVECTOR(Scaling), XMVECTOR(RotOrigin),
				Rotation, XMVECTOR(Translation));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s�񂩂�X�P�[�����O�A��]�A���s�ړ������o��
		@param[out]	rScaling	�X�P�[�����O���󂯎��ϐ�
		@param[out]	rQt	�N�I�[�^�j�I�����󂯎��ϐ�
		@param[out]	rTranslation	���s�ړ����󂯎��ϐ�
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		inline  void Decompose(Vector3& rScaling, Quaternion& rQt,
			Vector3& rTranslation, const Matrix4X4& m) {
			XMVECTOR Scale;
			XMVECTOR Qt;
			XMVECTOR Translation;
			if (XMMatrixDecompose(&Scale, &Qt, &Translation, XMMATRIX(m))) {
				rScaling = Scale;
				rQt = Qt;
				rTranslation = Translation;
			}
			else {
				throw BaseException(
					L"�s��̃f�R���|�[�Y�Ɏ��s���܂���",
					L"if(!XMMatrixDecompose(&Scale, &Qt, &Translation, XMMATRIX(m)))",
					L"Matrix4X4EX::Decompose()"
					);
			}
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s�񎮂�Ԃ�
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�쐬�����s�񎮁iVector4�̊e�v�f�ɓ���j
		*/
		//--------------------------------------------------------------------------------------
		inline  Vector4 Determinant(const Matrix4X4& m) {
			return (Vector4)XMMatrixDeterminant(XMMATRIX(m));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�P�ʍs���Ԃ�
		@return	�P�ʍs��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Identity() {
			return (Matrix4X4)XMMatrixIdentity();
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�s���Ԃ��BpVec�ɂ͍s�񎮂�����
		@param[out]	pVec	�s�񎮂��󂯎��x�N�g��
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�t�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Inverse(Vector4* pVec, const Matrix4X4& m) {
			XMVECTOR Vec(*pVec);
			Matrix4X4 ret = (Matrix4X4)XMMatrixInverse(&Vec, XMMATRIX(m));
			*pVec = Vec;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�s���Ԃ��BpVec�ɂ͍s�񎮂�����
		@param[out]	rVec	�s�񎮂��󂯎��x�N�g��
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�t�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Inverse(Vector4& rVec, const Matrix4X4& m) {
			XMVECTOR Vec(rVec);
			Matrix4X4 ret = (Matrix4X4)XMMatrixInverse(&Vec, XMMATRIX(m));
			rVec = Vec;
			return ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�P�ʍs�񂩂ǂ��������؂���
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�P�ʍs��Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsIdentity(const Matrix4X4& m) {
			return XMMatrixIsIdentity(XMMATRIX(m));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s��̂����ꂩ�̗v�f�����܂��͕��̖����傩�ǂ��������؂���
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	���܂��͕��̖�����Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsInfinite(const Matrix4X4& m) {
			return XMMatrixIsInfinite(XMMATRIX(m));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s��̂����ꂩ�̗v�f��NaN���ǂ��������؂���
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	NaN�Ȃ�true
		*/
		//--------------------------------------------------------------------------------------
		inline  bool IsNaN(const Matrix4X4& m) {
			return XMMatrixIsNaN(XMMATRIX(m));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������W�r���[�s����쐬����
		@param[in]	Eye	�J�����ʒu
		@param[in]	At	�J�������_
		@param[in]	Up	�J�����X���i�ʏ�<0,1,0>�j
		@return	������W�r���[�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 LookAtLH(const Vector3& Eye, const Vector3& At, const Vector3& Up) {
			return (Matrix4X4)XMMatrixLookAtLH(
				XMVECTOR(Eye),
				XMVECTOR(At),
				XMVECTOR(Up));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�E����W�r���[�s����쐬����
		@param[in]	Eye	�J�����ʒu
		@param[in]	At	�J�������_
		@param[in]	Up	�J�����X���i�ʏ�<0,1,0>�j
		@return	�E����W�r���[�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 LookAtRH(const Vector3& Eye, const Vector3& At, const Vector3& Up) {
			return (Matrix4X4)XMMatrixLookAtRH(
				XMVECTOR(Eye),
				XMVECTOR(At),
				XMVECTOR(Up));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�����ʒu�A�����A�X�����獶����W�r���[�s����쐬����
		@param[in]	Eye	�J�����ʒu
		@param[in]	EyeDirection	�J��������
		@param[in]	Up	�J�����X���i�ʏ�<0,1,0>�j
		@return	������W�r���[�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 LookToLH(const Vector3& Eye, const Vector3& EyeDirection, const Vector3& Up) {
			return (Matrix4X4)XMMatrixLookToLH(
				XMVECTOR(Eye),
				XMVECTOR(EyeDirection),
				XMVECTOR(Up));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�����ʒu�A�����A�X������E����W�r���[�s����쐬����
		@param[in]	Eye	�J�����ʒu
		@param[in]	EyeDirection	�J��������
		@param[in]	Up	�J�����X���i�ʏ�<0,1,0>�j
		@return	�E����W�r���[�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 LookToRH(const Vector3& Eye, const Vector3& EyeDirection, const Vector3& Up) {
			return (Matrix4X4)XMMatrixLookToRH(
				XMVECTOR(Eye),
				XMVECTOR(EyeDirection),
				XMVECTOR(Up));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s��̐ς�Ԃ�
		@param[in]	m1	�v�Z���ƂȂ�s��
		@param[in]	m2	���Z��ɂȂ�s��
		@return	�ς̌��ʍs��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Multiply(const Matrix4X4& m1, const Matrix4X4& m2) {
			return  (Matrix4X4)XMMatrixMultiply(XMMATRIX(m1), XMMATRIX(m2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�ς̓]�u�s���Ԃ�
		@param[in]	m1	�v�Z���ƂȂ�s��
		@param[in]	m2	���Z��ɂȂ�s��
		@return	�ς̓]�u�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 MultiplyTranspose(const Matrix4X4& m1, const Matrix4X4& m2) {
			return  (Matrix4X4)XMMatrixMultiplyTranspose(XMMATRIX(m1), XMMATRIX(m2));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������W�n�̐��ˉe�s���Ԃ�
		@param[in]	ViewWidth	��
		@param[in]	ViewHeight	����
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	������W�n�̐��ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 OrthographicLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixOrthographicLH(ViewWidth, ViewHeight, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�E����W�n�̐��ˉe�s���Ԃ�
		@param[in]	ViewWidth	��
		@param[in]	ViewHeight	����
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�E����W�n�̐��ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 OrthographicRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixOrthographicRH(ViewWidth, ViewHeight, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������W�n�̃J�X�^�����ˉe�s���Ԃ�
		@param[in]	ViewLeft	��
		@param[in]	ViewRight	�E
		@param[in]	ViewBottom	��
		@param[in]	ViewTop	��
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	������W�n�̃J�X�^�����ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 OrthographicOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixOrthographicOffCenterLH(
				ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�E����W�n�̃J�X�^�����ˉe�s���Ԃ�
		@param[in]	ViewLeft	��
		@param[in]	ViewRight	�E
		@param[in]	ViewBottom	��
		@param[in]	ViewTop	��
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�E����W�n�̃J�X�^�����ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 OrthographicOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixOrthographicOffCenterRH(
				ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	����Ɋ�Â��āA������W�n�̃p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	FovAngleY	�g�b�v�_�E������p�x
		@param[in]	AspectHByW	�r���[��Ԃ̍����ƕ��̃A�X�y�N�g��
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	������W�n�̃p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveFovLH(float FovAngleY, float AspectHByW, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveFovLH(FovAngleY, AspectHByW, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	����Ɋ�Â��āA�E����W�n�̃p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	FovAngleY	�g�b�v�_�E������p�x
		@param[in]	AspectHByW	�r���[��Ԃ̍����ƕ��̃A�X�y�N�g��
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�E����W�n�̃p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveFovRH(float FovAngleY, float AspectHByW, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveFovRH(FovAngleY, AspectHByW, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	������W�n�̃p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	ViewWidth	�߂��̃N���b�v�ʂ̎�����̕�
		@param[in]	ViewHeight	�߂��̃N���b�v�ʂ̎�����̍���
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	������W�n�̃p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveLH(ViewWidth, ViewHeight, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�E����W�n�̃p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	ViewWidth	�߂��̃N���b�v�ʂ̎�����̕�
		@param[in]	ViewHeight	�߂��̃N���b�v�ʂ̎�����̍���
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�E����W�n�̃p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveRH(ViewWidth, ViewHeight, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�X�^�� �o�[�W�����̍�����W�n�p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	ViewLeft	�N���b�v������̍�����x���W
		@param[in]	ViewRight	�N���b�v������̉E����x���W
		@param[in]	ViewBottom	�N���b�v������̉�����y���W
		@param[in]	ViewTop	�N���b�v������̏㑤��y���W
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�J�X�^�� �o�[�W�����̍�����W�n�p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop,
			float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveOffCenterLH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�J�X�^�� �o�[�W�����̉E����W�n�p�[�X�y�N�e�B�u�ˉe�s���Ԃ�
		@param[in]	ViewLeft	�N���b�v������̍�����x���W
		@param[in]	ViewRight	�N���b�v������̉E����x���W
		@param[in]	ViewBottom	�N���b�v������̉�����y���W
		@param[in]	ViewTop	�N���b�v������̏㑤��y���W
		@param[in]	NearZ	���s��O
		@param[in]	FarZ	���s��
		@return	�J�X�^�� �o�[�W�����̉E����W�n�p�[�X�y�N�e�B�u�ˉe�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 PerspectiveOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop,
			float NearZ, float FarZ) {
			return  (Matrix4X4)XMMatrixPerspectiveOffCenterRH(ViewLeft, ViewRight, ViewBottom, ViewTop, NearZ, FarZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肳�ꂽ���ʂ���ăx�N�g���𔽉f����g�����X�t�H�[���s����쐬���Ԃ�
		@param[in]	Pln	����
		@return	�x�N�g���𔽉f����g�����X�t�H�[���s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Reflect(const Plane& Pln) {
			return  (Matrix4X4)XMMatrixReflect(XMVECTOR(Pln));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C�ӂ̎�����]���ɂ��āA��]�����s����쐬���Ԃ�
		@param[in]	Axis	��]����\���x�N�g��
		@param[in]	Angle	��]�p�x�i���W�A���j
		@return	�C�ӂ̎�����]���ɂ��āA��]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationAxis(const Vector3& Axis, float Angle) {
			return  (Matrix4X4)XMMatrixRotationAxis(XMVECTOR(Axis), Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�C�ӂ̖@���x�N�g������]���ɂ��āA��]�����s����쐬���Ԃ�
		@param[in]	NormalAxis	��]�����L�q����@���x�N�g��
		@param[in]	Angle	��]�p�x�i���W�A���j
		@return	�C�ӂ̖@���x�N�g������]���ɂ��āA��]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationNormal(const Vector3& NormalAxis, float Angle) {
			return  (Matrix4X4)XMMatrixRotationNormal(XMVECTOR(NormalAxis), Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�N�I�[�^�j�I�������]�s����쐬���Ԃ�
		@param[in]	Qt	��]���L�q����N�I�[�^�j�I��
		@return	�N�I�[�^�j�I������쐬������]�s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationQuaternion(const Quaternion& Qt) {
			return  (Matrix4X4)XMMatrixRotationQuaternion(XMVECTOR(Qt));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I�C���[�p�Ɋ�Â��ĉ�]�s����쐬����B��]��RollPitchYaw�iZ�AX�AY�j�̏��ōs����
		@param[in]	Pitch	X����]
		@param[in]	Yaw		Y����]
		@param[in]	Roll	Z����]
		@return	�I�C���[�p�Ɋ�Â��ĉ�]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationRollPitchYaw(float Pitch, float Yaw, float Roll) {
			return  (Matrix4X4)XMMatrixRotationRollPitchYaw(Pitch, Yaw, Roll);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�I�C���[�p(�x�N�g��)�Ɋ�Â��ĉ�]�s����쐬����B��]��RollPitchYaw�iZ�AX�AY�j�̏��ōs����
		@param[in]	Angles	��]���L�q����x�N�g��
		@return	�I�C���[�p(�x�N�g��)�Ɋ�Â��ĉ�]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationRollPitchYawFromVector(const Vector3& Angles) {
			return  (Matrix4X4)XMMatrixRotationRollPitchYawFromVector(XMVECTOR(Angles));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	X����]�Ɋ�Â��ĉ�]�s����쐬����
		@param[in]	Angle	X����]
		@return	X����]�Ɋ�Â��ĉ�]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationX(float Angle) {
			return  (Matrix4X4)XMMatrixRotationX(Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Y����]�Ɋ�Â��ĉ�]�s����쐬����
		@param[in]	Angle	Y����]
		@return	Y����]�Ɋ�Â��ĉ�]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationY(float Angle) {
			return  (Matrix4X4)XMMatrixRotationY(Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	Z����]�Ɋ�Â��ĉ�]�s����쐬����
		@param[in]	Angle	Z����]
		@return	Z����]�Ɋ�Â��ĉ�]�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 RotationZ(float Angle) {
			return  (Matrix4X4)XMMatrixRotationZ(Angle);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	x���Ay���A�����z���ɉ����ăX�P�[�����O�����s����쐬����
		@param[in]	ScaleX	X�ɉ������X�P�[�����O
		@param[in]	ScaleY	Y�ɉ������X�P�[�����O
		@param[in]	ScaleZ	Z�ɉ������X�P�[�����O
		@return	x���Ay���A�����z���ɉ����ăX�P�[�����O�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Scaling(float ScaleX, float ScaleY, float ScaleZ) {
			return  (Matrix4X4)XMMatrixScaling(ScaleX, ScaleY, ScaleZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g���ɉ����ăX�P�[�����O�����s����쐬����
		@param[in]	Scale	�X�P�[�����O���L�q����x�N�g��
		@return	�x�N�g���ɉ����ăX�P�[�����O�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 ScalingFromVector(const Vector3& Scale) {
			return  (Matrix4X4)XMMatrixScalingFromVector(XMVECTOR(Scale));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�l��ݒ肵���s����쐬����
		@param[in]	m00	�ݒ茳00
		@param[in]	m01	�ݒ茳01
		@param[in]	m02	�ݒ茳02
		@param[in]	m03	�ݒ茳03
		@param[in]	m10	�ݒ茳10
		@param[in]	m11	�ݒ茳11
		@param[in]	m12	�ݒ茳12
		@param[in]	m13	�ݒ茳13
		@param[in]	m20	�ݒ茳20
		@param[in]	m21	�ݒ茳21
		@param[in]	m22	�ݒ茳22
		@param[in]	m23	�ݒ茳23
		@param[in]	m30	�ݒ茳30
		@param[in]	m31	�ݒ茳31
		@param[in]	m32	�ݒ茳32
		@param[in]	m33	�ݒ茳33
		@return	�e�l��ݒ肵���s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Set(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33
			) {
			return  (Matrix4X4)XMMatrixSet(
				m00, m01, m02, m03,
				m10, m11, m12, m13,
				m20, m21, m22, m23,
				m30, m31, m32, m33
				);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�W�I���g���𕽖ʂɎˉe����g�����X�t�H�[���s����쐬����B<br />
		���C�g��w�v�f�́A0.0�Ńf�B���N�V���i�����C�g�A1.0�Ń|�C���g���C�g�ƂȂ�
		@param[in]	ShadowPlane	���
		@param[in]	LightPosition	���C�g�̈ʒu
		@return	�W�I���g���𕽖ʂɎˉe����g�����X�t�H�[���s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Shadow(const Plane& ShadowPlane, const Vector4& LightPosition) {
			return  (Matrix4X4)XMMatrixShadow(XMVECTOR(ShadowPlane), XMVECTOR(LightPosition));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�g�����X�t�H�[���s����쐬����B
		@param[in]	ScalingOrigin	�X�P�[�����O�̒��S���L�q����3D�x�N�g��
		@param[in]	ScalingOrientationQuaternion	�X�P�[�����O�̌������L�q����N�I�[�^�j�I��
		@param[in]	Scaling		x���Ay���Az���̃X�P�[�����O�W�����܂�3D�x�N�g��
		@param[in]	RotationOrigin	��]�̒��S���L�q����3D�x�N�g��
		@param[in]	RotationQuaternion	RotationOrigin�ɂ���Ď�����錴�_�𒆐S�Ƃ����]���L�q����N�I�[�^�j�I��
		@param[in]	Translation		x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@return	�g�����X�t�H�[���s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Transformation(const Vector3& ScalingOrigin, const Quaternion& ScalingOrientationQuaternion, const Vector3& Scaling,
			const Vector3& RotationOrigin, const Quaternion& RotationQuaternion,
			const Vector3& Translation) {
			return  (Matrix4X4)XMMatrixTransformation(
				XMVECTOR(ScalingOrigin), XMVECTOR(ScalingOrientationQuaternion), XMVECTOR(Scaling),
				XMVECTOR(RotationOrigin), XMVECTOR(RotationQuaternion),
				XMVECTOR(Translation)
				);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	2D�g�����X�t�H�[���s���xy���ʂɍ쐬����B
		@param[in]	ScalingOrigin	�X�P�[�����O�̒��S���L�q����2D�x�N�g��
		@param[in]	ScalingOrientation	�X�P�[�����O��]�W��
		@param[in]	Scaling		x���Ay���̃X�P�[�����O�W�����܂�2D�x�N�g��
		@param[in]	RotationOrigin	��]�̒��S���L�q����2D�x�N�g��
		@param[in]	Rotation	��]�̊p�x (���W�A���P��)
		@param[in]	Translation		���s�ړ����L�q����2D�x�N�g��
		@return	xy���ʂ�2D�g�����X�t�H�[���s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Transformation2D(const Vector2& ScalingOrigin, float ScalingOrientation, const Vector2& Scaling,
			const Vector2& RotationOrigin, float Rotation,
			const Vector2& Translation) {
			return  (Matrix4X4)XMMatrixTransformation2D(XMVECTOR(ScalingOrigin), ScalingOrientation, XMVECTOR(Scaling),
				XMVECTOR(RotationOrigin), Rotation, XMVECTOR(Translation));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�肳�ꂽ�I�t�Z�b�g���畽�s�ړ��s����쐬����
		@param[in]	OffsetX	X���ɉ��������s�ړ�
		@param[in]	OffsetY	Y���ɉ��������s�ړ�
		@param[in]	OffsetZ	Z���ɉ��������s�ړ�
		@return	�w�肳�ꂽ�I�t�Z�b�g�ŕ��s�ړ������s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Translation(float OffsetX, float OffsetY, float OffsetZ) {
			return  (Matrix4X4)XMMatrixTranslation(OffsetX, OffsetY, OffsetZ);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�x�N�g�����畽�s�ړ��s����쐬����
		@param[in]	Offset	x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@return	�x�N�g�����畽�s�ړ������s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 TranslationFromVector(const Vector3& Offset) {
			return  (Matrix4X4)XMMatrixTranslationFromVector(XMVECTOR(Offset));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�s���]�u����
		@param[in]	m	�v�Z���ƂȂ�s��
		@return	�]�u�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 Transpose(const Matrix4X4& m) {
			return  (Matrix4X4)XMMatrixTranspose(XMMATRIX(m));
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�P�[�����O�A��]�A�ړ�����s����쐬����<br />
		��]�ʒu�𒆐S�ɒu�����A�t�B���ϊ��ł���B
		@param[in]	Scaling	x���Ay���Az���̃X�P�[�����O�W�����܂�3D�x�N�g��
		@param[in]	RotationQt	��]���L�q����N�I�[�^�j�I��
		@param[in]	Translation	x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 DefTransformation(const Vector3& Scaling, const Quaternion& RotationQt, const Vector3& Translation) {
			return AffineTransformation(Scaling, Vector3(0, 0, 0), RotationQt, Translation);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�P�[�����O�A��]�x�N�g���A�ړ�����s����쐬����<br />
		��]�ʒu�𒆐S�ɒu�����A�t�B���ϊ��ł���B
		@param[in]	Scaling	x���Ay���Az���̃X�P�[�����O�W�����܂�3D�x�N�g��
		@param[in]	Rotation	��]���L�q����x�N�g��
		@param[in]	Translation	x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 DefTransformation(const Vector3& Scaling, const Vector3& Rotation, const Vector3& Translation) {
			Quaternion Qt;
			Qt.RotationRollPitchYawFromVector(Rotation);
			Qt.Normalize();
			return AffineTransformation(Scaling, Vector3(0, 0, 0), Qt, Translation);
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�P�[�����O�A�ړ��A��]����s����쐬����B��]���ړ����ɍs���B
		@param[in]	Scaling	x���Ay���Az���̃X�P�[�����O�W�����܂�3D�x�N�g��
		@param[in]	Translation	x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@param[in]	RotationQt	��]���L�q����N�I�[�^�j�I��
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 STRTransformation(const Vector3& Scaling, const Vector3& Translation, const Quaternion& RotationQt) {
			Matrix4X4 Scale = ScalingFromVector(Scaling);
			Matrix4X4 Trans = TranslationFromVector(Translation);
			Matrix4X4 Qt = RotationQuaternion(RotationQt);
			Matrix4X4 ret = Scale * Trans * Qt;
			return  ret;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�X�P�[�����O�A�ړ��A��]�x�N�g������s����쐬����B��]���ړ����ɍs���B
		@param[in]	Scaling	x���Ay���Az���̃X�P�[�����O�W�����܂�3D�x�N�g��
		@param[in]	Translation	x���Ay���Az���ɉ��������s�ړ����L�q����3D�x�N�g��
		@param[in]	Rotation	��]���L�q����x�N�g��
		@return	�쐬�����s��
		*/
		//--------------------------------------------------------------------------------------
		inline  Matrix4X4 STRTransformation(const Vector3& Scaling, const Vector3& Translation, const Vector3& Rotation) {
			Matrix4X4 Scale = ScalingFromVector(Scaling);
			Matrix4X4 Trans = TranslationFromVector(Translation);
			Matrix4X4 Rot = RotationRollPitchYawFromVector(Rotation);
			Matrix4X4 ret = Scale * Trans * Rot;
			return  ret;
		}
	};
	//end Matrix4X4EX


}
//end of namespace basecross.

