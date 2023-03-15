#include "Snake.h"

#include "Game.h"

Snake::Snake() {
  SnakeNode::Size = FrameSize;

  auto result = TextureStorage::getTexture("snake");

  if (result) {
    this->snake.push_back(SnakeNode(
        sf::Vector2f(Game::Width / 2.f, Game::Height / 2.f), *result.get(),
        sf::IntRect(FrameSize * 4, FrameSize, FrameSize, FrameSize)));

    this->snake.push_back(SnakeNode(
        sf::Vector2f(Game::Width / 2.f + SnakeNode::Size, Game::Height / 2.f),
        *result.get(), sf::IntRect(0, FrameSize, FrameSize, FrameSize)));
  }
}

Snake::~Snake() {}

const std::vector<SnakeNode>& Snake::getSnakeNodes() const {
  return this->snake;
}

const sf::FloatRect Snake::getHeadBounds() const {
  return this->snake[0].getShape().getGlobalBounds();
}

void Snake::addSnakeNode() {
  this->snake.push_back(this->snake[snakeSize - 1]);

  snakeSize++;
}

void Snake::move() {
  sf::sleep(sf::Time(sf::seconds(3.f / 30.f)));

  if (this->snake[0].getMovementX() != 0 ||
      this->snake[0].getMovementY() != 0) {
    for (auto i = snakeSize - 1; i > 0; --i) {
      this->snake[i].setPosition(this->snake[i - 1].getPosition());
    }
  }
}

bool Snake::isPosDifGreatZero(float pos1, float pos2) {
  return pos1 - pos2 > 0;
}

void Snake::updateTexture() {
  if (this->isPosDifGreatZero(this->snake[1].getPosition().x,
                              this->snake[0].getPosition().x)) {
    this->snake[0].setTextureRect(FrameSize * 4, FrameSize, FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[0].getPosition().x,
                                     this->snake[1].getPosition().x)) {
    this->snake[0].setTextureRect(FrameSize * 4, 0, FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[1].getPosition().y,
                                     this->snake[0].getPosition().y)) {
    this->snake[0].setTextureRect(FrameSize * 3, 0, FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[0].getPosition().y,
                                     this->snake[1].getPosition().y)) {
    this->snake[0].setTextureRect(FrameSize * 3, FrameSize, FrameSize);
  }

  if (this->isPosDifGreatZero(this->snake[snakeSize - 1].getPosition().x,
                              this->snake[snakeSize - 2].getPosition().x)) {
    this->snake[snakeSize - 1].setTextureRect(0, FrameSize, FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 2].getPosition().x,
                 this->snake[snakeSize - 1].getPosition().x)) {
    this->snake[snakeSize - 1].setTextureRect(FrameSize, 0, FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 1].getPosition().y,
                 this->snake[snakeSize - 2].getPosition().y)) {
    this->snake[snakeSize - 1].setTextureRect(0, 0, FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 2].getPosition().y,
                 this->snake[snakeSize - 1].getPosition().y)) {
    this->snake[snakeSize - 1].setTextureRect(FrameSize, FrameSize, FrameSize);
  }

  for (size_t i = 1; i < snakeSize - 1; i++) {
    if (this->snake[i + 1].getPosition().x ==
        this->snake[i - 1].getPosition().x) {
      this->snake[i].setTextureRect(FrameSize * 2, 0, FrameSize);
    } else if (this->snake[i + 1].getPosition().y ==
               this->snake[i - 1].getPosition().y) {
      this->snake[i].setTextureRect(FrameSize * 2, FrameSize, FrameSize);
    }

    if (this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                this->snake[i - 1].getPosition().x) &&
            this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                    this->snake[i + 1].getPosition().y) ||
        this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                this->snake[i - 1].getPosition().y) &&
            this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                    this->snake[i + 1].getPosition().x)) {
      this->snake[i].setTextureRect(FrameSize * 6, FrameSize, FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i - 1].getPosition().x,
                                       this->snake[i].getPosition().x) &&
                   this->isPosDifGreatZero(
                       this->snake[i].getPosition().y,
                       this->snake[i + 1].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                       this->snake[i - 1].getPosition().y) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().x,
                                           this->snake[i].getPosition().x)) {
      this->snake[i].setTextureRect(FrameSize * 5, 0, FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                       this->snake[i - 1].getPosition().x) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().y,
                                           this->snake[i].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i - 1].getPosition().y,
                                       this->snake[i].getPosition().y) &&
                   this->isPosDifGreatZero(
                       this->snake[i].getPosition().x,
                       this->snake[i + 1].getPosition().x)) {
      this->snake[i].setTextureRect(FrameSize * 6, 0, FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i - 1].getPosition().x,
                                       this->snake[i].getPosition().x) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().y,
                                           this->snake[i].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i - 1].getPosition().y,
                                       this->snake[i].getPosition().y) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().x,
                                           this->snake[i].getPosition().x)) {
      this->snake[i].setTextureRect(FrameSize * 5, FrameSize, FrameSize);
    }
  }
}

void Snake::checkEdgeCol() {
  if (this->snake[0].getPosition().x < 0.f - SnakeNode::Size) {
    this->snake[0].setPosition(Game::Width, this->snake[0].getPosition().y);
  } else if (this->snake[0].getPosition().x > Game::Width) {
    this->snake[0].setPosition(0 - SnakeNode::Size,
                               this->snake[0].getPosition().y);
  } else if (this->snake[0].getPosition().y < 0.f - SnakeNode::Size) {
    this->snake[0].setPosition(this->snake[0].getPosition().x, Game::Height);
  } else if (this->snake[0].getPosition().y > Game::Height) {
    this->snake[0].setPosition(this->snake[0].getPosition().x,
                               0.f - SnakeNode::Size);
  }
}

bool Snake::checkSelfCol() {
  for (size_t i = 2; i < snakeSize; i++) {
    if (this->snake[0].getGlobalBounds().intersects(
            this->snake[i].getGlobalBounds())) {
      return true;
    }
  }

  return false;
}

void Snake::render(sf::RenderTarget& target) {
  for (auto& s : this->snake) {
    target.draw(s.getShape());
  }
}

void Snake::update() {
  this->move();
  this->snake[0].update();

  this->checkEdgeCol();
  this->updateTexture();
}