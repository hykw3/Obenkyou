#pragma once
#include"stdafx.h"

namespace basecross 
{
	enum Pivot //�ʒu�̒��S
	{
		LeftUp, LeftDown, Center, RightUp, RightDown
	};

	//--------------------------------------------------------------------------------------
	//	class StageCreate
	//	�p�r: Csv�ŃX�e�[�W����
	//--------------------------------------------------------------------------------------
	class StageCreate
	{
	private:
		shared_ptr<GameStage> m_Stage;
		wstring m_FileName;

		float m_RowPos;		//�s�̈ʒu
		float m_ColPos;		//��̈ʒu
		float m_VInterval;	//�c�̊Ԋu
		float m_HInterval;	//���̊Ԋu

		Pivot m_Pivot;
		bool m_isFinish;//�S�č��I�������̏���

	public:
		//�c�Ɖ��̊Ԋu�����炵�����ꍇ�Ɏg���R���X�g���N�^
		StageCreate(
			const shared_ptr<GameStage>& StagePtr,
			const wstring& FileName,
			const Pivot& pivot);
		StageCreate(
			const shared_ptr<GameStage>& StagePtr,
			const wstring& FileName,
			const Pivot& pivot,
			const float& VerticalInterval,
			const float& HorizontalInterval);

		virtual ~StageCreate();

		//�X�e�[�W�̍쐬�֐�
		void OnCreate();

		//�X�e�[�W�̒��S�_�����炷�֐�
		//Row
		void ShiftPivotRow(int RowNum, Pivot piv);
		//Column
		void ShiftPivotColumn(int ColNum, Pivot piv);

		//�I�u�W�F�N�g��I�Ԋ֐�
		void SelectObject(int);

		//�A�N�Z�T
		wstring GetFileName() { return m_FileName; }
		bool GetIsFinish() { return m_isFinish; }
	};
}
