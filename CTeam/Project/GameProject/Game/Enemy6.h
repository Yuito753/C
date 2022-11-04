#pragma once
#include "../Base/Base.h"

class Enemy6 : public Base {
private:
	CImage m_img;
	int m_cnt;
public:
	Enemy6(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};