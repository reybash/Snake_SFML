#pragma once

#include"SFML/Graphics.hpp"

enum MOVE
{
	LEFT = 0, DOWN, UP, RIGHT
};

class SnakeNode
{
public:
	SnakeNode();
	SnakeNode(sf::Vector2f position,
		sf::Texture& texture);
	SnakeNode(sf::Vector2f position,
		sf::Texture& texture, sf::IntRect frame);
	~SnakeNode();

	static const float Size;

	void move();
	void move(float xOffset, float yOffset);
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setDirection(float x,float y);
	void setTextureRect(int left, int top, int size);
	void setTextureRect(sf::IntRect frame);

	const sf::RectangleShape& getShape() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::IntRect getTextureRect() const;
	sf::Vector2f getPosition() const;
	const short getDirection() const;
	const float getMovementX() const;
	const float getMovementY() const;

	void render(sf::RenderTarget& target);
	void update();

private:
	sf::RectangleShape shape;

	short direction;

	float movementX;
	float movementY;

	sf::Vector2f position;

	void initVar();
	void updateInput();
};