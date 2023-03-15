#pragma once

#include <vector>

#include "SFML/Audio.hpp"
#include "SnakeNode.h"

class Snake {
 public:
  Snake();
  ~Snake();

  const std::vector<SnakeNode>& getSnakeNodes() const;
  const sf::FloatRect getHeadBounds() const;

  void addSnakeNode();
  bool checkSelfCol();

  void render(sf::RenderTarget& target);
  void update();

 private:
  std::vector<SnakeNode> snake;

  size_t snakeSize = 2;

  static const int FrameSize = 40;

  void move();
  void updateTexture();
  void checkEdgeCol();

  bool isPosDifGreatZero(float pos1, float pos2);
};