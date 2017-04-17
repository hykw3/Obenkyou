#include"stdafx.h"
#include"Project.h"
#include "StageCreate.h"

namespace basecross 
{
	//--------------------------------------------------------------------------------------
	//	class StageCreate
	//	�p�r: Csv�ŃX�e�[�W����
	//--------------------------------------------------------------------------------------

	StageCreate::StageCreate(const shared_ptr<GameStage>& StagePtr, const wstring & FileName, const Pivot & pivot):
		m_Stage(StagePtr),
		m_FileName(FileName),
		m_Pivot(pivot),
		m_isFinish(false),
		m_VInterval(1.0f),//��{��1.0f�̊Ԋu
		m_HInterval(1.0f)
	{}
	StageCreate::StageCreate(const shared_ptr<GameStage>& StagePtr, const wstring & FileName, const Pivot & pivot, const float & VerticalInterval, const float & HorizontalInterval):
		m_VInterval(VerticalInterval),
		m_HInterval(HorizontalInterval)
	{
		StageCreate(StagePtr, FileName, pivot);
	}

	StageCreate::~StageCreate(){}

	void StageCreate::OnCreate()
	{
		//Csv�̃R���X�g���N�^
		CsvFile StageCsv(m_FileName);

		//Csv�t�@�C���̎擾
		if (!StageCsv.ReadCsv())
		{
			throw BaseException(
				L"if(!StageCsv.ReadCsv())",
				L"CSV�t�@�C����",
				L"�ǂݍ��݃~�X"
			);
		}

		//Csv�t�@�C���̍s���擾
		const int RowNum = StageCsv.GetRowCount();
		//Pos
		m_RowPos = 0;

		ShiftPivotRow(RowNum, m_Pivot);
		
		for (int i = 0; i < RowNum; i++)
		{
			//1�s���̋�؂�ꂽ�������擾���邽�߂̕ϐ�
			vector<wstring> RowStr;
			StageCsv.GetRowVec(i, RowStr);
			//�񐔎擾
			int ColNum = RowStr.size();
			m_ColPos = 0;
			ShiftPivotColumn(ColNum, m_Pivot);

			for (int j = 0; j < ColNum; j++)
			{
				//�I�u�W�F�N�g�I��Ő���
				SelectObject(stoi(RowStr[j]));

				//��̕��𑝂₷
				m_ColPos += m_HInterval;
			}

			//�s�̕��𑝂₷
			m_RowPos -= m_VInterval;
		}
		m_isFinish = true;	//�I��
	}

	//�X�e�[�W�̒��S�_�����炷�֐�

	//Row
	void StageCreate::ShiftPivotRow(int RowNum, Pivot piv)
	{
		switch (piv)
		{
		case Pivot::LeftUp:
			m_RowPos = 0; //�����ʒu�炵��
			break;

		case Pivot::LeftDown:
			m_RowPos = float(RowNum) - m_VInterval / 2;
			break;

		case Pivot::Center:
			m_RowPos = float(RowNum / 2); //���̔���
			break;

		case Pivot::RightUp:
			m_RowPos = 0;
			break;

		case Pivot::RightDown:
			m_RowPos = float(RowNum) - m_VInterval / 2;
			break;

		default:
			break;
		}
	}

	//Column
	void StageCreate::ShiftPivotColumn(int ColNum, Pivot piv)
	{
		switch (piv)
		{
		case Pivot::LeftUp:
			m_ColPos = 0;	//�����ʒu�炵��
			break;

		case Pivot::LeftDown:
			m_ColPos = 0;
			break;

		case Pivot::Center:
			m_ColPos = -float(ColNum / 2); //-���̔���
			break;

		case Pivot::RightUp:
			m_ColPos = -float(ColNum) + m_VInterval / 2;
			break;

		case Pivot::RightDown:
			m_ColPos = -float(ColNum) + m_VInterval / 2;
			break;

		default:
			break;
		}
	}

	//�I�u�W�F�N�g�I�Ԋ֐�
	void StageCreate::SelectObject(int num)
	{

		//�����ɂ���č����̂����߂�
		switch (num)
		{

			//�Œ�̃u���b�N
		case 1:
		{
			m_Stage->AddGameObject<TilingFixedBox>
				(
					Vector3(1.0f, 1.0f, 1.0f),
					Vector3(0.0f, 0.0f, 0.0f),
					Vector3(m_ColPos, m_RowPos, 0.0f)
				);
		}
		break;
		default:
			break;
		}
	}
}