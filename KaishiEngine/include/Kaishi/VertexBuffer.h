//
// Created by Matt Whitaker on 25/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_VERTEXBUFFER_H_
#define KAISHIENGINE_INCLUDE_KAISHI_VERTEXBUFFER_H_

namespace Kaishi {

class VertexBuffer {
 private:
 public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
  virtual void remove() = 0;
};

} // namespace Kaishi

#endif // KAISHIENGINE_INCLUDE_KAISHI_VERTEXBUFFER_H_
