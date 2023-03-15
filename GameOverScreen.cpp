#include "GameOverScreen.h"

#include "Game.h"
#include "GameScreen.h"

GameOverScreen::GameOverScreen(int score) {
  if (score > GameScreen::HighScore) {
    GameScreen::HighScore = score;
  }

  this->text.setString(
      "YOU DEAD!"
      "\n\nScore : " +
      std::to_string(score) +
      "\n\nBest Score : " + std::to_string(GameScreen::HighScore) +
      "\n\nPress [SPACE] to retry"
      "\n\nPress [ESC] to quit");
  this->text.setFillColor(sf::Color::Red);

  sf::FloatRect textBounds = this->text.getLocalBounds();
  this->text.setOrigin(textBounds.left + textBounds.width / 2,
                       textBounds.top + textBounds.height / 2);
  this->text.setPosition(Game::Width / 2.f, Game::Height / 2.f);
}

GameOverScreen::~GameOverScreen() {}

void GameOverScreen::update(sf::RenderWindow& window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    this->over = true;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window.close();
}

void GameOverScreen::render(sf::RenderWindow& window) {
  window.draw(this->text);
}