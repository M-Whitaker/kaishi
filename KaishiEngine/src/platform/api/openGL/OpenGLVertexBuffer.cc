//
// Created by Matt Whitaker on 25/04/2021.
//

#include "platform/api/openGL/OpenGLVertexBuffer.h"

namespace Kaishi {

OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, GLsizeiptr size) {
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
void OpenGLVertexBuffer::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void OpenGLVertexBuffer::unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void OpenGLVertexBuffer::remove() {
  printf("Deleting Vertex Buffer...\n");
  glDeleteBuffers(1, &VBO);
}

} // namespace Kaishi
