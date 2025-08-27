#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"

GameOver::GameOver()
{
    spriteRender.Init("Assets/sprite/gameover.DDS", 1920.0f, 1080.);
    //�^�C�g����BGM��ǂݍ��ށB
    g_soundEngine->ResistWaveFileBank(2, "Assets/sound/over.wav");
    //�^�C�g����BGM���Đ�����B
    overBGM = NewGO<SoundSource>(0);
    overBGM->Init(2);
    overBGM->Play(false);
}

GameOver::~GameOver()
{
	DeleteGO(overBGM);
}

void GameOver::Update()
{
    //A�{�^���������ꂽ��B
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //�^�C�g���̃I�u�W�F�N�g������B
        NewGO<Title>(0, "title");
        //���g���폜����B
        DeleteGO(this);
    }
}
//�`�揈���B
void GameOver::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}