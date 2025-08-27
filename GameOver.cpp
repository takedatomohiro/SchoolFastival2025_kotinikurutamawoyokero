#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"

GameOver::GameOver()
{
    spriteRender.Init("Assets/sprite/gameover.DDS", 1920.0f, 1080.);
    //タイトルのBGMを読み込む。
    g_soundEngine->ResistWaveFileBank(2, "Assets/sound/over.wav");
    //タイトルのBGMを再生する。
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
    //Aボタンが押されたら。
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //タイトルのオブジェクトをつくる。
        NewGO<Title>(0, "title");
        //自身を削除する。
        DeleteGO(this);
    }
}
//描画処理。
void GameOver::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}