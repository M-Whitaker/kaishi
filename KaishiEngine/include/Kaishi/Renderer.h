//
// Created by Matt Whitaker on 16/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_RENDERER_H_
#define KAISHIENGINE_INCLUDE_KAISHI_RENDERER_H_

#include <glm/glm.hpp>

#include "Shader.h"

namespace Kaishi {

typedef enum RenderAPI {
  RENDER_API_OPENGL,
  RENDER_API_OPENGLES,
  RENDER_API_VULKAN,
  RENDER_API_DIRECT3D11,
  RENDER_API_DIRECT3D12
} GraphicsAPI;

class Renderer {
 private:
  static const RenderAPI s_RenderApi;
  Shader *shader;

 public:
  virtual void drawQuad() = 0;
  virtual void setClearColour(float R, float G, float B, float A) = 0;
  virtual void setClearColour(const glm::vec4 &colour) = 0;
  virtual void draw() = 0;
  static RenderAPI getAPI() {return s_RenderApi;}
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_RENDERER_H_
