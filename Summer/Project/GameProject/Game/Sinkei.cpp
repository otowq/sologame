#include"Sinkei.h"

int count = 1;
static int board[4][4] = {
	{1,2,3,4},
	{1,2,3,4},
	{-1,-2,-3,-4},
	{-1,-2,-3,-4},
};

Board::Board()
	:Base(eType_Board)
{
	
	//�摜����
	m_img = COPY_RESOURCE("cards", CImage);
}

void Board::Draw()
{

	CVector2D p = CInput::GetMousePoint();
	int col = p.x / CARD_SIZE;
	int row = p.y / CARD_SIZE2;

	if (PUSH(CInput::eMouseL) && board[row][col] < 0 && count <= 2) {
		board[row][col] = -board[row][col];
		count++;
		if (count == 2 ) {
			//�߂������J�[�h����v���������

		}
		else {
			//��v���Ȃ���΂܂����ɖ߂�

		}
	}
	


	//�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�
	for ( int i = 0; i < 4; i++) {
		for ( int j = 0; j < 4; j++) {
			//�\�����Ȃ�����
			if (board[i][j] == 0)continue;
			int t = board[i][j] - 1;

			int x = t % 8;
			int y = t / 8;
			//�摜�؂蔲��
			if (t >= 0) {
				m_img.SetRect(32 * x, 58 * y, 32 * x + 32, 58 * y + 58);
			}
			else {
				m_img.SetRect(32 * 14, 58 * 0, 32 * 14 + 32, 58 * 0 + 58);
			}
			//�\���T�C�Y�ݒ�
			m_img.SetSize(CARD_SIZE, CARD_SIZE2);
			//�\���ʒu�ݒ�
			m_img.SetPos(CARD_SIZE * j , CARD_SIZE2 * i );
			//�`��
			m_img.Draw();
		}
	}
}

int Board::GetTip(const CVector2D& pos)
{
	//����v�Z
	int col = pos.x / CARD_SIZE;
	//��̐���(0�`MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > 4 - 1) col = 4 - 1;
	//�s���v�Z
	int raw = pos.y / CARD_SIZE2;
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