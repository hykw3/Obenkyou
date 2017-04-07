#pragma once


#include "stdafx.h"

namespace basecross {

	class MyCamera : public Camera {

	public:

		explicit MyCamera();

		virtual ~MyCamera();

		shared_ptr<GameObject> GetTargetObject() const;

		void SetTargetObject(const shared_ptr<GameObject>& Obj);

		float GetToTargetLerp() const;

		void SetToTargetLerp(float f);

		//アクセサ
		//shared_ptr< StateMachine<MyCamera> > GetStateMachine() const {
		//	return m_StateMachine;
		//}
		//virtual void OnCreate();
		virtual void OnUpdate();

		////SetEye変更用変数
		//float ChangeSetEyeX = 0.0f;
		//float ChangeSetEyeY = 0.0f;
		////そのためのセッター関数
		//void setChangeSetEyeX(float ChangeRange) {
		//	ChangeSetEyeX = ChangeRange;
		//}
		//void setChangeSetEyeY(float ChangeRange) {
		//	ChangeSetEyeY = ChangeRange;
		//}

	private:
		// pImplイディオム
		struct Impl;
		unique_ptr<Impl> pImpl;

	};

}