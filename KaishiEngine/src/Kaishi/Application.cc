//
// Created by Matt Whitaker on 28/02/2021.
//

#include <kaipch.h>

#include "Application.h"

namespace Kaishi {

KaishiApplication::KaishiApplication(char *name, float version, RenderAPI renderApi)
    : m_name(name), m_version(version), m_RenderApi(renderApi) {}

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
