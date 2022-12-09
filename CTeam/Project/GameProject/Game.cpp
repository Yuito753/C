#include"Game.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Map.h"
#include "Game/UI.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Player(CVector2D(32 * 2, 32 * 13)));
	//敵の生成
	Base::Add(new Enemy("Enemy", CVector2D(32 * 32, 32 * 19)));
	Base::Add(new Enemy("Enemy4", CVector2D(32 * 34, 32 * 19)));
	Base::Add(new Enemy("Enemy2", CVector2D(32 * 32, 32 * 16)));
	Base::Add(new Enemy("Enemy3", CVector2D(32 * 33, 32 * 16)));
	Base::Add(new Enemy("Enemy5", CVector2D(32 * 36, 32 * 16)));
	Base::Add(new Enemy("Enemy6", CVector2D(32 * 37, 32 * 16)));

	//マップの生成
	Base::Add(new Map());

	Base::Add(new UI());
}

Game::~Game()
{
}

void Game:: Update()
{
	Base* b = Base::FindObject(eType_Field);
	if (Map* m = dynamic_cast<Map*>(b)) {
		printf("%d\n", m->item);
	}
}

void Game:: Draw()
{
}


