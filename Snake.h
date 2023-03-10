#pragma once

#include <iostream>
#include "SnakeNode.h"
#include "SFML/Audio.hpp"

class Snake
{
public:
	Snake();
	~Snake();

	const std::vector<SnakeNode>& getSnakeNodes() const;
	const sf::FloatRect getHeadBounds() const;

	void addSnakeNode();
	bool checkSelfCol();

	void clear();

	void render(sf::RenderTarget& target);
	void update();
private:
	std::vector<SnakeNode> snake;

	sf::SoundBuffer dieBuffer;
	sf::Sound dieSound;

	size_t snakeSize = 2;
	
	void move();
	void updateTexture();
	void checkEdgeCol();

	bool isPosDifGreatZero(float pos1, float pos2);
};