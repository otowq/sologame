#include"Sinkei.h"

static int board[4][4] = {
	{1,2,3,4},
	{1,2,3,4},
	{1,2,3,4},
	{1,2,3,4},
};

Board::Board()
	:Base(eType_Board)
{
	//�摜����
	m_img = COPY_RESOURCE("cards", CImage);
}

void Board::Draw()
{
	//�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//�\�����Ȃ�����
			if (board[i][j] == 0)continue;
			int t = board[i][j];
			int x = t % 8;
			int y = t / 8;
			//�摜�؂蔲��
			m_img.SetRect(32 * x, 64 * y, 32 * x + 32,64 * y + 64);
			//�\���T�C�Y�ݒ�
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE2);
			//�\���ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE2 * i - m_scroll.y);
			//�`��
			m_img.Draw();
		}
	}
}

int Board::GetTip(const CVector2D& pos)
{
	//����v�Z
	int col = pos.x / MAP_TIP_SIZE;
	//��̐���(0�`MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > 4 - 1) col = 4 - 1;
	//�s���v�Z
	int raw = pos.y / MAP_TIP_SIZE2;
	//�s�̐���(0�`MAP_HEIGHT-1)
	if (raw < 0) raw = 0;
	if (raw > 4 - 1) raw = 4 - 1;
	//�`�b�v�f�[�^��ԋp
	return GetTip(col, raw);
}

int Board::GetTip(int col, int raw)
{
	return board[raw][col];
}