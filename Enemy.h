#pragma once
#include <Game.h>
class player;

class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start() override;
	//更新処理
	void Update() override;
	//描画距離。
	void Render(RenderContext& rc) override;

	const Vector3& GetPosition() const{
		return m_position;
	}
	void SetPosition(const Vector3& pos) {	
		m_position = pos;
	}
	void SetPlayer(Player* player) { m_player = player; }
	
private:
	//移動処理
	void Move();
	//回転処理
	void Rotation();
private:
	//こっからメンバ変数
	ModelRender m_modelRender;//モデルレンダー。
	Vector3 m_position = Vector3::Zero;//座標。
	Quaternion rotation;
	Player* m_player = nullptr; // プレイヤーへのポインタ
	float m_moveTimer = 0.0f;       // 経過時間
	float m_speed = 3.0f;       // 移動速度
	Player* player;
	Vector3 moveSpeed; //移動速度。
	//CharacterController m_characterController;  //キャラクターコントローラー。
};