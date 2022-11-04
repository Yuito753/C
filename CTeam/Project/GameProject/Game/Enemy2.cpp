#include "Enemy2.h"
Enemy2::Enemy2(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy2", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
}
void Enemy2::Update() {
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);

	}
}
void Enemy2::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy2::Collision(Base* b) {

}