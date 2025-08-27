#pragma once
#include <Game.h>
class player;

class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start() override;
	//�X�V����
	void Update() override;
	//�`�拗���B
	void Render(RenderContext& rc) override;

	const Vector3& GetPosition() const{
		return m_position;
	}
	void SetPosition(const Vector3& pos) {	
		m_position = pos;
	}
	void SetPlayer(Player* player) { m_player = player; }
	
private:
	//�ړ�����
	void Move();
	//��]����
	void Rotation();
private:
	//�������烁���o�ϐ�
	ModelRender m_modelRender;//���f�������_�[�B
	Vector3 m_position = Vector3::Zero;//���W�B
	Quaternion rotation;
	Player* m_player = nullptr; // �v���C���[�ւ̃|�C���^
	float m_moveTimer = 0.0f;       // �o�ߎ���
	float m_speed = 3.0f;       // �ړ����x
	Player* player;
	Vector3 moveSpeed; //�ړ����x�B
	//CharacterController m_characterController;  //�L�����N�^�[�R���g���[���[�B
};