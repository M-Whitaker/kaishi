//
// Created by Matt Whitaker on 24/03/2021.
//

#include "Window.h"

namespace Kaishi {

Window::Window(RenderAPI renderApi)
: m_ViewHierarchy(new ViewHierarchy()) {
  const char *description;
  // TODO(M-Whitaker): Setup platform specific shader folder
  switch (renderApi) {
    case RENDER_API_OPENGL:
    case RENDER_API_OPENGLES:break;
    case RENDER_API_VULKAN:break;
    case RENDER_API_DIRECT3D11:break;
    case RENDER_API_DIRECT3D12:break;
  }
  glfwSetErrorCallback(errorCallback);
  if (!glfwInit()) {
    glfwGetError(&description);
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
  }
#ifdef KAI_MACOS
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#endif
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, nullptr, &height);
}

Window::~Window() {
  for (View *view : m_ViewHierarchy->getViews()) {
    view->onDetach();
  }
  glfwDestroyWindow(window);
}

void Window::errorCallback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

int Window::create(const char *windowName, int i) {
  const char *description;
  size = height / 4;

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
  glfwSetKeyCallback(window, keyCallback);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

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
  glfwMakeContextCurrent(window);
  for (View *view : m_ViewHierarchy->getViews()) {
    view->onAttach();
  }
  glfwShowWindow(window);
}

GLFWwindow *Window::getGLFWWindow() {
  return this->window;
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
  else if (action == GLFW_PRESS)
    printf("You pressed: %s \n", glfwGetKeyName(key, scancode));
}

void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width and
  // height will be significantly larger than specified on retina displays.
  glfwMakeContextCurrent(window);
  glViewport(0, 0, width, height);
}
void Window::swapBuffers() {
  glfwSwapBuffers(window);
}
void Window::pushView(View *view) {
  m_ViewHierarchy->addView(view);
}
void Window::render() {
  glfwMakeContextCurrent(window);
  for (View *view : m_ViewHierarchy->getViews()) {
    view->renderLoop();
  }
  swapBuffers();
  glfwPollEvents();
}

}  // namespace Kaishi
