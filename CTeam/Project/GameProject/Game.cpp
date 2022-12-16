#include"Game.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Map.h"
#include "Game/UI.h"
#include"Title/Title.h"

Game::Game() :Base(eType_Scene) {
	GameClear_text = COPY_RESOURCE("GameClear", CImage);
	Base::Add(new Player(CVector2D(32 * 2, 32 * 13)));
	//ìGÇÃê∂ê¨
	Base::Add(new Enemy("Enemy", CVector2D(32 * 32, 32 * 19)));
	Base::Add(new Enemy("Enemy4", CVector2D(32 * 34, 32 * 19)));
	Base::Add(new Enemy("Enemy2", CVector2D(32 * 32, 32 * 16)));
	Base::Add(new Enemy("Enemy3", CVector2D(32 * 33, 32 * 16)));
	Base::Add(new Enemy("Enemy5", CVector2D(32 * 36, 32 * 16)));
	Base::Add(new Enemy("Enemy6", CVector2D(32 * 37, 32 * 16)));

	//É}ÉbÉvÇÃê∂ê¨
	Base::Add(new Map());

	Base::Add(new UI());
}

Game::~Game()
{
}

void Game:: Update()
{
	
}

void Game:: Draw()
{
	Base* b = Base::FindObject(eType_Field);
	if (Map* m = dynamic_cast<Map*>(b)) {
		printf("%d\n", m->item);
		if (m->item == 0)
		{
			if (PUSH(CInput::eButton10)) {
				SOUND("SE_Button2")->Play();
				SetKill();
				Base::KillAll();
				Base::Add(new Title ());
			}
			GameClear_text.SetPos(100, 300);
			GameClear_text.Draw();
		}
	}
}


