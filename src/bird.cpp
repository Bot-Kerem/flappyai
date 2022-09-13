#include "bird.h"

#include <glad/glad.h>

const float gravity = -5.0f;

Bird::Bird(){
  uniformVarSize = m_Shader.getLocation("size");
  uniformVarPosition = m_Shader.getLocation("position");
}

void Bird::draw(){
  m_Shader.use();

  m_Shader.setVec2(uniformVarSize, Size, Size);
  m_Shader.setVec2(uniformVarPosition, xPosition, yPosition);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Bird::jump(){
  Velocity = 1.5f;
}

void Bird::move(float deltaTime){
  Velocity += deltaTime * gravity;
  yPosition += deltaTime * Velocity;
}
