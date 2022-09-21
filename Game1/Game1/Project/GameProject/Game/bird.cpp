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
	m_img.SetCenter(16, 16);
}
void bird::Update() {
	//�G�����ɓ�����
	const int move_speed = 32;
	//�J�E���g�A�b�v
	m_cnt++;
	if (m_pos.y < 1000) {
		//60�J�E���g(1�b)�ȏ�Ȃ�
		if (m_cnt >= 60) {
			//�ړ�
			m_pos.y += move_speed;
			//�J�E���^�[���Z�b�g
			m_cnt = 0;
		}
	}
}
void bird::Draw() {
	m_img.SetPos(m_pos);
	//�摜�̕\��
	m_img.Draw();
}