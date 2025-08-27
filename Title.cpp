#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	spriteRender.Init("Assets/sprite/title.dds", 1920.0f, 1080.0f);
	//�^�C�g����BGM��ǂݍ��ށB
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/title.wav");
	//�^�C�g����BGM���Đ�����B
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);
}

Title::~Title()
{
	//�^�C�g����BGM���폜����B
	DeleteGO(titleBGM);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
    //�摜��`�悷��B
    spriteRender.Draw(rc);
}
