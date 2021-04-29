//
// Created by Matt Whitaker on 29/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_INDEXBUFFER_H_
#define KAISHIENGINE_INCLUDE_KAISHI_INDEXBUFFER_H_

namespace Kaishi {

class IndexBuffer {
 private:
 public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
  virtual void remove() = 0;
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_INDEXBUFFER_H_
