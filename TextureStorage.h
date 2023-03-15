#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>
#include <string_view>

class TextureStorage {
 public:
  static std::shared_ptr<sf::Texture> getTexture(const std::string_view name);

 private:
  static bool load(const std::string_view name);

  static std::map<std::string, std::shared_ptr<sf::Texture>> textures;

  static const std::string prefix;
  static const std::string postfix;
};