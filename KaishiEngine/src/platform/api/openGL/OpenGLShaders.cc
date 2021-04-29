//
// Created by Matt Whitaker on 15/04/2021.
//

#include "platform/api/openGL/OpenGLShaders.h"

namespace Kaishi {

OpenGLShaders::OpenGLShaders(const char *filename)
    : m_Filename(filename) {

}

void OpenGLShaders::setup() {
  readShaderFile();
  compile();
  link();
}

// activate the shader
// ------------------------------------------------------------------------
void OpenGLShaders::use() {
  glUseProgram(program);
}
// utility uniform functions
// ------------------------------------------------------------------------
void OpenGLShaders::setBool(const char *name, bool value) const {
  glUniform1i(glGetUniformLocation(program, name), (int)value);
}
void OpenGLShaders::setInt(const char *name, int value) const {
  glUniform1i(glGetUniformLocation(program, name), value);
}
void OpenGLShaders::setFloat(const char *name, float value) const {
  glUniform1f(glGetUniformLocation(program, name), value);
}
void OpenGLShaders::setVec2(const char *name, const glm::vec2 &value) const {
  glUniform2fv(glGetUniformLocation(program, name), 1, &value[0]);
}
void OpenGLShaders::setVec2(const char *name, float x, float y) const {
  glUniform2f(glGetUniformLocation(program, name), x, y);
}
void OpenGLShaders::setVec3(const char *name, const glm::vec3 &value) const {
  glUniform3fv(glGetUniformLocation(program, name), 1, &value[0]);
}
void OpenGLShaders::setVec3(const char *name, float x, float y, float z) const {
  glUniform3f(glGetUniformLocation(program, name), x, y, z);
}
void OpenGLShaders::setVec4(const char *name, const glm::vec4 &value) const {
  glUniform4fv(glGetUniformLocation(program, name), 1, &value[0]);
}
void OpenGLShaders::setVec4(const char *name, float x, float y, float z, float w) const {
  glUniform4f(glGetUniformLocation(program, name), x, y, z, w);
}
void OpenGLShaders::setMat2(const char *name, const glm::mat2 &mat) const {
  glUniformMatrix2fv(glGetUniformLocation(program, name), 1, GL_FALSE, &mat[0][0]);
}
void OpenGLShaders::setMat3(const char *name, const glm::mat3 &mat) const {
  glUniformMatrix3fv(glGetUniformLocation(program, name), 1, GL_FALSE, &mat[0][0]);
}
void OpenGLShaders::setMat4(const char *name, const glm::mat4 &mat) const {
  glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &mat[0][0]);
}
unsigned int OpenGLShaders::getShaderProgram() const {
  return program;
}

ShaderTypeFlags OpenGLShaders::readShaderFile() {
  std::ifstream File(m_Filename);
  std::string line;
  ShaderTypeFlags shaderFlags;
  std::stringstream vertexStringStream;
  std::stringstream fragmentStringStream;
  std::stringstream computeStringStream;

  while (std::getline(File, line)) {
    if (line[0] == '#') {
      if (line == "#shadertype vertex")
        shaderFlags.vertex = !shaderFlags.vertex;
      else if (line == "#shadertype fragment")
        shaderFlags.fragment = !shaderFlags.fragment;
      else if (line == "#shadertype compute")
        shaderFlags.compute = !shaderFlags.compute;
      else if (line == "#endshadertype")
        shaderFlags.reset();
    } else if (shaderFlags.vertex)
      vertexStringStream << line;
    else if (shaderFlags.fragment)
      fragmentStringStream << line;
    else if (shaderFlags.compute)
      computeStringStream << line;
  }

  File.close();

  m_VertexSource = vertexStringStream.str();
  m_FragmentSource = fragmentStringStream.str();
  computeSource = computeStringStream.str();

  return shaderFlags;
}

int OpenGLShaders::compile() {
  // vertex shader
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char* vertexShaderSource = m_VertexSource.c_str();
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
    std::cout << "ERROR::OpenGLShaders::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  // fragment shader
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char* fragmentShaderSource = m_FragmentSource.c_str();
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
    std::cout << "ERROR::OpenGLShaders::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  return 0;

}

int OpenGLShaders::link() {
  // link shaders
  int success;
  char infoLog[512];
  program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
  // check for linking errors
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program, 512, nullptr, infoLog);
    std::cout << "ERROR::OpenGLShaders::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  return 0;
}
}  // namespace Kaishi

