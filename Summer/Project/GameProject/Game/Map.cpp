#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Boss.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 178,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,182,184,184,184,184,184,184,184,184,184,184,184,184,179},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,572,572,572,572,572,176,155,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,588,588,588,588,588,176,163,152,153,153,153,153,153,153,153,153,154,1,176},
	{ 176,1,1,1,1,278,279,1,262,263,569,569,569,569,569,1,1,1,1,1,1,368,369,369,375,370,176,1,160,161,161,161,161,161,161,161,161,162,1,176},
	{ 176,1,1,1,1,286,287,1,270,271,585,585,585,585,585,1,1,1,1,1,1,376,377,377,383,378,176,1,160,161,161,161,161,161,161,161,161,162,1,176},
	{ 176,1,1,1,1,152,153,154,155,1,368,369,369,375,370,1,1,1,1,5,5,5,5,5,5,5,176,1,168,169,169,169,169,169,169,169,169,170,1,176},
	{ 176,1,1,1,1,160,161,162,163,1,376,377,377,383,378,1,1,1,1,5,1,1,1,1,1,1,176,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,168,169,170,1,1,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,186,180,1,1,188,184,184,184,184,184,184,184,184,190},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,569,569,569,569,569,1,1,571,571,571,571,571,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,585,585,585,585,585,1,1,587,587,587,587,587,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,368,369,369,375,370,1,1,368,369,369,375,370,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,376,377,377,383,378,1,1,376,377,377,383,378,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,569,569,569,569,569,1,1,570,570,570,570,570,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,585,585,585,585,585,1,1,586,586,586,586,586,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,368,369,369,375,370,1,1,368,369,369,375,370,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,230,231,5,1,1,376,377,377,383,378,1,1,376,377,377,383,378,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,238,239,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 186,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,187},
};

static int stage2data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 178,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,179},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 176,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,176},
	{ 186,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,187},
};

Map::Map(int stage)
	:Base(eType_Map)
	{

		//????????
		m_img = COPY_RESOURCE("Map", CImage);
		switch (stage) {
		case 1:
			
			Base::Add(new Player(CVector2D(200, 300), false));
			Base::Add(new Enemy(CVector2D(1300, 400), false));
			//Base::Add(new Enemy(CVector2D(600, 500), false));
			//Base::Add(new Enemy(CVector2D(600, 100), false));
			memcpy(m_stagedata, stage1data, sizeof(stage1data));

			break;
		case 2:
			Base::Add(new Player(CVector2D(2000, 300), false));
			Base::Add(new Boss(CVector2D(400, 300), false));
			Base::Add(new Enemy(CVector2D(1000, 400), false));
			memcpy(m_stagedata, stage2data, sizeof(stage2data));
			break;
		}
	}

	void Map::Draw()
	{
		//?}?b?v?`?b?v???????\?????J??????
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				//?\????????????
				if (m_stagedata[i][j] == 0)continue;
				int t = m_stagedata[i][j];
				int x = t % 8;
				int y = t / 8;
				//????????????
				m_img.SetRect(32 * x, 32 * y, 32 * x + 32, 32 * y + 32);
				//?\???T?C?Y????
				m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
				//?\?????u????
				m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i -m_scroll.y);
				//?`??
				m_img.Draw();
			}
		}

	}
	int Map::GetTip(const CVector2D& pos)
	{
		//?????v?Z
		int col = pos.x / MAP_TIP_SIZE;
		//????????(0?`MAP_WIDTH-1)
		if (col < 0) col = 0;
		if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
		//?s???v?Z
		int raw = pos.y / MAP_TIP_SIZE;
		//?s??????(0?`MAP_HEIGHT-1)
		if (raw < 0) raw = 0;
		if (raw > MAP_HEIGHT - 1) raw = MAP_HEIGHT - 1;
		//?`?b?v?f?[?^?????p
		return GetTip(col, raw);
	}

	int Map::GetTip(int col, int raw)
	{
		return m_stagedata[raw][col];
	}

	int Map::CollisionMap(const CVector2D& pos, const CRect& rect)
	{
			//????
			int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
			if (t >=8) return t;
			//?E??
			t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
			if (t >=8) return t;
			//????
			t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
			if (t >=8) return t;
			//?E??
			t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
			if (t >=8) return t;
			return 0;
		}
	



