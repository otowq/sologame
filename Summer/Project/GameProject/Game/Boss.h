#pragma once
#include"Enemy.h"
#include"Sinkei.h"

#define ENEMY_SIZE	64
class Boss : public Enemy {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	//��ԕϐ�
	

	//�e��Ԃł̋���

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
	//�G��HP�͒ʏ�̕ϐ�
		//static�̓Q�[���ň�����̃f�[�^�ɂȂ�

};
extern TexAnimData boss_anim_data[];