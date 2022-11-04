#include "Enemy3.h"
Enemy3::Enemy3(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
}
void Enemy3::Update() {
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
void Enemy3::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy3::Collision(Base* b) {

}