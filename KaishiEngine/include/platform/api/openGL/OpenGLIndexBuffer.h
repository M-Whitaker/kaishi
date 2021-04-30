//
// Created by Matt Whitaker on 29/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLINDEXBUFFER_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLINDEXBUFFER_H_

#include <glad/glad.h>

#include "Kaishi/IndexBuffer.h"

namespace Kaishi {

class OpenGLIndexBuffer : public IndexBuffer {
 private:
  unsigned int IBO;

 public:
  OpenGLIndexBuffer(unsigned int *indices, GLsizeiptr size);
  void bind() override;
  void unbind() override;
  void remove() override;
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLINDEXBUFFER_H_
