#pragma once
#include"../Base/Base.h"
#define UI_SIZE 128
class UI :public Base {
private:
	CImage m_heart;
	CImage m_img;
public:
	UI();
	void Draw();
};