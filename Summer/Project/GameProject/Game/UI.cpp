#include"UI.h"
#include"Player.h"

UI::UI():Base(eType_UI)
{
	m_heart = COPY_RESOURCE("heart", CImage);
	m_img.Load("Image/UI.png");

}

void UI::Draw()
{
	m_heart.Draw();
	//表示サイズ設定
	m_heart.SetSize(UI_SIZE, UI_SIZE);

	int hp = Player::m_hp;

	for (int i = 0; i < 2; i++, hp /= 10) {
		int s = hp % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(32, 32);
		m_img.SetPos(50 - 16 * i, 50);
		m_img.Draw();
	}

	
}
