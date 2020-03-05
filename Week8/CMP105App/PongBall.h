#include "Framework/GameObject.h"

#pragma once
class PongBall : public GameObject
{
public:
	PongBall();
	~PongBall();
	void update(float dt) override;
	void CollisionResponse();
	void setRenderWindow(sf::RenderWindow* wind);
private:
	sf::Texture texture;
	sf::RenderWindow* rendwind;
	float speed = 15.f;
	int maxVelocity = 100;
};

