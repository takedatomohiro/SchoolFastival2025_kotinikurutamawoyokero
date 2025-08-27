#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy()
{

	if (m_player == nullptr) return;

	Vector3 dir = m_player->position - m_position;
	dir.Normalize();
	float speed = 3.0f;
	m_position += dir * speed;

	
	/*m_characterController.Init(25.0f, 75.0f, m_position);*/
}

Enemy::~Enemy()
{
	
}

bool Enemy::Start()
{
	m_modelRender.Init("Assets/modelData/ATK.tkm");
	m_modelRender.SetPosition(0.0f, 0.0f, 0.0f);
	m_modelRender.SetScale(5.5f, 5.0f, 5.5f);//サイズ変更（ｘ、ｙ、ｚ）
	m_modelRender.Update();
	return true;
}

void Enemy::Update()
{
	
	//移動処理
	Move();
	
	//絵描きさんの更新処理
	m_modelRender.Update();

	//回転処理
	Rotation();		

	
}
void Enemy::Move()
{	
	//毎フレーム時間加算
	m_moveTimer += GameTime().GetFrameDeltaTime();

	// //3秒経過でプレイヤーに向かって移動
	if (m_moveTimer >= 0.0f && m_player != nullptr)
	{
		// 方向ベクトル計算
		Vector3 dir = m_player->position - m_position;
		dir.Normalize();

		float speed = 4.0f;  // ← プレイヤーに向かってどれだけ進むか
		m_position += dir * speed;

		m_moveTimer = 0.0f; // タイマーリセット

		Vector3 diff = m_player->position - m_position;
	}
	m_modelRender.SetPosition(m_position);

	/*m_position = m_characterController.Execute(moveSpeed, 1.0f / 60.0f);*/
}

void Enemy::Rotation()
{
	//回転を加算する
	rotation.AddRotationDegY(20.0f);

	//絵描きさんに回転を教える。
	m_modelRender.SetRotation(rotation);
}

void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}



