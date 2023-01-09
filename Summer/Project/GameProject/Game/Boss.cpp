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
	//画像複製
	m_img = COPY_RESOURCE("boss", CImage);

	//m_img.Load("Image/Enemy.png", enemy_anim_data, 256, 256);
	//再生アニメーション設定
	//m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(32, 32);
	//当たり判定用矩形設定
	m_rect = CRect(-32, -32, 32, 32);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	//m_state = eState_Idle;
	m_cnt = 0;
	//着地フラグ
	m_is_ground = true;

	//m_hp = 5;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_attack_no = -1;
	m_dir = eDown;
	//アニメーション種類指定
	m_img.ChangeAnimation(m_dir);
	//HPを設定
	m_hp = 10;

}void Boss::StateIdle()
{
	//移動量
	//const float move_speed = 6;
	//移動フラグ
//	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;

	/*Base* player = Base::FindObject(eType_Player);

	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		else
			//右移動
			if (player->m_pos.x > m_pos.x + 64) {
				//移動量を設定
				m_pos.x += move_speed;
				//反転フラグ
				m_flip = false;
				move_flag = true;
			}
			else {
				//攻撃状態へ移行
				m_state = eState_Attack;
				m_attack_no++;
			}
	}*/




	/* if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//移動中なら
	else
	{
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}

	}
	if (--m_cnt <= 0) {
		m_cnt = rand() % 120 + 180;
		m_state = eState_Wait;
	}*/

}
void Boss::StateWait() {
	//待機アニメーション

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





	//アニメーション更新
	//m_img.UpdateAnimation();

	//スクロール設定
//	m_scroll.x = m_pos.x - 1280 / 2;

}

void Boss::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	//DrawRect();
	//表示サイズ設定
	m_img.SetSize(ENEMY_SIZE, ENEMY_SIZE);
}
void Boss::Collision(Base* b)
{



}
