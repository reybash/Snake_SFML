#include "Apple.h"
#include "Game.h"


Apple::Apple()
{
	this->apple.setRadius(SnakeNode::Size / 2.f);
}

Apple::Apple(Snake& snake, std::vector<Apple>& apples)
{
	this->apple.setTexture(TextureStorage::textures["APPLE"]);

	this->apple.setRadius(SnakeNode::Size / 2.5f);
	this->apple.setScale(1.f, 1.f);
	
	this->spawnApple();
	this->fixWrongLocApple(snake, apples);
}

Apple::~Apple()
{

}

const sf::CircleShape& Apple::getShape() const
{
	return this->apple;
}

const sf::FloatRect Apple::getGlobalBounds() const
{
	return this->apple.getGlobalBounds();
}

void Apple::fixWrongLocApple(Snake& snake, std::vector<Apple>& apples)
{
	do {
		this->wrongSpawnApple = false;

		for (auto& s : snake.getSnakeNodes()) {
			if (s.getGlobalBounds().intersects(this->apple.getGlobalBounds())) {
				this->spawnApple();
				std::cout << "snake" << std::endl;

				this->wrongSpawnApple = true;

				break;
			}
		}

		for (auto& a : apples) {
			if (a.getGlobalBounds().intersects(this->apple.getGlobalBounds())) {
				this->spawnApple();
				std::cout << "apple" << std::endl;

				this->wrongSpawnApple = true;

				break;
			}
		}
	} while (wrongSpawnApple);
}

void Apple::spawnApple()
{
	this->apple.setPosition(
		static_cast<float>(SnakeNode::Size + rand() % static_cast<int>((
				Game::Width - SnakeNode::Size * 2.f) / SnakeNode::Size) * SnakeNode::Size),
		static_cast<float>(SnakeNode::Size + rand() % static_cast<int>((
				Game::Height - SnakeNode::Size * 2.f) / SnakeNode::Size) * SnakeNode::Size));
}

void Apple::render(sf::RenderTarget& target)
{
	target.draw(this->apple);
}