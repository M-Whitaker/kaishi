//
// Created by Matt Whitaker on 28/02/2021.
//

#include <kaipch.h>

#include "Application.h"

namespace Kaishi {

KaishiApplication::KaishiApplication(char *name, float version, RenderAPI renderApi)
    : m_name(name), m_version(version), m_RenderApi(renderApi) {
    if (renderApi == RENDER_API_OPENGL) {
      glfwInit();
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  #ifdef KAI_MACOS
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
  #endif

#ifdef KAISHI_DEBUG
      glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

      // Create a dummy openGL Context to check compatibility and then delete
      glfwMakeContextCurrent(glfwCreateWindow(1, 1, "", nullptr, nullptr));

      // glad: load all OpenGL function pointers
      // ---------------------------------------
      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        const char *errorDescription;
        glfwGetError(&errorDescription);
        printf("Failed to initialize GLAD\n GLFW ERROR: %s\n", errorDescription);
        exit(EXIT_FAILURE);
      }
      // Get max number of texture slots for GPU
      int textureUnits;
      glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);

      int glMajor, glMinor;
      glGetIntegerv(GL_MAJOR_VERSION, &glMajor);
      glGetIntegerv(GL_MINOR_VERSION, &glMinor);

      printf("OpenGL Version %d.%d Max Texture Units: %d\n", glMajor, glMinor, textureUnits);
      glfwTerminate();
    } else if (renderApi == RENDER_API_VULKAN) {
      //TODO(M-Whitaker): Vulkan application setup
      throw std::logic_error("Vulkan not implemented!");
    }
  }

int KaishiApplication::setup(unsigned int noOfWindows) {
  for (int i = 0; i < noOfWindows; i++) {
    Window *window = new Window(m_RenderApi);
    char buffer[50];
    sprintf((char *) (&buffer), "Window %d", i + 1);
    window->create(buffer, i);
    windows.push_back(window);
  }
  return 0;
}
int KaishiApplication::run() {
  for (auto &window : windows)
    window->show();
  while (true) {
    for (auto it = windows.begin(); it != windows.end();) {
      (*it)->render();
      if (glfwWindowShouldClose((*it)->getGLFWWindow())) {
        delete (*it);
        it = windows.erase(it);
        if (windows.empty()) {
          glfwTerminate();
          return EXIT_SUCCESS;
        }
      } else {
        ++it;
      }
    }
  }
}
void KaishiApplication::pushView(Window *window, View *view) {
  // TODO(M-Whitaker): Check if window is valid for said application
  window->pushView(view);
}
}  // namespace Kaishi
