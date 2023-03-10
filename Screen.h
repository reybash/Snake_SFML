#pragma once

#include "SFML/Graphics.hpp"

class Screen
{
public:
	Screen();
	virtual ~Screen();

	virtual void update(sf::RenderWindow& window) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
protected:
	sf::Font font;
	sf::Text text;
};
