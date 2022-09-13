#ifndef PIPE_H
#define PIPE_H

class Pipe{
  private:
    const MaxHeight = 0;
    const float Width = 0.1f;
  public:
    Pipe() = default;

    float Height;
    float position; // only x position we don't need y position
}

#endif // PIPE_H
