#include "GameOverScreen.h"
#include "Game.h"


GameOverScreen::GameOverScreen(int score)
{
	if (score > Game::HighScore)
	{
		Game::HighScore = score;
	}

	this->text.setString("YOU DEAD!"
		"\n\nScore : " + std::to_string(score) +
		"\n\nBest Score : " + std::to_string(Game::HighScore) +
		"\n\nPress [SPACE] to retry"
		"\n\nPress [ESC] to quit");
	this->text.setFillColor(sf::Color::Red);

	sf::FloatRect textBounds = this->text.getLocalBounds();
	this->text.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	this->text.setPosition(Game::Width / 2.f, Game::Height / 2.f);
}

GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::update(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::screen = std::make_unique<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void GameOverScreen::render(sf::RenderWindow& window)
{
	window.draw(this->text);
}