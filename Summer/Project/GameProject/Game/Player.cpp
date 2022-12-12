#include "Player.h"
#include "AnimData.h"
#include"Field.h"
#include"Sinkei.h"
#include"Map.h"
#include"Game.h"
//#include "Effect.h"
static TexAnim _anim_down[] = {
	{0,4},
	{1,4},
	{2,4},
};
static TexAnim _anim_left[] = {
	{3,4},
	{4,4},
	{5,4},
};
static TexAnim _anim_right[] = {
	{6,4},
	{7,4},
	{8,4},
};
static TexAnim _anim_up[] = {
	{9,4},
	{10,4},
	{11,4},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(_anim_down),		//eUp
	ANIMDATA(_anim_left),		//eLeft
	ANIMDATA(_anim_right),		//eRight
	ANIMDATA(_anim_up),			//eUp
};
Player::Player(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("player", CImage);
	//�Đ��A�j���[�V�����ݒ�
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
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
	m_hp = 100;
	//����
	m_dir = eUp;
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);


}

void Player::Update() {
	if (Game::gamestate == Game::eBattle) {
		return;
	}

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


}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
		//����
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			if (Game::gamestate == Game::eStage) {
				Game::gamestate = Game::eBattle;
				Base::Add(new Board());
			}
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




