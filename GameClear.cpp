#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"

GameClear::GameClear()
{
    spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);
    //タイトルのBGMを読み込む。
    g_soundEngine->ResistWaveFileBank(3, "Assets/sound/clear.wav");
    //タイトルのBGMを再生する。
    clearBGM = NewGO<SoundSource>(0);
    clearBGM->Init(3);
    clearBGM->Play(false);
}

GameClear::~GameClear()
{
	DeleteGO(clearBGM);
}

//更新処理。
void GameClear::Update()
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
void GameClear::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}