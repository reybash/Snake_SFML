#include "StartScreen.h"

#include "Game.h"

StartScreen::StartScreen() {
  this->text.setString(
      "\n\n\n\n\n\n\n\n\nPress [SPACE] to play"
      "\n\nPress [ESC] to quit");

  sf::FloatRect textBounds = this->text.getLocalBounds();
  this->text.setOrigin(textBounds.left + textBounds.width / 2,
                       textBounds.top + textBounds.height / 2);
  this->text.setPosition(Game::Width / 2.f, Game::Height / 2.f);

  this->snakeText.setFont(this->font);
  this->snakeText.setString("Snake!");
  this->snakeText.setFillColor(sf::Color::Green);
  this->snakeText.setCharacterSize(80);
  this->snakeText.setOutlineThickness(2.f);
  this->snakeText.setOutlineColor(sf::Color::Black);
  this->snakeText.setStyle(sf::Text::Bold);

  sf::FloatRect snakeTextBounds = this->snakeText.getLocalBounds();
  this->snakeText.setOrigin(snakeTextBounds.left + snakeTextBounds.width / 2,
                            snakeTextBounds.top + snakeTextBounds.height / 2);
  this->snakeText.setPosition(Game::Width / 2.f, Game::Height / 4.f);
}

StartScreen::~StartScreen() {}

void StartScreen::update(sf::RenderWindow& window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    this->over = true;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window.close();
}

void StartScreen::render(sf::RenderWindow& window) {
  window.draw(this->text);
  window.draw(this->snakeText);
}