#include "Player.h"
#include "AnimData.h"
#include"Field.h"
#include"Sinkei.h"
#include"Map.h"
#include"Game.h"
//#include "Effect.h"
#include"Enemy.h"
//staticメンバーは.cppに定義しておく
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
	//画像複製
	m_img = COPY_RESOURCE("player", CImage);

	//再生アニメーション設定
	//m_img.ChangeAnimation(0);
	//座標設定
	m_pos = pos;
	m_pos_old = pos;
	//中心位置設定
	m_img.SetCenter(16, 16);
	m_rect = CRect(-16, -16, 16, 16);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	//m_state = eState_Idle;
	//着地フラグ
	//m_is_ground=true;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;
	//
	m_hp = 5;
	//方向
	m_dir = eUp;
	//アニメーション種類指定
	m_img.ChangeAnimation(m_dir);


}

void Player::Update() {
	if (Game::gamestate == Game::eBattle) {
		return;
	}
	m_pos_old = m_pos;
	bool is_move = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		m_dir = eLeft;
		is_move = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		m_dir = eRight;
		is_move = true;
	}
	//上移動
	if (HOLD(CInput::eUp)) {
		m_dir = eUp;
		is_move = true;
	}
	//下移動
	if (HOLD(CInput::eDown)) {
		m_dir = eDown;
		is_move = true;
	}
	if (is_move) {
		float move_speed = 4.0f;
		//現在の方向へ移動
		//各方向の方向ベクトル
		CVector2D move_dir[] = {
			CVector2D(0,1),		//eDown
			CVector2D(-1,0),	//eLeft
			CVector2D(1,0),		//eRight
			CVector2D(0,-1),	//eUp
		};
		//移動
		m_pos += move_dir[m_dir] * move_speed;
		//アニメーション再生
		m_img.m_animSpeed = 1.0f;
	}
	else {
		//アニメーション停止
		m_img.m_animSpeed = 0.0f;
	}
	//アニメーション種類指定
	m_img.ChangeAnimation(m_dir);
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;


	//アニメーション更新
	m_img.UpdateAnimation();

	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;
	
}

void Player::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	//DrawRect();
	//表示サイズ設定
	m_img.SetSize(PLAYER_SIZE, PLAYER_SIZE);
	
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
		//判定
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			if (Game::gamestate == Game::eStage) {
				Game::gamestate = Game::eBattle;
				//神経衰弱ゲーム生成時に対戦相手を渡す
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

		//攻撃エフェクトとの判定
	/*case eType_Enemy_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//同じ攻撃の連続ダメージ防止
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
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;*/
	}

}




