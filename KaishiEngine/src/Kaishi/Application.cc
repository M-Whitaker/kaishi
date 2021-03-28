//
// Created by Matt Whitaker on 28/02/2021.
//

#include "Application.h"

namespace Kaishi {

KaishiApplication::KaishiApplication(char *name, float version)
    : m_name(name), m_version(version) {}

int KaishiApplication::mainLoop() {
  
  for (int i = 0;  i < 4;  i++) {
    Window *window = new Window();
    char buffer [50];
    sprintf((char*)(&buffer), "Window %d", i + 1);
    window->create(buffer, i);
    windows.push_back(window);
  }
  
  for (auto & window : windows)
    window->show();

  // render loop
  // -----------
  for (;;) {
    for (int i = 0;  i < 4;  i++) {
      glfwMakeContextCurrent(windows[i]->getGLFWWindow());
      glClear(GL_COLOR_BUFFER_BIT);
      glfwSwapBuffers(windows[i]->getGLFWWindow());

      const struct
      {
        float r, g, b;
      } colors[] =
          {
              { 0.95f, 0.32f, 0.11f },
              { 0.50f, 0.80f, 0.16f },
              {   0.f, 0.68f, 0.94f },
              { 0.98f, 0.74f, 0.04f }
          };

      // colors[i].r, colors[i].g, colors[i].b, 1.f

      if (glfwWindowShouldClose(windows[i]->getGLFWWindow()) ||
        glfwGetKey(windows[i]->getGLFWWindow(), GLFW_KEY_ESCAPE)) {

        glfwTerminate();
        exit(EXIT_SUCCESS);
      }
    }

    glfwWaitEvents();
  }
  return 0;
}

}  // namespace Kaishi
