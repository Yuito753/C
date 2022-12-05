#include "Enemy.h":
Enemy::Enemy(const char*name,const CVector2D& pos)
	:Base(eType_Enemy) {

	m_img = COPY_RESOURCE(name, CImage);
	m_pos = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//��`��ݒ�
	m_rect = CRect(-16, -16, 16, 16);
	//���a
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
{//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) {



		//�}�E�X�N���b�N�ŖړI�n�ύX
		if (m_cnt % 120 == 0) {

			if (Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Field))) {
				//�o�H�T���@�Ώۃ}�b�v�A�����̍��W�A�ڕW�̍��W
				m_path.FindShortestPath(m, m_pos, b->m_pos);
				//�o�H�f�[�^�z��̓Y���Ɏg�p
				m_path_idx = 2;
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

void Enemy::nigeru()
{
}
