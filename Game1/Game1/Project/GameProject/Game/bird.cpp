#include "bird.h"
bird::bird(const CVector2D& pos,bool flip) :Base(eType_bird) {
	//画像の読み込み
	m_img=COPY_RESOURCE("bird_toki_fly",CImage);
	m_pos = pos;
	//半径の設定
	m_rad = 16;
	//表示サイズ設定
	m_img.SetSize(150, 150);
	//描画の基点設定(画像の中心に設定)
	m_img.SetCenter(16, 16);
}
void bird::Update() {
	//敵を下に動かす
	const int move_speed = 32;
	//カウントアップ
	m_cnt++;
	if (m_pos.y < 1000) {
		//60カウント(1秒)以上なら
		if (m_cnt >= 60) {
			//移動
			m_pos.y += move_speed;
			//カウンターリセット
			m_cnt = 0;
		}
	}
}
void bird::Draw() {
	m_img.SetPos(m_pos);
	//画像の表示
	m_img.Draw();
}