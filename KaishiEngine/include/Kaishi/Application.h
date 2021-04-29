//
// Created by Matt Whitaker on 28/02/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_APPLICATION_H_
#define KAISHIENGINE_INCLUDE_KAISHI_APPLICATION_H_

#include "kaipch.h"

#include <vector>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Window.h"
#include "Renderer.h"

namespace Kaishi {

class KaishiApplication {
 protected:
  char *m_name;
  float m_version;
  RenderAPI m_RenderApi;
  std::vector<Window*> windows = {};
  virtual int renderLoop(Kaishi::Window* window) = 0;

 public:
  KaishiApplication(char *name, float version, RenderAPI renderApi);
  int setup();

  char *getName() const {
    return m_name;
  }

  void setName(char *name) {
    m_name = name;
  }

  float getVersion() const {
    return m_version;
  }

  void setVersion(float version) {
    m_version = version;
  }
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_APPLICATION_H_
