#pragma once
#include "../Base/Base.h"
class bird :public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;

	//��������p�̃J�E���^�[
	int m_cnt;
	int m_move;
public:
	//�R���X�g���N�^
	//pos [in] �o���ʒu
	bird(const CVector2D& pos,bool flip);
	//�X�V
	void Update();
	//�`��;
	void Draw();
};
