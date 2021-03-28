//
// Created by Matt Whitaker on 28/02/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_APPLICATION_H_
#define KAISHIENGINE_INCLUDE_KAISHI_APPLICATION_H_

#include "kaipch.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Window.h"

namespace Kaishi {

class KaishiApplication {
 private:
  char *m_name;
  float m_version;
  std::vector<Window*> windows = {};
 public:
  KaishiApplication(char *name, float version);

  int mainLoop();

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
