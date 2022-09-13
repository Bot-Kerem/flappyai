#include "pipemanager.h"

#include <glad/glad.h>

#include <iostream>

void PipeManager::drawPipes(){
  m_Shader.use();
  for(auto& pipe: pipes){
    m_Shader.setVec2(uniformVarSize, pipe->Width, pipe->Height);
    m_Shader.setVec2(uniformVarPosition, pipe->position, 0.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    m_Shader.setVec2(uniformVarSize, pipe->Width, 2.0f - (pipe->Height + pipe->PipeSpace));
    m_Shader.setVec2(uniformVarPosition, pipe->position, -(pipe->Height + pipe->PipeSpace));
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  }
}

PipeManager::PipeManager(){
  uniformVarSize = m_Shader.getLocation("size");
  uniformVarPosition = m_Shader.getLocation("position");
}

void PipeManager::move(float deltaTime){
  for(auto& pipe: pipes){
    pipe->position += pipeSpeed * deltaTime;
  }

  pipeTimer -= pipeSpeed * deltaTime;
  if(pipeTimer >= pipeGap){
    pipeTimer = 0;
    pipes.push_back(new Pipe());
  }
  if(pipes[0]->position < -1.0f - pipes[0]->Width){
    delete pipes[0];
    pipes.erase(pipes.begin());
  }
}

bool PipeManager::checkCollision(Bird& bird){
  return (bird.xPosition > pipes[0]->position && bird.xPosition < (pipes[0]->position + pipes[0]->Width) && (bird.yPosition >= 1.0f - pipes[0]->Height || bird.yPosition <= 1.0f -(pipes[0]->Height + pipes[0]->PipeSpace)));
}
