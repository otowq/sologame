#include"Sinkei.h"

int count = 1;
//int mekuri_x[2];
//int mekuri_y[2];
//card{mekuri_x[0]}{mekuri_y[0]}
//
static int boardbase[4][4] = {
	{1,2,3,4},
	{1,2,3,4},
	{-1,-2,-3,-4},
	{-1,-2,-3,-4},
};

Board::Board()
	:Base(eType_Board)
{
	
	//画像複製
	m_img = COPY_RESOURCE("cards", CImage);
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




}

void Board::Draw()
{

	CVector2D p = CInput::GetMousePoint();
	int col = p.x / CARD_SIZE;
	int row = p.y / CARD_SIZE2;

	if (PUSH(CInput::eMouseL) && m_board[row][col] < 0 && count <= 2) {
		m_board[row][col] = -m_board[row][col];
		count++;
		if (count == 2 ) {
			//めくったカードが一致したら消す

		}
		else {
			//一致しなければまた裏に戻す

		}
	}
	


	//マップチップによる表示の繰り返し
	for ( int i = 0; i < 4; i++) {
		for ( int j = 0; j < 4; j++) {
			//表示しない制御
			if (m_board[i][j] == 0)continue;
			int t = m_board[i][j] - 1;

			int x = t % 8;
			int y = t / 8;
			//画像切り抜き
			if (t >= 0) {
				m_img.SetRect(32 * x, 58 * y, 32 * x + 32, 58 * y + 58);
			}
			else {
				m_img.SetRect(32 * 14, 58 * 0, 32 * 14 + 32, 58 * 0 + 58);
			}
			//表示サイズ設定
			m_img.SetSize(CARD_SIZE, CARD_SIZE2);
			//表示位置設定
			m_img.SetPos(CARD_SIZE * j , CARD_SIZE2 * i );
			//描画
			m_img.Draw();
		}
	}
}

int Board::GetTip(const CVector2D& pos)
{
	//列を計算
	int col = pos.x / CARD_SIZE;
	//列の制限(0～MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > 4 - 1) col = 4 - 1;
	//行を計算
	int raw = pos.y / CARD_SIZE2;
	//行の制限(0～MAP_HEIGHT-1)
	if (raw < 0) raw = 0;
	if (raw > 4 - 1) raw = 4 - 1;
	//チップデータを返却
	return GetTip(col, raw);
}

int Board::GetTip(int col, int raw)
{
	return m_board[raw][col];
}