//
// Created by Matt Whitaker on 25/04/2021.
//

#include "platform/api/openGL/OpenGLIndexBuffer.h"

namespace Kaishi {

OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int *indices, GLsizeiptr size) {
  glGenBuffers(1, &IBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
void OpenGLIndexBuffer::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, IBO);
}
void OpenGLIndexBuffer::unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void OpenGLIndexBuffer::remove() {
  printf("Deleting Index Buffer...\n");
  glDeleteBuffers(1, &IBO);
}

} // namespace Kaishi