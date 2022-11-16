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
	//�w����W�̃`�b�v�ԍ����擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int raw);

};
