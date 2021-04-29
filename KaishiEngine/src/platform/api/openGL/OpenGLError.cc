//
// Created by Matt Whitaker on 19/04/2021.
//

#include "platform/api/openGL/OpenGLError.h"

namespace Kaishi {

GLenum Error::glCheckError_(const char *file, int line) {
  GLenum errorCode;
  while ((errorCode = glGetError()) != GL_NO_ERROR) {
    std::string error;
    switch (errorCode) {
      case GL_INVALID_ENUM: error = "INVALID_ENUM";
        break;
      case GL_INVALID_VALUE: error = "INVALID_VALUE";
        break;
      case GL_INVALID_OPERATION: error = "INVALID_OPERATION";
        break;
      case GL_STACK_OVERFLOW: error = "STACK_OVERFLOW";
        break;
      case GL_STACK_UNDERFLOW: error = "STACK_UNDERFLOW";
        break;
      case GL_OUT_OF_MEMORY: error = "OUT_OF_MEMORY";
        break;
      case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION";
        break;
    }
    Log* log = Log::GetInstance(LOGGING_LEVEL_DEBUG);
    char BUFFER[100];
    snprintf(BUFFER, sizeof(BUFFER), "%s | %s | \"(%d)\"\n", error.c_str(), file, line);
    log->error(BUFFER);
  }
  return errorCode;
}

}  // namespace Kaishi
