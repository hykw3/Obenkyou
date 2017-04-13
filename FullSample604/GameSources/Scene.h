/*!
@file Scene.h
@brief シーン
*/
#pragma once

#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	ゲームシーン
	//--------------------------------------------------------------------------------------
	class Scene : public SceneBase {
		//--------------------------------------------------------------------------------------
		/*!
		@brief リソースの作成
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		void CreateResourses();
		///ステージナンバー
		int m_StageNum;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief コンストラクタ
		*/
		//--------------------------------------------------------------------------------------
		Scene() :SceneBase(),m_StageNum(1){}
		//--------------------------------------------------------------------------------------
		/*!
		@brief デストラクタ
		*/
		//--------------------------------------------------------------------------------------
		virtual ~Scene() {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	ステージナンバーを得る
		@return	ステージナンバー
		*/
		//--------------------------------------------------------------------------------------
		int GetStageNum() const {
			return m_StageNum;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief	ステージナンバーを設定する
		@param[in]	i	ステージナンバー
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		void GetStageNum(int i){
			m_StageNum = i;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief 初期化
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief イベント取得
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnEvent(const shared_ptr<Event>& event) override;
	};

}

//end basecross
