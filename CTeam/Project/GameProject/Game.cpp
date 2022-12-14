#include"Game.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Map.h"
#include "Game/UI.h"
#include "Game/GameData.h"
#include "GameData.h"
Game::Game() :Base(eType_Scene) {
	Base::Add(new Player(CVector2D(32 * 2, 32 * 13)));
	//“G‚Ì¶¬
	Base::Add(new Enemy("Enemy", CVector2D(32 * 32, 32 * 19)));
	Base::Add(new Enemy("Enemy4", CVector2D(32 * 34, 32 * 19)));
	Base::Add(new Enemy("Enemy2", CVector2D(32 * 32, 32 * 16)));
	Base::Add(new Enemy("Enemy3", CVector2D(32 * 33, 32 * 16)));
	Base::Add(new Enemy("Enemy5", CVector2D(32 * 36, 32 * 16)));
	Base::Add(new Enemy("Enemy6", CVector2D(32 * 37, 32 * 16)));

	//ƒ}ƒbƒv‚Ì¶¬
	Base::Add(new Map());

	Base::Add(new UI());
}

Game::~Game()
{
	Base::KillAll();
	GameData::point[0] = 0;
	GameData::point[1] = 0;
}

void Game:: Update()
{
	if (GameData::game_state == 0 && PUSH(CInput::eButton1))
		GameData::game_state = 1;
	if (GameData::point[0] >= 3) {
		SetKill();

	}
	if (GameData::game_state == 1) {

		GameData::t_time++;
	}
}

void Game:: Draw()
{
}


