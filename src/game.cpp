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

    pipemanager.move(deltaTime);
    bird.move(deltaTime);

    draw();

    if(pipemanager.checkCollision(bird)){
      //std::cout << "Hit" << "\n";
    }

    Pipe& pipe = pipemanager.getClosest(bird);
    auto Predict = bird.Brain.predict({
      1.0f -(pipe.Height + pipe.PipeSpace),
      1.0f - pipe.Height,
      (pipe.Width + pipe.position) - bird.xPosition,
      bird.yPosition,
      bird.Velocity});

      if(Predict[0] < Predict[1]){
        bird.jump();
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
