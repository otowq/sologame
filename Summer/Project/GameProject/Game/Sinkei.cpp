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
	//画像複製
	m_img = COPY_RESOURCE("cards", CImage);
}

void Board::Draw()
{
	//マップチップによる表示の繰り返し
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//表示しない制御
			if (board[i][j] == 0)continue;
			int t = board[i][j];
			int x = t % 8;
			int y = t / 8;
			//画像切り抜き
			m_img.SetRect(32 * x, 64 * y, 32 * x + 32,64 * y + 64);
			//表示サイズ設定
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE2);
			//表示位置設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE2 * i - m_scroll.y);
			//描画
			m_img.Draw();
		}
	}
}

int Board::GetTip(const CVector2D& pos)
{
	//列を計算
	int col = pos.x / MAP_TIP_SIZE;
	//列の制限(0～MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > 4 - 1) col = 4 - 1;
	//行を計算
	int raw = pos.y / MAP_TIP_SIZE2;
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