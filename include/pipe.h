#ifndef PIPE_H
#define PIPE_H

class Pipe{
  public:
    Pipe();
    ~Pipe();

    const float MinHeight = 0.2;
    const float MinPipeSpace = 0.4f;
    const float MaxPipeSpace = 0.6f;

    const float Width = 0.15f;


    float Height{0};
    float PipeSpace{0};

    float position = 1.0f; // only x position we don't need y position
}; // class Pipe

#endif // PIPE_H
