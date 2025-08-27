#pragma once

class Enemy;
class Player: public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();
	Vector3 GetPosition() const { return position; }

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;			//���W�B
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,

	};
	AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	CharacterController m_characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	//Enemy* enemy = nullptr;	//�G�̃|�C���^�B
	//int starCount = 0;	//�W�߂����̐����J�E���g����B
};


