#pragma once

#include "SFML/Graphics.hpp"

enum MOVE { LEFT = 0, DOWN, UP, RIGHT };

class SnakeNode {
 public:
  SnakeNode();
  SnakeNode(sf::Vector2f position, sf::Texture& texture, sf::IntRect frame);
  ~SnakeNode();

  static float Size;

  void move();
  void move(float xOffset, float yOffset);
  void setPosition(float x, float y);
  void setPosition(sf::Vector2f position);
  void setTextureRect(int left, int top, int size);

  const sf::Sprite& getShape() const;
  const sf::FloatRect getGlobalBounds() const;
  const sf::Vector2f getPosition() const;
  const float getMovementX() const;
  const float getMovementY() const;

  void render(sf::RenderTarget& target);
  void update();

 private:
  sf::Sprite shape;

  short direction;

  float movementX;
  float movementY;

  sf::Vector2f position;

  void initVar();
  void updateInput();
};