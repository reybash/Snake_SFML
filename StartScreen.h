#pragma once

#include "Screen.h"

class StartScreen : public Screen {
 public:
  StartScreen();
  ~StartScreen() override;

  void update(sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override;

 private:
  sf::Text snakeText;
};