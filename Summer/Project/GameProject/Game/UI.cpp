#include"UI.h"
#include"Player.h"
#include"Sinkei.h"
#include"Enemy.h"
#include"Boss.h"

UI::UI():Base(eType_UI)
{
	m_heart = COPY_RESOURCE("heart", CImage);
	m_img.Load("Image/UI.png");

}

void UI::Draw()
{
	m_heart.SetPos(300, 0);
	m_heart.Draw();
	//表示サイズ設定
	m_heart.SetSize(UI_SIZE, UI_SIZE);

	int hp = Player::m_hp;

	for (int i = 0; i < 2; i++, hp /= 10) {
		int s = hp % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(32, 32);
		m_img.SetPos(350 - 16 * i, 50);
		m_img.Draw();
	}
	//敵のHP表示
	//神経衰弱クラスから対戦中の敵のHPを取得
	if (Board* s = dynamic_cast<Board*>(Base::FindObject(eType_Board))) {
		int hp = s->m_enemy->m_hp;
		for (int i = 0; i < 2; i++, hp /= 10) {
			int s = hp % 10;
			m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
			m_img.SetSize(32, 32);
			m_img.SetPos(450 - 16 * i, 50);
			m_img.Draw();
		}
	}
}
