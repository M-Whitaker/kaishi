//
// Created by Matt Whitaker on 24/04/2021.
//

#ifndef EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_
#define EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_

#include <iostream>
#include <thread>
#include <unistd.h>

#include <Kaishi/Kaishi.h>
#include <Kaishi/Audio.h>
#include "platform/api/openGL/openGL4.h"

#include "Kaishi/Shader.h"
#include "Kaishi/VertexArray.h"

class Application : public Kaishi::KaishiApplication {
  using Kaishi::KaishiApplication::KaishiApplication;
};

class ExampleView : public Kaishi::View {
 private:
  int m_IndicesSize;
  Kaishi::Shader *shader;
  Kaishi::OpenGLTexture *texture;
  Kaishi::VertexArray *m_VertexArray;

 public:
  void onAttach() override;
  void onDetach() override;
  void renderLoop() override;
};

#endif // EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_
