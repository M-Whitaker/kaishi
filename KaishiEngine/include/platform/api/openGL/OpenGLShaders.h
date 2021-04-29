//
// Created by Matt Whitaker on 15/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLSHADERS_H_
#define KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLSHADERS_H_

#include "Kaishi/kaipch.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Kaishi/Shader.h>

namespace Kaishi {

class OpenGLShaders : public Shader {
 public:
  explicit OpenGLShaders(const char *filename);
  /**
   *
   * @return Shader program ID
   */
  unsigned int getShaderProgram() const override;
  void setup() override;
  /**
   * Use the Shader program
   */
  void use() override;
  /**
   *
   * @param name
   * @param value
   */
  void setBool(const char *name, bool value) const override;
  /**
   *
   * @param name
   * @param value
   */
  void setInt(const char *name, int value) const override;
  /**
   *
   * @param name
   * @param value
   */
  void setFloat(const char *name, float value) const override;
  /**
   *
   * @param name
   * @param value
   */
  void setVec2(const char *name, const glm::vec2 &value) const override;
  /**
   *
   * @param name
   * @param x
   * @param y
   */
  void setVec2(const char *name, float x, float y) const override;
  /**
   *
   * @param name
   * @param value
   */
  void setVec3(const char *name, const glm::vec3 &value) const override;
  /**
   *
   * @param name
   * @param x
   * @param y
   * @param z
   */
  void setVec3(const char *name, float x, float y, float z) const override;
  /**
   *
   * @param name
   * @param value
   */
  void setVec4(const char *name, const glm::vec4 &value) const override;
  /**
   *
   * @param name
   * @param x
   * @param y
   * @param z
   * @param w
   */
  void setVec4(const char *name, float x, float y, float z, float w) const override;
  /**
   *
   * @param name
   * @param mat
   */
  void setMat2(const char *name, const glm::mat2 &mat) const override;
  /**
   *
   * @param name
   * @param mat
   */
  void setMat3(const char *name, const glm::mat3 &mat) const override;
  /**
   *
   * @param name
   * @param mat
   */
  void setMat4(const char *name, const glm::mat4 &mat) const override;
 private:
  unsigned int program{};
  const char *m_Filename;
  std::string m_VertexSource;
  std::string m_FragmentSource;
  std::string computeSource;
  unsigned int vertexShader{};
  unsigned int fragmentShader{};
  ShaderTypeFlags readShaderFile();
  int compile();
  int link();
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_PLATFORM_API_OPENGL_OPENGLSHADERS_H_
