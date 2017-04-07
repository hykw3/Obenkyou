#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//Impl
	struct MyCamera::Impl {
		weak_ptr<GameObject> m_TargetObject;	//目標となるオブジェクト
		float m_ToTargetLerp;	//目標を追いかける際の補間値


		float m_RadY;
		float m_RadXZ;
		//カメラの上下スピード
		float m_CameraUpDownSpeed;
		//カメラを下げる下限角度
		float m_CameraUnderRot;
		float	m_Arm;
		//腕の長さの設定
		float m_MaxArm;
		float m_MinArm;
		//回転スピード
		float m_RotSpeed;
		//ズームスピード
		float m_ZoomSpeed;

		Impl() :
			m_ToTargetLerp(1.0f),
			m_RadY(0.0f),
			m_RadXZ(0),
			m_CameraUpDownSpeed(0.0f),
			m_CameraUnderRot(0.0f),
			m_Arm(5.0f),
			m_MaxArm(20.0f),
			m_MinArm(2.0f),
			m_RotSpeed(1.0f),
			m_ZoomSpeed(0.1f)
		{}
		~Impl() {}
	};


	//GameStage用のカメラ
	MyCamera::MyCamera() :
		Camera(),
		pImpl(new Impl())
	{
	}
	MyCamera::~MyCamera() {}
	//アクセサ
	shared_ptr<GameObject> MyCamera::GetTargetObject() const {
		if (!pImpl->m_TargetObject.expired()) {
			return pImpl->m_TargetObject.lock();
		}
		return nullptr;
	}

	void MyCamera::SetTargetObject(const shared_ptr<GameObject>& Obj) {
		pImpl->m_TargetObject = Obj;
	}

	float MyCamera::GetToTargetLerp() const {
		return pImpl->m_ToTargetLerp;
	}
	void MyCamera::SetToTargetLerp(float f) {
		pImpl->m_ToTargetLerp = f;
	}

	void MyCamera::OnUpdate() {
		//Sceneの取得
		auto ScenePtr = App::GetApp()->GetScene<Scene>();

		auto CntlVec = App::GetApp()->GetInputDevice().GetControlerVec();
		//前回のターンからの時間
		float ElapsedTime = App::GetApp()->GetElapsedTime();
		Vector3 NewEye = GetEye();
		Vector3 NewAt = GetAt();
		//計算に使うための腕角度（ベクトル）
		Vector3 ArmVec = NewEye - NewAt;
		//正規化しておく
		ArmVec.Normalize();
		//if (CntlVec[0].bConnected) {

		//クオータニオンでY回転（つまりXZベクトルの値）を計算
		Quaternion QtXZ;
		QtXZ.RotationAxis(Vector3(0, 0.0f, 0), pImpl->m_RadXZ);
		QtXZ.Normalize();
		//移動先行の行列計算することで、XZの値を算出
		Matrix4X4 Mat;
		Mat.STRTransformation(
			Vector3(1.0f, 1.0f, 1.0f),
			Vector3(0.0f, 0.0f, -1.0f),
			QtXZ
		);

		Vector3 PosXZ = Mat.PosInMatrixSt();
		//XZの値がわかったので腕角度に代入
		ArmVec.x = PosXZ.x;
		ArmVec.z = PosXZ.z;
		//腕角度を正規化
		ArmVec.Normalize();

		auto TargetPtr = GetTargetObject();
		if (TargetPtr) {
			//目指したい場所
			Matrix4X4 ToAtMat = TargetPtr->GetComponent<Transform>()->GetWorldMatrix();
			Vector3 ToAt = ToAtMat.PosInMatrixSt();
			NewAt = Lerp::CalculateLerp(GetAt(), ToAt, 0, 1.0f, 2.0f, Lerp::Linear);
		}

		////目指したい場所にアームの値と腕ベクトルでEyeを調整
		/*NewEye = NewAt + ArmVec * pImpl->m_Arm;

		SetEye(NewEye.x + 4.0f, NewEye.y + 2.0f, NewEye.z - 5.0f);
		SetAt(NewAt.x + 4.0f, NewAt.y + 2.0f, NewAt.z);
		Camera::OnUpdate();*/

	}
}