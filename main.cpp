#include "Game.h"

int main() {
  std::srand(static_cast<unsigned>(time(NULL)));

  Game game;

  while (game.getWindiowIsOpen()) {
    game.run();
  }

  return 0;
}