#include "Framework/GameObject.h"

#pragma once
class AABBSprite : public GameObject
{
public:
	AABBSprite(sf::Vector2f positionToSpawnAt, sf::Color colorToBe);
	~AABBSprite();
	void update(float dt) override;
	void collisionResponse();
private:
	float speed = 10.f;
};

