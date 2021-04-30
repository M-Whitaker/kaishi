//
// Created by Matt Whitaker on 25/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXBUFFER_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXBUFFER_H_

#include "Kaishi/VertexBuffer.h"

#include <glad/glad.h>

namespace Kaishi {

class OpenGLVertexBuffer : public VertexBuffer {
 private:
  unsigned int VBO;

 public:
  OpenGLVertexBuffer(float *vertices, GLsizeiptr size);
  void bind() override;
  void unbind() override;
  void remove() override;
};
}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXBUFFER_H_
