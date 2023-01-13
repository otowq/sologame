#pragma once
#include "../Base/Base.h"
#define PLAYER_SIZE	32
class Player : public Base {
private:
	//���
	enum {														
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool	m_flip;
	//���n�t���O
	bool	m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;

	//int m_player_hp;
	
	
	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	static int m_hp;
	Player(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
	
};
extern TexAnimData player_anim_data[];