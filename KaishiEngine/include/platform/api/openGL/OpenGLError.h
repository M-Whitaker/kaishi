//
// Created by Matt Whitaker on 18/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLERROR_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLERROR_H_

#include "Kaishi/kaipch.h"

#include <glad/glad.h>

namespace Kaishi {

class Error {
 public:
  static GLenum glCheckError_(const char *file, int line);
};

#ifndef KAISHI_DEBUG
#define glCheckError() Error::glCheckError_(__FILE__, __LINE__)
#else
#define glCheckError()
#endif

}  // namespace Kaishi

#endif //KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLERROR_H_

