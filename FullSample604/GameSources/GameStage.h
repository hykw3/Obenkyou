/*!
@file GameStage.h
@brief �Q�[���X�e�[�W
*/

#pragma once
#include "stdafx.h"

namespace basecross {




	//--------------------------------------------------------------------------------------
	//	�Q�[���X�e�[�W�N���X
	//--------------------------------------------------------------------------------------
	class GameStage : public Stage {
		//�r���[�̍쐬
		void CreateViewLight();
		//�v���C���[�̍쐬
		void CreatePlayer();
		///�X�e�[�W�i���o�[
		int m_StageNum;
	public:
		//�\�z�Ɣj��
		GameStage(int StageNum) :Stage(),m_StageNum(StageNum){}
		virtual ~GameStage() {}
		//������
		virtual void OnCreate()override;
	};


}
//end basecross

