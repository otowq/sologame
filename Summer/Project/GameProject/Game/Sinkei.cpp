#include"Sinkei.h"

	int mark;
	int no;
	bool rev;
static int board[4][4] = {
	{1,2,3,4},
	{1,2,3,4},
	{1,2,3,4},
	{-1,-2,-3,-4},
};

Board::Board()
	:Base(eType_Board)
{
	
	//画像複製
	m_img = COPY_RESOURCE("cards", CImage);
}

void Board::Draw()
{
	//int deal[4][4] = { 0 };
	//マップチップによる表示の繰り返し
	for ( int i = 0; i < 4; i++) {
		for ( int j = 0; j < 4; j++) {
			//表示しない制御
			if (board[i][j] == 0)continue;
			int t = board[i][j] - 1;
			int x = t % 4;
			int y = t / 4;
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
			m_img.SetPos(CARD_SIZE * j - m_scroll.x, CARD_SIZE2 * i - m_scroll.y);
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
	return board[raw][col];
}