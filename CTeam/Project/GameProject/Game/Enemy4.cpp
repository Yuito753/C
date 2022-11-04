#include "Enemy4.h"
Enemy4::Enemy4(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy4", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
}
void Enemy4::Update() {
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
void Enemy4::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy4::Collision(Base* b) {

}