//
// Created by Matt Whitaker on 28/02/2021.
//

#include <iostream>
#include <unistd.h>

#include <Kaishi/Kaishi.h>
#include "main.h"

int Application::renderLoop(Kaishi::Window* window) {

  Kaishi::Log* log = Kaishi::Log::GetInstance(Kaishi::LOGGING_LEVEL_DEBUG);
//  log->debug("Application Initialised, starting render loop...\n");

  glfwMakeContextCurrent(window->getGLFWWindow());

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  window->shader->use();
  float currentTime = (float) glfwGetTime();
  float RedValue = sin(currentTime + 3) / 2.0f + 0.5f;
  float greenValue = sin(currentTime + 2) / 2.0f + 0.5f;
  float blueValue = sin(currentTime + 1) / 2.0f + 0.5f;
  window->shader->setVec4("ourColour", RedValue, greenValue, blueValue, 1.0f);
  glm::mat4 transform = glm::mat4(1.0f);
  // identity matrix, speed, rotation (x, y, z)
  transform = glm::rotate(transform, currentTime, glm::vec3(0.5f, 0.75f, 0.25f));

  window->shader->setMat4("transform", transform);

  // Call renderer draw
  window->m_VertexArray->bind();
  glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

  // Swap front and back buffers
  window->swapBuffers();
  glfwPollEvents();
  return 0;
}

int main(int argc, const char **argv) {
  // Create one application
  Application app = Application((char *) "openGLApplication", 1.0, Kaishi::RENDER_API_OPENGL);
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    printf("Current working dir: %s\n", cwd);
  } else {
    perror("getcwd() error");
    return 1;
  }
  std::cout << "Application name: " << app.getName() << "\n";

  app.setup();

  // Specify how many windows we want created and be able to access them

  // Push the render layer onto the view hierarchy for each window

  return 0;
}
