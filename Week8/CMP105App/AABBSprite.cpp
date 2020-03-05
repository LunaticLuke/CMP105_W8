#include "AABBSprite.h"

AABBSprite::AABBSprite(sf::Vector2f positionToSpawnAt, sf::Color colorToBe)
{
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	setPosition(positionToSpawnAt);
	setFillColor(colorToBe);
	setVelocity(50, 0);
}

AABBSprite::~AABBSprite()
{
}

void AABBSprite::update(float dt)
{
	move(velocity * dt * speed);
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 750)
	{
		setPosition(750, getPosition().y);
		velocity.x = -velocity.x;
	}
}

void AABBSprite::collisionResponse()
{
	velocity.x = -velocity.x;
}
