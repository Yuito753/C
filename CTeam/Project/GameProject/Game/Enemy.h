#pragma once
#include "../Base/Base.h"
#include "Dijkstra.h"
class Enemy : public Base {
private:
	CImage m_img;
	int m_cnt;
	CVector2D m_target_point;
	Dijkstra m_path;
	int		m_path_idx;
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};