#include "Enemy.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//��`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);
	//���a
	m_rad = 16;
}
void Enemy::Update() {

	//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) {
		//�^�[�Q�b�g�ւ̃x�N�g��
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		
		//�}�E�X�N���b�N�ŖړI�n�ύX
		if (PUSH(CInput::eMouseL)) {
			CVector2D mouse_pos = CInput::GetMousePoint();
			if (Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Field))) {
				//�o�H�T���@�Ώۃ}�b�v�A�����̍��W�A�ڕW�̍��W
				m_path.FindShortestPath(m, m_pos, mouse_pos);
				//�o�H�f�[�^�z��̓Y���Ɏg�p
				m_path_idx = 0;
			}
		}
		const float speed = 4;
		//���݂̓Y���@< �p�X�̐��Ȃ玟�̖ڕW�n�_�ֈړ�
		if (m_path_idx < m_path.GetPathSize()) {
			//���̖ڕW�n�_�ւ̃x�N�g��
			CVector2D vec = m_path.GetPathPoint(m_path_idx) - m_pos;
			//�ڕW�n�_�Ƃ̋�����8��艓�����
			if (vec.Length() > 8) {
				m_ang = atan2(vec.x, vec.y);
				CVector2D dir(sin(m_ang), cos(m_ang));
				//�ڕW�n�_�ֈړ�
				m_pos += dir * speed;
			}
			else {
				//���̌o�H�|�C���g��
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