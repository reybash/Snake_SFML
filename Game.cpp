#include "Game.h"
#include "StartScreen.h"

int Game::HighScore = 0;

std::unique_ptr<Screen> Game::screen = std::make_unique<StartScreen>();

Game::Game()
{
	this->initWindow();

	this->music.openFromFile("Music/chill_drum_loop.wav");
	this->music.setLoop(true);
	this->music.play();
	this->music.setVolume(5.f);
}

Game::~Game()
{
}

void Game::initWindow()
{
	this->videoMode.height = this->Height;
	this->videoMode.width = this->Width;

	this->window.create(this->videoMode, "SNAKE!");

	this->backGround.setTexture(TextureStorage::textures["BG"]);
	this->backGround.setSize(sf::Vector2f(this->Width, this->Height));

	//this->window.setFramerateLimit(75);
}

void Game::updateEvents()
{
	while (this->window.pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window.close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window.close();
			break;
		}
	}
}

const bool Game::getWindiowIsOpen() const
{
	return this->window.isOpen();
}

void Game::render()
{
	this->window.clear();
	this->window.draw(this->backGround);

	Game::screen->render(this->window);

	this->window.display();
}

void Game::update()
{
	this->updateEvents();
	Game::screen->update(this->window);
}

void Game::run()
{
	//sf::Clock clock;
	//float timeSinceLastUpdate = 0.f;

	//float timePerFrame = 1.f / 30.f;

	//float delta = clock.restart().asSeconds();
	//timeSinceLastUpdate += delta;

	//while (timeSinceLastUpdate > timePerFrame)
	//{
	//	timeSinceLastUpdate -= timePerFrame;
	//	this->update();
	//}

	this->update();

	this->render();
}