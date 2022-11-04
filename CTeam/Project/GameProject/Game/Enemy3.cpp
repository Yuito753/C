#include "Enemy3.h"
Enemy3::Enemy3(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//��`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);
	//���a
	m_rad = 16;
}
void Enemy3::Update() {
	//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) {
		//�^�[�Q�b�g�ւ̃x�N�g��
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