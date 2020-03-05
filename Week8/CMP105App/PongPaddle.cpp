#include "PongPaddle.h"

PongPaddle::PongPaddle(int player)
{
	playerNumber = player;
	setSize(sf::Vector2f(50, 200));
	setFillColor(sf::Color::Blue);
	setCollisionBox(sf::FloatRect(0, 0, 50, 200));
	if (player == 1)
	{
		setPosition(50, 200);
	}
	else
	{
		setPosition(700, 200);
	}
}

PongPaddle::~PongPaddle()
{
}

void PongPaddle::handleInput(float dt)
{
	switch (playerNumber)
	{
	case 1:
		if (input->isKeyDown(sf::Keyboard::W))
		{
			move(sf::Vector2f(0, -speed * dt));
		}
		if (input->isKeyDown(sf::Keyboard::S))
		{
			move(sf::Vector2f(0, speed * dt));
		}
		break;
	case 2:
		if (input->isMouseLDown())
		{
			setPosition(sf::Vector2f(getPosition().x,input->getMouseY()));
		}

		break;
	}
}

void PongPaddle::update(float dt)
{
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}
	else if (getPosition().y + getSize().y > 600)
	{
		setPosition(getPosition().x, 600 - getSize().y);
	}
	
}
