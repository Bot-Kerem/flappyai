#include <iostream>

#include "game.h"

int main(int argc, char const *argv[]) {

  Game::Init();

  Game game{};

  game.build();
  game.run();

  std::cout << "Hello Bird!" << std::endl;
  return 0;
}
