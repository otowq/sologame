#pragma once
#include "../Base/Base.h"
#define CARD_SIZE	64
#define CARD_SIZE2   128

class Board : public Base {
private:
	CImage m_img;
	//int board[4][4];
	int m_board[4][4];
public:
	Board();
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);

};
