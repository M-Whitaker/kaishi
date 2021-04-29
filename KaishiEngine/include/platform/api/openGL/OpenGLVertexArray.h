//
// Created by Matt Whitaker on 29/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXARRAY_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXARRAY_H_

#include "Kaishi/VertexArray.h"

#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace Kaishi {

class OpenGLVertexArray : public VertexArray {
 public:
  unsigned int VAO;
  OpenGLVertexArray();
  void bind() override;
  void unbind() override;
  void remove() override;
  void linkVertexBuffer(VertexBuffer &VBO, unsigned int layout) override;
};

} // namespace Kaishi

#endif // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLVERTEXARRAY_H_
