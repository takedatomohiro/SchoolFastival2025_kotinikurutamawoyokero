#pragma once
class GameOver : public IGameObject
{
public:

    GameOver();
        ~GameOver();

    //�X�V�����B
    void Update();
    //�`�揈���B
    void Render(RenderContext& rc);
    //�����o�ϐ��B
    SpriteRender spriteRender; //�X�v���C�g�����_�\�B
    SoundSource* overBGM;
};

