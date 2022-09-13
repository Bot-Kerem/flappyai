#ifndef PIPE_MANAGER_H
#define PIPE_MANAGER_H

#include "pipe.h"
#include "shader.h"
#include "bird.h"

#include <vector>

class PipeManager{
  private:
    //std::vector<Pipe> m_Pipes;
    Shader m_Shader{"./../shaders/pipe.vs", "./../shaders/pipe.fs"};
    std::vector<Pipe*> pipes = {new Pipe()};

    unsigned int uniformVarSize{0};
    unsigned int uniformVarPosition{0};

    float pipeTimer = 0.0f;
  public:
    PipeManager();

    float pipeSpeed = -0.4f;
    float pipeGap = 0.7f;

    void move(float deltaTime);
    void drawPipes();

    bool checkCollision(Bird& bird);
}; // class PipeManager

#endif // PIPE_MANAGER_H
