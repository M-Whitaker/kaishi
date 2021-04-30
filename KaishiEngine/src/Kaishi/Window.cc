//
// Created by Matt Whitaker on 24/03/2021.
//

#include "Window.h"

namespace Kaishi {

Window::Window(RenderAPI renderApi) {

  const char *description;
  //TODO(M-Whitaker): Setup platform specific shader folder
  switch (renderApi) {
    case RENDER_API_OPENGL:
    case RENDER_API_OPENGLES:shader = new OpenGLShaders("../../../assets/basic.glsl");
      break;
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
  m_VertexArray->remove();
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
  // build and compile our shader program
  // ------------------------------------
  shader->setup();

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] =
      {
          -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
          0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
          0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
          -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
          0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
          0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
      };

  // Indices for vertices order
  unsigned int indices[] =
      {
          0, 3, 5, // Lower left triangle
          3, 2, 4, // Lower right triangle
          5, 4, 1 // Upper triangle
      };

  m_VertexArray = new OpenGLVertexArray();
  m_VertexArray->bind();

  OpenGLVertexBuffer vertexBuffer = OpenGLVertexBuffer(vertices, sizeof(vertices));

  OpenGLIndexBuffer indexBuffer = OpenGLIndexBuffer(indices, sizeof(indices));

  m_VertexArray->linkVertexBuffer(vertexBuffer, 0);

  // unbind both buffers so we don't use them accidentally
  vertexBuffer.unbind();
  indexBuffer.unbind();
  m_VertexArray->unbind();

  Texture texture = OpenGLTexture("../../../assets/pig.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

  vertexBuffer.remove();
  indexBuffer.remove();
  // Check for openGL errors
  glCheckError();

  return 0;
}

void Window::show() {
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

}  // namespace Kaishi
