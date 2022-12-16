#pragma once
#include"Base/Base.h"

class Game :public Base {
	CImage GameClear_text;
public:
	Game();
	~Game();
	void Update();
	void Draw();
};