#pragma once
#include "../Base/Base.h"
#define CARD_SIZE	64
#define CARD_SIZE2   128

class Board : public Base {
private:
	CImage m_img;
	int m_board[4][4];
	//�Q�[���̏��
	int m_step;
	//�ҋ@����
	int m_wait;
public:
	Board();
	void Draw();
	//�w����W�̃`�b�v�ԍ����擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int raw);

};
