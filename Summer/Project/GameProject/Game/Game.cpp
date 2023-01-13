#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include"Map.h"
#include"Sinkei.h"
#include "../Title/Title.h"
#include"UI.h"

int stage = 1;
int Game::gamestate = eStage;

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Map(1));
	Base::Add(new UI());
	//Base::Add(new Board());
}

Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	Base* enemy = Base::FindObject(eType_Enemy);
	Base* boss = Base::FindObject(eType_Boss);
	Base* map = Base::FindObject(eType_Map);
	if (enemy == nullptr && boss == nullptr) {
		Base* player = Base::FindObject(eType_Player);
		Base* map = Base::FindObject(eType_Map);
		Base* enemy = Base::FindObject(eType_Enemy);
		map->SetKill();
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
	}
	//ゴールが無ければゲームシーン終了
	//if (!Base::FindObject(eType_Goal)) {
		//SetKill();
//	}

	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

