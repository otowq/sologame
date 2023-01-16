#pragma once
#include"Enemy.h"
#include"Sinkei.h"

#define ENEMY_SIZE	64
class Boss : public Enemy {
private:
	//状態
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	//状態変数
	

	//各状態での挙動

	void StateWait();
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	Boss(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
	//敵のHPは通常の変数
		//staticはゲームで一つだけのデータになる

};
extern TexAnimData boss_anim_data[];