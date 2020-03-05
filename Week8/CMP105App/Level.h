#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Framework/Collision.h"
#include "AABBSprite.h"
#include "PongBall.h"
#include "PongPaddle.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	Ball ball1 = Ball(sf::Vector2f(200, 200));
	Ball ball2 = Ball(sf::Vector2f(600, 200));
	AABBSprite box1 = AABBSprite(sf::Vector2f(200, 500), sf::Color::Blue);
	AABBSprite box2 = AABBSprite(sf::Vector2f(600, 500), sf::Color::Red);
	PongBall ballObject;
	PongPaddle paddle1 = PongPaddle(1);
	PongPaddle paddle2 = PongPaddle(2);
};