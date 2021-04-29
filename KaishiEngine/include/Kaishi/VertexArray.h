//
// Created by Matt Whitaker on 29/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_VERTEXARRAY_H_
#define KAISHIENGINE_INCLUDE_KAISHI_VERTEXARRAY_H_

#include "VertexBuffer.h"

namespace Kaishi {

class VertexArray {
 public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
  virtual void remove() = 0;
  virtual void linkVertexBuffer(VertexBuffer &VBO, unsigned int layout) = 0;
};

}  // namespace Kaishi

#endif // KAISHIENGINE_INCLUDE_KAISHI_VERTEXARRAY_H_
