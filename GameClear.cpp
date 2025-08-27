#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"

GameClear::GameClear()
{
    spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);
    //�^�C�g����BGM��ǂݍ��ށB
    g_soundEngine->ResistWaveFileBank(3, "Assets/sound/clear.wav");
    //�^�C�g����BGM���Đ�����B
    clearBGM = NewGO<SoundSource>(0);
    clearBGM->Init(3);
    clearBGM->Play(false);
}

GameClear::~GameClear()
{
	DeleteGO(clearBGM);
}

//�X�V�����B
void GameClear::Update()
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
void GameClear::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}