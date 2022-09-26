#include "bird.h"
bird::bird(const CVector2D& pos,bool flip) :Base(eType_bird) {
	//�摜�̓ǂݍ���
	m_img=COPY_RESOURCE("bird_toki_fly",CImage);
	m_pos = pos;
	//���a�̐ݒ�
	m_rad = 16;
	//�\���T�C�Y�ݒ�
	m_img.SetSize(150, 150);
	//�`��̊�_�ݒ�(�摜�̒��S�ɐݒ�)
	m_img.SetCenter(75, 75);
	m_rect = CRect(-75, -50, 75, 40);
}
void bird::Update() {
	//�G�����ɓ�����
	const int move_speed = 32;
	//�J�E���g�A�b�v
	m_cnt++;
	m_move = rand() % 4;
	if (m_pos.y < 1000&&m_pos.x<1920) {
		//60�J�E���g(1�b)�ȏ�Ȃ�
		if (m_cnt >= 30) {
			switch (m_move) {
			case 0:
				//�ړ�
				m_pos.y += move_speed;
				//�J�E���^�[���Z�b�g
				m_cnt = 0;
				break;
			case 1:
				//�ړ�
				m_pos.y -= move_speed;
				//�J�E���^�[���Z�b�g
				m_cnt = 0;
				break;
			case 2:
				//�ړ�
				m_pos.x += move_speed;
				//�J�E���^�[���Z�b�g
				m_cnt = 0;
				break;
			case 3:
				//�ړ�
				m_pos.x -= move_speed;
				//�J�E���^�[���Z�b�g
				m_cnt = 0;
				break;
			}
			
		}
	}
}
void bird::Draw() {
	m_img.SetPos(m_pos);
	//�摜�̕\��
	m_img.Draw();
	//DrawRect();
}