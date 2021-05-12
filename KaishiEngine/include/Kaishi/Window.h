//
// Created by Matt Whitaker on 24/03/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_
#define KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_

#include "kaipch.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "platform/api/openGL/openGL4.h"

#include "utils/Math.h"
#include "Renderer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "ViewHierarchy.h"
#include "View.h"

#ifdef KAI_MACOS
#include "platform/apple/c.interface.h"
#endif  // KAI_MACOS

namespace Kaishi {

class Window {
 private:
  GLFWwindow *window{};
  ViewHierarchy *m_ViewHierarchy;
#ifdef KAI_MACOS
  CocoaWindowInformation windowInfo{};
#endif  // KAI_MACOS
  int xpos{}, ypos{}, height{};

 public:
  explicit Window(RenderAPI graphicsApi);
  ~Window();
  int create(const char *windowName, int i);
  void show();
  void pushView(View *view);
  static void errorCallback(int error, const char *description);
  static void framebufferSizeCallback(GLFWwindow *window,
                                      int width, int height);
  GLFWwindow *getGLFWWindow();
  static void keyCallback(GLFWwindow *window, int key,
                          int scancode, int action, int mods);
  /**
   * Swap the front and back framebuffer.
   */
  void swapBuffers();
  void render();
  Shader *shader;
  OpenGLTexture *texture;
  VertexArray *m_VertexArray;
  int size{};
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_WINDOW_H_
