#include "Game.h"

#include "GameOverScreen.h"
#include "GameScreen.h"
#include "StartScreen.h"

std::unique_ptr<Screen> Game::screen = std::make_unique<StartScreen>();

Game::Game() {
  this->initWindow();

  this->changeState = 0;

  this->music.openFromFile("Music/chill_drum_loop.wav");
  this->music.setLoop(true);
  this->music.play();
  this->music.setVolume(5.f);
}

Game::~Game() {}

void Game::initWindow() {
  this->videoMode.height = this->Height;
  this->videoMode.width = this->Width;

  this->window.create(this->videoMode, "SNAKE!");

  auto result = TextureStorage::getTexture("grass");

  if (result) {
    this->backGround.setTexture(result.get());
  }

  this->backGround.setSize(sf::Vector2f(this->Width, this->Height));
}

void Game::updateEvents() {
  while (this->window.pollEvent(this->event)) {
    switch (this->event.type) {
      case sf::Event::Closed:
        this->window.close();
        break;
      case sf::Event::KeyPressed:
        if (this->event.key.code == sf::Keyboard::Escape) this->window.close();
        break;
    }
  }
}

const bool Game::getWindiowIsOpen() const { return this->window.isOpen(); }

void Game::render() {
  this->window.clear(sf::Color::Black);
  this->window.draw(this->backGround);

  Game::screen->render(this->window);

  this->window.display();
}

void Game::update() {
  this->updateEvents();

  if (screen.get()->isOver()) {
    switch (changeState) {
      case STATE::MAINGAME:
        screen = std::make_unique<GameScreen>();
        ++this->changeState;
        break;
      case STATE::GAMEOVER:
        screen = std::make_unique<GameOverScreen>(GameScreen::score);
        --this->changeState;
        break;
      default:
        break;
    }
  }

  Game::screen->update(this->window);
}

void Game::run() {
  this->update();
  this->render();
}