#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include"Map.h"
#include "../Title/Title.h"
int stage = 1;

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Map(1));
}

Game::~Game()
{
	//全てのオブジェクトを破棄
//	Base::KillAll();
	//タイトルシーンへ
	//Base::Add(new Title());
}

void Game::Update()
{
	/*Base* enemy = Base::FindObject(eType_Enemy);
	if (enemy == nullptr || (PUSH(CInput::eButton1))) {
		Base* field = Base::FindObject(eType_Field);
		//Base* Map = Base::FindObject(eType_Map);
		Base* player = Base::FindObject(eType_Player);
		Base* enemy = Base::FindObject(eType_Enemy);
		field->SetKill();
		player->SetKill();
		stage++;
		if (stage >= 3) {
			//ゲームクリアに移行
			//全てのオブジェクトを破棄
			Base::KillAll();

			//Base::Add(new Gameclear());
		}
		else
		{
			Base::Add(new Map(stage));
		}
	}*/
	//ゴールが無ければゲームシーン終了
	//if (!Base::FindObject(eType_Goal)) {
		//SetKill();
//	}

	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

