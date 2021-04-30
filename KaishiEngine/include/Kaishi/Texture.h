//
// Created by Matt Whitaker on 30/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_IMAGE_H_
#define KAISHIENGINE_INCLUDE_KAISHI_IMAGE_H_

namespace Kaishi {

class Texture {
 public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
};

}  // namespace Kaishi

#endif // KAISHIENGINE_INCLUDE_KAISHI_IMAGE_H_
