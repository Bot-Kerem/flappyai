#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Window::Init(){
  glfwInit();
}

Window::Window(std::string title, int width, int height){

  // using opengl version 4.6
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // opengl version 4.x
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // opengl version x.6

  // using opengl compatibility profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

  // creates window
  m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  // setting window context current
  glfwMakeContextCurrent(m_Window);

  // loads opengl
  gladLoadGLLoader(GLADloadproc(glfwGetProcAddress));
}

bool Window::isOpen(){
  return !glfwWindowShouldClose(m_Window);
}

void Window::swapBuffers(){
  glfwSwapBuffers(m_Window);
}

void Window::destroy(){
  glfwDestroyWindow(m_Window);
}

void Window::PollEvents(){
  glfwPollEvents();
}

void Window::Terminate(){
  glfwTerminate();
}

double Window::GetTime(){
  return glfwGetTime();
}
