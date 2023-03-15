#include "GameScreen.h"

#include "Game.h"
#include "GameOverScreen.h"

int GameScreen::score = 0;
int GameScreen::HighScore = 0;

GameScreen::GameScreen() {
  score = 0;
  auto result = TextureStorage::getTexture("apple");

  if (result) {
    this->apple.setTexture(*result.get());
  }

  this->spawnApple();

  this->pickupBuffer.loadFromFile("Music/crunch.wav");
  this->pickupSound.setBuffer(this->pickupBuffer);
  this->pickupSound.setVolume(25.f);

  this->dieBuffer.loadFromFile("Music/died_sound_effect.wav");
  this->dieSound.setBuffer(this->dieBuffer);
  this->dieSound.setVolume(20.f);
}

GameScreen::~GameScreen() {}

void GameScreen::getSnakeSelfCol() {
  if (this->snake.checkSelfCol()) {
    dieSound.play();
    sf::sleep(sf::seconds(dieBuffer.getDuration().asSeconds()));
    this->over = true;
  }
}

void GameScreen::spawnApple() {
  this->apple.setPosition(
      static_cast<float>(SnakeNode::Size +
                         rand() %
                             static_cast<int>((Game::Width - SnakeNode::Size) /
                                              SnakeNode::Size) *
                             SnakeNode::Size),
      static_cast<float>(SnakeNode::Size +
                         rand() %
                             static_cast<int>((Game::Height - SnakeNode::Size) /
                                              SnakeNode::Size) *
                             SnakeNode::Size));
}

void GameScreen::updateLocApple() {
  do {
    this->wrongSpawnApple = false;

    for (auto& s : snake.getSnakeNodes()) {
      if (s.getGlobalBounds().intersects(this->apple.getGlobalBounds())) {
        this->spawnApple();

        this->wrongSpawnApple = true;

        break;
      }
    }
  } while (this->wrongSpawnApple);
}

void GameScreen::snakeGrow() {
  if (this->snake.getHeadBounds().intersects(this->apple.getGlobalBounds())) {
    this->snake.addSnakeNode();
    this->spawnApple();
    this->updateLocApple();

    this->score++;

    this->pickupSound.play();
  }
}

void GameScreen::render(sf::RenderWindow& window) {
  window.draw(this->apple);

  this->snake.render(window);
}

void GameScreen::update(sf::RenderWindow& window) {
  this->snake.update();

  this->snakeGrow();
  this->getSnakeSelfCol();
}