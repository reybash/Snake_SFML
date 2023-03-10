#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureStorage {
 public:
  TextureStorage();
  ~TextureStorage();

  static std::map<std::string, sf::Texture*> textures;

  static const int FrameSize = 40;

 private:
  static sf::Texture* snakeTexture;
  static sf::Texture* appleTexture;
  static sf::Texture* backgroundTexture;

  sf::Texture* getTextue();
};