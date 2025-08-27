#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Enemy.h"
#include <chrono>
#include <iostream>
#include "GameClear.h"
#include <GameOver.h>
#include "sound/SoundEngine.h"


Game::Game()
{
	m_player = NewGO<Player>(0, "player");

	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	m_backGround = NewGO<BackGround>(0);

	Enemy* enemy1 = NewGO<Enemy>(0, "enemy");
	Vector3 ePos = { 1500.0f,0.0f,0.0f };
	enemy1->SetPosition(ePos);
	enemy1->SetPlayer(m_player);
	m_enemies.push_back(enemy1);

	Enemy* enemy2 = NewGO<Enemy>(0, "enemy");
	Vector3  epos = { 0.0f,0.0f,1500.0f };
	enemy2->SetPosition(epos);
	enemy2->SetPlayer(m_player);
	m_enemies.push_back(enemy2);

	Enemy* enemy3 = NewGO<Enemy>(0, "enemy");
	Vector3 Epos = { -1500.0f,0.0f,0.0f };
	enemy3->SetPosition(Epos);
	enemy3->SetPlayer(m_player);
	m_enemies.push_back(enemy3);

	Enemy* enemy4 = NewGO<Enemy>(0, "enemy");
	Vector3 epoS = { 0.0f,0.0f,-1500.0f };
	enemy4->SetPosition(epoS);
	enemy4->SetPlayer(m_player);
	m_enemies.push_back(enemy4);

	Enemy* enemy5 = NewGO<Enemy>(0, "enemy");
	Vector3 EPos = { 2000.0f,0.0f,-2000.0f };
	enemy5->SetPosition(EPos);
	enemy5->SetPlayer(m_player);
	//m_enemies.push_back(enemy5);

	Enemy* enemy6 = NewGO<Enemy>(0, "enemy");
	Vector3 EPOs = { -2000.0f,0.0f,-2000.0f };
	enemy6->SetPosition(EPOs);
	enemy6->SetPlayer(m_player);
	//m_enemies.push_back(enemy6);

	Enemy* enemy7 = NewGO<Enemy>(0, "enemy");
	Vector3 EPOS = { 2000.0f,0.0f,2000.0f };
	enemy7->SetPosition(EPOS);
	enemy7->SetPlayer(m_player);
	//m_enemies.push_back(enemy7);

	Enemy* enemy8 = NewGO<Enemy>(0, "enemy");
	Vector3 epOS = { -2000.0f,0.0f,2000.0f };
	enemy8->SetPosition(epOS);
	enemy8->SetPlayer(m_player);
	//m_enemies.push_back(enemy8);

	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/game.wav");
	//ゲーム中のBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(1);
	gameBGM->Play(true);
}

Game::~Game()
{
	
}


void Game::Update()
{
	int minute = (int)m_timer / 60;
	int sec = (int)m_timer % 60;

	wchar_t text[256];
	swprintf_s(text, 256, L"%02d:%02d", minute, sec);
	m_timeFontRender.SetText(text);
	//文字の座標
	m_timeFontRender.SetPosition(-100.0f,500.0f,0.0f);
	//文字の大きさ
	m_timeFontRender.SetScale(2.0f);
	//文字の色
	m_timeFontRender.SetColor(g_vec4White);

	m_timer -= g_gameTime->GetFrameDeltaTime();

	Vector3 playerPos = m_player->GetPosition();  // ※ GetPosition() を Player クラスに実装しておく
	
	for (Enemy* enemy : m_enemies) {
		Vector3 enemyPos = enemy->GetPosition();  // ※ Enemy も同様に GetPosition() が必要
		float dx = playerPos.x - enemyPos.x;
		float dy = playerPos.y - enemyPos.y;
		float dz = playerPos.z - enemyPos.z;
		float distance = std::sqrt(dx * dx + dy * dy + dz * dz);
		if (playerPos.y <= -10.0f) {
			NewGO<GameOver>(0, "gameover");
			//プレイヤーを削除する。
			DeleteGO(m_player);
			//ゲームカメラを削除する。
			DeleteGO(m_gameCamera);
			//ゲーム中のBGMを削除する。
			DeleteGO(gameBGM);
			//背景を削除する。
			DeleteGO(m_backGround);
			//敵を削除する。
			DeleteGO(m_enemies[0]);
			DeleteGO(m_enemies[1]);
			DeleteGO(m_enemies[2]);
			DeleteGO(m_enemies[3]);
			DeleteGO(m_enemies[4]);
			DeleteGO(m_enemies[5]);
			DeleteGO(m_enemies[6]);
			DeleteGO(m_enemies[7]);
			
			DeleteGO(this);
			return;
		}
		

		if (distance < 500.0f) {
			m_distance.SetText(L"距離が近い");
			m_distance.SetPosition({ -600.0f,100.0f,0.0f });
			m_distance.SetColor(g_vec4White);

			if (distance < 200.0f) {
				NewGO<GameOver>(0, "gameover");
				//プレイヤーを削除する。
				DeleteGO(m_player);
				//ゲームカメラを削除する。
				DeleteGO(m_gameCamera);
				//ゲーム中のBGMを削除する。
				 DeleteGO(gameBGM);
				//背景を削除する。
				DeleteGO(m_backGround);
				//敵を削除する。
				DeleteGO(m_enemies[0]);
				DeleteGO(m_enemies[1]);
				DeleteGO(m_enemies[2]);
				DeleteGO(m_enemies[3]);
				DeleteGO(m_enemies[4]);
				DeleteGO(m_enemies[5]);
				DeleteGO(m_enemies[6]);
				DeleteGO(m_enemies[7]);

				DeleteGO(this);
				return;
			}
		}
		
		
	}
	if (m_timer <= 0.0f) {
		NewGO<GameClear>(0, "gameclear");
		//プレイヤーを削除する。
		DeleteGO(m_player);
		//ゲームカメラを削除する。
		DeleteGO(m_gameCamera);
		//ゲーム中のBGMを削除する。
		DeleteGO(gameBGM);
		//背景を削除する。
		DeleteGO(m_backGround);
		//敵を削除する。
		DeleteGO(m_enemies[0]);
		DeleteGO(m_enemies[1]);
		DeleteGO(m_enemies[2]);
		DeleteGO(m_enemies[3]);
		DeleteGO(m_enemies[4]);
		DeleteGO(m_enemies[5]);
		DeleteGO(m_enemies[6]);
		DeleteGO(m_enemies[7]);
		DeleteGO(this);
			
		return;
	}
		
}
void Game::Render(RenderContext& rc)
{
	//フォントを描画する。
	m_timeFontRender.Draw(rc);
	m_distance.Draw(rc);
}
