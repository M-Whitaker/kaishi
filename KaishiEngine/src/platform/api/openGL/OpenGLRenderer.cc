//
// Created by Matt Whitaker on 29/04/2021.
//

#include <platform/api/openGL/OpenGLRenderer.h>


namespace Kaishi {

OpenGLRenderer::OpenGLRenderer(OpenGLShaders &shader, OpenGLVertexArray &VAO)
: m_Shader(shader), m_VAO(VAO) {}

void OpenGLRenderer::drawQuad() {}
void OpenGLRenderer::setClearColour(float R, float G, float B, float A) {
  glClearColor(R, G, B, A);
}
void OpenGLRenderer::setClearColour(const glm::vec4 &colour) {}
void OpenGLRenderer::draw() {
  // Clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);
  // Set the shader for drawing
  m_Shader.use();
  // Select the data we want to draw
  glBindVertexArray(m_VAO.getVAO());
  // Trigger the draw call
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

}  // namespace Kaishi
