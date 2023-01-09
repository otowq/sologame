#include "Boss.h"
#include "AnimData.h"
#include "Field.h"

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

TexAnimData boss_anim_data[] = {
	ANIMDATA(_anim_down),		//eUp
	ANIMDATA(_anim_left),		//eLeft
	ANIMDATA(_anim_right),		//eRight
	ANIMDATA(_anim_up),			//eUp
};
Boss::Boss(const CVector2D& p, bool flip) :
	Base(eType_Boss) {
	//�摜����
	m_img = COPY_RESOURCE("boss", CImage);

	//m_img.Load("Image/Enemy.png", enemy_anim_data, 256, 256);
	//�Đ��A�j���[�V�����ݒ�
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 32);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-32, -32, 32, 32);
	//���]�t���O
	m_flip = flip;
	//�ʏ��Ԃ�
	//m_state = eState_Idle;
	m_cnt = 0;
	//���n�t���O
	m_is_ground = true;

	//m_hp = 5;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_attack_no = -1;
	m_dir = eDown;
	//�A�j���[�V������ގw��
	m_img.ChangeAnimation(m_dir);
	//HP��ݒ�
	m_hp = 10;

}void Boss::StateIdle()
{
	//�ړ���
	//const float move_speed = 6;
	//�ړ��t���O
//	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;

	/*Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		else
			//�E�ړ�
			if (player->m_pos.x > m_pos.x + 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += move_speed;
				//���]�t���O
				m_flip = false;
				move_flag = true;
			}
			else {
				//�U����Ԃֈڍs
				m_state = eState_Attack;
				m_attack_no++;
			}
	}*/




	/* if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//�ړ����Ȃ�
	else
	{
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}

	}
	if (--m_cnt <= 0) {
		m_cnt = rand() % 120 + 180;
		m_state = eState_Wait;
	}*/

}
void Boss::StateWait() {
	//�ҋ@�A�j���[�V����

}
void Boss::StateAttack()
{

}
void Boss::StateDamage()
{

}
void Boss::StateDown()
{

}
void Boss::Update() {





	//�A�j���[�V�����X�V
	//m_img.UpdateAnimation();

	//�X�N���[���ݒ�
//	m_scroll.x = m_pos.x - 1280 / 2;

}

void Boss::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
	//�\���T�C�Y�ݒ�
	m_img.SetSize(ENEMY_SIZE, ENEMY_SIZE);
}
void Boss::Collision(Base* b)
{



}
