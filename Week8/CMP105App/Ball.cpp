#include "Ball.h"

Ball::Ball(sf::Vector2f positionToSpawnAt)
{
	setPosition(positionToSpawnAt);
	setSize(sf::Vector2f(150, 150));
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	velocity.x = 10;
}

Ball::~Ball()
{
}

void Ball::update(float dt)
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

void Ball::collisionResponse()
{
	velocity.x = -velocity.x;
}
