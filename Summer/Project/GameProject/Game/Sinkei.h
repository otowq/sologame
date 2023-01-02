#pragma once
#include "../Base/Base.h"
#define CARD_SIZE	64
#define CARD_SIZE2   128

class Enemy;

class Board : public Base {
private:
	CImage m_img;
	int m_board[4][4];
	//ゲームの状態
	int m_step;
	//待機時間
	int m_wait;
	//敵がめくるカードを決める
	void EnemyCPU(int* col, int* row);
public:
	Enemy* m_enemy;
	Board(Enemy* m_enemy);
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);

};
