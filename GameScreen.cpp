#include "GameScreen.h"
#include "Game.h"
#include "GameOverScreen.h"

GameScreen::GameScreen()
{
	this->spawnApples();

	this->pickupBuffer.loadFromFile("Music/crunch.wav");
	this->pickupSound.setBuffer(this->pickupBuffer);
	this->pickupSound.setVolume(25.f);
}

GameScreen::~GameScreen()
{
}

void GameScreen::getSnakeSelfCol()
{
	if (this->snake.checkSelfCol())
	{
		Game::screen = std::make_unique<GameOverScreen>(this->score);
	}
}

void GameScreen::spawnApples()
{
	while (this->apples.size() < this->maxApples) {
		this->apples.push_back(Apple(snake, apples));
	}
}

void GameScreen::updateSpawnApples()
{
	if (this->spawnTimerApple < this->spawnTimerAppleMax && this->apples.size() < this->maxApples) {
		this->spawnTimerApple++;
	}
	else if (this->apples.size() < this->maxApples) {
		this->apples.push_back(Apple(snake, apples));

		this->spawnTimerApple = 0;
	}
}

void GameScreen::snakeGrow()
{
	for (size_t i = 0; i < this->apples.size(); i++) {
		if (this->snake.getHeadBounds().intersects(this->apples[i].getGlobalBounds())) {
			this->snake.addSnakeNode();

			this->apples.erase(this->apples.begin() + i);

			this->score++;
			//this->score += this->spawnTimerAppleMax - this->spawnTimerApple;

			this->pickupSound.play();

			break;
		}
	}
}

void GameScreen::render(sf::RenderWindow& window)
{
	for (auto& a : this->apples) {
		a.render(window);
	}

	this->snake.render(window);
}

void GameScreen::update(sf::RenderWindow& window)
{
	this->updateSpawnApples();
	this->snake.update();
	this->snakeGrow();
	this->getSnakeSelfCol();
}