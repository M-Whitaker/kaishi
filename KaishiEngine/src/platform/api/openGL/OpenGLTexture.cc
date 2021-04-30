//
// Created by Matt Whitaker on 30/04/2021.
//

#include "platform/api/openGL/OpenGLTexture.h"

namespace Kaishi {

OpenGLTexture::OpenGLTexture(const char *imagePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {

  int imgWidth, imgHeight, numColCh;
  // Flips the image so it appears right side up
  stbi_set_flip_vertically_on_load(true);
  unsigned char* bytes = stbi_load(imagePath, &imgWidth, &imgHeight, &numColCh, 0);

  // Generates an OpenGL texture object
  glGenTextures(1, &m_TextureID);
  glActiveTexture(slot);
  glBindTexture(texType, m_TextureID);

  // Configures the type of algorithm that is used to make the image smaller or bigger
  glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Texture tiling
  glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Assigns the image to the OpenGL Texture object
  glTexImage2D(texType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);
  glGenerateMipmap(texType);

  // Deletes the image data as it is already in the OpenGL Texture object
  stbi_image_free(bytes);

  // Unbinds the OpenGL Texture
  glBindTexture(texType, 0);
}
void OpenGLTexture::bind() {
  glBindTexture(m_Type, m_TextureID);
}
void OpenGLTexture::unbind() {
  glBindTexture(m_Type, 0);
}

}  // namespace Kaishi