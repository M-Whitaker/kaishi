//
// Created by Matt Whitaker on 16/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_SHADER_H_
#define KAISHIENGINE_INCLUDE_KAISHI_SHADER_H_

#include "kaipch.h"

#include <vector>
#include <string>

#include <glm/glm.hpp>

namespace Kaishi {

typedef struct ShaderTypeFlags {
  unsigned int vertex:1;
  unsigned int fragment:1;
  unsigned int compute:1;

  void reset() {
    vertex = 0;
    fragment = 0;
    compute = 0;
  }
} ShaderTypeFlags;

class Shader {
 protected:
  int m_ShaderVersion = 0;
  std::vector<std::string> m_ShaderExtensions;

 public:
  virtual unsigned int getShaderProgram() const = 0;
  virtual void setup() = 0;
  /**
   * Use the Shader program
   */
  virtual void use() = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setBool(const char *name, bool value) const = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setInt(const char *name, int value) const = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setFloat(const char *name, float value) const = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setVec2(const char *name, const glm::vec2 &value) const = 0;
  /**
   *
   * @param name
   * @param x
   * @param y
   */
  virtual void setVec2(const char *name, float x, float y) const = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setVec3(const char *name, const glm::vec3 &value) const = 0;
  /**
   *
   * @param name
   * @param x
   * @param y
   * @param z
   */
  virtual void setVec3(const char *name, float x, float y, float z) const = 0;
  /**
   *
   * @param name
   * @param value
   */
  virtual void setVec4(const char *name, const glm::vec4 &value) const = 0;
  /**
   *
   * @param name
   * @param x
   * @param y
   * @param z
   * @param w
   */
  virtual void setVec4(const char *name, float x, float y,
                       float z, float w) const = 0;
  /**
   *
   * @param name
   * @param mat
   */
  virtual void setMat2(const char *name, const glm::mat2 &mat) const = 0;
  /**
   *
   * @param name
   * @param mat
   */
  virtual void setMat3(const char *name, const glm::mat3 &mat) const = 0;
  /**
   *
   * @param name
   * @param mat
   */
  virtual void setMat4(const char *name, const glm::mat4 &mat) const = 0;
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_SHADER_H_
