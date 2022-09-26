#pragma once
#include "../Base/Base.h"
class bird :public Base {
private:
	//画像オブジェクト
	CImage m_img;

	//動き制御用のカウンター
	int m_cnt;
	int m_move;
public:
	//コンストラクタ
	//pos [in] 出現位置
	bird(const CVector2D& pos,bool flip);
	//更新
	void Update();
	//描画;
	void Draw();
};
