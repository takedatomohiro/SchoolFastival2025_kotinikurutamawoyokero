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
	m_modelRender.SetScale(5.5f, 5.0f, 5.5f);//�T�C�Y�ύX�i���A���A���j
	m_modelRender.Update();
	return true;
}

void Enemy::Update()
{
	
	//�ړ�����
	Move();
	
	//�G�`������̍X�V����
	m_modelRender.Update();

	//��]����
	Rotation();		

	
}
void Enemy::Move()
{	
	//���t���[�����ԉ��Z
	m_moveTimer += GameTime().GetFrameDeltaTime();

	// //3�b�o�߂Ńv���C���[�Ɍ������Ĉړ�
	if (m_moveTimer >= 0.0f && m_player != nullptr)
	{
		// �����x�N�g���v�Z
		Vector3 dir = m_player->position - m_position;
		dir.Normalize();

		float speed = 4.0f;  // �� �v���C���[�Ɍ������Ăǂꂾ���i�ނ�
		m_position += dir * speed;

		m_moveTimer = 0.0f; // �^�C�}�[���Z�b�g

		Vector3 diff = m_player->position - m_position;
	}
	m_modelRender.SetPosition(m_position);

	/*m_position = m_characterController.Execute(moveSpeed, 1.0f / 60.0f);*/
}

void Enemy::Rotation()
{
	//��]�����Z����
	rotation.AddRotationDegY(20.0f);

	//�G�`������ɉ�]��������B
	m_modelRender.SetRotation(rotation);
}

void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}



