//
// Created by Matt Whitaker on 29/04/2021.
//

#include <platform/api/openGL/OpenGLVertexArray.h>

namespace Kaishi {
Kaishi::OpenGLVertexArray::OpenGLVertexArray() {
  glGenVertexArrays(1, &VAO);
}
void OpenGLVertexArray::linkVertexBuffer(VertexBuffer &VBO, unsigned int layout) {
  // Select the VBO
  VBO.bind();
  glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
  glEnableVertexAttribArray(layout);
  // Deselect the VBO
  VBO.unbind();
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
} // namespace Kaishi