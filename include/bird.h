#ifndef BIRD_H
#define BIRD_H

#include "shader.h"

class Bird{
  private:
    Shader m_Shader{"./../shaders/bird.vs", "./../shaders/bird.fs"};

    unsigned int uniformVarSize{0};
    unsigned int uniformVarPosition{0};
  public:
    Bird();
    const float Size = 0.075f;
    float Velocity = 0.0f;

    const float xPosition = -0.8f;
    float yPosition = 0.0f;

    void jump();
    void draw();

    void move(float deltaTime);
};

#endif // BIRD_H
