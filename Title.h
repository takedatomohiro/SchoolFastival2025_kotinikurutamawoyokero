#pragma once
class Title : public IGameObject
{
  public:
        Title();
        ~Title();

        //�`��֐��B
        void Render(RenderContext& rc);
        //�X�V�����B 
        void Update();
        //�X�v���C�g�����_�\�B
        SpriteRender spriteRender;
        SoundSource* titleBGM;//�^�C�g����BGM�B
    
};

