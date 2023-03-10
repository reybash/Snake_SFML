#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameScreen.h"
#include "Screen.h"
#include "TextureStorage.h"

class Game
{
public:
	Game();
	~Game();

	static const int Width = 900;
	static const int Height = 600;
	static int HighScore;

	static std::unique_ptr<Screen> screen;

	const bool getWindiowIsOpen() const;
	
	void run();
private:
	sf::RenderWindow window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Music music;

	TextureStorage textures;

	sf::RectangleShape backGround;

	void initWindow();

	void updateEvents();

	void render();
	void update();
};