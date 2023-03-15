#include "SnakeNode.h"

#include "Game.h"

float SnakeNode::Size = 0.f;

SnakeNode::SnakeNode() { this->initVar(); }

SnakeNode::SnakeNode(sf::Vector2f position, sf::Texture& texture,
                     sf::IntRect frame)
    : position(position) {
  this->shape.setPosition(position);
  this->shape.setTexture(texture);
  this->shape.setTextureRect(frame);

  this->initVar();
}

SnakeNode::~SnakeNode() {}

void SnakeNode::initVar() {
  this->movementX = 0.f;
  this->movementY = 0.f;

  this->direction = MOVE::LEFT;
}

void SnakeNode::setPosition(sf::Vector2f position) {
  this->position = position;
  this->shape.setPosition(this->position);
}

void SnakeNode::setTextureRect(int left, int top, int size) {
  this->shape.setTextureRect(sf::IntRect(left, top, size, size));
}

void SnakeNode::setPosition(float x, float y) {
  this->position.x = x;
  this->position.y = y;
  this->shape.setPosition(this->position);
}

const sf::Sprite& SnakeNode::getShape() const { return this->shape; }

const sf::FloatRect SnakeNode::getGlobalBounds() const {
  return this->shape.getGlobalBounds();
}

const sf::Vector2f SnakeNode::getPosition() const { return this->position; }

const float SnakeNode::getMovementX() const { return this->movementX; }

const float SnakeNode::getMovementY() const { return this->movementY; }

void SnakeNode::move() { this->shape.move(this->movementX, this->movementY); }

void SnakeNode::move(float xOffset, float yOffset) {
  this->position.x += xOffset;
  this->position.y += yOffset;
  this->shape.setPosition(this->position);
}

void SnakeNode::updateInput() {
  if (!(this->getPosition().x < 0.f ||
        this->getPosition().x > Game::Width - SnakeNode::Size ||
        this->getPosition().y < 0.f ||
        this->getPosition().y > Game::Height - SnakeNode::Size)) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
        this->direction != MOVE::DOWN) {
      this->direction = MOVE::UP;

      this->movementX = 0.f;
      this->movementY = -SnakeNode::Size;
    } else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
               this->direction != MOVE::UP) {
      this->direction = MOVE::DOWN;

      this->movementX = 0.f;
      this->movementY = SnakeNode::Size;
    } else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
               this->direction != MOVE::RIGHT) {
      this->direction = MOVE::LEFT;

      this->movementX = -SnakeNode::Size;
      this->movementY = 0.f;
    } else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
               this->direction != MOVE::LEFT) {
      this->direction = MOVE::RIGHT;

      this->movementX = SnakeNode::Size;
      this->movementY = 0.f;
    }
  }
}

void SnakeNode::render(sf::RenderTarget& target) { target.draw(this->shape); }

void SnakeNode::update() {
  this->move(this->movementX, this->movementY);
  this->updateInput();
}