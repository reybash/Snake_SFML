#pragma once

#include "Screen.h"

class GameOverScreen : public Screen {
 public:
  GameOverScreen(int score);
  ~GameOverScreen();

  void update(sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override;

 private:
};
