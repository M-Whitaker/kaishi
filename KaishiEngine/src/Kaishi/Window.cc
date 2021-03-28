//
// Created by Matt Whitaker on 24/03/2021.
//

#include "Window.h"

namespace Kaishi {

Window::Window() {

  const char* description;
  
  if (!glfwInit()) {
    glfwGetError(&description);
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef KAI_MACOS
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
  
  glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, NULL, &height);
}

Window::~Window() {

  // glfw: terminate, clearing all previously allocated GLFW resources.

  glfwTerminate();
}

int Window::create(const char *windowName, int i) {
  
  const char* description;
  const int size = height / 5;
  
  if (i > 0)
    glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
  
  window = glfwCreateWindow(size, size, windowName, nullptr, nullptr);
  
  if (!window) {
    glfwGetError(&description);
    printf("Error: %s\n", description);
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwSetWindowPos(window,
              xpos + size * (1 + (i & 1)),
              ypos + size * (1 + (i >> 1)));
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

  glfwMakeContextCurrent(window);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    puts("Failed to initialize GLAD");
    return -1;
  }

#ifdef KAI_MACOS
  windowInfo = OBJC_API(createCocoaWindow)(window);
  if (windowInfo.darkMode)
    glClearColor(0, 0, 0, 1);
  else
    glClearColor(255, 255, 255, 1);
#endif

  return 0;
}

void Window::show() {
  glfwShowWindow(window);
}

GLFWwindow *Window::getGLFWWindow() {
  return this->window;
}

}  // namespace Kaishi
