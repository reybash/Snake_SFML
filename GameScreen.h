#pragma once

#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "Snake.h"

class GameScreen : public Screen {
 public:
  GameScreen();
  ~GameScreen();

  static int HighScore;
  static int score;

  void render(sf::RenderWindow& window) override;
  void update(sf::RenderWindow& window) override;

 private:
  Snake snake;
  sf::Sprite apple;

  sf::SoundBuffer pickupBuffer;
  sf::Sound pickupSound;

  sf::SoundBuffer dieBuffer;
  sf::Sound dieSound;

  bool wrongSpawnApple = false;

  void getSnakeSelfCol();

  void spawnApple();
  void updateLocApple();

  void snakeGrow();
};