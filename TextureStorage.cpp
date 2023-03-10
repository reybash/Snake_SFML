#include "TextureStorage.h"

sf::Texture* TextureStorage::snakeTexture = new sf::Texture();
sf::Texture* TextureStorage::appleTexture = new sf::Texture();
sf::Texture* TextureStorage::backgroundTexture = new sf::Texture();

std::map<std::string, sf::Texture*> TextureStorage::textures{
	{"APPLE",  TextureStorage::appleTexture},
	{"SNAKE",TextureStorage::snakeTexture},
	{"BG",TextureStorage::backgroundTexture} };


TextureStorage::TextureStorage()
{
	this->snakeTexture->loadFromFile("Textures/tilemap.png");
	this->appleTexture->loadFromFile("Textures/small_apple.png");
	this->backgroundTexture->loadFromFile("Textures/grass_1.png");
}

TextureStorage::~TextureStorage()
{
	for (auto& t : this->textures) {
		delete t.second;
	}
}

sf::Texture* TextureStorage::getTextue()
{
	return this->appleTexture;
}
