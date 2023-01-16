#pragma once
#include "../Base/Base.h"
#include"Sinkei.h"

#define ENEMY_SIZE	32
class Enemy : public Base {
public:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Wait,
	};
	//��ԕϐ�
	int m_state;
	int m_cnt;

	CImage m_img;
	bool	m_flip;
	//���n�t���O
	bool	m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	

	//�e��Ԃł̋���

	void StateWait();
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	Enemy(const CVector2D& p, bool flip,int Type);
	void Update();
	void Draw();
	void Collision(Base* b);
	//�G��HP�͒ʏ�̕ϐ�
		//static�̓Q�[���ň�����̃f�[�^�ɂȂ�
	int m_hp;
};
extern TexAnimData Enemy_anim_data[];