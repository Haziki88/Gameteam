#include "Enemy.h"
#include "AnimData.h"
#include "Field.h"


Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	//画像複製
	m_img = COPY_RESOURCE("doctor_isya_warui", CImage);

	//m_img.Load("Image/Enemy.png", enemy_anim_data, 256, 256);
	//再生アニメーション設定
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetSize(200, 150);
	m_img.SetCenter(100, 150);
	//当たり判定用矩形設定
	m_rect = CRect(-85, -140, 85, -10);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	m_cnt = 0;
	//着地フラグ
	m_is_ground = true;
	

}void Enemy::StateIdle()
{
	//移動量
	const float move_speed = 2;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;

	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		else
			//右移動
			if (player->m_pos.x > m_pos.x + 64) {
				//移動量を設定
				m_pos.x += move_speed;
				//反転フラグ
				m_flip = false;
				move_flag = true;
			}
			else
				//上移動
				if (player->m_pos.y < m_pos.y + 64) {
					//移動量を設定
					m_pos.y += -move_speed;
					//反転フラグ
				}
				else
					//下移動
					if (player->m_pos.y > m_pos.y - 64) {
						//移動量を設定
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
	
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;


	//アニメーション更新
	m_img.UpdateAnimation();

	//スクロール設定
//	m_scroll.x = m_pos.x - 1280 / 2;

}

void Enemy::Draw() {
	//位置設定
	m_img.SetPos(m_pos);
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	//DrawRect();
}
void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	//攻撃エフェクトとの判定
	case eType_Player:
		if (Base::CollisionRect(this,b)) {
			b->SetKill();
		}
	case eType_Field:
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	}

}




