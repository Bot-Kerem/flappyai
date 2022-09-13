#include "game.h"

#include <glad/glad.h>

#include <iostream>

void Game::draw(){
  glClear(GL_COLOR_BUFFER_BIT);

  pipemanager.drawPipes();
  bird.draw();
}

void Game::Init(){
  Window::Init();
}

void Game::run(){
  while (window.isOpen()) {
    Window::PollEvents();
    deltaTime = Window::GetTime() - lastTime;
    lastTime = Window::GetTime();

    if(window.isPressedSpace()){
      bird.jump();
    }

    pipemanager.move(deltaTime);
    bird.move(deltaTime);

    draw();

    if(pipemanager.checkCollision(bird)){
      std::cout << "Hit" << "\n";
    }


    window.swapBuffers();
  }
}


void Game::build(){
  // Channels: Red   Green   Blue   Alpha
  glClearColor(1.0f, 1.0f,   1.0f,  1.0f); // White

  // enable transparency
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Game::~Game(){
  // Destroy window
  window.destroy();
  Window::Terminate();
}
