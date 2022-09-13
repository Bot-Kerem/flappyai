#ifndef WINDOW_H
#define WINDOW_H

#include <string>

struct GLFWwindow;

class Window{
  private:
    GLFWwindow* m_Window;
  public:
    // Window constructor
    Window(std::string title, int width, int height);

    // Returns true if is open
    bool isOpen();

    // Swaps back and front buffers
    void swapBuffers();

    // Destroys window
    void destroy();

    // Processes Window/Mouse/Keyboard events
    static void PollEvents();

    // Initializes GLFW
    static void Init();

    // Terminates GLFW
    static void Terminate();
}; // class Window

#endif // WINDOW_H
