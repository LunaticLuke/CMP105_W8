#include "Framework/GameObject.h"

#pragma once
class Ball : public GameObject
{
public:
	Ball(sf::Vector2f positionToSpawnAt);
	~Ball();
	void update(float dt) override;
	void collisionResponse();
private:
	sf::Texture texture;
	float speed = 10.f;
};

