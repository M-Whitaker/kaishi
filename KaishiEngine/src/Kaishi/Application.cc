//
// Created by Matt Whitaker on 28/02/2021.
//

#include <kaipch.h>

#include "Application.h"

namespace Kaishi {

KaishiApplication::KaishiApplication(char *name, float version, RenderAPI renderApi)
    : m_name(name), m_version(version), m_RenderApi(renderApi) {}
int KaishiApplication::setup() {
  int NO_OF_WINDOWS = 4;

  for (int i = 0; i < NO_OF_WINDOWS; i++) {
    Window *window = new Window(m_RenderApi);
    char buffer[50];
    sprintf((char *) (&buffer), "Window %d", i + 1);
    window->create(buffer, i);
    windows.push_back(window);
  }

  if (m_RenderApi == RENDER_API_OPENGL) {
    //Load openGL and create buffers
//    Renderer renderer = OpenGLRenderer();
  }

  for (auto &window : windows)
    window->show();
  while (true) {
    for (auto it = windows.begin(); it != windows.end();) {
      renderLoop((*it));
      if (glfwWindowShouldClose((*it)->getGLFWWindow())) {
        delete (*it);
        it = windows.erase(it);
        if (windows.empty()) {
          glfwTerminate();
          exit(EXIT_SUCCESS);
        }
      } else {
        ++it;
      }
    }
  }
}
}  // namespace Kaishi
