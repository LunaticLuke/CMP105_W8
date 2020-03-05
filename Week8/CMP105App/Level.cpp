#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	ballObject.setRenderWindow(window);
	// initialise game objects
	paddle1.setInput(in);
	paddle2.setInput(in);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	paddle1.handleInput(dt);
	paddle2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	/*ball1.update(dt);
	ball2.update(dt);
	box1.update(dt);
	box2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.collisionResponse();
		ball2.collisionResponse();
	}
	if (Collision::checkBoundingBox(&box1, &box2))
	{
		box1.collisionResponse();
		box2.collisionResponse();
	}*/
	paddle1.update(dt);
	paddle2.update(dt);
	ballObject.update(dt);
	if (Collision::checkBoundingBox(&paddle1, &ballObject) || Collision::checkBoundingBox(&paddle2,&ballObject))
	{
		ballObject.CollisionResponse();
	}
}

// Render level
void Level::render()
{
	beginDraw();
	/*window->draw(ball1);
	window->draw(ball2);
	window->draw(box1);
	window->draw(box2);*/
	window->draw(paddle1);
	window->draw(paddle2);
	window->draw(ballObject);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}