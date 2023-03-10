#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.h"

class Apple
{
public:
	Apple();
	Apple(Snake& snake, std::vector<Apple>& apples);
	~Apple();

	const sf::CircleShape& getShape() const;
	const sf::FloatRect getGlobalBounds() const;

	void render(sf::RenderTarget& target);
private:
	sf::CircleShape apple;

	bool wrongSpawnApple = false;

	void spawnApple();
	void fixWrongLocApple(
		Snake& snake, 
		std::vector<Apple>& apples);
};