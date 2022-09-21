#include "Enemy.h"
#include "AnimData.h"
#include "Field.h"


Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	//�摜����
	m_img = COPY_RESOURCE("doctor_isya_warui", CImage);

	//m_img.Load("Image/Enemy.png", enemy_anim_data, 256, 256);
	//�Đ��A�j���[�V�����ݒ�
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetSize(200, 150);
	m_img.SetCenter(100, 150);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-85, -140, 85, -10);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	m_cnt = 0;
	//���n�t���O
	m_is_ground = true;
	

}void Enemy::StateIdle()
{
	//�ړ���
	const float move_speed = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;

	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		else
			//�E�ړ�
			if (player->m_pos.x > m_pos.x + 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += move_speed;
				//���]�t���O
				m_flip = false;
				move_flag = true;
			}
			else
				//��ړ�
				if (player->m_pos.y < m_pos.y + 64) {
					//�ړ��ʂ�ݒ�
					m_pos.y += -move_speed;
					//���]�t���O
				}
				else
					//���ړ�
					if (player->m_pos.y > m_pos.y - 64) {
						//�ړ��ʂ�ݒ�
						m_pos.y += move_speed;
					}
			
	}


	

	

}
void Enemy::StateWait() {

	if (--m_cnt <= 0) {
		m_cnt = rand() % 120 + 180;
		m_state = eState_Idle;
	}
}
void Enemy::StateAttack()
{
	
}
void Enemy::StateDamage()
{
	
}
void Enemy::StateDown()
{
	
}
void Enemy::Update() {
	switch (m_state) {
	
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;


	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//�X�N���[���ݒ�
//	m_scroll.x = m_pos.x - 1280 / 2;

}

void Enemy::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(m_pos);
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
}
void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	//�U���G�t�F�N�g�Ƃ̔���
	case eType_Player:
		if (Base::CollisionRect(this,b)) {
			b->SetKill();
		}
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;
	}

}




