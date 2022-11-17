#include "Enemy.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);
	//半径
	m_rad = 16;
}
void Enemy::Update() {

	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		
		//マウスクリックで目的地変更
		if (PUSH(CInput::eMouseL)) {
			CVector2D mouse_pos = CInput::GetMousePoint();
			if (Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Field))) {
				//経路探索　対象マップ、自分の座標、目標の座標
				m_path.FindShortestPath(m, m_pos, mouse_pos);
				//経路データ配列の添字に使用
				m_path_idx = 0;
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
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy::Collision(Base* b) {

}