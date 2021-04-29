//
// Created by Matt Whitaker on 29/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLRENDERER_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLRENDERER_H_

#include <glad/glad.h>

#include "Kaishi/Renderer.h"

#include "OpenGLVertexArray.h"
#include "OpenGLShaders.h"

namespace Kaishi {

class OpenGLRenderer : public Renderer {
 private:
  OpenGLShaders m_Shader;
  OpenGLVertexArray m_VAO;
 public:
  OpenGLRenderer(OpenGLShaders &shader, OpenGLVertexArray &VAO);
  void drawQuad() override;
  void setClearColour(float R, float G, float B, float A) override;
  void setClearColour(const glm::vec4 &colour) override;
  void draw() override;
};

} // namespace Kaishi

#endif // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLRENDERER_H_
