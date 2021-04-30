//
// Created by Matt Whitaker on 29/04/2021.
//

#include <platform/api/openGL/OpenGLVertexArray.h>

namespace Kaishi {
Kaishi::OpenGLVertexArray::OpenGLVertexArray() {
  glGenVertexArrays(1, &VAO);
}
void OpenGLVertexArray::linkVertexBuffer(VertexBuffer *VBO, unsigned int layout, GLint numComponents, GLenum type, GLsizei stride, void* offset) {
  // Select the VBO
  VBO->bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  // Deselect the VBO
  VBO->unbind();
}
void OpenGLVertexArray::bind() {
  glBindVertexArray(VAO);
}
void OpenGLVertexArray::unbind() {
  glBindVertexArray(0);
}
void OpenGLVertexArray::remove() {
  printf("Deleting Vertex Array...\n");
  glDeleteVertexArrays(1, &VAO);
}
unsigned int OpenGLVertexArray::getVAO() const {
  return VAO;
}
}  // namespace Kaishi
