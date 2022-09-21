#include"Game over.h"
#include "../Game/Game.h"
#include"../Title/Title.h"

Gameover::Gameover() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("gameover",CImage);
}

Gameover::~Gameover()
{
	Base::Add(new Title());
}

void Gameover::Update()
{
	//�{�^���P�ŃQ�[���I�[�o�[�j��
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

void Gameover::Draw()
{
	m_img.Draw();
	m_title_text.Draw(64, 900, 0, 0, 0, "Push Z");
}
