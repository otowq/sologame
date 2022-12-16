#include"Sinkei.h"

int count = 1;
int mekuri_x[2];
int mekuri_y[2];

static int boardbase[4][4] = {
	{-1,-2,-3,-4},
	{-1,-2,-3,-4},
	{-1,-2,-3,-4},
	{-1,-2,-3,-4},
};

Board::Board()
	:Base(eType_Board)
{
	
	//�摜����
	m_img = COPY_RESOURCE("cards", CImage);
	//�J�[�h�����_���z�u
	memcpy(m_board, boardbase, sizeof(boardbase));
	for (int i = 0; i < 10; i++) {
		int c1 = rand() % 4;
		int r1 = rand() % 4;
		int c2 = rand() % 4;
		int r2 = rand() % 4;
		int w = m_board[r1][c1];
		m_board[r1][c1] = m_board[r2][c2];
		m_board[r2][c2] = w;
		w = m_board[r1][c1];
	}
	count = 0;
	m_step = 0;
	m_wait = 0;

}

void Board::Draw()
{
	
	//�}�E�X����
	CVector2D p = CInput::GetMousePoint();
	int col = p.x / CARD_SIZE;
	int row = p.y / CARD_SIZE2;
	switch (m_step) {
	case 0:
		if (PUSH(CInput::eMouseL) && m_board[row][col] < 0) {
			m_board[row][col] = -m_board[row][col];
			mekuri_x[count] = col;  //�߂��������ۑ�
			mekuri_y[count] = row;  //�߂������s��ۑ�
			count++;
			if (count >= 2) {
				m_step++;
				m_wait = 0;
			}
		}
		break;
	case 1:
		m_wait++;
		//120F(2�b�҂�)���N���b�N����
		if (m_wait > 120 || PUSH(CInput::eMouseL)) {
			//�߂������J�[�h����v���������
			if (m_board[mekuri_y[0]][mekuri_x[0]] == m_board[mekuri_y[1]][mekuri_x[1]]) {
				m_board[mekuri_y[0]][mekuri_x[0]] = 0;
				m_board[mekuri_y[1]][mekuri_x[1]] = 0;
			}
			else {
				//��v���Ȃ���΂܂����ɖ߂�
				m_board[mekuri_y[0]][mekuri_x[0]] = -m_board[mekuri_y[0]][mekuri_x[0]];
				m_board[mekuri_y[1]][mekuri_x[1]] = -m_board[mekuri_y[1]][mekuri_x[1]];
			}
			//�߂�����������0�֖߂�
			count = 0;
			//�߂����Ԃ�
			m_step = 0;
		}
		break;
	}
	
	


	//�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�
	for ( int i = 0; i < 4; i++) {
		for ( int j = 0; j < 4; j++) {
			//�\�����Ȃ�����
			if (m_board[i][j] == 0)continue;
			int t = m_board[i][j] - 1;

			int x = t % 8;
			int y = t / 8;
			//�摜�؂蔲��
			if (t >= 0) {
				//�J�[�h�\
				m_img.SetRect(32 * x, 58 * y, 32 * x + 32, 58 * y + 58);
			}
			else {
				//�J�[�h��
				m_img.SetRect(32 * 14, 58 * 1, 32 * 14 + 32, 58 * 1 + 58);
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
	return m_board[raw][col];
}