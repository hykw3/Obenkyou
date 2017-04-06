/*!
@file Character.cpp
@brief キャラクターなど実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{

	//コンストラクタは関数の外に書く！！！！！！！！！
	MultiSpark::MultiSpark(shared_ptr<Stage>& StagePtr):MultiParticle(StagePtr)
	{}
	MultiSpark::~MultiSpark() {}

	//初期化
	void MultiSpark::OnCreate() {
	}


	void MultiSpark::InsertSpark(const Vector3& Pos ) {	
		
		auto ParticlePtr = InsertParticle(4);
		ParticlePtr->SetEmitterPos(Pos);
		ParticlePtr->SetTextureResource(L"SPARK_TX");
		ParticlePtr->SetMaxTime(0.5f);
		vector<ParticleSprite>& pspriteVec = ParticlePtr->GetParticleSpriteVec();
		for (auto& rParticleSprite : ParticlePtr->GetParticleSpriteVec()) {
			rParticleSprite.m_LocalPos.x = Util::RandZeroToOne() * 0.1f-0.05f;
			rParticleSprite.m_LocalPos.y = Util::RandZeroToOne() * 0.1f;
			rParticleSprite.m_LocalPos.z = Util::RandZeroToOne() * 0.1f - 0.05f;
			//各パーティクルの移動速度を指定
			rParticleSprite.m_Velocity = Vector3(
				rParticleSprite.m_LocalPos.x * 5.0f,
				rParticleSprite.m_LocalPos.y * 5.0f,
				rParticleSprite.m_LocalPos.z * 5.0f
			);
			//色の指定
			rParticleSprite.m_Color = Color4(1.0f, 1.0f, 1.0f, 1.0f);
		
		}
	}
	//--------------------------------------------------------------------------------------
	///	壁模様のスプライト
	//--------------------------------------------------------------------------------------
	WallSprite::WallSprite(const shared_ptr<Stage>& StagePtr,
		const wstring& TextureKey,
		bool Trace,
		const Vector2& StartScale,
		const Vector2& StartPos):

		GameObject(StagePtr),
		m_TextureKey(TextureKey),
		m_Trace(Trace),
		m_StartScale(StartScale),
		m_StartPos(StartPos)
	{}

	WallSprite::~WallSprite() {}
	void WallSprite::OnCreate() {
		float HelfSize = 0.5f;
		//頂点配列(縦横5個ずつ表示)
		vector<VertexPositionColorTexture> vertices = {
			{ VertexPositionColorTexture(Vector3(-HelfSize, HelfSize, 0),Color4(1.0f,1.0f,1.0f,1.0f), Vector2(0.0f, 0.0f)) },
			{ VertexPositionColorTexture(Vector3(HelfSize, HelfSize, 0), Color4(1.0f, 1.0f, 1.0f, 1.0f), Vector2(1.0f, 0.0f)) },
			{ VertexPositionColorTexture(Vector3(-HelfSize, -HelfSize, 0), Color4(1.0f, 1.0f, 1.0f, 1.0f), Vector2(0.0f, 1.0f)) },
			{ VertexPositionColorTexture(Vector3(HelfSize, -HelfSize, 0), Color4(1.0f, 1.0f, 1.0f, 1.0f), Vector2(1.0f, 1.0f)) },
		};

		//インデックス配列
		vector<uint16_t> indices = { 0, 1, 2, 1, 3, 2 };
		SetAlphaActive(m_Trace);
		auto PtrTransform = GetComponent<Transform>();
		PtrTransform->SetScale(m_StartScale.x, m_StartScale.y, 1.0f);
		PtrTransform->SetRotation(0, 0, 0);
		PtrTransform->SetPosition(m_StartPos.x, m_StartPos.y, 0.0f);
		//頂点とインデックスを指定してスプライト作成
		auto PtrDraw = AddComponent<PCTSpriteDraw>(vertices, indices);
		PtrDraw->SetWrapSampler(true);
		PtrDraw->SetTextureResource(m_TextureKey);

		auto PtrAction = AddComponent<Action>();
		PtrAction->AddRotateBy(1.0f, Vector3(0, 0, XM_PI* -1));
	
		PtrAction->AddRotateInterval(1.0f);
		PtrAction->AddMoveTo(1.0f, Vector3(-440.0f, -200.0f, 1.0f));
		PtrAction->AddMoveTo(1.0f, Vector3(440.0f, -200.0f, 1.0f));
		PtrAction->SetLooped(true);
		PtrAction->Run();

	}
	void WallSprite::OnUpdate() {
		auto size = GetComponent<Transform>();

	}

	//--------------------------------------------------------------------------------------
	//	class FixedBox : public GameObject;
	//	用途: 固定のボックス
	//--------------------------------------------------------------------------------------
	//構築と破棄
	FixedBox::FixedBox(const shared_ptr<Stage>& StagePtr,
		const Vector3& Scale,
		const Vector3& Rotation,
		const Vector3& Position
	) :
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Rotation(Rotation),
		m_Position(Position)
	{
	}
	FixedBox::~FixedBox() {}

	//初期化
	void FixedBox::OnCreate() {
		auto PtrTransform = GetComponent<Transform>();

		PtrTransform->SetScale(m_Scale);
		PtrTransform->SetRotation(m_Rotation);
		PtrTransform->SetPosition(m_Position);

		//衝突判定
		auto PtrObb = AddComponent<CollisionObb>();
		PtrObb->SetFixed(true);

		//影をつける
		auto ShadowPtr = AddComponent<Shadowmap>();
		ShadowPtr->SetMeshResource(L"DEFAULT_CUBE");

		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		PtrDraw->SetFogEnabled(true);

		auto PtrAction = AddComponent<Action>();

		PtrAction->AddRotateBy(1.0f, Vector3(XM_PI/2, XM_PI, 0));
		PtrAction->AddScaleBy(0.5f, Vector3(2, 2, 2));
		PtrAction->AddScaleBy(0.5f, Vector3(0.5f, 0.5f, 0.5f));
		
		PtrAction->SetLooped(true);
		PtrAction->Run();

		PtrDraw->SetMeshResource(L"DEFAULT_CUBE");
		PtrDraw->SetOwnShadowActive(true);
		PtrDraw->SetTextureResource(L"SKY_TX");
	}

}
//end basecross
