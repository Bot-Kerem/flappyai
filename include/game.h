#ifndef GAME_H
#define GAME_H

#include "window.h"

#include <string>

class Game{
  private:
    const int Width = 800;
    const int Height = 600;
    const std::string Title = "Flappy Ai";

    Window window{Title, Width, Height};

  public:
    // Game constructor
    Game() = default;
    // Game destructor
    ~Game();

    // Runs game
    void run();
    // Prepares game
    void build();
    // Draws scene
    void draw();

    static void Init();
}; // class Game

#endif // GAME_H
