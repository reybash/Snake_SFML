#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "TextureStorage.h"

enum STATE { MAINGAME = 0, GAMEOVER };

class Game {
 public:
  Game();
  ~Game();

  static const int Width = 1200;
  static const int Height = 800;

  static std::unique_ptr<Screen> screen;

  const bool getWindiowIsOpen() const;

  void run();

 private:
  sf::RenderWindow window;
  sf::VideoMode videoMode;
  sf::Event event;

  sf::Music music;

  sf::RectangleShape backGround;

  short changeState;

  void initWindow();

  void updateEvents();

  void render();
  void update();
};