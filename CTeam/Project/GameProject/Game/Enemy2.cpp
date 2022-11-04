#include "Enemy2.h"
Enemy2::Enemy2(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy2", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//��`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);
	//���a
	m_rad = 16;
}
void Enemy2::Update() {
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
void Enemy2::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Enemy2::Collision(Base* b) {

}