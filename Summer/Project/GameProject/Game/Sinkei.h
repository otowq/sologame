#pragma once
#include "../Base/Base.h"
#define MAP_TIP_SIZE	32
#define MAP_TIP_SIZE2   64

class Board : public Base {
private:
	CImage m_img;
	int board[4][4];
public:
	Board();
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);

};
