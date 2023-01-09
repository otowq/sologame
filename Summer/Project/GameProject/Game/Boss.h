#pragma once
#include "../Base/Base.h"
#include"Sinkei.h"

#define ENEMY_SIZE	64
class Boss : public Base {
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
	int m_state;
	int m_cnt;

	CImage m_img;
	bool	m_flip;
	//着地フラグ
	bool	m_is_ground;
	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;


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
	int m_hp;
};
extern TexAnimData boss_anim_data[];