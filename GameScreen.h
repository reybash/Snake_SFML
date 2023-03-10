#pragma once

#include "SFML/Graphics.hpp"
#include "SnakeNode.h"
#include "Apple.h"
#include "Screen.h"

class GameScreen : public Screen
{
public:
	GameScreen();
	~GameScreen();

	void getSnakeSelfCol();
	
	void render(sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
private:
	Snake snake;
	std::vector<Apple> apples;

	sf::SoundBuffer pickupBuffer;
	sf::Sound pickupSound;

	int spawnTimerApple = 0;
	int const spawnTimerAppleMax = 20;
	int const maxApples = 5;
	int score = 0;

	void spawnApples();
	void updateSpawnApples();

	void snakeGrow();
};