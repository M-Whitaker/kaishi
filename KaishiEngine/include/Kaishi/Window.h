//
// Created by Matt Whitaker on 24/03/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_
#define KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_

#include "kaipch.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#ifdef KAI_MACOS
#include "platform/apple/c.interface.h"
#endif  // KAI_MACOS

namespace Kaishi {

class Window {
 public:

 private:
  GLFWwindow *window;
#ifdef KAI_MACOS
  CocoaWindowInformation windowInfo{};
#endif  // KAI_MACOS
  int xpos, ypos, height;
 public:
  Window();
  ~Window();
  int create(const char *windowName, int i);
  void show();
  GLFWwindow *getGLFWWindow();
 private:
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_
