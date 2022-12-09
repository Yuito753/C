#include "Player.h"
#include "Map.h"

Player::Player(const CVector2D& pos)
	:Base(eType_Player) {

	m_img = COPY_RESOURCE("Player", CImage);
	m_pos= m_pos_old = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
	WPcount = 0;
	
	
}
void Player::Update() {
	m_pos_old = m_pos;
	const float speed = 4;
	//左に移動
	if (HOLD(CInput::eLeft))
		m_pos.x -= speed;
	//右に移動
	if (HOLD(CInput::eRight))
		m_pos.x += speed;
	//上に移動
	if (HOLD(CInput::eUp))

		m_pos.y -= speed;
	//下に移動
	if (HOLD(CInput::eDown))
		m_pos.y += speed;
	if (WPcount > 0)
		WPcount--;


}
void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}
void Player::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {

			int t = m->GetTip(m_pos);
			if (t != 0) {
				if (t == 3) {
					m->SetTip(m_pos, 0);
				}
				else if (t == 4) {
					m->SetTip(m_pos, 0);
				}
				else if (t & (1 << 16)) {
					int x = t & 0xFF;


					int y = (t >> 8) & 0xFF;


					if (WPcount == 0) {
						m_pos = CVector2D(x * 40 + 20, y * 40 + 20);
						WPcount = 60;
					}
				}
			}
			t = m->CollisionMap(CVector2D(m_pos.x,m_pos_old.y),m_rect);
			if (t == 1) {
				m_pos.x = m_pos_old.x;
			}
				
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t == 1)
				m_pos.y = m_pos_old.y;
			
		}
		break;

	}

}