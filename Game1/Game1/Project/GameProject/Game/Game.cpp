#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "bird.h"
#include "../Title/Title.h"
#include"../Game over/Game over.h"

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(100,540), false));
	Base::Add(new Enemy(CVector2D(700, 500), false));
	Base::Add(new bird(CVector2D(100, 500), false));
	SOUND("BGM_maoudamasii")->Play(true);

}

Game::~Game()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());

	if (!Base::FindObject(eType_Player) ) {
		Base::Add(new Gameover());
		m_kill = true;
	}
}

void Game::Update()
{
	//�S�[����������΃Q�[���V�[���I��
	//if (!Base::FindObject(eType_Goal)) {
	//	SetKill();
	//}

	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

