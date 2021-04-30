//
// Created by Matt Whitaker on 30/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLTEXTURE_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLTEXTURE_H_

#include <glad/glad.h>
#include <stb_image.h>

#include "Kaishi/Texture.h"

namespace Kaishi {

enum OpenGLTextureType {};

enum OpenGLTextureFormat {};

class OpenGLTexture : public Texture {
 private:
  unsigned int m_TextureID;
  unsigned int m_Type;

 public:
  OpenGLTexture(const char *imagePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
  void bind() override;
  void unbind() override;
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLTEXTURE_H_
