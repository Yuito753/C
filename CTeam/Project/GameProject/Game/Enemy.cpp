#include "Enemy.h":
Enemy::Enemy(const char*name,const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE(name, CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
	m_state = estate_randamu;
	m_cnt = 0;
	m_direction = eunder;
}
void Enemy::Update() {
	switch (m_state) {
	case estate_randamu:
		randamu();
		break;
	case estate_tuiseki:
		tuiseki();
		break;
	case estate_nigeru:
		nigeru();
		break;
	}
	
}
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy::Collision(Base* b) {

}

void Enemy::randamu()
{
	m_cnt++;
	int t;
	Base* b = Base::FindObject(eType_Field);
	if (Map* m = dynamic_cast<Map*>(b)) {
		switch (m_direction) {
		case eup:
			t = m->GetTip(m_pos + CVector2D(0, -32 + 16));
			if (t != 0) {
				m_direction = rand()%4;
			}
			else {
				m_pos.y -= 1;
			}
			break;
		case eright:
			t = m->GetTip(m_pos + CVector2D(32-16, 0));
			if (t != 0) {
				m_direction = rand()%4;
			}
			else {
				m_pos.x += 1;
			}
			
			break;
		case eleft:
			t = m->GetTip(m_pos + CVector2D(-32 + 16, 0));
			if (t != 0) {
				m_direction = rand()%4;
			}
			else {
				m_pos.x -= 1;
			}
			break;
		case eunder:
			t = m->GetTip(m_pos+CVector2D(0,32-16));
			if (t != 0) {
				m_direction = rand()%4;
			}
			else {
				m_pos.y += 1;
			}
			
			break;
		}
	}
	
	if (m_cnt > 180) {
		//m_state = estate_tuiseki;
	}
}

void Enemy::tuiseki()
{//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {



		//マウスクリックで目的地変更
		if (m_cnt % 120 == 0) {

			if (Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Field))) {
				//経路探索　対象マップ、自分の座標、目標の座標
				m_path.FindShortestPath(m, m_pos, b->m_pos);
				//経路データ配列の添字に使用
				m_path_idx = 2;
			}
		}
		const float speed = 4;
		//現在の添字　< パスの数なら次の目標地点へ移動
		if (m_path_idx < m_path.GetPathSize()) {
			//次の目標地点へのベクトル
			CVector2D vec = m_path.GetPathPoint(m_path_idx) - m_pos;
			//目標地点との距離が8より遠ければ
			if (vec.Length() > 8) {
				m_ang = atan2(vec.x, vec.y);
				CVector2D dir(sin(m_ang), cos(m_ang));
				//目標地点へ移動
				m_pos += dir * speed;
			}
			else {
				//次の経路ポイントへ
				m_path_idx++;
			}
		}

	}
}

void Enemy::nigeru()
{
}
