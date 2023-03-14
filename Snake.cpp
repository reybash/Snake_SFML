#include "Snake.h"

#include "Game.h"

Snake::Snake() {
  this->snake.push_back(SnakeNode(
      sf::Vector2f(Game::Width / 2.f, Game::Height / 2.f),
      *TextureStorage::textures["SNAKE"],
      sf::IntRect(TextureStorage::FrameSize * 4, TextureStorage::FrameSize,
                  TextureStorage::FrameSize, TextureStorage::FrameSize)));

  this->snake.push_back(SnakeNode(
      sf::Vector2f(Game::Width / 2.f + SnakeNode::Size, Game::Height / 2.f),
      *TextureStorage::textures["SNAKE"],
      sf::IntRect(0, TextureStorage::FrameSize, TextureStorage::FrameSize,
                  TextureStorage::FrameSize)));

  this->dieBuffer.loadFromFile("Music/died_sound_effect.wav");
  this->dieSound.setBuffer(this->dieBuffer);
  this->dieSound.setVolume(20.f);
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
    this->snake[0].setTextureRect(TextureStorage::FrameSize * 4,
                                  TextureStorage::FrameSize,
                                  TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[0].getPosition().x,
                                     this->snake[1].getPosition().x)) {
    this->snake[0].setTextureRect(TextureStorage::FrameSize * 4, 0,
                                  TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[1].getPosition().y,
                                     this->snake[0].getPosition().y)) {
    this->snake[0].setTextureRect(TextureStorage::FrameSize * 3, 0,
                                  TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(this->snake[0].getPosition().y,
                                     this->snake[1].getPosition().y)) {
    this->snake[0].setTextureRect(TextureStorage::FrameSize * 3,
                                  TextureStorage::FrameSize,
                                  TextureStorage::FrameSize);
  }

  if (this->isPosDifGreatZero(this->snake[snakeSize - 1].getPosition().x,
                              this->snake[snakeSize - 2].getPosition().x)) {
    this->snake[snakeSize - 1].setTextureRect(0, TextureStorage::FrameSize,
                                              TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 2].getPosition().x,
                 this->snake[snakeSize - 1].getPosition().x)) {
    this->snake[snakeSize - 1].setTextureRect(TextureStorage::FrameSize, 0,
                                              TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 1].getPosition().y,
                 this->snake[snakeSize - 2].getPosition().y)) {
    this->snake[snakeSize - 1].setTextureRect(0, 0, TextureStorage::FrameSize);
  } else if (this->isPosDifGreatZero(
                 this->snake[snakeSize - 2].getPosition().y,
                 this->snake[snakeSize - 1].getPosition().y)) {
    this->snake[snakeSize - 1].setTextureRect(TextureStorage::FrameSize,
                                              TextureStorage::FrameSize,
                                              TextureStorage::FrameSize);
  }

  for (size_t i = 1; i < snakeSize - 1; i++) {
    if (this->snake[i + 1].getPosition().x ==
        this->snake[i - 1].getPosition().x) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 2, 0,
                                    TextureStorage::FrameSize);
    } else if (this->snake[i + 1].getPosition().y ==
               this->snake[i - 1].getPosition().y) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 2,
                                    TextureStorage::FrameSize,
                                    TextureStorage::FrameSize);
    }

    if (this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                this->snake[i - 1].getPosition().x) &&
            this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                    this->snake[i + 1].getPosition().y) ||
        this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                this->snake[i - 1].getPosition().y) &&
            this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                    this->snake[i + 1].getPosition().x)) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 6,
                                    TextureStorage::FrameSize,
                                    TextureStorage::FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i - 1].getPosition().x,
                                       this->snake[i].getPosition().x) &&
                   this->isPosDifGreatZero(
                       this->snake[i].getPosition().y,
                       this->snake[i + 1].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i].getPosition().y,
                                       this->snake[i - 1].getPosition().y) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().x,
                                           this->snake[i].getPosition().x)) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 5, 0,
                                    TextureStorage::FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i].getPosition().x,
                                       this->snake[i - 1].getPosition().x) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().y,
                                           this->snake[i].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i - 1].getPosition().y,
                                       this->snake[i].getPosition().y) &&
                   this->isPosDifGreatZero(
                       this->snake[i].getPosition().x,
                       this->snake[i + 1].getPosition().x)) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 6, 0,
                                    TextureStorage::FrameSize);
    } else if (this->isPosDifGreatZero(this->snake[i - 1].getPosition().x,
                                       this->snake[i].getPosition().x) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().y,
                                           this->snake[i].getPosition().y) ||
               this->isPosDifGreatZero(this->snake[i - 1].getPosition().y,
                                       this->snake[i].getPosition().y) &&
                   this->isPosDifGreatZero(this->snake[i + 1].getPosition().x,
                                           this->snake[i].getPosition().x)) {
      this->snake[i].setTextureRect(TextureStorage::FrameSize * 5,
                                    TextureStorage::FrameSize,
                                    TextureStorage::FrameSize);
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
      dieSound.play();
      sf::sleep(sf::seconds(dieBuffer.getDuration().asSeconds()));
      return true;
    }
  }

  return false;
}

void Snake::clear() { this->~Snake(); }

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