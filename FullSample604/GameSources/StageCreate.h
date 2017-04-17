#pragma once
#include"stdafx.h"

namespace basecross 
{
	enum Pivot //位置の中心
	{
		LeftUp, LeftDown, Center, RightUp, RightDown
	};

	//--------------------------------------------------------------------------------------
	//	class StageCreate
	//	用途: Csvでステージ制作
	//--------------------------------------------------------------------------------------
	class StageCreate
	{
	private:
		shared_ptr<GameStage> m_Stage;
		wstring m_FileName;

		float m_RowPos;		//行の位置
		float m_ColPos;		//列の位置
		float m_VInterval;	//縦の間隔
		float m_HInterval;	//横の間隔

		Pivot m_Pivot;
		bool m_isFinish;//全て作り終えたかの処理

	public:
		//縦と横の間隔をずらしたい場合に使うコンストラクタ
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

		//ステージの作成関数
		void OnCreate();

		//ステージの中心点をずらす関数
		//Row
		void ShiftPivotRow(int RowNum, Pivot piv);
		//Column
		void ShiftPivotColumn(int ColNum, Pivot piv);

		//オブジェクトを選ぶ関数
		void SelectObject(int);

		//アクセサ
		wstring GetFileName() { return m_FileName; }
		bool GetIsFinish() { return m_isFinish; }
	};
}
