#include "PongBall.h"

PongBall::PongBall()
{
	setSize(sf::Vector2f(50, 50));
	setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	setPosition(375, 375);
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setVelocity(40, 40);
}

PongBall::~PongBall()
{
}

void PongBall::update(float dt)
{
	move(velocity * dt * speed);
	if (getPosition().x < 0)
	{
		
		setPosition(rendwind->getSize().x / 2, rendwind->getSize().y / 2);
		setVelocity(40, 40);
	}
	else if (getPosition().x + getSize().x > 800)
	{
		setPosition(rendwind->getSize().x / 2, rendwind->getSize().y / 2);
		setVelocity(-40, -40);
	}
	else if (getPosition().y < 0)
	{
		setPosition(getPosition().x,0);
		velocity.y = -velocity.y;
		if (velocity.y <= maxVelocity && velocity.y >= -maxVelocity)
		{
			velocity.y *= 1.2f;
			velocity.x /= 1.2f;
		}
	}
	else if (getPosition().y + getSize().y > 600)
	{
		setPosition(getPosition().x, 600 - getSize().y);
		velocity.y = -velocity.y;
		if (velocity.y <= maxVelocity && velocity.y >= -maxVelocity)
		{
			velocity.y *= 1.2f;
			velocity.x /= 1.2f;
		}
	}
}

void PongBall::CollisionResponse()
{
	velocity.x = -velocity.x;
	if (velocity.x <= maxVelocity && velocity.x >= -maxVelocity)
	{
		velocity.x *= 1.2f;
		velocity.y /= 1.2f;
	}
}

void PongBall::setRenderWindow(sf::RenderWindow* wind)
{
	rendwind = wind;
}
