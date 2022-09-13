#include "game.h"

#include <glad/glad.h>

void Game::draw(){
  glClear(GL_COLOR_BUFFER_BIT);
}

void Game::Init(){
  Window::Init();
}

void Game::run(){
  while (window.isOpen()) {
    Window::PollEvents();

    draw();
    window.swapBuffers();
  }
}


void Game::build(){
  //           Red   Green   Blue   Alpha
  glClearColor(1.0f, 1.0f,   1.0f,  1.0f); // White
}

Game::~Game(){

  // Destroy window
  window.destroy();
  Window::Terminate();
}
