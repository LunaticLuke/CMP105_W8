#include "Framework/GameObject.h"


#pragma once
class PongPaddle : public GameObject
{
public:
	PongPaddle(int player);
	~PongPaddle();
	void handleInput(float dt) override;
	void update(float dt) override;
private:
	int speed = 2250;
	int playerNumber = 0;
};

