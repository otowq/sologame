#include "Player.h"
#include "AnimData.h"
#include"Field.h"
#include"Sinkei.h"
#include"Map.h"
#include"Game.h"
//#include "Effect.h"
#include"Enemy.h"
//static�����o�[��.cpp�ɒ�`���Ă���
int Player::m_hp = 10;

static TexAnim _anim_down[] = {
	{0,6},
	{1,6},
	{2,6},
};
static TexAnim _anim_left[] = {
	{3,6},
	{4,6},
	{5,6},
};
static TexAnim _anim_right[] = {
	{6,6},
	{7,6},
	{8,6},
};
static TexAnim _anim_up[] = {
	{9,6},
	{10,6},
	{11,6},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(_anim_down),		//eUp
	ANIMDATA(_anim_left),		//eLeft
	ANIMDATA(_anim_right),		//eRight
	ANIMDATA(_anim_up),			//eUp
};
Player::Player(const CVector2D& pos, bool flip) :
	Base(eType_Player){
	//�摜����
	m_img = COPY_RESOURCE("player", CImage);

	//�Đ��A�j���[�V�����ݒ�
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = pos;
	m_pos_old = pos;
	//���S�ʒu�ݒ�
	m_img.SetCenter(16, 16);
	m_rect = CRect(-16, -16, 16, 16);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	//m_state = eState_Idle;
	//���n�t���O
	//m_is_ground=true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//
	m_hp = 5;
	//����
	m_dir = eUp;
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);


}

void Player::Update() {
	if (Game::gamestate == Game::eBattle) {
		return;
	}
	m_pos_old = m_pos;
	bool is_move = false;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		m_dir = eLeft;
		is_move = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		m_dir = eRight;
		is_move = true;
	}
	//��ړ�
	if (HOLD(CInput::eUp)) {
		m_dir = eUp;
		is_move = true;
	}
	//���ړ�
	if (HOLD(CInput::eDown)) {
		m_dir = eDown;
		is_move = true;
	}
	if (is_move) {
		float move_speed = 4.0f;
		//���݂̕����ֈړ�
		//�e�����̕����x�N�g��
		CVector2D move_dir[] = {
			CVector2D(0,1),		//eDown
			CVector2D(-1,0),	//eLeft
			CVector2D(1,0),		//eRight
			CVector2D(0,-1),	//eUp
		};
		//�ړ�
		m_pos += move_dir[m_dir] * move_speed;
		//�A�j���[�V�����Đ�
		m_img.m_animSpeed = 1.0f;
	}
	else {
		//�A�j���[�V������~
		m_img.m_animSpeed = 0.0f;
	}
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;


	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
	
}

void Player::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
	//�\���T�C�Y�ݒ�
	m_img.SetSize(PLAYER_SIZE, PLAYER_SIZE);
	
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
		//����
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			if (Game::gamestate == Game::eStage) {
				Game::gamestate = Game::eBattle;
				//�_�o����Q�[���������ɑΐ푊���n��
				Base::Add(new Board(dynamic_cast<Enemy*>(b)));
			}
		}
		break;
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t >=8)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t >=8)
				m_pos.y = m_pos_old.y;

		}
		break;

		//�U���G�t�F�N�g�Ƃ̔���
	/*case eType_Enemy_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�h�~
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;

				}
				Base::Add(new Effect("Effect_Blood",
					m_pos + CVector2D(0, -64), m_flip));

				//Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -64), m_flip));
			}
		}
		break;*/
	/*case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
		break;*/
	}

}




