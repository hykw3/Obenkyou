#include"stdafx.h"
#include"Project.h"
#include "StageCreate.h"

namespace basecross 
{
	//--------------------------------------------------------------------------------------
	//	class StageCreate
	//	用途: Csvでステージ制作
	//--------------------------------------------------------------------------------------

	StageCreate::StageCreate(const shared_ptr<GameStage>& StagePtr, const wstring & FileName, const Pivot & pivot):
		m_Stage(StagePtr),
		m_FileName(FileName),
		m_Pivot(pivot),
		m_isFinish(false),
		m_VInterval(1.0f),//基本は1.0fの間隔
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
		//Csvのコンストラクタ
		CsvFile StageCsv(m_FileName);

		//Csvファイルの取得
		if (!StageCsv.ReadCsv())
		{
			throw BaseException(
				L"if(!StageCsv.ReadCsv())",
				L"CSVファイルの",
				L"読み込みミス"
			);
		}

		//Csvファイルの行数取得
		const int RowNum = StageCsv.GetRowCount();
		//Pos
		m_RowPos = 0;

		ShiftPivotRow(RowNum, m_Pivot);
		
		for (int i = 0; i < RowNum; i++)
		{
			//1行分の区切られた文字を取得するための変数
			vector<wstring> RowStr;
			StageCsv.GetRowVec(i, RowStr);
			//列数取得
			int ColNum = RowStr.size();
			m_ColPos = 0;
			ShiftPivotColumn(ColNum, m_Pivot);

			for (int j = 0; j < ColNum; j++)
			{
				//オブジェクト選んで生成
				SelectObject(stoi(RowStr[j]));

				//列の幅を増やす
				m_ColPos += m_HInterval;
			}

			//行の幅を増やす
			m_RowPos -= m_VInterval;
		}
		m_isFinish = true;	//終了
	}

	//ステージの中心点をずらす関数

	//Row
	void StageCreate::ShiftPivotRow(int RowNum, Pivot piv)
	{
		switch (piv)
		{
		case Pivot::LeftUp:
			m_RowPos = 0; //初期位置らしい
			break;

		case Pivot::LeftDown:
			m_RowPos = float(RowNum) - m_VInterval / 2;
			break;

		case Pivot::Center:
			m_RowPos = float(RowNum / 2); //数の半分
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
			m_ColPos = 0;	//初期位置らしい
			break;

		case Pivot::LeftDown:
			m_ColPos = 0;
			break;

		case Pivot::Center:
			m_ColPos = -float(ColNum / 2); //-数の半分
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

	//オブジェクト選ぶ関数
	void StageCreate::SelectObject(int num)
	{

		//数字によって作るものを決める
		switch (num)
		{

			//固定のブロック
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