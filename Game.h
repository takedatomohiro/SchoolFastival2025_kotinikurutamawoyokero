#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class BackGround;
class Enemy;

class Game : public IGameObject
{
public:
	Game();
	~Game();

	
	void Update();
	void Render(RenderContext& rc);

	

	bool m_isCleared = false;
private:
	Player* m_player = nullptr; //�v���C���[�B
	std::vector<Enemy*> m_enemies;
	GameCamera* m_gameCamera = nullptr; //�Q�[���J�����B
	BackGround* m_backGround = nullptr;  //�w�i�B
	SoundSource* gameBGM;
	float m_timer = 20.0f;
	FontRender m_timeFontRender;
	FontRender m_distance;
};

