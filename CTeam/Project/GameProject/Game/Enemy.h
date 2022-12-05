#pragma once
#include "../Base/Base.h"
#include "Dijkstra.h"
class Enemy : public Base {
private:
	CImage m_img;
	int m_cnt;
	int m_state;
	enum {
		estate_randamu,
		estate_tuiseki,
		estate_nigeru,

	};
	int m_direction;
	enum {
		eup,
		eright,
		eleft,
		eunder,
	};
	CVector2D m_target_point;
	Dijkstra m_path;
	int		m_path_idx;
public:
	Enemy(const char* name,const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
	void randamu();
	void tuiseki();
	void nigeru();

};