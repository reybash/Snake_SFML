#include "TextureStorage.h"

const std::string TextureStorage::prefix = "Textures/";
const std::string TextureStorage::postfix = ".png";

std::map<std::string, std::shared_ptr<sf::Texture>> TextureStorage::textures;

std::shared_ptr<sf::Texture> TextureStorage::getTexture(
    const std::string_view name) {
  const auto it = textures.find(name.data());

  if (it != textures.end()) {
    return it->second;
  }

  if (load(name)) {
    return getTexture(name);
  }

  return nullptr;
}

bool TextureStorage::load(const std::string_view name) {
  std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

  const bool result = texture->loadFromFile(prefix + name.data() + postfix);

  if (result) {
    textures.emplace(name, texture);
  }

  return result;
}