#pragma once

#include "../Base/Base.h"

class Game : public Base {
public:
	static int gamestate;
	enum{eStage,eBattle};
	Game();
	~Game();
	void Update();
};